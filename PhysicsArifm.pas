{$B- C+ O- Q+ R+}
unit PhysicsArifm;

interface
Uses dglOpenGL, Math, Windows;

Const PiOver180 = 57.295779513082320876798154814105;
      CMP_EPS = 0.000000001;
      EPS = 0.00000001;

Type
    Float = Single;

    {��������������� ���� ��������}
    {������� �� 4 ��������}
    TGLArray4b = array [0..3] of Shortint;
    TGLArray4bs = array of TGLArray4b;
    TGLArray4bo = array [0..3] of boolean;
    TGLArray4bos = array of TGLArray4bs;
    TGLArray4d = array [0..3] of Double;
    TGLArray4ds = array of TGLArray4d;
    TGLArray4F = array [0..3] of Single;
    TGLArray4fs = array of TGLArray4f;
    TGLArray4ub = array [0..3] of Byte;
    TGLArray4ubs = array of TGLArray4ub;

    {������� �� 3 ��������}
    TGLArray3b = array [0..2] of Shortint;
    TGLArray3bo = array [0..2] of boolean;
    TGLArray3d = array [0..2] of Double;
    TGLArray3f = array [0..2] of Single;
    TGLArray3ub = array [0..2] of Byte;

    {������� �� 2 ��������}
    TGLArray2b = array [0..1] of Shortint;
    TGLArray2bo = array [0..1] of boolean;
    TGLArray2d = array [0..1] of Double;
    TGLArray2f = array [0..1] of Single;
    TGLArray2ub = array [0..1] of Byte;

