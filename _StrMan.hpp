// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) '_strman.pas' rev: 11.00

#ifndef _strmanHPP
#define _strmanHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace _strman
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Byte LowerCase[256];
extern PACKAGE Byte UpperCase[256];
extern PACKAGE Byte LowerCaseEng[256];
extern PACKAGE Byte UpperCaseEng[256];
extern PACKAGE AnsiString __fastcall CharReplicate(char Character, Byte Count);
extern PACKAGE AnsiString __fastcall StringReplicate(AnsiString Source, Byte Count);
extern PACKAGE Byte __fastcall CharPos(char CharToFind, AnsiString Source, Byte Offs);
extern PACKAGE Byte __fastcall StringPos(AnsiString StringToFind, AnsiString Source, Byte Offs);
extern PACKAGE AnsiString __fastcall StringJustifyRight(AnsiString Source, Byte Width, char JustifyChar);
extern PACKAGE AnsiString __fastcall StringJustifyLeft(AnsiString Source, Byte Width, char JustifyChar);
extern PACKAGE AnsiString __fastcall StringJustifyCenter(AnsiString Source, Byte Width, char JustifyChar);
extern PACKAGE AnsiString __fastcall StringJustifyWrap(AnsiString Source, Byte Width, AnsiString WordDelimiters, char JustifyChar);
extern PACKAGE AnsiString __fastcall StringTrimRight(AnsiString Source, AnsiString Garbage);
extern PACKAGE AnsiString __fastcall StringTrimLeft(AnsiString Source, AnsiString Garbage);
extern PACKAGE AnsiString __fastcall StringTrimAll(AnsiString Source, AnsiString Garbage);
extern PACKAGE AnsiString __fastcall StringReverse(AnsiString Source);
extern PACKAGE AnsiString __fastcall StringFromData(void * Source, Byte Count);
extern PACKAGE AnsiString __fastcall StringFromNul(void * Source);
extern PACKAGE AnsiString __fastcall StringCase(AnsiString Source, void * RecodeTable);
extern PACKAGE AnsiString __fastcall StringExtract(AnsiString Source, Byte Offs, Byte Count);
extern PACKAGE AnsiString __fastcall StringRemove(AnsiString Source, Byte Offs, Byte Count);
extern PACKAGE AnsiString __fastcall StringInsert(AnsiString SubString, AnsiString Source, Byte Offs);
extern PACKAGE Byte __fastcall StringWordCount(AnsiString Source, AnsiString WordDelimiters);
extern PACKAGE AnsiString __fastcall StringWordGet(AnsiString Source, AnsiString WordDelimiters, Byte Num);
extern PACKAGE Byte __fastcall StringWordPos(AnsiString Source, AnsiString WordDelimiters, Byte Num);
extern PACKAGE bool __fastcall StringMatching(AnsiString InString, AnsiString Pattern);

}	/* namespace _strman */
using namespace _strman;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// _strman
