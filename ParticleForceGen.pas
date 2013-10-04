unit ParticleForceGen;

interface
Uses Math, DGLOpenGL, PhysicsParticles, PhysicsArifm;

CONST //UNUSED SO FAR
{Эти констатны определяют тип генератора силы}
    NIL_FORCE_GEN = $0;                //отсутствующий генератор силы
    GRAVITY_FORCE_GEN = $1;            //сила притяжения к земле
    DRAG_FORCE_GEN = $2;               //сила тащения
    SPRING_FORCE_GEN = $4;             //обычная пружина
    STIFF_JOINT_FORCE_GEN = $8;        //твёрдая связь
    ANCHORED_SPRING_FORCE_GEN = $10;   //закреплённая одним концом пружина
    BUNGEE_SPRING_FORCE_GEN = $20;     //канат
    FLOATING_BODY_FORCE_GEN = $40;     //Архимедова сила для тела, погруженного в жидкость
    FAKE_SRPING_FORCE_GEN = $80;       //упрощённый и, следовательно, не совсем точный генератор силы упругости пружины
    SOFT_BODY_FORCE_GEN = $100;        //генератор сил для "аморфного" тела

Type
TParticleForceGenerator = class         //общий класс-предок для генераторов сил
  public
    Procedure UpdateForce (Var AParticle: TParticle; const DeltaTime: double);
end;

TGravityForceGen = class (TParticleForceGenerator)        //генератор гравитационной силы
  public
    Gravity: TVector3;                         //текущее значение гравитации
    Constructor Create (Gravity: TVector3);
    Procedure UpdateForce (Var AParticle: TParticle; const DeltaTime: Double);
end;

TDragForceGen = class (TParticleForceGenerator)
  protected
    DragCoefficient, SquareDragCoefficient: double;  //коэффициент "тащения" и он же в квадрате
  public
    Constructor Create (const DragCoefficient: Double);
    Procedure UpdateForce (Var AParticle: TParticle; const DeltaTime: Double);
end;

TSpringForceGen = class (TParticleForceGenerator)   //F = -k*deltaL
  protected
    SpringInflexibilityCoefficient: double;         //коэффициент жёсткости пружины
    StartLength: double;                            //длина пружины в отсутствие сил
    ForceLimit: Double;                             //при превышении этой силы пружина "рвётся"
  public
    constructor Create (const k, RestLength, AForceLimit: double);
    Function UpdateForce (Var FirstParticle, SecondParticle: TParticle; const DeltaTime: Double): boolean;
end;

TAnchoredSpringForceGen = class (TSpringForceGen)    //у такой пружины один конец жёстко закреплён
  protected
    AAnchor: TVector3;
  public
    Constructor Create (const Anchor: TVector3; const SpringInflexibilityCoeff, StartLength, AForceLimit: Double);
    Function UpdateForce (Var AParticle: TParticle; const DeltaTime: Double): boolean;
end;

TBungeeSpringForceGen = class (TSpringForceGen)    //канат (двигает конец только в случае, если расстояние
  public                                           //между началом и концом стремится стать больше длины в состоянии покоя
    Function UpdateForce (Var FirstParticle, SecondParticle: TParticle; const DeltaTime: Double): boolean;
end;

TFloatingBodyForceGen = class (TParticleForceGenerator)     //тело находится в жидкости
  protected
    LiquidHeightAboveZero: Double;   //высота поверхности жидкости над нулевым уровнем по оси Y
    LiquidDensity: Double;    //плотность жидкости
    BodyVolume: Double;    //объём тела, погруженного в жидкость
    MaxLiquidDepth: Double;    //максимальная глубина данной "лужи" жидкости
  public
    Constructor Create (const LiquidHeight, BodyVolume, MaxLiquidDepth: Double; const LiquidDensity: Double = 1000);
    Procedure UpdateForce (Var AParticle: TParticle; const DeltaTime: Double);
end;

TStiffConnection = class
  protected
    RestLength: Double;
  public
    Constructor Create (const ZeroForceLength: Double);
    Procedure UpdatePosition (var Particle1, Particle2: TParticle);
end;

TEntry = record          //запись "реестра"; содержит информацию о частице
    AParticle: TParticle;
    AFG: TParticleForceGenerator;
end;

TPullForces = record
    PullBack: Double;
    DragTo: Double;
end;

TRestDistances = record
    Min, Max: Double;
end;

TSoftBodyForceGen = Class (TParticleForceGenerator)
  public
    Particles: TParticles;                  //частицы в теле
    PullForces: TPullForces;                //силы взаимного притяжения и отталкивания между частицами
    RestDistances: TRestDistances;          //минимальная и максимальная длина связи между соседними частицами в отсутствие сил
    IfJoinedForce: Double;                  //сила, применяемая к голове, если она соединена с другими частицами
    JointCountBeforeMaxForce: Cardinal;     //число частиц в теле, при котором к голове прикладывается максимальная сила
    MaxConnectionDistance: Double;          //длина соединения, сверх которой оно "лопнет"

    constructor Create (const AParticles: TParticles;
                        const APullForces: TPullForces;
                        const ARestDistances: TRestDistances;
                        const AIfJoinedForce: Double;
                        const AJointCountBeforeMaxForce: Cardinal;
                        const AMaxConnectionDistance: Double);
    Procedure UpdateForce (Var AParticle: TParticle; const DeltaTime: Double);
