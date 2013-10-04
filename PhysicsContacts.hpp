// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Physicscontacts.pas' rev: 11.00

#ifndef PhysicscontactsHPP
#define PhysicscontactsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Mapstructure.hpp>	// Pascal unit
#include <Physicsparticles.hpp>	// Pascal unit
#include <Physicsarifm.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Physicscontacts
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TContact2P;
class PASCALIMPLEMENTATION TContact2P : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Physicsparticles::TParticle* Particles[2];
	double BounceCoefficient;
	double FrictionCoefficient;
	Physicsarifm::TVector3 Normal;
	double Penetration;
	Physicsarifm::TVector3 DeltaPos[2];
	
private:
	double __fastcall CalculateVelocityDifference(const double DeltaTime);
	void __fastcall HandleVelocities(const double DeltaTime);
	void __fastcall HandleInterPenetration(void);
	void __fastcall ProcessContact(const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TContact2P(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TContact2P(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TContact2P* >  TContacts2P;

typedef TContacts2P *PContacts2P;

class DELPHICLASS TContactHandler2P;
class PASCALIMPLEMENTATION TContactHandler2P : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	unsigned WorkIterations;
	unsigned CompletedIterations;
	
public:
	__fastcall TContactHandler2P(unsigned Iterations);
	void __fastcall SetIterationsCount(const unsigned Iterations);
	void __fastcall RemoveContactByIndex(TContacts2P &Contacts, const int Index);
	void __fastcall HandleContacts(TContacts2P &Contacts, const double DeltaTime);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TContactHandler2P(void) { }
	#pragma option pop
	
};


class DELPHICLASS TContactGenerator2P;
class PASCALIMPLEMENTATION TContactGenerator2P : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Byte __fastcall AddContact(TContacts2P &AContacts, const Byte Limit = (Byte)(0x0));
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TContactGenerator2P(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TContactGenerator2P(void) { }
	#pragma option pop
	
};


class DELPHICLASS T2PContactGenerator;
class PASCALIMPLEMENTATION T2PContactGenerator : public TContactGenerator2P 
{
	typedef TContactGenerator2P inherited;
	
public:
	unsigned __fastcall AddContacts(TContacts2P &AContacts, const Physicsparticles::TParticles AParticles);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall T2PContactGenerator(void) : TContactGenerator2P() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~T2PContactGenerator(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPPlaneContactGenerator;
class PASCALIMPLEMENTATION TPPlaneContactGenerator : public TContactGenerator2P 
{
	typedef TContactGenerator2P inherited;
	
public:
	unsigned __fastcall AddContacts(TContacts2P &AContacts, const Physicsparticles::TParticles AParticles, const Mapstructure::TSector &WorldSector);
	unsigned __fastcall AddContactsNew(TContacts2P &AContacts, const Physicsparticles::TParticles AParticles, const Mapstructure::TSector &WorldSector);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TPPlaneContactGenerator(void) : TContactGenerator2P() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TPPlaneContactGenerator(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Extended EPS = 1.000000E-06;
static const Extended VELOCITY_EPS = 1.000000E-05;

}	/* namespace Physicscontacts */
using namespace Physicscontacts;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Physicscontacts
