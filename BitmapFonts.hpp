// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Bitmapfonts.pas' rev: 11.00

#ifndef BitmapfontsHPP
#define BitmapfontsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Opengl.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Bitmapfonts
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE unsigned Base;
extern "C" void __stdcall glBindTexture(unsigned target, unsigned texture);
extern PACKAGE void __fastcall BuildFont(HDC DC);
extern PACKAGE void __fastcall DestroyFont(void);
extern PACKAGE void __fastcall OutText(AnsiString text);

}	/* namespace Bitmapfonts */
using namespace Bitmapfonts;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Bitmapfonts
