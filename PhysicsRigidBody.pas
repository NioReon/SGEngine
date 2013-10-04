unit PhysicsRigidBody;

interface

Uses dglOpenGL,
     MapStructure,
     Math,
     PhysicsArifm,
     Windows,
     SysUtils,
     Textures;
{#####################################################################}
                                 TYPE
{#####################################################################}

TBodyVertex = record
    Pos: TVector3;
    Mass: Single;
end;

TBodyVertexes = array of TBodyVertex;

TFaceVertexes = record
    {Вершины}
    Vertexes: array [0..2] of Cardinal;
    {Текстурные координаты}
    TexCoords: array [0..2] of TTextureCoord;
    {Нормаль}
    Normal: TVector3;
    {Хэндл текстуры}
    TextureIndex: GLUint;
end;

TRib = array [0..1] of Cardinal;

TRigidBody = class
  public
    {Частицы, составляющие тело}
    GlobalVertexes, OriginalLocalVertexes: TBodyVertexes;
    {Рёбра, составляющие тело}
    Ribs: array of TRib;
    {Полигоны тела}
    Faces: array of TFaceVertexes;
    {Масса тела}
    Mass: Float;
    {Положение центра масс тела в мировых координатах}
    Position: TVector3;
    {Угловая ориентация тела в мировых координатах}
    Orientation: TQuaternion;
    {Линейная скорость тела}
    Velocity: TVector3;
    {Угловая скорость тела}
    AngularVelocity: TVector3;
    {Угловое ускорение тела}
    AngularAcceleration: TVector3;
    {Матрица конвертации локальных координат тела в мировые координаты}
    TransformationMatrix: TMatrix3x4;
    {Инвертированный тензор инерции}
    InvInertiaTensor: TMatrix3x3;
    {Линейное затухание скорости}
    LinearDamping: Float;
    {Затухание для вращения}
    RotationDamping: Float;
    {Инвертированный тензор инерции тела в мировых координатах}
    InvInertiaTensorInWorldCoords: TMatrix3x3;
    {Равнодействующая внешних сил}
    ForceAccumulator: TVector3;
    {Равнодействующая для ускорения вращения}
    RotationAccumulator: TVector3;
    {Линейное ускорение тела}
    Acceleration: TVector3;
    {Предыдущее значение ускорения тела}
    PreviousAcceleration: TVector3;
    {Может ли тело покоиться}
    CanSleep: boolean;
    {Обновлять ли параметры тела}
    DoUpdate: boolean;
    {Пороговая величина, ниже которой тело считается неподвижным}
    SleepEpsilon: Float;
    {Кинетическая энергия тела}
    CineticEnergy: Float;

    Function GetFarthestPointInDirection (const Direction: TVector3): TBodyVertex;
    Procedure CalculateBodyData;
    Procedure SetInertiaTensor (const ATensor: TMatrix3x3);
    Procedure Integrate (DeltaTime: Float);
    Procedure SetMass (const NewMass: Float);
    Function GetMass: Float;
    Procedure SetInvertedMass (const NewMass: Float);
    Function GetInvertedMass: Float;

    Function GetLocalInertiaTensor: TMatrix3x3;
    Procedure SetLocalInertiaTensor (const ATensor: TMatrix3x3);
    Function GetInvLocalInertiaTensor: TMatrix3x3;
    Procedure SetInvLocalInertiaTensor (const ATensor: TMatrix3x3);
    Function GetWorldInertiaTensor: TMatrix3x3;
    Function GetWorldInvInertiaTensor: TMatrix3x3;
    Procedure SetWorldInertiaTensor (const ATensor: TMatrix3x3);
    Procedure SetWorldInvInertiaTensor (const ATensor: TMatrix3x3);

    Procedure SetDamping (const LinearDamping, AngularDamping: Float);
    Function GetLinearDamping: Float;
    Function GetAngularDamping: Float;
    Procedure SetPosition (const APosition: TVector3);
    Function GetPosition: TVector3;
    Procedure SetAcceleration (const AAcceleration: TVector3);
    Function GetAcceleration: TVector3;
    Procedure SetVelocity (const AVelocity: TVector3);
    Function GetVelocity: TVector3;
    Procedure SetAngularVelocity (const AVelocity: TVector3);
    Function GetAngularVelocity: TVector3;
    Procedure SetAngularAcceleration (const AAcceleration: TVector3);
    Function GetAngularAcceleration: TVector3;

    Procedure SetOrientation (const AOrientation: TQuaternion);
    Procedure GetOrientation (Var A: TQuaternion); overload;
    Procedure GetOrientation (Var AMatrix: TMatrix3x3); overload;

    Procedure GetTransformMatrix (Var AMatrix: TMatrix3x4); overload;
    Procedure GetTransformMatrix (Var AMatrix: TGlArray16F); overload;
    Procedure GetGLTransformMatrix (Var AMatrix: TGlArray16F);

    Function GetPointInLocalSpace (const Point: TVector3): TVector3;
    Function GetPointInWorldSpace (const Point: TVector3): TVector3;
    Function GetDirectionInLocalSpace (const Direction: TVector3): TVector3;
    Function GetDirectionInWorldSpace (const Direction: TVector3): TVector3;

    Procedure ClearForceAccumulator;
    Procedure ClearRotationAccumulator;
    Procedure ClearAccumulators;

    Procedure AddRotationForce (const DeltaForce: TVector3);
    Procedure AddAngularVelocity (const DeltaRotation: TVector3);

    Procedure AddForce (const DeltaForce: TVector3);
    Procedure AddForceAtPoint (const DeltaForce, Point: TVector3);
    Procedure AddForceAtBodyPoint (const DeltaForce, Point: TVector3);

    Function GetCanBeUpdated: Boolean;
    Procedure SetCanBeUpdated (const AValue: boolean);

    Function GetCanSleep: Boolean;
    Procedure SetCanSleep (const AValue: Boolean);

    Procedure SetSleepEpsilon(const value: Float);
    Function GetSleepEpsilon: Float;

    Procedure Draw;

    Procedure CalculateInertiaTensor;
    Procedure CalculateTotalMass;
    Procedure CalculateMassCenter;

    Procedure LoadBodyDataFromFile (const FileName: string);

    Constructor Create (const AOrientation: TQuaternion;
                        const AVelocity, AAcceleration,
                        AAngularVelocity, AAngularAcceleration: TVector3;
                        const ACanSleep, ADoUpdate: Boolean;
                        const ALinearDamping, ARotationDamping: Float;
                        const ASleepEps: Float;
                        const PathToConfigFile: string);
end;

PRigidBody = ^TRigidBody;

TRigidBodies = array of TRigidBody;
PRigidBodies = array of PRigidBody;

Var TexturePaths: array of string;   //массив с названиями файлов текстур
    TexturePseudoVars: array of string;    //псевдопеременные текстур
    TextureHandles: array of GLUint;    //ссылки на текстуры

implementation

Procedure glBindTexture(target: GLenum; texture: GLuint); stdcall; external opengl32;

{Support Mapping: вернуть точку тела в мировых координатах,
 имеющую наибольшую проекцию на заданное направление}

Function TRigidBody.GetFarthestPointInDirection (const Direction: TVector3): TBodyVertex;
Var {Максимальная среди вычисленных длина проекции вершин на вектор направления}
    MaxDist: Float;
    {Длина проекции текущей вершины на вектор направления}
    CurrentDist: Float;
    {Счётчик}
    I, Index: Integer;
begin
    {Проецируем первую вершину и считаем результат максимумом}
    MaxDist := V3ScalarProduct (GlobalVertexes[0].Pos, Direction);
    Index := 0;
    {Проецируем остальные вершины и ищем новый максимум}
    For I := 1 to High (GlobalVertexes) do
    begin
        CurrentDist := V3ScalarProduct (GlobalVertexes[I].Pos, Direction);
        If CurrentDist > MaxDist then
        begin
            MaxDist := CurrentDist;
            Index := I;
        end;
    end;
    Result := GlobalVertexes[Index];
end;

Procedure TRigidBody.SetInertiaTensor(const ATensor: TMatrix3x3);
begin
    InvInertiaTensor := PhysicsArifm.Mat3x3Invert(ATensor);
end;

Procedure TRigidBody.CalculateBodyData;
begin
    Orientation:= QuatNormalize (Orientation);
    TransformationMatrix := OrientAndPosToMatrix3x4 (Orientation, Position);
    InvInertiaTensorInWorldCoords := Mat3x3TransformByQuaternion (Orientation,
                                     InvInertiaTensor, TransformationMatrix);
end;

Procedure TRigidBody.Integrate(DeltaTime: Float);
Var Tmp: Float;
    I: Integer;
begin
    if DeltaTime = +Infinity then
        DeltaTime := 0.01;
    If (not DoUpdate) or (Mass <= 0) or (DeltaTime <= 0)
    then Exit;
    {Рассчитать линейное ускорение тела}
    Acceleration := V3Div (ForceAccumulator, Mass);
    {Получить новую линейную скорость}
    Velocity := V3AddScaledVector (Velocity, Acceleration, DeltaTime);
    {Обновить угловое ускорение}
    AngularAcceleration := Mat3x3Mul (InvInertiaTensorInWorldCoords, RotationAccumulator);
    {Обновить угловую скорость}
    AngularVelocity := V3AddScaledVector (AngularVelocity, AngularAcceleration, DeltaTime);
    {Предотвратить эффект "тащения"}
    Velocity := V3Mul (Velocity, Power (LinearDamping, DeltaTime));
    AngularVelocity := V3Mul (AngularVelocity, Power (RotationDamping, DeltaTime));
    {Рассчитать смещение центра масс и вершин при линейном движении}
    {Обновить положение и ориентацию в пространстве}
    Position := V3Add (Position, V3Mul (Velocity, DeltaTime));
    Orientation := QuatAddScaledVector (Orientation, AngularVelocity, DeltaTime);
    {Нормализовать ориентацию, а также обновить матрицы}
    CalculateBodyData;
    {Обновить угловую ориентацию точек тела}
    For I := 0 to High (OriginalLocalVertexes) do
    With GlobalVertexes[i] do
        Pos := Mat3x4Mul (TransformationMatrix, OriginalLocalVertexes[i].Pos);
    {Пересчитать нормали к фейсам}
    For I := 0 to High (Faces) do
    With Faces[i] do
        Normal := GetNormalToPlane (GlobalVertexes[Vertexes[0]].Pos,
                                    GlobalVertexes[Vertexes[1]].Pos,
                                    GlobalVertexes[Vertexes[2]].Pos);
    {Очистить аккумуляторы равнодействующих}
    ClearAccumulators;
    {Обновить кинетическую энергию тела и, возможно, перевести его в неподвижное состояние}
    If CanSleep then
    begin
        CineticEnergy := 0.5 * (Mass * V3SquareLength (Velocity)
            + V3Length (Mat3x3Mul (GetLocalInertiaTensor,
                              V3ComponentWiseSquare (AngularVelocity))));
        If (CineticEnergy < SleepEpsilon)
        then SetCanBeUpdated (False)
        else
        begin
            Tmp := SleepEpsilon * 10;
            If (CineticEnergy > Tmp) then CineticEnergy := Tmp;
        end;
    end;
end;

Procedure TRigidBody.SetMass(const NewMass: Float);
begin
    Mass := NewMass;
end;

Function TRigidBody.GetMass: Float;
begin
    Result := Mass;
end;

Procedure TRigidBody.SetInvertedMass (const NewMass: Float);
begin
    Mass := 1 / NewMass;
end;

Function TRigidBody.GetInvertedMass: Float;
begin
    Result := 1 / Mass;
end;

Function TRigidBody.GetLocalInertiaTensor: TMatrix3x3;
begin
    Result := Mat3x3Invert (InvInertiaTensor);
end;

Procedure TRigidBody.SetLocalInertiaTensor (const ATensor: TMatrix3x3);
begin
    InvInertiaTensor := Mat3x3Invert (ATensor);
end;

Function TRigidBody.GetInvLocalInertiaTensor: TMatrix3x3;
begin
    Result := InvInertiaTensor;
end;

Procedure TRigidBody.SetInvLocalInertiaTensor (const ATensor: TMatrix3x3);
begin
    InvInertiaTensor := ATensor;
end;

Function TRigidBody.GetWorldInertiaTensor: TMatrix3x3;
begin
    Result := Mat3x3Invert (InvInertiaTensorInWorldCoords);
end;

Function TRigidBody.GetWorldInvInertiaTensor: TMatrix3x3;
begin
    Result := InvInertiaTensorInWorldCoords;
end;

Procedure TRigidBody.SetWorldInertiaTensor (const ATensor: TMatrix3x3);
begin
    InvInertiaTensorInWorldCoords := Mat3x3Invert (ATensor);
end;

Procedure TRigidBody.SetWorldInvInertiaTensor (const ATensor: TMatrix3x3);
begin
    InvInertiaTensorInWorldCoords := ATensor;
end;

Procedure TRigidBody.SetDamping (const LinearDamping, AngularDamping: Float);
begin
    Self.LinearDamping := LinearDamping;
    Self.RotationDamping := AngularDamping;
end;

Function TRigidBody.GetLinearDamping: Float;
begin
    Result := LinearDamping;
end;

Function TRigidBody.GetAngularDamping: Float;
begin
    Result := RotationDamping;
end;

Procedure TRigidBody.SetPosition (const APosition: TVector3);
begin
    Position := APosition;
end;

Function TRigidBody.GetPosition: TVector3;
begin
    Result := Position;
end;

Procedure TRigidBody.SetAcceleration (const AAcceleration: TVector3);
begin
    Acceleration := AAcceleration;
end;

Function TRigidBody.GetAcceleration: TVector3;
begin
    Result := Acceleration;
end;

Procedure TRigidBody.SetVelocity (const AVelocity: TVector3);
begin
    Velocity := AVelocity;
end;

Function TRigidBody.GetVelocity: TVector3;
begin
    Result := Velocity;
end;

Procedure TRigidBody.SetAngularVelocity (const AVelocity: TVector3);
begin
    AngularVelocity := AVelocity;
end;

Function TRigidBody.GetAngularVelocity: TVector3;
begin
    Result := AngularVelocity;
end;

Procedure TRigidBody.SetAngularAcceleration(const AAcceleration: TVector3);
begin
    AngularAcceleration := AAcceleration;
end;

Function TRigidBody.GetAngularAcceleration: TVector3;
begin
    Result := AngularAcceleration;
end;

Procedure TRigidBody.SetOrientation (const AOrientation: TQuaternion);
begin
    Orientation := QuatNormalize (AOrientation);
end;

Procedure TRigidBody.GetOrientation (Var A: TQuaternion);
begin
    A := QuatNormalize (Orientation);
end;

Procedure TRigidBody.GetOrientation(Var AMatrix: TMatrix3x3);
begin
    With TransformationMatrix do
    begin
        AMatrix.Data[0] := Data[0];
        AMatrix.Data[1] := Data[1];
        AMatrix.Data[2] := Data[2];

        AMatrix.Data[3] := Data[4];
        AMatrix.Data[4] := Data[5];
        AMatrix.Data[5] := Data[6];

        AMatrix.Data[6] := Data[8];
        AMatrix.Data[7] := Data[9];
        AMatrix.Data[8] := Data[10];
    end;
end;

Procedure TRigidBody.GetTransformMatrix (Var AMatrix: TMatrix3x4);
begin
    AMatrix := TransformationMatrix;
end;

Procedure TRigidBody.GetTransformMatrix (Var AMatrix: TGlArray16F);
Var I: byte;
begin
    For I := 0 to 11 do
        AMatrix[i] := TransformationMatrix.Data[i];
    AMatrix[12] := 0;
    AMatrix[13] := 0;
    AMatrix[14] := 0;
    AMatrix[15] := 1;
end;

Procedure TRigidBody.GetGLTransformMatrix (Var AMatrix: TGlArray16F);
begin
    With TransformationMatrix do
    begin
        AMatrix[0] := Data[0];
        AMatrix[1] := Data[4];
        AMatrix[2] := Data[8];
        AMatrix[3] := 0;

        AMatrix[4] := Data[1];
        AMatrix[5] := Data[5];
        AMatrix[6] := Data[9];
        AMatrix[7] := 0;

        AMatrix[8] := Data[2];
        AMatrix[9] := Data[6];
        AMatrix[10] := Data[10];
        AMatrix[11] := 0;

        AMatrix[12] := Data[3];
        AMatrix[13] := Data[7];
        AMatrix[14] := Data[11];
        AMatrix[15] := 1;
    end;
end;

Procedure TRigidBody.AddForce (const DeltaForce: TVector3);
begin
    ForceAccumulator := V3Add (ForceAccumulator, DeltaForce);
end;

Procedure TRigidBody.AddRotationForce (const DeltaForce: TVector3);
begin
    RotationAccumulator := V3Add (RotationAccumulator, DeltaForce);
end;

Procedure TRigidBody.AddAngularVelocity (const DeltaRotation: TVector3);
begin
    AngularVelocity := V3Add (AngularVelocity, DeltaRotation);
end;

Function TRigidbody.GetPointInLocalSpace(const Point: TVector3): TVector3;
begin
    Result := Mat3x4MulInvV3 (TransformationMatrix, Point);
end;

Function TRigidBody.GetPointInWorldSpace(const Point: TVector3): TVector3;
begin
    Result := Mat3x4Mul (TransformationMatrix, Point);
end;

Function TRigidBody.GetDirectionInLocalSpace (const Direction: TVector3): TVector3;
begin
    Result := Mat3x4MulInvDirV3 (TransformationMatrix, Direction);
end;

Function TRigidBody.GetDirectionInWorldSpace(const Direction: TVector3): TVector3;
begin
    Result := Mat3x4MulDirV3 (TransformationMatrix, Direction);
end;

Procedure TRigidBody.ClearForceAccumulator;
begin
    ForceAccumulator := V3 (0, 0, 0);
end;

Procedure TRigidBody.ClearRotationAccumulator;
begin
    RotationAccumulator := V3 (0, 0, 0);
end;

Procedure TRigidBody.ClearAccumulators;
begin
    ClearForceAccumulator;
    ClearRotationAccumulator;
end;

Procedure TRigidBody.AddForceAtPoint(const DeltaForce: TVector3; const Point: TVector3);
Var Pt: TVector3;
begin
    {Перейти к системе отсчёта для центра масс тела}
    Pt:= V3Sub (Point, position);
    ForceAccumulator := V3Add (ForceAccumulator, DeltaForce);
    RotationAccumulator := V3Add (RotationAccumulator, V3Mul (Pt, DeltaForce));
    DoUpdate:= true;
end;

Procedure TRigidBody.AddForceAtBodyPoint(const DeltaForce: TVector3; const Point: TVector3);
begin
    AddForceAtPoint (DeltaForce, GetPointInWorldSpace (Point));
    DoUpdate:= true;
end;

Procedure TRigidBody.SetCanBeUpdated(const AValue: Boolean);
begin
    DoUpdate := AValue;
    If not AValue then
    begin
        Velocity := V3 (0, 0, 0);
        AngularVelocity := V3 (0, 0, 0);
    end
    else CineticEnergy := 2 * SleepEpsilon;
end;

Function TRigidBody.GetCanBeUpdated: boolean;
begin
    Result := DoUpdate;
end;

Function TRigidBody.GetCanSleep: Boolean;
begin
    Result := CanSleep;
end;

Procedure TRigidBody.SetCanSleep(const AValue: Boolean);
begin
    CanSleep := AValue;
    If not (DoUpdate and CanSleep) then SetCanBeUpdated (GetCanBeUpdated);
end;

Procedure TRigidBody.SetSleepEpsilon(const Value: Float);
begin
    SleepEpsilon := Value;
end;

Function TRigidBody.GetSleepEpsilon: Float;
begin
    Result := SleepEpsilon;
end;

Procedure TRigidBody.Draw;
Var Temp: TGLArray16F;
    I, J: Integer;
    CurrentTexture: GLUint;
begin
    glPushMatrix;
    {Настройка перспективы}
    glMatrixMode (GL_MODELVIEW);
    Mat3x4ToGLArray (TransformationMatrix, Temp);
    //glLoadIdentity;
    glMultMatrixf (@Temp);
    {/Настройка перспективы}
    {Отрисовка}
    CurrentTexture := Faces[0].TextureIndex;
    glBindTexture (GL_TEXTURE_2D, CurrentTexture);
    For I := 0 to High (Faces) do
    With Faces[I] do
    begin
        If CurrentTexture <> TextureIndex then
        begin
            CurrentTexture := TextureIndex;
            glBindTexture (GL_TEXTURE_2D, CurrentTexture)
        end
        else glBindTexture (GL_TEXTURE_2D, TextureIndex);

        glBegin (GL_TRIANGLES);
            For J := 0 to 2 do
            begin
                With Normal do
                    glNormal3f (X, Y, Z);
                With TexCoords[J] do
                    glTexCoord2f (X, Y);
                With OriginalLocalVertexes[Vertexes[J]].Pos do
                    glVertex3f (X, Y, Z);
            end;
        glEnd;
    end;
    {/Отрисовка}
    glPopMatrix;
    glBindTexture (GL_TEXTURE_2D, 0);
end;

Procedure TRigidBody.CalculateInertiaTensor;
Var
    {Представление тензора инерции в стандартном виде}
    XX, YY, ZZ, XY, XZ, ZY: Single;
    {Число вершин в теле}
    Count,
    I: Integer;
    InertiaTensor: TMatrix3x3;
begin
    {XX, YY, ZZ - моменты инерции относительно основных осей тела}
    XX := 0; XY := 0; XZ := 0;
    YY := 0; ZY := 0; ZZ := 0;
    Count := High (OriginalLocalVertexes);

    For I := 0 to Count do
    With OriginalLocalVertexes[I] do
    begin
        XX := XX + Mass * (Sqr (Pos.Y) + Sqr (Pos.Z));
        YY := YY + Mass * (Sqr (Pos.X) + Sqr (Pos.Z));
        ZZ := ZZ + Mass * (Sqr (Pos.X) + Sqr (Pos.Y));

        XY := XY + Mass * (V3SquareLength (Pos) - Pos.X * Pos.Y);
        XZ := XZ + Mass * (V3SquareLength (Pos) - Pos.X * Pos.Z);
        ZY := ZY + Mass * (V3SquareLength (Pos) - Pos.Z * Pos.Y);
    end;
    {
    Тензор инерции - матрица 3*3:
      Jxx  -Jxy  -Jxz
     -Jxy   Jyy  -Jyz
     -Jxz  -Jyz   Jzz

    Тензор инерции связывает момент импульса L
    тела и его угловую скорость w:
    L = Jw
    }
    InertiaTensor.Data[0] := XX;
    InertiaTensor.Data[1] := -XY;
    InertiaTensor.Data[2] := -XZ;

    InertiaTensor.Data[3] := -XY;
    InertiaTensor.Data[4] := YY;
    InertiaTensor.Data[5] := -ZY;

    InertiaTensor.Data[6] := -XZ;
    InertiaTensor.Data[7] := -ZY;
    InertiaTensor.Data[8] := ZZ;

    SetLocalInertiaTensor (InertiaTensor);
end;

Procedure TRigidBody.CalculateTotalMass;
Var I: Integer;
begin
    Mass := 0;
    For I := 0 to High (GlobalVertexes) do
        Mass := Mass + GlobalVertexes[i].Mass;
end;

Procedure TRigidBody.CalculateMassCenter;
Var I, Count: Integer;
    TempCenter: TVector3;
begin
    ZeroMemory (@TempCenter, SizeOf (TempCenter));
    Count := High (GlobalVertexes);
    For I := 0 to Count do
    With GlobalVertexes[i] do
        TempCenter := V3AddScaledVector (TempCenter, Pos, Mass);
    Position := V3Div (TempCenter, Mass);

    SetLength (OriginalLocalVertexes, Count + 1);
    For I := 0 to Count do
    With OriginalLocalVertexes[i] do
    begin
        Pos := V3Sub (GlobalVertexes[i].Pos, Position);
        Mass := GlobalVertexes[i].Mass;
    end;
end;

{################## ЗАГРУЗКА ДАННЫХ ТЕЛА #################################}

procedure ReadStr(var f: textfile; var s: string);
begin
  readln(f,s);
  while ((copy(s, 1, 1) = '/') or (length(s) = 0)) do
    readln(f,s);
end;

Function TexNameToTexHandle (TextureName: String = ''): Integer;
Var I: Integer;
begin
    TextureName := Trim (LowerCase (TextureName));
    Result := -1;
    If TextureName = '' then Exit;
    For I := 0 to High (TexturePseudoVars) do
        If TextureName = TexturePseudoVars[i] then
        begin
            Result := I;
            Break;
        end;
end;

Function ReadVertex (S: String): TBodyVertex;
Var I: word;
begin
    S := Trim (S);
    {Масса}
    I := Pos (' ', S);
    Result.Mass := StrToFloat (Trim (Copy (S, 1, I)));
    Delete (S, 1, I);
    {Мировая координата X}
    I := Pos (' ', S);
    Result.Pos.x := StrToFloat (Trim (Copy (S, 1, I)));
    Delete (S, 1, I);
    {Мировая координата Y}
    I := Pos (' ', S);
    Result.Pos.y := StrToFloat (Trim (Copy (S, 1, I)));
    Delete (S, 1, I);
    {Мировая координата Z}
    Result.Pos.z := StrToFloat (Trim (S));
end;

Function ReadRib (S: String): TRib;
Var I: word;
begin
    S := Trim (S);
    {Масса}
    I := Pos (' ', S);
    Result[0] := StrToInt (Trim (Copy (S, 1, I)));
    Delete (S, 1, I);
    {Мировая координата Z}
    Result[1] := StrToInt (Trim (S));
end;

Function ReadFace (Source: String): TFaceVertexes;
Var TempInt: Integer;
begin
    {Индекс первой вершины полигона}
    Source := Trim (Source);
    TempInt := Pos (' ', Source);
    Result.Vertexes[0] := StrToInt (Trim (Copy (Source, 1, TempInt)));
    Delete (Source, 1, TempInt);
    {Индекс второй вершины полигона}
    Source := Trim (Source);
    TempInt := Pos (' ', Source);
    Result.Vertexes[1] := StrToInt (Trim (Copy (Source, 1, TempInt)));
    Delete (Source, 1, TempInt);
    {Индекс третьей вершины полигона}
    Source := Trim (Source);
    TempInt := Pos (' ', Source);
    Result.Vertexes[2] := StrToInt (Trim (Copy (Source, 1, TempInt)));
    Delete (Source, 1, TempInt);

    {Текстурная координата U0}
    Source := Trim (Source);
    TempInt := Pos (' ', Source);
    Result.TexCoords[0].x := StrToFloat (Copy (Trim (Source), 1, TempInt));
    Delete (Source, 1, TempInt);
    {Текстурная координата V0}
    Source := Trim (Source);
    TempInt := Pos (' ', Source);
    Result.TexCoords[0].y := StrToFloat (Trim (Copy (Source, 1, TempInt)));
    Delete (Source, 1, TempInt);
    {Текстурная координата U1}
    Source := Trim (Source);
    TempInt := Pos (' ', Source);
    Result.TexCoords[1].x := StrToFloat (Trim (Copy (Source, 1, TempInt)));
    Delete (Source, 1, TempInt);
    {Текстурная координата V1}
    Source := Trim (Source);
    TempInt := Pos (' ', Source);
    Result.TexCoords[1].y := StrToFloat (Trim (Copy (Source, 1, TempInt)));
    Delete (Source, 1, TempInt);
    {Текстурная координата U2}
    Source := Trim (Source);
    TempInt := Pos (' ', Source);
    Result.TexCoords[2].x := StrToFloat (Trim (Copy (Source, 1, TempInt)));
    Delete (Source, 1, TempInt);
    {Текстурная координата V2}
    Source := Trim (Source);
    TempInt := Pos (' ', Source);
    Result.TexCoords[2].y := StrToFloat (Trim (Copy (Source, 1, TempInt)));
    Delete (Source, 1, TempInt);

    {Текстура текущего полигона}
    TempInt := TexNameToTexHandle (Source);
    If TempInt = -1
    then Result.TextureIndex := 0
    else Result.TextureIndex := TextureHandles [TempInt];
end;

Procedure TRigidBody.LoadBodyDataFromFile (const FileName: String);
var
    {Количество треугольников в модели}
    NumTriangles: Integer;
    F: TextFile;
    {Буфера для чтения из файла}
    OneLine, TwoLine: string;
    {Число текстур, используемых в модели}
    TextureCount: Integer;
    {Просто счётчики}
    I, J, K: Integer;
    TempInt: Integer;
    {Индекс найденной текстуры}
    FoundIndex: Integer;
begin
    AssignFile(F, FileName);
    Reset(F);
    Readstr(F, oneline);
    Delete(oneline, 1, Pos ('=', OneLine));
    TextureCount := StrToIntDef (OneLine, 0);
    {Загрузить текстуры}
    If High (TextureHandles) = -1 then
    begin
        SetLength (TexturePaths, 1);
        SetLength (TexturePseudoVars, 1);
        SetLength (TextureHandles, 1);
        ReadStr(F, OneLine);
        TexturePseudoVars[0] := LowerCase (Copy (OneLine, 1, Pos (' ', OneLine) - 1));
        OneLine := Copy (OneLine, Pos(' ', OneLine) + 1, length (OneLine));
        LoadTexture (OneLine, TextureHandles[0], FALSE);
        TexturePaths[0] := OneLine;
        Dec (TextureCount);
    end;

    For I := 0 to (TextureCount - 1) do
    begin
        ReadStr(F, OneLine);
        TwoLine := Copy (OneLine, 1, Pos (' ', OneLine) - 1);
        OneLine := Copy (OneLine, Pos(' ', OneLine) + 1, length (OneLine));
        FoundIndex := -1;
        For J := 0 to High (TexturePaths) do
        begin
            If LowerCase (OneLine) = LowerCase (TexturePaths[J]) then
            begin
                FoundIndex := I;
                Break;
            end;
        end;
        If FoundIndex = -1 then
        begin
            TempInt := Length (TexturePaths) + 1;
            SetLength (TexturePaths, TempInt);
            SetLength (TexturePseudoVars, TempInt);
            SetLength (TextureHandles, TempInt);
            Dec (TempInt);
            TexturePaths [TempInt] := OneLine;
            TexturePseudoVars [TempInt] := TwoLine;
            LoadTexture (OneLine, TextureHandles[TempInt], FALSE);
        end;
    end;

    {Загрузить основные данные тела}
    For I := 0 to 14 do
    begin
        ReadStr (F, OneLine);
        OneLine := LowerCase (Trim (OneLine));
        If Pos ('position', OneLine) > 0 then
        begin
            Delete (OneLine, 1, Pos('.', OneLine));
            Case OneLine[1] of
                'x': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K] <> ' ') do Dec (K);
                    Position.X := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'y': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    Position.Y := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'z': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    Position.Z := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
            end;
        end;

        If Pos ('angularvelocity', OneLine) > 0 then
        begin
            Delete (OneLine, 1, Pos('.', OneLine));
            Case OneLine[1] of
                'x': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K] <> ' ') do Dec (K);
                    AngularVelocity.X := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'y': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    AngularVelocity.Y := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'z': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    AngularVelocity.Z := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
            end;
        end else
        If Pos ('velocity', OneLine) > 0 then
        begin
            Delete (OneLine, 1, Pos('.', OneLine));
            Case OneLine[1] of
                'x': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K] <> ' ') do Dec (K);
                    Velocity.X := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'y': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    Velocity.Y := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'z': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    Velocity.Z := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
            end;
        end;

        If Pos ('angularacceleration', OneLine) > 0 then
        begin
            Delete (OneLine, 1, Pos('.', OneLine));
            Case OneLine[1] of
                'x': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K] <> ' ') do Dec (K);
                    AngularAcceleration.X := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'y': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    AngularAcceleration.Y := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'z': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    AngularAcceleration.Z := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
            end;
        end else
        If Pos ('acceleration', OneLine) > 0 then
        begin
            Delete (OneLine, 1, Pos('.', OneLine));
            Case OneLine[1] of
                'x': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K] <> ' ') do Dec (K);
                    Acceleration.X := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'y': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    Acceleration.Y := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
                'z': begin
                    K := Length (OneLine);
                    J := K;
                    While (K > 0) and (OneLine[K - 1] <> ' ') do Dec (K);
                    Acceleration.Z := StrToFloat (Copy (OneLine, K, J - K + 1));
                end;
            end;
        end;
    end;

    {Загрузить данные вершин}
    Readstr(F, oneline);
    Delete(oneline, 1, Pos ('=', OneLine));
    NumTriangles := StrToIntDef(oneline, 0);
    SetLength (GlobalVertexes, NumTriangles);
    SetLength (OriginalLocalVertexes, NumTriangles);
    For I := 0 to NumTriangles - 1 do
    begin
        ReadStr (F, OneLine);
        OriginalLocalVertexes[I] := ReadVertex (OneLine);
        GlobalVertexes[I].Pos := V3Add (OriginalLocalVertexes[I].Pos, Position);
        GlobalVertexes[I].Mass := OriginalLocalVertexes[I].Mass;
    end;

    {Загрузить данные рёбер}
    Readstr(F, oneline);
    Delete(oneline, 1, Pos ('=', OneLine));
    NumTriangles := StrToIntDef(oneline, 0);
    SetLength (Ribs, NumTriangles);
    For I := 0 to NumTriangles - 1 do
    begin
        ReadStr (F, OneLine);
        Ribs[I] := ReadRib (OneLine);
    end;

    {Загрузить данные треугольников}
    ReadStr (F, OneLine);
    Delete(oneline, 1, Pos ('=', OneLine));
    NumTriangles := StrToIntDef(oneline, 0);
    SetLength (Faces, NumTriangles);
    For I := 0 to NumTriangles - 1 do
    begin
        ReadStr (F, OneLine);
        Faces[I] := ReadFace (OneLine);
    end;
    CloseFile(F);
end;

Constructor TRigidBody.Create (const AOrientation: TQuaternion;
                               const AVelocity, AAcceleration,
                                     AAngularVelocity, AAngularAcceleration: TVector3;
                               const ACanSleep, ADoUpdate: Boolean;
                               const ALinearDamping, ARotationDamping: Float;
                               const ASleepEps: Float;
                               const PathToConfigFile: string);
begin
    inherited Create;
    Orientation := AOrientation;
    Velocity := AVelocity;
    Acceleration := AAcceleration;
    AngularVelocity := AAngularVelocity;
    AngularAcceleration := AAngularAcceleration;
    LinearDamping := ALinearDamping;
    RotationDamping := ARotationDamping;
    SleepEpsilon := ASleepEps;
    LoadBodyDataFromFile (PathToConfigFile);
    CalculateTotalMass;
//    CalculateMassCenter;
    CalculateInertiaTensor;
    CalculateBodyData;
    SetCanBeUpdated (ADoUpdate);
    SetCanSleep (ACanSleep);
    Integrate (0.01);
end;

end.
