// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Cameras.pas' rev: 11.00

#ifndef CamerasHPP
#define CamerasHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Opengl.hpp>	// Pascal unit
#include <Physicsarifm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cameras
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCamera;
class PASCALIMPLEMENTATION TCamera : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Physicsarifm::TVector3 Position;
	#pragma pack(push,1)
	Physicsarifm::TQuaternion Heading;
	#pragma pack(pop)
	#pragma pack(push,1)
	Physicsarifm::TQuaternion Tilt;
	#pragma pack(pop)
	float HeadingAngle;
	float TiltAngle;
	Physicsarifm::TVector3 LookDirection;
	float FOVAngle;
	float NearClippingDistance;
	float FarClippingDistance;
	__fastcall TCamera(const float X, const float Y, const float Z, const float FOV, const float NearClipDistance, const float FarClipDistance);
	void __fastcall Update(const float RotationSpeed = 2.000000E+00);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCamera(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Cameras */
using namespace Cameras;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Cameras
