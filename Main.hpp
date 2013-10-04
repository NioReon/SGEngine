// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Main.pas' rev: 11.00

#ifndef MainHPP
#define MainHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <_shader.hpp>	// Pascal unit
#include <Dglopengl.hpp>	// Pascal unit
#include <Mapstructure.hpp>	// Pascal unit
#include <Cameras.hpp>	// Pascal unit
#include <Physicsarifm.hpp>	// Pascal unit
#include <Fontsnew.hpp>	// Pascal unit
#include <Bitmapfonts.hpp>	// Pascal unit
#include <Textures.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Appevnts.hpp>	// Pascal unit
#include <Particleworldstructure.hpp>	// Pascal unit
#include <Spawnscripts.hpp>	// Pascal unit
#include <Particleforcegen.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Main
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<int >  Main__2;

class DELPHICLASS TShittyGameEngine;
class PASCALIMPLEMENTATION TShittyGameEngine : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TTimer* FPSTimer;
	Appevnts::TApplicationEvents* ShittyGameEngineEvents;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall FPSTimerTimer(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall ShittyGameEngineEventsIdle(System::TObject* Sender, bool &Done);
	void __fastcall FormKeyUp(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall FormKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	
public:
	Particleworldstructure::TParticleWorldStruc* PWorldStruc;
	bool UseShaders;
	DynamicArray<int >  Shaders;
	unsigned VVBO;
	unsigned NVBO;
	unsigned TCVBO;
	unsigned CVBO;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TShittyGameEngine(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TShittyGameEngine(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TShittyGameEngine(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TShittyGameEngine(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


typedef DynamicArray<unsigned >  TGraphics;

struct TFPSCounter
{
	
public:
	unsigned DemoStart;
	unsigned LastTime;
	unsigned FPSCount;
	unsigned ElapsedTime;
	unsigned FrameTime;
} ;

struct TFogSettings
{
	
public:
	double Density;
	double Colour[4];
	double FogStartDistance;
	double FogEndDistance;
} ;

typedef DynamicArray<Mapstructure::TSector >  Main__3;

//-- var, const, procedure ---------------------------------------------------
static const Extended PiOver180 = 1.745329E-02;
#define PLAYERHEIGHT  (7.500000E-01)
#define ModelZoom  (1.000000E-02)
#define MAX_CAM_ZOOM  (2.500000E+00)
#define MIN_CAM_ZOOM  (1.000000E-01)
#define ZOOM_SPEED  (5.000000E-02)
extern PACKAGE double MaxDT;
static const Shortint IterationsCount = 0xa;
extern PACKAGE Byte SpringColor[4];
extern PACKAGE Byte BungeeSpringColor[4];
extern PACKAGE Byte AnchoredSpringColor[4];
extern PACKAGE DynamicArray<unsigned >  MapGraphics;
extern PACKAGE DynamicArray<unsigned >  MonsterGraphics;
extern PACKAGE float MoveSpeed;
extern PACKAGE float MouseSpeed;
extern PACKAGE bool Paused;
extern PACKAGE bool ShowDolbagInfo;
extern PACKAGE bool Keys[256];
extern PACKAGE DynamicArray<Mapstructure::TSector >  WorldMap;
extern PACKAGE bool Blend;
extern PACKAGE float AmbientLight[4];
extern PACKAGE float DiffuseLight[4];
extern PACKAGE float SpecularLight[4];
extern PACKAGE float SpecularReflection[4];
extern PACKAGE float LightPosition[4];
extern PACKAGE TFPSCounter FPSCounter;
extern PACKAGE Cameras::TCamera* Camera;
extern PACKAGE TFogSettings FogParams;
extern PACKAGE HDC DC;
extern PACKAGE HGLRC HRC;
extern PACKAGE float Dt;
extern PACKAGE Word CurrentWeapon;
extern PACKAGE TShittyGameEngine* ShittyGameEngine;

}	/* namespace Main */
using namespace Main;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Main
