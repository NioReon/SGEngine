// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Fontsnew.pas' rev: 11.00

#ifndef FontsnewHPP
#define FontsnewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Opengl.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Physicsarifm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Fontsnew
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TextGetSymbols(HDC DC);
extern PACKAGE void __fastcall TextCreate(HDC DC, bool Enable3D);
extern PACKAGE void __fastcall TextDraw(AnsiString Text, const Physicsarifm::TVector3 &pos, const Physicsarifm::TVector3 &scale, const Physicsarifm::TVector3 &rotation);

}	/* namespace Fontsnew */
using namespace Fontsnew;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Fontsnew
