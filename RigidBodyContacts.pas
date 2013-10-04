unit RigidBodyContacts;

interface
Uses GJKCollisions, Math, MapStructure, PhysicsArifm, PhysicsRigidBody, PrimitiveCollsTesters, SysUtils, RigidBodyForceGen,
  PhysicsMillingtonSolver, Windows;

CONST AXIS_COUNT = 30;
      PIBy2 = 2*Pi;
      PIBy2OverAXIS_COUNT = PIBy2 / AXIS_COUNT;
      Friction: Float = 0;
      PullBack: Float = 0.5;

{########################################################################################
                 ���������, ������������ ��� ���������� ���������
########################################################################################}

TWO_RIGID_BODIES = 0;
RIGID_BODY_AND_PLANE = 1;
RIGID_BODY_AND_PARTICLE = 2;

Type
TDArrayI = array of Integer;
T2BodyVertexes = array [0..1] of TBodyVertexes;

{###############################################################################
                              TContactGenerator
��������� ��������� ������ ���. � ��� ������ ������ ���������� ����� ���������
�������� ����������, ������������ ��� ��� ����������.
    ����:
  - WorkIterations: �������� ��������, ������� ����� ���������; ��� ������, ���
    ���� ��������� ����� WorkIterations ��������, �� �������������� ����� ��
    ������������ ���������
  - CompletedIterations: ���������� ����������� �� ������� ������ �������� ��������
    ������������ ���������
    ������:
  - SetIterationsCount: ������ �������� ���� WorkIterations
  - RemoveContactByIndex: ������� ������� �� ������ ������� �� �������
  - HandleContacts: ���������� �� ����� WorkIterations ���������
���� ��������� ����� ���� ����������� ��� ������ �� ����� ����������.
###############################################################################}

T2RBContactGen = class
  public
    Function GenerateContacts (var Contacts: TContacts; var Bodies: TRigidBodies): Integer;
end;

TRBPlaneContactGen = class
  public
    Function GenerateContacts (var Contacts: TContacts; var Bodies: TRigidBodies; const WorldSector: TSector): Integer;
end;

TForceGenData = record
    Type_: Word;
    Gen: Pointer;
end;

TContactGenData = record
    Type_: Word;
    Gen: Pointer;
end;

TGenData = record
    Force: array of TForceGenData;
    Contact: array of TContactGenData;
end;

TWorldStruc = class
  protected
    SimCyclesPerContact: Integer;
    ContactCountLimit: Integer;
    ContactHandler: TContactHandler;
    Contacts: TContacts;
  public
    Registry: TRegistry;
    Generators: TGenData;
    Bodies: TRigidBodies;

    Constructor Create (const ContactsPerFrame, SimCyclesPerContact_: Integer);
    Destructor Destroy;
    Procedure Simulate (const WorldSector: TSector; const DeltaTime: Float);
    Procedure AddBody (const ANewBody: TRigidBody; const LinkWithGravityForceGenerator: boolean = true);
    Procedure DrawBodies;
    Procedure IntegrateWorld (const DeltaTime: Float);
end;

implementation

{������� �� ������� ������� �� ��� �������}
Procedure RemoveArrayElement (Var A: TVectors3; const Index: Integer); overload;
Var Len: Integer;
begin
    Len := High (A);
    If Index > Len then Exit;
    A[Index] := A[Len];
    SetLength (A, Len);
end;

Procedure RemoveArrayElement2 (Var A: TBodyVertexes; const Index: Integer); overload;
Var Len: Integer;
begin
    Len := High (A);
    If Index > Len then Exit;
    A[Index] := A[Len];
    SetLength (A, Len);
end;

{������� ������������� �������� � ������� ��������}
Procedure ClearDuplicates (Var Elements: TVectors3; StartIndex, EndIndex: Integer);
Var I, J: Integer;
    AreEqual: boolean;
begin
    I := 0;
    EndIndex := High (Elements);
    If EndIndex <= 0 then Exit;

    While (I <= EndIndex) do
    begin
        J := 1;
        While J <= EndIndex do
        begin
            AreEqual := V3Equal (Elements[I], Elements[J]);
            While not AreEqual and (J < EndIndex) do
            begin
                Inc (J);
                AreEqual := V3Equal (Elements[I], Elements[J]);
            end;
            If (J <> I) and AreEqual then
            begin
                RemoveArrayElement (Elements, J);
                Dec (EndIndex);
            end
            else Inc (J);
        end;
        If High (Elements) < EndIndex then EndIndex := High (Elements);
        Inc (I);
    end;
end;

Procedure ClearDuplicates2 (Var Elements: TBodyVertexes; StartIndex, EndIndex: Integer);
Var I, J: Integer;
    AreEqual: boolean;
begin
    I := 0;
    EndIndex := High (Elements);
    If EndIndex <= 0 then Exit;

    While (I <= EndIndex) do
    begin
        J := 1;
        While J <= EndIndex do
        begin
            AreEqual := V3Equal (Elements[I].Pos, Elements[J].Pos);
            While not AreEqual and (J < EndIndex) do
            begin
                Inc (J);
                AreEqual := V3Equal (Elements[I].Pos, Elements[J].Pos);
            end;
            If (J <> I) and AreEqual then
            begin
                RemoveArrayElement2 (Elements, J);
                Dec (EndIndex);
            end
            else Inc (J);
        end;
        If High (Elements) < EndIndex then EndIndex := High (Elements);
        Inc (I);
    end;
end;

{������� �������� �������, ������ 0 �� �����}
Procedure ClearZeroEqualElements (Var A: TVectors3);
Var J: Integer;
begin
    J := 0;
    While J <= High (A) do
    begin
        If not V3Equal (A[J], V3 (0))
        then Inc (J)
        else
        begin
            A[J] := V3Normalize (A[J]);
            If V3Equal (A[J], V3 (0))
            then RemoveArrayElement (A, J);
        end;
    end;
end;

Procedure AddContact (var Contacts: TContacts; const AContact: TContact);
Var Len: Integer;
begin
    Len := Length (Contacts);
    SetLength (Contacts, Len + 1);
    Contacts[Len] := AContact;
end;

Procedure ContactsConcat (var TargetContacts: TContacts; const AdditionalContacts: TContacts);
Var I, J, TotalLength: Integer;
begin
    I := Length (TargetContacts);
    TotalLength := I + High (AdditionalContacts);
    SetLength (TargetContacts, TotalLength + 1);

    For J := I to TotalLength do
        TargetContacts[J] := AdditionalContacts[J - I];
end;

Procedure ClearContactData (var Contacts: TContacts);
Var I: Integer;
begin
    For I := High (Contacts) downto 0 do
    begin
        FreeAndNil (Contacts[I]);
        SetLength (Contacts, I);
    end;
end;

{����� �� ��������� ������� � ����������� ���� (Separating Axis Theorem, SAT) �������� ��,
 ��� ��� ������ �������������� �������������� ���� ���� ������ ����� ���� ������� ������ �� ������,
 ���� ��������� ������������ ������������ ���� ����, ��� ���� ����� ����������� ������ �������������,
 � ������ � �������. �� ����, ��� ������ �������������� ��������������, ���� �������� ��� �����������,
 �������� ������ SAT �������� � ��������� ���� ��������:
  a) ��������� ������ ������������� ����������� ����, ��������� �� ���� �������� ������
     � ���� ��������� ��� ����,
  �) ��������� �������� ����������� �������� ����� ��������� �� ������ �� ����. ���,
     �� ������� �������� �������� �����������, ������ �����������
     (����� ��, ��� �� ������ �����, ��� ��� ��������� ������������), � ���������
     �������� ����������� �������� ������ penetration depth ��� PD.
     �������, ��� ���� ������ ���� �������� �� ������ PD, �� ����������� ��������������.}
