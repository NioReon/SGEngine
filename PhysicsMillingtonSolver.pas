unit PhysicsMillingtonSolver;

interface
Uses PhysicsArifm, PhysicsRigidBody, Windows;

Type
TContact = class
  public
    Bodies: array [0..1] of TRigidBody;
    Friction, PullBack: Float;
    Point: TBodyVertex;
    Normal: TVector3;
    Penetration: Float;
  protected
    LocalToWorld: TMatrix3x3;
    LocalVelocity: TVector3;
    DesiredVelocityChange: Float;
    RelativeContactPosition: T2Vectors3D;

  public
    Constructor Create (const Body1, Body2: TRigidBody; const AContactPoint: TBodyVertex;
                        const ANormal: TVector3; const InterPenetration: Float;
                        const PullBackCoefficient, FrictionCoefficient: Float);

    Procedure InitializeContact (const DeltaTime: Float);
    Procedure SwapBodies;
    Procedure MatchBodyState;
    Procedure ComputeDesiredVelocityChange (const DeltaTime: Float);
    Function CalculateLocalVelocityForBody (const Index: Integer; const DeltaTime: Float): TVector3;
    Procedure ComputeBasis;
    Procedure ApplyVelocityChange (var LinearChange, AngularChange: T2Vectors3D; const DeltaTime: Float);
    Procedure ApplyPositionChange (var LinearChange, AngularChange: T2Vectors3D; const Penetration, DeltaTime: Float);
    Function ComputeImpulse: TVector3;
    Function ComputeFrictionlessImpulse: TVector3;
end;

TContacts = array of TContact;

TContactHandler = class
  protected
    {������������ ���������� ��������, ��������� �� ���� ������ �������
     ���������, ��� ��������� � ��������� ��� ��������������}
    VelocityIterationsLimit,
    PositionIterationsLimit: Integer;
    {���������� �������������� �������� ��� ��������� � ���������}
    VelocityIterationsUsed,
    PositionIterationsUsed: Integer;
    {�� ��������� ������������ ������ ��� ��������, ������� ����� ��������,
     ����� ��������� ������� ����. ��� ������� ����� ��������� ��������
     ������������ ������ �������, ��� ������� ������� - ���� ����� ���������
     ��������� ���� � �����. �������� ��������� �������� - 0.01.}
  public
    VelocityEpsilon,
    {�� ��������� ������������ ������ ��� ������� �������������, ������� ����� ��������,
     ����� ��������� ������� ����. ��� ������� ����� ��������� ��������
     ������������ ������ �������, ��� ������� ������� - ���� ����� ���������
     ��������� ���� � �����. �������� ��������� �������� - 0.01.}
    PositionEpsilon: Float;

  public
    Constructor Create (const IterationsLimit: Integer; const VelocityEps: Float = 0.01;
        const PositionEps: Float = 0.01); overload;
    Constructor Create (const Velocity_Iterations, Position_Iterations: Integer;
        const VelocityEps: Float = 0.01; const PositionEps: Float = 0.01); overload;

    Procedure SetIterations (const Velocity_Iterations, Position_Iterations: Integer); overload;
    Procedure SetIterations (const EachStageIterations: Integer); overload;

    Procedure SetEpsilon (const VelocityEps: Float = 0.01; const PositionEps: Float = 0.01);
    Procedure ProcessContacts (var Contacts: TContacts; const NumberOfContacts: Integer;
        const DeltaTime: Float);
  protected
    Procedure PrepareContacts (var Contacts: TContacts; const NumberOfContacts: Integer;
        const DeltaTime: Float);
    Procedure AdjustVelocities (var Contacts: TContacts; const NumberOfContacts: Integer;
        const DeltaTime: Float);
    Procedure AdjustPositions (var Contacts: TContacts; const NumberOfContacts: Integer;
        const DeltaTime: Float);
end;

