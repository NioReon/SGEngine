unit ParticleWorldStructure;

interface
Uses MapStructure,
     PhysicsContacts,
     Math,
     PhysicsArifm,
     ParticleForceGen,
     PhysicsParticles,
     Windows,
     SysUtils;

Type

TGenerators = record
    Force: record
        Gravity: array of TGravityForceGen;
        Drag: array of TDragForceGen;
        Spring: array of TSpringForceGen;
        AnchoredSpring: array of TAnchoredSpringForceGen;
        Bungee: array of TBungeeSpringForceGen;
        FloatingBody: array of TFloatingBodyForceGen;
        SoftBody: array of TSoftBodyForceGen;
    end;
    Contact: record
        StiffJoint: array of TStiffConnection;
        ParticleAndParticle: T2PContactGenerator;
        ParticleAndPlane: TPPlaneContactGenerator;
    end;
end;

TSoftBody = class
  public
    Particles: TParticles;
    ParticleRadius: Float;
    PlayerNumber: Word;
    ParticleCount: Cardinal;
    HeadPosition: TVector3;
    
    Constructor Create (const AHeadPosition: TVector3; const ParticleCount: Cardinal; const ParticleRadius: Float; const PlayerNumber: Word);
    Destructor Destroy; virtual;
    Procedure UpdateForce (const DeltaTime: Float);
end;

TBlobs = array of TSoftBody;

TParticleWorldStruc = class
  public
    ContactCountLimit: Cardinal;     //максимально допустимое число контактов
    Registrations: TParticleAndForceGenRegistry;      //хранит связи между частицами и генераторами сил
    ContactHandler: TContactHandler2P;      //хранит ссылку на обработчик контактов
    Contacts2P: TContacts2P;     //содержит сами контакты
    Bodies: TBlobs;              //мягкие тела
    Particles: TParticles;       //содержит частицы
    Generators: TGenerators;     //генераторы сил для частиц

    Constructor Create (const MaxContacts: byte; const MaxIterations: byte = 0);
    Destructor Destroy; virtual;
    Procedure ClearAllForces;
    Procedure AddParticle (const AParticle: TParticle; const ConnectWithForceGens: boolean = true);
    Procedure DrawParticles;
    Procedure IntegrateWorld (const DeltaTime: Float);
    Procedure UpdateForces (const DeltaTime: Float);
    Function GenerateContacts2P: Cardinal;
    Procedure Simulate(const DeltaTime: Float;
                       const FullSimCyclesPerFrame: byte;
                       const WorldSector: TSector);
end;

