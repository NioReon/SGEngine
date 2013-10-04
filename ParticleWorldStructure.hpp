// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Particleworldstructure.pas' rev: 11.00

#ifndef ParticleworldstructureHPP
#define ParticleworldstructureHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Mapstructure.hpp>	// Pascal unit
#include <Physicscontacts.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Physicsarifm.hpp>	// Pascal unit
#include <Particleforcegen.hpp>	// Pascal unit
#include <Physicsparticles.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Particleworldstructure
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<Particleforcegen::TGravityForceGen* >  ParticleWorldStructure__2;

typedef DynamicArray<Particleforcegen::TDragForceGen* >  ParticleWorldStructure__3;

typedef DynamicArray<Particleforcegen::TSpringForceGen* >  ParticleWorldStructure__4;

typedef DynamicArray<Particleforcegen::TAnchoredSpringForceGen* >  ParticleWorldStructure__5;

typedef DynamicArray<Particleforcegen::TBungeeSpringForceGen* >  ParticleWorldStructure__6;

typedef DynamicArray<Particleforcegen::TFloatingBodyForceGen* >  ParticleWorldStructure__7;

typedef DynamicArray<Particleforcegen::TSoftBodyForceGen* >  ParticleWorldStructure__8;

struct ParticleWorldStructure__1
{
	
public:
	DynamicArray<Particleforcegen::TGravityForceGen* >  Gravity;
	DynamicArray<Particleforcegen::TDragForceGen* >  Drag;
	DynamicArray<Particleforcegen::TSpringForceGen* >  Spring;
	DynamicArray<Particleforcegen::TAnchoredSpringForceGen* >  AnchoredSpring;
	DynamicArray<Particleforcegen::TBungeeSpringForceGen* >  Bungee;
	DynamicArray<Particleforcegen::TFloatingBodyForceGen* >  FloatingBody;
	DynamicArray<Particleforcegen::TSoftBodyForceGen* >  SoftBody;
} ;

struct ParticleWorldStructure__9
{
	
public:
	Physicscontacts::T2PContactGenerator* ParticleAndParticle;
	Physicscontacts::TPPlaneContactGenerator* ParticleAndPlane;
} ;

struct TGenerators
{
	
public:
	ParticleWorldStructure__1 Force;
	ParticleWorldStructure__9 Contact;
} ;

class DELPHICLASS TSoftBody;
class PASCALIMPLEMENTATION TSoftBody : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	DynamicArray<Physicsparticles::TParticle* >  Particles;
	double ParticleRadius;
	Word PlayerNumber;
	unsigned ParticleCount;
	Physicsarifm::TVector3 HeadPosition;
	__fastcall TSoftBody(const Physicsarifm::TVector3 &AHeadPosition, const unsigned ParticleCount, const double ParticleRadius, const Word PlayerNumber);
	__fastcall virtual ~TSoftBody(void);
	void __fastcall UpdateForce(const double DeltaTime);
};


typedef DynamicArray<TSoftBody* >  TBlobs;

class DELPHICLASS TParticleWorldStruc;
class PASCALIMPLEMENTATION TParticleWorldStruc : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	unsigned ContactCountLimit;
	Particleforcegen::TParticleAndForceGenRegistry* Registrations;
	Physicscontacts::TContactHandler2P* ContactHandler;
	DynamicArray<Physicscontacts::TContact2P* >  Contacts2P;
	DynamicArray<TSoftBody* >  Bodies;
	DynamicArray<Physicsparticles::TParticle* >  Particles;
	TGenerators Generators;
	__fastcall TParticleWorldStruc(const Byte MaxContacts, const Physicsparticles::TParticles AParticles, const Byte MaxIterations);
	__fastcall virtual ~TParticleWorldStruc(void);
	void __fastcall ClearAllForces(void);
	void __fastcall AddParticle(const Physicsparticles::TParticle* AParticle, const bool ConnectWithForceGens = true);
	void __fastcall DrawParticles(void);
	void __fastcall IntegrateWorld(const double DeltaTime);
	void __fastcall UpdateForces(const double DeltaTime);
	unsigned __fastcall GenerateContacts2P(void);
	void __fastcall Simulate(const double DeltaTime, const Byte FullSimCyclesPerFrame, const Mapstructure::TSector &WorldSector);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Particleworldstructure */
using namespace Particleworldstructure;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Particleworldstructure
