// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) '_shader.pas' rev: 11.00

#ifndef _shaderHPP
#define _shaderHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Dglopengl.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace _shader
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString __fastcall GetInfoLog(int s);
extern PACKAGE int __fastcall LoadShader(const AnsiString src, const unsigned stype);
extern PACKAGE int __fastcall LoadShaderFromFile(const AnsiString filename, const unsigned stype);
extern PACKAGE int __fastcall LoadProgram(System::TVarRec const * sources, const int sources_Size);
extern PACKAGE int __fastcall LoadProgramFromFiles(System::TVarRec const * filenames, const int filenames_Size);
extern PACKAGE int __fastcall LinkPrograms(int const * programs, const int programs_Size);

}	/* namespace _shader */
using namespace _shader;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// _shader