{######################################################################}
                            implementation
{######################################################################}

{######################################################################
                    TSoftBody (не описывает мир)

                                                      К.О.
######################################################################}
Constructor TSoftBody.Create(const AHeadPosition: TVector3; const ParticleCount: Cardinal; const ParticleRadius: Float; const PlayerNumber: Word);
Const BulletMass = 1;
Var I: Cardinal;
begin
    Inherited Create;
    SetLength (Particles, ParticleCount);
    For I := 0 to ParticleCount - 1 do
        Particles[i] := TParticle.Create(V3(HeadPosition.X+0.01*i,HeadPosition.Y+0.01*i,HeadPosition.Z+0.01*i),
            V3(0, 0, 0), V3Mul (Gravity, BulletMass), 0, BulletMass, ParticleRadius);
    HeadPosition := AHeadPosition;
    Self.ParticleRadius := ParticleRadius;
    Self.PlayerNumber := PlayerNumber;
end;

Destructor TSoftBody.Destroy;
Var I: Cardinal;
begin
    For I := 0 to Length (Particles) do
        Particles[i].Free;
    SetLength (Particles, 0);
    inherited Destroy;
end;

Procedure TSoftBody.UpdateForce (const DeltaTime: Float);
Var I: Cardinal;
begin
    For I := 0 to ParticleCount - 1 do
        Particles[i].Integrate(DeltaTime);
end;

{######################################################################
                    TParticleWorldStruc (описывает мир)
######################################################################}
Constructor TParticleWorldStruc.Create (const MaxContacts: byte; const MaxIterations: byte = 0);
begin
    Self := inherited Create;
    SetLength (Particles, 0);
    With Generators do
    begin
        With Force do
        begin
            SetLength (Gravity, 0);
            SetLength (Drag, 0);
            SetLength (Spring, 0);
            SetLength (Bungee, 0);
            SetLength (AnchoredSpring, 0);
            SetLength (FloatingBody, 0);
            SetLength (SoftBody, 0);
        end;
        With Contact do
        begin
            SetLength (StiffJoint, 0);
        end;
    end;
    Registrations := TParticleAndForceGenRegistry.Create;
    ContactHandler := TContactHandler2P.Create (1);
    Generators.Contact.ParticleAndParticle := T2PContactGenerator.Create;
    Generators.Contact.ParticleAndPlane := TPPlaneContactGenerator.Create;
end;

Destructor TParticleWorldStruc.Destroy;
Var I: LongInt;
begin
    //Очистить содержимое реестра связей частица-генератор силы
    Registrations.ClearEntries;

    //Удалить реестр
    Registrations.Free;

    //Удалить частицы
    For I := High (Particles) downto 0 do
        If Assigned (Particles[I]) then Particles[I].Free;
    SetLength (Particles, 0);

    //Удалить генераторы сил
    With Generators.Force do
    begin
        For I := High (Gravity) downto 0 do
            If Assigned (Gravity[I]) then Gravity[I].Free;
        SetLength (Gravity, 0);
        For I := High (Drag) downto 0 do
            If Assigned (Drag[I]) then Drag[I].Free;
        SetLength (Drag, 0);
        For I := High (Spring) downto 0 do
            If Assigned (Spring[I]) then Spring[I].Free;
        SetLength (Spring, 0);
        For I := High (AnchoredSpring) downto 0 do
            If Assigned (AnchoredSpring[I]) then AnchoredSpring[I].Free;
        SetLength (AnchoredSpring, 0);
        For I := High (Bungee) downto 0 do
            If Assigned (Bungee[I]) then Bungee[I].Free;
        SetLength (Bungee, 0);
        For I := High (FloatingBody) downto 0 do
            If Assigned (FloatingBody[I]) then FloatingBody[I].Free;
        SetLength (FloatingBody, 0);
        For I := High (SoftBody) downto 0 do
            If Assigned (SoftBody[I]) then SoftBody[I].Free;
        SetLength (SoftBody, 0);
    end;

    //Удалить контакты
    For I := 0 to High (Contacts2P) do
    begin
        Contacts2P[i].Free;
    end;
    For I := High (Contacts2P) downto 0 do
    begin
        Contacts2P[i].Free;
    end;
    //Удалить генераторы контактов частиц
    Generators.Contact.ParticleAndParticle.Free;
    Generators.Contact.ParticleAndPlane.Free;
    //Удалить контактный процессор (солвер)
    ContactHandler.Free;
    inherited Destroy;
end;

Procedure TParticleWorldStruc.ClearAllForces;
begin
    Registrations.ClearForceAccums;
end;

Procedure TParticleWorldStruc.AddParticle(const AParticle: TParticle; const ConnectWithForceGens: boolean = true);
Var I: Integer;
begin
    //Добавить частицу в общий список
    I := Length (Particles);
    SetLength (Particles, I + 1);
    Particles[I] := AParticle;

    //Связать частицу с первым генератором силы гравитационного притяжения к земле
    If ConnectWithForceGens then
    begin
        Registrations.AddEntry(Particles[I], Generators.Force.Gravity[0]);
    end;
end;

Procedure TParticleWorldStruc.DrawParticles;
Var I: Integer;
begin
    For I := High (Particles) downto 0 do
        Particles[I].Draw;
end;

Procedure TParticleWorldStruc.IntegrateWorld(const DeltaTime: Float);
begin
    Registrations.IntegrateEntireParticles(DeltaTime);
end;

Procedure TParticleWorldStruc.UpdateForces(const DeltaTime: Float);
begin
    Registrations.UpdateForces(DeltaTime);
end;

Function TParticleWorldStruc.GenerateContacts2P: Cardinal;
begin
    Result := 0;
end;

Procedure TParticleWorldStruc.Simulate(const DeltaTime: Float;
                                       const FullSimCyclesPerFrame: byte;
                                       const WorldSector: TSector);
Var I, Count: Integer;
begin
    Assert (FullSimCyclesPerFrame > 0);
    Registrations.ClearForceAccums;
    UpdateForces (DeltaTime);
    IntegrateWorld (DeltaTime);

    Count := High (Contacts2P);
    For I := Count downto 0 do
        Contacts2P[i].Free;
    SetLength (Contacts2P, 0);

    Generators.Contact.ParticleAndParticle.AddContacts(Contacts2P, Particles);

    Generators.Contact.ParticleAndPlane.AddContacts(Contacts2P, Particles, WorldSector);

    ContactHandler.SetIterationsCount (10*Length (Contacts2P));
    ContactHandler.HandleContacts (Contacts2P, DeltaTime);

    Count := High (Contacts2P);
    For I := Count downto 0 do
        Contacts2P[i].Free;
    SetLength (Contacts2P, 0);
end;

end.
