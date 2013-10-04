unit Cameras;

interface
Uses Math, OpenGL, PhysicsArifm;
Type

TDirectionVariants = (dvForward, dvBackward, dvLeft, dvRight);

TCamera = class
  public
    Position: TVector3;
    Heading,
    Tilt: TQuaternion;
    HeadingAngle,
    TiltAngle: Single;
    LookDirection: TVector3;
    FOVAngle,
    NearClippingDistance,
    FarClippingDistance: Single;

  protected
    Procedure Move (const Direction: TDirectionVariants; const Speed: Float);
  public
    Constructor Create (const X, Y, Z, FOV, NearClipDistance, FarClipDistance: Float);
    Procedure Update (const MovementDirection: TDirectionVariants = dvForward;
        const MovementSpeed: Float = 0);
end;

implementation

Constructor TCamera.Create (const X, Y, Z, FOV, NearClipDistance, FarClipDistance: Float);
begin
    Inherited Create;
    Position.X := X;
    Position.Y := Y;
    Position.Z := Z;
    FOVAngle := FOV;
    NearClippingDistance := NearClipDistance;
    FarClippingDistance := FarClipDistance;
    HeadingAngle := 0;
    TiltAngle := 0;
    Update;
end;

Procedure TCamera.Move(const Direction: TDirectionVariants; const Speed: Float);
Var Movement: TVector3;
begin
    If Speed <> 0 then
    begin
        With LookDirection do
            Movement := V3Normalize (V3 (X, 0, Z));

        Case Direction of
          dvForward: Position := V3AddScaledVector (Position, Movement, Speed);
          dvBackward: Position := V3AddScaledVector (Position, Movement, -Speed);
          dvLeft:
            Position := V3AddScaledVector (Position, Mat3x3Mul (LEFTY_ROTATION_MAT_3x3, Movement), Speed);
          dvRight:
            Position := V3AddScaledVector (Position, Mat3x3Mul (RIGHTY_ROTATION_MAT_3x3, Movement), Speed);
        end;
    end;
end;

Procedure TCamera.Update (const MovementDirection: TDirectionVariants = dvForward;
    const MovementSpeed: Float = 0);
Var TempMat4x4: TMatrix4x4;
begin
    {�������� ������� ���� ������}
    glMatrixMode (GL_MODELVIEW);
    {��������� ����������� ���������� � ������� 4x4 � ������������� OpenGL}
    Heading := AngleToQuaternion (0, 1, 0, HeadingAngle / 2);
    Tilt := AngleToQuaternion (1, 0, 0, TiltAngle / 2);
    {���������� ������� ������}
    TempMat4x4 := OrientAndPosToMatrix4x4 (QuatMul (Tilt, Heading), V3 (0, 0, 0));
    glLoadMatrixf (@TempMat4x4);
    {�������� ����������� ������� ������}
    TempMat4x4 := OrientAndPosToMatrix4x4 (Tilt, V3 (0, 0, 0));
    LookDirection.Y := -TempMat4x4.Data[9];

    TempMat4x4 := OrientAndPosToMatrix4x4 (QuatMul (Heading, Tilt), V3 (0, 0, 0));
    LookDirection.X := -TempMat4x4.Data[8];
    LookDirection.Z := TempMat4x4.Data[10];

    {�������� ������ ����� ���������� �����������}
    Move (MovementDirection, MovementSpeed);
    glTranslateF (-Position.X, -Position.Y, -Position.Z);
end;

end.