{################################################################################
                        �Ш������� ������ � �������� ��� ���
################################################################################}

    TVector3 = {packed }record
          X, Y, Z: Float;
    end;
    TVectors3 = array of TVector3;
    T2Vectors3D = array [0..1] of TVector3;
    TGlArray16f = array [0..15] of glFloat;

{�������� ����� � ��������� �����}
Function V3 (const XCoord, YCoord, ZCoord: Float): TVector3; overload;
Function V3 (const Value: Float): TVector3; overload;
{���������}
Function V3Equal (const A, B: TVector3): boolean;
{��������}
Function V3Add (const A, B: TVector3): TVector3;
{��������}
Function V3Invert (const A: TVector3): TVector3;
{���������}
Function V3Sub (const A, B: TVector3): TVector3;
{����� �������}
Function V3Length (const A: TVector3): Extended;
{����� ������� � ��������}
Function V3SquareLength (const A: TVector3): Extended;
{�������� ���������������� ��������}
Function V3CheckSonapr (const A,B : TVector3): boolean;
{��������� ������� �� ������}
Function V3Mul (const A, B: TVector3): TVector3; overload;
{��������� ������� �� �����}
Function V3Mul (const A: TVector3; const B: Float): TVector3; overload;
{������� ��������� ������������}
Function V3TripleProduct (const A, B, C: TVector3): TVector3;
{������� ������� �� �����}
Function V3Div (const A: TVector3; const B: Float): TVector3; overload;
Function V3Div (const A, B: TVector3): TVector3; overload;
{�������������� ���������� ������� � �������}
Function V3ComponentWiseSquare (const A: TVector3): TVector3;
{������, ���������������� �������}
Function V3Perpendicular (const A: TVector3): TVector3;
{������������ �������}
Function V3Normalize (const A: TVector3): TVector3;
{��������� ������������ ��������}
Function V3ScalarProduct (const A, B: TVector3): Float;
Function V3ScalarPerpendicularProduct (const A, B: TVector3): TVector3;
{�������������� ������������ ��������}
Function V3ComponentProduct (const A, B: TVector3): TVector3;
{��������� � ������� ������� ������, ���������� �� B_SCALE}
Function V3AddScaledVector (const A, B: TVector3; const B_Scale: Float): TVector3;
{����� ������ �� ��������� �����}
Function V3TrimVector (const A: TVector3; const Limit: Float): TVector3;
{���������� ����� �������}
Procedure V3SetLength (var Vector: TVector3; const Len: Float);
{�������� ����� �������� ������� �� �������� ��� � ���� �������� ���� ����� ����}
Function V3Project (const Vector, Axis: TVector3): Float;
{��������� ��� ������� �������� � ����}
Procedure Vectors3ConcatReplace (var A: TVectors3; const B: TVectors3);
Function Vectors3Concat (const A, B: TVectors3): TVectors3;
{��������� ��������� ����� �� ���������}
Function GenerateRandomNumber (const Min, Max: Float): Float;
{�������� ������� � ��������� (V0, V1, V2 - �����, �������� ���������)}
Function GetNormalToPlane (const V0, V1, V2: TVector3): TVector3;
{�������� ���������� �� ����� �� ���������}
Function GetDistanceToPlane (const ANormal, APoint: TVector3): Float;
{�������� ����� �� �������, ��������� � ������}
Function GetClosestPointOnLineSegment (const LineStart, LineEnd, Point: TVector3): TVector3;
{�������� ����� �� ������, �������� ����� �������, ��������� � ������}
Function GetClosestPointOnLine (const LineStart, LineEnd, Point: TVector3): TVector3;
{���������� ���������� ����� 2 ��������� ��� �� �������������}
Function GetDistanceBetweenLineSegments (const A1, B1, A2, B2: TVector3): Float;
{�������� ���� ����� ���������}
Function GetAngleBetweenVectors (const A, B: TVector3): Float;
{�������� ����� ���� ����� ���������}
Function GetSineOfAngleBetweenV3 (const A, B: TVector3): Float;
{���������, ������������ �� ������, �������� ��������� �� �����������.
 ���������� true, ���� ����������� ����, � ���������� ����� ����������� InterSectionPoint.
 ���� ������� ������� false, �� �������� InterSectionPoint �� ������������}
Function LineIntersectsLine (const DirA, DirB: TVector3; var InterSectionPoint: TVector3): boolean;
{��������, ����� �� ����� ��, ����� ���������� ��� ���������� �.
����� ������� ���������� ���������� �� ������ ����� �� ���������}
Function GetDistanceFromSphereCenterToPlane (const CCenter: TVector3;           //����� �����
                                                    const CRadius: Float;             //������ �����
                                                    const PStartPoint: TVector3;       //�������� ����� ���������
                                                    const PNormal: TVector3;           //������� � ���������
                                                    Var CenterToPlaneDistance: Float  //���������� �� ������ ����� �� ���������
                                                    ): byte;     //��, ����� ��� ����������

{�������� ����������, �� ������� ���� ���������� ����� �� ��������� ��� ��������}
Function GetCollisionOffset (const Normal: TVector3;              //������� � ���������
                             const SphereRadius,                  //������ �����
                             SphereCenterToPlaneDistance: Float  //���������� �� ������ ����� �� ���������
                             ): TVector3;    //���������� ���������, �� ������� ���� ���������� ����� �� ���������

{��������� ����������� ���� � ���������, �������� ����� �������}
Function RayInterSectsPlane (const RayStart, RayDir, V0, V1, V2: TVector3; var InterSectionPoint: TVector3): boolean;

{�������� ���������� ���������� ����� ����� ���������
 A1, B1 - ����� ������� �������,
 A2, B2 - ����� ������� �������.
 http://geomalgorithms.com/a07-_distance.html#dist3D_Segment_to_Segment(}
Function GetDistanceBetween2LineSegments (const A1, B1, A2, B2: TVector3): Float;

{################################################################################
                           ���������� � �������� ��� ���
################################################################################}

Type TQuaternion = packed record
         R,            //�������������� ����������
         I,            //������ ����������� ����������
         J,            //������ ����������� ����������
         K: Float;    //������ ����������� ����������
     end;

{���������� ���������� � ��������� ������������}
Function Quaternion (const RealCmp, FCmp, SCmp, TCmp: Float): TQuaternion;
{����� �����������}
Function QuatLength (const A: TQuaternion): Float;
{������������ �����������}
Function QuatNormalize (const A: TQuaternion): TQuaternion;
{�������������� �������� ������������}
Function QuatAdd (const A, B: TQuaternion): TQuaternion;
{�������������� ��������� �������������}
Function QuatSub (const Minuend, Subtrahend: TQuaternion): TQuaternion;
{��������� ����������� �� ����������}
Function QuatMul (const A, B: TQuaternion): TQuaternion; overload;
{��������� ����������� �� �����}
Function QuatMul (const Quat: TQuaternion; Multiplier: Float): TQuaternion; overload;
{���������� ����������, �������� ��������, �������� �������}
Function QuatConjugate (const A: TQuaternion): TQuaternion;
{������� ����� �����������}
Function QuatNorma (const A: TQuaternion): Float;
{������������� ����������}
Function QuatInvert (const A: TQuaternion): TQuaternion;
{��������� ������������ ������������}
Function QuatScalarProduct (const A, B: TQuaternion): Float;
{��������� � ������� ����������� ������, ���������� �� VectorScale}
Function QuatAddScaledVector (const AQuaternion: TQuaternion;
                              const Vector: TVector3;
                              const VectorScale: Float
                              ): TQuaternion;
{��������� ���������� �� ������}
Procedure QuatRotateByVector (Var AQuaternion: TQuaternion; const Vector: TVector3);
{�������� ���������� �� ���� (� ��������)}
Function AngleToQuaternion (const AxisX, AxisY, AxisZ, Angle: Single): TQuaternion;

{################################################################################
                        ������� 3*3 � �������� ��� ���
################################################################################}
Type TMatrix3x3 = packed record
         Data: array [0..8] of Float;
     end;
{�������� ����� � ��������� �������������}
Function Mat3x3 (const c0, c1, c2, c3, c4, c5, c6, c7, c8: Float): TMatrix3x3;
{�������������� �������� ������}
Function Mat3x3ComponentWiseAddition (const A, B: TMatrix3x3): TMatrix3x3;
{���������� ��������� ������� 3x3}
Function Mat3x3GetIdentityMatrix: TMatrix3x3;
{������ ������� �� ���������� ������� �������}
Procedure Mat3x3SetInertiaTensorParams (Var AMatrix: TMatrix3x3; const IX, IY, IZ: Float; const IXY: Float = 0; const IXZ: Float = 0; const IYZ: Float = 0);
{������ ��������� �������}
Procedure Mat3x3SetDiagonal (Var AMatrix: TMatrix3x3; const A, B, C: Float);
{������ ������ ������� ��� ��������������, ����������� � ������� ��������� ����, ����� ������ �������� ������������ �� ��� � �����}
Procedure Mat3x3SetBodyInertiaTensor (Var AMatrix: TMatrix3x3; const HalfDimensions: TVector3; Mass: Float);
{��������� ������������ �������}
Procedure Mat3x3SetDiagonalSymmetric (Var Matrix: TMatrix3x3; const Vector: TVector3);
{������ ������� ����� � ����������}
Procedure Mat3x3SetComponents (Var AMatrix: TMatrix3x3; const First, Second, Third: TVector3);
{�������� ������� �� ������}
Function Mat3x3Mul (const AMatrix: TMatrix3x3; const AVector: TVector3): TVector3; overload;
{�������� ������� �� �������}
Function Mat3x3Mul (const A, B: TMatrix3x3): TMatrix3x3; overload;
{�������� ������ ������ ������� �� �����}
Function Mat3x3Mul (const AMatrix: TMatrix3x3; const Multiplier: Float): TMatrix3x3; overload;
{�������������������� �������: ������� ���������� ��������, � ��������}
Function Mat3x3Transpose (const AMatrix: TMatrix3x3): TMatrix3x3;
{�������� ������ �� ���������������������� ������ ������ �������}
Function Mat3x3TransposeTransformV3ByMatrix3x3 (const AMatrix: TMatrix3x3; const AVector: TVector3): TVector3;
{������������� �������: ������� := 1 / �������}
Function Mat3x3Invert (const Matrix: TMatrix3x3): TMatrix3x3;
{�������� �������� ������ �������}
Function Mat3x3GetRowByIndex (const AMatrix: TMatrix3x3; Index: byte): TVector3;
{�������� �������� ������� �������}
Function Mat3x3GetColumnByIndex (const AMatrix: TMatrix3x3; const Index: byte): TVector3;
{�������������� ���������� � �������}
Function QuatToMat3x3 (const Quat: TQuaternion): TMatrix3x3;
{�������� ������������ ���� ������}
Function Mat3x3LinearInterpolation (const A, B: TMatrix3x3; const Proportion: Float): TMatrix3x3;

{################################################################################
                        ������� 3*4 � �������� ��� ���
################################################################################}
Type TMatrix3x4 = packed record
         Data: array [0..11] of Float;
     end;
{�������� ����� � ��������� �������������}
Function Mat3x4 (const D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11: Float): TMatrix3x4;
{���������� ��������� ������� 4x4}
Function Mat3x4GetIdentityMatrix: TMatrix3x4;
{������ ��������� �������}
Procedure Mat3x4SetDiagonal (Var AMatrix: TMatrix3x4; const D0, D1, D2: Float);
{��������� ������� �� �������}
Function Mat3x4Mul (const A, B: TMatrix3x4): TMatrix3x4; overload;
{��������� ������� �� �����}
Function Mat3x4Mul (const Matrix: TMatrix3x4; const Multiplier: Float): TMatrix3x4; overload;
{��������� ������� �� ������}
Function Mat3x4Mul (const AMatrix: TMatrix3x4; const AVector: TVector3): TVector3; overload;
(*{��������� ������� �� �������}
Function Mat3x4Mul (const A, B: TMatrix3x4): TMatrix3x4; overload;
{��������� ������� �� �����}
Function Mat3x4Mul (const Matrix: TMatrix3x4; const Multiplier: Float): TMatrix3x4; overload;*)
{�������������� �������}
Function Mat3x4Invert (const AMatrix: TMatrix3x4): TMatrix3x4;
{��������� ������� ����������� �� �������}
Function Mat3x4MulDirV3 (const AMatrix: TMatrix3x4; const DirectionVector: TVector3): TVector3;
{��������� ������� ����������� �� ���������������������� ������ �������}
Function Mat3x4MulInvDirV3 (const AMatrix: TMatrix3x4; const DirectionVector: TVector3): TVector3;
{��������� ������� �� ���������������������� ������ �������}
Function Mat3x4MulInvV3 (const AMatrix: TMatrix3x4; const Vector: TVector3): TVector3;
{�������� ������� ������� �� ��� �������}
Function Mat3x4GetColumnByIndex (const AMatrix: TMatrix3x4; const Index: byte): TVector3;
{�������� ������ ������� �� � �������}
Function Mat3x4GetRowByIndex (const AMatrix: TMatrix3x4; Index: byte): TVector3;
{�������� ������� 3x4 �� ����������� � �������}
Function OrientAndPosToMatrix3x4 (const Orientation: TQuaternion; const Position: TVector3): TMatrix3x4;
{�������������������� �������}
Function Mat3x4Transpose (const AMatrix: TMatrix3x4): TMatrix3x4;
{��������� ������� 3x4 � �������������, ������� ��� ������ ����� ��� OpenGL}
Procedure Mat3x4ToGLArray (const AMatrix: TMatrix3x4; Var AArray: TGlArray16F);
{��������� ������� OpenGL � ������� ���� 3x4}
Procedure GLArrayToMat3x4 (const AArray: TGlArray16F; Var AMatrix: TMatrix3x4);
{��������� ������� �� ���� 3x3 � ��� 3x4}
Function Mat3x3ToMat3x4 (const Matrix3x3: TMatrix3x3): TMatrix3x4;
{���������������� ������ ������� ���� �� ������� �����������}
Function Mat3x3TransformByQuaternion (const Quat: TQuaternion; const BodyIT: TMatrix3x3; const RotMat: TMatrix3x4): TMatrix3x3;

{################################################################################
                        ������� 4*4 � �������� ��� ���
################################################################################}
Type TMatrix4x4 = record
    Data: array [0..15] of glFloat;
end;

Function Mat4x4 (const D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15: glFloat): TMatrix4x4;
Function OrientAndPosToMatrix4x4 (const Quat: TQuaternion; const Position: TVector3): TMatrix4x4;

{################################################################################
                                  ���������
################################################################################}
Type TPlane = record
    {�������}
    Normal: TVector3;
    {���������� �� ������ ���������}
    Offset: Float;
end;

{################################################################################
                 ����������˨���� ���������
################################################################################}
Const Gravity: TVector3 = (x:0; y:-9.81; z:0);
    {������� �������� ������ ��� X �� 90 �������� ����� � ������}
      LEFTX_ROTATION_MAT_3x3: TMatrix3x3 = (
         Data:(1, 0, 0,
               0, 0, -1,
               0, 1, 0));
      RIGHTX_ROTATION_MAT_3x3: TMatrix3x3 = (
         Data:(1, 0, 0,
               0, 0, 1,
               0, -1, 0));
    {������� �������� ������ ��� Y �� 90 �������� ����� � ������}
      LEFTY_ROTATION_MAT_3x3: TMatrix3x3 = (
         Data:(0, 0, 1,
               0, 1, 0,
               -1, 0, 0));
      RIGHTY_ROTATION_MAT_3x3: TMatrix3x3 = (
         Data:(0, 0, -1,
               0, 1, 0,
               1, 0, 0));
    {������� �������� ������ ��� Z �� 90 �������� ����� � ������}
      LEFTZ_ROTATION_MAT_3x3: TMatrix3x3 = (
         Data:(0, -1, 0,
               1, 0, 0,
               0, 0, 1));
      RIGHTZ_ROTATION_MAT_3x3: TMatrix3x3 = (
         Data:(0, 1, 0,
               -1, 0, 0,
               0, 0, 1));
{################################################################################}
                                 IMPLEMENTATION
{################################################################################}

Function V3 (const XCoord, YCoord, ZCoord: Float): TVector3;
begin
    With Result do
    begin
        X := XCoord;
        Y := YCoord;
        Z := ZCoord;
    end;
end;

Function V3 (const Value: Float): TVector3; overload;
begin
    With Result do
    begin
        X := Value;
        Y := Value;
        Z := Value;
    end;
end;

Function V3Equal (const A, B: TVector3): boolean;
begin
    Result := (Abs (A.X - B.X) < CMP_EPS)
              and (Abs (A.Y - B.Y) < CMP_EPS)
              and (Abs (A.Z - B.Z) < CMP_EPS);
end;

Function V3Add (const A, B: TVector3): TVector3;
begin
    With Result do
    begin
        X := A.X + B.X;
        Y := A.Y + B.Y;
        Z := A.Z + B.Z;
    end;
end;

Function V3Invert (const A: TVector3): TVector3;
begin
    With Result do
    begin
        X := - A.X;
        Y := - A.Y;
        Z := - A.Z;
    end;
end;

Function V3Sub (const A, B: TVector3): TVector3;
begin
    Result := V3Add (A, V3Invert (B));
end;

Function V3Length (const A: TVector3): Extended;
begin
    Result := Sqrt (Sqr (A.X) + Sqr (A.Y) + Sqr (A.Z));
end;

Function V3SquareLength (const A: TVector3): Extended;
begin
    Result := Sqr (A.X) + Sqr (A.Y) + Sqr (A.Z);
end;

Function V3CheckSonapr (const A, B : TVector3): boolean;
begin
    Result := (A.X * B.X >= 0) and (A.Y * B.Y >= 0) and (A.Z * B.Z >= 0);
end;

Function V3Mul (const A, B: TVector3): TVector3; overload;
begin
    With Result do
    begin
        X := (A.Y * B.Z) - (A.Z * B.Y);
        Y := (A.Z * B.X) - (A.X * B.Z);
        Z := (A.X * B.Y) - (A.Y * B.X);
    end;
end;

Function V3Mul (const A: TVector3; const B: Float): TVector3; overload;
begin
    With Result do
    begin
        X := A.X * B;
        Y := A.Y * B;
        Z := A.Z * B;
    end;
end;

{������� ��������� ������������}
Function V3TripleProduct (const A, B, C: TVector3): TVector3;
begin
    Result := V3Sub (V3Mul (B, V3ScalarProduct (A, C)), V3Mul (A, V3ScalarProduct (B, C)));
end;

Function V3Div (const A: TVector3; const B: Float): TVector3;
begin
    With Result do
    begin
        X := A.X / B;
        Y := A.Y / B;
        Z := A.Z / B;
    end;
end;

Function V3Div (const A, B: TVector3): TVector3;
begin
    With Result do
    begin
        X := A.X / B.X;
        Y := A.Y / B.Y;
        Z := A.Z / B.Z;
    end;
end;

Function V3ComponentWiseSquare (const A: TVector3): TVector3;
begin
    With A do
    begin
        Result.X := Sqr (X);
        Result.Y := Sqr (Y);
        Result.Z := Sqr (Z);
    end;
end;

Function V3Normalize (const A: TVector3): TVector3;
begin
    If (Abs (A.X) < 0.00001) and (Abs (A.Y) < 0.00001) and (Abs (A.Z) < 0.00001)
    then ZeroMemory (@Result, SizeOf (Result))
    else Result := V3Div (A, V3Length (A));
end;

Function V3ScalarProduct (const A, B: TVector3): Float;            //��������� ������������ ��������
begin
    Result := A.X*B.X + A.Y*B.Y + A.Z*B.Z; 
end;

Function V3ScalarPerpendicularProduct (const A, B: TVector3): TVector3;
begin

end;

Function V3ComponentProduct (const A, B: TVector3): TVector3;
begin
    Result.X := A.X * B.X;
    Result.Y := A.Y * B.Y;
    Result.Z := A.Z * B.Z;
end;

Function V3AddScaledVector (const A, B: TVector3; const B_Scale: Float): TVector3;
begin
    Result.X := A.X + B.X * B_Scale;
    Result.Y := A.Y + B.Y * B_Scale;
    Result.Z := A.Z + B.Z * B_Scale;
end;

{���������� ����� �������}
Procedure V3SetLength (var Vector: TVector3; const Len: Float);
Var OldLen: Float;
begin
    With Vector do
    begin
        OldLen := Sqrt (Sqr (X) + Sqr (Y) + Sqr (Z));
        X := X / OldLen * Len;
        Y := Y / OldLen * Len;
        Z := Z / OldLen * Len;
    end;
end;

Function V3Project (const Vector, Axis: TVector3): Float;
Var Len, SP: Float;
begin
    Len := V3Length (Vector);
    SP := V3ScalarProduct (Vector, Axis);
    Result := SP / (Len * V3Length (Axis));
end;

{��������� ��� ������� �������� � ����}
Procedure Vectors3ConcatReplace (var A: TVectors3; const B: TVectors3);
Var I, Len: Integer;
begin
    Len := Length (B);
    SetLength (A, Length (A) + Len);
    For I := Len to High (A) do
        A[I] := B[I - Len];
end;

Function Vectors3Concat (const A, B: TVectors3): TVectors3; overload;
Var I, Len, LenA: Integer;
begin
    LenA := Length (A);
    Len := LenA + High (B);
    SetLength (Result, Len + 1);
    For I := 0 to LenA do
        Result[I] := A[I];
    For I := LenA to Len do
        Result[I] := B[I - LenA];
end;

Function V3TrimVector (const A: TVector3; const Limit: Float): TVector3;
begin
    If (V3SquareLength (A) > Sqr (Limit)) then
        Result := V3Mul (V3Normalize (A), Limit);
end;

Function GenerateRandomNumber (const Min, Max: Float): Float;
begin
    If Min > Max then
    Result := Random * (Min - Max) + Max
    else Result := Random * (Max - Min) + Min;
end;

Function GetNormalToPlane (const V0, V1, V2: TVector3): TVector3;
begin
    Result := V3Normalize (V3Mul (V3Sub (V1, V0), V3Sub (V2, V0)));
end;

Function GetDistanceToPlane (const ANormal, APoint: TVector3): Float;     //���������� ���������� �� ����� �� ���������
begin
    Result := - V3ScalarProduct (ANormal, APoint);
end;

Function GetClosestPointOnLineSegment (const LineStart, LineEnd, Point: TVector3): TVector3;    //���������� ����� ����� ����� LineStart � LineEnd, ��������� � ����� Point
Var V1, V2: TVector3;    //�� ���� �������� ������� �������
    Temp: Float;    //����� ����� �� LineStart �� LineEnd;
begin
    {������ �� ������ ����� �� ����� Point}
    V1 := V3Sub (Point, LineStart);
    {��������������� ������ ����������� �����}
    V2 := V3Normalize (V3Sub (LineEnd, LineStart));
    Temp := V3ScalarProduct (V2, V1);
    If (Temp <= 0) then
        Result := LineStart
    else If (Temp >= 1) then
        Result := LineEnd
    else
        Result := V3AddScaledVector (LineStart, V2, Temp);
end;

{���������� ���������� ����� 2 ��������� ��� �� �������������}
Function GetDistanceBetweenLineSegments (const A1, B1, A2, B2: TVector3): Float;
Var V1, V2: TVector3;
    Temp: Float;
    ClosestPoint1, ClosestPoint2: TVector3;
begin
    {������ �� ������ ����� �� ����� �� 2 �������}
    V1 := V3Sub (A2, A1);
    {��������������� ������ ����������� �����}
    V2 := V3Normalize (V3Sub (B1, A1));
    Temp := V3ScalarProduct (V2, V1);
    {��������� ����� �� 1 �������}
    ClosestPoint1 := V3Mul (V2, Temp);

    {������ �� ������ ����� �� ����� �� 1 �������}
    V1 := V3Sub (A1, A2);
    {��������������� ������ ����������� �����}
    V2 := V3Normalize (V3Sub (B2, A2));
    Temp := V3ScalarProduct (V1, V2);
    {��������� ����� �� 1 �������}
    ClosestPoint2 := V3Mul (V1, Temp);

    Result := V3Length (V3Sub (ClosestPoint1, ClosestPoint2));
end;

{�������� ����� �� ������, �������� ����� �������, ��������� � ������}
Function GetClosestPointOnLine (const LineStart, LineEnd, Point: TVector3): TVector3;
Var V1, V2: TVector3;    //�� ���� �������� ������� �������
    Temp: Float;    //����� ����� �� LineStart �� LineEnd;
begin
    {������ �� ������ ����� �� ����� Point}
    V1 := V3Sub (Point, LineStart);
    {��������������� ������ ����������� �����}
    V2 := V3Normalize (V3Sub (LineEnd, LineStart));
    Temp := V3ScalarProduct (V2, V1);
    Result := V3AddScaledVector (LineStart, V2, Temp);
end;

Function LineIntersectsLine (const DirA, DirB: TVector3; var InterSectionPoint: TVector3): boolean;
Var A11, A12, A21, A22, B1, B2, D1, D2, T1, T2, Temp1, Temp2, Det: Float;
begin
    Result := false;
    A11 := DirA.X;
    A12 := -DirB.X;
    A21 := DirA.Y;
    A22 := -DirA.Y;
    B1 := DirB.X - DirA.X;
    B2 := DirB.Y - DirA.Y;

    Det := A11 * A22 - A12 * A21;
    If Abs (Det) > EPS then
    begin
        D1 := B1*A22 - A12*B2;
        D2 := A11*B2 - A21*B1;
        T1 := D1 / Det;
        T2 := D2 / Det;

        Temp1 := DirA.Z * (T1 + 1);
        Temp2 := DirB.Z * (T2 + 1);
        If Abs (Temp1 - Temp2) < EPS then
        With InterSectionPoint do
        begin
            X := DirA.X * (T1 + 1);
            Y := DirA.Y * (T1 + 1);
            Z := Temp1;
            Result := true;
            Exit;
        end else
        begin
            Result := false;
            Exit;
        end;
    end;

    A21 := DirA.Z;
    A22 := -DirB.Z;
    B2 := DirB.Z - DirA.Z;

    Det := A11 * A22 - A12 * A21;
    If Abs (Det) > EPS then
    begin
        D1 := B1*A22 - A12*B2;
        D2 := A11*B2 - A21*B1;
        T1 := D1 / Det;
        T2 := D2 / Det;

        Temp1 := DirA.Z * (T1 + 1);
        Temp2 := DirB.Z * (T2 + 1);
        If Abs (Temp1 - Temp2) < EPS then
        With InterSectionPoint do
        begin
            X := DirA.X * (T1 + 1);
            Y := DirA.Y * (T1 + 1);
            Z := Temp1;
            Result := true;
            Exit;
        end else
        begin
            Result := false;
            Exit;
        end;
    end;

    A11 := DirA.Y;
    A12 := -DirB.Y;
    B1 := DirB.Y - DirA.Y;

    Det := A11 * A22 - A12 * A21;
    If Abs (Det) > EPS then
    begin
        D1 := B1*A22 - A12*B2;
        D2 := A11*B2 - A21*B1;
        T1 := D1 / Det;
        T2 := D2 / Det;

        Temp1 := DirA.Z * (T1 + 1);
        Temp2 := DirB.Z * (T2 + 1);
        If Abs (Temp1 - Temp2) < EPS then
        With InterSectionPoint do
        begin
            X := DirA.X * (T1 + 1);
            Y := DirA.Y * (T1 + 1);
            Z := Temp1;
            Result := true;
            Exit;
        end else
        begin
            Result := false;
            Exit;
        end;
    end;
end;

Function GetAngleBetweenVectors (const A, B: TVector3): Float;    //���� ����� 2 ���������
begin
    Result := ArcCos (V3ScalarProduct (A, B) / (V3Length (A) * V3Length (B)));
end;

{�������� ����� ���� ����� ���������}
Function GetSineOfAngleBetweenV3 (const A, B: TVector3): Float;
begin
    Result := Sqrt (1 - Sqr (V3ScalarProduct (A, B) / (V3Length (A) * V3Length (B))));
end;

//������, ����� �� ����� ��, ����� ���������� ��� �� ���������� �. ����� ���������� ���������� �� ������ ����� �� ���������.
//0 = ����� ����� ����������; 1 = ����� ���������� ���������; 2: ����� ����� ���������
Function GetDistanceFromSphereCenterToPlane (const CCenter: TVector3;      //����� �����
                                             const CRadius: Float;        //������ �����
                                             const PStartPoint: TVector3;  //�������� ����� ���������
                                             const PNormal: TVector3;      //������� � ���������
                                             Var CenterToPlaneDistance: Float    //���������� �� ������ ����� �� ���������
                                             ): byte;                      //��� �����
Var DistanceToZeroCoords: Float;    //���������� ��������� �� ������ ���������
begin
    {����� ���������� ��������� �� ������ ���������}
    DistanceToZeroCoords := GetDistanceToPlane (PNormal, PStartPoint);
    {����� ���������� �� ������ ����� �� ���������}
    CenterToPlaneDistance := V3ScalarProduct (PNormal, CCenter) + DistanceToZeroCoords;
    {������ ����� ������ � ���, ���������� �� ����� ���������:
    ������1. ������ ���������� ������ ����� �� ��������� ������ � �������: �����������.}
    If (Abs (CenterToPlaneDistance) <= CRadius) then
        Result := 1
    else
        If (CenterToPlaneDistance > CRadius) then
            {������2. ���������� �� ������ ����� �� ��������� ������ ���� ����� � �������: ����� ����������}
            Result := 0
            {������3. ����� ���������.}
        else Result := 2;
end;

{�������� ����������, �� ������� ���� ���������� ����� �� ��������� ��� ��������}
Function GetCollisionOffset (const Normal: TVector3;              //������� � ���������
                             const SphereRadius,                  //������ �����
                             SphereCenterToPlaneDistance: Float  //���������� �� ������ ����� �� ���������
                             ): TVector3;    //���������� ���������, �� ������� ���� ���������� ����� �� ���������
begin
    If (SphereCenterToPlaneDistance > 0) then
        {� ���� ������ ����� ����� ����������, �. �. ���������� �� �� �� ����� ������������}
        Result := V3Mul (Normal, SphereRadius - SphereCenterToPlaneDistance)
    else
        {� � ���� - ������ ���������.}
        Result := V3Mul (Normal, - SphereRadius - SphereCenterToPlaneDistance);
end;

(*
��� �������� �������� ����������� ���� ( ������� ) � �������� ( ��� �������� ������������ )
Vx, Vy, Vz - ��� ������  ����������� ����
Xa Ya Za - ����� ����������� ������� ( �� ��� ������� ������ )
X1 Y1 Z1
X2 Y2 Z2 ���������� ������ ������������
X3 Y3 Z3
�������� ������� � ���������
(A,B,C)=[L1xL2]
����� ������� ����������� D �� ����� �� ��������� D:=-A*X1-B*Y1-C*Z1;
����� ������� ����� ����������� ���� � ���������� X0 Y0 Z0
����� X0=k*Vx+Xa;
      Y0=k*Vy+Ya;
      Z0=k*Vz+Za;
��� k-����� ����������
� ������ ������� k :
����������� ��������� � ��������� ��������� ������������ :
A*X0+B*Y0+C*Z0+D=0;
A*(k*Vx+Xa)+B*(k*Vy+Ya)+C*(k*Vz+Za)+D=0;
k*(A*Vx+B*Vy+C*Vz)+A*Xa+B*Ya+C*Za+D=0;
from there k=-(A*Xa+B*Ya+C*Za+D)/(A*Vx+B*Vy+C*Vz);
*)

Function RayInterSectsPlane (const RayStart, RayDir, V0, V1, V2: TVector3; var InterSectionPoint: TVector3): boolean;
Var Normal: TVector3;
    Distance: Float;
    K: Float;
begin
    Result := false;
    {���������� ��������� � ��������� ��������� - ������� � ���������� �� ������ ���������}
    Normal := GetNormalToPlane (V0, V1, V2);
    Distance := -V3ScalarProduct (Normal, V0);
    {�������� ���������� �� ����� ����������� ���� � ���������� �� ����� ������ ����}
    K := -(V3ScalarProduct (Normal, RayStart) + Distance) / V3ScalarProduct (Normal, RayDir);
    {���� Normal dot RayDir ����� 0, �� ��� ������, ��� ������ ����������� ���������
     � ������� �� �� ��������� (������ 1).
     ���� t < 0 (������ 2) ��� t > 1 (������ 3), �� ��� ������, ��� ����� ����������� ����� �� StartPoint
     ��� �� EndPoint ��������������.
     ��� ����, ����� ���������� ������ (1) � (2) - ����� ������ �����, ������������� ����}
    If K <= EPS then
    begin
        {��� ������, ���������� ��� ��������� - ����� �� ����� �� ����}
        InterSectionPoint := V3 (0);
        Exit;
    end;
    Result := true;
    {���������� ���������� ����� �����������}
    InterSectionPoint := V3AddScaledVector (RayStart, RayDir, K);
end;

{http://geomalgorithms.com/a07-_distance.html#dist3D_Segment_to_Segment(}
Function GetDistanceBetween2LineSegments (const A1, B1, A2, B2: TVector3): Float;
Var U, V, W: TVector3;
    A, B, C, D, E, F, sC, sN, sD, tC, tN, tD: Float;
begin
    U := V3Sub (B1, A1);
    V := V3Sub (B2, A2);
    W := V3Sub (A1, A2);

    A := V3ScalarProduct (U, U);
    B := V3ScalarProduct (U, V);
    C := V3ScalarProduct (V, V);

    D := V3ScalarProduct (U, W);
    E := V3ScalarProduct (V, W);
    F := A*C - B*B;

    {compute the line parameters of the two closest points}
    If F < EPS then
    begin
        SN := 0;
        SD := 1;
        TN := E;
        TD := C;
    end else
    {get the closest points on infinite lines}
    begin
        sN := (b*e - c*d);
        tN := (a*e - b*d);
        if (sN < 0) then
        begin        // sc < 0 => the s=0 edge is visible
            sN := 0;
            tN := e;
            tD := c;
        end
        else if (sN > sD) then
        begin        // sc > 1  => the s=1 edge is visible
            sN := sD;
            tN := e + b;
            tD := c;
        end;
    end;

    If (tN < 0) then            // tc < 0 => the t=0 edge is visible
    begin
        tN := 0;
        // recompute sc for this edge
        if (d > 0) then
            sN := 0
        else If (d < a)
        then sN := sD
        else
        begin
            sN := -d;
            sD := a;
        end;
    end
    else if (tN > tD) then      // tc > 1  => the t=1 edge is visible
    begin
        tN := tD;
        // recompute sc for this edge
        if ((-d + b) < 0) then
            sN := 0
        else if ((-d + b) > a)
        then sN := sD
        else begin
            sN := (-d +  b);
            sD := a;
        end;
    end;

    // finally do the division to get sc and tc
    If Abs (SN) < EPS
    then SC := 0
    else SC := SN / SD;

    If Abs (SN) < EPS
    then TC := 0
    else TC := TN / TD;

    // get the difference of the two closest points
    Result := V3SquareLength (V3Sub (V3Add (W, V3Mul(U, SC)), V3Mul(V, TC)));  // =  S1(sc) - S2(tc)
end;

Function IsBetweenFloat_Float (const Left, Right, TestNumber: Float): boolean;
begin
    Result := (TestNumber >= Left) and (TestNumber <= Right);
end;

{################################################################################
                        ���������� � �������� ��� ���
################################################################################}

Function Quaternion (const RealCmp, FCmp, SCmp, TCmp: Float): TQuaternion;
begin
    With Result do
    begin
        R := RealCmp;
        I := FCmp;
        J := SCmp;
        K := TCmp;
    end;
end;

Function QuatLength (const A: TQuaternion): Float;
begin
    With A do
        Result := Sqrt (R*R + I*I + J*J + K*K);
end;

Function QuatNormalize (const A: TQuaternion): TQuaternion;
Var Len: Float;
begin
    With Result do
    begin
        Len := QuatLength (A);
        {� ������, ����� ����� ����������� �������, ����� ������������
        ������� ����������, �. �. �� �������� �������. ��� ����� ����������
        ���������� ��� �������������� ���������� � 1}
        If (Len = 0) then
        begin
            R := 1;
            I := 0;
            J := 0;
            K := 0;
        end
        else
        begin
        {����� �� ���������. �������� ���������� � ��������� �����}
            Len := 1 / Len;
            R := A.R * Len;
            I := A.I * Len;
            J := A.J * Len;
            K := A.K * Len;
        end;
    end;
end;

Function QuatAdd (const A, B: TQuaternion): TQuaternion;
begin
    With Result do
    begin
        R := A.R + B.R;
        I := A.I + B.I;
        J := A.J + B.J;
        K := A.K + B.K;
    end;
end;

Function QuatSub (const Minuend, Subtrahend: TQuaternion): TQuaternion;
begin
    With Result do
    begin
        R := Minuend.R - Subtrahend.R;
        I := Minuend.I - Subtrahend.I;
        J := Minuend.J - Subtrahend.J;
        K := Minuend.K - Subtrahend.K;
    end;
end;

Function QuatMul (const A, B: TQuaternion): TQuaternion;
begin
    Result.R := A.R * B.R - A.I * B.I - A.J * B.J - A.K * B.K;
    Result.I := A.R * B.I + A.I * B.R + A.J * B.K - A.K * B.J;
    Result.J := A.R * B.J + A.J * B.R + A.K * B.I - A.I * B.K;
    Result.K := A.R * B.K + A.K * B.R + A.I * B.J - A.J * A.I;
end;

Function QuatMul (const Quat: TQuaternion; Multiplier: Float): TQuaternion; overload;
begin
    With Result do
    begin
        R := Quat.R * Multiplier;
        I := Quat.I * Multiplier;
        J := Quat.J * Multiplier;
        K := Quat.K * Multiplier;
    end;
end;

{���������� ����������, �������� ��������, �������� �������}
Function QuatConjugate (const A: TQuaternion): TQuaternion;
begin
    With Result do
    begin
        R := -A.R;
        I := A.I;
        J := A.J;
        K := A.K;
    end;
end;

{������� ����� �����������}
Function QuatNorma (const A: TQuaternion): Float;
begin
    With A do
        Result := R*R + I*I + J*J + K*K;
end;

{������������� ����������}
Function QuatInvert (const A: TQuaternion): TQuaternion;
Var Norma: Float;
begin
    With A do
        Norma := R*R + I*I + J*J + K*K;

    With Result do
    begin
        R := -A.R / Norma;
        I := A.I / Norma;
        J := A.J / Norma;
        K := A.K / Norma;
    end;
end;

{��������� ������������ ������������}
Function QuatScalarProduct (const A, B: TQuaternion): Float;
begin
    Result := A.R * B.R + A.I * B.I + A.J * B.J + A.K * B.K;
end;

Function QuatAddScaledVector (const AQuaternion: TQuaternion; const Vector: TVector3; const VectorScale: Float): TQuaternion;
Var Tmp: TQuaternion;
begin
    Tmp.R := 0;
    Tmp.I := Vector.X * VectorScale;
    Tmp.J := Vector.Y * VectorScale;
    Tmp.K := Vector.Z * VectorScale;

    Tmp := QuatMul (Tmp, AQuaternion);

    With AQuaternion do
    begin
        Result.R := R + Tmp.R * 0.5;
        Result.I := I + Tmp.I * 0.5;
        Result.J := J + Tmp.J * 0.5;
        Result.K := K + Tmp.K * 0.5;
    end;
end;

{������� ����������� �� �������}
Procedure QuatRotateByVector (Var AQuaternion: TQuaternion; const Vector: TVector3);
begin
    AQuaternion := QuatMul (AQuaternion, Quaternion (0, Vector.X, Vector.Y, Vector.Z));
end;

{������� ������� �� �����������}
Function V3RotateByQuat (const Vector: TVector3; const Quat: TQuaternion): TVector3;
Var Temp: TQuaternion;
begin
    Temp := QuatMul (QuatMul (Quat, Quaternion (Vector.X, Vector.Y, Vector.Z, 0)), QuatInvert (Quat));
    With Result do
    begin
        X := Temp.R;
        Y := Temp.I;
        Z := Temp.J;
    end;
end;

{�������� ���������� �� ���� (� ��������) � ��� ��������}
Function AngleToQuaternion (const AxisX, AxisY, AxisZ, Angle: Single): TQuaternion;
Var RadAngle,
    SinAngleOver2, CosAngleOver2: Extended;
begin
    RadAngle := (Angle / PiOver180);
    SinCos (RadAngle, SinAngleOver2, CosAngleOver2);
    Result := Quaternion (CosAngleOver2,
                          AxisX * SinAngleOver2,
                          AxisY * SinAngleOver2,
                          AxisZ * SinAngleOver2);
end;

{################################################################################
                        ������� 3*3 � �������� ��� ���
################################################################################}

Function Mat3x3 (const c0, c1, c2, c3, c4, c5, c6, c7, c8: Float): TMatrix3x3;
begin
    With Result do
    begin
        Data[0] := c0;
        Data[1] := c1;
        Data[2] := c2;
        Data[3] := c3;
        Data[4] := c4;
        Data[5] := c5;
        Data[6] := c6;
        Data[7] := c7;
        Data[8] := c8;
    end;
end;

Function Mat3x3ComponentWiseAddition (const A, B: TMatrix3x3): TMatrix3x3;
Var I: byte;
begin
    For I := 0 to 8 do
        Result.Data[i] := A.Data[i] + B.Data[i];
end;

Function Mat3x3GetIdentityMatrix: TMatrix3x3;
begin
    With Result do
    begin
        ZeroMemory (@Data, SizeOf (Data));
        Data[0] := 1;
        Data[4] := 1;
        Data[8] := 1;
    end;
end;

Procedure Mat3x3SetInertiaTensorParams (Var AMatrix: TMatrix3x3; const IX, IY, IZ: Float; const IXY: Float = 0; const IXZ: Float = 0; const IYZ: Float = 0);
begin
    With AMatrix do
    begin
        Data[0] := IX;
        Data[1] := -IXY;
        Data[2] := -IXZ;
        Data[3] := -IXY;
        Data[4] := IY;
        Data[5] := -IYZ;
        Data[6] := -IXZ;
        Data[7] := -IYZ;
        Data[8] := IZ;
    end;
end;

Function V3Perpendicular (const A: TVector3): TVector3;
Var RotationMatrix: TMatrix3x3;
begin
    ZeroMemory (@RotationMatrix, SizeOf (RotationMatrix));

    RotationMatrix.Data[1] := 1;
    RotationMatrix.Data[3] := -1;
    RotationMatrix.Data[8] := 1;

    Result := Mat3x3Mul (RotationMatrix, A);

    If V3Equal (Result, A) then
    begin
        ZeroMemory (@RotationMatrix, SizeOf (RotationMatrix));

        RotationMatrix.Data[2] := 1;
        RotationMatrix.Data[6] := -1;
        RotationMatrix.Data[8] := 1;

        Result := Mat3x3Mul (RotationMatrix, A);
    end;

    If V3Equal (Result, A) then
    begin
        ZeroMemory (@RotationMatrix, SizeOf (RotationMatrix));

        RotationMatrix.Data[3] := 1;
        RotationMatrix.Data[7] := -1;
        RotationMatrix.Data[8] := 1;

        Result := Mat3x3Mul (RotationMatrix, A);
    end;
end;

Procedure Mat3x3SetDiagonal (Var AMatrix: TMatrix3x3; const A, B, C: Float);
begin
    Mat3x3SetInertiaTensorParams (AMatrix, A, B, C);
end;

Procedure Mat3x3SetBodyInertiaTensor (Var AMatrix: TMatrix3x3; const HalfDimensions: TVector3; Mass: Float);
Var SquaredHalfDims: TVector3;
begin
    Mass := 0.3 * Mass;
    SquaredHalfDims := V3ComponentProduct (HalfDimensions, HalfDimensions);
    Mat3x3SetInertiaTensorParams (AMatrix, Mass * (SquaredHalfDims.Y + SquaredHalfDims.Z),
                            Mass * (SquaredHalfDims.X + SquaredHalfDims.Z),
                            Mass * (SquaredHalfDims.X + SquaredHalfDims.Y));
end;

Procedure Mat3x3SetDiagonalSymmetric (Var Matrix: TMatrix3x3; const Vector: TVector3);
begin
    ZeroMemory (@Matrix, SizeOf (Matrix));
    With Matrix do
    begin
        Data[1] := -Vector.Z;
        Data[2] := Vector.Y;
        Data[3] := Vector.Z;
        Data[5] := -Vector.X;
        Data[6] := -Vector.Y;
        Data[7] := Vector.X;
    end;
end;

Procedure Mat3x3SetComponents (Var AMatrix: TMatrix3x3; const First, Second, Third: TVector3);
begin
    With AMatrix do
    begin
        Data[0] := First.X;
        Data[1] := Second.X;
        Data[2] := Third.X;
        Data[3] := First.Y;
        Data[4] := Second.Y;
        Data[5] := Third.Y;
        Data[6] := First.Z;
        Data[7] := Second.Z;
        Data[8] := Third.Z;
    end;
end;

Function Mat3x3Mul (const AMatrix: TMatrix3x3; const AVector: TVector3): TVector3; overload;
begin
    With AMatrix do
    begin
        Result.X := AVector.X * Data[0] + AVector.Y * Data[1] + AVector.Z * Data[2];
        Result.Y := AVector.X * Data[3] + AVector.Y * Data[4] + AVector.Z * Data[5];
        Result.Z := AVector.X * Data[6] + AVector.Y * Data[7] + AVector.Z * Data[8];
    end;
end;

Function Mat3x3Mul (const A, B: TMatrix3x3): TMatrix3x3; overload;
begin
    With Result do
    begin
        Data[0] := A.Data[0] * B.Data[0] + A.Data[1] * A.Data[3] + A.Data[2] * B.Data[6];
        Data[1] := A.Data[0] * B.Data[1] + A.Data[1] * A.Data[4] + A.Data[2] * B.Data[7];
        Data[2] := A.Data[0] * B.Data[2] + A.Data[1] * A.Data[5] + A.Data[2] * B.Data[8];

        Data[3] := A.Data[3] * B.Data[0] + A.Data[4] * A.Data[3] + A.Data[5] * B.Data[6];
        Data[4] := A.Data[3] * B.Data[1] + A.Data[4] * A.Data[4] + A.Data[5] * B.Data[7];
        Data[5] := A.Data[3] * B.Data[2] + A.Data[4] * A.Data[5] + A.Data[5] * B.Data[8];

        Data[6] := A.Data[6] * B.Data[0] + A.Data[7] * A.Data[3] + A.Data[8] * B.Data[6];
        Data[7] := A.Data[6] * B.Data[1] + A.Data[7] * A.Data[4] + A.Data[8] * B.Data[7];
        Data[8] := A.Data[6] * B.Data[2] + A.Data[7] * A.Data[5] + A.Data[8] * B.Data[8];
    end;
end;
{$O-}
Function Mat3x3Mul (const AMatrix: TMatrix3x3; const Multiplier: Float): TMatrix3x3; overload;
Var I: Byte;
begin
    For I := 0 to 8 do
        Result.Data[i] := AMatrix.Data[i] * Multiplier;
end;
{$O+}
Function Mat3x3Transpose (const AMatrix: TMatrix3x3): TMatrix3x3;
begin
    With Result do
    begin
        Data[0] := AMatrix.Data[0];
        Data[1] := AMatrix.Data[3];
        Data[2] := AMatrix.Data[6];
        Data[3] := AMatrix.Data[1];
        Data[4] := AMatrix.Data[4];
        Data[5] := AMatrix.Data[7];
        Data[6] := AMatrix.Data[2];
        Data[7] := AMatrix.Data[5];
        Data[8] := AMatrix.Data[8];
    end;
end;

Function Mat3x3TransposeTransformV3ByMatrix3x3 (const AMatrix: TMatrix3x3; const AVector: TVector3): TVector3;
begin
    With AMatrix do
    begin
        Result.X := AVector.X * Data[0] + AVector.Y * Data[3] + AVector.Z * Data[6];
        Result.Y := AVector.X * Data[1] + AVector.Y * Data[4] + AVector.Z * Data[7];
        Result.Z := AVector.X * Data[2] + AVector.Y * Data[5] + AVector.Z * Data[8];
    end;
end;

Function Mat3x3Invert (const Matrix: TMatrix3x3): TMatrix3x3;
Var T0, T1, T2, T3, T4, T5: Float;
    Determinant: Float;
begin
    With Matrix do
    begin
        T0 := Data[0] * Data[4];
        T1 := Data[0] * Data[5];
        T2 := Data[1] * Data[3];
        T3 := Data[2] * Data[3];
        T4 := Data[1] * Data[6];
        T5 := Data[2] * Data[6];

        {������������ = aei + dhc + gbf - ahf - gec - dbi}
        Determinant := T0 * Data[8] - T1 * Data[7] - T2 * Data[8]
                       + T3 * Data[7] + T4 * Data[5] - T5 * Data[4];
        {�� ������� �������������� ������� �������, ��� ������������ �� ������ ���� ����� 0}
        If (Determinant = 0) then Exit;

        Determinant := 1/Determinant;

        Result.Data[0] := (Data[4] * Data[8] - Data[5] * Data[7]) * Determinant;
        Result.Data[1] := - (Data[1] * Data[8] - Data[2] * Data[7]) * Determinant;
        Result.Data[2] := (Data[1] * Data[5] - Data[2] * Data[4]) * Determinant;
        Result.Data[3] := - (Data[3] * Data[8] - Data[5] * Data[6]) * Determinant;
        Result.Data[4] := (Data[0] * Data[8] - T5) * Determinant;
        Result.Data[5] := (T3 - T1) * Determinant;
        Result.Data[6] := (Data[3] * Data[7] - Data[4] * Data[6]) * Determinant;
        Result.Data[7] := - (Data[0] * Data[7] - T4) * Determinant;
        Result.Data[8] := (T0 - T2) * Determinant;
    end;
end;

Function Mat3x3GetRowByIndex (const AMatrix: TMatrix3x3; Index: byte): TVector3;
begin
    Index := Index * 3;
    With Result do
    begin
        X := AMatrix.Data [Index];
        Y := AMatrix.Data [Index + 1];
        Z := AMatrix.Data [Index + 2];
    end;
end;

Function Mat3x3GetColumnByIndex (const AMatrix: TMatrix3x3; const Index: byte): TVector3;
begin
    With Result do
    begin
        X := AMatrix.Data [Index];
        Y := AMatrix.Data [Index + 3];
        Z := AMatrix.Data [Index + 6];
    end;
end;

Function QuatToMat3x3 (const Quat: TQuaternion): TMatrix3x3;
begin
    With Quat do
    begin
        Result.Data[0] := 1 - 2 * (J * J + K * K);
        Result.Data[1] := 2 * (I * J + K * R);
        Result.Data[2] := 2 * (I * K - J * R);

        Result.Data[3] := 2 * (I * J - K * R);
        Result.Data[4] := 1 - 2 * (I * I + K * K);
        Result.Data[5] := 2 * (J * K + I * R);

        Result.Data[6] := 2 * (I * K + J * R);
        Result.Data[7] := 2 * (J * K - I * R);
        Result.Data[8] := 1 - 2 * (I * I + J * J);
    end;
end;

Function Mat3x3LinearInterpolation (const A, B: TMatrix3x3; const Proportion: Float): TMatrix3x3;
Var I: byte;
begin
    For I := 0 to 8 do
        Result.Data[i] := A.Data[i] * (1 - Proportion) + B.Data[i] * Proportion;
end;

{################################################################################
                        ������� 3*4 � �������� ��� ���
################################################################################}
{�������� ����� � ��������� �������������}
Function Mat3x4 (const D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11: Float): TMatrix3x4;
begin
    With Result do
    begin
        Data[0] := D0;
        Data[1] := D1;
        Data[2] := D2;
        Data[3] := D3;
        Data[4] := D4;
        Data[5] := D5;
        Data[6] := D6;
        Data[7] := D7;
        Data[8] := D8;
        Data[9] := D9;
        Data[10] := D10;
        Data[11] := D11;
    end;
end;

{���������� ��������� ������� 4x4}
Function Mat3x4GetIdentityMatrix: TMatrix3x4;
begin
    ZeroMemory (@Result.Data, SizeOf (Result.Data));
    With Result do
    begin
        Data[0] := 1;
        Data[5] := 1;
        Data[10] := 1;
    end;
end;

{������ ��������� �������}
Procedure Mat3x4SetDiagonal (Var AMatrix: TMatrix3x4; const D0, D1, D2: Float);
begin
    With AMatrix do
    begin
        Data[0] := D0;
        Data[5] := D1;
        Data[10] := D2;
    end;
end;

{��������� ������� �� �������}
Function Mat3x4Mul (const A, B: TMatrix3x4): TMatrix3x4;// overload;
begin
    With Result do
    begin
        Data[0] := (A.Data[0] * B.Data[0]) + (A.Data[4] * B.Data[1]) + (A.Data[8] * B.Data[2]);
        Data[4] := (A.Data[0] * B.Data[4]) + (A.Data[4] * B.Data[5]) + (A.Data[8] * B.Data[6]);
        Data[8] := (A.Data[0] * B.Data[8]) + (A.Data[4] * B.Data[9]) + (A.Data[8] * B.Data[10]);

        Data[1] := (A.Data[1] * B.Data[0]) + (A.Data[5] * B.Data[1]) + (A.Data[9] * B.Data[2]);
        Data[5] := (A.Data[1] * B.Data[4]) + (A.Data[5] * B.Data[5]) + (A.Data[9] * B.Data[6]);
        Data[9] := (A.Data[1] * B.Data[8]) + (A.Data[5] * B.Data[9]) + (A.Data[9] * B.Data[10]);

        Data[2] := (A.Data[2] * B.Data[0]) + (A.Data[6] * B.Data[1]) + (A.Data[10] * B.Data[2]);
        Data[6] := (A.Data[2] * B.Data[4]) + (A.Data[6] * B.Data[5]) + (A.Data[10] * B.Data[6]);
        Data[10] := (A.Data[2] * B.Data[8]) + (A.Data[6] * B.Data[9]) + (A.Data[10] * B.Data[10]);

        Data[3] := (A.Data[3] * B.Data[0]) + (A.Data[7] * B.Data[1]) + (A.Data[11] * B.Data[2]) + B.Data[3];
        Data[7] := (A.Data[3] * B.Data[4]) + (A.Data[7] * B.Data[5]) + (A.Data[11] * B.Data[6]) + B.Data[7];
        Data[11] := (A.Data[3] * B.Data[8]) + (A.Data[7] * B.Data[9]) + (A.Data[11] * B.Data[10]) + B.Data[11];
    end;
end;

{��������� ������� �� �����}
Function Mat3x4Mul (const Matrix: TMatrix3x4; const Multiplier: Float): TMatrix3x4;// overload;
Var I: byte;
begin
    For I := 0 to 11 do
        Result.Data[i] := Matrix.Data[i] * Multiplier;
end;

Function Mat3x4Mul (const AMatrix: TMatrix3x4; const AVector: TVector3): TVector3;// overload;
begin
    With AMatrix do
    begin
        Result.X := AVector.X * Data[0] + AVector.Y * Data[1] + AVector.Z * Data[2] + Data[3];
        Result.Y := AVector.X * Data[4] + AVector.Y * Data[5] + AVector.Z * Data[6] + Data[7];
        Result.Z := AVector.X * Data[8] + AVector.Y * Data[9] + AVector.Z * Data[10] + Data[11];
    end;
end;

Function Mat3x4CalculateDeterminant (const AMatrix: TMatrix3x4): Float;
begin
    With AMatrix do
        Result := Data[8] * Data[5] * Data[2] +
                  Data[4] * Data[9] * Data[2] +
                  Data[8] * Data[1] * Data[6] -
                  Data[0] * Data[9] * Data[6] -
                  Data[4] * Data[1] * Data[10] +
                  Data[0] * Data[5] * Data[10];
end;

Function Mat3x4Invert (const AMatrix: TMatrix3x4): TMatrix3x4;
Var Determinant: Float;
begin
    With AMatrix do
    begin
        Determinant := Mat3x4CalculateDeterminant (AMatrix);
        If (Determinant = 0) then Exit;
        Determinant := 1 / Determinant;

        Result.Data[0] := (Data[5] * Data[10] - Data[9] * Data[6]) * Determinant;
        Result.Data[4] := (Data[8] * Data[6] - Data[4] * Data[10]) * Determinant;
        Result.Data[8] := (Data[4] * Data[9] - Data[8] * Data[5]) * Determinant;

        Result.Data[1] := (Data[9] * Data[2] - Data[1] * Data[10]) * Determinant;
        Result.Data[5] := (Data[0] * Data[10] - Data[8] * Data[2]) * Determinant;
        Result.Data[9] := (Data[8] * Data[1] - Data[0] * Data[9]) * Determinant;

        Result.Data[2] := (Data[1] * Data[6] - Data[5] * Data[2]) * Determinant;
        Result.Data[6] := (Data[4] * Data[2] - Data[0] * Data[6]) * Determinant;
        Result.Data[10] := (Data[0] * Data[5] - Data[4] * Data[1]) * Determinant;

        Result.Data[3] := (Data[9] * Data[6] * Data[3] -
                           Data[5] * Data[10] * Data[3] -
                           Data[9] * Data[2] * Data[7] +
                           Data[1] * Data[10] * Data[7] +
                           Data[5] * Data[2] * Data[11] -
                           Data[1] * Data[6] * Data[11]) * Determinant;
        Result.Data[7] := (Data[4] * Data[10] * Data[3] -
                           Data[8] * Data[6] * Data[3] +
                           Data[8] * Data[2] * Data[7] -
                           Data[0] * Data[10] * Data[7] -
                           Data[4] * Data[2] * Data[11] +
                           Data[0] * Data[6] * Data[11]) * Determinant;
        Result.Data[11] := (Data[8] * Data[5] * Data[3] -
                           Data[4] * Data[9] * Data[3] -
                           Data[8] * Data[1] * Data[7] +
                           Data[0] * Data[9] * Data[7] +
                           Data[4] * Data[1] * Data[11] -
                           Data[0] * Data[5] * Data[11]) * Determinant;
    end;
end;

Function Mat3x4MulDirV3 (const AMatrix: TMatrix3x4; const DirectionVector: TVector3): TVector3;
begin
    With AMatrix do
    begin
        Result.X := DirectionVector.X * Data[0] + DirectionVector.Y * Data[1] + DirectionVector.Z * Data[2];
        Result.Y := DirectionVector.X * Data[4] + DirectionVector.Y * Data[5] + DirectionVector.Z * Data[6];
        Result.Z := DirectionVector.X * Data[8] + DirectionVector.Y * Data[9] + DirectionVector.Z * Data[10];
    end;
end;

Function Mat3x4MulInvDirV3 (const AMatrix: TMatrix3x4; const DirectionVector: TVector3): TVector3;
begin
    With AMatrix do
    begin
        Result.X := DirectionVector.X * Data[0] + DirectionVector.Y * Data[4] + DirectionVector.Z * Data[8];
        Result.Y := DirectionVector.X * Data[1] + DirectionVector.Y * Data[5] + DirectionVector.Z * Data[9];
        Result.Z := DirectionVector.X * Data[2] + DirectionVector.Y * Data[6] + DirectionVector.Z * Data[10];
    end;
end;

Function Mat3x4MulInvV3 (const AMatrix: TMatrix3x4; const Vector: TVector3): TVector3;
Var Tmp: TVector3;
begin
    With AMatrix do
    begin
        Tmp.X := Vector.X - Data[3];
        Tmp.Y := Vector.Y - Data[7];
        Tmp.Z := Vector.Z - Data[11];

        Result.X := Tmp.X * Data[0] + Tmp.Y * Data[4] + Tmp.Z * Data[8];
        Result.Y := Tmp.X * Data[1] + Tmp.Y * Data[5] + Tmp.Z * Data[9];
        Result.Z := Tmp.X * Data[2] + Tmp.Y * Data[6] + Tmp.Z * Data[10];
    end;
end;

Function Mat3x4GetColumnByIndex (const AMatrix: TMatrix3x4; const Index: byte): TVector3;
begin
    Result.X := AMatrix.Data [Index];
    Result.Y := AMatrix.Data [Index + 4];
    Result.Z := AMatrix.Data [Index + 8];
end;

Function Mat3x4GetRowByIndex (const AMatrix: TMatrix3x4; Index: byte): TVector3;
begin
    Index := Index shl 2;
    Result.X := AMatrix.Data [Index];
    Result.Y := AMatrix.Data [Index + 1];
    Result.Z := AMatrix.Data [Index + 2];
end;

Function OrientAndPosToMatrix3x4 (const Orientation: TQuaternion; const Position: TVector3): TMatrix3x4;
Var ij, ik, ir, jr, jk, kr, i2, k2, j2: Float;    //��������� ���������
begin
    With Orientation do
    begin
        ij := i * j;
        ik := i * k;
        ir := i * r;
        jr := j * r;
        jk := j * k;
        kr := k * r;
        i2 := i * i;
        k2 := k * k;
        j2 := j * j;

        Result.Data[0] := 1 - 2 * (j2  + k2);
        Result.Data[1] := 2 * (ij  - kr);
        Result.Data[2] := 2 * (ik  + jr);
        Result.Data[3] := Position.X;

        Result.Data[4] := 2 * (ij  + kr);
        Result.Data[5] := 1 - 2 * (i2  + k2);
        Result.Data[6] := 2 * (jk  - ir);
        Result.Data[7] := Position.Y;

        Result.Data[8] := 2 * (ik  - jr);
        Result.Data[9] := 2 * (jk  + ir);
        Result.Data[10] := 1 - 2 * (i2  + j2);
        Result.Data[11] := Position.Z;
    end;
end;

Function Mat3x4Transpose (const AMatrix: TMatrix3x4): TMatrix3x4;
begin
    With Result do
    begin
        Data[0] := AMatrix.Data[0];
        Data[1] := AMatrix.Data[4];
        Data[2] := AMatrix.Data[8];

        Data[3] := AMatrix.Data[1];
        Data[4] := AMatrix.Data[5];
        Data[5] := AMatrix.Data[9];

        Data[6] := AMatrix.Data[2];
        Data[7] := AMatrix.Data[6];
        Data[8] := AMatrix.Data[10];

        Data[9] := AMatrix.Data[3];
        Data[10] := AMatrix.Data[7];
        Data[11] := AMatrix.Data[11];
    end;
end;

Procedure Mat3x4ToGLArray (const AMatrix: TMatrix3x4; Var AArray: TGlArray16F);
begin
    AArray [0] := AMatrix.Data[0];
    AArray [1] := AMatrix.Data[4];
    AArray [2] := AMatrix.Data[8];
    AArray [3] := 0;

    AArray [4] := AMatrix.Data[1];
    AArray [5] := AMatrix.Data[5];
    AArray [6] := AMatrix.Data[9];
    AArray [7] := 0;

    AArray [8] := AMatrix.Data[2];
    AArray [9] := AMatrix.Data[6];
    AArray [10] := AMatrix.Data[10];
    AArray [11] := 0;

    AArray [12] := AMatrix.Data[3];
    AArray [13] := AMatrix.Data[7];
    AArray [14] := AMatrix.Data[11];
    AArray [15] := 1;
end;

Procedure GLArrayToMat3x4 (const AArray: TGlArray16F; Var AMatrix: TMatrix3x4);
begin
    With AMatrix do
    begin
        Data[0] := AArray[0];
        Data[1] := AArray[4];
        Data[2] := AArray[8];

        Data[3] := AArray[12];
        Data[4] := AArray[1];
        Data[5] := AArray[5];

        Data[6] := AArray[9];
        Data[7] := AArray[13];
        Data[8] := AArray[2];

        Data[9] := AArray[6];
        Data[10] := AArray[10];
        Data[11] := AArray[14];
    end;
end;

{��������� ������� �� ���� 3x3 � ��� 3x4}
Function Mat3x3ToMat3x4 (const Matrix3x3: TMatrix3x3): TMatrix3x4;
Var I: byte;
begin
    ZeroMemory (@Result, SizeOf (Result));
    For I := 0 to 8 do
        Result.Data[i] := Matrix3x3.Data[i];
end;

Function Mat3x3TransformByQuaternion (const Quat: TQuaternion; const BodyIT: TMatrix3x3; const RotMat: TMatrix3x4): TMatrix3x3;
Var T0, T1, T2, T3, T4, T5, T6, T7, T8: Float;    //��������� ���������
begin
    T0 := RotMat.Data[0] * BodyIT.Data[0] + RotMat.Data[1] * BodyIT.Data[3] + RotMat.Data[2] * BodyIT.Data[6];
    T1 := RotMat.Data[0] * BodyIT.Data[1] + RotMat.Data[1] * BodyIT.Data[4] + RotMat.Data[2] * BodyIT.Data[7];
    T2 := RotMat.Data[0] * BodyIT.Data[2] + RotMat.Data[1] * BodyIT.Data[5] + RotMat.Data[2] * BodyIT.Data[8];

    T3 := RotMat.Data[4] * BodyIT.Data[0] + RotMat.Data[5] * BodyIT.Data[3] + RotMat.Data[6] * BodyIT.Data[6];
    T4 := RotMat.Data[4] * BodyIT.Data[1] + RotMat.Data[5] * BodyIT.Data[4] + RotMat.Data[6] * BodyIT.Data[7];
    T5 := RotMat.Data[4] * BodyIT.Data[2] + RotMat.Data[5] * BodyIT.Data[5] + RotMat.Data[6] * BodyIT.Data[8];

    T6 := RotMat.Data[8] * BodyIT.Data[0] + RotMat.Data[9] * BodyIT.Data[3] + RotMat.Data[10] * BodyIT.Data[6];
    T7 := RotMat.Data[8] * BodyIT.Data[1] + RotMat.Data[9] * BodyIT.Data[4] + RotMat.Data[10] * BodyIT.Data[7];
    T8 := RotMat.Data[8] * BodyIT.Data[2] + RotMat.Data[9] * BodyIT.Data[5] + RotMat.Data[10] * BodyIT.Data[8];

    With RotMat do
    begin
        Result.Data[0] := T0 * Data[0] + T1 * Data[1] + T2 * Data[2];
        Result.Data[1] := T0 * Data[4] + T1 * Data[5] + T2 * Data[6];
        Result.Data[2] := T0 * Data[8] + T1 * Data[9] + T2 * Data[10];

        Result.Data[3] := T3 * Data[0] + T4 * Data[1] + T5 * Data[2];
        Result.Data[4] := T3 * Data[4] + T4 * Data[5] + T5 * Data[6];
        Result.Data[5] := T3 * Data[8] + T4 * Data[9] + T5 * Data[10];

        Result.Data[6] := T6 * Data[0] + T7 * Data[1] + T8 * Data[2];
        Result.Data[7] := T6 * Data[4] + T7 * Data[5] + T8 * Data[6];
        Result.Data[8] := T6 * Data[8] + T7 * Data[9] + T8 * Data[10];
    end;
end;

Function Mat4x4 (const D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15: glFloat): TMatrix4x4;
begin
    With Result do
    begin
        Data[0] := D0;
        Data[1] := D1;
        Data[2] := D2;
        Data[3] := D3;

        Data[4] := D4;
        Data[5] := D5;
        Data[6] := D6;
        Data[7] := D7;

        Data[8] := D8;
        Data[9] := D9;
        Data[10] := D10;
        Data[11] := D11;

        Data[12] := D12;
        Data[13] := D13;
        Data[14] := D14;
        Data[15] := D15;
    end;
end;

Function OrientAndPosToMatrix4x4 (const Quat: TQuaternion; const Position: TVector3): TMatrix4x4;
Var ij, ik, ir, jr, jk, kr, i2, k2, j2: Float;    //��������� ���������
begin
    With Quat do
    begin
        ij := i * j;
        ik := i * k;
        ir := i * r;
        jr := j * r;
        jk := j * k;
        kr := k * r;
        i2 := i * i;
        k2 := k * k;
        j2 := j * j;

        Result.Data [0] := 1 - 2 * (j2  + k2);
        Result.Data [1] := 2 * (ij  + kr);
        Result.Data [2] := 2 * (ik  - jr);
        Result.Data [3] := 0;

        Result.Data [4] := 2 * (ij  - kr);
        Result.Data [5] := 1 - 2 * (i2  + k2);
        Result.Data [6] := 2 * (jk  + ir);
        Result.Data [7] := 0;

        Result.Data [8] := 2 * (ik  + jr);
        Result.Data [9] := 2 * (jk  - ir);
        Result.Data [10] := 1 - 2 * (i2  + j2);
        Result.Data [11] := 0;

        Result.Data [12] := Position.X;
        Result.Data [13] := Position.Y;
        Result.Data [14] := Position.Z;
        Result.Data [15] := 1;
    end;
end;

end.

