unit CameraNew;

interface
Uses dglOpenGL, PhysicsArifm;

Type
TDirectionVariants = (dvForward, dvBackward, dvLeft, dvRight);
TCamera = class
  public
    Position: TVector3;
    LookDirection: TVector3;
    UpDirection: TVector3;
    FieldOfViewAngle: Float;
  protected
    LookDirRotationMatrix: TMatrix4x4;
    
  public
    Constructor Create (const Position_, LookDirection_, UpDirection_: TVector3; const FoVAngle: Float);
    Procedure Move (const Direction: TDirectionVariants; const Speed: Float);
    Procedure Rotate (const DeltaXAngle, DeltaYAngle: Float);
end;

implementation

Constructor TCamera.Create(const Position_, LookDirection_, UpDirection_: TVector3; const FoVAngle: Float);
begin
    inherited Create;
    Position := Position_;
    LookDirection := LookDirection_;
    UpDirection := UpDirection_;
    FieldOfViewAngle := FOVAngle;
end;

Procedure TCamera.Move(const Direction: TDirectionVariants; const Speed: Float);
begin
    Case Direction of
      dvForward: Position := V3AddScaledVector (Position, LookDirection, Speed);
      dvBackward: Position := V3AddScaledVector (Position, LookDirection, -Speed);
      dvLeft:
        Position := V3AddScaledVector (Position, Mat3x3Mul (LEFTY_ROTATION_MAT_3x3, LookDirection), Speed);
      dvRight:
        Position := V3AddScaledVector (Position, Mat3x3Mul (RIGHTY_ROTATION_MAT_3x3, LookDirection), Speed);
    end;
end;

Procedure TCamera.Rotate(const Axis: TVector3; const Angle: Single);
begin

end;

end.