End;

TParticleAndForceGenRegistry = class       //реестр, содержащий информацию о частицах и связанных с ними генераторов сил
  protected
      EntriesGravity: array of record
                        AParticle: TParticle;
                        AFG: TGravityForceGen;
                       end;
      EntriesDrag: array of record
                      AParticle: TParticle;
                      AFG: TDragForceGen;
                    end;
      EntriesSpring: array of record
                        FirstParticle, SecondParticle: TParticle;
                        AFG: TSpringForceGen;
                      end;
      EntriesStiffConnection: array of record
                        FirstParticle, SecondParticle: TParticle;
                        Joint: TStiffConnection;
                      end;
      EntriesAnchoredSpring: array of record
                                AParticle: TParticle;
                                AFG: TAnchoredSpringForceGen;
                              end;
      EntriesBungeeSpring: array of  record
                          FirstParticle, SecondParticle: TParticle;
                          AFG: TBungeeSpringForceGen;
                       end;
      EntriesFloatingBody: array of record
                              AParticle: TParticle;
                              AFG: TFloatingBodyForceGen;
                            end;
      EntriesSoftBody: array of  record
                             AParticle: TParticle;
                             AFG: TSoftBodyForceGen;
                         end;
  public
    Constructor Create;
    Destructor Destroy; virtual;

    Procedure DrawColouredVectorAtPos (const AStart, Vector: TVector3; const R, G, B: byte);
    Procedure DrawAllSprings(const SpringColor, BungeeColor, AnchoredSpringColor: TGLArray4ub);

    Procedure AddEntry (const AParticle: TParticle; const AForceGen: TGravityForceGen); overload;
    Procedure AddEntry (const AParticle: TParticle; const AForceGen: TDragForceGen); overload;
    Procedure AddEntry (const FirstParticle, SecondParticle: TParticle; const AForceGen: TSpringForceGen); overload;
    Procedure AddEntry (const FirstParticle, SecondParticle: TParticle; const AJoint: TStiffConnection); overload;
    Procedure AddEntry (const AParticle: TParticle; const AForceGen: TAnchoredSpringForceGen); overload;
    Procedure AddEntry (const FirstParticle, SecondParticle: TParticle; const AForceGen: TBungeeSpringForceGen); overload;
    Procedure AddEntry (const AParticle: TParticle; const AForceGen: TFloatingBodyForceGen); overload;
    Procedure AddEntry (const AParticle: TParticle; const AForceGen: TSoftBodyForceGen); overload;

    Function RemoveEntry (const AParticle: TParticle; const AForceGen: TGravityForceGen): boolean; overload;
    Function RemoveEntry (const AParticle: TParticle; const AForceGen: TDragForceGen): boolean; overload;
    Function RemoveEntry (const FirstParticle, SecondParticle: TParticle; const AForceGen: TSpringForceGen): boolean; overload;
    Function RemoveEntry (const FirstParticle, SecondParticle: TParticle; const AJoint: TStiffConnection): boolean; overload;
    Function RemoveEntry (const AParticle: TParticle; const AForceGen: TAnchoredSpringForceGen): boolean; overload;
    Function RemoveEntry (const FirstParticle, SecondParticle: TParticle; const AForceGen: TBungeeSpringForceGen): boolean; overload;
    Function RemoveEntry (const AParticle: TParticle; const AForceGen: TFloatingBodyForceGen): boolean; overload;
    Function RemoveEntry (const AParticle: TParticle; const AForceGen: TSoftBodyForceGen): boolean; overload;

    Procedure ClearEntries;    //удалить СВЯЗИ между частицей и генератором силы
    Procedure UpdateForces (const DeltaTime: Double);     //обновить силы, действующие на частицу
    Procedure IntegrateEntireParticles (const DeltaTime: Double);     //произвести обновление частиц
    Procedure ClearForceAccums;    //очистка аккумуляторов сил перед новым кадром
end;

