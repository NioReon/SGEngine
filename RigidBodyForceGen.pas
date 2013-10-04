unit RigidBodyForceGen;

interface
Uses dglOpenGL, PhysicsArifm, PhysicsRigidBody;

CONST

{###############################################################################################
                                 ГЕНЕРАТОРЫ СИЛ ДЛЯ ТВЁРДЫХ ТЕЛ
###############################################################################################}
{гравитация}
GRAVITY_BFG = 0;
{тащение}
DRAG_BFG = 1;
{пружина между 2 телами}
SPRING_BFG = 2;
{канат между 2 телами}
BUNGEE_BFG = 3;
{пружина, к одному концу которой прикреплено тело, а второй неподвижен и фиксирован в мире}
ANCHORED_SPRING_BFG = 4;

Type

{Сила гравитации}
TRBGravityForceGen = class
  public
    Gravity: TVector3;
    Constructor Create (const AGravity: TVector3);
    Procedure UpdateForce (var Body: TRigidBody; const DeltaTime: Double);
end;

{Сила тяги}
TRBDragForceGen = class
  public
    {Коэффициент тащения}
    DragCoeff: Double;
    {Он же в квадрате}
    SquaredDragCoeff: Double;

    Constructor Create (const DragCoefficient: Double);
    Procedure UpdateForce (var Body: TRigidBody; const DeltaTime: Double);
end;

{Сила упругости пружины}
TRBSpringForceGen = class
  public
    {Длина пружины в состоянии покоя}
    RestLength: Double;
    {Коэффициент жёсткости}
    InflexibilityCoeff: Double;
    {Порог силы упругости, при превышении которого пружина "рвётся"}
    ForceLimit: Double;

    Constructor Create (const InitialLength, InflexibilityCoefficient, MaxForce: Double);
    Function UpdateForce (var Body1, Body2: TRigidBody; const DeltaTime: Double): boolean;
end;

{Канат}
TRBBungeeForceGen = class (TRBSpringForceGen)
  public
    Function UpdateForce (var Body1, Body2: TRigidBody; const DeltaTime: Double): boolean;
end;

{Пружина с одним жёстко закреплённым и фиксированным концом}
TRBAnchoredSpringForceGen = class (TRBSpringForceGen)
  public
    {Положение закреплённого конца пружины в мировых координатах}
    Anchor: TVector3;

    Constructor Create (const InitialLength, Inflexibilitycoefficient, MaxForce: Double; AnchorPos: TVector3);
    {Изменить координаты неподвижного конца пружины}
    Procedure SetAnchor (const NewAnchorPosition: TVector3);
    Function UpdateForce (var Body: TRigidBody; const DeltaTime: Double): boolean;
end;

{Запись в реестре тел и генераторов сил}
TRegistryEntry = record
    Case Type_: word of
        GRAVITY_BFG: (GFG: TRBGravityForceGen;
                 Body_G: TRigidBody);
        DRAG_BFG: (DFG: TRBDragForceGen;
                 Body_D: TRigidBody);
        SPRING_BFG: (SFG: TRBSpringForceGen;
                 Body_S1, Body_S2: TRigidBody);
        BUNGEE_BFG: (BFG: TRBBungeeForceGen;
                 Body_B1, Body_B2: TRigidBody);
        ANCHORED_SPRING_BFG: (ASFG: TRBAnchoredSpringForceGen;
                 Body_AS: TRigidBody);
end;

{Реестр, содержащий записи о соответствии тел генераторам сил}
TRegistry = class
  public
    Entries: array of TRegistryEntry;

    Constructor Create;
    Destructor Destroy;

    Procedure AddEntry (const Entry: TRegistryEntry);
    Procedure RemoveEntry (const Index: Integer); overload;
    Procedure RemoveEntry (const Entry: TRegistryEntry); overload;
    Procedure ClearEntries;
    Procedure UpdateForces (const DeltaTime: Double);
    Procedure IntegrateEntireBodies (const DeltaTime: Double);
    Procedure DrawAllSprings(const SpringColor, BungeeColor, AnchoredSpringColor: TGLArray4ub);
    Procedure ClearAccums;
end;

{###############################################################################################}
                                        implementation
{###############################################################################################}

{Сила гравитации}
Constructor TRBGravityForceGen.Create(const AGravity: TVector3);
begin
    inherited Create;
    Gravity := AGravity;
end;

Procedure TRBGravityForceGen.UpdateForce(var Body: TRigidBody; const DeltaTime: Double);
begin
    Body.AddForce (V3Mul (Gravity, Body.Mass));
end;

{Сила тяги}
Constructor TRBDragForceGen.Create(const DragCoefficient: Double);
begin
    inherited Create;
    DragCoeff := DragCoefficient;
    SquaredDragCoeff := DragCoefficient * DragCoefficient;
end;

Procedure TRBDragForceGen.UpdateForce(var Body: TRigidBody; const DeltaTime: Double);
Var ResultingForce: TVector3;
    DragCoeff: Double;
begin
    ResultingForce := Body.Velocity;
    DragCoeff := V3Length (ResultingForce);
    DragCoeff := DragCoeff * (Self.DragCoeff + Self.SquaredDragCoeff * DragCoeff);
    ResultingForce := V3Normalize (ResultingForce);
    DragCoeff := -DragCoeff;
    ResultingForce := V3Mul (ResultingForce, DragCoeff);
    Body.AddForce (ResultingForce);
end;

{Сила упругости пружины}
Constructor TRBSpringForceGen.Create (const InitialLength, InflexibilityCoefficient, MaxForce: Double);
begin
    inherited Create;
    RestLength := InitialLength;
    InflexibilityCoeff := InflexibilityCoefficient;
    ForceLimit := MaxForce;
end;

Function TRBSpringForceGen.UpdateForce(var Body1: TRigidBody; var Body2: TRigidBody; const DeltaTime: Double): boolean;
Var ResultingForce: TVector3;
    ForceVectorLength: double;
begin
    Result := true;
    ResultingForce := V3Sub (Body1.Position, Body2.Position);
    ForceVectorLength := (V3Length (ResultingForce) - RestLength) * InflexibilityCoeff;
    ResultingForce := V3Normalize (ResultingForce);
    ForceVectorLength := -ForceVectorLength / 2;
    ResultingForce := V3Mul (ResultingForce, ForceVectorLength);
    Body1.AddForce (ResultingForce);
    Body2.AddForce (V3Invert (ResultingForce));
    If Abs (ForceVectorLength) > ForceLimit then Result := false;
end;

Function TRBBungeeForceGen.UpdateForce(var Body1: TRigidBody; var Body2: TRigidBody; const DeltaTime: Double): boolean;
Var ResultingForce: TVector3;
    ForceVectorLength: Double;
begin
    Result := true;
    ResultingForce := V3Sub (Body1.Position, Body2.Position);
    ForceVectorLength := V3Length (ResultingForce);
    If (ForceVectorLength <= RestLength) then Exit;
    ForceVectorLength := (RestLength - ForceVectorLength) * InflexibilityCoeff;
    ResultingForce := V3Normalize (ResultingForce);
    ForceVectorLength := -ForceVectorLength / 2;
    ResultingForce := V3Mul (ResultingForce, ForceVectorLength);
    Body1.AddForce (V3Invert (ResultingForce));
    Body2.AddForce (ResultingForce);
    If Abs (ForceVectorLength) > ForceLimit then Result := false;
end;

Constructor TRBAnchoredSpringForceGen.Create(const InitialLength: Double; const Inflexibilitycoefficient: Double; const MaxForce: Double; AnchorPos: TVector3);
begin
    inherited Create (InitialLength, InflexibilityCoefficient, MaxForce);
    Anchor := AnchorPos;
end;

Procedure TRBAnchoredSpringForceGen.SetAnchor (const NewAnchorPosition: TVector3);
begin
    Anchor := NewAnchorPosition;
end;

Function TRBAnchoredSpringForceGen.UpdateForce(var Body: TRigidBody; const DeltaTime: Double): boolean;
Var ResultingForce: TVector3;
    ForceVectorLength: double;
begin
    Result := true;
    ResultingForce := V3Sub (Body.Position, Anchor);
    ForceVectorLength := (V3Length (ResultingForce) - RestLength) * InflexibilityCoeff;
    ResultingForce := V3Normalize (ResultingForce);
    ForceVectorLength := -ForceVectorLength;
    Body.AddForce (V3Mul (ResultingForce, ForceVectorLength));
    If Abs (ForceVectorLength) > ForceLimit then Result := false;
end;

{###############################################################################################
                              РЕЕСТР ДЛЯ ТЕЛ И ГЕНЕРАТОРОВ СИЛ
###############################################################################################}
Constructor TRegistry.Create;
begin
    inherited Create;
    SetLength (Entries, 0);
end;

Destructor TRegistry.Destroy;
Var I: Integer;
begin
    For I := High (Entries) downto 0 do
        RemoveEntry(I);
    inherited Destroy;
end;

Procedure TRegistry.AddEntry(const Entry: TRegistryEntry);
Var Len: Integer;
begin
    Len := Length (Entries);
    SetLength (Entries, Len + 1);
    Entries[Len] := Entry;
end;

Procedure TRegistry.RemoveEntry(const Index: Integer);
Var Last: Integer;
begin
    Last := High (Entries);
    Entries[Index] := Entries[Last];
    SetLength (Entries, Last);
end;

Procedure TRegistry.RemoveEntry(const Entry: TRegistryEntry);
Var I, Len: Integer;
    Remove: boolean;
begin
    Len := High (Entries);
    If Len < 0 then Exit;
    For I := 0 to Len do
    With Entries[I] do
    begin
        Remove := false;
        If Entry.Type_ = Type_ then
        Case Type_ of
            GRAVITY_BFG:
                If (Entry.GFG = GFG) and (Entry.Body_G = Body_G)
                then Remove := true;
            DRAG_BFG:
                If (Entry.DFG = DFG) and (Entry.Body_D = Body_D)
                then Remove := true;
            SPRING_BFG:
                If (Entry.SFG = SFG) and (Entry.Body_S1 = Body_S1) and (Entry.Body_S2 = Body_S2)
                then Remove := true;
            BUNGEE_BFG:
                If (Entry.BFG = BFG) and (Entry.Body_B1 = Body_B1) and (Entry.Body_B2 = Body_B2)
                then Remove := true;
            ANCHORED_SPRING_BFG:
                If (Entry.ASFG = ASFG) and (Entry.Body_AS = Body_AS)
                then Remove := true;
        End; {Case Type_ of}
        If Remove then
        begin
            Entries[I] := Entries[Len];
            SetLength (Entries, Len);
        end;
    end;
end;

Procedure TRegistry.ClearEntries;
begin
    SetLength (Entries, 0);
end;

Procedure TRegistry.UpdateForces;
Var Len, I: Integer;
begin
    Len := High (Entries);
    For I := 0 to Len do
    With Entries[I] do
    Case Type_ of
        GRAVITY_BFG: GFG.UpdateForce(Body_G, DeltaTime);
        DRAG_BFG: DFG.UpdateForce(Body_D, DeltaTime);
        SPRING_BFG: SFG.UpdateForce(Body_S1, Body_S2, DeltaTime);
        BUNGEE_BFG: BFG.UpdateForce(Body_B1, Body_B2, DeltaTime);
        ANCHORED_SPRING_BFG: ASFG.UpdateForce(Body_AS, DeltaTime);
    End;
end;

Procedure TRegistry.IntegrateEntireBodies(const DeltaTime: Double);
Var I, Len: Integer;
begin
    Len := High (Entries);
    For I := 0 to Len do
    With Entries[I] do
    Case Type_ of
        GRAVITY_BFG: Body_G.Integrate(DeltaTime);
        DRAG_BFG: Body_D.Integrate(DeltaTime);
        SPRING_BFG:
        begin
            Body_S1.Integrate(DeltaTime);
            Body_S2.Integrate(DeltaTime);
        end;
        BUNGEE_BFG:
        begin
            Body_B1.Integrate(DeltaTime);
            Body_B2.Integrate(DeltaTime);
        end;
        ANCHORED_SPRING_BFG: Body_AS.Integrate(DeltaTime);
    End;
end;

Procedure TRegistry.DrawAllSprings(const SpringColor, BungeeColor, AnchoredSpringColor: TGLArray4ub);
Var I: Integer;
begin
    glColor3ubv (@SpringColor);
    For I := 0 to High (Entries) do
        Case Entries[I].Type_ of
          SPRING_BFG:
            begin
                glColor3ubv (@SpringColor);
                glBegin (GL_LINES);
                    With Entries[I].Body_S1.Position do
                        glVertex3f (X, Y, Z);
                    With Entries[I].Body_S2.Position do
                        glVertex3f (X, Y, Z);
                glEnd;
            end;
          BUNGEE_BFG:
            begin
                glColor3ubv (@BungeeColor);
                glBegin (GL_LINES);
                    With Entries[I].Body_S1.Position do
                        glVertex3f (X, Y, Z);
                    With Entries[I].Body_S2.Position do
                        glVertex3f (X, Y, Z);
                glEnd;
            end;
          ANCHORED_SPRING_BFG:
            begin
                glColor3ubv (@AnchoredSpringColor);
                glBegin (GL_LINES);
                    With Entries[I].Body_S1.Position do
                        glVertex3f (X, Y, Z);
                    With Entries[I].Body_S2.Position do
                        glVertex3f (X, Y, Z);
                glEnd;
            end;
        End;
    glColor3ub (255, 255, 255);
end;


Procedure TRegistry.ClearAccums;
Var I, Len: Integer;
begin
    Len := High (Entries);
    For I := 0 to Len do
    With Entries[I] do
    Case Type_ of
        GRAVITY_BFG: Body_G.ClearAccumulators;
        DRAG_BFG: Body_D.ClearAccumulators;
        SPRING_BFG:
        begin
            Body_S1.ClearAccumulators;
            Body_S2.ClearAccumulators;
        end;
        BUNGEE_BFG:
        begin
            Body_B1.ClearAccumulators;
            Body_B2.ClearAccumulators;
        end;
        ANCHORED_SPRING_BFG: Body_AS.ClearAccumulators;
    End;
end;

end.