implementation
{################################################################################################################
                                             TContact type
################################################################################################################}
Constructor TContact.Create(const Body1: TRigidBody; const Body2: TRigidBody; const AContactPoint: TBodyVertex;
    const ANormal: TVector3; const InterPenetration: Float; const PullBackCoefficient, FrictionCoefficient: Float);
begin
    inherited Create;
    Bodies[0] := Body1;
    Bodies[1] := Body2;
    Point := AContactPoint;
    Normal := ANormal;
    Penetration := InterPenetration;
    PullBack := PullBackCoefficient;
    Friction := FrictionCoefficient;
end;

Procedure TContact.InitializeContact(const DeltaTime: Float);
begin
    {���������, ������������ �� ������ �� ����}
    If Bodies[0] = nil
    then SwapBodies;
    Assert (Bodies[0] <> nil);

    {���������� �������������� ����� ��������}
    ComputeBasis;

    {���������� ��������� ��� ������������ ����� ��������}
    RelativeContactPosition[0] := V3Sub (Point.Pos, Bodies[0].Position);
    If Bodies[1] <> nil
    then RelativeContactPosition[1] := V3Sub (Point.Pos, Bodies[1].Position)
    else RelativeContactPosition[1] := V3 (0);

    {���������� �������� � ����� ��������}
    LocalVelocity := CalculateLocalVelocityForBody (0, DeltaTime);
    If Bodies[1] <> nil then
        LocalVelocity := V3Sub (LocalVelocity, CalculateLocalVelocityForBody (1, DeltaTime));

    {���������� ����������� ��������� � �������� ��� ���������� ��������}
    ComputeDesiredVelocityChange (DeltaTime);
end;

Procedure TContact.SwapBodies;
Var Body: TRigidBody;
begin
    Normal := V3Invert (Normal);

    Body := Bodies[0];
    Bodies[0] := Bodies[1];
    Bodies[1] := Body;
end;

Procedure TContact.MatchBodyState;
Var Body1Awake, Body0Awake: boolean;
begin
    If Bodies[1] = nil then Exit;

    Body0Awake := Bodies[0].GetCanBeUpdated;
    Body1Awake := Bodies[1].GetCanBeUpdated;

    If Body0Awake xor Body1Awake
    then If Body0Awake
    then Bodies[1].SetCanBeUpdated(true)
    else Bodies[0].SetCanBeUpdated(true);
end;

Procedure TContact.ComputeDesiredVelocityChange(const DeltaTime: Float);
Const VelocityLimit: Float = 0.25;
Var AccelAddedVelocity: Float;
    CurrentPullBack: Float;
begin
    AccelAddedVelocity := 0;
    //���������� ��������, ����������� ����������
    If Bodies[0].GetCanBeUpdated
    then AccelAddedVelocity := V3ScalarProduct (V3Mul (Bodies[0].GetAcceleration, DeltaTime), Normal);
    If Bodies[1] <> nil then
    If Bodies[1].GetCanBeUpdated then
        AccelAddedVelocity := AccelAddedVelocity
            - V3ScalarProduct (V3Mul (Bodies[1].GetAcceleration, DeltaTime), Normal);
    //���� �������� �������� ����, ���������� ������
    CurrentPullBack := PullBack;
    If Abs (LocalVelocity.X) < VelocityLimit
    then CurrentPullBack := 0;
    //���������� ���������
    DesiredVelocityChange := - LocalVelocity.X - CurrentPullBack * (LocalVelocity.X - AccelAddedVelocity);
end;

Function TContact.CalculateLocalVelocityForBody(const Index: Integer; const DeltaTime: Float): TVector3;
Var Velocity, AccAddedVelocity: TVector3;
begin
    //���������� �������� � ����� ��������
    Velocity := V3Add (Bodies[Index].Velocity,
        V3Mul (Bodies[Index].AngularVelocity, RelativeContactPosition[Index]));

    //��������� � � ���������� ��������
    Velocity := Mat3x3TransposeTransformV3ByMatrix3x3 (LocalToWorld, Velocity);
    //���������� ��������, ����������� ���������� �� ������� �����
    AccAddedVelocity := Mat3x3TransposeTransformV3ByMatrix3x3 (LocalToWorld,
        V3Mul (Bodies[Index].GetAcceleration, DeltaTime));
    //���������� ��������� ����� ���������������, ��� ���������� ������ ���������
    //� ��������� ��������
    AccAddedVelocity.X := 0; 
    //�������� ��������� - ��������, ����������� ���������� + �������� � ��������� ��������
    Result := V3Add (Velocity, AccAddedVelocity);
end;

Procedure TContact.ComputeBasis;
Var Axis: array [0..1] of TVector3;
    Scale: Float;
begin
    {��������, � ����� �� ���� ����� ��� OZ}
    If Abs (Normal.X) > Abs (Normal.Y) then
    begin    {� OX}
        Scale := 1/Sqrt (Sqr (Normal.X) + Sqr (Normal.Z));
        {������ ������� � ������� ��� OY}
        Axis[0].X := Normal.Z * Scale;
        Axis[0].Y := 0;
        Axis[0].Z := -Normal.X * Scale;
        {������������� � ���������, �������� ����� ����������� �����}
        Axis[1].X := Normal.Y * Axis[0].X;
        Axis[1].Y := Normal.Z * Axis[0].X - Normal.X * Axis[0].Z;
        Axis[1].Z := -Normal.Y * Axis[0].X;
    end else
    begin    {� OY}
        Scale := 1/Sqrt (Sqr (Normal.Y) + Sqr (Normal.Z));
        {������ ������� � ������� ��� OX}
        Axis[0].Y := -Normal.Z * Scale;
        Axis[0].X := 0;
        Axis[0].Z := Normal.Y * Scale;
        {������������� � ���������, �������� ����� ����������� �����}
        Axis[1].X := Normal.Y * Axis[0].Z - Normal.Z * Axis[0].Y;
        Axis[1].Y := - Normal.X * Axis[0].Z;
        Axis[1].Z := Normal.X * Axis[0].Y;
    end;
    Mat3x3SetComponents (LocalToWorld, Normal, Axis[0], Axis[1]);
end;

Procedure TContact.ApplyVelocityChange (var LinearChange, AngularChange: T2Vectors3D; const DeltaTime: Float);
Var {��������������� ������� ������� ������� ���}
    Tensors: array [0..1] of TMatrix3x3;
    {������� � ������� �����������}
    Impulse, ImpulsiveTorque: TVector3;
begin
    {�������� ��������������� ������� ������� ��� ��� ������� ���������}
    Tensors[0] := Bodies[0].InvInertiaTensorInWorldCoords;
    If Bodies[1] <> nil then Tensors[1] := Bodies[1].InvInertiaTensorInWorldCoords;
    {������� � ������� �����������}
    If Friction = 0
    then Impulse := Mat3x3Mul (LocalToWorld, ComputeFrictionlessImpulse)
    else Impulse := Mat3x3Mul (LocalToWorld, ComputeImpulse);
    {�������� ������������ � �������� ���������� ��������}
    ImpulsiveTorque := V3Mul (RelativeContactPosition[0], Impulse);
    AngularChange[0] := Mat3x3Mul (Tensors[0], ImpulsiveTorque);
    LinearChange[0] := V3Mul (Impulse, Bodies[0].GetInvertedMass);
    {�������� �������� � ������� �������� ������� ����}
    Bodies[0].Velocity := V3Add (Bodies[0].Velocity, LinearChange[0]);
    Bodies[0].AngularVelocity := V3Add (Bodies[0].AngularVelocity, AngularChange[0]);
    {�� �� ����� �������� ��� ������� ����}
    If Bodies[1] <> nil then
    begin
        {�������� ������������ � �������� ���������� ��������}
        ImpulsiveTorque := V3Mul (Impulse, RelativeContactPosition[1]);
        AngularChange[1] := Mat3x3Mul (Tensors[1], ImpulsiveTorque);
        LinearChange[1] := V3Mul (Impulse, -Bodies[1].GetInvertedMass);
        {�������� �������� � ������� �������� ������� ����}
        Bodies[1].Velocity := V3Add (Bodies[1].Velocity, LinearChange[1]);
        Bodies[1].AngularVelocity := V3Add (Bodies[1].AngularVelocity, AngularChange[1]);
    end;
end;

Procedure TContact.ApplyPositionChange(var LinearChange: T2Vectors3D; var AngularChange: T2Vectors3D;
    const Penetration, DeltaTime: Float);
Const AngularLimit: Float = 0.2;
Var I: Integer;
    {������ ������� �������� ����}
    Tensor: TMatrix3x3;
    {������� � �������� �������}
    AngularInertiaWorld, TargetAngularDirection: TVector3;
    AngularInertia, LinearInertia,
    {��������� � ���������� � ������� ���}
    AngularMovement, LinearMovement: array [0..1] of Float;
    {����� ������� ���}
    TotalInertia: Float;
    MaxLength, TotalMovement: Float;
    Projection: TVector3;
begin
    TotalInertia := 0;
    {���������� ����� ������� ���}
    For I := 0 to 1 do
    If Bodies[I] <> nil then
    begin
        Tensor := Bodies[I].InvInertiaTensorInWorldCoords;
        {���������� ������� �������}
        AngularInertiaWorld := V3Mul (RelativeContactPosition[I], Normal);
        AngularInertiaWorld := Mat3x3Mul (Tensor, AngularInertiaWorld);
        AngularInertiaWorld := V3Mul (AngularInertiaWorld, RelativeContactPosition[I]);
        AngularInertia[I] := V3ScalarProduct (AngularInertiaWorld, Normal);
        {���������� �������� �������}
        LinearInertia[I] := Bodies[I].GetInvertedMass;
        {�������� ���������� ������� � �����}
        TotalInertia := TotalInertia + AngularInertia[I] + LinearInertia[I];
    end;
    {��������� ��������� � �����}
    For I := 0 to 1 do
    If Bodies[I] <> nil then
    begin
        //���������� �������� ����������� ����
        If I = 0 then
        begin
            AngularMovement[I] := Penetration * (AngularInertia[I] / TotalInertia);
            LinearMovement[I] := Penetration * (LinearInertia[I] / TotalInertia);
        end else
        begin
            AngularMovement[I] := -Penetration * (AngularInertia[I] / TotalInertia);
            LinearMovement[I] := -Penetration * (LinearInertia[I] / TotalInertia);
        end;

        {���������� ������������ �������� ��� ������ ������ ������� ������� � �������
         ����� ����}
        Projection := V3AddScaledVector (RelativeContactPosition[I],
            Normal, -V3ScalarProduct (RelativeContactPosition[I], Normal));
        {���������� ������������� ��� ������ ������ ���� ��� ����������� �������������
         �������� ����}
        MaxLength := AngularLimit * V3Length (Projection);
        If AngularMovement[I] < -MaxLength then
        begin
            TotalMovement := AngularMovement[I] + LinearMovement[I];
            AngularMovement[I] := -MaxLength;
            LinearMovement[I] := TotalMovement - AngularMovement[I];
        end else
        If AngularMovement[I] > MaxLength then
        begin
            TotalMovement := AngularMovement[I] + LinearMovement[I];
            AngularMovement[I] := MaxLength;
            LinearMovement[I] := TotalMovement - AngularMovement[I];
        end;
        {� ��� ������� �������� ��������� ��������, ������� ���� ����������,
         �������� ���� (� AngularMovement[I]). ���� ����������, �� ����� ��������
         ��������� ����, ����� ������� �����}
        If AngularMovement[I] = 0
        then AngularChange[I] := V3 (0)
        else {AngularChange[I] := Mat3x3Mul (Bodies[I].InvInertiaTensorInWorldCoords,
                V3Mul (V3Mul (RelativeContactPosition[I], Normal), AngularMovement[I]/AngularInertia[I]));}
        begin
            TargetAngularDirection := V3Mul (RelativeContactPosition[I], Normal);
            AngularChange[I] := Mat3x3Mul (Bodies[I].InvInertiaTensorInWorldCoords, TargetAngularDirection);
            AngularChange[I] := V3Mul (AngularChange[I], AngularMovement[I]/AngularInertia[I]);
        end;
        {� �������� ���������� ����� - ��� �������� �������� ����� ������� ��������}
        LinearChange[I] := V3Mul (Normal, LinearMovement[I]);
        {�������� ������� ������ ���� ����}
        Bodies[I].Position := V3Add (Bodies[I].Position, LinearChange[I]);
        {�������� ������� ���������� ����}
        Bodies[I].Orientation := QuatAddScaledVector (Bodies[I].Orientation, AngularChange[I], 1);
        {���������� �������� ������ ������ "�������" ����, ����� ��������� ����������
         � ��������� �������. � ��������� ������ �� ��������� �������� ������ ��������
         ����� �� �� ����� ������������������� � ���� �� ��������.}
        If not Bodies[I].GetCanBeUpdated then Bodies[I].CalculateBodyData;
    end;
end;

Function TContact.ComputeFrictionlessImpulse: TVector3;
Var DeltaVelWorld: TVector3;
    DeltaVelocity: Float;
begin
    {���������� ������, ������� ���� ��������� �������� � ������� �����������
     ��� ����������� ���������� ��������}
    DeltaVelWorld := V3Mul (RelativeContactPosition[0], Normal);
    DeltaVelWorld := Mat3x3Mul (Bodies[0].InvInertiaTensor, DeltaVelWorld);
    DeltaVelWorld := V3Mul (DeltaVelWorld, RelativeContactPosition[0]);
    {��������� ���������� �������� � ���������� ��������}
    DeltaVelocity := V3ScalarProduct (DeltaVelWorld, Normal);
    {�������� �������� ���������� ��������� ��������}
    DeltaVelocity := DeltaVelocity + Bodies[0].GetInvertedMass;

    If Bodies[1] <> nil then
    begin
        {���������� ������, ������� ���� ��������� �������� � ������� �����������
         ��� ����������� ���������� ��������}
        DeltaVelWorld := V3Mul (RelativeContactPosition[1], Normal);
        DeltaVelWorld := Mat3x3Mul (Bodies[1].InvInertiaTensor, DeltaVelWorld);
        DeltaVelWorld := V3Mul (DeltaVelWorld, RelativeContactPosition[1]);
        {��������� ���������� �������� � ���������� ��������}
        DeltaVelocity := DeltaVelocity + V3ScalarProduct (DeltaVelWorld, Normal);
        {�������� �������� ���������� ��������� ��������}
        DeltaVelocity := DeltaVelocity + Bodies[1].GetInvertedMass;
    end;
    Result.X := DesiredVelocityChange / DeltaVelocity;
    Result.Y := 0;
    Result.Z := 0;
end;

Function TContact.ComputeImpulse: TVector3;
Var InvMass: Float;
    {������� ��� �������� �� ��������� �������� � �������������}
    ImpulseToTorque: TMatrix3x3;
    {�� ��������� �������� ���� �������� ��������� �������� � ������� �����������}
    WorldVelChange: array [0..1] of TMatrix3x3;
    {������� ��� ��������������� ������� ��������� � ��������� ���������� ��������}
    WorldToLocal: TMatrix3x3;
    {�������, ����������� ��� ��������� ��������}
    ImpulseMatrix: TMatrix3x3;
    {������� � ����� ��������}
    ContactImpulse: TVector3;
    {����� �������� �������� � ��������� YOZ}
    YOZImpulse: Float;
begin
    ZeroMemory (@WorldVelChange[0], SizeOf (WorldVelChange[0]));
    ZeroMemory (@WorldVelChange[1], SizeOf (WorldVelChange[1]));
    {������ ���������� ������������ ��� ������ - ��������� ������� ��
     ������ �������, ������������ ������������ ������� ���������.
     ���������� ��� ��� ��������� ������������ � �������� ��������� ��������}
    Mat3x3SetDiagonalSymmetric (ImpulseToTorque, RelativeContactPosition[0]);
    {�������� ������� ��� ������� ��������� �������� � ������� ����������� ��
     �������� � ����������� ��������}
    WorldVelChange[0] := Mat3x3Mul (ImpulseToTorque, Bodies[0].InvInertiaTensorInWorldCoords);
    WorldVelChange[0] := Mat3x3Mul (WorldVelChange[0], ImpulseToTorque);
    WorldVelChange[0] := Mat3x3Mul (WorldVelChange[0], -1);
    
    {������� ��������������� ����� ������� ����}
    InvMass := Bodies[0].GetInvertedMass;
    {���� � ��� ������� ���� � ������ �����, �������� �� �� ��������,
     �� ��� ��� ������� ����}
    If Bodies[1] <> nil then
    begin
        Mat3x3SetDiagonalSymmetric (ImpulseToTorque, RelativeContactPosition[1]);
        WorldVelChange[1] := Mat3x3Mul (ImpulseToTorque, Bodies[1].InvInertiaTensorInWorldCoords);
        WorldVelChange[1] := Mat3x3Mul (WorldVelChange[1], ImpulseToTorque);
        WorldVelChange[1] := Mat3x3Mul (WorldVelChange[1], -1);

        WorldVelChange[0] := Mat3x3ComponentWiseAddition (WorldVelChange[0],
            WorldVelChange[1]);
        InvMass := InvMass + Bodies[1].GetInvertedMass;
    end;
    {������� ���������� ����� ��������� ������� ���������� � ���������.
     ������������� ���, ����� ���������� �������� ��������}
    WorldToLocal := Mat3x3Transpose (LocalToWorld);
    WorldToLocal := Mat3x3Mul (WorldToLocal, WorldVelChange[0]);
    WorldToLocal := Mat3x3Mul (WorldToLocal, LocalToWorld);

    {WorldToLocal := Mat3x3Mul (Mat3x3Transpose (LocalToWorld),
        Mat3x3Mul (WorldVelChange[0], LocalToWorld));}
    {�������� ��������� �������� ��������}
    WorldToLocal.Data[0] := WorldToLocal.Data[0] + InvMass;
    WorldToLocal.Data[4] := WorldToLocal.Data[4] + InvMass;
    WorldToLocal.Data[8] := WorldToLocal.Data[8] + InvMass;
    {������� ��� ��������� ��������}
    ImpulseMatrix := Mat3x3Invert (WorldToLocal);
    {����� �������, ������� ����� ��������� ��� ������������ ���������
     ��������� ���}
    ContactImpulse := Mat3x3Mul (ImpulseMatrix,
        V3 (DesiredVelocityChange, -LocalVelocity.Y, -LocalVelocity.Z));
    {���������, ��������������� �� ���� � ���������� ������. ��� �����
     ���������� ����� �������� �������� � ��������� Y0Z ��������}
    YOZImpulse := Sqrt (Sqr (ContactImpulse.Y) + Sqr (ContactImpulse.Z));
    If YOZImpulse > ContactImpulse.X * Friction then
    begin
        {����� ���������� ������������ ������}
        ContactImpulse.Y := ContactImpulse.Y / YOZImpulse;
        ContactImpulse.Z := ContactImpulse.Z / YOZImpulse;
        ContactImpulse.X := WorldToLocal.Data[0] +
            WorldToLocal.Data[1] * Friction * ContactImpulse.Y +
            WorldToLocal.Data[2] * Friction * ContactImpulse.Z;
        ContactImpulse.X := DesiredVelocityChange / ContactImpulse.X;
        ContactImpulse.Y := ContactImpulse.Y * ContactImpulse.X * Friction;
        ContactImpulse.Z := ContactImpulse.Z * ContactImpulse.X * Friction;
    end;
    Result := ContactImpulse;
end;

{################################################################################################################
                                            TContactHandler type
################################################################################################################}

Constructor TContactHandler.Create(const IterationsLimit: Integer; const VelocityEps: Float = 0.01;
    const PositionEps: Float = 0.01);
begin
    Inherited Create;
    VelocityIterationsLimit := IterationsLimit;
    PositionIterationsLimit := IterationsLimit;
    VelocityEpsilon := VelocityEps;
    PositionEpsilon := PositionEps;
    VelocityIterationsUsed := 0;
    PositionIterationsUsed := 0;
end;

Constructor TContactHandler.Create(const Velocity_Iterations: Integer; const Position_Iterations: Integer;
    const VelocityEps: Float = 0.01; const PositionEps: Float = 0.01);
begin
    Inherited Create;
    VelocityIterationsLimit := Velocity_Iterations;
    PositionIterationsLimit := Position_Iterations;
    VelocityEpsilon := VelocityEps;
    PositionEpsilon := PositionEps;
    VelocityIterationsUsed := 0;
    PositionIterationsUsed := 0;
end;

Procedure TContactHandler.SetIterations(const Velocity_Iterations: Integer; const Position_Iterations: Integer);
begin
    VelocityIterationsLimit := Velocity_Iterations;
    PositionIterationsLimit := Position_Iterations;
end;

Procedure TContactHandler.SetEpsilon(const VelocityEps: Float = 0.01; const PositionEps: Float = 0.01);
begin
    VelocityEpsilon := VelocityEps;
    PositionEpsilon := PositionEps;
end;

Procedure TContactHandler.SetIterations(const EachStageIterations: Integer);
begin
    VelocityIterationsLimit := EachStageIterations;
    PositionIterationsLimit := EachStageIterations;
end;

Procedure TContactHandler.ProcessContacts(var Contacts: TContacts; const NumberOfContacts: Integer; const DeltaTime: Float);
begin
    If NumberOfContacts < 0 then Exit;
    PrepareContacts (Contacts, NumberOfContacts, DeltaTime);
    AdjustPositions (Contacts, NumberOfContacts, DeltaTime);
    AdjustVelocities (Contacts, NumberOfContacts, DeltaTime);
end;

Procedure TContactHandler.PrepareContacts(var Contacts: TContacts; const NumberOfContacts: Integer; const DeltaTime: Float);
Var I: Integer;
begin
    For I := 0 to NumberOfContacts do
        Contacts[I].InitializeContact(DeltaTime);
end;

Procedure TContactHandler.AdjustVelocities(var Contacts: TContacts; const NumberOfContacts: Integer; const DeltaTime: Float);
Var VelocityChange, RotationChange: T2Vectors3D;
    DeltaVel: TVector3;
    Max: Float;
    I, J, K, MaxFoundIndex: Integer;
begin
    VelocityIterationsUsed := 0;
    While (VelocityIterationsUsed < VelocityIterationsLimit) do
    begin
        {����� ������� � ���������� ����������� ���������� �������� ���}
        If NumberOfContacts > 0 then
        begin
            Max := VelocityEpsilon;
            MaxFoundIndex := NumberOfContacts;
            For I := 0 to NumberOfContacts do
            If Contacts[I].DesiredVelocityChange > Max then
            begin
                Max := Contacts[I].DesiredVelocityChange;
                MaxFoundIndex := I;
            end;
        end else MaxFoundIndex := 0;

        If MaxFoundIndex = NumberOfContacts then Break;

        {��������� ��������� ��� �� ������� "������"}
        Contacts[MaxFoundIndex].MatchBodyState;
        {���������� ��������� �������}
        Contacts[MaxFoundIndex].ApplyVelocityChange(VelocityChange, RotationChange, DeltaTime);

        For I := 0 to NumberOfContacts do
            {��������� ������ ���� � ������� ��������}
            For J := 0 to 1 do
            If Contacts[I].Bodies[J] <> nil then
                {��������� ������ ���� � MaxFoundIndex'��� ��������}
                For K := 0 to 1 do
                If (Contacts[I].Bodies[J] = Contacts[MaxFoundIndex].Bodies[K]) then
                begin
                    DeltaVel := V3Add (VelocityChange[K], V3Mul (RotationChange[K],
                        Contacts[I].RelativeContactPosition[J]));
                    If J = 0 then
                    Contacts[I].LocalVelocity := V3Add (Contacts[I].LocalVelocity,
                        Mat3x3TransposeTransformV3ByMatrix3x3 (Contacts[I].LocalToWorld, DeltaVel))
                    else
                    Contacts[I].LocalVelocity := V3Sub (Contacts[I].LocalVelocity,
                        Mat3x3TransposeTransformV3ByMatrix3x3 (Contacts[I].LocalToWorld, DeltaVel));
                    Contacts[I].ComputeDesiredVelocityChange(DeltaTime);
                end;
        Inc (VelocityIterationsUsed);
    end;
end;

Procedure TContactHandler.AdjustPositions(var Contacts: TContacts; const NumberOfContacts: Integer; const DeltaTime: Float);
Var I, J, K, MaxFoundIndex: Integer;
    LinearChange, AngularChange: T2Vectors3D;
    Max: Float;
    DeltaPos: TVector3;
begin
    PositionIterationsUsed := 0;
    While (PositionIterationsUsed < PositionIterationsLimit) do
    begin
        {����� ������� � ���������� �������� ��������������}
        Max := PositionEpsilon;
        MaxFoundIndex := NumberOfContacts;
        For I := 0 to NumberOfContacts do
        If Contacts[I].Penetration > Max then
        begin
            Max := Contacts[I].Penetration;
            MaxFoundIndex := I;
        end;

        If MaxFoundIndex = NumberOfContacts then Exit;

        Contacts[MaxFoundIndex].MatchBodyState;
        Contacts[MaxFoundIndex].ApplyPositionChange(LinearChange, AngularChange, Max, DeltaTime);

        For I := 0 to NumberOfContacts do
            For J := 0 to 1 do
            If Contacts[I].Bodies[J] <> nil then
                For K := 0 to 1 do
                    If Contacts[I].Bodies[J] = Contacts[MaxFoundIndex].Bodies[K] then
                    begin
                        DeltaPos := V3Add (LinearChange[K],
                            V3Mul (AngularChange[K], Contacts[I].RelativeContactPosition[J]));
                        If J = 0 then
                            Contacts[I].Penetration := Contacts[I].Penetration -
                                V3ScalarProduct (DeltaPos, Contacts[I].Normal)
                        else Contacts[I].Penetration := Contacts[I].Penetration +
                                V3ScalarProduct (DeltaPos, Contacts[I].Normal)
                    end;
        Inc (PositionIterationsUsed);
    end;
end;

end.