{##############################################################################}
                             implementation
{##############################################################################}

{##############################################################################}
{TParticleForceGenerator}
Procedure TParticleForceGenerator.UpdateForce(var AParticle: TParticle; const DeltaTime: Double);
begin
    {Заготовка для метода. Переопределяется в потомках этого класса.}
end;

{##############################################################################}
{TGravityForceGen}
Constructor TGravityForceGen.Create (Gravity: TVector3);
begin
    inherited Create;
    Self.Gravity := Gravity;
end;
//F = mg
Procedure TGravityForceGen.UpdateForce(Var AParticle: TParticle; const DeltaTime: Double);
begin
    AParticle.AddForce (V3Mul (Self.Gravity, AParticle.Mass));
end;

{##############################################################################}
{TDragForceGen}
Constructor TDragForceGen.Create(const DragCoefficient: Double);
begin
    inherited Create;
    Self.DragCoefficient := DragCoefficient;
    SquareDragCoefficient := DragCoefficient * DragCoefficient;
end;
//F = - (DragCoeff * (k1 + k2 * DragCoeff)) * Velocity;
Procedure TDragForceGen.UpdateForce(var AParticle: TParticle; const DeltaTime: Double);
Var ResultingForce: TVector3;
    DragCoeff: Double;
begin
    With AParticle do
        ResultingForce := V3Div (V3Sub (Position, PreviousPosition), DeltaTime);
    DragCoeff := V3Length (ResultingForce);
    DragCoeff := DragCoeff * (Self.DragCoefficient + Self.SquareDragCoefficient * DragCoeff);
    ResultingForce := V3Normalize (ResultingForce);
    DragCoeff := -DragCoeff;
    ResultingForce := V3Mul (ResultingForce, DragCoeff);
    AParticle.AddForce (ResultingForce);
end;

{##############################################################################}
{TSpringForceGen}
Constructor TSpringForceGen.Create(const k, RestLength, AForceLimit: Double);
begin
    inherited Create;
    SpringInflexibilityCoefficient := k;
    StartLength := RestLength;
    ForceLimit := AForceLimit;
end;

Function TSpringForceGen.UpdateForce(var FirstParticle, SecondParticle: TParticle; const DeltaTime: Double): boolean;
Var ResultingForce: TVector3;
    ForceVectorLength: double;
begin
    Result := true;
    ResultingForce := V3Sub (FirstParticle.Position, SecondParticle.Position);
    ForceVectorLength := (V3Length (ResultingForce) - StartLength) * SpringInflexibilityCoefficient;
    ResultingForce := V3Normalize (ResultingForce);
    ForceVectorLength := -ForceVectorLength / 2;
    ResultingForce := V3Mul (ResultingForce, ForceVectorLength);
    FirstParticle.AddForce (ResultingForce);
    SecondParticle.AddForce (V3Invert (ResultingForce));
    If Abs (ForceVectorLength) > ForceLimit then Result := false;
end;

{##############################################################################}
{TBungeeSpringForceGen}
Function TBungeeSpringForceGen.UpdateForce(var FirstParticle, SecondParticle: TParticle; const DeltaTime: Double): boolean;
Var ResultingForce: TVector3;
    ForceVectorLength: Double;
begin
    Result := true;
    ResultingForce := V3Sub (FirstParticle.Position, SecondParticle.Position);
    ForceVectorLength := V3Length (ResultingForce);
    If (ForceVectorLength <= StartLength) then Exit;
    ForceVectorLength := (StartLength - ForceVectorLength) * SpringInflexibilityCoefficient;
    ResultingForce := V3Normalize (ResultingForce);
    ForceVectorLength := -ForceVectorLength / 2;
    ResultingForce := V3Mul (ResultingForce, ForceVectorLength);
    FirstParticle.AddForce (V3Invert (ResultingForce));
    SecondParticle.AddForce (ResultingForce);
    If Abs (ForceVectorLength) > ForceLimit then Result := false;
end;

{##############################################################################}
{TFloatingBodyForceGen}
Constructor TFloatingBodyForceGen.Create(const LiquidHeight: Double; const BodyVolume: Double; const MaxLiquidDepth: Double; const LiquidDensity: Double = 1000);
begin
    inherited Create;
    LiquidHeightAboveZero := LiquidHeight;
    Self.LiquidDensity := LiquidDensity;
    Self.BodyVolume := BodyVolume;
    Self.MaxLiquidDepth := MaxLiquidDepth;
end;

Procedure TFloatingBodyForceGen.UpdateForce(var AParticle: TParticle; const DeltaTime: Double);
Var BodyDepth, Tmp: Double;    //координата тела по оси Y
begin
    BodyDepth := AParticle.Position.y;
    If (BodyDepth >= (LiquidHeightAboveZero + MaxLiquidDepth)) then Exit;
    Tmp := LiquidHeightAboveZero - MaxLiquidDepth;
    If (BodyDepth = Tmp) then
    begin
        BodyDepth := LiquidDensity * BodyVolume; //а с этого момента BodyDepth - сила Архимеда вдоль оси Y
    end
    else If (BodyDepth < Tmp) then Exit
    else
    begin
        BodyDepth := LiquidDensity * BodyVolume *
                     (BodyDepth - MaxLiquidDepth - LiquidHeightAboveZero) * 0.5 *
                     MaxLiquidDepth;
    end;
    AParticle.AddForce (V3 (0, BodyDepth, 0));
end;

{##############################################################################}
{TStiffConnection}
Constructor TStiffConnection.Create(const ZeroForceLength: Double);
begin
    inherited Create;
    RestLength := ZeroForceLength;
end;

Procedure TStiffConnection.UpdatePosition(var Particle1: TParticle; var Particle2: TParticle);
Var Delta: TVector3;
    DeltaStartLength, DeltaLength: Double;
begin
    Delta := V3Sub (Particle2.Position, Particle1.Position);
    DeltaStartLength := V3Length (Delta);
    DeltaLength := 0.5 * (DeltaStartLength - RestLength);

    Delta := V3Normalize (Delta);
    With Particle1 do
        Position := V3AddScaledVector (Position, Delta, DeltaLength);
    With Particle2 do
        Position := V3AddScaledVector (Position, Delta, -DeltaLength);
end;

{##############################################################################}
{TAnchoredSpringForceGenRegistry}
Constructor TAnchoredSpringForceGen.Create(const Anchor: TVector3; const SpringInflexibilityCoeff, StartLength, AForceLimit: Double);
begin
    inherited Create (SpringInflexibilityCoeff, StartLength, ForceLimit);
    AAnchor := Anchor;
    SpringInflexibilityCoefficient := SpringInflexibilityCoeff;
    Self.StartLength := StartLength;
end;

Function TAnchoredSpringForceGen.UpdateForce(var AParticle: TParticle; const DeltaTime: Double): boolean;
Var ResultingForce: TVector3;
    ForceVectorLength: double;
begin
    Result := true;
    ResultingForce := V3Sub (AParticle.Position, AAnchor);
    ForceVectorLength := (V3Length (ResultingForce) - StartLength) * SpringInflexibilityCoefficient;
    ResultingForce := V3Normalize (ResultingForce);
    ForceVectorLength := -ForceVectorLength;
    AParticle.AddForce (V3Mul (ResultingForce, ForceVectorLength));
    If Abs (ForceVectorLength) > ForceLimit then Result := false;
end;

{##############################################################################}
{TParticleAndForceGenRegistry}
Constructor TParticleAndForceGenRegistry.Create;
begin
    inherited Create;
    SetLength (EntriesGravity, 0);
    SetLength (EntriesDrag , 0);
    SetLength (EntriesSpring, 0);
    SetLength (EntriesStiffConnection, 0);
    SetLength (EntriesAnchoredSpring, 0);
    SetLength (EntriesBungeeSpring, 0);
    SetLength (EntriesFloatingBody, 0);
    SetLength (EntriesSoftBody , 0);
end;

Destructor TParticleAndForceGenRegistry.Destroy;
begin
    ClearEntries;
    Inherited Destroy;
end;

Procedure TParticleAndForceGenRegistry.DrawColouredVectorAtPos(const AStart: TVector3; const Vector: TVector3; const R: Byte; const G: Byte; const B: Byte);
begin
    glLineWidth (3);
    glColor3ub (R, G, B);
    glBegin (GL_LINES);
        glVertex3f (AStart.X, AStart.Y, AStart.Z);
        glVertex3f (Vector.X + AStart.X, Vector.Y + AStart.Y, Vector.Z + AStart.Z);
    glEnd;
    glColor3ub (255, 255, 255);
    glLineWidth (1);
end;

Procedure TParticleAndForceGenRegistry.DrawAllSprings(const SpringColor, BungeeColor, AnchoredSpringColor: TGLArray4ub);
Var I, Len: Integer;
begin
    glColor3ubv (@SpringColor);
    Len := Length (EntriesSpring) - 1;
    For I := 0 to Len do
        With EntriesSpring[i] do
        begin
            glBegin (GL_LINES);
                glVertex3f (FirstParticle.Position.X,
                            FirstParticle.Position.Y,
                            FirstParticle.Position.Z);
                glVertex3f (SecondParticle.Position.X,
                            SecondParticle.Position.Y,
                            SecondParticle.Position.Z);
            glEnd;
        end;

    glColor3ubv (@SpringColor);
    Len := Length (EntriesBungeeSpring) - 1;
    For I := 0 to Len do
        With EntriesBungeeSpring[i] do
        begin
            glBegin (GL_LINES);
                glVertex3f (FirstParticle.Position.X,
                            FirstParticle.Position.Y,
                            FirstParticle.Position.Z);
                glVertex3f (SecondParticle.Position.X,
                            SecondParticle.Position.Y,
                            SecondParticle.Position.Z);
            glEnd;
        end;

    glColor3ubv (@SpringColor);
    Len := Length (EntriesAnchoredSpring) - 1;
    For I := 0 to Len do
        With EntriesAnchoredSpring[i] do
        begin
            glBegin (GL_LINES);
                glVertex3f (AFG.AAnchor.X,
                            AFG.AAnchor.Y,
                            AFG.AAnchor.Z);
                glVertex3f (AParticle.Position.X,
                            AParticle.Position.Y,
                            AParticle.Position.Z);
            glEnd;
        end;
    glColor3ub (255, 255, 255);
end;

Procedure TParticleAndForceGenRegistry.AddEntry(const AParticle: TParticle; const AForceGen: TGravityForceGen);
Var Len: Cardinal;
begin
    Len := Length (EntriesGravity);
    SetLength (EntriesGravity, Len + 1);
    EntriesGravity [Len].AParticle := AParticle;
    EntriesGravity [Len].AFG := AForceGen;
end;

Procedure TParticleAndForceGenRegistry.AddEntry(const AParticle: TParticle; const AForceGen: TDragForceGen);
Var Len: Cardinal;
begin
    Len := Length (EntriesDrag);
    SetLength (EntriesDrag, Len + 1);
    EntriesDrag [Len].AParticle := AParticle;
    EntriesDrag [Len].AFG := AForceGen;
end;

Procedure TParticleAndForceGenRegistry.AddEntry(const FirstParticle, SecondParticle: TParticle; const AForceGen: TSpringForceGen);
Var Len: Cardinal;
begin
    Len := Length (EntriesSpring);
    SetLength (EntriesSpring, Len + 1);
    EntriesSpring [Len].FirstParticle := FirstParticle;
    EntriesSpring [Len].SecondParticle := SecondParticle;
    EntriesSpring [Len].AFG := AForceGen;
end;

Procedure TParticleAndForceGenRegistry.AddEntry (const FirstParticle, SecondParticle: TParticle; const AJoint: TStiffConnection);
Var Len: Cardinal;
begin
    Len := Length (EntriesStiffConnection);
    SetLength (EntriesStiffConnection, Len + 1);
    EntriesStiffConnection [Len].FirstParticle := FirstParticle;
    EntriesStiffConnection [Len].SecondParticle := SecondParticle;
    EntriesStiffConnection [Len].Joint := AJoint;
end;

Procedure TParticleAndForceGenRegistry.AddEntry(const AParticle: TParticle; const AForceGen: TAnchoredSpringForceGen);
Var Len: Cardinal;
begin
    Len := Length (EntriesAnchoredSpring);
    SetLength (EntriesAnchoredSpring, Len + 1);
    EntriesAnchoredSpring [Len].AParticle := AParticle;
    EntriesAnchoredSpring [Len].AFG := AForceGen;
end;

Procedure TParticleAndForceGenRegistry.AddEntry(const FirstParticle, SecondParticle: TParticle; const AForceGen: TBungeeSpringForceGen);
Var Len: Cardinal;
begin
    Len := Length (EntriesBungeeSpring);
    SetLength (EntriesBungeeSpring, Len + 1);
    EntriesBungeeSpring [Len].FirstParticle := FirstParticle;
    EntriesBungeeSpring [Len].SecondParticle := SecondParticle;
    EntriesBungeeSpring [Len].AFG := AForceGen;
end;

Procedure TParticleAndForceGenRegistry.AddEntry(const AParticle: TParticle; const AForceGen: TFloatingBodyForceGen);
Var Len: Cardinal;
begin
    Len := Length (EntriesFloatingBody);
    SetLength (EntriesFloatingBody, Len + 1);
    EntriesFloatingBody [Len].AParticle := AParticle;
    EntriesFloatingBody [Len].AFG := AForceGen;
end;

Procedure TParticleAndForceGenRegistry.AddEntry(const AParticle: TParticle; const AForceGen: TSoftBodyForceGen);
Var Len: Cardinal;
begin
    Len := Length (EntriesSoftBody);
    SetLength (EntriesSoftBody, Len + 1);
    EntriesSoftBody [Len].AParticle := AParticle;
    EntriesSoftBody [Len].AFG := AForceGen;
end;

Function TParticleAndForceGenRegistry.RemoveEntry(const AParticle: TParticle; const AForceGen: TGravityForceGen): boolean;
Var I, Len: Cardinal;
    Num: LongInt;
begin
    Len := Length (EntriesGravity);
    If Len = 0 then
    begin
        Result := false;
        Exit;
    end;
    Dec (Len);
    Num := -1;
    For I := 0 to Len do
    begin
        If (EntriesGravity[i].AFG = AForceGen) and (EntriesGravity[i].AParticle = AParticle) then
        begin
            Num := I;
            Break;
        end;
    end;
    If Num = -1 then
    begin
        Result := false;
        Exit;
    end;
    EntriesGravity[Num] := EntriesGravity[Len];
    SetLength (EntriesGravity, Len);
    Result := true;
end;

Function TParticleAndForceGenRegistry.RemoveEntry(const AParticle: TParticle; const AForceGen: TDragForceGen): boolean;
Var I, Len: Cardinal;
    Num: LongInt;
begin
    Len := Length (EntriesDrag);
    If Len = 0 then
    begin
        Result := false;
        Exit;
    end;
    Dec (Len);
    Num := -1;
    For I := 0 to Len do
    begin
        If (EntriesDrag[i].AFG = AForceGen) and (EntriesDrag[i].AParticle = AParticle) then
        begin
            Num := I;
            Break;
        end;
    end;
    If Num = -1 then
    begin
        Result := false;
        Exit;
    end;
    EntriesDrag[Num] := EntriesDrag[Len];
    SetLength (EntriesDrag, Len);
    Result := true;
end;

Function TParticleAndForceGenRegistry.RemoveEntry(const FirstParticle, SecondParticle: TParticle; const AForceGen: TSpringForceGen): boolean;
Var I, Len: Cardinal;
    Num: LongInt;
begin
    Len := Length (EntriesSpring);
    If Len = 0 then
    begin
        Result := false;
        Exit;
    end;
    Dec (Len);
    Num := -1;
    For I := 0 to Len do
    begin
        If (EntriesSpring[i].AFG = AForceGen) and
           (EntriesSpring[i].FirstParticle = FirstParticle) and
           (EntriesSpring[i].FirstParticle = FirstParticle) then
        begin
            Num := I;
            Break;
        end;
    end;
    If Num = -1 then
    begin
        Result := false;
        Exit;
    end;
    EntriesSpring[Num] := EntriesSpring[Len];
    SetLength (EntriesSpring, Len);
    Result := true;
end;

Function TParticleAndForceGenRegistry.RemoveEntry (const FirstParticle, SecondParticle: TParticle; const AJoint: TStiffConnection): boolean;
Var I, Len: Cardinal;
    Num: LongInt;
begin
    Len := Length (EntriesStiffConnection);
    If Len = 0 then
    begin
        Result := false;
        Exit;
    end;
    Dec (Len);
    Num := -1;
    For I := 0 to Len do
    begin
        If (EntriesStiffConnection[i].Joint = AJoint) and
           (EntriesStiffConnection[i].FirstParticle = FirstParticle) and
           (EntriesStiffConnection[i].FirstParticle = FirstParticle) then
        begin
            Num := I;
            Break;
        end;
    end;
    If Num = -1 then
    begin
        Result := false;
        Exit;
    end;
    EntriesStiffConnection[Num] := EntriesStiffConnection[Len];
    SetLength (EntriesStiffConnection, Len);
    Result := true;
end;

Function TParticleAndForceGenRegistry.RemoveEntry(const AParticle: TParticle; const AForceGen: TAnchoredSpringForceGen): boolean;
Var I, Len: Cardinal;
    Num: LongInt;
begin
    Len := Length (EntriesAnchoredSpring);
    If Len = 0 then
    begin
        Result := false;
        Exit;
    end;
    Dec (Len);
    Num := -1;
    For I := 0 to Len do
    begin
        If (EntriesAnchoredSpring[i].AFG = AForceGen) and (EntriesAnchoredSpring[i].AParticle = AParticle) then
        begin
            Num := I;
            Break;
        end;
    end;
    If Num = -1 then
    begin
        Result := false;
        Exit;
    end;
    EntriesAnchoredSpring[Num] := EntriesAnchoredSpring[Len];
    SetLength (EntriesAnchoredSpring, Len);
    Result := true;
end;

Function TParticleAndForceGenRegistry.RemoveEntry(const FirstParticle, SecondParticle: TParticle; const AForceGen: TBungeeSpringForceGen): boolean;
Var I, Len: Cardinal;
    Num: LongInt;
begin
    Len := Length (EntriesBungeeSpring);
    If Len = 0 then
    begin
        Result := false;
        Exit;
    end;
    Dec (Len);
    Num := -1;
    For I := 0 to Len do
    begin
        If (EntriesBungeeSpring[i].AFG = AForceGen) and (EntriesBungeeSpring[i].FirstParticle = FirstParticle) then
        begin
            Num := I;
            Break;
        end;
    end;
    If Num = -1 then
    begin
        Result := false;
        Exit;
    end;
    EntriesBungeeSpring[Num] := EntriesBungeeSpring[Len];
    SetLength (EntriesBungeeSpring, Len);
    Result := true;
end;

Function TParticleAndForceGenRegistry.RemoveEntry(const AParticle: TParticle; const AForceGen: TFloatingBodyForceGen): boolean;
Var I, Len: Cardinal;
    Num: LongInt;
begin
    Len := Length (EntriesFloatingBody);
    If Len = 0 then
    begin
        Result := false;
        Exit;
    end;
    Dec (Len);
    Num := -1;
    For I := 0 to Len do
    begin
        If (EntriesFloatingBody[i].AFG = AForceGen) and (EntriesFloatingBody[i].AParticle = AParticle) then
        begin
            Num := I;
            Break;
        end;
    end;
    If Num = -1 then
    begin
        Result := false;
        Exit;
    end;
    EntriesFloatingBody[Num] := EntriesFloatingBody[Len];
    SetLength (EntriesFloatingBody, Len);
    Result := true;
end;

Function TParticleAndForceGenRegistry.RemoveEntry(const AParticle: TParticle; const AForceGen: TSoftBodyForceGen): boolean;
Var I, Len: Cardinal;
    Num: LongInt;
begin
    Len := Length (EntriesSoftBody);
    If Len = 0 then
    begin
        Result := false;
        Exit;
    end;
    Dec (Len);
    Num := -1;
    For I := 0 to Len do
    begin
        If (EntriesSoftBody[i].AFG = AForceGen) and (EntriesSoftBody[i].AParticle = AParticle) then
        begin
            Num := I;
            Break;
        end;
    end;
    If Num = -1 then
    begin
        Result := false;
        Exit;
    end;
    EntriesSoftBody[Num] := EntriesSoftBody[Len];
    SetLength (EntriesSoftBody, Len);
    Result := true;
end;
{--------------------------------------------------}

Procedure TParticleAndForceGenRegistry.ClearEntries;
Var I: Cardinal;
    Len: Cardinal;
begin
    Len := Length (EntriesGravity);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesGravity [i].AParticle := nil;
            EntriesGravity [i].AFG := nil;
        end;
        SetLength (EntriesGravity, 0);
    end;
    {----------------------}
    Len := Length (EntriesDrag);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesDrag [i].AParticle := nil;
            EntriesDrag [i].AFG := nil;
        end;
        SetLength (EntriesDrag, 0);
    end;
    {----------------------}
    Len := Length (EntriesSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesSpring [i].FirstParticle := nil;
            EntriesSpring [i].SecondParticle := nil;
            EntriesSpring [i].AFG := nil;
        end;
        SetLength (EntriesSpring, 0);
    end;
    {----------------------}
    Len := Length (EntriesStiffConnection);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesStiffConnection [i].FirstParticle := nil;
            EntriesStiffConnection [i].SecondParticle := nil;
            EntriesStiffConnection [i].Joint := nil;
        end;
        SetLength (EntriesSpring, 0);
    end;
    {----------------------}
    Len := Length (EntriesAnchoredSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesAnchoredSpring [i].AParticle := nil;
            EntriesAnchoredSpring [i].AFG := nil;
        end;
        SetLength (EntriesAnchoredSpring, 0);
    end;
    {----------------------}
    Len := Length (EntriesBungeeSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesBungeeSpring [i].FirstParticle := nil;
            EntriesBungeeSpring [i].SecondParticle := nil;
            EntriesBungeeSpring [i].AFG := nil;
        end;
        SetLength (EntriesBungeeSpring, 0);
    end;
    {----------------------}
    Len := Length (EntriesFloatingBody);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesFloatingBody [i].AParticle := nil;
            EntriesFloatingBody [i].AFG := nil;
        end;
        SetLength (EntriesFloatingBody, 0);
    end;
    {----------------------}
    Len := Length (EntriesSoftBody);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesSoftBody [i].AParticle := nil;
            EntriesSoftBody [i].AFG := nil;
        end;
        SetLength (EntriesSoftBody, 0);
    end;
end;

Procedure TParticleAndForceGenRegistry.UpdateForces(const DeltaTime: Double);
Var I: Cardinal;
    Len: Cardinal;
begin
    Len := Length (EntriesGravity);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            If (EntriesGravity[i].AParticle <> nil) and (EntriesGravity[i].AFG <> nil) then
                EntriesGravity[i].AFG.UpdateForce(EntriesGravity[i].AParticle, DeltaTime);
    end;
    {------------------------------------------------}
    Len := Length (EntriesDrag);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            If (EntriesDrag[i].AParticle <> nil) and (EntriesDrag[i].AFG <> nil) then
                EntriesDrag[i].AFG.UpdateForce(EntriesDrag[i].AParticle, DeltaTime);
    end;
    {------------------------------------------------}
    Len := Length (EntriesSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            If (EntriesSpring[i].FirstParticle <> nil) and (EntriesSpring[i].SecondParticle <> nil) and (EntriesSpring[i].AFG <> nil) then
                If not EntriesSpring[i].AFG.UpdateForce(EntriesSpring[i].FirstParticle, EntriesSpring[i].SecondParticle, DeltaTime)
                then RemoveEntry (EntriesSpring[i].FirstParticle, EntriesSpring[i].SecondParticle, EntriesSpring[i].AFG);
    end;
    {------------------------------------------------}
    Len := Length (EntriesStiffConnection);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            If (EntriesStiffConnection[i].FirstParticle <> nil) and (EntriesStiffConnection[i].SecondParticle <> nil)
                and (EntriesStiffConnection[i].Joint <> nil) then
                EntriesStiffConnection[i].Joint.UpdatePosition(EntriesStiffConnection[i].FirstParticle,
                    EntriesStiffConnection[i].SecondParticle)
    end;
    {------------------------------------------------}
    Len := Length (EntriesAnchoredSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            If (EntriesAnchoredSpring[i].AParticle <> nil) and (EntriesAnchoredSpring[i].AFG <> nil) then
                If not EntriesAnchoredSpring[i].AFG.UpdateForce(EntriesAnchoredSpring[i].AParticle, DeltaTime)
                then RemoveEntry (EntriesAnchoredSpring[i].AParticle, EntriesAnchoredSpring[i].AFG);
    end;
    {------------------------------------------------}
    Len := Length (EntriesBungeeSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            If (EntriesBungeeSpring[i].FirstParticle <> nil) and
               (EntriesBungeeSpring[i].SecondParticle <> nil) and
               (EntriesBungeeSpring[i].AFG <> nil) then
                If not EntriesBungeeSpring[i].AFG.UpdateForce(EntriesBungeeSpring[i].FirstParticle,
                                                              EntriesBungeeSpring[i].SecondParticle,
                                                              DeltaTime)
                then RemoveEntry (EntriesBungeeSpring[i].FirstParticle,
                                  EntriesBungeeSpring[i].SecondParticle,
                                  EntriesBungeeSpring[i].AFG);
    end;
    {------------------------------------------------}
    Len := Length (EntriesFloatingBody);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            If (EntriesFloatingBody[i].AParticle <> nil) and (EntriesFloatingBody[i].AFG <> nil) then
                EntriesFloatingBody[i].AFG.UpdateForce(EntriesFloatingBody[i].AParticle, DeltaTime);
    end;
    {------------------------------------------------}
    Len := Length (EntriesSoftBody);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            If (EntriesSoftBody[i].AParticle <> nil) and (EntriesSoftBody[i].AFG <> nil) then
                EntriesSoftBody[i].AFG.UpdateForce(EntriesSoftBody[i].AParticle, DeltaTime);
    end;
end;

Procedure TParticleAndForceGenRegistry.IntegrateEntireParticles(const DeltaTime: Double);
Var I: Cardinal;
    Len: Cardinal;
begin
    Len := Length (EntriesGravity);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            EntriesGravity[i].AParticle.Integrate(DeltaTime);
    end;
    {-----------------------------------------}
     Len := Length (EntriesDrag);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            EntriesDrag[i].AParticle.Integrate(DeltaTime);
    end;
    {-----------------------------------------}
     Len := Length (EntriesSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesSpring[i].FirstParticle.Integrate(DeltaTime);
            EntriesSpring[i].SecondParticle.Integrate(DeltaTime);
        end;
    end;
    {-----------------------------------------}
     Len := Length (EntriesStiffConnection);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesStiffConnection[i].FirstParticle.Integrate(DeltaTime);
            EntriesStiffConnection[i].SecondParticle.Integrate(DeltaTime);
        end;
    end;
    {-----------------------------------------}
     Len := Length (EntriesAnchoredSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            EntriesAnchoredSpring[i].AParticle.Integrate(DeltaTime);
    end;
    {-----------------------------------------}
     Len := Length (EntriesBungeeSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesBungeeSpring[i].FirstParticle.Integrate(DeltaTime);
            EntriesBungeeSpring[i].SecondParticle.Integrate(DeltaTime);
        end;
    end;
    {-----------------------------------------}
     Len := Length (EntriesFloatingBody);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            EntriesFloatingBody[i].AParticle.Integrate(DeltaTime);
    end;
    {-----------------------------------------}
     Len := Length (EntriesSoftBody);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            EntriesSoftBody[i].AParticle.Integrate(DeltaTime);
    end;
end;

Procedure TParticleAndForceGenRegistry.ClearForceAccums;
Var I: Cardinal;
    Len: Cardinal;
begin
    Len := Length (EntriesGravity);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            EntriesGravity[i].AParticle.ClearForceAccumulator;
    end;
    {-----------------------------------------------}
    Len := Length (EntriesDrag);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
           EntriesDrag[i].AParticle.ClearForceAccumulator;
    end;
    {-----------------------------------------------}
    Len := Length (EntriesSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesSpring[i].FirstParticle.ClearForceAccumulator;
            EntriesSpring[i].SecondParticle.ClearForceAccumulator;
        end;
    end;
    {-----------------------------------------------}
    Len := Length (EntriesStiffConnection);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesStiffConnection[i].FirstParticle.ClearForceAccumulator;
            EntriesStiffConnection[i].SecondParticle.ClearForceAccumulator;
        end;
    end;
    {-----------------------------------------------}
    Len := Length (EntriesAnchoredSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            EntriesAnchoredSpring[i].AParticle.ClearForceAccumulator;
    end;
    {-----------------------------------------------}
    Len := Length (EntriesBungeeSpring);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
        begin
            EntriesBungeeSpring[i].FirstParticle.ClearForceAccumulator;
            EntriesBungeeSpring[i].SecondParticle.ClearForceAccumulator;
        end;
    end;
    {-----------------------------------------------}
    Len := Length (EntriesFloatingBody);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            EntriesFloatingBody[i].AParticle.ClearForceAccumulator;
    end;
    {-----------------------------------------------}
    Len := Length (EntriesSoftBody);
    If Len > 0 then
    begin
        Dec (Len);
        For I := 0 to Len do
            EntriesSoftBody[i].AParticle.ClearForceAccumulator;
    end;
end;

{##############################################################################
                                TSoftBodyForceGen
##############################################################################}
Constructor TSoftBodyForceGen.Create(const AParticles: TParticles; const APullForces: TPullForces; const ARestDistances: TRestDistances; const AIfJoinedForce: Double; const AJointCountBeforeMaxForce: Cardinal; const AMaxConnectionDistance: Double);
begin
    Particles := AParticles;
    PullForces := APullForces;
    RestDistances := ARestDistances;
    IfJoinedForce := AIfJoinedForce;
    JointCountBeforeMaxForce := AJointCountBeforeMaxForce;
    MaxConnectionDistance := AMaxConnectionDistance;
end;

Procedure TSoftBodyForceGen.UpdateForce(var AParticle: TParticle; const DeltaTime: Double);
Var ConnectionsCount,    //число соединений между частицами тела
    I: Cardinal;         //просто счётчик
    SeparationDistance: TVector3;    //расстояние между i-ой и данной частицами
    DistanceLength: Double;     //длина вектора расстояния между частицами
begin
    ConnectionsCount := 0;
    For I := 1 to Length (Particles) do
    begin
        SeparationDistance := V3Sub (Particles[i].Position, AParticle.Position);
        DistanceLength := V3Length (SeparationDistance);
        SeparationDistance := V3Normalize (SeparationDistance);

        If (DistanceLength < RestDistances.Min) then
        begin     //растолкнуть частицы
            DistanceLength := 1 - DistanceLength / RestDistances.Min;
            AParticle.AddForce(V3Mul (SeparationDistance, -((1-DistanceLength) * PullForces.PullBack)));
        end
        else If (DistanceLength > RestDistances.Max) then
        begin     //сблизить частицы
            DistanceLength := (DistanceLength - RestDistances.Max) * PullForces.DragTo / (Self.MaxConnectionDistance - RestDistances.Max);
            AParticle.AddForce(V3Mul (SeparationDistance, DistanceLength));
        end;
        Inc (ConnectionsCount);
    end;

    If (AParticle = Particles[0]) and (ConnectionsCount > 0) and (JointCountBeforeMaxForce > 0) then
    begin
        DistanceLength := IfJoinedForce * ConnectionsCount / JointCountBeforeMaxForce;
        If (DistanceLength > IfJoinedForce) then AParticle.AddForce(V3 (0, DistanceLength, 0));
    end;
end;

end.