Procedure GeneratePossibleSATs2RB (const Body1, Body2: TRigidBody; Var Results: TVectors3);
Var I, J: Integer;
    Count: Integer;
    Offset: Integer;
begin
    {����������� ������� � ������}
    SetLength (Results, Length (Body1.Ribs) + Length (Body2.Ribs) + Sqr (Length (Body1.Ribs))
                        + Sqr (Length (Body1.Ribs)));
    {������� � ������ 1 ����}
    Count := High (Body1.Faces);
    For I := 0 to Count do
    With Body1 do
        Results[i] := GetNormalToPlane (GlobalVertexes [Faces[I].Vertexes[0]].Pos,
                                        GlobalVertexes [Faces[I].Vertexes[1]].Pos,
                                        GlobalVertexes [Faces[I].Vertexes[2]].Pos);
    {������� � ������ 2 ����}
    Offset := Count + 1;
    Count := High (Body2.Faces);
    For I := 0 to Count do
    With Body2 do
        Results[i + Offset] := GetNormalToPlane (GlobalVertexes [Faces[I].Vertexes[0]].Pos,
                                        GlobalVertexes [Faces[I].Vertexes[1]].Pos,
                                        GlobalVertexes [Faces[I].Vertexes[2]].Pos);
    Offset := Offset + Count + 1;

    {��������� ��������� ������������ ���� 1 ���� �� ���� 2 ����}
    Count := 0;
    For I := 0 to High (Body1.Ribs) do
    begin
        For J := 0 to High (Body2.Ribs) do
        begin
            Results[Count + Offset] := V3Mul (V3Sub (Body1.GlobalVertexes [Body1.Ribs[I, 1]].Pos,
                                  Body1.GlobalVertexes [Body1.Ribs[I, 0]].Pos),
                                  V3Sub (Body2.GlobalVertexes [Body2.Ribs[J, 1]].Pos,
                                  Body2.GlobalVertexes [Body2.Ribs[J, 0]].Pos));
            Inc (Count);
        end;
    end;

    SetLength (Results, Offset + Count);

    {������������� ������������ ���}
    For J := 0 to High (Results) do
        Results[J] := V3Normalize (Results[J]);

    {������� ������������� ������}
    ClearDuplicates (Results, 0, High (Results));
    {������� ��������, ������ 0 �� �����}
    ClearZeroEqualElements (Results);
