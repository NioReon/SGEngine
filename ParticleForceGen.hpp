// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Particleforcegen.pas' rev: 11.00

#ifndef ParticleforcegenHPP
#define ParticleforcegenHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Dglopengl.hpp>	// Pascal unit
#include <Physicsparticles.hpp>	// Pascal unit
#include <Physicsarifm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Particleforcegen
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TParticleForceGenerator;
class PASCALIMPLEMENTATION TParticleForceGenerator : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void __fastcall UpdateForce(Physicsparticles::TParticle* &AParticle, const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TParticleForceGenerator(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TParticleForceGenerator(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGravityForceGen;
class PASCALIMPLEMENTATION TGravityForceGen : public TParticleForceGenerator 
{
	typedef TParticleForceGenerator inherited;
	
public:
	Physicsarifm::TVector3 Gravity;
	__fastcall TGravityForceGen(const Physicsarifm::TVector3 &Gravity);
	HIDESBASE void __fastcall UpdateForce(Physicsparticles::TParticle* &AParticle, const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TGravityForceGen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDragForceGen;
class PASCALIMPLEMENTATION TDragForceGen : public TParticleForceGenerator 
{
	typedef TParticleForceGenerator inherited;
	
protected:
	double DragCoefficient;
	double SquareDragCoefficient;
	
public:
	__fastcall TDragForceGen(const double DragCoefficient);
	HIDESBASE void __fastcall UpdateForce(Physicsparticles::TParticle* &AParticle, const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDragForceGen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSpringForceGen;
class PASCALIMPLEMENTATION TSpringForceGen : public TParticleForceGenerator 
{
	typedef TParticleForceGenerator inherited;
	
protected:
	double SpringInflexibilityCoefficient;
	double StartLength;
	double ForceLimit;
	
public:
	__fastcall TSpringForceGen(const double k, const double RestLength, const double AForceLimit);
	HIDESBASE bool __fastcall UpdateForce(Physicsparticles::TParticle* &FirstParticle, Physicsparticles::TParticle* &SecondParticle, const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSpringForceGen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAnchoredSpringForceGen;
class PASCALIMPLEMENTATION TAnchoredSpringForceGen : public TSpringForceGen 
{
	typedef TSpringForceGen inherited;
	
protected:
	Physicsarifm::TVector3 AAnchor;
	
public:
	__fastcall TAnchoredSpringForceGen(const Physicsarifm::TVector3 &Anchor, const double SpringInflexibilityCoeff, const double StartLength, const double AForceLimit);
	HIDESBASE bool __fastcall UpdateForce(Physicsparticles::TParticle* &AParticle, const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAnchoredSpringForceGen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBungeeSpringForceGen;
class PASCALIMPLEMENTATION TBungeeSpringForceGen : public TSpringForceGen 
{
	typedef TSpringForceGen inherited;
	
public:
	HIDESBASE bool __fastcall UpdateForce(Physicsparticles::TParticle* &FirstParticle, Physicsparticles::TParticle* &SecondParticle, const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TSpringForceGen.Create */ inline __fastcall TBungeeSpringForceGen(const double k, const double RestLength, const double AForceLimit) : TSpringForceGen(k, RestLength, AForceLimit) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBungeeSpringForceGen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFloatingBodyForceGen;
class PASCALIMPLEMENTATION TFloatingBodyForceGen : public TParticleForceGenerator 
{
	typedef TParticleForceGenerator inherited;
	
protected:
	double LiquidHeightAboveZero;
	double LiquidDensity;
	double BodyVolume;
	double MaxLiquidDepth;
	
public:
	__fastcall TFloatingBodyForceGen(const double LiquidHeight, const double BodyVolume, const double MaxLiquidDepth, const double LiquidDensity);
	HIDESBASE void __fastcall UpdateForce(Physicsparticles::TParticle* &AParticle, const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TFloatingBodyForceGen(void) { }
	#pragma option pop
	
};


struct TEntry
{
	
public:
	Physicsparticles::TParticle* AParticle;
	TParticleForceGenerator* AFG;
} ;

struct TPullForces
{
	
public:
	double PullBack;
	double DragTo;
} ;

struct TRestDistances
{
	
public:
	double Min;
	double Max;
} ;

class DELPHICLASS TSoftBodyForceGen;
class PASCALIMPLEMENTATION TSoftBodyForceGen : public TParticleForceGenerator 
{
	typedef TParticleForceGenerator inherited;
	
public:
	DynamicArray<Physicsparticles::TParticle* >  Particles;
	TPullForces PullForces;
	TRestDistances RestDistances;
	double IfJoinedForce;
	unsigned JointCountBeforeMaxForce;
	double MaxConnectionDistance;
	__fastcall TSoftBodyForceGen(const Physicsparticles::TParticles AParticles, const TPullForces &APullForces, const TRestDistances &ARestDistances, const double AIfJoinedForce, const unsigned AJointCountBeforeMaxForce, const double AMaxConnectionDistance);
	HIDESBASE void __fastcall UpdateForce(Physicsparticles::TParticle* &AParticle, const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSoftBodyForceGen(void) { }
	#pragma option pop
	
};


struct ParticleForceGen__01
{
	
public:
	Physicsparticles::TParticle* AParticle;
	TGravityForceGen* AFG;
} ;

typedef DynamicArray<ParticleForceGen__01 >  ParticleForceGen__11;

struct ParticleForceGen__21
{
	
public:
	Physicsparticles::TParticle* AParticle;
	TDragForceGen* AFG;
} ;

typedef DynamicArray<ParticleForceGen__21 >  ParticleForceGen__31;

struct ParticleForceGen__41
{
	
public:
	Physicsparticles::TParticle* FirstParticle;
	Physicsparticles::TParticle* SecondParticle;
	TSpringForceGen* AFG;
} ;

typedef DynamicArray<ParticleForceGen__41 >  ParticleForceGen__51;

struct ParticleForceGen__61
{
	
public:
	Physicsparticles::TParticle* AParticle;
	TAnchoredSpringForceGen* AFG;
} ;

typedef DynamicArray<ParticleForceGen__61 >  ParticleForceGen__71;

struct ParticleForceGen__81
{
	
public:
	Physicsparticles::TParticle* FirstParticle;
	Physicsparticles::TParticle* SecondParticle;
	TBungeeSpringForceGen* AFG;
} ;

typedef DynamicArray<ParticleForceGen__81 >  ParticleForceGen__91;

struct ParticleForceGen__02
{
	
public:
	Physicsparticles::TParticle* AParticle;
	TFloatingBodyForceGen* AFG;
} ;

typedef DynamicArray<ParticleForceGen__02 >  ParticleForceGen__12;

struct ParticleForceGen__22
{
	
public:
	Physicsparticles::TParticle* AParticle;
	TSoftBodyForceGen* AFG;
} ;

typedef DynamicArray<ParticleForceGen__22 >  ParticleForceGen__32;

class DELPHICLASS TParticleAndForceGenRegistry;
class PASCALIMPLEMENTATION TParticleAndForceGenRegistry : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	DynamicArray<ParticleForceGen__01 >  EntriesGravity;
	DynamicArray<ParticleForceGen__21 >  EntriesDrag;
	DynamicArray<ParticleForceGen__41 >  EntriesSpring;
	DynamicArray<ParticleForceGen__61 >  EntriesAnchoredSpring;
	DynamicArray<ParticleForceGen__81 >  EntriesBungeeSpring;
	DynamicArray<ParticleForceGen__02 >  EntriesFloatingBody;
	DynamicArray<ParticleForceGen__22 >  EntriesSoftBody;
	
public:
	__fastcall TParticleAndForceGenRegistry(void);
	__fastcall virtual ~TParticleAndForceGenRegistry(void);
	void __fastcall DrawColouredVectorAtPos(const Physicsarifm::TVector3 &AStart, const Physicsarifm::TVector3 &Vector, const Byte R, const Byte G, const Byte B);
	void __fastcall DrawAllSprings(Byte const * SpringColor, Byte const * BungeeColor, Byte const * AnchoredSpringColor);
	void __fastcall AddEntry(const Physicsparticles::TParticle* AParticle, const TGravityForceGen* AForceGen)/* overload */;
	void __fastcall AddEntry(const Physicsparticles::TParticle* AParticle, const TDragForceGen* AForceGen)/* overload */;
	void __fastcall AddEntry(const Physicsparticles::TParticle* FirstParticle, const Physicsparticles::TParticle* SecondParticle, const TSpringForceGen* AForceGen)/* overload */;
	void __fastcall AddEntry(const Physicsparticles::TParticle* AParticle, const TAnchoredSpringForceGen* AForceGen)/* overload */;
	void __fastcall AddEntry(const Physicsparticles::TParticle* FirstParticle, const Physicsparticles::TParticle* SecondParticle, const TBungeeSpringForceGen* AForceGen)/* overload */;
	void __fastcall AddEntry(const Physicsparticles::TParticle* AParticle, const TFloatingBodyForceGen* AForceGen)/* overload */;
	void __fastcall AddEntry(const Physicsparticles::TParticle* AParticle, const TSoftBodyForceGen* AForceGen)/* overload */;
	bool __fastcall RemoveEntry(const Physicsparticles::TParticle* AParticle, const TGravityForceGen* AForceGen)/* overload */;
	bool __fastcall RemoveEntry(const Physicsparticles::TParticle* AParticle, const TDragForceGen* AForceGen)/* overload */;
	bool __fastcall RemoveEntry(const Physicsparticles::TParticle* FirstParticle, const Physicsparticles::TParticle* SecondParticle, const TSpringForceGen* AForceGen)/* overload */;
	bool __fastcall RemoveEntry(const Physicsparticles::TParticle* AParticle, const TAnchoredSpringForceGen* AForceGen)/* overload */;
	bool __fastcall RemoveEntry(const Physicsparticles::TParticle* FirstParticle, const Physicsparticles::TParticle* SecondParticle, const TBungeeSpringForceGen* AForceGen)/* overload */;
	bool __fastcall RemoveEntry(const Physicsparticles::TParticle* AParticle, const TFloatingBodyForceGen* AForceGen)/* overload */;
	bool __fastcall RemoveEntry(const Physicsparticles::TParticle* AParticle, const TSoftBodyForceGen* AForceGen)/* overload */;
	void __fastcall ClearEntries(void);
	void __fastcall UpdateForces(const double DeltaTime);
	void __fastcall IntegrateEntireParticles(const double DeltaTime);
	void __fastcall ClearForceAccums(void);
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint GRAVITY_FORCE_GEN = 0x0;
static const Shortint DRAG_FORCE_GEN = 0x1;
static const Shortint SPRING_FORCE_GEN = 0x2;
static const Shortint ANCHORED_SPRING_FORCE_GEN = 0x4;
static const Shortint BUNGEE_SPRING_FORCE_GEN = 0x8;
static const Shortint FLOATING_BODY_FORCE_GEN = 0x10;
static const Shortint FAKE_SRPING_FORCE_GEN = 0x20;
static const Shortint SOFT_BODY_FORCE_GEN = 0x40;

}	/* namespace Particleforcegen */
using namespace Particleforcegen;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Particleforcegen
