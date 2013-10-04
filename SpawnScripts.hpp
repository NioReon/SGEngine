// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Spawnscripts.pas' rev: 11.00

#ifndef SpawnscriptsHPP
#define SpawnscriptsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Physicsarifm.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Particleworldstructure.hpp>	// Pascal unit
#include <Physicsparticles.hpp>	// Pascal unit
#include <Particleforcegen.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Spawnscripts
{
//-- type declarations -------------------------------------------------------
struct tAction;
typedef tAction *pAction;

struct act_newparticle;
typedef act_newparticle *pAct_newparticle;

struct act_newspring;
typedef act_newspring *pAct_newspring;

struct act_Entry;
typedef act_Entry *pAct_Entry;

struct act_loop;
typedef act_loop *pAct_particleloop;

struct act_newparticle
{
	
public:
	double x;
	double y;
	double z;
	double velocityx;
	double velocityy;
	double velocityz;
	double ParticleMass;
	double radius;
	double damping;
	void *res;
} ;

struct act_newtemplate
{
	
public:
	AnsiString name;
	act_newparticle *act;
} ;

struct act_loop
{
	
public:
	int n;
	double x;
	double y;
	double z;
	double sx;
	double sy;
	double sz;
	double velocityx;
	double velocityy;
	double velocityz;
	double ParticleMass;
	double radius;
	double damping;
} ;

struct act_newspring
{
	
public:
	double k;
	double l;
	double forcelimit;
	void *res;
} ;

struct act_Entry
{
	
public:
	int i1;
	int i2;
	int iGen;
} ;

struct tAction
{
	
public:
	Word obj;
	void *params;
	tAction *next;
} ;

struct tTemplate
{
	
public:
	AnsiString name;
	tAction *p;
} ;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE pAction __fastcall LoadSSL(AnsiString name);
extern PACKAGE void __fastcall RunSSl(pAction act, Physicsparticles::TParticles &p, Particleworldstructure::TParticleWorldStruc* &WorldStruc);

}	/* namespace Spawnscripts */
using namespace Spawnscripts;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Spawnscripts