end;

Function IsBetweenFloatFloat (const Left, Right, TestNumber: Float): boolean;
begin
    Result := (TestNumber >= Left) and (TestNumber <= Right);
end;

Function InterSect (const Min0, Max0, Min1, Max1: Float; var Penetration: Float): boolean;
Var Result1, Result2, Result3, Result4, Temp, Temp2: Float;
begin
    Result := false;
    Result1 := +Infinity;
    Result2 := +Infinity;
    Result3 := +Infinity;
    Result4 := +Infinity;

    If IsBetweenFloatFloat (Min0, Max0, Min1) then
    begin
        Temp := Min0 - Min1;
        Temp2 := Max0 - Min1;
        Result1 := Min (Abs (Temp), Abs (Temp2));
        If Temp * Temp2 <= 0
        then Result := true;
    end;
    If IsBetweenFloatFloat (Min0, Max0, Max1) then
    begin
        Temp := Min0 - Max1;
        Temp2 := Max0 - Max1;
        Result2 := Min (Abs (Temp), Abs (Temp2));
        If Temp * Temp2 <= 0
        then Result := true;
    end;
    If IsBetweenFloatFloat (Min1, Max1, Min0) then
    begin
        Temp := Min1 - Min0;
        Temp2 := Max1 - Min0;
        Result3 := Min (Abs (Temp), Abs (Temp2));
        If Temp * Temp2 <= 0
        then Result := true;
    end;
    If IsBetweenFloatFloat (Min1, Max1, Max0) then
    begin
        Temp := Min1 - Max0;
        Temp2 := Max1 - Max0;
        Result4 := Min (Abs (Temp), Abs (Temp2));
        If Temp * Temp2 <= 0
        then Result := true;
    end;
    Penetration := Min (Min (Abs (Result1), Abs (Result2)), Min (Abs (Result3), Abs (Result4)));
end;

{��������, ��� ������ 2 ���� ������������ ����� ����� (� ���� ������ ������� ���
 ����������� ����������� � CalculatedSA) ��� �� ������������ (�� ���� ������� ���� ��
 ���� ����������� ���� ���).}
Function ChooseSAT2RB (const Body1, Body2: TRigidBody; Var CalculatedSA: TVector3): boolean;
Var {��������}
    I, J, Len: Integer;
    {�������� �� ������� ��� 1 � 2 ���� ��������������}
    Min: array [0..1] of Float;
    Max: array [0..1] of Float;
    {����������� ��� ����� ��������� ��� - CalculatedSA}
    MaxPenetration: Float;
    {��������� ����������}
    Tmp: Float;
    {��������� �� ������� ��������� � ����������� ���}
    Candidates: TVectors3;
