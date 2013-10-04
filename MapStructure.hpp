// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Mapstructure.pas' rev: 11.00

#ifndef MapstructureHPP
#define MapstructureHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Dglopengl.hpp>	// Pascal unit
#include <Physicsarifm.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mapstructure
{
//-- type declarations -------------------------------------------------------
struct TMapVertex
{
	
public:
	float X;
	float Y;
	float Z;
} ;

struct TTextureCoord
{
	
public:
	float X;
	float Y;
} ;

struct TTriangleVertex
{
	
public:
	TMapVertex Vertex;
	TTextureCoord TextureCoord;
} ;

typedef DynamicArray<TMapVertex >  MapStructure__1;

typedef DynamicArray<tagRGBTRIPLE >  MapStructure__2;

typedef DynamicArray<TMapVertex >  MapStructure__3;

typedef DynamicArray<TTextureCoord >  MapStructure__4;

typedef DynamicArray<unsigned >  MapStructure__5;

struct TSector
{
	
public:
	int NumTriangles;
	DynamicArray<TMapVertex >  Vertexs;
	DynamicArray<tagRGBTRIPLE >  Colors;
	DynamicArray<TMapVertex >  Normals;
	DynamicArray<TTextureCoord >  TextureCoords;
	DynamicArray<unsigned >  Texturez;
} ;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE tagRGBTRIPLE __fastcall SetColor(const Byte Red, const Byte Green, const Byte Blue);

}	/* namespace Mapstructure */
using namespace Mapstructure;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Mapstructure
