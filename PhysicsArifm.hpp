// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Physicsarifm.pas' rev: 11.00

#ifndef PhysicsarifmHPP
#define PhysicsarifmHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Dglopengl.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Physicsarifm
{
//-- type declarations -------------------------------------------------------
typedef Shortint TGLArray4b[4];

typedef bool TGLArray4bo[4];

typedef double TGLArray4d[4];

typedef float TGLArray4F[4];

typedef Byte TGLArray4ub[4];

typedef Shortint TGLArray3b[3];

typedef bool TGLArray3bo[3];

typedef double TGLArray3d[3];

typedef float TGLArray3f[3];

typedef Byte TGLArray3ub[3];

typedef Shortint TGLArray2b[2];

typedef bool TGLArray2bo[2];

typedef double TGLArray2d[2];

typedef float TGLArray2f[2];

typedef Byte TGLArray2ub[2];

struct TVector3
{
	
public:
	double X;
	double Y;
	double Z;
} ;

typedef DynamicArray<TVector3 >  TVectors3;

typedef TVector3 T2Vectors3D[2];

typedef float TGlArray16f[16];

#pragma pack(push,1)
struct TQuaternion
{
	
public:
	double R;
	double I;
	double J;
	double K;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TMatrix3x3
{
	
public:
	double Data[9];
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TMatrix3x4
{
	
public:
	double Data[12];
} ;
#pragma pack(pop)

struct TMatrix4x4
{
	
public:
	float Data[16];
} ;

struct TPlane
{
	
public:
	TVector3 Normal;
	double Offset;
} ;

//-- var, const, procedure ---------------------------------------------------
static const Extended PiOver180 = 5.729578E+01;
static const Extended CMP_EPS = 1.000000E-09;
static const Extended EPS = 1.000000E-08;
extern PACKAGE TVector3 Gravity;
extern PACKAGE TVector3 __fastcall V3(const double XCoord, const double YCoord, const double ZCoord)/* overload */;
extern PACKAGE TVector3 __fastcall V3(const double Value)/* overload */;
extern PACKAGE bool __fastcall V3Equal(const TVector3 &A, const TVector3 &B);
extern PACKAGE TVector3 __fastcall V3Add(const TVector3 &A, const TVector3 &B);
extern PACKAGE TVector3 __fastcall V3Invert(const TVector3 &A);
extern PACKAGE TVector3 __fastcall V3Sub(const TVector3 &A, const TVector3 &B);
extern PACKAGE Extended __fastcall V3Length(const TVector3 &A);
extern PACKAGE Extended __fastcall V3SquareLength(const TVector3 &A);
extern PACKAGE bool __fastcall V3CheckSonapr(const TVector3 &A, const TVector3 &B);
extern PACKAGE TVector3 __fastcall V3Mul(const TVector3 &A, const TVector3 &B)/* overload */;
extern PACKAGE TVector3 __fastcall V3Mul(const TVector3 &A, const double B)/* overload */;
extern PACKAGE TVector3 __fastcall V3Div(const TVector3 &A, const double B)/* overload */;
extern PACKAGE TVector3 __fastcall V3Div(const TVector3 &A, const TVector3 &B)/* overload */;
extern PACKAGE TVector3 __fastcall V3ComponentWiseSquare(const TVector3 &A);
extern PACKAGE TVector3 __fastcall V3Perpendicular(const TVector3 &A);
extern PACKAGE TVector3 __fastcall V3Normalize(const TVector3 &A);
extern PACKAGE double __fastcall V3ScalarProduct(const TVector3 &A, const TVector3 &B);
extern PACKAGE TVector3 __fastcall V3ScalarPerpendicularProduct(const TVector3 &A, const TVector3 &B);
extern PACKAGE TVector3 __fastcall V3ComponentProduct(const TVector3 &A, const TVector3 &B);
extern PACKAGE TVector3 __fastcall V3AddScaledVector(const TVector3 &A, const TVector3 &B, const double B_Scale);
extern PACKAGE void __fastcall V3SetLength(TVector3 &Vector, const double Len);
extern PACKAGE double __fastcall V3Project(const TVector3 &Vector, const TVector3 &Axis);
extern PACKAGE void __fastcall Vectors3ConcatReplace(TVectors3 &A, const TVectors3 B);
extern PACKAGE TVectors3 __fastcall Vectors3Concat(const TVectors3 A, const TVectors3 B)/* overload */;
extern PACKAGE TVector3 __fastcall V3TrimVector(const TVector3 &A, const double Limit);
extern PACKAGE double __fastcall GenerateRandomNumber(const double Min, const double Max);
extern PACKAGE TVector3 __fastcall GetNormalToPlane(const TVector3 &V0, const TVector3 &V1, const TVector3 &V2);
extern PACKAGE double __fastcall GetDistanceToPlane(const TVector3 &ANormal, const TVector3 &APoint);
extern PACKAGE TVector3 __fastcall GetClosestPointOnLineSegment(const TVector3 &LineStart, const TVector3 &LineEnd, const TVector3 &Point);
extern PACKAGE TVector3 __fastcall GetClosestPointOnLine(const TVector3 &LineStart, const TVector3 &LineEnd, const TVector3 &Point);
extern PACKAGE bool __fastcall LineIntersectsLine(const TVector3 &DirA, const TVector3 &DirB, TVector3 &InterSectionPoint);
extern PACKAGE double __fastcall GetAngleBetweenVectors(const TVector3 &A, const TVector3 &B);
extern PACKAGE double __fastcall GetSineOfAngleBetweenV3(const TVector3 &A, const TVector3 &B);
extern PACKAGE Byte __fastcall GetDistanceFromSphereCenterToPlane(const TVector3 &CCenter, const double CRadius, const TVector3 &PStartPoint, const TVector3 &PNormal, double &CenterToPlaneDistance);
extern PACKAGE TVector3 __fastcall GetCollisionOffset(const TVector3 &Normal, const double SphereRadius, const double SphereCenterToPlaneDistance);
extern PACKAGE bool __fastcall RayInterSectsPlane(const TVector3 &RayStart, const TVector3 &RayDir, const TVector3 &V0, const TVector3 &V1, const TVector3 &V2, TVector3 &InterSectionPoint);
extern PACKAGE TQuaternion __fastcall Quaternion(const double RealCmp, const double FCmp, const double SCmp, const double TCmp);
extern PACKAGE double __fastcall QuatLength(const TQuaternion &A);
extern PACKAGE TQuaternion __fastcall QuatNormalize(const TQuaternion &A);
extern PACKAGE TQuaternion __fastcall QuatMul(const TQuaternion &A, const TQuaternion &B);
extern PACKAGE TQuaternion __fastcall QuatAddScaledVector(const TQuaternion &AQuaternion, const TVector3 &Vector, const double VectorScale);
extern PACKAGE void __fastcall QuatRotateByVector(TQuaternion &AQuaternion, const TVector3 &Vector);
extern PACKAGE TQuaternion __fastcall AngleToQuaternion(const float AxisX, const float AxisY, const float AxisZ, const float Angle);
extern PACKAGE TMatrix3x3 __fastcall Mat3x3(const double c0, const double c1, const double c2, const double c3, const double c4, const double c5, const double c6, const double c7, const double c8);
extern PACKAGE TMatrix3x3 __fastcall Mat3x3ComponentWiseAddition(const TMatrix3x3 &A, const TMatrix3x3 &B);
extern PACKAGE TMatrix3x3 __fastcall Mat3x3GetIdentityMatrix();
extern PACKAGE void __fastcall Mat3x3SetInertiaTensorParams(TMatrix3x3 &AMatrix, const double IX, const double IY, const double IZ, const double IXY = 0.000000E+00, const double IXZ = 0.000000E+00, const double IYZ = 0.000000E+00);
extern PACKAGE void __fastcall Mat3x3SetDiagonal(TMatrix3x3 &AMatrix, const double A, const double B, const double C);
extern PACKAGE void __fastcall Mat3x3SetBodyInertiaTensor(TMatrix3x3 &AMatrix, const TVector3 &HalfDimensions, double Mass);
extern PACKAGE void __fastcall Mat3x3SetDiagonalSymmetric(TMatrix3x3 &Matrix, const TVector3 &Vector);
extern PACKAGE void __fastcall Mat3x3SetComponents(TMatrix3x3 &AMatrix, const TVector3 &First, const TVector3 &Second, const TVector3 &Third);
extern PACKAGE TVector3 __fastcall Mat3x3Mul(const TMatrix3x3 &AMatrix, const TVector3 &AVector)/* overload */;
extern PACKAGE TMatrix3x3 __fastcall Mat3x3Mul(const TMatrix3x3 &A, const TMatrix3x3 &B)/* overload */;
extern PACKAGE TMatrix3x3 __fastcall Mat3x3Mul(const TMatrix3x3 &AMatrix, const double Multiplier)/* overload */;
extern PACKAGE TMatrix3x3 __fastcall Mat3x3Transpose(const TMatrix3x3 &AMatrix);
extern PACKAGE TVector3 __fastcall Mat3x3TransposeTransformV3ByMatrix3x3(const TMatrix3x3 &AMatrix, const TVector3 &AVector);
extern PACKAGE TMatrix3x3 __fastcall Mat3x3Invert(const TMatrix3x3 &Matrix);
extern PACKAGE TVector3 __fastcall Mat3x3GetRowByIndex(const TMatrix3x3 &AMatrix, Byte Index);
extern PACKAGE TVector3 __fastcall Mat3x3GetColumnByIndex(const TMatrix3x3 &AMatrix, const Byte Index);
extern PACKAGE TMatrix3x3 __fastcall QuatToMat3x3(const TQuaternion &Quat);
extern PACKAGE TMatrix3x3 __fastcall Mat3x3LinearInterpolation(const TMatrix3x3 &A, const TMatrix3x3 &B, const double Proportion);
extern PACKAGE TMatrix3x4 __fastcall Mat3x4(const double D0, const double D1, const double D2, const double D3, const double D4, const double D5, const double D6, const double D7, const double D8, const double D9, const double D10, const double D11);
extern PACKAGE TMatrix3x4 __fastcall Mat3x4GetIdentityMatrix();
extern PACKAGE void __fastcall Mat3x4SetDiagonal(TMatrix3x4 &AMatrix, const double D0, const double D1, const double D2);
extern PACKAGE TMatrix3x4 __fastcall Mat3x4Mul(const TMatrix3x4 &A, const TMatrix3x4 &B)/* overload */;
extern PACKAGE TMatrix3x4 __fastcall Mat3x4Mul(const TMatrix3x4 &Matrix, const double Multiplier)/* overload */;
extern PACKAGE TVector3 __fastcall Mat3x4Mul(const TMatrix3x4 &AMatrix, const TVector3 &AVector)/* overload */;
extern PACKAGE TMatrix3x4 __fastcall Mat3x4Invert(const TMatrix3x4 &AMatrix);
extern PACKAGE TVector3 __fastcall Mat3x4MulDirV3(const TMatrix3x4 &AMatrix, const TVector3 &DirectionVector);
extern PACKAGE TVector3 __fastcall Mat3x4MulInvDirV3(const TMatrix3x4 &AMatrix, const TVector3 &DirectionVector);
extern PACKAGE TVector3 __fastcall Mat3x4MulInvV3(const TMatrix3x4 &AMatrix, const TVector3 &Vector);
extern PACKAGE TVector3 __fastcall Mat3x4GetColumnByIndex(const TMatrix3x4 &AMatrix, const Byte Index);
extern PACKAGE TVector3 __fastcall Mat3x4GetRowByIndex(const TMatrix3x4 &AMatrix, Byte Index);
extern PACKAGE TMatrix3x4 __fastcall OrientAndPosToMatrix3x4(const TQuaternion &Orientation, const TVector3 &Position);
extern PACKAGE TMatrix3x4 __fastcall Mat3x4Transpose(const TMatrix3x4 &AMatrix);
extern PACKAGE void __fastcall Mat3x4ToGLArray(const TMatrix3x4 &AMatrix, float * AArray);
extern PACKAGE void __fastcall GLArrayToMat3x4(float const * AArray, TMatrix3x4 &AMatrix);
extern PACKAGE TMatrix3x4 __fastcall Mat3x3ToMat3x4(const TMatrix3x3 &Matrix3x3);
extern PACKAGE TMatrix3x3 __fastcall Mat3x3TransformByQuaternion(const TQuaternion &Quat, const TMatrix3x3 &BodyIT, const TMatrix3x4 &RotMat);
extern PACKAGE TMatrix4x4 __fastcall Mat4x4(const float D0, const float D1, const float D2, const float D3, const float D4, const float D5, const float D6, const float D7, const float D8, const float D9, const float D10, const float D11, const float D12, const float D13, const float D14, const float D15);
extern PACKAGE TMatrix4x4 __fastcall OrientAndPosToMatrix4x4(const TQuaternion &Quat, const TVector3 &Position);

}	/* namespace Physicsarifm */
using namespace Physicsarifm;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Physicsarifm