begin
    {������������� ����� ������������� ����������� ���� ��� ������ ���� ���}
    GeneratePossibleSATs2RB (Body1, Body2, Candidates);

    Result := true;
    Len := High (Candidates);
    MaxPenetration := -Infinity;

    {��������� ��������� ���, �������� �� ��� ����������� ��� ������ ���� ���}
    For I := 0 to Len do
    begin
        Min[0] := +Infinity;
        Min[1] := +Infinity;
        Max[0] := -Infinity;
        Max[1] := -Infinity;
        {������������� ��� ���� 1 ���� �� ������ ���}
        With Body1 do
        For J := 0 to High (GlobalVertexes) do
        begin
            Tmp := V3ScalarProduct (GlobalVertexes[J].Pos, Candidates[I]);
            If Tmp < Min[0] then Min[0] := Tmp
            else If Tmp > Max[0] then Max[0] := Tmp;
        end;
        {������������� ��� ���� 2 ���� �� ������ ���}
        With Body2 do
        For J := 0 to High (GlobalVertexes) do
        begin
            Tmp := V3ScalarProduct (GlobalVertexes[J].Pos, Candidates[I]);
            If Tmp < Min[1] then Min[1] := Tmp
            else If Tmp > Max[1] then Max[1] := Tmp;
        end;

        {��������, ������������ �� 2 ���� ����� ������ ���}
        If InterSect (Min[0], Max[0], Min[1], Max[1], Tmp) then
        begin
            {����� ���� ����������� ����� ������ ���. ���������� ���,
             ����������� �������� ��� �� ������� ��������� ����������.}
            If Tmp > MaxPenetration then
            begin
                CalculatedSA := Candidates[I];
                MaxPenetration := Tmp;
            end;
        end else
        begin
            {����� �������� ��� �� ������� ��� ��������� �����������������.
             �����: ������� ����������� ���. ������� �� ������������.}
            Result := false;
            Exit;
        end;
    end;
end;

{���� 2: ������������� ���������� ����� � ������� �����������}
Procedure GenerateContactPointsInWorld (
    const MainAxis: TVector3;
    const Body1, Body2: TRigidBody;
    Var ContactPointsBody1, ContactPointsBody2: TBodyVertexes);
Const EPS2 = EPS;
Var {������ �������������� ���� ��� ��������� ������� ���������� ��������}
    AuxAxis: array of TVector3;
    {����� � ������� ���� }
    TmpSin, TmpCos: Extended;
    {������� � ��������� � �������� ���}
    Normal0, Normal1: TVector3;
    {��������}
    I: Integer;
