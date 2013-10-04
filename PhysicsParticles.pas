unit PhysicsParticles;

interface
Uses dglOpenGL, PhysicsArifm;

Type

TParticle = class
  public
    PreviousPosition, Position: TVector3;
    ForceAccumulator: TVector3;
    Velocity: TVector3;
    Acceleration: TVector3;
    Mass: Float;
    Radius: Float;
    Texture: GLUInt;

    Constructor Create (const InitialPosition, InitialVelocity, InitialForce: TVector3;
        const ParticleTexture: GLUInt; const ParticleMass, ParticleRadius: Float);
    Procedure ClearForceAccumulator;
    Function GetMass: Float;
    Function GetInvMass: Float;
    Procedure AddForce (const Force: TVector3);
    Procedure Draw;
    Procedure Integrate (const DeltaTime: Float);
end;

TParticles = array of TParticle;

implementation

{###############################################################################################################
                         TParticle - класс, описывающий материальную частицу
###############################################################################################################}
Constructor TParticle.Create(const InitialPosition: TVector3; const InitialVelocity: TVector3;
    const InitialForce: TVector3; const ParticleTexture: Cardinal; const ParticleMass, ParticleRadius: Float);
begin
    inherited Create;
    Position := V3AddScaledVector (InitialPosition, InitialVelocity, 0.01);
    PreviousPosition := InitialPosition;
    Velocity := InitialVelocity;
    Mass := ParticleMass;
    ForceAccumulator := InitialForce;
    Acceleration := V3 (0);
    Texture := ParticleTexture;
    Radius := ParticleRadius;
end;

Procedure TParticle.ClearForceAccumulator;
begin
    ForceAccumulator := V3 (0);
end;

Function TParticle.GetMass: Float;
begin
    Result := Mass;
end;

Function TParticle.GetInvMass: Float;
begin
    Result := 1 / Mass;
end;

Procedure TParticle.AddForce(const Force: TVector3);
begin
    ForceAccumulator := V3Add (ForceAccumulator, Force);
end;

Procedure TParticle.Draw;
Var QuadricObj: PGLUQuadricObj;
begin
    QuadricObj := gluNewQuadric;
    //Разрешаем наложение текстуры на трёхмерный объект
    gluQuadricTexture (QuadricObj, TRUE);
    //Устанавливаем тип рисования объекта - заполнение
    gluQuadricDrawStyle (QuadricObj, GL_FILL);

    glBindTexture (GL_TEXTURE_2D, Texture);
    glPushMatrix;
    glTranslateF (Position.X, Position.Y, Position.Z);
    gluSphere (QuadricObj, Radius, 10, 10);
    glPopMatrix;

    //Удаляем объект
    gluDeleteQuadric (QuadricObj);
end;

Procedure TParticle.Integrate (const DeltaTime: Float);
begin
    //Сохраним текущую позицию частицы
    PreviousPosition := Position;
    {//Рассчитаем новую позицию частицы
    Position := V3AddScaledVector (V3Add (Position, V3Sub (Position, PreviousPosition)),
        ForceAccumulator, Sqr (DeltaTime)/Mass);
    //Сохраним текущую позицию в предыдущую}
    Acceleration := V3Div (ForceAccumulator, Mass);
    Velocity := V3AddScaledVector (Velocity, Acceleration, DeltaTime);
    Position := V3AddScaledVector (Position, Velocity, DeltaTime);
    ClearForceAccumulator;
end;

end.
