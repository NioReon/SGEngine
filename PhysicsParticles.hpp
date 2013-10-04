// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Physicsparticles.pas' rev: 11.00

#ifndef PhysicsparticlesHPP
#define PhysicsparticlesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Dglopengl.hpp>	// Pascal unit
#include <Physicsarifm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Physicsparticles
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TParticle;
class PASCALIMPLEMENTATION TParticle : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Physicsarifm::TVector3 PreviousPosition;
	Physicsarifm::TVector3 Position;
	Physicsarifm::TVector3 ForceAccumulator;
	double Mass;
	double Radius;
	unsigned Texture;
	__fastcall TParticle(const Physicsarifm::TVector3 &InitialPosition, const Physicsarifm::TVector3 &InitialVelocity, const Physicsarifm::TVector3 &InitialForce, const unsigned ParticleTexture, const double ParticleMass, const double ParticleRadius);
	void __fastcall ClearForceAccumulator(void);
	double __fastcall GetMass(void);
	double __fastcall GetInvMass(void);
	Physicsarifm::TVector3 __fastcall GetVelocity(const double DeltaTime);
	void __fastcall SetVelocity(const Physicsarifm::TVector3 &Value, const double DeltaTime);
	Physicsarifm::TVector3 __fastcall GetAcceleration();
	void __fastcall SetAcceleration(const Physicsarifm::TVector3 &Value);
	void __fastcall AddForce(const Physicsarifm::TVector3 &Force);
	void __fastcall Draw(void);
	void __fastcall Integrate(const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TParticle(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TParticle* >  TParticles;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Physicsparticles */
using namespace Physicsparticles;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Physicsparticles