begin
    {�������� ������������� � ������ ���}
    Normal0 := V3Normalize (V3Perpendicular (MainAxis));
    {�������� ������������� � ���� ��������� ���� (������� �������,
    ������� � ���������, ������� ��� ������)}
    Normal1 := V3Normalize (V3Mul (Normal0, MainAxis));

    {���������� �������������� ���}
    SetLength (AuxAxis, AXIS_COUNT);
    For I := 0 to AXIS_COUNT - 1 do
    begin
        SinCos (PIBy2OverAXIS_COUNT * I, TmpSin, TmpCos);
        AuxAxis[i] := V3Normalize (V3Add (V3Add (MainAxis, V3Mul (Normal0, TmpCos * EPS2)),
                                          V3Mul (Normal1, TmpSin * EPS2)));
    end;
    {�������� Support Point'�}
    SetLength (ContactPointsBody1, AXIS_COUNT);
    SetLength (ContactPointsBody2, AXIS_COUNT);
    {��� 1 ����}
    With Body1 do
    For I := 0 to AXIS_COUNT - 1 do
        ContactPointsBody1[I] := GetFarthestPointInDirection (AuxAxis[I]);

    ClearDuplicates2 (ContactPointsBody1, 0, High (ContactPointsBody1));

    {��� 2 ����}
    With Body2 do
    For I := 0 to AXIS_COUNT - 1 do
        ContactPointsBody2[I] := GetFarthestPointInDirection (V3Invert (AuxAxis[I]));

    ClearDuplicates2 (ContactPointsBody2, 0, High (ContactPointsBody2));
end;

{��������� �� ������ ����� ������ ������ ��������� �������� Polygon}
Function PointInConvexPolygon (const Point: TVector3; const Polygon: TVectors3): boolean;
Var AngleSum: Float;
    I, Len: Integer;
begin
    Result := false;
    Len := High (Polygon);
    Case Len of
    0: If V3Equal (Polygon[0], Point) then Result := true;
    else If Len > 0 then
        begin
            AngleSum := GetAngleBetweenVectors (
                V3Sub (Polygon[0], Point),
                V3Sub (Polygon[Len], Point));
            For I := 1 to Len do
            begin
                AngleSum := AngleSum + GetAngleBetweenVectors (
                    V3Sub (Polygon[I - 1], Point),
                    V3Sub (Polygon[I], Point));
            end;
            If (AngleSum + 0.001 >= 2*Pi) then Result := true;
        end;
    End;
end;

{���� 3�. ��� �������� ����� �� ���������:
     - ���������� ���������� �� ����� �� ���������;
     - ������� ����� ����� ������� ������� �� ���������� �����.}
Procedure ProjectContactPointsOnPlane2 (
    {����������� ��� (������� � ����� ���������)}
    const Normal: TVector3;
    {����� �� ���� ���������}
    const PlaneOrigin: TVector3;
    {�����, ������� ���� �������������}
    const OriginalPoints: TBodyVertexes;
    {�����, ���������� � ���������� �������������}
    var ProjectedPoints: TBodyVertexes);
Var I, Len: integer;
    Offset, Delta: Float;
begin
    {���������� ������ ����� �� ��������� ����� �������
     ����������� �� ��������� �� ������ ���������}
    Offset := V3ScalarProduct (Normal, PlaneOrigin);
    Len := High (OriginalPoints);
    SetLength (ProjectedPoints, Len + 1);

    {������������� ��� �����}
    For I := 0 to Len do
    begin
        Delta := Offset - V3ScalarProduct (OriginalPoints[I].Pos, Normal);
        ProjectedPoints[I].Pos := V3AddScaledVector (OriginalPoints[I].Pos, Normal, Delta);
        ProjectedPoints[I].Mass := OriginalPoints[i].Mass;
    end;
end;

Procedure AddEl (var Els: TVectors3; const El: TVector3);
Var Len: Integer;
begin
    Len := Length (Els);
    SetLength (Els, Len + 1);
    Els[Len] := El;
end;

Procedure AddEl2 (var Els: TBodyVertexes; const El: TBodyVertex);
Var Len: Integer;
begin
    Len := Length (Els);
    SetLength (Els, Len + 1);
    Els[Len] := El;
end;

{������� ������� ������������� ������ ����� (Feature) � �������� ���� Body �����
 ������ ������� ContactNormal}
Function ComputePenetrationAtPoint (const Body: TRigidBody; const Feature, ContactNormal: TVector3): Float;
Var I, Count: Integer;
    Tmp, Min, Max: Float;
begin
    Min := +Infinity;
    Max := -Infinity;
    {���������� ������ � ����}
    Count := High (Body.GlobalVertexes);

    {������������� ��� ���� ���� �� ������ ���}
    For I := 0 to Count do
    With Body.GlobalVertexes[I] do
    begin
        Tmp := V3ScalarProduct (Pos, ContactNormal);
        If Tmp < Min then Min := Tmp
        else If Tmp > Max then Max := Tmp;
    end;
    {����� ��������� ������������ �������� �������� ��������
     ����������� ����� �� �������}
    Tmp := V3ScalarProduct (Feature, ContactNormal);
    {����������� ������� ���������� ������� ����� �������� �������
     �������� ���� �� ������� � �������� ����� �� ��}
    Result := Math.Min (Abs (Min - Tmp), Abs (Max - Tmp));
end;

{���� 4 ��� ��������� ���� - ���������
����� ���������� ����� ��� ����.}
Procedure ChooseContactCandidates2RB (
    Body1, Body2: TRigidBody;
    ProjectionPlaneNormal: TVector3;
    Var Contacts: TContacts;
    Var CandidateFeatures: T2BodyVertexes);
Var ProjectedPoints: TBodyVertexes;
    I, J: Integer;
    Count: array [0..1] of Integer;
    MassCenter: T2Vectors3D;
    FeatureMass, CurrentPenetration: Float;
    Temp: TVector3;
begin
    {����� ������������� ���������� ���� ���� �� ���������, ���������� �����
     � ����� ����. ��� ����� ����� ����� ���� ���� � ����������� ��� �����
     ���� �� ��}
    For I := 0 to 1 do
        MassCenter[I] := V3 (0);

    For J := 0 to 1 do
    begin
        Count[J] := High (CandidateFeatures[J]);
        {���������� ������ ���� ����, ���������� �� � �����}
        For I := 0 to Count[J] do
        With CandidateFeatures[J, I] do
            MassCenter[J] := V3AddScaledVector (MassCenter[J], Pos, Mass);
        {������� ����� ���������� ����}
        FeatureMass := 0;
        For I := 0 to Count[J] do
            FeatureMass := FeatureMass + CandidateFeatures[J, I].Mass;
        {����� ������� ��������� ������ ����}
        MassCenter[J] := V3Div (MassCenter[J], FeatureMass);
    end;

    For J := 0 to 1 do
    begin
        {������������� ����� � ���������� ���� �� ������������ ���������}
        ProjectContactPointsOnPlane2 (ProjectionPlaneNormal, MassCenter[1 - J], CandidateFeatures[J],
            ProjectedPoints);

        {����� ���������� �������� �� �����, ������� �� ����� � ����������������, ��� ����� �������
         ��������� �������������. ��� �����:
         1. �������� �� ��������� ����� � ��������������� ������;
         2. �������, ����������� �� ��������� � ��������:
         2.1 ��: ����� �� ����� � ����������������, ��� ����� �������. ������, ��
             ����� ���� �� ���������� �����. ��������� � ��������;
         2.2 ���: ����� ����� � ����������������, ��� ����� �������. ������, ��
             ����� �����, ������� �� �������� ��������� ��������. �����������
             ��� ����� � ��������� � ���������.}
        Count[J] := High (CandidateFeatures[J]);
        For I := 0 to Count[J] do
        begin
            {������ �� ������ ���� �� ������}
            Temp := V3Sub (ProjectedPoints[I].Pos, CandidateFeatures[J, I].Pos);

            {������� ��������� ������������� ��� � ������ ���������� �����}
            If I <= Count[1-J] then
            If J = 0
            then CurrentPenetration := ComputePenetrationAtPoint (Body1, CandidateFeatures[1-J, I].Pos,
                ProjectionPlaneNormal)
            else CurrentPenetration := ComputePenetrationAtPoint (Body2, CandidateFeatures[1-J, I].Pos,
                ProjectionPlaneNormal);

            {���� ������ �� ������ ���� �� ������ ����������� � �������� ��������,
             �� ������ �������}
            If V3CheckSonapr (ProjectionPlaneNormal, Temp) and (CurrentPenetration > 0)
            then AddContact (Contacts, TContact.Create(Body1, Body2, CandidateFeatures[J, I],
                ProjectionPlaneNormal, CurrentPenetration, PullBack,
                Friction));
        end;
    end;
end;

{##########################################################################################
                               T2RBContactGen
##########################################################################################}

Function T2RBContactGen.GenerateContacts(var Contacts: TContacts; var Bodies: TRigidBodies): Integer;
Var {����� ����������� ��� � ������� �����������}
    InterSectionPoints: T2BodyVertexes;
    {������ ������� ��������, ������������ ������� ������, ������� � ����� ����������� �������}
    I, J, AddedContacts: Integer;
    {������ ���������, ��������������� ������� ������}
    FoundContacts: TContacts;
    {������� ������ ������� ���}
    Count: Integer;
    {������� ��������}
    SA: TVector3;
begin
    Result := 0;
    SetLength (FoundContacts, 0);

    Count := High (Bodies);
    If Count <= 0 then Exit;

    For I := 0 to Count - 1 do
    For J := I + 1 to Count do
    begin
        If ChooseSAT2RB (Bodies[I], Bodies[J], SA) then
        begin
            {������������� �����, �������������� ���������� �������� ���}
            GenerateContactPointsInWorld (SA, Bodies[I], Bodies[J],
                InterSectionPoints[0], InterSectionPoints[1]);

            ChooseContactCandidates2RB (Bodies[I], Bodies[J], SA, FoundContacts,
                InterSectionPoints);

            {�������� ���������� �������� � ����� ������}
            AddedContacts := Length (FoundContacts);
            Result := Result + AddedContacts;
            If AddedContacts > 0 then
            begin
                ContactsConcat (Contacts, FoundContacts);
                SetLength (FoundContacts, 0);
            end;
        end;
    end;
end;

{##########################################################################################
                               TRBPlaneContactGen
##########################################################################################}

Function ChooseSATBPlane (const Plane: TPlane; const Body: TRigidBody): boolean;
Var I, Len: Integer;
    Tmp, Min, Max: Float;
begin
    Len := High (Body.GlobalVertexes);
    Assert (Len > -1);
    Min := V3ScalarProduct (Body.GlobalVertexes[0].Pos, Plane.Normal);
    If Len > 0
    then Max := V3ScalarProduct (Body.GlobalVertexes[1].Pos, Plane.Normal)
    else Max := Min;

    If Min > Max then
    begin
        Tmp := Min;
        Min := Max;
        Max := Tmp;
    end;

    {������������� ��� ���� 1 ���� �� ������ ���}
    For I := 2 to Len do
    begin
        Tmp := V3ScalarProduct (Body.GlobalVertexes[I].Pos, Plane.Normal);
        If Tmp < Min then Min := Tmp
        else If Tmp > Max then Max := Tmp;
    end;

    Min := Min - Plane.Offset;
    Max := Max - Plane.Offset;

    If Min * Max <= 0
    then Result := true
    else Result := false;
end;

Procedure GenerateContactPointsWithWorld (
    const MainAxis: TVector3;
    const Body: TRigidBody;
    Var ContactPoints: TBodyVertexes);
Var {������ �������������� ���� ��� ��������� ������� ���������� ��������}
    AuxAxis: array of TVector3;
    {����� � ������� ���� }
    TmpSin, TmpCos: Extended;
    {������� � ��������� � �������� ���}
    Normal0, Normal1: TVector3;
    {��������}
    I: Integer;
begin
    {�������� ������������� � ������ ���}
    Normal0 := V3Normalize (V3Perpendicular (MainAxis));
    {�������� ������������� � ���� ��������� ���� (������� �������,
    ������� � ���������, ������� ��� ������)}
    Normal1 := V3Normalize (V3Mul (Normal0, MainAxis));

    {���������� �������������� ���}
    SetLength (AuxAxis, AXIS_COUNT);
    For I := 0 to AXIS_COUNT - 1 do
    begin
        SinCos (PIBy2OverAXIS_COUNT * I, TmpSin, TmpCos);
        AuxAxis[i] := V3Normalize (V3Add (V3Add (MainAxis, V3Mul (Normal0, TmpCos * EPS)),
                                          V3Mul (Normal1, TmpSin * EPS)));
    end;
    {�������� Support Point'�}
    SetLength (ContactPoints, AXIS_COUNT);

    For I := 0 to AXIS_COUNT - 1 do
        ContactPoints[I] := Body.GetFarthestPointInDirection (V3Invert (AuxAxis[I]));

    ClearDuplicates2 (ContactPoints, 0, AXIS_COUNT - 1);
end;

Procedure ChooseContactCandidatesForBodyAndPlane (
    Body: TRigidBody;
    ProjectionPlane: TPlane;
    Var Contacts: TContacts);
Var I, Count: Integer;
    DistanceToPlane: Float;
begin
    Count := High (Body.GlobalVertexes);
    For I := 0 to Count do
    With Body.GlobalVertexes[I] do
    begin
        DistanceToPlane := V3ScalarProduct (Pos, ProjectionPlane.Normal);
        If DistanceToPlane <= ProjectionPlane.Offset then
        begin
            {PointData.Mass := Mass;
            PointData.Pos := V3AddScaledVector (Pos, ProjectionPlane.Normal,
                DistanceToPlane - ProjectionPlane.Offset);}
            AddContact (Contacts, TContact.Create(Body, nil, Body.GlobalVertexes[I],
                ProjectionPlane.Normal, ProjectionPlane.Offset - DistanceToPlane, PullBack, Friction));
        end;
    end;
end;

Function TRBPlaneContactGen.GenerateContacts(
    {��������, ��������������� ���� �������������}
    var Contacts: TContacts;
    {����, ����������� ������� � ����� ���� ���������}
    var Bodies: TRigidBodies;
    {������� ��������� ��������� - ���������, ���������� 3 �������, � ������ ������}
    const WorldSector: TSector): Integer;
Var I, J: Integer;
    PointOnPlane: TVector3;
    Plane: TPlane;
    FoundContacts: TContacts;
begin
    I := 0;
    SetLength (FoundContacts, 0);
    
    While I < High (WorldSector.Normals) do
    begin
        {�������� ��������� ���������� ��������}
        {������� ��������}
        With WorldSector.Normals[I] do
            Plane.Normal := V3 (X, Y, Z);
        {���������� �� �������� �� ������ ���������}
        With WorldSector.Vertexs[I] do
            PointOnPlane := V3 (X, Y, Z);
        Plane.Offset := V3ScalarProduct (PointOnPlane, Plane.Normal);
        {������������� �������� ����� ������ ����� � ������ ������� ���������}
        For J := 0 to High (Bodies) do
            {����� �������� - ��������� ������ ���������}
            If ChooseSATBPlane (Plane, Bodies[J]) then
                ChooseContactCandidatesForBodyAndPlane (Bodies[J], Plane, FoundContacts);
        I := I + 3;
    end;
    {� ���������� ������� ���������� ��������������� ���������}
    Result := Length (FoundContacts);
    If Result > 0 then ContactsConcat (Contacts, FoundContacts);
end;

{##########################################################################################
                        TWorldStruc - ��������� ������ ����
##########################################################################################}

Constructor TWorldStruc.Create (const ContactsPerFrame, SimCyclesPerContact_: Integer);
begin
    inherited Create;
    ContactCountLimit := ContactsPerFrame;
    SimCyclesPerContact := SimCyclesPerContact;
    ContactHandler := TContactHandler.Create(10000, 0.001, 0.001);
    SetLength (Contacts, 0);
    Registry := TRegistry.Create;
    SetLength (Generators.Force, 1);
    Generators.Force[0].Type_ := GRAVITY_BFG;
    Generators.Force[0].Gen := TRBGravityForceGen.Create(PhysicsArifm.Gravity);

    SetLength (Generators.Contact, 2);
    Generators.Contact[0].Gen := T2RBContactGen.Create;
    Generators.Contact[0].Type_ := TWO_RIGID_BODIES;
    Generators.Contact[1].Gen := TRBPlaneContactGen.Create;
    Generators.Contact[1].Type_ := RIGID_BODY_AND_PLANE;
    SetLength (Bodies, 0);
end;

Destructor TWorldStruc.Destroy;
Var I: Integer;
begin
    FreeAndNil (ContactHandler);
    FreeAndNil (Registry);

    For I := High (Bodies) downto 0 do
        FreeAndNil (Bodies[I]);
    SetLength (Bodies, 0);

    For I := High (Generators.Contact) downto 0 do
    Case Generators.Contact[I].Type_ of
        TWO_RIGID_BODIES: FreeAndNil (T2RBContactGen(Generators.Contact[I].Gen));
        RIGID_BODY_AND_PLANE: FreeAndNil (TRBPlaneContactGen (Generators.Contact[I].Gen));
    end;
    SetLength (Generators.Contact, 0);

    For I := High (Generators.Force) downto 0 do
    Case Generators.Force[I].Type_ of
        GRAVITY_BFG: FreeAndNil (TRBGravityForceGen (Generators.Force[I].Gen));
        DRAG_BFG: FreeAndNil (TRBDragForceGen (Generators.Force[I].Gen));
        SPRING_BFG: FreeAndNil (TRBSpringForceGen (Generators.Force[I].Gen));
        BUNGEE_BFG: FreeAndNil (TRBBungeeForceGen (Generators.Force[I].Gen));
        ANCHORED_SPRING_BFG: FreeAndNil (TRBAnchoredSpringForceGen (Generators.Force[I].Gen));
    End;
    SetLength (Generators.Force, 0);

    For I := High (Contacts) downto 0 do
        FreeAndNil (Contacts[I]);
    SetLength (Contacts, 0);
end;

Procedure TWorldStruc.IntegrateWorld(const DeltaTime: Float);
begin
    Registry.IntegrateEntireBodies(DeltaTime);
end;

Procedure TWorldStruc.AddBody(const ANewBody: TRigidBody; const LinkWithGravityForceGenerator: Boolean = True);
Var I, BodyIndex: Integer;
    Found: boolean;
    Entry: TRegistryEntry;
begin
    BodyIndex := Length (Bodies);
    SetLength (Bodies, BodyIndex + 1);
    Bodies[BodyIndex] := ANewBody;

    If LinkWithGravityForceGenerator then
    begin
        I := -1;
        Found := false;
        While (I <= High (Generators.Force)) and not Found do
        begin
            Inc (I);
            If Generators.Force[I].Type_ = GRAVITY_BFG
            then Found := true;
        end;
        If Found then
        begin
            Entry.Type_ := GRAVITY_BFG;
            Entry.GFG := Generators.Force[I].Gen;
            Entry.Body_G := Bodies[BodyIndex];
            Registry.AddEntry(Entry);
        end;
    end;
end;

Procedure TWorldStruc.DrawBodies;
Var I: Integer;
begin
    For I := 0 to High (Bodies) do
        Bodies[I].Draw;
end;

{$O-}
Procedure TWorldStruc.Simulate(const WorldSector: TSector; const DeltaTime: Float);
Var I, ContactsUsed: Integer;
begin
    Assert (ContactCountLimit > 0);
    Registry.ClearAccums;
    Registry.UpdateForces (DeltaTime);

    SetLength (Contacts, 0);

    ContactsUsed := 0;
    For I := 0 to High (Generators.Contact) do
    Case Generators.Contact[I].Type_ of
        TWO_RIGID_BODIES: ContactsUsed := ContactsUsed +
            T2RBContactGen (Generators.Contact[I].Gen).GenerateContacts (Contacts, Bodies);
        RIGID_BODY_AND_PLANE: ContactsUsed := ContactsUsed +
            TRBPlaneContactGen (Generators.Contact[I].Gen).GenerateContacts(Contacts,
                Bodies, WorldSector);
    end;

    ContactHandler.SetIterations (10*ContactsUsed);
    ContactHandler.ProcessContacts (Contacts, High (Contacts), DeltaTime);

    IntegrateWorld (DeltaTime);
    SetLength (Contacts, 0);
end;
{$O+}
end.
