// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Dglopengl.pas' rev: 11.00

#ifndef DglopenglHPP
#define DglopenglHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dglopengl
{
//-- type declarations -------------------------------------------------------
typedef void * *PPointer;

typedef unsigned TGLenum;

typedef Byte TGLboolean;

typedef unsigned TGLbitfield;

typedef Shortint TGLbyte;

typedef short TGLshort;

typedef int TGLint;

typedef int TGLsizei;

typedef Byte TGLubyte;

typedef Word TGLushort;

typedef unsigned TGLuint;

typedef float TGLfloat;

typedef float TGLclampf;

typedef double TGLdouble;

typedef double TGLclampd;

typedef void *TGLvoid;

typedef __int64 TGLint64;

typedef unsigned GLenum;

typedef Byte GLboolean;

typedef unsigned GLbitfield;

typedef Shortint GLbyte;

typedef short GLshort;

typedef int GLint;

typedef int GLsizei;

typedef Byte GLubyte;

typedef Word GLushort;

typedef unsigned GLuint;

typedef float GLfloat;

typedef float GLclampf;

typedef double GLdouble;

typedef double GLclampd;

typedef void *GLvoid;

typedef __int64 GLint64;

typedef Byte *PGLBoolean;

typedef Shortint *PGLByte;

typedef short *PGLShort;

typedef int *PGLInt;

typedef int *PGLSizei;

typedef Byte *PGLubyte;

typedef Word *PGLushort;

typedef unsigned *PGLuint;

typedef float *PGLclampf;

typedef float *PGLfloat;

typedef double *PGLdouble;

typedef double *PGLclampd;

typedef unsigned *PGLenum;

typedef void *PGLvoid;

typedef __int64 *PGLint64;

typedef Word TGLhalfNV;

typedef Word *PGLhalfNV;

typedef int *PGLHandleARB;

typedef int GLHandleARB;

typedef char * *PPGLCharARB;

typedef char *PGLCharARB;

typedef char GLCharARB;

typedef int GLHandle;

typedef char * *PPGLChar;

typedef int TGLVectori4[4];

typedef float TGLVectorf4[4];

typedef double TGLVectord3[3];

typedef double TGLVectord4[4];

typedef void *TGLVectorp4[4];

typedef float TGLVectorf3[3];

typedef float TGLVector3f[3];

typedef float TGLArrayf4[4];

typedef float TGLArrayf3[3];

typedef double TGLArrayd3[3];

typedef int TGLArrayi4[4];

typedef void *TGLArrayp4[4];

typedef float TGLMatrixf4[4][4];

typedef double TGLMatrixd4[4][4];

typedef int TGlMatrixi4[4][4];

typedef double TVector3d[3];

typedef int TVector4i[4];

typedef float TVector4f[4];

typedef void *TVector4p[4];

typedef float TMatrix4f[4][4];

typedef double TMatrix4d[4][4];

typedef unsigned HPBUFFERARB;

typedef unsigned HPBUFFEREXT;

struct TGLUNurbs
{
	
} ;

struct TGLUQuadric
{
	
} ;

struct TGLUTesselator
{
	
} ;

typedef TGLUNurbs *PGLUNurbs;

typedef TGLUQuadric *PGLUQuadric;

typedef TGLUTesselator *PGLUTesselator;

typedef TGLUNurbs  TGLUNurbsObj;

typedef TGLUQuadric  TGLUQuadricObj;

typedef TGLUTesselator  TGLUTesselatorObj;

typedef TGLUTesselator  TGLUTriangulatorObj;

typedef TGLUNurbs *PGLUNurbsObj;

typedef TGLUQuadric *PGLUQuadricObj;

typedef TGLUTesselator *PGLUTesselatorObj;

typedef TGLUTesselator *PGLUTriangulatorObj;

typedef void __stdcall (*TGLUQuadricErrorProc)(unsigned errorCode);

typedef void __stdcall (*TGLUTessBeginProc)(unsigned AType);

typedef void __stdcall (*TGLUTessEdgeFlagProc)(Byte Flag);

typedef void __stdcall (*TGLUTessVertexProc)(void * VertexData);

typedef void __stdcall (*TGLUTessEndProc)(void);

typedef void __stdcall (*TGLUTessErrorProc)(unsigned ErrNo);

typedef void __stdcall (*TGLUTessCombineProc)(double * Coords, void * * VertexData, float * Weight, PPointer OutData);

typedef void __stdcall (*TGLUTessBeginDataProc)(unsigned AType, void * UserData);

typedef void __stdcall (*TGLUTessEdgeFlagDataProc)(Byte Flag, void * UserData);

typedef void __stdcall (*TGLUTessVertexDataProc)(void * VertexData, void * UserData);

typedef void __stdcall (*TGLUTessEndDataProc)(void * UserData);

typedef void __stdcall (*TGLUTessErrorDataProc)(unsigned ErrNo, void * UserData);

typedef void __stdcall (*TGLUTessCombineDataProc)(double * Coords, void * * VertexData, float * Weight, PPointer OutData, void * UserData);

typedef void __stdcall (*TGLUNurbsErrorProc)(unsigned ErrorCode);

typedef void __stdcall (*TglAccum)(unsigned op, float value);

typedef void __stdcall (*TglAlphaFunc)(unsigned func, float ref);

typedef Byte __stdcall (*TglAreTexturesResident)(int n, const PGLuint textures, PGLBoolean residences);

typedef void __stdcall (*TglArrayElement)(int i);

typedef void __stdcall (*TglBegin)(unsigned mode);

typedef void __stdcall (*TglBindTexture)(unsigned target, unsigned texture);

typedef void __stdcall (*TglBitmap)(int width, int height, float xorig, float yorig, float xmove, float ymove, const PGLubyte bitmap);

typedef void __stdcall (*TglBlendFunc)(unsigned sfactor, unsigned dfactor);

typedef void __stdcall (*TglCallList)(unsigned list);

typedef void __stdcall (*TglCallLists)(int n, unsigned _type, const void * lists);

typedef void __stdcall (*TglClear)(unsigned mask);

typedef void __stdcall (*TglClearAccum)(float red, float green, float blue, float alpha);

typedef void __stdcall (*TglClearColor)(float red, float green, float blue, float alpha);

typedef void __stdcall (*TglClearDepth)(double depth);

typedef void __stdcall (*TglClearIndex)(float c);

typedef void __stdcall (*TglClearStencil)(int s);

typedef void __stdcall (*TglClipPlane)(unsigned plane, const PGLdouble equation);

typedef void __stdcall (*TglColor3b)(Shortint red, Shortint green, Shortint blue);

typedef void __stdcall (*TglColor3bv)(const PGLByte v);

typedef void __stdcall (*TglColor3d)(double red, double green, double blue);

typedef void __stdcall (*TglColor3dv)(const PGLdouble v);

typedef void __stdcall (*TglColor3f)(float red, float green, float blue);

typedef void __stdcall (*TglColor3fv)(const PGLfloat v);

typedef void __stdcall (*TglColor3i)(int red, int green, int blue);

typedef void __stdcall (*TglColor3iv)(const PGLInt v);

typedef void __stdcall (*TglColor3s)(short red, short green, short blue);

typedef void __stdcall (*TglColor3sv)(const PGLShort v);

typedef void __stdcall (*TglColor3ub)(Byte red, Byte green, Byte blue);

typedef void __stdcall (*TglColor3ubv)(const PGLubyte v);

typedef void __stdcall (*TglColor3ui)(unsigned red, unsigned green, unsigned blue);

typedef void __stdcall (*TglColor3uiv)(const PGLuint v);

typedef void __stdcall (*TglColor3us)(Word red, Word green, Word blue);

typedef void __stdcall (*TglColor3usv)(const PGLushort v);

typedef void __stdcall (*TglColor4b)(Shortint red, Shortint green, Shortint blue, Shortint alpha);

typedef void __stdcall (*TglColor4bv)(const PGLByte v);

typedef void __stdcall (*TglColor4d)(double red, double green, double blue, double alpha);

typedef void __stdcall (*TglColor4dv)(const PGLdouble v);

typedef void __stdcall (*TglColor4f)(float red, float green, float blue, float alpha);

typedef void __stdcall (*TglColor4fv)(const PGLfloat v);

typedef void __stdcall (*TglColor4i)(int red, int green, int blue, int alpha);

typedef void __stdcall (*TglColor4iv)(const PGLInt v);

typedef void __stdcall (*TglColor4s)(short red, short green, short blue, short alpha);

typedef void __stdcall (*TglColor4sv)(const PGLShort v);

typedef void __stdcall (*TglColor4ub)(Byte red, Byte green, Byte blue, Byte alpha);

typedef void __stdcall (*TglColor4ubv)(const PGLubyte v);

typedef void __stdcall (*TglColor4ui)(unsigned red, unsigned green, unsigned blue, unsigned alpha);

typedef void __stdcall (*TglColor4uiv)(const PGLuint v);

typedef void __stdcall (*TglColor4us)(Word red, Word green, Word blue, Word alpha);

typedef void __stdcall (*TglColor4usv)(const PGLushort v);

typedef void __stdcall (*TglColorMask)(Byte red, Byte green, Byte blue, Byte alpha);

typedef void __stdcall (*TglColorMaterial)(unsigned face, unsigned mode);

typedef void __stdcall (*TglColorPointer)(int size, unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglCopyPixels)(int x, int y, int width, int height, unsigned _type);

typedef void __stdcall (*TglCopyTexImage1D)(unsigned target, int level, unsigned internalFormat, int x, int y, int width, int border);

typedef void __stdcall (*TglCopyTexImage2D)(unsigned target, int level, unsigned internalFormat, int x, int y, int width, int height, int border);

typedef void __stdcall (*TglCopyTexSubImage1D)(unsigned target, int level, int xoffset, int x, int y, int width);

typedef void __stdcall (*TglCopyTexSubImage2D)(unsigned target, int level, int xoffset, int yoffset, int x, int y, int width, int height);

typedef void __stdcall (*TglCullFace)(unsigned mode);

typedef void __stdcall (*TglDeleteLists)(unsigned list, int range);

typedef void __stdcall (*TglDeleteTextures)(int n, const PGLuint textures);

typedef void __stdcall (*TglDepthFunc)(unsigned func);

typedef void __stdcall (*TglDepthMask)(Byte flag);

typedef void __stdcall (*TglDepthRange)(double zNear, double zFar);

typedef void __stdcall (*TglDisable)(unsigned cap);

typedef void __stdcall (*TglDisableClientState)(unsigned _array);

typedef void __stdcall (*TglDrawArrays)(unsigned mode, int first, int count);

typedef void __stdcall (*TglDrawBuffer)(unsigned mode);

typedef void __stdcall (*TglDrawElements)(unsigned mode, int count, unsigned _type, const void * indices);

typedef void __stdcall (*TglDrawPixels)(int width, int height, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglEdgeFlag)(Byte flag);

typedef void __stdcall (*TglEdgeFlagPointer)(int stride, const void * _pointer);

typedef void __stdcall (*TglEdgeFlagv)(const PGLBoolean flag);

typedef void __stdcall (*TglEnable)(unsigned cap);

typedef void __stdcall (*TglEnableClientState)(unsigned _array);

typedef void __stdcall (*TglEnd)(void);

typedef void __stdcall (*TglEndList)(void);

typedef void __stdcall (*TglEvalCoord1d)(double u);

typedef void __stdcall (*TglEvalCoord1dv)(const PGLdouble u);

typedef void __stdcall (*TglEvalCoord1f)(float u);

typedef void __stdcall (*TglEvalCoord1fv)(const PGLfloat u);

typedef void __stdcall (*TglEvalCoord2d)(double u, double v);

typedef void __stdcall (*TglEvalCoord2dv)(const PGLdouble u);

typedef void __stdcall (*TglEvalCoord2f)(float u, float v);

typedef void __stdcall (*TglEvalCoord2fv)(const PGLfloat u);

typedef void __stdcall (*TglEvalMesh1)(unsigned mode, int i1, int i2);

typedef void __stdcall (*TglEvalMesh2)(unsigned mode, int i1, int i2, int j1, int j2);

typedef void __stdcall (*TglEvalPoint1)(int i);

typedef void __stdcall (*TglEvalPoint2)(int i, int j);

typedef void __stdcall (*TglFeedbackBuffer)(int size, unsigned _type, PGLfloat buffer);

typedef void __stdcall (*TglFinish)(void);

typedef void __stdcall (*TglFlush)(void);

typedef void __stdcall (*TglFogf)(unsigned pname, float param);

typedef void __stdcall (*TglFogfv)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglFogi)(unsigned pname, int param);

typedef void __stdcall (*TglFogiv)(unsigned pname, const PGLInt params);

typedef void __stdcall (*TglFrontFace)(unsigned mode);

typedef void __stdcall (*TglFrustum)(double left, double right, double bottom, double top, double zNear, double zFar);

typedef unsigned __stdcall (*TglGenLists)(int range);

typedef void __stdcall (*TglGenTextures)(int n, PGLuint textures);

typedef void __stdcall (*TglGetBooleanv)(unsigned pname, PGLBoolean params);

typedef void __stdcall (*TglGetClipPlane)(unsigned plane, PGLdouble equation);

typedef void __stdcall (*TglGetDoublev)(unsigned pname, PGLdouble params);

typedef unsigned __stdcall (*TglGetError)(void);

typedef void __stdcall (*TglGetFloatv)(unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetIntegerv)(unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetLightfv)(unsigned light, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetLightiv)(unsigned light, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetMapdv)(unsigned target, unsigned query, PGLdouble v);

typedef void __stdcall (*TglGetMapfv)(unsigned target, unsigned query, PGLfloat v);

typedef void __stdcall (*TglGetMapiv)(unsigned target, unsigned query, PGLInt v);

typedef void __stdcall (*TglGetMaterialfv)(unsigned face, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetMaterialiv)(unsigned face, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetPixelMapfv)(unsigned map, PGLfloat values);

typedef void __stdcall (*TglGetPixelMapuiv)(unsigned map, PGLuint values);

typedef void __stdcall (*TglGetPixelMapusv)(unsigned map, PGLushort values);

typedef void __stdcall (*TglGetPointerv)(unsigned pname, void * params);

typedef void __stdcall (*TglGetPolygonStipple)(PGLubyte mask);

typedef char * __stdcall (*TglGetString)(unsigned name);

typedef void __stdcall (*TglGetTexEnvfv)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetTexEnviv)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetTexGendv)(unsigned coord, unsigned pname, PGLdouble params);

typedef void __stdcall (*TglGetTexGenfv)(unsigned coord, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetTexGeniv)(unsigned coord, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetTexImage)(unsigned target, int level, unsigned format, unsigned _type, void * pixels);

typedef void __stdcall (*TglGetTexLevelParameterfv)(unsigned target, int level, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetTexLevelParameteriv)(unsigned target, int level, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetTexParameterfv)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetTexParameteriv)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglHint)(unsigned target, unsigned mode);

typedef void __stdcall (*TglIndexMask)(unsigned mask);

typedef void __stdcall (*TglIndexPointer)(unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglIndexd)(double c);

typedef void __stdcall (*TglIndexdv)(const PGLdouble c);

typedef void __stdcall (*TglIndexf)(float c);

typedef void __stdcall (*TglIndexfv)(const PGLfloat c);

typedef void __stdcall (*TglIndexi)(int c);

typedef void __stdcall (*TglIndexiv)(const PGLInt c);

typedef void __stdcall (*TglIndexs)(short c);

typedef void __stdcall (*TglIndexsv)(const PGLShort c);

typedef void __stdcall (*TglIndexub)(Byte c);

typedef void __stdcall (*TglIndexubv)(const PGLubyte c);

typedef void __stdcall (*TglInitNames)(void);

typedef void __stdcall (*TglInterleavedArrays)(unsigned format, int stride, const void * _pointer);

typedef Byte __stdcall (*TglIsEnabled)(unsigned cap);

typedef Byte __stdcall (*TglIsList)(unsigned list);

typedef Byte __stdcall (*TglIsTexture)(unsigned texture);

typedef void __stdcall (*TglLightModelf)(unsigned pname, float param);

typedef void __stdcall (*TglLightModelfv)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglLightModeli)(unsigned pname, int param);

typedef void __stdcall (*TglLightModeliv)(unsigned pname, const PGLInt params);

typedef void __stdcall (*TglLightf)(unsigned light, unsigned pname, float param);

typedef void __stdcall (*TglLightfv)(unsigned light, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglLighti)(unsigned light, unsigned pname, int param);

typedef void __stdcall (*TglLightiv)(unsigned light, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglLineStipple)(int factor, Word pattern);

typedef void __stdcall (*TglLineWidth)(float width);

typedef void __stdcall (*TglListBase)(unsigned base);

typedef void __stdcall (*TglLoadIdentity)(void);

typedef void __stdcall (*TglLoadMatrixd)(const PGLdouble m);

typedef void __stdcall (*TglLoadMatrixf)(const PGLfloat m);

typedef void __stdcall (*TglLoadName)(unsigned name);

typedef void __stdcall (*TglLogicOp)(unsigned opcode);

typedef void __stdcall (*TglMap1d)(unsigned target, double u1, double u2, int stride, int order, const PGLdouble points);

typedef void __stdcall (*TglMap1f)(unsigned target, float u1, float u2, int stride, int order, const PGLfloat points);

typedef void __stdcall (*TglMap2d)(unsigned target, double u1, double u2, int ustride, int uorder, double v1, double v2, int vstride, int vorder, const PGLdouble points);

typedef void __stdcall (*TglMap2f)(unsigned target, float u1, float u2, int ustride, int uorder, float v1, float v2, int vstride, int vorder, const PGLfloat points);

typedef void __stdcall (*TglMapGrid1d)(int un, double u1, double u2);

typedef void __stdcall (*TglMapGrid1f)(int un, float u1, float u2);

typedef void __stdcall (*TglMapGrid2d)(int un, double u1, double u2, int vn, double v1, double v2);

typedef void __stdcall (*TglMapGrid2f)(int un, float u1, float u2, int vn, float v1, float v2);

typedef void __stdcall (*TglMaterialf)(unsigned face, unsigned pname, float param);

typedef void __stdcall (*TglMaterialfv)(unsigned face, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglMateriali)(unsigned face, unsigned pname, int param);

typedef void __stdcall (*TglMaterialiv)(unsigned face, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglMatrixMode)(unsigned mode);

typedef void __stdcall (*TglMultMatrixd)(const PGLdouble m);

typedef void __stdcall (*TglMultMatrixf)(const PGLfloat m);

typedef void __stdcall (*TglNewList)(unsigned list, unsigned mode);

typedef void __stdcall (*TglNormal3b)(Shortint nx, Shortint ny, Shortint nz);

typedef void __stdcall (*TglNormal3bv)(const PGLByte v);

typedef void __stdcall (*TglNormal3d)(double nx, double ny, double nz);

typedef void __stdcall (*TglNormal3dv)(const PGLdouble v);

typedef void __stdcall (*TglNormal3f)(float nx, float ny, float nz);

typedef void __stdcall (*TglNormal3fv)(const PGLfloat v);

typedef void __stdcall (*TglNormal3i)(int nx, int ny, int nz);

typedef void __stdcall (*TglNormal3iv)(const PGLInt v);

typedef void __stdcall (*TglNormal3s)(short nx, short ny, short nz);

typedef void __stdcall (*TglNormal3sv)(const PGLShort v);

typedef void __stdcall (*TglNormalPointer)(unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglOrtho)(double left, double right, double bottom, double top, double zNear, double zFar);

typedef void __stdcall (*TglPassThrough)(float token);

typedef void __stdcall (*TglPixelMapfv)(unsigned map, int mapsize, const PGLfloat values);

typedef void __stdcall (*TglPixelMapuiv)(unsigned map, int mapsize, const PGLuint values);

typedef void __stdcall (*TglPixelMapusv)(unsigned map, int mapsize, const PGLushort values);

typedef void __stdcall (*TglPixelStoref)(unsigned pname, float param);

typedef void __stdcall (*TglPixelStorei)(unsigned pname, int param);

typedef void __stdcall (*TglPixelTransferf)(unsigned pname, float param);

typedef void __stdcall (*TglPixelTransferi)(unsigned pname, int param);

typedef void __stdcall (*TglPixelZoom)(float xfactor, float yfactor);

typedef void __stdcall (*TglPointSize)(float size);

typedef void __stdcall (*TglPolygonMode)(unsigned face, unsigned mode);

typedef void __stdcall (*TglPolygonOffset)(float factor, float units);

typedef void __stdcall (*TglPolygonStipple)(const PGLubyte mask);

typedef void __stdcall (*TglPopAttrib)(void);

typedef void __stdcall (*TglPopClientAttrib)(void);

typedef void __stdcall (*TglPopMatrix)(void);

typedef void __stdcall (*TglPopName)(void);

typedef void __stdcall (*TglPrioritizeTextures)(int n, const PGLuint textures, const PGLclampf priorities);

typedef void __stdcall (*TglPushAttrib)(unsigned mask);

typedef void __stdcall (*TglPushClientAttrib)(unsigned mask);

typedef void __stdcall (*TglPushMatrix)(void);

typedef void __stdcall (*TglPushName)(unsigned name);

typedef void __stdcall (*TglRasterPos2d)(double x, double y);

typedef void __stdcall (*TglRasterPos2dv)(const PGLdouble v);

typedef void __stdcall (*TglRasterPos2f)(float x, float y);

typedef void __stdcall (*TglRasterPos2fv)(const PGLfloat v);

typedef void __stdcall (*TglRasterPos2i)(int x, int y);

typedef void __stdcall (*TglRasterPos2iv)(const PGLInt v);

typedef void __stdcall (*TglRasterPos2s)(short x, short y);

typedef void __stdcall (*TglRasterPos2sv)(const PGLShort v);

typedef void __stdcall (*TglRasterPos3d)(double x, double y, double z);

typedef void __stdcall (*TglRasterPos3dv)(const PGLdouble v);

typedef void __stdcall (*TglRasterPos3f)(float x, float y, float z);

typedef void __stdcall (*TglRasterPos3fv)(const PGLfloat v);

typedef void __stdcall (*TglRasterPos3i)(int x, int y, int z);

typedef void __stdcall (*TglRasterPos3iv)(const PGLInt v);

typedef void __stdcall (*TglRasterPos3s)(short x, short y, short z);

typedef void __stdcall (*TglRasterPos3sv)(const PGLShort v);

typedef void __stdcall (*TglRasterPos4d)(double x, double y, double z, double w);

typedef void __stdcall (*TglRasterPos4dv)(const PGLdouble v);

typedef void __stdcall (*TglRasterPos4f)(float x, float y, float z, float w);

typedef void __stdcall (*TglRasterPos4fv)(const PGLfloat v);

typedef void __stdcall (*TglRasterPos4i)(int x, int y, int z, int w);

typedef void __stdcall (*TglRasterPos4iv)(const PGLInt v);

typedef void __stdcall (*TglRasterPos4s)(short x, short y, short z, short w);

typedef void __stdcall (*TglRasterPos4sv)(const PGLShort v);

typedef void __stdcall (*TglReadBuffer)(unsigned mode);

typedef void __stdcall (*TglReadPixels)(int x, int y, int width, int height, unsigned format, unsigned _type, void * pixels);

typedef void __stdcall (*TglRectd)(double x1, double y1, double x2, double y2);

typedef void __stdcall (*TglRectdv)(const PGLdouble v1, const PGLdouble v2);

typedef void __stdcall (*TglRectf)(float x1, float y1, float x2, float y2);

typedef void __stdcall (*TglRectfv)(const PGLfloat v1, const PGLfloat v2);

typedef void __stdcall (*TglRecti)(int x1, int y1, int x2, int y2);

typedef void __stdcall (*TglRectiv)(const PGLInt v1, const PGLInt v2);

typedef void __stdcall (*TglRects)(short x1, short y1, short x2, short y2);

typedef void __stdcall (*TglRectsv)(const PGLShort v1, const PGLShort v2);

typedef int __stdcall (*TglRenderMode)(unsigned mode);

typedef void __stdcall (*TglRotated)(double angle, double x, double y, double z);

typedef void __stdcall (*TglRotatef)(float angle, float x, float y, float z);

typedef void __stdcall (*TglScaled)(double x, double y, double z);

typedef void __stdcall (*TglScalef)(float x, float y, float z);

typedef void __stdcall (*TglScissor)(int x, int y, int width, int height);

typedef void __stdcall (*TglSelectBuffer)(int size, PGLuint buffer);

typedef void __stdcall (*TglShadeModel)(unsigned mode);

typedef void __stdcall (*TglStencilFunc)(unsigned func, int ref, unsigned mask);

typedef void __stdcall (*TglStencilMask)(unsigned mask);

typedef void __stdcall (*TglStencilOp)(unsigned fail, unsigned zfail, unsigned zpass);

typedef void __stdcall (*TglTexCoord1d)(double s);

typedef void __stdcall (*TglTexCoord1dv)(const PGLdouble v);

typedef void __stdcall (*TglTexCoord1f)(float s);

typedef void __stdcall (*TglTexCoord1fv)(const PGLfloat v);

typedef void __stdcall (*TglTexCoord1i)(int s);

typedef void __stdcall (*TglTexCoord1iv)(const PGLInt v);

typedef void __stdcall (*TglTexCoord1s)(short s);

typedef void __stdcall (*TglTexCoord1sv)(const PGLShort v);

typedef void __stdcall (*TglTexCoord2d)(double s, double t);

typedef void __stdcall (*TglTexCoord2dv)(const PGLdouble v);

typedef void __stdcall (*TglTexCoord2f)(float s, float t);

typedef void __stdcall (*TglTexCoord2fv)(const PGLfloat v);

typedef void __stdcall (*TglTexCoord2i)(int s, int t);

typedef void __stdcall (*TglTexCoord2iv)(const PGLInt v);

typedef void __stdcall (*TglTexCoord2s)(short s, short t);

typedef void __stdcall (*TglTexCoord2sv)(const PGLShort v);

typedef void __stdcall (*TglTexCoord3d)(double s, double t, double r);

typedef void __stdcall (*TglTexCoord3dv)(const PGLdouble v);

typedef void __stdcall (*TglTexCoord3f)(float s, float t, float r);

typedef void __stdcall (*TglTexCoord3fv)(const PGLfloat v);

typedef void __stdcall (*TglTexCoord3i)(int s, int t, int r);

typedef void __stdcall (*TglTexCoord3iv)(const PGLInt v);

typedef void __stdcall (*TglTexCoord3s)(short s, short t, short r);

typedef void __stdcall (*TglTexCoord3sv)(const PGLShort v);

typedef void __stdcall (*TglTexCoord4d)(double s, double t, double r, double q);

typedef void __stdcall (*TglTexCoord4dv)(const PGLdouble v);

typedef void __stdcall (*TglTexCoord4f)(float s, float t, float r, float q);

typedef void __stdcall (*TglTexCoord4fv)(const PGLfloat v);

typedef void __stdcall (*TglTexCoord4i)(int s, int t, int r, int q);

typedef void __stdcall (*TglTexCoord4iv)(const PGLInt v);

typedef void __stdcall (*TglTexCoord4s)(short s, short t, short r, short q);

typedef void __stdcall (*TglTexCoord4sv)(const PGLShort v);

typedef void __stdcall (*TglTexCoordPointer)(int size, unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglTexEnvf)(unsigned target, unsigned pname, float param);

typedef void __stdcall (*TglTexEnvfv)(unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglTexEnvi)(unsigned target, unsigned pname, int param);

typedef void __stdcall (*TglTexEnviv)(unsigned target, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglTexGend)(unsigned coord, unsigned pname, double param);

typedef void __stdcall (*TglTexGendv)(unsigned coord, unsigned pname, const PGLdouble params);

typedef void __stdcall (*TglTexGenf)(unsigned coord, unsigned pname, float param);

typedef void __stdcall (*TglTexGenfv)(unsigned coord, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglTexGeni)(unsigned coord, unsigned pname, int param);

typedef void __stdcall (*TglTexGeniv)(unsigned coord, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglTexImage1D)(unsigned target, int level, int internalformat, int width, int border, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTexImage2D)(unsigned target, int level, int internalformat, int width, int height, int border, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTexParameterf)(unsigned target, unsigned pname, float param);

typedef void __stdcall (*TglTexParameterfv)(unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglTexParameteri)(unsigned target, unsigned pname, int param);

typedef void __stdcall (*TglTexParameteriv)(unsigned target, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglTexSubImage1D)(unsigned target, int level, int xoffset, int width, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTexSubImage2D)(unsigned target, int level, int xoffset, int yoffset, int width, int height, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTranslated)(double x, double y, double z);

typedef void __stdcall (*TglTranslatef)(float x, float y, float z);

typedef void __stdcall (*TglVertex2d)(double x, double y);

typedef void __stdcall (*TglVertex2dv)(const PGLdouble v);

typedef void __stdcall (*TglVertex2f)(float x, float y);

typedef void __stdcall (*TglVertex2fv)(const PGLfloat v);

typedef void __stdcall (*TglVertex2i)(int x, int y);

typedef void __stdcall (*TglVertex2iv)(const PGLInt v);

typedef void __stdcall (*TglVertex2s)(short x, short y);

typedef void __stdcall (*TglVertex2sv)(const PGLShort v);

typedef void __stdcall (*TglVertex3d)(double x, double y, double z);

typedef void __stdcall (*TglVertex3dv)(const PGLdouble v);

typedef void __stdcall (*TglVertex3f)(float x, float y, float z);

typedef void __stdcall (*TglVertex3fv)(const PGLfloat v);

typedef void __stdcall (*TglVertex3i)(int x, int y, int z);

typedef void __stdcall (*TglVertex3iv)(const PGLInt v);

typedef void __stdcall (*TglVertex3s)(short x, short y, short z);

typedef void __stdcall (*TglVertex3sv)(const PGLShort v);

typedef void __stdcall (*TglVertex4d)(double x, double y, double z, double w);

typedef void __stdcall (*TglVertex4dv)(const PGLdouble v);

typedef void __stdcall (*TglVertex4f)(float x, float y, float z, float w);

typedef void __stdcall (*TglVertex4fv)(const PGLfloat v);

typedef void __stdcall (*TglVertex4i)(int x, int y, int z, int w);

typedef void __stdcall (*TglVertex4iv)(const PGLInt v);

typedef void __stdcall (*TglVertex4s)(short x, short y, short z, short w);

typedef void __stdcall (*TglVertex4sv)(const PGLShort v);

typedef void __stdcall (*TglVertexPointer)(int size, unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglViewport)(int x, int y, int width, int height);

typedef void __stdcall (*TglBlendColor)(float red, float green, float blue, float alpha);

typedef void __stdcall (*TglBlendEquation)(unsigned mode);

typedef void __stdcall (*TglDrawRangeElements)(unsigned mode, unsigned start, unsigned _end, int count, unsigned _type, const void * indices);

typedef void __stdcall (*TglColorTable)(unsigned target, unsigned internalformat, int width, unsigned format, unsigned _type, const void * table);

typedef void __stdcall (*TglColorTableParameterfv)(unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglColorTableParameteriv)(unsigned target, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglCopyColorTable)(unsigned target, unsigned internalformat, int x, int y, int width);

typedef void __stdcall (*TglGetColorTable)(unsigned target, unsigned format, unsigned _type, void * table);

typedef void __stdcall (*TglGetColorTableParameterfv)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetColorTableParameteriv)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglColorSubTable)(unsigned target, int start, int count, unsigned format, unsigned _type, const void * data);

typedef void __stdcall (*TglCopyColorSubTable)(unsigned target, int start, int x, int y, int width);

typedef void __stdcall (*TglConvolutionFilter1D)(unsigned target, unsigned internalformat, int width, unsigned format, unsigned _type, const void * image);

typedef void __stdcall (*TglConvolutionFilter2D)(unsigned target, unsigned internalformat, int width, int height, unsigned format, unsigned _type, const void * image);

typedef void __stdcall (*TglConvolutionParameterf)(unsigned target, unsigned pname, float params);

typedef void __stdcall (*TglConvolutionParameterfv)(unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglConvolutionParameteri)(unsigned target, unsigned pname, int params);

typedef void __stdcall (*TglConvolutionParameteriv)(unsigned target, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglCopyConvolutionFilter1D)(unsigned target, unsigned internalformat, int x, int y, int width);

typedef void __stdcall (*TglCopyConvolutionFilter2D)(unsigned target, unsigned internalformat, int x, int y, int width, int height);

typedef void __stdcall (*TglGetConvolutionFilter)(unsigned target, unsigned format, unsigned _type, void * image);

typedef void __stdcall (*TglGetConvolutionParameterfv)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetConvolutionParameteriv)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetSeparableFilter)(unsigned target, unsigned format, unsigned _type, void * row, void * column, void * span);

typedef void __stdcall (*TglSeparableFilter2D)(unsigned target, unsigned internalformat, int width, int height, unsigned format, unsigned _type, const void * row, const void * column);

typedef void __stdcall (*TglGetHistogram)(unsigned target, Byte reset, unsigned format, unsigned _type, void * values);

typedef void __stdcall (*TglGetHistogramParameterfv)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetHistogramParameteriv)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetMinmax)(unsigned target, Byte reset, unsigned format, unsigned _type, void * values);

typedef void __stdcall (*TglGetMinmaxParameterfv)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetMinmaxParameteriv)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglHistogram)(unsigned target, int width, unsigned internalformat, Byte sink);

typedef void __stdcall (*TglMinmax)(unsigned target, unsigned internalformat, Byte sink);

typedef void __stdcall (*TglResetHistogram)(unsigned target);

typedef void __stdcall (*TglResetMinmax)(unsigned target);

typedef void __stdcall (*TglTexImage3D)(unsigned target, int level, int internalformat, int width, int height, int depth, int border, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTexSubImage3D)(unsigned target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglCopyTexSubImage3D)(unsigned target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);

typedef void __stdcall (*TglActiveTexture)(unsigned texture);

typedef void __stdcall (*TglClientActiveTexture)(unsigned texture);

typedef void __stdcall (*TglMultiTexCoord1d)(unsigned target, double s);

typedef void __stdcall (*TglMultiTexCoord1dv)(unsigned target, const PGLdouble v);

typedef void __stdcall (*TglMultiTexCoord1f)(unsigned target, float s);

typedef void __stdcall (*TglMultiTexCoord1fv)(unsigned target, const PGLfloat v);

typedef void __stdcall (*TglMultiTexCoord1i)(unsigned target, int s);

typedef void __stdcall (*TglMultiTexCoord1iv)(unsigned target, const PGLInt v);

typedef void __stdcall (*TglMultiTexCoord1s)(unsigned target, short s);

typedef void __stdcall (*TglMultiTexCoord1sv)(unsigned target, const PGLShort v);

typedef void __stdcall (*TglMultiTexCoord2d)(unsigned target, double s, double t);

typedef void __stdcall (*TglMultiTexCoord2dv)(unsigned target, const PGLdouble v);

typedef void __stdcall (*TglMultiTexCoord2f)(unsigned target, float s, float t);

typedef void __stdcall (*TglMultiTexCoord2fv)(unsigned target, const PGLfloat v);

typedef void __stdcall (*TglMultiTexCoord2i)(unsigned target, int s, int t);

typedef void __stdcall (*TglMultiTexCoord2iv)(unsigned target, const PGLInt v);

typedef void __stdcall (*TglMultiTexCoord2s)(unsigned target, short s, short t);

typedef void __stdcall (*TglMultiTexCoord2sv)(unsigned target, const PGLShort v);

typedef void __stdcall (*TglMultiTexCoord3d)(unsigned target, double s, double t, double r);

typedef void __stdcall (*TglMultiTexCoord3dv)(unsigned target, const PGLdouble v);

typedef void __stdcall (*TglMultiTexCoord3f)(unsigned target, float s, float t, float r);

typedef void __stdcall (*TglMultiTexCoord3fv)(unsigned target, const PGLfloat v);

typedef void __stdcall (*TglMultiTexCoord3i)(unsigned target, int s, int t, int r);

typedef void __stdcall (*TglMultiTexCoord3iv)(unsigned target, const PGLInt v);

typedef void __stdcall (*TglMultiTexCoord3s)(unsigned target, short s, short t, short r);

typedef void __stdcall (*TglMultiTexCoord3sv)(unsigned target, const PGLShort v);

typedef void __stdcall (*TglMultiTexCoord4d)(unsigned target, double s, double t, double r, double q);

typedef void __stdcall (*TglMultiTexCoord4dv)(unsigned target, const PGLdouble v);

typedef void __stdcall (*TglMultiTexCoord4f)(unsigned target, float s, float t, float r, float q);

typedef void __stdcall (*TglMultiTexCoord4fv)(unsigned target, const PGLfloat v);

typedef void __stdcall (*TglMultiTexCoord4i)(unsigned target, int s, int t, int r, int q);

typedef void __stdcall (*TglMultiTexCoord4iv)(unsigned target, const PGLInt v);

typedef void __stdcall (*TglMultiTexCoord4s)(unsigned target, short s, short t, short r, short q);

typedef void __stdcall (*TglMultiTexCoord4sv)(unsigned target, const PGLShort v);

typedef void __stdcall (*TglLoadTransposeMatrixf)(const PGLfloat m);

typedef void __stdcall (*TglLoadTransposeMatrixd)(const PGLdouble m);

typedef void __stdcall (*TglMultTransposeMatrixf)(const PGLfloat m);

typedef void __stdcall (*TglMultTransposeMatrixd)(const PGLdouble m);

typedef void __stdcall (*TglSampleCoverage)(float value, Byte invert);

typedef void __stdcall (*TglCompressedTexImage3D)(unsigned target, int level, unsigned internalformat, int width, int height, int depth, int border, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexImage2D)(unsigned target, int level, unsigned internalformat, int width, int height, int border, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexImage1D)(unsigned target, int level, unsigned internalformat, int width, int border, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexSubImage3D)(unsigned target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, unsigned format, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexSubImage2D)(unsigned target, int level, int xoffset, int yoffset, int width, int height, unsigned format, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexSubImage1D)(unsigned target, int level, int xoffset, int width, unsigned format, int imageSize, const void * data);

typedef void __stdcall (*TglGetCompressedTexImage)(unsigned target, int level, void * img);

typedef void __stdcall (*TglBlendFuncSeparate)(unsigned sfactorRGB, unsigned dfactorRGB, unsigned sfactorAlpha, unsigned dfactorAlpha);

typedef void __stdcall (*TglFogCoordf)(float coord);

typedef void __stdcall (*TglFogCoordfv)(const PGLfloat coord);

typedef void __stdcall (*TglFogCoordd)(double coord);

typedef void __stdcall (*TglFogCoorddv)(const PGLdouble coord);

typedef void __stdcall (*TglFogCoordPointer)(unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglMultiDrawArrays)(unsigned mode, PGLInt first, PGLSizei count, int primcount);

typedef void __stdcall (*TglMultiDrawElements)(unsigned mode, const PGLSizei count, unsigned _type, const void * indices, int primcount);

typedef void __stdcall (*TglPointParameterf)(unsigned pname, float param);

typedef void __stdcall (*TglPointParameterfv)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglPointParameteri)(unsigned pname, int param);

typedef void __stdcall (*TglPointParameteriv)(unsigned pname, const PGLInt params);

typedef void __stdcall (*TglSecondaryColor3b)(Shortint red, Shortint green, Shortint blue);

typedef void __stdcall (*TglSecondaryColor3bv)(const PGLByte v);

typedef void __stdcall (*TglSecondaryColor3d)(double red, double green, double blue);

typedef void __stdcall (*TglSecondaryColor3dv)(const PGLdouble v);

typedef void __stdcall (*TglSecondaryColor3f)(float red, float green, float blue);

typedef void __stdcall (*TglSecondaryColor3fv)(const PGLfloat v);

typedef void __stdcall (*TglSecondaryColor3i)(int red, int green, int blue);

typedef void __stdcall (*TglSecondaryColor3iv)(const PGLInt v);

typedef void __stdcall (*TglSecondaryColor3s)(short red, short green, short blue);

typedef void __stdcall (*TglSecondaryColor3sv)(const PGLShort v);

typedef void __stdcall (*TglSecondaryColor3ub)(Byte red, Byte green, Byte blue);

typedef void __stdcall (*TglSecondaryColor3ubv)(const PGLubyte v);

typedef void __stdcall (*TglSecondaryColor3ui)(unsigned red, unsigned green, unsigned blue);

typedef void __stdcall (*TglSecondaryColor3uiv)(const PGLuint v);

typedef void __stdcall (*TglSecondaryColor3us)(Word red, Word green, Word blue);

typedef void __stdcall (*TglSecondaryColor3usv)(const PGLushort v);

typedef void __stdcall (*TglSecondaryColorPointer)(int size, unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglWindowPos2d)(double x, double y);

typedef void __stdcall (*TglWindowPos2dv)(const PGLdouble v);

typedef void __stdcall (*TglWindowPos2f)(float x, float y);

typedef void __stdcall (*TglWindowPos2fv)(const PGLfloat v);

typedef void __stdcall (*TglWindowPos2i)(int x, int y);

typedef void __stdcall (*TglWindowPos2iv)(const PGLInt v);

typedef void __stdcall (*TglWindowPos2s)(short x, short y);

typedef void __stdcall (*TglWindowPos2sv)(const PGLShort v);

typedef void __stdcall (*TglWindowPos3d)(double x, double y, double z);

typedef void __stdcall (*TglWindowPos3dv)(const PGLdouble v);

typedef void __stdcall (*TglWindowPos3f)(float x, float y, float z);

typedef void __stdcall (*TglWindowPos3fv)(const PGLfloat v);

typedef void __stdcall (*TglWindowPos3i)(int x, int y, int z);

typedef void __stdcall (*TglWindowPos3iv)(const PGLInt v);

typedef void __stdcall (*TglWindowPos3s)(short x, short y, short z);

typedef void __stdcall (*TglWindowPos3sv)(const PGLShort v);

typedef void __stdcall (*TglGenQueries)(int n, PGLuint ids);

typedef void __stdcall (*TglDeleteQueries)(int n, const PGLuint ids);

typedef bool __stdcall (*TglIsQuery)(unsigned id);

typedef void __stdcall (*TglBeginQuery)(unsigned target, unsigned id);

typedef void __stdcall (*TglEndQuery)(unsigned target);

typedef void __stdcall (*TglGetQueryiv)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetQueryObjectiv)(unsigned id, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetQueryObjectuiv)(unsigned id, unsigned pname, PGLuint params);

typedef void __stdcall (*TglBindBuffer)(unsigned target, unsigned buffer);

typedef void __stdcall (*TglDeleteBuffers)(int n, const PGLuint buffers);

typedef void __stdcall (*TglGenBuffers)(int n, PGLuint buffers);

typedef Byte __stdcall (*TglIsBuffer)(unsigned buffer);

typedef void __stdcall (*TglBufferData)(unsigned target, int size, const void * data, unsigned usage);

typedef void __stdcall (*TglBufferSubData)(unsigned target, int offset, int size, const void * data);

typedef void __stdcall (*TglGetBufferSubData)(unsigned target, int offset, int size, void * data);

typedef void * __stdcall (*TglMapBuffer)(unsigned target, unsigned access);

typedef Byte __stdcall (*TglUnmapBuffer)(unsigned target);

typedef void __stdcall (*TglGetBufferParameteriv)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetBufferPointerv)(unsigned target, unsigned pname, void * params);

typedef void __stdcall (*TglBlendEquationSeparate)(unsigned modeRGB, unsigned modeAlpha);

typedef void __stdcall (*TglDrawBuffers)(int n, const PGLenum bufs);

typedef void __stdcall (*TglStencilOpSeparate)(unsigned face, unsigned sfail, unsigned dpfail, unsigned dppass);

typedef void __stdcall (*TglStencilFuncSeparate)(unsigned frontfunc, unsigned backfunc, int ref, unsigned mask);

typedef void __stdcall (*TglStencilMaskSeparate)(unsigned face, unsigned mask);

typedef void __stdcall (*TglAttachShader)(int programObj, int shaderObj);

typedef void __stdcall (*TglBindAttribLocation)(int programObj, unsigned index, char * name);

typedef void __stdcall (*TglCompileShader)(int shaderObj);

typedef int __stdcall (*TglCreateProgram)(void);

typedef int __stdcall (*TglCreateShader)(unsigned shaderType);

typedef void __stdcall (*TglDeleteProgram)(int programObj);

typedef void __stdcall (*TglDeleteShader)(int shaderObj);

typedef void __stdcall (*TglDetachShader)(int programObj, int shaderObj);

typedef void __stdcall (*TglDisableVertexAttribArray)(unsigned index);

typedef void __stdcall (*TglEnableVertexAttribArray)(unsigned index);

typedef void __stdcall (*TglGetActiveAttrib)(int programObj, unsigned index, int maxlength, int &length, unsigned &_type, char * name);

typedef void __stdcall (*TglGetActiveUniform)(int programObj, unsigned index, int maxLength, int &length, int &size, unsigned &_type, char * name);

typedef void __stdcall (*TglGetAttachedShaders)(int programObj, int MaxCount, int &Count, PGLuint shaders);

typedef int __stdcall (*TglGetAttribLocation)(int programObj, AnsiString char);

typedef void __stdcall (*TglGetProgramiv)(int programObj, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetProgramInfoLog)(int programObj, int maxLength, int &length, char * infoLog);

typedef void __stdcall (*TglGetShaderiv)(int shaderObj, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetShaderInfoLog)(int shaderObj, int maxLength, int &length, char * infoLog);

typedef void __stdcall (*TglGetShaderSource)(int shaderObj, int maxlength, int &length, char * source);

typedef int __stdcall (*TglGetUniformLocation)(int programObj, const char * char);

typedef void __stdcall (*TglGetUniformfv)(int programObj, int location, PGLfloat params);

typedef void __stdcall (*TglGetUniformiv)(int programObj, int location, PGLInt params);

typedef void __stdcall (*TglGetVertexAttribfv)(unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetVertexAttribiv)(unsigned index, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetVertexAttribPointerv)(unsigned index, unsigned pname, void * _pointer);

typedef Byte __stdcall (*TglIsProgram)(int programObj);

typedef Byte __stdcall (*TglIsShader)(int shaderObj);

typedef void __stdcall (*TglLinkProgram)(int programObj);

typedef void __stdcall (*TglShaderSource)(int shaderObj, int count, PPGLChar _string, PGLInt lengths);

typedef void __stdcall (*TglUseProgram)(int programObj);

typedef void __stdcall (*TglUniform1f)(int location, float v0);

typedef void __stdcall (*TglUniform2f)(int location, float v0, float v1);

typedef void __stdcall (*TglUniform3f)(int location, float v0, float v1, float v2);

typedef void __stdcall (*TglUniform4f)(int location, float v0, float v1, float v2, float v3);

typedef void __stdcall (*TglUniform1i)(int location, int v0);

typedef void __stdcall (*TglUniform2i)(int location, int v0, int v1);

typedef void __stdcall (*TglUniform3i)(int location, int v0, int v1, int v2);

typedef void __stdcall (*TglUniform4i)(int location, int v0, int v1, int v2, int v3);

typedef void __stdcall (*TglUniform1fv)(int location, int count, PGLfloat value);

typedef void __stdcall (*TglUniform2fv)(int location, int count, PGLfloat value);

typedef void __stdcall (*TglUniform3fv)(int location, int count, PGLfloat value);

typedef void __stdcall (*TglUniform4fv)(int location, int count, PGLfloat value);

typedef void __stdcall (*TglUniform1iv)(int location, int count, PGLInt value);

typedef void __stdcall (*TglUniform2iv)(int location, int count, PGLInt value);

typedef void __stdcall (*TglUniform3iv)(int location, int count, PGLInt value);

typedef void __stdcall (*TglUniform4iv)(int location, int count, PGLInt value);

typedef void __stdcall (*TglUniformMatrix2fv)(int location, int count, Byte transpose, PGLfloat value);

typedef void __stdcall (*TglUniformMatrix3fv)(int location, int count, Byte transpose, PGLfloat value);

typedef void __stdcall (*TglUniformMatrix4fv)(int location, int count, Byte transpose, PGLfloat value);

typedef void __stdcall (*TglValidateProgram)(int programObj);

typedef void __stdcall (*TglVertexAttrib1d)(unsigned index, double x);

typedef void __stdcall (*TglVertexAttrib1dv)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib1f)(unsigned index, float x);

typedef void __stdcall (*TglVertexAttrib1fv)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib1s)(unsigned index, short x);

typedef void __stdcall (*TglVertexAttrib1sv)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib2d)(unsigned index, double x, double y);

typedef void __stdcall (*TglVertexAttrib2dv)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib2f)(unsigned index, float x, float y);

typedef void __stdcall (*TglVertexAttrib2fv)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib2s)(unsigned index, short x, short y);

typedef void __stdcall (*TglVertexAttrib2sv)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib3d)(unsigned index, double x, double y, double z);

typedef void __stdcall (*TglVertexAttrib3dv)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib3f)(unsigned index, float x, float y, float z);

typedef void __stdcall (*TglVertexAttrib3fv)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib3s)(unsigned index, short x, short y, short z);

typedef void __stdcall (*TglVertexAttrib3sv)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib4Nbv)(unsigned index, const PGLByte v);

typedef void __stdcall (*TglVertexAttrib4Niv)(unsigned index, const PGLInt v);

typedef void __stdcall (*TglVertexAttrib4Nsv)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib4Nub)(unsigned index, Byte x, Byte y, Byte z, Byte w);

typedef void __stdcall (*TglVertexAttrib4Nubv)(unsigned index, const PGLubyte v);

typedef void __stdcall (*TglVertexAttrib4Nuiv)(unsigned index, const PGLuint v);

typedef void __stdcall (*TglVertexAttrib4Nusv)(unsigned index, const PGLushort v);

typedef void __stdcall (*TglVertexAttrib4bv)(unsigned index, const PGLByte v);

typedef void __stdcall (*TglVertexAttrib4d)(unsigned index, double x, double y, double z, double w);

typedef void __stdcall (*TglVertexAttrib4dv)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib4f)(unsigned index, float x, float y, float z, float w);

typedef void __stdcall (*TglVertexAttrib4fv)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib4iv)(unsigned index, const PGLInt v);

typedef void __stdcall (*TglVertexAttrib4s)(unsigned index, short x, short y, short z, short w);

typedef void __stdcall (*TglVertexAttrib4sv)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib4ubv)(unsigned index, const PGLubyte v);

typedef void __stdcall (*TglVertexAttrib4uiv)(unsigned index, const PGLuint v);

typedef void __stdcall (*TglVertexAttrib4usv)(unsigned index, const PGLushort v);

typedef void __stdcall (*TglVertexAttribPointer)(unsigned index, int size, unsigned _type, Byte normalized, int stride, const void * _pointer);

typedef void __stdcall (*TglTbufferMask3DFX)(unsigned mask);

typedef void __stdcall (*TglElementPointerAPPLE)(unsigned _type, const void * _pointer);

typedef void __stdcall (*TglDrawElementArrayAPPLE)(unsigned mode, int first, int count);

typedef void __stdcall (*TglDrawRangeElementArrayAPPLE)(unsigned mode, unsigned start, unsigned _end, int first, int count);

typedef void __stdcall (*TglMultiDrawElementArrayAPPLE)(unsigned mode, const PGLInt first, const PGLSizei count, int primcount);

typedef void __stdcall (*TglMultiDrawRangeElementArrayAPPLE)(unsigned mode, unsigned start, unsigned _end, const PGLInt first, const PGLSizei count, int primcount);

typedef void __stdcall (*TglGenFencesAPPLE)(int n, PGLuint fences);

typedef void __stdcall (*TglDeleteFencesAPPLE)(int n, const PGLuint fences);

typedef void __stdcall (*TglSetFenceAPPLE)(unsigned fence);

typedef Byte __stdcall (*TglIsFenceAPPLE)(unsigned fence);

typedef Byte __stdcall (*TglTestFenceAPPLE)(unsigned fence);

typedef void __stdcall (*TglFinishFenceAPPLE)(unsigned fence);

typedef Byte __stdcall (*TglTestObjectAPPLE)(unsigned _object, unsigned name);

typedef void __stdcall (*TglFinishObjectAPPLE)(unsigned _object, int name);

typedef void __stdcall (*TglBindVertexArrayAPPLE)(unsigned _array);

typedef void __stdcall (*TglDeleteVertexArraysAPPLE)(int n, const PGLuint arrays);

typedef void __stdcall (*TglGenVertexArraysAPPLE)(int n, const PGLuint arrays);

typedef Byte __stdcall (*TglIsVertexArrayAPPLE)(unsigned _array);

typedef void __stdcall (*TglVertexArrayRangeAPPLE)(int length, void * _pointer);

typedef void __stdcall (*TglFlushVertexArrayRangeAPPLE)(int length, void * _pointer);

typedef void __stdcall (*TglVertexArrayParameteriAPPLE)(unsigned pname, int param);

typedef void __stdcall (*TglCurrentPaletteMatrixARB)(int index);

typedef void __stdcall (*TglMatrixIndexubvARB)(int size, const PGLubyte indices);

typedef void __stdcall (*TglMatrixIndexusvARB)(int size, const PGLushort indices);

typedef void __stdcall (*TglMatrixIndexuivARB)(int size, const PGLuint indices);

typedef void __stdcall (*TglMatrixIndexPointerARB)(int size, unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglSampleCoverageARB)(float value, Byte invert);

typedef void __stdcall (*TglActiveTextureARB)(unsigned texture);

typedef void __stdcall (*TglClientActiveTextureARB)(unsigned texture);

typedef void __stdcall (*TglMultiTexCoord1dARB)(unsigned target, double s);

typedef void __stdcall (*TglMultiTexCoord1dvARB)(unsigned target, const PGLdouble v);

typedef void __stdcall (*TglMultiTexCoord1fARB)(unsigned target, float s);

typedef void __stdcall (*TglMultiTexCoord1fvARB)(unsigned target, const PGLfloat v);

typedef void __stdcall (*TglMultiTexCoord1iARB)(unsigned target, int s);

typedef void __stdcall (*TglMultiTexCoord1ivARB)(unsigned target, const PGLInt v);

typedef void __stdcall (*TglMultiTexCoord1sARB)(unsigned target, short s);

typedef void __stdcall (*TglMultiTexCoord1svARB)(unsigned target, const PGLShort v);

typedef void __stdcall (*TglMultiTexCoord2dARB)(unsigned target, double s, double t);

typedef void __stdcall (*TglMultiTexCoord2dvARB)(unsigned target, const PGLdouble v);

typedef void __stdcall (*TglMultiTexCoord2fARB)(unsigned target, float s, float t);

typedef void __stdcall (*TglMultiTexCoord2fvARB)(unsigned target, const PGLfloat v);

typedef void __stdcall (*TglMultiTexCoord2iARB)(unsigned target, int s, int t);

typedef void __stdcall (*TglMultiTexCoord2ivARB)(unsigned target, const PGLInt v);

typedef void __stdcall (*TglMultiTexCoord2sARB)(unsigned target, short s, short t);

typedef void __stdcall (*TglMultiTexCoord2svARB)(unsigned target, const PGLShort v);

typedef void __stdcall (*TglMultiTexCoord3dARB)(unsigned target, double s, double t, double r);

typedef void __stdcall (*TglMultiTexCoord3dvARB)(unsigned target, const PGLdouble v);

typedef void __stdcall (*TglMultiTexCoord3fARB)(unsigned target, float s, float t, float r);

typedef void __stdcall (*TglMultiTexCoord3fvARB)(unsigned target, const PGLfloat v);

typedef void __stdcall (*TglMultiTexCoord3iARB)(unsigned target, int s, int t, int r);

typedef void __stdcall (*TglMultiTexCoord3ivARB)(unsigned target, const PGLInt v);

typedef void __stdcall (*TglMultiTexCoord3sARB)(unsigned target, short s, short t, short r);

typedef void __stdcall (*TglMultiTexCoord3svARB)(unsigned target, const PGLShort v);

typedef void __stdcall (*TglMultiTexCoord4dARB)(unsigned target, double s, double t, double r, double q);

typedef void __stdcall (*TglMultiTexCoord4dvARB)(unsigned target, const PGLdouble v);

typedef void __stdcall (*TglMultiTexCoord4fARB)(unsigned target, float s, float t, float r, float q);

typedef void __stdcall (*TglMultiTexCoord4fvARB)(unsigned target, const PGLfloat v);

typedef void __stdcall (*TglMultiTexCoord4iARB)(unsigned target, int s, int t, int r, int q);

typedef void __stdcall (*TglMultiTexCoord4ivARB)(unsigned target, const PGLInt v);

typedef void __stdcall (*TglMultiTexCoord4sARB)(unsigned target, short s, short t, short r, short q);

typedef void __stdcall (*TglMultiTexCoord4svARB)(unsigned target, const PGLShort v);

typedef void __stdcall (*TglPointParameterfARB)(unsigned pname, float param);

typedef void __stdcall (*TglPointParameterfvARB)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglCompressedTexImage3DARB)(unsigned target, int level, unsigned internalformat, int width, int height, int depth, int border, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexImage2DARB)(unsigned target, int level, unsigned internalformat, int width, int height, int border, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexImage1DARB)(unsigned target, int level, unsigned internalformat, int width, int border, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexSubImage3DARB)(unsigned target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, unsigned format, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexSubImage2DARB)(unsigned target, int level, int xoffset, int yoffset, int width, int height, unsigned format, int imageSize, const void * data);

typedef void __stdcall (*TglCompressedTexSubImage1DARB)(unsigned target, int level, int xoffset, int width, unsigned format, int imageSize, const void * data);

typedef void __stdcall (*TglGetCompressedTexImageARB)(unsigned target, int level, void * img);

typedef void __stdcall (*TglLoadTransposeMatrixfARB)(const PGLfloat m);

typedef void __stdcall (*TglLoadTransposeMatrixdARB)(const PGLdouble m);

typedef void __stdcall (*TglMultTransposeMatrixfARB)(const PGLfloat m);

typedef void __stdcall (*TglMultTransposeMatrixdARB)(const PGLdouble m);

typedef void __stdcall (*TglWeightbvARB)(int size, const PGLByte weights);

typedef void __stdcall (*TglWeightsvARB)(int size, const PGLShort weights);

typedef void __stdcall (*TglWeightivARB)(int size, const PGLInt weights);

typedef void __stdcall (*TglWeightfvARB)(int size, const PGLfloat weights);

typedef void __stdcall (*TglWeightdvARB)(int size, const PGLdouble weights);

typedef void __stdcall (*TglWeightubvARB)(int size, const PGLubyte weights);

typedef void __stdcall (*TglWeightusvARB)(int size, const PGLushort weights);

typedef void __stdcall (*TglWeightuivARB)(int size, const PGLuint weights);

typedef void __stdcall (*TglWeightPointerARB)(int size, unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglVertexBlendARB)(int count);

typedef void __stdcall (*TglBindBufferARB)(unsigned target, unsigned buffer);

typedef void __stdcall (*TglDeleteBuffersARB)(int n, const PGLuint buffers);

typedef void __stdcall (*TglGenBuffersARB)(int n, PGLuint buffers);

typedef Byte __stdcall (*TglIsBufferARB)(unsigned buffer);

typedef void __stdcall (*TglBufferDataARB)(unsigned target, int size, const void * data, unsigned usage);

typedef void __stdcall (*TglBufferSubDataARB)(unsigned target, int offset, int size, const void * data);

typedef void __stdcall (*TglGetBufferSubDataARB)(unsigned target, int offset, int size, void * data);

typedef void * __stdcall (*TglMapBufferARB)(unsigned target, unsigned access);

typedef Byte __stdcall (*TglUnmapBufferARB)(unsigned target);

typedef void __stdcall (*TglGetBufferParameterivARB)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetBufferPointervARB)(unsigned target, unsigned pname, void * params);

typedef void __stdcall (*TglVertexAttrib1dARB)(unsigned index, double x);

typedef void __stdcall (*TglVertexAttrib1dvARB)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib1fARB)(unsigned index, float x);

typedef void __stdcall (*TglVertexAttrib1fvARB)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib1sARB)(unsigned index, short x);

typedef void __stdcall (*TglVertexAttrib1svARB)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib2dARB)(unsigned index, double x, double y);

typedef void __stdcall (*TglVertexAttrib2dvARB)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib2fARB)(unsigned index, float x, float y);

typedef void __stdcall (*TglVertexAttrib2fvARB)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib2sARB)(unsigned index, short x, short y);

typedef void __stdcall (*TglVertexAttrib2svARB)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib3dARB)(unsigned index, double x, double y, double z);

typedef void __stdcall (*TglVertexAttrib3dvARB)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib3fARB)(unsigned index, float x, float y, float z);

typedef void __stdcall (*TglVertexAttrib3fvARB)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib3sARB)(unsigned index, short x, short y, short z);

typedef void __stdcall (*TglVertexAttrib3svARB)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib4NbvARB)(unsigned index, const PGLByte v);

typedef void __stdcall (*TglVertexAttrib4NivARB)(unsigned index, const PGLInt v);

typedef void __stdcall (*TglVertexAttrib4NsvARB)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib4NubARB)(unsigned index, Byte x, Byte y, Byte z, Byte w);

typedef void __stdcall (*TglVertexAttrib4NubvARB)(unsigned index, const PGLubyte v);

typedef void __stdcall (*TglVertexAttrib4NuivARB)(unsigned index, const PGLuint v);

typedef void __stdcall (*TglVertexAttrib4NusvARB)(unsigned index, const PGLushort v);

typedef void __stdcall (*TglVertexAttrib4bvARB)(unsigned index, const PGLByte v);

typedef void __stdcall (*TglVertexAttrib4dARB)(unsigned index, double x, double y, double z, double w);

typedef void __stdcall (*TglVertexAttrib4dvARB)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib4fARB)(unsigned index, float x, float y, float z, float w);

typedef void __stdcall (*TglVertexAttrib4fvARB)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib4ivARB)(unsigned index, const PGLInt v);

typedef void __stdcall (*TglVertexAttrib4sARB)(unsigned index, short x, short y, short z, short w);

typedef void __stdcall (*TglVertexAttrib4svARB)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib4ubvARB)(unsigned index, const PGLubyte v);

typedef void __stdcall (*TglVertexAttrib4uivARB)(unsigned index, const PGLuint v);

typedef void __stdcall (*TglVertexAttrib4usvARB)(unsigned index, const PGLushort v);

typedef void __stdcall (*TglVertexAttribPointerARB)(unsigned index, int size, unsigned _type, Byte normalized, int stride, const void * _pointer);

typedef void __stdcall (*TglEnableVertexAttribArrayARB)(unsigned index);

typedef void __stdcall (*TglDisableVertexAttribArrayARB)(unsigned index);

typedef void __stdcall (*TglProgramStringARB)(unsigned target, unsigned format, int len, const void * _string);

typedef void __stdcall (*TglBindProgramARB)(unsigned target, unsigned _program);

typedef void __stdcall (*TglDeleteProgramsARB)(int n, const PGLuint programs);

typedef void __stdcall (*TglGenProgramsARB)(int n, PGLuint programs);

typedef void __stdcall (*TglProgramEnvParameter4dARB)(unsigned target, unsigned index, double x, double y, double z, double w);

typedef void __stdcall (*TglProgramEnvParameter4dvARB)(unsigned target, unsigned index, const PGLdouble params);

typedef void __stdcall (*TglProgramEnvParameter4fARB)(unsigned target, unsigned index, float x, float y, float z, float w);

typedef void __stdcall (*TglProgramEnvParameter4fvARB)(unsigned target, unsigned index, const PGLfloat params);

typedef void __stdcall (*TglProgramLocalParameter4dARB)(unsigned target, unsigned index, double x, double y, double z, double w);

typedef void __stdcall (*TglProgramLocalParameter4dvARB)(unsigned target, unsigned index, const PGLdouble params);

typedef void __stdcall (*TglProgramLocalParameter4fARB)(unsigned target, unsigned index, float x, float y, float z, float w);

typedef void __stdcall (*TglProgramLocalParameter4fvARB)(unsigned target, unsigned index, const PGLfloat params);

typedef void __stdcall (*TglGetProgramEnvParameterdvARB)(unsigned target, unsigned index, PGLdouble params);

typedef void __stdcall (*TglGetProgramEnvParameterfvARB)(unsigned target, unsigned index, PGLfloat params);

typedef void __stdcall (*TglGetProgramLocalParameterdvARB)(unsigned target, unsigned index, PGLdouble params);

typedef void __stdcall (*TglGetProgramLocalParameterfvARB)(unsigned target, unsigned index, PGLfloat params);

typedef void __stdcall (*TglGetProgramivARB)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetProgramStringARB)(unsigned target, unsigned pname, void * _string);

typedef void __stdcall (*TglGetVertexAttribdvARB)(unsigned index, unsigned pname, PGLdouble params);

typedef void __stdcall (*TglGetVertexAttribfvARB)(unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetVertexAttribivARB)(unsigned index, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetVertexAttribPointervARB)(unsigned index, unsigned pname, void * _pointer);

typedef Byte __stdcall (*TglIsProgramARB)(unsigned _program);

typedef void __stdcall (*TglWindowPos2dARB)(double x, double y);

typedef void __stdcall (*TglWindowPos2dvARB)(const PGLdouble v);

typedef void __stdcall (*TglWindowPos2fARB)(float x, float y);

typedef void __stdcall (*TglWindowPos2fvARB)(const PGLfloat v);

typedef void __stdcall (*TglWindowPos2iARB)(int x, int y);

typedef void __stdcall (*TglWindowPos2ivARB)(const PGLInt v);

typedef void __stdcall (*TglWindowPos2sARB)(short x, short y);

typedef void __stdcall (*TglWindowPos2svARB)(const PGLShort v);

typedef void __stdcall (*TglWindowPos3dARB)(double x, double y, double z);

typedef void __stdcall (*TglWindowPos3dvARB)(const PGLdouble v);

typedef void __stdcall (*TglWindowPos3fARB)(float x, float y, float z);

typedef void __stdcall (*TglWindowPos3fvARB)(const PGLfloat v);

typedef void __stdcall (*TglWindowPos3iARB)(int x, int y, int z);

typedef void __stdcall (*TglWindowPos3ivARB)(const PGLInt v);

typedef void __stdcall (*TglWindowPos3sARB)(short x, short y, short z);

typedef void __stdcall (*TglWindowPos3svARB)(const PGLShort v);

typedef void __stdcall (*TglDrawBuffersARB)(int n, PGLenum bufs);

typedef void __stdcall (*TglClampColorARB)(unsigned target, unsigned clamp);

typedef void __stdcall (*TglGetActiveAttribARB)(int programobj, unsigned index, int maxLength, int &length, int &size, unsigned &_type, char * name);

typedef int __stdcall (*TglGetAttribLocationARB)(int programObj, const char * char);

typedef void __stdcall (*TglBindAttribLocationARB)(int programObj, unsigned index, const char * name);

typedef void __stdcall (*TglDeleteObjectARB)(int Obj);

typedef int __stdcall (*TglGetHandleARB)(unsigned pname);

typedef void __stdcall (*TglDetachObjectARB)(int container, int attached);

typedef int __stdcall (*TglCreateShaderObjectARB)(unsigned shaderType);

typedef void __stdcall (*TglShaderSourceARB)(int shaderObj, int count, PPGLCharARB _string, PGLInt lengths);

typedef void __stdcall (*TglCompileShaderARB)(int shaderObj);

typedef int __stdcall (*TglCreateProgramObjectARB)(void);

typedef void __stdcall (*TglAttachObjectARB)(int programObj, int shaderObj);

typedef void __stdcall (*TglLinkProgramARB)(int programObj);

typedef void __stdcall (*TglUseProgramObjectARB)(int programObj);

typedef void __stdcall (*TglValidateProgramARB)(int programObj);

typedef void __stdcall (*TglUniform1fARB)(int location, float v0);

typedef void __stdcall (*TglUniform2fARB)(int location, float v0, float v1);

typedef void __stdcall (*TglUniform3fARB)(int location, float v0, float v1, float v2);

typedef void __stdcall (*TglUniform4fARB)(int location, float v0, float v1, float v2, float v3);

typedef void __stdcall (*TglUniform1iARB)(int location, int v0);

typedef void __stdcall (*TglUniform2iARB)(int location, int v0, int v1);

typedef void __stdcall (*TglUniform3iARB)(int location, int v0, int v1, int v2);

typedef void __stdcall (*TglUniform4iARB)(int location, int v0, int v1, int v2, int v3);

typedef void __stdcall (*TglUniform1fvARB)(int location, int count, PGLfloat value);

typedef void __stdcall (*TglUniform2fvARB)(int location, int count, PGLfloat value);

typedef void __stdcall (*TglUniform3fvARB)(int location, int count, PGLfloat value);

typedef void __stdcall (*TglUniform4fvARB)(int location, int count, PGLfloat value);

typedef void __stdcall (*TglUniform1ivARB)(int location, int count, PGLInt value);

typedef void __stdcall (*TglUniform2ivARB)(int location, int count, PGLInt value);

typedef void __stdcall (*TglUniform3ivARB)(int location, int count, PGLInt value);

typedef void __stdcall (*TglUniform4ivARB)(int location, int count, PGLInt value);

typedef void __stdcall (*TglUniformMatrix2fvARB)(int location, int count, Byte transpose, PGLfloat value);

typedef void __stdcall (*TglUniformMatrix3fvARB)(int location, int count, Byte transpose, PGLfloat value);

typedef void __stdcall (*TglUniformMatrix4fvARB)(int location, int count, Byte transpose, PGLfloat value);

typedef void __stdcall (*TglGetObjectParameterfvARB)(int Obj, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetObjectParameterivARB)(int Obj, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetInfoLogARB)(int shaderObj, int maxLength, int &length, char * infoLog);

typedef void __stdcall (*TglGetAttachedObjectsARB)(int programobj, int maxCount, int &count, PGLHandleARB objects);

typedef int __stdcall (*TglGetUniformLocationARB)(int programObj, const char * char);

typedef void __stdcall (*TglGetActiveUniformARB)(int programobj, unsigned index, int maxLength, int &length, int &size, unsigned &_type, char * name);

typedef void __stdcall (*TglGetUniformfvARB)(int programObj, int location, PGLfloat params);

typedef void __stdcall (*TglGetUniformivARB)(int programObj, int location, PGLInt params);

typedef void __stdcall (*TglGetShaderSourceARB)(int shader, int maxLength, int &length, char * source);

typedef void __stdcall (*TglGenQueriesARB)(int n, PGLuint ids);

typedef void __stdcall (*TglDeleteQueriesARB)(int n, const PGLuint ids);

typedef bool __stdcall (*TglIsQueryARB)(unsigned id);

typedef void __stdcall (*TglBeginQueryARB)(unsigned target, unsigned id);

typedef void __stdcall (*TglEndQueryARB)(unsigned target);

typedef void __stdcall (*TglGetQueryivARB)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetQueryObjectivARB)(unsigned id, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetQueryObjectuivARB)(unsigned id, unsigned pname, PGLuint params);

typedef void __stdcall (*TglDrawBuffersATI)(int n, const PGLenum bufs);

typedef void __stdcall (*TglElementPointerATI)(unsigned _type, const void * _pointer);

typedef void __stdcall (*TglDrawElementArrayATI)(unsigned mode, int count);

typedef void __stdcall (*TglDrawRangeElementArrayATI)(unsigned mode, unsigned start, unsigned _end, int count);

typedef void __stdcall (*TglTexBumpParameterivATI)(unsigned pname, const PGLInt param);

typedef void __stdcall (*TglTexBumpParameterfvATI)(unsigned pname, const PGLfloat param);

typedef void __stdcall (*TglGetTexBumpParameterivATI)(unsigned pname, PGLInt param);

typedef void __stdcall (*TglGetTexBumpParameterfvATI)(unsigned pname, PGLfloat param);

typedef unsigned __stdcall (*TglGenFragmentShadersATI)(unsigned range);

typedef void __stdcall (*TglBindFragmentShaderATI)(unsigned id);

typedef void __stdcall (*TglDeleteFragmentShaderATI)(unsigned id);

typedef void __stdcall (*TglBeginFragmentShaderATI)(void);

typedef void __stdcall (*TglEndFragmentShaderATI)(void);

typedef void __stdcall (*TglPassTexCoordATI)(unsigned dst, unsigned coord, unsigned swizzle);

typedef void __stdcall (*TglSampleMapATI)(unsigned dst, unsigned interp, unsigned swizzle);

typedef void __stdcall (*TglColorFragmentOp1ATI)(unsigned op, unsigned dst, unsigned dstMask, unsigned dstMod, unsigned arg1, unsigned arg1Rep, unsigned arg1Mod);

typedef void __stdcall (*TglColorFragmentOp2ATI)(unsigned op, unsigned dst, unsigned dstMask, unsigned dstMod, unsigned arg1, unsigned arg1Rep, unsigned arg1Mod, unsigned arg2, unsigned arg2Rep, unsigned arg2Mod);

typedef void __stdcall (*TglColorFragmentOp3ATI)(unsigned op, unsigned dst, unsigned dstMask, unsigned dstMod, unsigned arg1, unsigned arg1Rep, unsigned arg1Mod, unsigned arg2, unsigned arg2Rep, unsigned arg2Mod, unsigned arg3, unsigned arg3Rep, unsigned arg3Mod);

typedef void __stdcall (*TglAlphaFragmentOp1ATI)(unsigned op, unsigned dst, unsigned dstMod, unsigned arg1, unsigned arg1Rep, unsigned arg1Mod);

typedef void __stdcall (*TglAlphaFragmentOp2ATI)(unsigned op, unsigned dst, unsigned dstMod, unsigned arg1, unsigned arg1Rep, unsigned arg1Mod, unsigned arg2, unsigned arg2Rep, unsigned arg2Mod);

typedef void __stdcall (*TglAlphaFragmentOp3ATI)(unsigned op, unsigned dst, unsigned dstMod, unsigned arg1, unsigned arg1Rep, unsigned arg1Mod, unsigned arg2, unsigned arg2Rep, unsigned arg2Mod, unsigned arg3, unsigned arg3Rep, unsigned arg3Mod);

typedef void __stdcall (*TglSetFragmentShaderConstantATI)(unsigned dst, const PGLfloat value);

typedef void * __stdcall (*TglMapObjectBufferATI)(unsigned buffer);

typedef void __stdcall (*TglUnmapObjectBufferATI)(unsigned buffer);

typedef void __stdcall (*TglPNTrianglesiATI)(unsigned pname, int param);

typedef void __stdcall (*TglPNTrianglesfATI)(unsigned pname, float param);

typedef void __stdcall (*TglStencilOpSeparateATI)(unsigned face, unsigned sfail, unsigned dpfail, unsigned dppass);

typedef void __stdcall (*TglStencilFuncSeparateATI)(unsigned frontfunc, unsigned backfunc, int ref, unsigned mask);

typedef unsigned __stdcall (*TglNewObjectBufferATI)(int size, const void * _pointer, unsigned usage);

typedef Byte __stdcall (*TglIsObjectBufferATI)(unsigned buffer);

typedef void __stdcall (*TglUpdateObjectBufferATI)(unsigned buffer, unsigned offset, int size, const void * _pointer, unsigned preserve);

typedef void __stdcall (*TglGetObjectBufferfvATI)(unsigned buffer, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetObjectBufferivATI)(unsigned buffer, unsigned pname, PGLInt params);

typedef void __stdcall (*TglFreeObjectBufferATI)(unsigned buffer);

typedef void __stdcall (*TglArrayObjectATI)(unsigned _array, int size, unsigned _type, int stride, unsigned buffer, unsigned offset);

typedef void __stdcall (*TglGetArrayObjectfvATI)(unsigned _array, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetArrayObjectivATI)(unsigned _array, unsigned pname, PGLInt params);

typedef void __stdcall (*TglVariantArrayObjectATI)(unsigned id, unsigned _type, int stride, unsigned buffer, unsigned offset);

typedef void __stdcall (*TglGetVariantArrayObjectfvATI)(unsigned id, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetVariantArrayObjectivATI)(unsigned id, unsigned pname, PGLInt params);

typedef void __stdcall (*TglVertexAttribArrayObjectATI)(unsigned index, int size, unsigned _type, Byte normalized, int stride, unsigned buffer, unsigned offset);

typedef void __stdcall (*TglGetVertexAttribArrayObjectfvATI)(unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetVertexAttribArrayObjectivATI)(unsigned index, unsigned pname, PGLInt params);

typedef void __stdcall (*TglVertexStream1sATI)(unsigned stream, short x);

typedef void __stdcall (*TglVertexStream1svATI)(unsigned stream, const PGLShort coords);

typedef void __stdcall (*TglVertexStream1iATI)(unsigned stream, int x);

typedef void __stdcall (*TglVertexStream1ivATI)(unsigned stream, const PGLInt coords);

typedef void __stdcall (*TglVertexStream1fATI)(unsigned stream, float x);

typedef void __stdcall (*TglVertexStream1fvATI)(unsigned stream, const PGLfloat coords);

typedef void __stdcall (*TglVertexStream1dATI)(unsigned stream, double x);

typedef void __stdcall (*TglVertexStream1dvATI)(unsigned stream, const PGLdouble coords);

typedef void __stdcall (*TglVertexStream2sATI)(unsigned stream, short x, short y);

typedef void __stdcall (*TglVertexStream2svATI)(unsigned stream, const PGLShort coords);

typedef void __stdcall (*TglVertexStream2iATI)(unsigned stream, int x, int y);

typedef void __stdcall (*TglVertexStream2ivATI)(unsigned stream, const PGLInt coords);

typedef void __stdcall (*TglVertexStream2fATI)(unsigned stream, float x, float y);

typedef void __stdcall (*TglVertexStream2fvATI)(unsigned stream, const PGLfloat coords);

typedef void __stdcall (*TglVertexStream2dATI)(unsigned stream, double x, double y);

typedef void __stdcall (*TglVertexStream2dvATI)(unsigned stream, const PGLdouble coords);

typedef void __stdcall (*TglVertexStream3sATI)(unsigned stream, short x, short y, short z);

typedef void __stdcall (*TglVertexStream3svATI)(unsigned stream, const PGLShort coords);

typedef void __stdcall (*TglVertexStream3iATI)(unsigned stream, int x, int y, int z);

typedef void __stdcall (*TglVertexStream3ivATI)(unsigned stream, const PGLInt coords);

typedef void __stdcall (*TglVertexStream3fATI)(unsigned stream, float x, float y, float z);

typedef void __stdcall (*TglVertexStream3fvATI)(unsigned stream, const PGLfloat coords);

typedef void __stdcall (*TglVertexStream3dATI)(unsigned stream, double x, double y, double z);

typedef void __stdcall (*TglVertexStream3dvATI)(unsigned stream, const PGLdouble coords);

typedef void __stdcall (*TglVertexStream4sATI)(unsigned stream, short x, short y, short z, short w);

typedef void __stdcall (*TglVertexStream4svATI)(unsigned stream, const PGLShort coords);

typedef void __stdcall (*TglVertexStream4iATI)(unsigned stream, int x, int y, int z, int w);

typedef void __stdcall (*TglVertexStream4ivATI)(unsigned stream, const PGLInt coords);

typedef void __stdcall (*TglVertexStream4fATI)(unsigned stream, float x, float y, float z, float w);

typedef void __stdcall (*TglVertexStream4fvATI)(unsigned stream, const PGLfloat coords);

typedef void __stdcall (*TglVertexStream4dATI)(unsigned stream, double x, double y, double z, double w);

typedef void __stdcall (*TglVertexStream4dvATI)(unsigned stream, const PGLdouble coords);

typedef void __stdcall (*TglNormalStream3bATI)(unsigned stream, Shortint nx, Shortint ny, Shortint nz);

typedef void __stdcall (*TglNormalStream3bvATI)(unsigned stream, const PGLByte coords);

typedef void __stdcall (*TglNormalStream3sATI)(unsigned stream, short nx, short ny, short nz);

typedef void __stdcall (*TglNormalStream3svATI)(unsigned stream, const PGLShort coords);

typedef void __stdcall (*TglNormalStream3iATI)(unsigned stream, int nx, int ny, int nz);

typedef void __stdcall (*TglNormalStream3ivATI)(unsigned stream, const PGLInt coords);

typedef void __stdcall (*TglNormalStream3fATI)(unsigned stream, float nx, float ny, float nz);

typedef void __stdcall (*TglNormalStream3fvATI)(unsigned stream, const PGLfloat coords);

typedef void __stdcall (*TglNormalStream3dATI)(unsigned stream, double nx, double ny, double nz);

typedef void __stdcall (*TglNormalStream3dvATI)(unsigned stream, const PGLdouble coords);

typedef void __stdcall (*TglClientActiveVertexStreamATI)(unsigned stream);

typedef void __stdcall (*TglVertexBlendEnviATI)(unsigned pname, int param);

typedef void __stdcall (*TglVertexBlendEnvfATI)(unsigned pname, float param);

typedef void __stdcall (*TglBlendColorEXT)(float red, float green, float blue, float alpha);

typedef void __stdcall (*TglBlendFuncSeparateEXT)(unsigned sfactorRGB, unsigned dfactorRGB, unsigned sfactorAlpha, unsigned dfactorAlpha);

typedef void __stdcall (*TglBlendEquationEXT)(unsigned mode);

typedef void __stdcall (*TglColorSubTableEXT)(unsigned target, int start, int count, unsigned format, unsigned _type, const void * data);

typedef void __stdcall (*TglCopyColorSubTableEXT)(unsigned target, int start, int x, int y, int width);

typedef void __stdcall (*TglLockArraysEXT)(int first, int count);

typedef void __stdcall (*TglUnlockArraysEXT)(void);

typedef void __stdcall (*TglConvolutionFilter1DEXT)(unsigned target, unsigned internalformat, int width, unsigned format, unsigned _type, const void * image);

typedef void __stdcall (*TglConvolutionFilter2DEXT)(unsigned target, unsigned internalformat, int width, int height, unsigned format, unsigned _type, const void * image);

typedef void __stdcall (*TglConvolutionParameterfEXT)(unsigned target, unsigned pname, float params);

typedef void __stdcall (*TglConvolutionParameterfvEXT)(unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglConvolutionParameteriEXT)(unsigned target, unsigned pname, int params);

typedef void __stdcall (*TglConvolutionParameterivEXT)(unsigned target, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglCopyConvolutionFilter1DEXT)(unsigned target, unsigned internalformat, int x, int y, int width);

typedef void __stdcall (*TglCopyConvolutionFilter2DEXT)(unsigned target, unsigned internalformat, int x, int y, int width, int height);

typedef void __stdcall (*TglGetConvolutionFilterEXT)(unsigned target, unsigned format, unsigned _type, void * image);

typedef void __stdcall (*TglGetConvolutionParameterfvEXT)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetConvolutionParameterivEXT)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetSeparableFilterEXT)(unsigned target, unsigned format, unsigned _type, void * row, void * column, void * span);

typedef void __stdcall (*TglSeparableFilter2DEXT)(unsigned target, unsigned internalformat, int width, int height, unsigned format, unsigned _type, const void * row, const void * column);

typedef void __stdcall (*TglTangent3bEXT)(Shortint tx, Shortint ty, Shortint tz);

typedef void __stdcall (*TglTangent3bvEXT)(const PGLByte v);

typedef void __stdcall (*TglTangent3dEXT)(double tx, double ty, double tz);

typedef void __stdcall (*TglTangent3dvEXT)(const PGLdouble v);

typedef void __stdcall (*TglTangent3fEXT)(float tx, float ty, float tz);

typedef void __stdcall (*TglTangent3fvEXT)(const PGLfloat v);

typedef void __stdcall (*TglTangent3iEXT)(int tx, int ty, int tz);

typedef void __stdcall (*TglTangent3ivEXT)(const PGLInt v);

typedef void __stdcall (*TglTangent3sEXT)(short tx, short ty, short tz);

typedef void __stdcall (*TglTangent3svEXT)(const PGLShort v);

typedef void __stdcall (*TglBinormal3bEXT)(Shortint bx, Shortint by, Shortint bz);

typedef void __stdcall (*TglBinormal3bvEXT)(const PGLByte v);

typedef void __stdcall (*TglBinormal3dEXT)(double bx, double by, double bz);

typedef void __stdcall (*TglBinormal3dvEXT)(const PGLdouble v);

typedef void __stdcall (*TglBinormal3fEXT)(float bx, float by, float bz);

typedef void __stdcall (*TglBinormal3fvEXT)(const PGLfloat v);

typedef void __stdcall (*TglBinormal3iEXT)(int bx, int by, int bz);

typedef void __stdcall (*TglBinormal3ivEXT)(const PGLInt v);

typedef void __stdcall (*TglBinormal3sEXT)(short bx, short by, short bz);

typedef void __stdcall (*TglBinormal3svEXT)(const PGLShort v);

typedef void __stdcall (*TglTangentPointerEXT)(unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglBinormalPointerEXT)(unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglCopyTexImage1DEXT)(unsigned target, int level, unsigned internalformat, int x, int y, int width, int border);

typedef void __stdcall (*TglCopyTexImage2DEXT)(unsigned target, int level, unsigned internalformat, int x, int y, int width, int height, int border);

typedef void __stdcall (*TglCopyTexSubImage1DEXT)(unsigned target, int level, int xoffset, int x, int y, int width);

typedef void __stdcall (*TglCopyTexSubImage2DEXT)(unsigned target, int level, int xoffset, int yoffset, int x, int y, int width, int height);

typedef void __stdcall (*TglCopyTexSubImage3DEXT)(unsigned target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);

typedef void __stdcall (*TglCullParameterdvEXT)(unsigned pname, PGLdouble params);

typedef void __stdcall (*TglCullParameterfvEXT)(unsigned pname, PGLfloat params);

typedef void __stdcall (*TglDrawRangeElementsEXT)(unsigned mode, unsigned start, unsigned _end, int count, unsigned _type, const void * indices);

typedef void __stdcall (*TglFogCoordfEXT)(float coord);

typedef void __stdcall (*TglFogCoordfvEXT)(const PGLfloat coord);

typedef void __stdcall (*TglFogCoorddEXT)(double coord);

typedef void __stdcall (*TglFogCoorddvEXT)(const PGLdouble coord);

typedef void __stdcall (*TglFogCoordPointerEXT)(unsigned _type, int stride, const void * _pointer);

typedef bool __stdcall (*TglIsRenderbufferEXT)(unsigned renderbuffer);

typedef void __stdcall (*TglBindRenderbufferEXT)(unsigned target, unsigned renderbuffer);

typedef void __stdcall (*TglDeleteRenderbuffersEXT)(int n, const PGLuint renderbuffers);

typedef void __stdcall (*TglGenRenderbuffersEXT)(int n, PGLuint renderbuffers);

typedef void __stdcall (*TglRenderbufferStorageEXT)(unsigned target, unsigned internalformat, int width, int height);

typedef void __stdcall (*TglGetRenderbufferParameterivEXT)(unsigned target, unsigned pname, PGLInt params);

typedef bool __stdcall (*TglIsFramebufferEXT)(unsigned framebuffer);

typedef void __stdcall (*TglBindFramebufferEXT)(unsigned target, unsigned framebuffer);

typedef void __stdcall (*TglDeleteFramebuffersEXT)(int n, const PGLuint framebuffers);

typedef void __stdcall (*TglGenFramebuffersEXT)(int n, PGLuint framebuffers);

typedef unsigned __stdcall (*TglCheckFramebufferStatusEXT)(unsigned target);

typedef void __stdcall (*TglFramebufferTexture1DEXT)(unsigned target, unsigned attachment, unsigned textarget, unsigned texture, int level);

typedef void __stdcall (*TglFramebufferTexture2DEXT)(unsigned target, unsigned attachment, unsigned textarget, unsigned texture, int level);

typedef void __stdcall (*TglFramebufferTexture3DEXT)(unsigned target, unsigned attachment, unsigned textarget, unsigned texture, int level, int zoffset);

typedef void __stdcall (*TglFramebufferRenderbufferEXT)(unsigned target, unsigned attachment, unsigned renderbuffertarget, unsigned renderbuffer);

typedef void __stdcall (*TglGetFramebufferAttachmentParameterivEXT)(unsigned target, unsigned attachment, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGenerateMipmapEXT)(unsigned target);

typedef void __stdcall (*TglGetHistogramEXT)(unsigned target, Byte reset, unsigned format, unsigned _type, void * values);

typedef void __stdcall (*TglGetHistogramParameterfvEXT)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetHistogramParameterivEXT)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetMinmaxEXT)(unsigned target, Byte reset, unsigned format, unsigned _type, void * values);

typedef void __stdcall (*TglGetMinmaxParameterfvEXT)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetMinmaxParameterivEXT)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglHistogramEXT)(unsigned target, int width, unsigned internalformat, Byte sink);

typedef void __stdcall (*TglMinmaxEXT)(unsigned target, unsigned internalformat, Byte sink);

typedef void __stdcall (*TglResetHistogramEXT)(unsigned target);

typedef void __stdcall (*TglResetMinmaxEXT)(unsigned target);

typedef void __stdcall (*TglIndexFuncEXT)(unsigned func, float ref);

typedef void __stdcall (*TglIndexMaterialEXT)(unsigned face, unsigned mode);

typedef void __stdcall (*TglApplyTextureEXT)(unsigned mode);

typedef void __stdcall (*TglTextureLightEXT)(unsigned pname);

typedef void __stdcall (*TglTextureMaterialEXT)(unsigned face, unsigned mode);

typedef void __stdcall (*TglMultiDrawArraysEXT)(unsigned mode, PGLInt first, PGLSizei count, int primcount);

typedef void __stdcall (*TglMultiDrawElementsEXT)(unsigned mode, const PGLSizei count, unsigned _type, const void * indices, int primcount);

typedef void __stdcall (*TglSampleMaskEXT)(float value, Byte invert);

typedef void __stdcall (*TglSamplePatternEXT)(unsigned pattern);

typedef void __stdcall (*TglColorTableEXT)(unsigned target, unsigned internalFormat, int width, unsigned format, unsigned _type, const void * table);

typedef void __stdcall (*TglGetColorTableEXT)(unsigned target, unsigned format, unsigned _type, void * data);

typedef void __stdcall (*TglGetColorTableParameterivEXT)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetColorTableParameterfvEXT)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglPixelTransformParameteriEXT)(unsigned target, unsigned pname, int param);

typedef void __stdcall (*TglPixelTransformParameterfEXT)(unsigned target, unsigned pname, float param);

typedef void __stdcall (*TglPixelTransformParameterivEXT)(unsigned target, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglPixelTransformParameterfvEXT)(unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglPointParameterfEXT)(unsigned pname, float param);

typedef void __stdcall (*TglPointParameterfvEXT)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglPolygonOffsetEXT)(float factor, float bias);

typedef void __stdcall (*TglSecondaryColor3bEXT)(Shortint red, Shortint green, Shortint blue);

typedef void __stdcall (*TglSecondaryColor3bvEXT)(const PGLByte v);

typedef void __stdcall (*TglSecondaryColor3dEXT)(double red, double green, double blue);

typedef void __stdcall (*TglSecondaryColor3dvEXT)(const PGLdouble v);

typedef void __stdcall (*TglSecondaryColor3fEXT)(float red, float green, float blue);

typedef void __stdcall (*TglSecondaryColor3fvEXT)(const PGLfloat v);

typedef void __stdcall (*TglSecondaryColor3iEXT)(int red, int green, int blue);

typedef void __stdcall (*TglSecondaryColor3ivEXT)(const PGLInt v);

typedef void __stdcall (*TglSecondaryColor3sEXT)(short red, short green, short blue);

typedef void __stdcall (*TglSecondaryColor3svEXT)(const PGLShort v);

typedef void __stdcall (*TglSecondaryColor3ubEXT)(Byte red, Byte green, Byte blue);

typedef void __stdcall (*TglSecondaryColor3ubvEXT)(const PGLubyte v);

typedef void __stdcall (*TglSecondaryColor3uiEXT)(unsigned red, unsigned green, unsigned blue);

typedef void __stdcall (*TglSecondaryColor3uivEXT)(const PGLuint v);

typedef void __stdcall (*TglSecondaryColor3usEXT)(Word red, Word green, Word blue);

typedef void __stdcall (*TglSecondaryColor3usvEXT)(const PGLushort v);

typedef void __stdcall (*TglSecondaryColorPointerEXT)(int size, unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglActiveStencilFaceEXT)(unsigned face);

typedef void __stdcall (*TglTexSubImage1DEXT)(unsigned target, int level, int xoffset, int width, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTexSubImage2DEXT)(unsigned target, int level, int xoffset, int yoffset, int width, int height, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTexImage3DEXT)(unsigned target, int level, unsigned internalformat, int width, int height, int depth, int border, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTexSubImage3DEXT)(unsigned target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, unsigned format, unsigned _type, const void * pixels);

typedef Byte __stdcall (*TglAreTexturesResidentEXT)(int n, const PGLuint textures, PGLBoolean residences);

typedef void __stdcall (*TglBindTextureEXT)(unsigned target, unsigned texture);

typedef void __stdcall (*TglDeleteTexturesEXT)(int n, const PGLuint textures);

typedef void __stdcall (*TglGenTexturesEXT)(int n, PGLuint textures);

typedef Byte __stdcall (*TglIsTextureEXT)(unsigned texture);

typedef void __stdcall (*TglPrioritizeTexturesEXT)(int n, const PGLuint textures, const PGLclampf priorities);

typedef void __stdcall (*TglTextureNormalEXT)(unsigned mode);

typedef void __stdcall (*TglArrayElementEXT)(int i);

typedef void __stdcall (*TglColorPointerEXT)(int size, unsigned _type, int stride, int count, const void * _pointer);

typedef void __stdcall (*TglDrawArraysEXT)(unsigned mode, int first, int count);

typedef void __stdcall (*TglEdgeFlagPointerEXT)(int stride, int count, const PGLBoolean _pointer);

typedef void __stdcall (*TglGetPointervEXT)(unsigned pname, void * params);

typedef void __stdcall (*TglIndexPointerEXT)(unsigned _type, int stride, int count, const void * _pointer);

typedef void __stdcall (*TglNormalPointerEXT)(unsigned _type, int stride, int count, const void * _pointer);

typedef void __stdcall (*TglTexCoordPointerEXT)(int size, unsigned _type, int stride, int count, const void * _pointer);

typedef void __stdcall (*TglVertexPointerEXT)(int size, unsigned _type, int stride, int count, const void * _pointer);

typedef void __stdcall (*TglBeginVertexShaderEXT)(void);

typedef void __stdcall (*TglEndVertexShaderEXT)(void);

typedef void __stdcall (*TglBindVertexShaderEXT)(unsigned id);

typedef unsigned __stdcall (*TglGenVertexShadersEXT)(unsigned range);

typedef void __stdcall (*TglDeleteVertexShaderEXT)(unsigned id);

typedef void __stdcall (*TglShaderOp1EXT)(unsigned op, unsigned res, unsigned arg1);

typedef void __stdcall (*TglShaderOp2EXT)(unsigned op, unsigned res, unsigned arg1, unsigned arg2);

typedef void __stdcall (*TglShaderOp3EXT)(unsigned op, unsigned res, unsigned arg1, unsigned arg2, unsigned arg3);

typedef void __stdcall (*TglSwizzleEXT)(unsigned res, unsigned _in, unsigned outX, unsigned outY, unsigned outZ, unsigned outW);

typedef void __stdcall (*TglWriteMaskEXT)(unsigned res, unsigned _in, unsigned outX, unsigned outY, unsigned outZ, unsigned outW);

typedef void __stdcall (*TglInsertComponentEXT)(unsigned res, unsigned src, unsigned num);

typedef void __stdcall (*TglExtractComponentEXT)(unsigned res, unsigned src, unsigned num);

typedef unsigned __stdcall (*TglGenSymbolsEXT)(unsigned datatype, unsigned storagetype, unsigned range, unsigned components);

typedef void __stdcall (*TglSetInvariantEXT)(unsigned id, unsigned _type, const void * addr);

typedef void __stdcall (*TglSetLocalConstantEXT)(unsigned id, unsigned _type, const void * addr);

typedef void __stdcall (*TglVariantbvEXT)(unsigned id, const PGLByte addr);

typedef void __stdcall (*TglVariantsvEXT)(unsigned id, const PGLShort addr);

typedef void __stdcall (*TglVariantivEXT)(unsigned id, const PGLInt addr);

typedef void __stdcall (*TglVariantfvEXT)(unsigned id, const PGLfloat addr);

typedef void __stdcall (*TglVariantdvEXT)(unsigned id, const PGLdouble addr);

typedef void __stdcall (*TglVariantubvEXT)(unsigned id, const PGLubyte addr);

typedef void __stdcall (*TglVariantusvEXT)(unsigned id, const PGLushort addr);

typedef void __stdcall (*TglVariantuivEXT)(unsigned id, const PGLuint addr);

typedef void __stdcall (*TglVariantPointerEXT)(unsigned id, unsigned _type, unsigned stride, const void * addr);

typedef void __stdcall (*TglEnableVariantClientStateEXT)(unsigned id);

typedef void __stdcall (*TglDisableVariantClientStateEXT)(unsigned id);

typedef unsigned __stdcall (*TglBindLightParameterEXT)(unsigned light, unsigned value);

typedef unsigned __stdcall (*TglBindMaterialParameterEXT)(unsigned face, unsigned value);

typedef unsigned __stdcall (*TglBindTexGenParameterEXT)(unsigned _unit, unsigned coord, unsigned value);

typedef unsigned __stdcall (*TglBindTextureUnitParameterEXT)(unsigned _unit, unsigned value);

typedef unsigned __stdcall (*TglBindParameterEXT)(unsigned value);

typedef Byte __stdcall (*TglIsVariantEnabledEXT)(unsigned id, unsigned cap);

typedef void __stdcall (*TglGetVariantBooleanvEXT)(unsigned id, unsigned value, PGLBoolean data);

typedef void __stdcall (*TglGetVariantIntegervEXT)(unsigned id, unsigned value, PGLInt data);

typedef void __stdcall (*TglGetVariantFloatvEXT)(unsigned id, unsigned value, PGLfloat data);

typedef void __stdcall (*TglGetVariantPointervEXT)(unsigned id, unsigned value, void * data);

typedef void __stdcall (*TglGetInvariantBooleanvEXT)(unsigned id, unsigned value, PGLBoolean data);

typedef void __stdcall (*TglGetInvariantIntegervEXT)(unsigned id, unsigned value, PGLInt data);

typedef void __stdcall (*TglGetInvariantFloatvEXT)(unsigned id, unsigned value, PGLfloat data);

typedef void __stdcall (*TglGetLocalConstantBooleanvEXT)(unsigned id, unsigned value, PGLBoolean data);

typedef void __stdcall (*TglGetLocalConstantIntegervEXT)(unsigned id, unsigned value, PGLInt data);

typedef void __stdcall (*TglGetLocalConstantFloatvEXT)(unsigned id, unsigned value, PGLfloat data);

typedef void __stdcall (*TglVertexWeightfEXT)(float weight);

typedef void __stdcall (*TglVertexWeightfvEXT)(const PGLfloat weight);

typedef void __stdcall (*TglVertexWeightPointerEXT)(int size, unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglStencilClearTagEXT)(int stencilTagBits, unsigned stencilClearTag);

typedef void __stdcall (*TglImageTransformParameteriHP)(unsigned target, unsigned pname, int param);

typedef void __stdcall (*TglImageTransformParameterfHP)(unsigned target, unsigned pname, float param);

typedef void __stdcall (*TglImageTransformParameterivHP)(unsigned target, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglImageTransformParameterfvHP)(unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglGetImageTransformParameterivHP)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetImageTransformParameterfvHP)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglDepthBoundsEXT)(double zmin, double zmax);

typedef void __stdcall (*TglBlendEquationSeparateEXT)(unsigned modeRGB, unsigned modeAlpha);

typedef void __stdcall (*TglMultiModeDrawArraysIBM)(unsigned mode, const PGLInt first, const PGLSizei count, int primcount, int modestride);

typedef void __stdcall (*TglMultiModeDrawElementsIBM)(const PGLenum mode, const PGLSizei count, unsigned _type, const void * indices, int primcount, int modestride);

typedef void __stdcall (*TglColorPointerListIBM)(int size, unsigned _type, int stride, const void * _pointer, int ptrstride);

typedef void __stdcall (*TglSecondaryColorPointerListIBM)(int size, unsigned _type, int stride, const void * _pointer, int ptrstride);

typedef void __stdcall (*TglEdgeFlagPointerListIBM)(int stride, const PGLBoolean _pointer, int ptrstride);

typedef void __stdcall (*TglFogCoordPointerListIBM)(unsigned _type, int stride, const void * _pointer, int ptrstride);

typedef void __stdcall (*TglIndexPointerListIBM)(unsigned _type, int stride, const void * _pointer, int ptrstride);

typedef void __stdcall (*TglNormalPointerListIBM)(unsigned _type, int stride, const void * _pointer, int ptrstride);

typedef void __stdcall (*TglTexCoordPointerListIBM)(int size, unsigned _type, int stride, const void * _pointer, int ptrstride);

typedef void __stdcall (*TglVertexPointerListIBM)(int size, unsigned _type, int stride, const void * _pointer, int ptrstride);

typedef void __stdcall (*TglBlendFuncSeparateINGR)(unsigned sfactorRGB, unsigned dfactorRGB, unsigned sfactorAlpha, unsigned dfactorAlpha);

typedef void __stdcall (*TglVertexPointervINTEL)(int size, unsigned _type, const void * _pointer);

typedef void __stdcall (*TglNormalPointervINTEL)(unsigned _type, const void * _pointer);

typedef void __stdcall (*TglColorPointervINTEL)(int size, unsigned _type, const void * _pointer);

typedef void __stdcall (*TglTexCoordPointervINTEL)(int size, unsigned _type, const void * _pointer);

typedef void __stdcall (*TglResizeBuffersMESA)(void);

typedef void __stdcall (*TglWindowPos2dMESA)(double x, double y);

typedef void __stdcall (*TglWindowPos2dvMESA)(const PGLdouble v);

typedef void __stdcall (*TglWindowPos2fMESA)(float x, float y);

typedef void __stdcall (*TglWindowPos2fvMESA)(const PGLfloat v);

typedef void __stdcall (*TglWindowPos2iMESA)(int x, int y);

typedef void __stdcall (*TglWindowPos2ivMESA)(const PGLInt v);

typedef void __stdcall (*TglWindowPos2sMESA)(short x, short y);

typedef void __stdcall (*TglWindowPos2svMESA)(const PGLShort v);

typedef void __stdcall (*TglWindowPos3dMESA)(double x, double y, double z);

typedef void __stdcall (*TglWindowPos3dvMESA)(const PGLdouble v);

typedef void __stdcall (*TglWindowPos3fMESA)(float x, float y, float z);

typedef void __stdcall (*TglWindowPos3fvMESA)(const PGLfloat v);

typedef void __stdcall (*TglWindowPos3iMESA)(int x, int y, int z);

typedef void __stdcall (*TglWindowPos3ivMESA)(const PGLInt v);

typedef void __stdcall (*TglWindowPos3sMESA)(short x, short y, short z);

typedef void __stdcall (*TglWindowPos3svMESA)(const PGLShort v);

typedef void __stdcall (*TglWindowPos4dMESA)(double x, double y, double z, double w);

typedef void __stdcall (*TglWindowPos4dvMESA)(const PGLdouble v);

typedef void __stdcall (*TglWindowPos4fMESA)(float x, float y, float z, float w);

typedef void __stdcall (*TglWindowPos4fvMESA)(const PGLfloat v);

typedef void __stdcall (*TglWindowPos4iMESA)(int x, int y, int z, int w);

typedef void __stdcall (*TglWindowPos4ivMESA)(const PGLInt v);

typedef void __stdcall (*TglWindowPos4sMESA)(short x, short y, short z, short w);

typedef void __stdcall (*TglWindowPos4svMESA)(const PGLShort v);

typedef void __stdcall (*TglMapControlPointsNV)(unsigned target, unsigned index, unsigned _type, int ustride, int vstride, int uorder, int vorder, Byte _packed, const void * points);

typedef void __stdcall (*TglMapParameterivNV)(unsigned target, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglMapParameterfvNV)(unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglGetMapControlPointsNV)(unsigned target, unsigned index, unsigned _type, int ustride, int vstride, Byte _packed, void * points);

typedef void __stdcall (*TglGetMapParameterivNV)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetMapParameterfvNV)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetMapAttribParameterivNV)(unsigned target, unsigned index, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetMapAttribParameterfvNV)(unsigned target, unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglEvalMapsNV)(unsigned target, unsigned mode);

typedef void __stdcall (*TglDeleteFencesNV)(int n, const PGLuint fences);

typedef void __stdcall (*TglGenFencesNV)(int n, PGLuint fences);

typedef Byte __stdcall (*TglIsFenceNV)(unsigned fence);

typedef Byte __stdcall (*TglTestFenceNV)(unsigned fence);

typedef void __stdcall (*TglGetFenceivNV)(unsigned fence, unsigned pname, PGLInt params);

typedef void __stdcall (*TglFinishFenceNV)(unsigned fence);

typedef void __stdcall (*TglSetFenceNV)(unsigned fence, unsigned condition);

typedef void __stdcall (*TglProgramNamedParameter4fNV)(unsigned id, int len, const PGLubyte name, float x, float y, float z, float w);

typedef void __stdcall (*TglProgramNamedParameter4dNV)(unsigned id, int len, const PGLubyte name, double x, double y, double z, double w);

typedef void __stdcall (*TglProgramNamedParameter4fvNV)(unsigned id, int len, const PGLubyte name, const PGLfloat v);

typedef void __stdcall (*TglProgramNamedParameter4dvNV)(unsigned id, int len, const PGLubyte name, const PGLdouble v);

typedef void __stdcall (*TglGetProgramNamedParameterfvNV)(unsigned id, int len, const PGLubyte name, PGLfloat params);

typedef void __stdcall (*TglGetProgramNamedParameterdvNV)(unsigned id, int len, const PGLubyte name, PGLdouble params);

typedef void __stdcall (*TglVertex2hNV)(Word x, Word y);

typedef void __stdcall (*TglVertex2hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglVertex3hNV)(Word x, Word y, Word z);

typedef void __stdcall (*TglVertex3hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglVertex4hNV)(Word x, Word y, Word z, Word w);

typedef void __stdcall (*TglVertex4hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglNormal3hNV)(Word nx, Word ny, Word nz);

typedef void __stdcall (*TglNormal3hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglColor3hNV)(Word red, Word green, Word blue);

typedef void __stdcall (*TglColor3hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglColor4hNV)(Word red, Word green, Word blue, Word alpha);

typedef void __stdcall (*TglColor4hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglTexCoord1hNV)(Word s);

typedef void __stdcall (*TglTexCoord1hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglTexCoord2hNV)(Word s, Word t);

typedef void __stdcall (*TglTexCoord2hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglTexCoord3hNV)(Word s, Word t, Word r);

typedef void __stdcall (*TglTexCoord3hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglTexCoord4hNV)(Word s, Word t, Word r, Word q);

typedef void __stdcall (*TglTexCoord4hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglMultiTexCoord1hNV)(unsigned target, Word s);

typedef void __stdcall (*TglMultiTexCoord1hvNV)(unsigned target, const PGLhalfNV v);

typedef void __stdcall (*TglMultiTexCoord2hNV)(unsigned target, Word s, Word t);

typedef void __stdcall (*TglMultiTexCoord2hvNV)(unsigned target, const PGLhalfNV v);

typedef void __stdcall (*TglMultiTexCoord3hNV)(unsigned target, Word s, Word t, Word r);

typedef void __stdcall (*TglMultiTexCoord3hvNV)(unsigned target, const PGLhalfNV v);

typedef void __stdcall (*TglMultiTexCoord4hNV)(unsigned target, Word s, Word t, Word r, Word q);

typedef void __stdcall (*TglMultiTexCoord4hvNV)(unsigned target, const PGLhalfNV v);

typedef void __stdcall (*TglFogCoordhNV)(Word fog);

typedef void __stdcall (*TglFogCoordhvNV)(const PGLhalfNV fog);

typedef void __stdcall (*TglSecondaryColor3hNV)(Word red, Word green, Word blue);

typedef void __stdcall (*TglSecondaryColor3hvNV)(const PGLhalfNV v);

typedef void __stdcall (*TglVertexWeighthNV)(Word weight);

typedef void __stdcall (*TglVertexWeighthvNV)(const PGLhalfNV weight);

typedef void __stdcall (*TglVertexAttrib1hNV)(unsigned index, Word x);

typedef void __stdcall (*TglVertexAttrib1hvNV)(unsigned index, const PGLhalfNV v);

typedef void __stdcall (*TglVertexAttrib2hNV)(unsigned index, Word x, Word y);

typedef void __stdcall (*TglVertexAttrib2hvNV)(unsigned index, const PGLhalfNV v);

typedef void __stdcall (*TglVertexAttrib3hNV)(unsigned index, Word x, Word y, Word z);

typedef void __stdcall (*TglVertexAttrib3hvNV)(unsigned index, const PGLhalfNV v);

typedef void __stdcall (*TglVertexAttrib4hNV)(unsigned index, Word x, Word y, Word z, Word w);

typedef void __stdcall (*TglVertexAttrib4hvNV)(unsigned index, const PGLhalfNV v);

typedef void __stdcall (*TglVertexAttribs1hvNV)(unsigned index, int n, const PGLhalfNV v);

typedef void __stdcall (*TglVertexAttribs2hvNV)(unsigned index, int n, const PGLhalfNV v);

typedef void __stdcall (*TglVertexAttribs3hvNV)(unsigned index, int n, const PGLhalfNV v);

typedef void __stdcall (*TglVertexAttribs4hvNV)(unsigned index, int n, const PGLhalfNV v);

typedef void __stdcall (*TglGenOcclusionQueriesNV)(int n, PGLuint ids);

typedef void __stdcall (*TglDeleteOcclusionQueriesNV)(int n, const PGLuint ids);

typedef Byte __stdcall (*TglIsOcclusionQueryNV)(unsigned id);

typedef void __stdcall (*TglBeginOcclusionQueryNV)(unsigned id);

typedef void __stdcall (*TglEndOcclusionQueryNV)(void);

typedef void __stdcall (*TglGetOcclusionQueryivNV)(unsigned id, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetOcclusionQueryuivNV)(unsigned id, unsigned pname, PGLuint params);

typedef void __stdcall (*TglPixelDataRangeNV)(unsigned target, int length, void * _pointer);

typedef void __stdcall (*TglFlushPixelDataRangeNV)(unsigned target);

typedef void __stdcall (*TglPointParameteriNV)(unsigned pname, int param);

typedef void __stdcall (*TglPointParameterivNV)(unsigned pname, const PGLInt params);

typedef void __stdcall (*TglPrimitiveRestartNV)(void);

typedef void __stdcall (*TglPrimitiveRestartIndexNV)(unsigned index);

typedef void __stdcall (*TglCombinerParameterfvNV)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglCombinerParameterfNV)(unsigned pname, float param);

typedef void __stdcall (*TglCombinerParameterivNV)(unsigned pname, const PGLInt params);

typedef void __stdcall (*TglCombinerParameteriNV)(unsigned pname, int param);

typedef void __stdcall (*TglCombinerInputNV)(unsigned stage, unsigned portion, unsigned variable, unsigned input, unsigned mapping, unsigned componentUsage);

typedef void __stdcall (*TglCombinerOutputNV)(unsigned stage, unsigned portion, unsigned abOutput, unsigned cdOutput, unsigned sumOutput, unsigned scale, unsigned bias, Byte abDotProduct, Byte cdDotProduct, Byte muxSum);

typedef void __stdcall (*TglFinalCombinerInputNV)(unsigned variable, unsigned input, unsigned mapping, unsigned componentUsage);

typedef void __stdcall (*TglGetCombinerInputParameterfvNV)(unsigned stage, unsigned portion, unsigned variable, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetCombinerInputParameterivNV)(unsigned stage, unsigned portion, unsigned variable, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetCombinerOutputParameterfvNV)(unsigned stage, unsigned portion, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetCombinerOutputParameterivNV)(unsigned stage, unsigned portion, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetFinalCombinerInputParameterfvNV)(unsigned variable, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetFinalCombinerInputParameterivNV)(unsigned variable, unsigned pname, PGLInt params);

typedef void __stdcall (*TglCombinerStageParameterfvNV)(unsigned stage, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglGetCombinerStageParameterfvNV)(unsigned stage, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglFlushVertexArrayRangeNV)(void);

typedef void __stdcall (*TglVertexArrayRangeNV)(int length, const void * _pointer);

typedef Byte __stdcall (*TglAreProgramsResidentNV)(int n, const PGLuint programs, PGLBoolean residences);

typedef void __stdcall (*TglBindProgramNV)(unsigned target, unsigned id);

typedef void __stdcall (*TglDeleteProgramsNV)(int n, const PGLuint programs);

typedef void __stdcall (*TglExecuteProgramNV)(unsigned target, unsigned id, const PGLfloat params);

typedef void __stdcall (*TglGenProgramsNV)(int n, PGLuint programs);

typedef void __stdcall (*TglGetProgramParameterdvNV)(unsigned target, unsigned index, unsigned pname, PGLdouble params);

typedef void __stdcall (*TglGetProgramParameterfvNV)(unsigned target, unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetProgramivNV)(unsigned id, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetProgramStringNV)(unsigned id, unsigned pname, PGLubyte _program);

typedef void __stdcall (*TglGetTrackMatrixivNV)(unsigned target, unsigned address, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetVertexAttribdvNV)(unsigned index, unsigned pname, PGLdouble params);

typedef void __stdcall (*TglGetVertexAttribfvNV)(unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetVertexAttribivNV)(unsigned index, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetVertexAttribPointervNV)(unsigned index, unsigned pname, void * _pointer);

typedef Byte __stdcall (*TglIsProgramNV)(unsigned id);

typedef void __stdcall (*TglLoadProgramNV)(unsigned target, unsigned id, int len, const PGLubyte _program);

typedef void __stdcall (*TglProgramParameter4dNV)(unsigned target, unsigned index, double x, double y, double z, double w);

typedef void __stdcall (*TglProgramParameter4dvNV)(unsigned target, unsigned index, const PGLdouble v);

typedef void __stdcall (*TglProgramParameter4fNV)(unsigned target, unsigned index, float x, float y, float z, float w);

typedef void __stdcall (*TglProgramParameter4fvNV)(unsigned target, unsigned index, const PGLfloat v);

typedef void __stdcall (*TglProgramParameters4dvNV)(unsigned target, unsigned index, unsigned count, const PGLdouble v);

typedef void __stdcall (*TglProgramParameters4fvNV)(unsigned target, unsigned index, unsigned count, const PGLfloat v);

typedef void __stdcall (*TglRequestResidentProgramsNV)(int n, const PGLuint programs);

typedef void __stdcall (*TglTrackMatrixNV)(unsigned target, unsigned address, unsigned matrix, unsigned transform);

typedef void __stdcall (*TglVertexAttribPointerNV)(unsigned index, int fsize, unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglVertexAttrib1dNV)(unsigned index, double x);

typedef void __stdcall (*TglVertexAttrib1dvNV)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib1fNV)(unsigned index, float x);

typedef void __stdcall (*TglVertexAttrib1fvNV)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib1sNV)(unsigned index, short x);

typedef void __stdcall (*TglVertexAttrib1svNV)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib2dNV)(unsigned index, double x, double y);

typedef void __stdcall (*TglVertexAttrib2dvNV)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib2fNV)(unsigned index, float x, float y);

typedef void __stdcall (*TglVertexAttrib2fvNV)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib2sNV)(unsigned index, short x, short y);

typedef void __stdcall (*TglVertexAttrib2svNV)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib3dNV)(unsigned index, double x, double y, double z);

typedef void __stdcall (*TglVertexAttrib3dvNV)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib3fNV)(unsigned index, float x, float y, float z);

typedef void __stdcall (*TglVertexAttrib3fvNV)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib3sNV)(unsigned index, short x, short y, short z);

typedef void __stdcall (*TglVertexAttrib3svNV)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib4dNV)(unsigned index, double x, double y, double z, double w);

typedef void __stdcall (*TglVertexAttrib4dvNV)(unsigned index, const PGLdouble v);

typedef void __stdcall (*TglVertexAttrib4fNV)(unsigned index, float x, float y, float z, float w);

typedef void __stdcall (*TglVertexAttrib4fvNV)(unsigned index, const PGLfloat v);

typedef void __stdcall (*TglVertexAttrib4sNV)(unsigned index, short x, short y, short z, short w);

typedef void __stdcall (*TglVertexAttrib4svNV)(unsigned index, const PGLShort v);

typedef void __stdcall (*TglVertexAttrib4ubNV)(unsigned index, Byte x, Byte y, Byte z, Byte w);

typedef void __stdcall (*TglVertexAttrib4ubvNV)(unsigned index, const PGLubyte v);

typedef void __stdcall (*TglVertexAttribs1dvNV)(unsigned index, int count, const PGLdouble v);

typedef void __stdcall (*TglVertexAttribs1fvNV)(unsigned index, int count, const PGLfloat v);

typedef void __stdcall (*TglVertexAttribs1svNV)(unsigned index, int count, const PGLShort v);

typedef void __stdcall (*TglVertexAttribs2dvNV)(unsigned index, int count, const PGLdouble v);

typedef void __stdcall (*TglVertexAttribs2fvNV)(unsigned index, int count, const PGLfloat v);

typedef void __stdcall (*TglVertexAttribs2svNV)(unsigned index, int count, const PGLShort v);

typedef void __stdcall (*TglVertexAttribs3dvNV)(unsigned index, int count, const PGLdouble v);

typedef void __stdcall (*TglVertexAttribs3fvNV)(unsigned index, int count, const PGLfloat v);

typedef void __stdcall (*TglVertexAttribs3svNV)(unsigned index, int count, const PGLShort v);

typedef void __stdcall (*TglVertexAttribs4dvNV)(unsigned index, int count, const PGLdouble v);

typedef void __stdcall (*TglVertexAttribs4fvNV)(unsigned index, int count, const PGLfloat v);

typedef void __stdcall (*TglVertexAttribs4svNV)(unsigned index, int count, const PGLShort v);

typedef void __stdcall (*TglVertexAttribs4ubvNV)(unsigned index, int count, const PGLubyte v);

typedef void __stdcall (*TglHintPGI)(unsigned target, int mode);

typedef void __stdcall (*TglDetailTexFuncSGIS)(unsigned target, int n, const PGLfloat points);

typedef void __stdcall (*TglGetDetailTexFuncSGIS)(unsigned target, PGLfloat points);

typedef void __stdcall (*TglFogFuncSGIS)(int n, const PGLfloat points);

typedef void __stdcall (*TglGetFogFuncSGIS)(PGLfloat points);

typedef void __stdcall (*TglSampleMaskSGIS)(float value, Byte invert);

typedef void __stdcall (*TglSamplePatternSGIS)(unsigned pattern);

typedef void __stdcall (*TglPixelTexGenParameteriSGIS)(unsigned pname, int param);

typedef void __stdcall (*TglPixelTexGenParameterivSGIS)(unsigned pname, const PGLInt params);

typedef void __stdcall (*TglPixelTexGenParameterfSGIS)(unsigned pname, float param);

typedef void __stdcall (*TglPixelTexGenParameterfvSGIS)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglGetPixelTexGenParameterivSGIS)(unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetPixelTexGenParameterfvSGIS)(unsigned pname, PGLfloat params);

typedef void __stdcall (*TglPointParameterfSGIS)(unsigned pname, float param);

typedef void __stdcall (*TglPointParameterfvSGIS)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglSharpenTexFuncSGIS)(unsigned target, int n, const PGLfloat points);

typedef void __stdcall (*TglGetSharpenTexFuncSGIS)(unsigned target, PGLfloat points);

typedef void __stdcall (*TglTexImage4DSGIS)(unsigned target, int level, unsigned internalformat, int width, int height, int depth, int size4d, int border, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTexSubImage4DSGIS)(unsigned target, int level, int xoffset, int yoffset, int zoffset, int woffset, int width, int height, int depth, int size4d, unsigned format, unsigned _type, const void * pixels);

typedef void __stdcall (*TglTextureColorMaskSGIS)(Byte red, Byte green, Byte blue, Byte alpha);

typedef void __stdcall (*TglGetTexFilterFuncSGIS)(unsigned target, unsigned filter, PGLfloat weights);

typedef void __stdcall (*TglTexFilterFuncSGIS)(unsigned target, unsigned filter, int n, const PGLfloat weights);

typedef void __stdcall (*TglAsyncMarkerSGIX)(unsigned marker);

typedef int __stdcall (*TglFinishAsyncSGIX)(PGLuint markerp);

typedef int __stdcall (*TglPollAsyncSGIX)(PGLuint markerp);

typedef unsigned __stdcall (*TglGenAsyncMarkersSGIX)(int range);

typedef void __stdcall (*TglDeleteAsyncMarkersSGIX)(unsigned marker, int range);

typedef Byte __stdcall (*TglIsAsyncMarkerSGIX)(unsigned marker);

typedef void __stdcall (*TglFlushRasterSGIX)(void);

typedef void __stdcall (*TglFragmentColorMaterialSGIX)(unsigned face, unsigned mode);

typedef void __stdcall (*TglFragmentLightfSGIX)(unsigned light, unsigned pname, float param);

typedef void __stdcall (*TglFragmentLightfvSGIX)(unsigned light, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglFragmentLightiSGIX)(unsigned light, unsigned pname, int param);

typedef void __stdcall (*TglFragmentLightivSGIX)(unsigned light, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglFragmentLightModelfSGIX)(unsigned pname, float param);

typedef void __stdcall (*TglFragmentLightModelfvSGIX)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglFragmentLightModeliSGIX)(unsigned pname, int param);

typedef void __stdcall (*TglFragmentLightModelivSGIX)(unsigned pname, const PGLInt params);

typedef void __stdcall (*TglFragmentMaterialfSGIX)(unsigned face, unsigned pname, float param);

typedef void __stdcall (*TglFragmentMaterialfvSGIX)(unsigned face, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglFragmentMaterialiSGIX)(unsigned face, unsigned pname, int param);

typedef void __stdcall (*TglFragmentMaterialivSGIX)(unsigned face, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglGetFragmentLightfvSGIX)(unsigned light, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetFragmentLightivSGIX)(unsigned light, unsigned pname, PGLInt params);

typedef void __stdcall (*TglGetFragmentMaterialfvSGIX)(unsigned face, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetFragmentMaterialivSGIX)(unsigned face, unsigned pname, PGLInt params);

typedef void __stdcall (*TglLightEnviSGIX)(unsigned pname, int param);

typedef void __stdcall (*TglFrameZoomSGIX)(int factor);

typedef void __stdcall (*TglIglooInterfaceSGIX)(unsigned pname, const void * params);

typedef int __stdcall (*TglGetInstrumentsSGIX)(void);

typedef void __stdcall (*TglInstrumentsBufferSGIX)(int size, PGLInt buffer);

typedef int __stdcall (*TglPollInstrumentsSGIX)(PGLInt marker_p);

typedef void __stdcall (*TglReadInstrumentsSGIX)(int marker);

typedef void __stdcall (*TglStartInstrumentsSGIX)(void);

typedef void __stdcall (*TglStopInstrumentsSGIX)(int marker);

typedef void __stdcall (*TglGetListParameterfvSGIX)(unsigned list, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetListParameterivSGIX)(unsigned list, unsigned pname, PGLInt params);

typedef void __stdcall (*TglListParameterfSGIX)(unsigned list, unsigned pname, float param);

typedef void __stdcall (*TglListParameterfvSGIX)(unsigned list, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglListParameteriSGIX)(unsigned list, unsigned pname, int param);

typedef void __stdcall (*TglListParameterivSGIX)(unsigned list, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglPixelTexGenSGIX)(unsigned mode);

typedef void __stdcall (*TglDeformationMap3dSGIX)(unsigned target, double u1, double u2, int ustride, int uorder, double v1, double v2, int vstride, int vorder, double w1, double w2, int wstride, int worder, const PGLdouble points);

typedef void __stdcall (*TglDeformationMap3fSGIX)(unsigned target, float u1, float u2, int ustride, int uorder, float v1, float v2, int vstride, int vorder, float w1, float w2, int wstride, int worder, const PGLfloat points);

typedef void __stdcall (*TglDeformSGIX)(unsigned mask);

typedef void __stdcall (*TglLoadIdentityDeformationMapSGIX)(unsigned mask);

typedef void __stdcall (*TglReferencePlaneSGIX)(const PGLdouble equation);

typedef void __stdcall (*TglSpriteParameterfSGIX)(unsigned pname, float param);

typedef void __stdcall (*TglSpriteParameterfvSGIX)(unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglSpriteParameteriSGIX)(unsigned pname, int param);

typedef void __stdcall (*TglSpriteParameterivSGIX)(unsigned pname, const PGLInt params);

typedef void __stdcall (*TglTagSampleBufferSGIX)(void);

typedef void __stdcall (*TglColorTableSGI)(unsigned target, unsigned internalformat, int width, unsigned format, unsigned _type, const void * table);

typedef void __stdcall (*TglColorTableParameterfvSGI)(unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*TglColorTableParameterivSGI)(unsigned target, unsigned pname, const PGLInt params);

typedef void __stdcall (*TglCopyColorTableSGI)(unsigned target, unsigned internalformat, int x, int y, int width);

typedef void __stdcall (*TglGetColorTableSGI)(unsigned target, unsigned format, unsigned _type, void * table);

typedef void __stdcall (*TglGetColorTableParameterfvSGI)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*TglGetColorTableParameterivSGI)(unsigned target, unsigned pname, PGLInt params);

typedef void __stdcall (*TglFinishTextureSUNX)(void);

typedef void __stdcall (*TglGlobalAlphaFactorbSUN)(Shortint factor);

typedef void __stdcall (*TglGlobalAlphaFactorsSUN)(short factor);

typedef void __stdcall (*TglGlobalAlphaFactoriSUN)(int factor);

typedef void __stdcall (*TglGlobalAlphaFactorfSUN)(float factor);

typedef void __stdcall (*TglGlobalAlphaFactordSUN)(double factor);

typedef void __stdcall (*TglGlobalAlphaFactorubSUN)(Byte factor);

typedef void __stdcall (*TglGlobalAlphaFactorusSUN)(Word factor);

typedef void __stdcall (*TglGlobalAlphaFactoruiSUN)(unsigned factor);

typedef void __stdcall (*TglDrawMeshArraysSUN)(unsigned mode, int first, int count, int width);

typedef void __stdcall (*TglReplacementCodeuiSUN)(unsigned code);

typedef void __stdcall (*TglReplacementCodeusSUN)(Word code);

typedef void __stdcall (*TglReplacementCodeubSUN)(Byte code);

typedef void __stdcall (*TglReplacementCodeuivSUN)(const PGLuint code);

typedef void __stdcall (*TglReplacementCodeusvSUN)(const PGLushort code);

typedef void __stdcall (*TglReplacementCodeubvSUN)(const PGLubyte code);

typedef void __stdcall (*TglReplacementCodePointerSUN)(unsigned _type, int stride, const void * _pointer);

typedef void __stdcall (*TglColor4ubVertex2fSUN)(Byte r, Byte g, Byte b, Byte a, float x, float y);

typedef void __stdcall (*TglColor4ubVertex2fvSUN)(const PGLubyte c, const PGLfloat v);

typedef void __stdcall (*TglColor4ubVertex3fSUN)(Byte r, Byte g, Byte b, Byte a, float x, float y, float z);

typedef void __stdcall (*TglColor4ubVertex3fvSUN)(const PGLubyte c, const PGLfloat v);

typedef void __stdcall (*TglColor3fVertex3fSUN)(float r, float g, float b, float x, float y, float z);

typedef void __stdcall (*TglColor3fVertex3fvSUN)(const PGLfloat c, const PGLfloat v);

typedef void __stdcall (*TglNormal3fVertex3fSUN)(float nx, float ny, float nz, float x, float y, float z);

typedef void __stdcall (*TglNormal3fVertex3fvSUN)(const PGLfloat n, const PGLfloat v);

typedef void __stdcall (*TglColor4fNormal3fVertex3fSUN)(float r, float g, float b, float a, float nx, float ny, float nz, float x, float y, float z);

typedef void __stdcall (*TglColor4fNormal3fVertex3fvSUN)(const PGLfloat c, const PGLfloat n, const PGLfloat v);

typedef void __stdcall (*TglTexCoord2fVertex3fSUN)(float s, float t, float x, float y, float z);

typedef void __stdcall (*TglTexCoord2fVertex3fvSUN)(const PGLfloat tc, const PGLfloat v);

typedef void __stdcall (*TglTexCoord4fVertex4fSUN)(float s, float t, float p, float q, float x, float y, float z, float w);

typedef void __stdcall (*TglTexCoord4fVertex4fvSUN)(const PGLfloat tc, const PGLfloat v);

typedef void __stdcall (*TglTexCoord2fColor4ubVertex3fSUN)(float s, float t, Byte r, Byte g, Byte b, Byte a, float x, float y, float z);

typedef void __stdcall (*TglTexCoord2fColor4ubVertex3fvSUN)(const PGLfloat tc, const PGLubyte c, const PGLfloat v);

typedef void __stdcall (*TglTexCoord2fColor3fVertex3fSUN)(float s, float t, float r, float g, float b, float x, float y, float z);

typedef void __stdcall (*TglTexCoord2fColor3fVertex3fvSUN)(const PGLfloat tc, const PGLfloat c, const PGLfloat v);

typedef void __stdcall (*TglTexCoord2fNormal3fVertex3fSUN)(float s, float t, float nx, float ny, float nz, float x, float y, float z);

typedef void __stdcall (*TglTexCoord2fNormal3fVertex3fvSUN)(const PGLfloat tc, const PGLfloat n, const PGLfloat v);

typedef void __stdcall (*TglTexCoord2fColor4fNormal3fVertex3fSUN)(float s, float t, float r, float g, float b, float a, float nx, float ny, float nz, float x, float y, float z);

typedef void __stdcall (*TglTexCoord2fColor4fNormal3fVertex3fvSUN)(const PGLfloat tc, const PGLfloat c, const PGLfloat n, const PGLfloat v);

typedef void __stdcall (*TglTexCoord4fColor4fNormal3fVertex4fSUN)(float s, float t, float p, float q, float r, float g, float b, float a, float nx, float ny, float nz, float x, float y, float z, float w);

typedef void __stdcall (*TglTexCoord4fColor4fNormal3fVertex4fvSUN)(const PGLfloat tc, const PGLfloat c, const PGLfloat n, const PGLfloat v);

typedef void __stdcall (*TglReplacementCodeuiVertex3fSUN)(unsigned rc, float x, float y, float z);

typedef void __stdcall (*TglReplacementCodeuiVertex3fvSUN)(const PGLuint rc, const PGLfloat v);

typedef void __stdcall (*TglReplacementCodeuiColor4ubVertex3fSUN)(unsigned rc, Byte r, Byte g, Byte b, Byte a, float x, float y, float z);

typedef void __stdcall (*TglReplacementCodeuiColor4ubVertex3fvSUN)(const PGLuint rc, const PGLubyte c, const PGLfloat v);

typedef void __stdcall (*TglReplacementCodeuiColor3fVertex3fSUN)(unsigned rc, float r, float g, float b, float x, float y, float z);

typedef void __stdcall (*TglReplacementCodeuiColor3fVertex3fvSUN)(const PGLuint rc, const PGLfloat c, const PGLfloat v);

typedef void __stdcall (*TglReplacementCodeuiNormal3fVertex3fSUN)(unsigned rc, float nx, float ny, float nz, float x, float y, float z);

typedef void __stdcall (*TglReplacementCodeuiNormal3fVertex3fvSUN)(const PGLuint rc, const PGLfloat n, const PGLfloat v);

typedef void __stdcall (*TglReplacementCodeuiColor4fNormal3fVertex3fSUN)(unsigned rc, float r, float g, float b, float a, float nx, float ny, float nz, float x, float y, float z);

typedef void __stdcall (*TglReplacementCodeuiColor4fNormal3fVertex3fvSUN)(const PGLuint rc, const PGLfloat c, const PGLfloat n, const PGLfloat v);

typedef void __stdcall (*TglReplacementCodeuiTexCoord2fVertex3fSUN)(unsigned rc, float s, float t, float x, float y, float z);

typedef void __stdcall (*TglReplacementCodeuiTexCoord2fVertex3fvSUN)(const PGLuint rc, const PGLfloat tc, const PGLfloat v);

typedef void __stdcall (*TglReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)(unsigned rc, float s, float t, float nx, float ny, float nz, float x, float y, float z);

typedef void __stdcall (*TglReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)(const PGLuint rc, const PGLfloat tc, const PGLfloat n, const PGLfloat v);

typedef void __stdcall (*TglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)(unsigned rc, float s, float t, float r, float g, float b, float a, float nx, float ny, float nz, float x, float y, float z);

typedef void __stdcall (*TglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)(const PGLuint rc, const PGLfloat tc, const PGLfloat c, const PGLfloat n, const PGLfloat v);

typedef void * __stdcall (*TwglGetProcAddress)(char * ProcName);

typedef BOOL __stdcall (*TwglCopyContext)(HGLRC p1, HGLRC p2, unsigned p3);

typedef HGLRC __stdcall (*TwglCreateContext)(HDC DC);

typedef HGLRC __stdcall (*TwglCreateLayerContext)(HDC p1, int p2);

typedef BOOL __stdcall (*TwglDeleteContext)(HGLRC p1);

typedef BOOL __stdcall (*TwglDescribeLayerPlane)(HDC p1, int p2, int p3, unsigned p4, Windows::PLayerPlaneDescriptor p5);

typedef HGLRC __stdcall (*TwglGetCurrentContext)(void);

typedef HDC __stdcall (*TwglGetCurrentDC)(void);

typedef int __stdcall (*TwglGetLayerPaletteEntries)(HDC p1, int p2, int p3, int p4, void *pcr);

typedef BOOL __stdcall (*TwglMakeCurrent)(HDC DC, HGLRC p2);

typedef BOOL __stdcall (*TwglRealizeLayerPalette)(HDC p1, int p2, BOOL p3);

typedef int __stdcall (*TwglSetLayerPaletteEntries)(HDC p1, int p2, int p3, int p4, void *pcr);

typedef BOOL __stdcall (*TwglShareLists)(HGLRC p1, HGLRC p2);

typedef BOOL __stdcall (*TwglSwapLayerBuffers)(HDC p1, unsigned p2);

typedef unsigned __stdcall (*TwglSwapMultipleBuffers)(unsigned p1, const PWGLSwap p2);

typedef BOOL __stdcall (*TwglUseFontBitmapsA)(HDC DC, unsigned p2, unsigned p3, unsigned p4);

typedef BOOL __stdcall (*TwglUseFontBitmapsW)(HDC DC, unsigned p2, unsigned p3, unsigned p4);

typedef BOOL __stdcall (*TwglUseFontBitmaps)(HDC DC, unsigned p2, unsigned p3, unsigned p4);

typedef BOOL __stdcall (*TwglUseFontOutlinesA)(HDC p1, unsigned p2, unsigned p3, unsigned p4, float p5, float p6, int p7, Windows::PGlyphMetricsFloat p8);

typedef BOOL __stdcall (*TwglUseFontOutlinesW)(HDC p1, unsigned p2, unsigned p3, unsigned p4, float p5, float p6, int p7, Windows::PGlyphMetricsFloat p8);

typedef BOOL __stdcall (*TwglUseFontOutlines)(HDC p1, unsigned p2, unsigned p3, unsigned p4, float p5, float p6, int p7, Windows::PGlyphMetricsFloat p8);

typedef unsigned __stdcall (*TwglCreateBufferRegionARB)(HDC hDC, int iLayerPlane, unsigned uType);

typedef void __stdcall (*TwglDeleteBufferRegionARB)(unsigned hRegion);

typedef bool __stdcall (*TwglSaveBufferRegionARB)(unsigned hRegion, int x, int y, int width, int height);

typedef bool __stdcall (*TwglRestoreBufferRegionARB)(unsigned hRegion, int x, int y, int width, int height, int xSrc, int ySrc);

typedef char * __stdcall (*TwglGetExtensionsStringARB)(HDC hdc);

typedef bool __stdcall (*TwglMakeContextCurrentARB)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);

typedef HDC __stdcall (*TwglGetCurrentReadDCARB)(void);

typedef unsigned __stdcall (*TwglCreatePbufferARB)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const PGLInt piAttribList);

typedef HDC __stdcall (*TwglGetPbufferDCARB)(unsigned hPbuffer);

typedef int __stdcall (*TwglReleasePbufferDCARB)(unsigned hPbuffer, HDC hDC);

typedef bool __stdcall (*TwglDestroyPbufferARB)(unsigned hPbuffer);

typedef bool __stdcall (*TwglQueryPbufferARB)(unsigned hPbuffer, int iAttribute, PGLInt piValue);

typedef bool __stdcall (*TwglGetPixelFormatAttribivARB)(HDC hdc, int iPixelFormat, int iLayerPlane, unsigned nAttributes, const PGLInt piAttributes, PGLInt piValues);

typedef bool __stdcall (*TwglGetPixelFormatAttribfvARB)(HDC hdc, int iPixelFormat, int iLayerPlane, unsigned nAttributes, const PGLInt piAttributes, PGLfloat pfValues);

typedef BOOL __stdcall (*TwglChoosePixelFormatARB)(HDC hdc, const PGLInt piAttribIList, const PGLfloat pfAttribFList, unsigned nMaxFormats, PGLInt piFormats, PGLuint nNumFormats);

typedef void __stdcall (*TwglClampColorARB)(unsigned target, unsigned clamp);

typedef bool __stdcall (*TwglBindTexImageARB)(unsigned hPbuffer, int iBuffer);

typedef bool __stdcall (*TwglReleaseTexImageARB)(unsigned hPbuffer, int iBuffer);

typedef bool __stdcall (*TwglSetPbufferAttribARB)(unsigned hPbuffer, const PGLInt piAttribList);

typedef Byte __stdcall (*TwglCreateDisplayColorTableEXT)(Word id);

typedef Byte __stdcall (*TwglLoadDisplayColorTableEXT)(const PGLushort table, unsigned length);

typedef Byte __stdcall (*TwglBindDisplayColorTableEXT)(Word id);

typedef void __stdcall (*TwglDestroyDisplayColorTableEXT)(Word id);

typedef char * __stdcall (*TwglGetExtensionsStringEXT)(void);

typedef bool __stdcall (*TwglMakeContextCurrentEXT)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);

typedef HDC __stdcall (*TwglGetCurrentReadDCEXT)(void);

typedef unsigned __stdcall (*TwglCreatePbufferEXT)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const PGLInt piAttribList);

typedef HDC __stdcall (*TwglGetPbufferDCEXT)(unsigned hPbuffer);

typedef int __stdcall (*TwglReleasePbufferDCEXT)(unsigned hPbuffer, HDC hDC);

typedef bool __stdcall (*TwglDestroyPbufferEXT)(unsigned hPbuffer);

typedef bool __stdcall (*TwglQueryPbufferEXT)(unsigned hPbuffer, int iAttribute, PGLInt piValue);

typedef bool __stdcall (*TwglGetPixelFormatAttribivEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, unsigned nAttributes, PGLInt piAttributes, PGLInt piValues);

typedef bool __stdcall (*TwglGetPixelFormatAttribfvEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, unsigned nAttributes, PGLInt piAttributes, PGLfloat pfValues);

typedef bool __stdcall (*TwglChoosePixelFormatEXT)(HDC hdc, const PGLInt piAttribIList, const PGLfloat pfAttribFList, unsigned nMaxFormats, PGLInt piFormats, PGLuint nNumFormats);

typedef bool __stdcall (*TwglSwapIntervalEXT)(int interval);

typedef int __stdcall (*TwglGetSwapIntervalEXT)(void);

typedef bool __stdcall (*TwglGetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, PGLInt piValue);

typedef bool __stdcall (*TwglSetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, const PGLInt piValue);

typedef bool __stdcall (*TwglGetGammaTableParametersI3D)(HDC hDC, int iAttribute, PGLInt piValue);

typedef bool __stdcall (*TwglSetGammaTableParametersI3D)(HDC hDC, int iAttribute, const PGLInt piValue);

typedef bool __stdcall (*TwglGetGammaTableI3D)(HDC hDC, int iEntries, PGLushort puRed, PGLushort puGreen, PGLushort puBlue);

typedef bool __stdcall (*TwglSetGammaTableI3D)(HDC hDC, int iEntries, const PGLushort puRed, const PGLushort puGreen, const PGLushort puBlue);

typedef bool __stdcall (*TwglEnableGenlockI3D)(HDC hDC);

typedef bool __stdcall (*TwglDisableGenlockI3D)(HDC hDC);

typedef bool __stdcall (*TwglIsEnabledGenlockI3D)(HDC hDC, bool pFlag);

typedef bool __stdcall (*TwglGenlockSourceI3D)(HDC hDC, unsigned uSource);

typedef bool __stdcall (*TwglGetGenlockSourceI3D)(HDC hDC, PGLuint uSource);

typedef bool __stdcall (*TwglGenlockSourceEdgeI3D)(HDC hDC, unsigned uEdge);

typedef bool __stdcall (*TwglGetGenlockSourceEdgeI3D)(HDC hDC, PGLuint uEdge);

typedef bool __stdcall (*TwglGenlockSampleRateI3D)(HDC hDC, unsigned uRate);

typedef bool __stdcall (*TwglGetGenlockSampleRateI3D)(HDC hDC, PGLuint uRate);

typedef bool __stdcall (*TwglGenlockSourceDelayI3D)(HDC hDC, unsigned uDelay);

typedef bool __stdcall (*TwglGetGenlockSourceDelayI3D)(HDC hDC, PGLuint uDelay);

typedef bool __stdcall (*TwglQueryGenlockMaxSourceDelayI3D)(HDC hDC, PGLuint uMaxLineDelay, PGLuint uMaxPixelDelay);

typedef void * __stdcall (*TwglCreateImageBufferI3D)(HDC hDC, unsigned dwSize, unsigned uFlags);

typedef bool __stdcall (*TwglDestroyImageBufferI3D)(HDC hDC, void * pAddress);

typedef bool __stdcall (*TwglAssociateImageBufferEventsI3D)(HDC hDC, const unsigned pEvent, const void * pAddress, const PGLuint pSize, unsigned count);

typedef bool __stdcall (*TwglReleaseImageBufferEventsI3D)(HDC hDC, const void * pAddress, unsigned count);

typedef bool __stdcall (*TwglEnableFrameLockI3D)(void);

typedef bool __stdcall (*TwglDisableFrameLockI3D)(void);

typedef bool __stdcall (*TwglIsEnabledFrameLockI3D)(bool pFlag);

typedef bool __stdcall (*TwglQueryFrameLockMasterI3D)(bool pFlag);

typedef bool __stdcall (*TwglGetFrameUsageI3D)(PGLfloat pUsage);

typedef bool __stdcall (*TwglBeginFrameTrackingI3D)(void);

typedef bool __stdcall (*TwglEndFrameTrackingI3D)(void);

typedef bool __stdcall (*TwglQueryFrameTrackingI3D)(PGLuint pFrameCount, PGLuint pMissedFrames, PGLfloat pLastMissedUsage);

typedef void __stdcall (*TwglAllocateMemoryNV)(int size, float readfreq, float writefreq, float priority);

typedef void __stdcall (*TwglFreeMemoryNV)(void * _pointer);

typedef bool __stdcall (*TwglGetSyncValuesOML)(HDC hdc, PGLint64 ust, PGLint64 msc, PGLint64 sbc);

typedef bool __stdcall (*TwglGetMscRateOML)(HDC hdc, PGLInt numerator, PGLInt denominator);

typedef __int64 __stdcall (*TwglSwapBuffersMscOML)(HDC hdc, __int64 target_msc, __int64 divisor, __int64 remainder);

typedef __int64 __stdcall (*TwglSwapLayerBuffersMscOML)(HDC hdc, int fuPlanes, __int64 target_msc, __int64 divisor, __int64 remainder);

typedef bool __stdcall (*TwglWaitForMscOML)(HDC hdc, __int64 target_msc, __int64 divisor, __int64 remainder, PGLint64 ust, PGLint64 msc, PGLint64 sbc);

typedef bool __stdcall (*TwglWaitForSbcOML)(HDC hdc, __int64 target_sbc, PGLint64 ust, PGLint64 msc, PGLint64 sbc);

typedef void __stdcall (*TglDrawRangeElementsWIN)(unsigned mode, unsigned start, unsigned _end, int count, unsigned _type, const void * indices);

typedef void __stdcall (*TglAddSwapHintRectWIN)(int x, int y, int width, int height);

typedef char * __stdcall (*TgluErrorString)(unsigned errCode);

typedef char * __stdcall (*TgluGetString)(unsigned name);

typedef void __stdcall (*TgluOrtho2D)(double left, double right, double bottom, double top);

typedef void __stdcall (*TgluPerspective)(double fovy, double aspect, double zNear, double zFar);

typedef void __stdcall (*TgluPickMatrix)(double x, double y, double width, double height, int * viewport);

typedef void __stdcall (*TgluLookAt)(double eyex, double eyey, double eyez, double centerx, double centery, double centerz, double upx, double upy, double upz);

typedef int __stdcall (*TgluProject)(double objx, double objy, double objz,  * modelMatrix,  * projMatrix, int * viewport, PGLdouble winx, PGLdouble winy, PGLdouble winz);

typedef int __stdcall (*TgluUnProject)(double winx, double winy, double winz,  * modelMatrix,  * projMatrix, int * viewport, PGLdouble objx, PGLdouble objy, PGLdouble objz);

typedef int __stdcall (*TgluScaleImage)(unsigned format, int widthin, int heightin, unsigned typein, void * datain, int widthout, int heightout, unsigned typeout, void * dataout);

typedef int __stdcall (*TgluBuild1DMipmaps)(unsigned target, int components, int width, unsigned format, unsigned atype, void * data);

typedef int __stdcall (*TgluBuild2DMipmaps)(unsigned target, int components, int width, int height, unsigned format, unsigned atype, void * Data);

typedef PGLUQuadric __stdcall (*TgluNewQuadric)(void);

typedef void __stdcall (*TgluDeleteQuadric)(PGLUQuadric state);

typedef void __stdcall (*TgluQuadricNormals)(PGLUQuadric quadObject, unsigned normals);

typedef void __stdcall (*TgluQuadricTexture)(PGLUQuadric quadObject, Byte textureCoords);

typedef void __stdcall (*TgluQuadricOrientation)(PGLUQuadric quadObject, unsigned orientation);

typedef void __stdcall (*TgluQuadricDrawStyle)(PGLUQuadric quadObject, unsigned drawStyle);

typedef void __stdcall (*TgluCylinder)(PGLUQuadric quadObject, double baseRadius, double topRadius, double height, int slices, int stacks);

typedef void __stdcall (*TgluDisk)(PGLUQuadric quadObject, double innerRadius, double outerRadius, int slices, int loops);

typedef void __stdcall (*TgluPartialDisk)(PGLUQuadric quadObject, double innerRadius, double outerRadius, int slices, int loops, double startAngle, double sweepAngle);

typedef void __stdcall (*TgluSphere)(PGLUQuadric quadObject, double radius, int slices, int stacks);

typedef void __stdcall (*TgluQuadricCallback)(PGLUQuadric quadObject, unsigned which, TGLUQuadricErrorProc fn);

typedef PGLUTesselator __stdcall (*TgluNewTess)(void);

typedef void __stdcall (*TgluDeleteTess)(PGLUTesselator tess);

typedef void __stdcall (*TgluTessBeginPolygon)(PGLUTesselator tess, void * polygon_data);

typedef void __stdcall (*TgluTessBeginContour)(PGLUTesselator tess);

typedef void __stdcall (*TgluTessVertex)(PGLUTesselator tess, double * coords, void * data);

typedef void __stdcall (*TgluTessEndContour)(PGLUTesselator tess);

typedef void __stdcall (*TgluTessEndPolygon)(PGLUTesselator tess);

typedef void __stdcall (*TgluTessProperty)(PGLUTesselator tess, unsigned which, double value);

typedef void __stdcall (*TgluTessNormal)(PGLUTesselator tess, double x, double y, double z);

typedef void __stdcall (*TgluTessCallback)(PGLUTesselator tess, unsigned which, void * fn);

typedef void __stdcall (*TgluGetTessProperty)(PGLUTesselator tess, unsigned which, PGLdouble value);

typedef PGLUNurbs __stdcall (*TgluNewNurbsRenderer)(void);

typedef void __stdcall (*TgluDeleteNurbsRenderer)(PGLUNurbs nobj);

typedef void __stdcall (*TgluBeginSurface)(PGLUNurbs nobj);

typedef void __stdcall (*TgluBeginCurve)(PGLUNurbs nobj);

typedef void __stdcall (*TgluEndCurve)(PGLUNurbs nobj);

typedef void __stdcall (*TgluEndSurface)(PGLUNurbs nobj);

typedef void __stdcall (*TgluBeginTrim)(PGLUNurbs nobj);

typedef void __stdcall (*TgluEndTrim)(PGLUNurbs nobj);

typedef void __stdcall (*TgluPwlCurve)(PGLUNurbs nobj, int count, PGLfloat points, int stride, unsigned atype);

typedef void __stdcall (*TgluNurbsCurve)(PGLUNurbs nobj, int nknots, PGLfloat knot, int stride, PGLfloat ctlarray, int order, unsigned atype);

typedef void __stdcall (*TgluNurbsSurface)(PGLUNurbs nobj, int sknot_count, PGLfloat sknot, int tknot_count, PGLfloat tknot, int s_stride, int t_stride, PGLfloat ctlarray, int sorder, int torder, unsigned atype);

typedef void __stdcall (*TgluLoadSamplingMatrices)(PGLUNurbs nobj,  * modelMatrix,  * projMatrix, int * viewport);

typedef void __stdcall (*TgluNurbsProperty)(PGLUNurbs nobj, unsigned aproperty, float value);

typedef void __stdcall (*TgluGetNurbsProperty)(PGLUNurbs nobj, unsigned aproperty, PGLfloat value);

typedef void __stdcall (*TgluNurbsCallback)(PGLUNurbs nobj, unsigned which, TGLUNurbsErrorProc fn);

typedef void __stdcall (*TgluBeginPolygon)(PGLUTesselator tess);

typedef void __stdcall (*TgluNextContour)(PGLUTesselator tess, unsigned atype);

typedef void __stdcall (*TgluEndPolygon)(PGLUTesselator tess);

#pragma option push -b-
enum dglOpenGL__1 { opDoubleBuffered, opGDI, opStereo };
#pragma option pop

typedef Set<dglOpenGL__1, opDoubleBuffered, opStereo>  TRCOptions;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool GL_VERSION_1_0;
extern PACKAGE bool GL_VERSION_1_1;
extern PACKAGE bool GL_VERSION_1_2;
extern PACKAGE bool GL_VERSION_1_3;
extern PACKAGE bool GL_VERSION_1_4;
extern PACKAGE bool GL_VERSION_1_5;
extern PACKAGE bool GL_VERSION_2_0;
extern PACKAGE bool GLU_VERSION_1_1;
extern PACKAGE bool GLU_VERSION_1_2;
extern PACKAGE bool GLU_VERSION_1_3;
extern PACKAGE bool GL_3DFX_multisample;
extern PACKAGE bool GL_3DFX_tbuffer;
extern PACKAGE bool GL_3DFX_texture_compression_FXT1;
extern PACKAGE bool GL_APPLE_client_storage;
extern PACKAGE bool GL_APPLE_element_array;
extern PACKAGE bool GL_APPLE_fence;
extern PACKAGE bool GL_APPLE_specular_vector;
extern PACKAGE bool GL_APPLE_transform_hint;
extern PACKAGE bool GL_APPLE_vertex_array_object;
extern PACKAGE bool GL_APPLE_vertex_array_range;
extern PACKAGE bool GL_APPLE_ycbcr_422;
extern PACKAGE bool GL_ARB_depth_texture;
extern PACKAGE bool GL_ARB_fragment_program;
extern PACKAGE bool GL_ARB_imaging;
extern PACKAGE bool GL_ARB_matrix_palette;
extern PACKAGE bool GL_ARB_multisample;
extern PACKAGE bool GL_ARB_multitexture;
extern PACKAGE bool GL_ARB_point_parameters;
extern PACKAGE bool GL_ARB_shadow;
extern PACKAGE bool GL_ARB_shadow_ambient;
extern PACKAGE bool GL_ARB_texture_border_clamp;
extern PACKAGE bool GL_ARB_texture_compression;
extern PACKAGE bool GL_ARB_texture_cube_map;
extern PACKAGE bool GL_ARB_texture_env_add;
extern PACKAGE bool GL_ARB_texture_env_combine;
extern PACKAGE bool GL_ARB_texture_env_crossbar;
extern PACKAGE bool GL_ARB_texture_env_dot3;
extern PACKAGE bool GL_ARB_texture_mirrored_repeat;
extern PACKAGE bool GL_ARB_transpose_matrix;
extern PACKAGE bool GL_ARB_vertex_blend;
extern PACKAGE bool GL_ARB_vertex_buffer_object;
extern PACKAGE bool GL_ARB_vertex_program;
extern PACKAGE bool GL_ARB_window_pos;
extern PACKAGE bool GL_ARB_shader_objects;
extern PACKAGE bool GL_ARB_vertex_shader;
extern PACKAGE bool GL_ARB_fragment_shader;
extern PACKAGE bool GL_ARB_shading_language_100;
extern PACKAGE bool GL_ARB_occlusion_query;
extern PACKAGE bool GL_ARB_texture_non_power_of_two;
extern PACKAGE bool GL_ARB_point_sprite;
extern PACKAGE bool GL_ARB_fragment_program_shadow;
extern PACKAGE bool GL_ARB_draw_buffers;
extern PACKAGE bool GL_ARB_texture_rectangle;
extern PACKAGE bool GL_ARB_color_buffer_float;
extern PACKAGE bool GL_ARB_half_float_pixel;
extern PACKAGE bool GL_ARB_texture_float;
extern PACKAGE bool GL_ARB_pixel_buffer_object;
extern PACKAGE bool GL_ATI_draw_buffers;
extern PACKAGE bool GL_ATI_element_array;
extern PACKAGE bool GL_ATI_envmap_bumpmap;
extern PACKAGE bool GL_ATI_fragment_shader;
extern PACKAGE bool GL_ATI_map_object_buffer;
extern PACKAGE bool GL_ATI_pn_triangles;
extern PACKAGE bool GL_ATI_separate_stencil;
extern PACKAGE bool GL_ATI_text_fragment_shader;
extern PACKAGE bool GL_ATI_texture_env_combine3;
extern PACKAGE bool GL_ATI_texture_float;
extern PACKAGE bool GL_ATI_texture_mirror_once;
extern PACKAGE bool GL_ATI_vertex_array_object;
extern PACKAGE bool GL_ATI_vertex_attrib_array_object;
extern PACKAGE bool GL_ATI_vertex_streams;
extern PACKAGE bool GL_EXT_422_pixels;
extern PACKAGE bool GL_EXT_abgr;
extern PACKAGE bool GL_EXT_bgra;
extern PACKAGE bool GL_EXT_blend_color;
extern PACKAGE bool GL_EXT_blend_func_separate;
extern PACKAGE bool GL_EXT_blend_logic_op;
extern PACKAGE bool GL_EXT_blend_minmax;
extern PACKAGE bool GL_EXT_blend_subtract;
extern PACKAGE bool GL_EXT_clip_volume_hint;
extern PACKAGE bool GL_EXT_cmyka;
extern PACKAGE bool GL_EXT_color_matrix;
extern PACKAGE bool GL_EXT_color_subtable;
extern PACKAGE bool GL_EXT_compiled_vertex_array;
extern PACKAGE bool GL_EXT_convolution;
extern PACKAGE bool GL_EXT_coordinate_frame;
extern PACKAGE bool GL_EXT_copy_texture;
extern PACKAGE bool GL_EXT_cull_vertex;
extern PACKAGE bool GL_EXT_draw_range_elements;
extern PACKAGE bool GL_EXT_fog_coord;
extern PACKAGE bool GL_EXT_framebuffer_object;
extern PACKAGE bool GL_EXT_histogram;
extern PACKAGE bool GL_EXT_index_array_formats;
extern PACKAGE bool GL_EXT_index_func;
extern PACKAGE bool GL_EXT_index_material;
extern PACKAGE bool GL_EXT_index_texture;
extern PACKAGE bool GL_EXT_light_texture;
extern PACKAGE bool GL_EXT_misc_attribute;
extern PACKAGE bool GL_EXT_multi_draw_arrays;
extern PACKAGE bool GL_EXT_multisample;
extern PACKAGE bool GL_EXT_packed_pixels;
extern PACKAGE bool GL_EXT_paletted_texture;
extern PACKAGE bool GL_EXT_pixel_transform;
extern PACKAGE bool GL_EXT_pixel_transform_color_table;
extern PACKAGE bool GL_EXT_point_parameters;
extern PACKAGE bool GL_EXT_polygon_offset;
extern PACKAGE bool GL_EXT_rescale_normal;
extern PACKAGE bool GL_EXT_secondary_color;
extern PACKAGE bool GL_EXT_separate_specular_color;
extern PACKAGE bool GL_EXT_shadow_funcs;
extern PACKAGE bool GL_EXT_shared_texture_palette;
extern PACKAGE bool GL_EXT_stencil_two_side;
extern PACKAGE bool GL_EXT_stencil_wrap;
extern PACKAGE bool GL_EXT_subtexture;
extern PACKAGE bool GL_EXT_texture;
extern PACKAGE bool GL_EXT_texture3D;
extern PACKAGE bool GL_EXT_texture_compression_s3tc;
extern PACKAGE bool GL_EXT_texture_cube_map;
extern PACKAGE bool GL_EXT_texture_edge_clamp;
extern PACKAGE bool GL_EXT_texture_env_add;
extern PACKAGE bool GL_EXT_texture_env_combine;
extern PACKAGE bool GL_EXT_texture_env_dot3;
extern PACKAGE bool GL_EXT_texture_filter_anisotropic;
extern PACKAGE bool GL_EXT_texture_lod_bias;
extern PACKAGE bool GL_EXT_texture_object;
extern PACKAGE bool GL_EXT_texture_perturb_normal;
extern PACKAGE bool GL_EXT_texture_rectangle;
extern PACKAGE bool GL_EXT_vertex_array;
extern PACKAGE bool GL_EXT_vertex_shader;
extern PACKAGE bool GL_EXT_vertex_weighting;
extern PACKAGE bool GL_EXT_depth_bounds_test;
extern PACKAGE bool GL_EXT_texture_mirror_clamp;
extern PACKAGE bool GL_EXT_blend_equation_separate;
extern PACKAGE bool GL_EXT_pixel_buffer_object;
extern PACKAGE bool GL_EXT_texture_compression_dxt1;
extern PACKAGE bool GL_EXT_stencil_clear_tag;
extern PACKAGE bool GL_FfdMaskSGIX;
extern PACKAGE bool GL_HP_convolution_border_modes;
extern PACKAGE bool GL_HP_image_transform;
extern PACKAGE bool GL_HP_occlusion_test;
extern PACKAGE bool GL_HP_texture_lighting;
extern PACKAGE bool GL_IBM_cull_vertex;
extern PACKAGE bool GL_IBM_multimode_draw_arrays;
extern PACKAGE bool GL_IBM_rasterpos_clip;
extern PACKAGE bool GL_IBM_texture_mirrored_repeat;
extern PACKAGE bool GL_IBM_vertex_array_lists;
extern PACKAGE bool GL_INGR_blend_func_separate;
extern PACKAGE bool GL_INGR_color_clamp;
extern PACKAGE bool GL_INGR_interlace_read;
extern PACKAGE bool GL_INGR_palette_buffer;
extern PACKAGE bool GL_INTEL_parallel_arrays;
extern PACKAGE bool GL_INTEL_texture_scissor;
extern PACKAGE bool GL_MESA_resize_buffers;
extern PACKAGE bool GL_MESA_window_pos;
extern PACKAGE bool GL_NV_blend_square;
extern PACKAGE bool GL_NV_copy_depth_to_color;
extern PACKAGE bool GL_NV_depth_clamp;
extern PACKAGE bool GL_NV_evaluators;
extern PACKAGE bool GL_NV_fence;
extern PACKAGE bool GL_NV_float_buffer;
extern PACKAGE bool GL_NV_fog_distance;
extern PACKAGE bool GL_NV_fragment_program;
extern PACKAGE bool GL_NV_half_float;
extern PACKAGE bool GL_NV_light_max_exponent;
extern PACKAGE bool GL_NV_multisample_filter_hint;
extern PACKAGE bool GL_NV_occlusion_query;
extern PACKAGE bool GL_NV_packed_depth_stencil;
extern PACKAGE bool GL_NV_pixel_data_range;
extern PACKAGE bool GL_NV_point_sprite;
extern PACKAGE bool GL_NV_primitive_restart;
extern PACKAGE bool GL_NV_register_combiners;
extern PACKAGE bool GL_NV_register_combiners2;
extern PACKAGE bool GL_NV_texgen_emboss;
extern PACKAGE bool GL_NV_texgen_reflection;
extern PACKAGE bool GL_NV_texture_compression_vtc;
extern PACKAGE bool GL_NV_texture_env_combine4;
extern PACKAGE bool GL_NV_texture_expand_normal;
extern PACKAGE bool GL_NV_texture_rectangle;
extern PACKAGE bool GL_NV_texture_shader;
extern PACKAGE bool GL_NV_texture_shader2;
extern PACKAGE bool GL_NV_texture_shader3;
extern PACKAGE bool GL_NV_vertex_array_range;
extern PACKAGE bool GL_NV_vertex_array_range2;
extern PACKAGE bool GL_NV_vertex_program;
extern PACKAGE bool GL_NV_vertex_program1_1;
extern PACKAGE bool GL_NV_vertex_program2;
extern PACKAGE bool GL_NV_fragment_program_option;
extern PACKAGE bool GL_NV_fragment_program2;
extern PACKAGE bool GL_NV_vertex_program2_option;
extern PACKAGE bool GL_NV_vertex_program3;
extern PACKAGE bool GL_OML_interlace;
extern PACKAGE bool GL_OML_resample;
extern PACKAGE bool GL_OML_subsample;
extern PACKAGE bool GL_PGI_misc_hints;
extern PACKAGE bool GL_PGI_vertex_hints;
extern PACKAGE bool GL_REND_screen_coordinates;
extern PACKAGE bool GL_S3_s3tc;
extern PACKAGE bool GL_SGIS_detail_texture;
extern PACKAGE bool GL_SGIS_fog_function;
extern PACKAGE bool GL_SGIS_generate_mipmap;
extern PACKAGE bool GL_SGIS_multisample;
extern PACKAGE bool GL_SGIS_pixel_texture;
extern PACKAGE bool GL_SGIS_point_line_texgen;
extern PACKAGE bool GL_SGIS_point_parameters;
extern PACKAGE bool GL_SGIS_sharpen_texture;
extern PACKAGE bool GL_SGIS_texture4D;
extern PACKAGE bool GL_SGIS_texture_border_clamp;
extern PACKAGE bool GL_SGIS_texture_color_mask;
extern PACKAGE bool GL_SGIS_texture_edge_clamp;
extern PACKAGE bool GL_SGIS_texture_filter4;
extern PACKAGE bool GL_SGIS_texture_lod;
extern PACKAGE bool GL_SGIS_texture_select;
extern PACKAGE bool GL_SGIX_async;
extern PACKAGE bool GL_SGIX_async_histogram;
extern PACKAGE bool GL_SGIX_async_pixel;
extern PACKAGE bool GL_SGIX_blend_alpha_minmax;
extern PACKAGE bool GL_SGIX_calligraphic_fragment;
extern PACKAGE bool GL_SGIX_clipmap;
extern PACKAGE bool GL_SGIX_convolution_accuracy;
extern PACKAGE bool GL_SGIX_depth_pass_instrument;
extern PACKAGE bool GL_SGIX_depth_texture;
extern PACKAGE bool GL_SGIX_flush_raster;
extern PACKAGE bool GL_SGIX_fog_offset;
extern PACKAGE bool GL_SGIX_fog_scale;
extern PACKAGE bool GL_SGIX_fragment_lighting;
extern PACKAGE bool GL_SGIX_framezoom;
extern PACKAGE bool GL_SGIX_igloo_interface;
extern PACKAGE bool GL_SGIX_impact_pixel_texture;
extern PACKAGE bool GL_SGIX_instruments;
extern PACKAGE bool GL_SGIX_interlace;
extern PACKAGE bool GL_SGIX_ir_instrument1;
extern PACKAGE bool GL_SGIX_list_priority;
extern PACKAGE bool GL_SGIX_pixel_texture;
extern PACKAGE bool GL_SGIX_pixel_tiles;
extern PACKAGE bool GL_SGIX_polynomial_ffd;
extern PACKAGE bool GL_SGIX_reference_plane;
extern PACKAGE bool GL_SGIX_resample;
extern PACKAGE bool GL_SGIX_scalebias_hint;
extern PACKAGE bool GL_SGIX_shadow;
extern PACKAGE bool GL_SGIX_shadow_ambient;
extern PACKAGE bool GL_SGIX_sprite;
extern PACKAGE bool GL_SGIX_subsample;
extern PACKAGE bool GL_SGIX_tag_sample_buffer;
extern PACKAGE bool GL_SGIX_texture_add_env;
extern PACKAGE bool GL_SGIX_texture_coordinate_clamp;
extern PACKAGE bool GL_SGIX_texture_lod_bias;
extern PACKAGE bool GL_SGIX_texture_multi_buffer;
extern PACKAGE bool GL_SGIX_texture_scale_bias;
extern PACKAGE bool GL_SGIX_texture_select;
extern PACKAGE bool GL_SGIX_vertex_preclip;
extern PACKAGE bool GL_SGIX_ycrcb;
extern PACKAGE bool GL_SGIX_ycrcb_subsample;
extern PACKAGE bool GL_SGIX_ycrcba;
extern PACKAGE bool GL_SGI_color_matrix;
extern PACKAGE bool GL_SGI_color_table;
extern PACKAGE bool GL_SGI_depth_pass_instrument;
extern PACKAGE bool GL_SGI_texture_color_table;
extern PACKAGE bool GL_SUNX_constant_data;
extern PACKAGE bool GL_SUN_convolution_border_modes;
extern PACKAGE bool GL_SUN_global_alpha;
extern PACKAGE bool GL_SUN_mesh_array;
extern PACKAGE bool GL_SUN_slice_accum;
extern PACKAGE bool GL_SUN_triangle_list;
extern PACKAGE bool GL_SUN_vertex;
extern PACKAGE bool GL_WIN_phong_shading;
extern PACKAGE bool GL_WIN_specular_fog;
extern PACKAGE bool WGL_3DFX_multisample;
extern PACKAGE bool WGL_ARB_buffer_region;
extern PACKAGE bool WGL_ARB_extensions_string;
extern PACKAGE bool WGL_ARB_make_current_read;
extern PACKAGE bool WGL_ARB_multisample;
extern PACKAGE bool WGL_ARB_pbuffer;
extern PACKAGE bool WGL_ARB_pixel_format;
extern PACKAGE bool WGL_ARB_pixel_format_float;
extern PACKAGE bool WGL_ARB_render_texture;
extern PACKAGE bool WGL_ATI_pixel_format_float;
extern PACKAGE bool WGL_EXT_depth_float;
extern PACKAGE bool WGL_EXT_display_color_table;
extern PACKAGE bool WGL_EXT_extensions_string;
extern PACKAGE bool WGL_EXT_make_current_read;
extern PACKAGE bool WGL_EXT_multisample;
extern PACKAGE bool WGL_EXT_pbuffer;
extern PACKAGE bool WGL_EXT_pixel_format;
extern PACKAGE bool WGL_EXT_swap_control;
extern PACKAGE bool WGL_I3D_digital_video_control;
extern PACKAGE bool WGL_I3D_gamma;
extern PACKAGE bool WGL_I3D_genlock;
extern PACKAGE bool WGL_I3D_image_buffer;
extern PACKAGE bool WGL_I3D_swap_frame_lock;
extern PACKAGE bool WGL_I3D_swap_frame_usage;
extern PACKAGE bool WGL_NV_float_buffer;
extern PACKAGE bool WGL_NV_render_depth_texture;
extern PACKAGE bool WGL_NV_render_texture_rectangle;
extern PACKAGE bool WGL_NV_vertex_array_range;
extern PACKAGE bool WGL_OML_sync_control;
extern PACKAGE bool WIN_draw_range_elements;
extern PACKAGE bool WIN_swap_hint;
static const Word GL_ACCUM = 0x100;
static const Word GL_LOAD = 0x101;
static const Word GL_RETURN = 0x102;
static const Word GL_MULT = 0x103;
static const Word GL_ADD = 0x104;
static const Word GL_NEVER = 0x200;
static const Word GL_LESS = 0x201;
static const Word GL_EQUAL = 0x202;
static const Word GL_LEQUAL = 0x203;
static const Word GL_GREATER = 0x204;
static const Word GL_NOTEQUAL = 0x205;
static const Word GL_GEQUAL = 0x206;
static const Word GL_ALWAYS = 0x207;
static const Shortint GL_CURRENT_BIT = 0x1;
static const Shortint GL_POINT_BIT = 0x2;
static const Shortint GL_LINE_BIT = 0x4;
static const Shortint GL_POLYGON_BIT = 0x8;
static const Shortint GL_POLYGON_STIPPLE_BIT = 0x10;
static const Shortint GL_PIXEL_MODE_BIT = 0x20;
static const Shortint GL_LIGHTING_BIT = 0x40;
static const Byte GL_FOG_BIT = 0x80;
static const Word GL_DEPTH_BUFFER_BIT = 0x100;
static const Word GL_ACCUM_BUFFER_BIT = 0x200;
static const Word GL_STENCIL_BUFFER_BIT = 0x400;
static const Word GL_VIEWPORT_BIT = 0x800;
static const Word GL_TRANSFORM_BIT = 0x1000;
static const Word GL_ENABLE_BIT = 0x2000;
static const Word GL_COLOR_BUFFER_BIT = 0x4000;
static const Word GL_HINT_BIT = 0x8000;
static const int GL_EVAL_BIT = 0x10000;
static const int GL_LIST_BIT = 0x20000;
static const int GL_TEXTURE_BIT = 0x40000;
static const int GL_SCISSOR_BIT = 0x80000;
static const int GL_ALL_ATTRIB_BITS = 0xfffff;
static const Shortint GL_POINTS = 0x0;
static const Shortint GL_LINES = 0x1;
static const Shortint GL_LINE_LOOP = 0x2;
static const Shortint GL_LINE_STRIP = 0x3;
static const Shortint GL_TRIANGLES = 0x4;
static const Shortint GL_TRIANGLE_STRIP = 0x5;
static const Shortint GL_TRIANGLE_FAN = 0x6;
static const Shortint GL_QUADS = 0x7;
static const Shortint GL_QUAD_STRIP = 0x8;
static const Shortint GL_POLYGON = 0x9;
static const Shortint GL_ZERO = 0x0;
static const Shortint GL_ONE = 0x1;
static const Word GL_SRC_COLOR = 0x300;
static const Word GL_ONE_MINUS_SRC_COLOR = 0x301;
static const Word GL_SRC_ALPHA = 0x302;
static const Word GL_ONE_MINUS_SRC_ALPHA = 0x303;
static const Word GL_DST_ALPHA = 0x304;
static const Word GL_ONE_MINUS_DST_ALPHA = 0x305;
static const Word GL_DST_COLOR = 0x306;
static const Word GL_ONE_MINUS_DST_COLOR = 0x307;
static const Word GL_SRC_ALPHA_SATURATE = 0x308;
static const Shortint GL_TRUE = 0x1;
static const Shortint GL_FALSE = 0x0;
static const Word GL_CLIP_PLANE0 = 0x3000;
static const Word GL_CLIP_PLANE1 = 0x3001;
static const Word GL_CLIP_PLANE2 = 0x3002;
static const Word GL_CLIP_PLANE3 = 0x3003;
static const Word GL_CLIP_PLANE4 = 0x3004;
static const Word GL_CLIP_PLANE5 = 0x3005;
static const Word GL_BYTE = 0x1400;
static const Word GL_UNSIGNED_BYTE = 0x1401;
static const Word GL_SHORT = 0x1402;
static const Word GL_UNSIGNED_SHORT = 0x1403;
static const Word GL_INT = 0x1404;
static const Word GL_UNSIGNED_INT = 0x1405;
static const Word GL_FLOAT = 0x1406;
static const Word GL_2_BYTES = 0x1407;
static const Word GL_3_BYTES = 0x1408;
static const Word GL_4_BYTES = 0x1409;
static const Word GL_DOUBLE = 0x140a;
static const Shortint GL_NONE = 0x0;
static const Word GL_FRONT_LEFT = 0x400;
static const Word GL_FRONT_RIGHT = 0x401;
static const Word GL_BACK_LEFT = 0x402;
static const Word GL_BACK_RIGHT = 0x403;
static const Word GL_FRONT = 0x404;
static const Word GL_BACK = 0x405;
static const Word GL_LEFT = 0x406;
static const Word GL_RIGHT = 0x407;
static const Word GL_FRONT_AND_BACK = 0x408;
static const Word GL_AUX0 = 0x409;
static const Word GL_AUX1 = 0x40a;
static const Word GL_AUX2 = 0x40b;
static const Word GL_AUX3 = 0x40c;
static const Shortint GL_NO_ERROR = 0x0;
static const Word GL_INVALID_ENUM = 0x500;
static const Word GL_INVALID_VALUE = 0x501;
static const Word GL_INVALID_OPERATION = 0x502;
static const Word GL_STACK_OVERFLOW = 0x503;
static const Word GL_STACK_UNDERFLOW = 0x504;
static const Word GL_OUT_OF_MEMORY = 0x505;
static const Word GL_2D = 0x600;
static const Word GL_3D = 0x601;
static const Word GL_3D_COLOR = 0x602;
static const Word GL_3D_COLOR_TEXTURE = 0x603;
static const Word GL_4D_COLOR_TEXTURE = 0x604;
static const Word GL_PASS_THROUGH_TOKEN = 0x700;
static const Word GL_POINT_TOKEN = 0x701;
static const Word GL_LINE_TOKEN = 0x702;
static const Word GL_POLYGON_TOKEN = 0x703;
static const Word GL_BITMAP_TOKEN = 0x704;
static const Word GL_DRAW_PIXEL_TOKEN = 0x705;
static const Word GL_COPY_PIXEL_TOKEN = 0x706;
static const Word GL_LINE_RESET_TOKEN = 0x707;
static const Word GL_EXP = 0x800;
static const Word GL_EXP2 = 0x801;
static const Word GL_CW = 0x900;
static const Word GL_CCW = 0x901;
static const Word GL_COEFF = 0xa00;
static const Word GL_ORDER = 0xa01;
static const Word GL_DOMAIN = 0xa02;
static const Word GL_CURRENT_COLOR = 0xb00;
static const Word GL_CURRENT_INDEX = 0xb01;
static const Word GL_CURRENT_NORMAL = 0xb02;
static const Word GL_CURRENT_TEXTURE_COORDS = 0xb03;
static const Word GL_CURRENT_RASTER_COLOR = 0xb04;
static const Word GL_CURRENT_RASTER_INDEX = 0xb05;
static const Word GL_CURRENT_RASTER_TEXTURE_COORDS = 0xb06;
static const Word GL_CURRENT_RASTER_POSITION = 0xb07;
static const Word GL_CURRENT_RASTER_POSITION_VALID = 0xb08;
static const Word GL_CURRENT_RASTER_DISTANCE = 0xb09;
static const Word GL_POINT_SMOOTH = 0xb10;
static const Word GL_POINT_SIZE = 0xb11;
static const Word GL_POINT_SIZE_RANGE = 0xb12;
static const Word GL_POINT_SIZE_GRANULARITY = 0xb13;
static const Word GL_LINE_SMOOTH = 0xb20;
static const Word GL_LINE_WIDTH = 0xb21;
static const Word GL_LINE_WIDTH_RANGE = 0xb22;
static const Word GL_LINE_WIDTH_GRANULARITY = 0xb23;
static const Word GL_LINE_STIPPLE = 0xb24;
static const Word GL_LINE_STIPPLE_PATTERN = 0xb25;
static const Word GL_LINE_STIPPLE_REPEAT = 0xb26;
static const Word GL_LIST_MODE = 0xb30;
static const Word GL_MAX_LIST_NESTING = 0xb31;
static const Word GL_LIST_BASE = 0xb32;
static const Word GL_LIST_INDEX = 0xb33;
static const Word GL_POLYGON_MODE = 0xb40;
static const Word GL_POLYGON_SMOOTH = 0xb41;
static const Word GL_POLYGON_STIPPLE = 0xb42;
static const Word GL_EDGE_FLAG = 0xb43;
static const Word GL_CULL_FACE = 0xb44;
static const Word GL_CULL_FACE_MODE = 0xb45;
static const Word GL_FRONT_FACE = 0xb46;
static const Word GL_LIGHTING = 0xb50;
static const Word GL_LIGHT_MODEL_LOCAL_VIEWER = 0xb51;
static const Word GL_LIGHT_MODEL_TWO_SIDE = 0xb52;
static const Word GL_LIGHT_MODEL_AMBIENT = 0xb53;
static const Word GL_SHADE_MODEL = 0xb54;
static const Word GL_COLOR_MATERIAL_FACE = 0xb55;
static const Word GL_COLOR_MATERIAL_PARAMETER = 0xb56;
static const Word GL_COLOR_MATERIAL = 0xb57;
static const Word GL_FOG = 0xb60;
static const Word GL_FOG_INDEX = 0xb61;
static const Word GL_FOG_DENSITY = 0xb62;
static const Word GL_FOG_START = 0xb63;
static const Word GL_FOG_END = 0xb64;
static const Word GL_FOG_MODE = 0xb65;
static const Word GL_FOG_COLOR = 0xb66;
static const Word GL_DEPTH_RANGE = 0xb70;
static const Word GL_DEPTH_TEST = 0xb71;
static const Word GL_DEPTH_WRITEMASK = 0xb72;
static const Word GL_DEPTH_CLEAR_VALUE = 0xb73;
static const Word GL_DEPTH_FUNC = 0xb74;
static const Word GL_ACCUM_CLEAR_VALUE = 0xb80;
static const Word GL_STENCIL_TEST = 0xb90;
static const Word GL_STENCIL_CLEAR_VALUE = 0xb91;
static const Word GL_STENCIL_FUNC = 0xb92;
static const Word GL_STENCIL_VALUE_MASK = 0xb93;
static const Word GL_STENCIL_FAIL = 0xb94;
static const Word GL_STENCIL_PASS_DEPTH_FAIL = 0xb95;
static const Word GL_STENCIL_PASS_DEPTH_PASS = 0xb96;
static const Word GL_STENCIL_REF = 0xb97;
static const Word GL_STENCIL_WRITEMASK = 0xb98;
static const Word GL_MATRIX_MODE = 0xba0;
static const Word GL_NORMALIZE = 0xba1;
static const Word GL_VIEWPORT = 0xba2;
static const Word GL_MODELVIEW_STACK_DEPTH = 0xba3;
static const Word GL_PROJECTION_STACK_DEPTH = 0xba4;
static const Word GL_TEXTURE_STACK_DEPTH = 0xba5;
static const Word GL_MODELVIEW_MATRIX = 0xba6;
static const Word GL_PROJECTION_MATRIX = 0xba7;
static const Word GL_TEXTURE_MATRIX = 0xba8;
static const Word GL_ATTRIB_STACK_DEPTH = 0xbb0;
static const Word GL_CLIENT_ATTRIB_STACK_DEPTH = 0xbb1;
static const Word GL_ALPHA_TEST = 0xbc0;
static const Word GL_ALPHA_TEST_FUNC = 0xbc1;
static const Word GL_ALPHA_TEST_REF = 0xbc2;
static const Word GL_DITHER = 0xbd0;
static const Word GL_BLEND_DST = 0xbe0;
static const Word GL_BLEND_SRC = 0xbe1;
static const Word GL_BLEND = 0xbe2;
static const Word GL_LOGIC_OP_MODE = 0xbf0;
static const Word GL_INDEX_LOGIC_OP = 0xbf1;
static const Word GL_COLOR_LOGIC_OP = 0xbf2;
static const Word GL_AUX_BUFFERS = 0xc00;
static const Word GL_DRAW_BUFFER = 0xc01;
static const Word GL_READ_BUFFER = 0xc02;
static const Word GL_SCISSOR_BOX = 0xc10;
static const Word GL_SCISSOR_TEST = 0xc11;
static const Word GL_INDEX_CLEAR_VALUE = 0xc20;
static const Word GL_INDEX_WRITEMASK = 0xc21;
static const Word GL_COLOR_CLEAR_VALUE = 0xc22;
static const Word GL_COLOR_WRITEMASK = 0xc23;
static const Word GL_INDEX_MODE = 0xc30;
static const Word GL_RGBA_MODE = 0xc31;
static const Word GL_DOUBLEBUFFER = 0xc32;
static const Word GL_STEREO = 0xc33;
static const Word GL_RENDER_MODE = 0xc40;
static const Word GL_PERSPECTIVE_CORRECTION_HINT = 0xc50;
static const Word GL_POINT_SMOOTH_HINT = 0xc51;
static const Word GL_LINE_SMOOTH_HINT = 0xc52;
static const Word GL_POLYGON_SMOOTH_HINT = 0xc53;
static const Word GL_FOG_HINT = 0xc54;
static const Word GL_TEXTURE_GEN_S = 0xc60;
static const Word GL_TEXTURE_GEN_T = 0xc61;
static const Word GL_TEXTURE_GEN_R = 0xc62;
static const Word GL_TEXTURE_GEN_Q = 0xc63;
static const Word GL_PIXEL_MAP_I_TO_I = 0xc70;
static const Word GL_PIXEL_MAP_S_TO_S = 0xc71;
static const Word GL_PIXEL_MAP_I_TO_R = 0xc72;
static const Word GL_PIXEL_MAP_I_TO_G = 0xc73;
static const Word GL_PIXEL_MAP_I_TO_B = 0xc74;
static const Word GL_PIXEL_MAP_I_TO_A = 0xc75;
static const Word GL_PIXEL_MAP_R_TO_R = 0xc76;
static const Word GL_PIXEL_MAP_G_TO_G = 0xc77;
static const Word GL_PIXEL_MAP_B_TO_B = 0xc78;
static const Word GL_PIXEL_MAP_A_TO_A = 0xc79;
static const Word GL_PIXEL_MAP_I_TO_I_SIZE = 0xcb0;
static const Word GL_PIXEL_MAP_S_TO_S_SIZE = 0xcb1;
static const Word GL_PIXEL_MAP_I_TO_R_SIZE = 0xcb2;
static const Word GL_PIXEL_MAP_I_TO_G_SIZE = 0xcb3;
static const Word GL_PIXEL_MAP_I_TO_B_SIZE = 0xcb4;
static const Word GL_PIXEL_MAP_I_TO_A_SIZE = 0xcb5;
static const Word GL_PIXEL_MAP_R_TO_R_SIZE = 0xcb6;
static const Word GL_PIXEL_MAP_G_TO_G_SIZE = 0xcb7;
static const Word GL_PIXEL_MAP_B_TO_B_SIZE = 0xcb8;
static const Word GL_PIXEL_MAP_A_TO_A_SIZE = 0xcb9;
static const Word GL_UNPACK_SWAP_BYTES = 0xcf0;
static const Word GL_UNPACK_LSB_FIRST = 0xcf1;
static const Word GL_UNPACK_ROW_LENGTH = 0xcf2;
static const Word GL_UNPACK_SKIP_ROWS = 0xcf3;
static const Word GL_UNPACK_SKIP_PIXELS = 0xcf4;
static const Word GL_UNPACK_ALIGNMENT = 0xcf5;
static const Word GL_PACK_SWAP_BYTES = 0xd00;
static const Word GL_PACK_LSB_FIRST = 0xd01;
static const Word GL_PACK_ROW_LENGTH = 0xd02;
static const Word GL_PACK_SKIP_ROWS = 0xd03;
static const Word GL_PACK_SKIP_PIXELS = 0xd04;
static const Word GL_PACK_ALIGNMENT = 0xd05;
static const Word GL_MAP_COLOR = 0xd10;
static const Word GL_MAP_STENCIL = 0xd11;
static const Word GL_INDEX_SHIFT = 0xd12;
static const Word GL_INDEX_OFFSET = 0xd13;
static const Word GL_RED_SCALE = 0xd14;
static const Word GL_RED_BIAS = 0xd15;
static const Word GL_ZOOM_X = 0xd16;
static const Word GL_ZOOM_Y = 0xd17;
static const Word GL_GREEN_SCALE = 0xd18;
static const Word GL_GREEN_BIAS = 0xd19;
static const Word GL_BLUE_SCALE = 0xd1a;
static const Word GL_BLUE_BIAS = 0xd1b;
static const Word GL_ALPHA_SCALE = 0xd1c;
static const Word GL_ALPHA_BIAS = 0xd1d;
static const Word GL_DEPTH_SCALE = 0xd1e;
static const Word GL_DEPTH_BIAS = 0xd1f;
static const Word GL_MAX_EVAL_ORDER = 0xd30;
static const Word GL_MAX_LIGHTS = 0xd31;
static const Word GL_MAX_CLIP_PLANES = 0xd32;
static const Word GL_MAX_TEXTURE_SIZE = 0xd33;
static const Word GL_MAX_PIXEL_MAP_TABLE = 0xd34;
static const Word GL_MAX_ATTRIB_STACK_DEPTH = 0xd35;
static const Word GL_MAX_MODELVIEW_STACK_DEPTH = 0xd36;
static const Word GL_MAX_NAME_STACK_DEPTH = 0xd37;
static const Word GL_MAX_PROJECTION_STACK_DEPTH = 0xd38;
static const Word GL_MAX_TEXTURE_STACK_DEPTH = 0xd39;
static const Word GL_MAX_VIEWPORT_DIMS = 0xd3a;
static const Word GL_MAX_CLIENT_ATTRIB_STACK_DEPTH = 0xd3b;
static const Word GL_SUBPIXEL_BITS = 0xd50;
static const Word GL_INDEX_BITS = 0xd51;
static const Word GL_RED_BITS = 0xd52;
static const Word GL_GREEN_BITS = 0xd53;
static const Word GL_BLUE_BITS = 0xd54;
static const Word GL_ALPHA_BITS = 0xd55;
static const Word GL_DEPTH_BITS = 0xd56;
static const Word GL_STENCIL_BITS = 0xd57;
static const Word GL_ACCUM_RED_BITS = 0xd58;
static const Word GL_ACCUM_GREEN_BITS = 0xd59;
static const Word GL_ACCUM_BLUE_BITS = 0xd5a;
static const Word GL_ACCUM_ALPHA_BITS = 0xd5b;
static const Word GL_NAME_STACK_DEPTH = 0xd70;
static const Word GL_AUTO_NORMAL = 0xd80;
static const Word GL_MAP1_COLOR_4 = 0xd90;
static const Word GL_MAP1_INDEX = 0xd91;
static const Word GL_MAP1_NORMAL = 0xd92;
static const Word GL_MAP1_TEXTURE_COORD_1 = 0xd93;
static const Word GL_MAP1_TEXTURE_COORD_2 = 0xd94;
static const Word GL_MAP1_TEXTURE_COORD_3 = 0xd95;
static const Word GL_MAP1_TEXTURE_COORD_4 = 0xd96;
static const Word GL_MAP1_VERTEX_3 = 0xd97;
static const Word GL_MAP1_VERTEX_4 = 0xd98;
static const Word GL_MAP2_COLOR_4 = 0xdb0;
static const Word GL_MAP2_INDEX = 0xdb1;
static const Word GL_MAP2_NORMAL = 0xdb2;
static const Word GL_MAP2_TEXTURE_COORD_1 = 0xdb3;
static const Word GL_MAP2_TEXTURE_COORD_2 = 0xdb4;
static const Word GL_MAP2_TEXTURE_COORD_3 = 0xdb5;
static const Word GL_MAP2_TEXTURE_COORD_4 = 0xdb6;
static const Word GL_MAP2_VERTEX_3 = 0xdb7;
static const Word GL_MAP2_VERTEX_4 = 0xdb8;
static const Word GL_MAP1_GRID_DOMAIN = 0xdd0;
static const Word GL_MAP1_GRID_SEGMENTS = 0xdd1;
static const Word GL_MAP2_GRID_DOMAIN = 0xdd2;
static const Word GL_MAP2_GRID_SEGMENTS = 0xdd3;
static const Word GL_TEXTURE_1D = 0xde0;
static const Word GL_TEXTURE_2D = 0xde1;
static const Word GL_FEEDBACK_BUFFER_POINTER = 0xdf0;
static const Word GL_FEEDBACK_BUFFER_SIZE = 0xdf1;
static const Word GL_FEEDBACK_BUFFER_TYPE = 0xdf2;
static const Word GL_SELECTION_BUFFER_POINTER = 0xdf3;
static const Word GL_SELECTION_BUFFER_SIZE = 0xdf4;
static const Word GL_TEXTURE_WIDTH = 0x1000;
static const Word GL_TEXTURE_HEIGHT = 0x1001;
static const Word GL_TEXTURE_INTERNAL_FORMAT = 0x1003;
static const Word GL_TEXTURE_BORDER_COLOR = 0x1004;
static const Word GL_TEXTURE_BORDER = 0x1005;
static const Word GL_DONT_CARE = 0x1100;
static const Word GL_FASTEST = 0x1101;
static const Word GL_NICEST = 0x1102;
static const Word GL_LIGHT0 = 0x4000;
static const Word GL_LIGHT1 = 0x4001;
static const Word GL_LIGHT2 = 0x4002;
static const Word GL_LIGHT3 = 0x4003;
static const Word GL_LIGHT4 = 0x4004;
static const Word GL_LIGHT5 = 0x4005;
static const Word GL_LIGHT6 = 0x4006;
static const Word GL_LIGHT7 = 0x4007;
static const Word GL_AMBIENT = 0x1200;
static const Word GL_DIFFUSE = 0x1201;
static const Word GL_SPECULAR = 0x1202;
static const Word GL_POSITION = 0x1203;
static const Word GL_SPOT_DIRECTION = 0x1204;
static const Word GL_SPOT_EXPONENT = 0x1205;
static const Word GL_SPOT_CUTOFF = 0x1206;
static const Word GL_CONSTANT_ATTENUATION = 0x1207;
static const Word GL_LINEAR_ATTENUATION = 0x1208;
static const Word GL_QUADRATIC_ATTENUATION = 0x1209;
static const Word GL_COMPILE = 0x1300;
static const Word GL_COMPILE_AND_EXECUTE = 0x1301;
static const Word GL_CLEAR = 0x1500;
static const Word GL_AND = 0x1501;
static const Word GL_AND_REVERSE = 0x1502;
static const Word GL_COPY = 0x1503;
static const Word GL_AND_INVERTED = 0x1504;
static const Word GL_NOOP = 0x1505;
static const Word GL_XOR = 0x1506;
static const Word GL_OR = 0x1507;
static const Word GL_NOR = 0x1508;
static const Word GL_EQUIV = 0x1509;
static const Word GL_INVERT = 0x150a;
static const Word GL_OR_REVERSE = 0x150b;
static const Word GL_COPY_INVERTED = 0x150c;
static const Word GL_OR_INVERTED = 0x150d;
static const Word GL_NAND = 0x150e;
static const Word GL_SET = 0x150f;
static const Word GL_EMISSION = 0x1600;
static const Word GL_SHININESS = 0x1601;
static const Word GL_AMBIENT_AND_DIFFUSE = 0x1602;
static const Word GL_COLOR_INDEXES = 0x1603;
static const Word GL_MODELVIEW = 0x1700;
static const Word GL_PROJECTION = 0x1701;
static const Word GL_TEXTURE = 0x1702;
static const Word GL_COLOR = 0x1800;
static const Word GL_DEPTH = 0x1801;
static const Word GL_STENCIL = 0x1802;
static const Word GL_COLOR_INDEX = 0x1900;
static const Word GL_STENCIL_INDEX = 0x1901;
static const Word GL_DEPTH_COMPONENT = 0x1902;
static const Word GL_RED = 0x1903;
static const Word GL_GREEN = 0x1904;
static const Word GL_BLUE = 0x1905;
static const Word GL_ALPHA = 0x1906;
static const Word GL_RGB = 0x1907;
static const Word GL_RGBA = 0x1908;
static const Word GL_LUMINANCE = 0x1909;
static const Word GL_LUMINANCE_ALPHA = 0x190a;
static const Word GL_BITMAP = 0x1a00;
static const Word GL_POINT = 0x1b00;
static const Word GL_LINE = 0x1b01;
static const Word GL_FILL = 0x1b02;
static const Word GL_RENDER = 0x1c00;
static const Word GL_FEEDBACK = 0x1c01;
static const Word GL_SELECT = 0x1c02;
static const Word GL_FLAT = 0x1d00;
static const Word GL_SMOOTH = 0x1d01;
static const Word GL_KEEP = 0x1e00;
static const Word GL_REPLACE = 0x1e01;
static const Word GL_INCR = 0x1e02;
static const Word GL_DECR = 0x1e03;
static const Word GL_VENDOR = 0x1f00;
static const Word GL_RENDERER = 0x1f01;
static const Word GL_VERSION = 0x1f02;
static const Word GL_EXTENSIONS = 0x1f03;
static const Word GL_S = 0x2000;
static const Word GL_T = 0x2001;
static const Word GL_R = 0x2002;
static const Word GL_Q = 0x2003;
static const Word GL_MODULATE = 0x2100;
static const Word GL_DECAL = 0x2101;
static const Word GL_TEXTURE_ENV_MODE = 0x2200;
static const Word GL_TEXTURE_ENV_COLOR = 0x2201;
static const Word GL_TEXTURE_ENV = 0x2300;
static const Word GL_EYE_LINEAR = 0x2400;
static const Word GL_OBJECT_LINEAR = 0x2401;
static const Word GL_SPHERE_MAP = 0x2402;
static const Word GL_TEXTURE_GEN_MODE = 0x2500;
static const Word GL_OBJECT_PLANE = 0x2501;
static const Word GL_EYE_PLANE = 0x2502;
static const Word GL_NEAREST = 0x2600;
static const Word GL_LINEAR = 0x2601;
static const Word GL_NEAREST_MIPMAP_NEAREST = 0x2700;
static const Word GL_LINEAR_MIPMAP_NEAREST = 0x2701;
static const Word GL_NEAREST_MIPMAP_LINEAR = 0x2702;
static const Word GL_LINEAR_MIPMAP_LINEAR = 0x2703;
static const Word GL_TEXTURE_MAG_FILTER = 0x2800;
static const Word GL_TEXTURE_MIN_FILTER = 0x2801;
static const Word GL_TEXTURE_WRAP_S = 0x2802;
static const Word GL_TEXTURE_WRAP_T = 0x2803;
static const Word GL_CLAMP = 0x2900;
static const Word GL_REPEAT = 0x2901;
static const Shortint GL_CLIENT_PIXEL_STORE_BIT = 0x1;
static const Shortint GL_CLIENT_VERTEX_ARRAY_BIT = 0x2;
static const unsigned GL_CLIENT_ALL_ATTRIB_BITS = 0xffffffff;
static const Word GL_POLYGON_OFFSET_FACTOR = 0x8038;
static const Word GL_POLYGON_OFFSET_UNITS = 0x2a00;
static const Word GL_POLYGON_OFFSET_POINT = 0x2a01;
static const Word GL_POLYGON_OFFSET_LINE = 0x2a02;
static const Word GL_POLYGON_OFFSET_FILL = 0x8037;
static const Word GL_ALPHA4 = 0x803b;
static const Word GL_ALPHA8 = 0x803c;
static const Word GL_ALPHA12 = 0x803d;
static const Word GL_ALPHA16 = 0x803e;
static const Word GL_LUMINANCE4 = 0x803f;
static const Word GL_LUMINANCE8 = 0x8040;
static const Word GL_LUMINANCE12 = 0x8041;
static const Word GL_LUMINANCE16 = 0x8042;
static const Word GL_LUMINANCE4_ALPHA4 = 0x8043;
static const Word GL_LUMINANCE6_ALPHA2 = 0x8044;
static const Word GL_LUMINANCE8_ALPHA8 = 0x8045;
static const Word GL_LUMINANCE12_ALPHA4 = 0x8046;
static const Word GL_LUMINANCE12_ALPHA12 = 0x8047;
static const Word GL_LUMINANCE16_ALPHA16 = 0x8048;
static const Word GL_INTENSITY = 0x8049;
static const Word GL_INTENSITY4 = 0x804a;
static const Word GL_INTENSITY8 = 0x804b;
static const Word GL_INTENSITY12 = 0x804c;
static const Word GL_INTENSITY16 = 0x804d;
static const Word GL_R3_G3_B2 = 0x2a10;
static const Word GL_RGB4 = 0x804f;
static const Word GL_RGB5 = 0x8050;
static const Word GL_RGB8 = 0x8051;
static const Word GL_RGB10 = 0x8052;
static const Word GL_RGB12 = 0x8053;
static const Word GL_RGB16 = 0x8054;
static const Word GL_RGBA2 = 0x8055;
static const Word GL_RGBA4 = 0x8056;
static const Word GL_RGB5_A1 = 0x8057;
static const Word GL_RGBA8 = 0x8058;
static const Word GL_RGB10_A2 = 0x8059;
static const Word GL_RGBA12 = 0x805a;
static const Word GL_RGBA16 = 0x805b;
static const Word GL_TEXTURE_RED_SIZE = 0x805c;
static const Word GL_TEXTURE_GREEN_SIZE = 0x805d;
static const Word GL_TEXTURE_BLUE_SIZE = 0x805e;
static const Word GL_TEXTURE_ALPHA_SIZE = 0x805f;
static const Word GL_TEXTURE_LUMINANCE_SIZE = 0x8060;
static const Word GL_TEXTURE_INTENSITY_SIZE = 0x8061;
static const Word GL_PROXY_TEXTURE_1D = 0x8063;
static const Word GL_PROXY_TEXTURE_2D = 0x8064;
static const Word GL_TEXTURE_PRIORITY = 0x8066;
static const Word GL_TEXTURE_RESIDENT = 0x8067;
static const Word GL_TEXTURE_BINDING_1D = 0x8068;
static const Word GL_TEXTURE_BINDING_2D = 0x8069;
static const Word GL_VERTEX_ARRAY = 0x8074;
static const Word GL_NORMAL_ARRAY = 0x8075;
static const Word GL_COLOR_ARRAY = 0x8076;
static const Word GL_INDEX_ARRAY = 0x8077;
static const Word GL_TEXTURE_COORD_ARRAY = 0x8078;
static const Word GL_EDGE_FLAG_ARRAY = 0x8079;
static const Word GL_VERTEX_ARRAY_SIZE = 0x807a;
static const Word GL_VERTEX_ARRAY_TYPE = 0x807b;
static const Word GL_VERTEX_ARRAY_STRIDE = 0x807c;
static const Word GL_NORMAL_ARRAY_TYPE = 0x807e;
static const Word GL_NORMAL_ARRAY_STRIDE = 0x807f;
static const Word GL_COLOR_ARRAY_SIZE = 0x8081;
static const Word GL_COLOR_ARRAY_TYPE = 0x8082;
static const Word GL_COLOR_ARRAY_STRIDE = 0x8083;
static const Word GL_INDEX_ARRAY_TYPE = 0x8085;
static const Word GL_INDEX_ARRAY_STRIDE = 0x8086;
static const Word GL_TEXTURE_COORD_ARRAY_SIZE = 0x8088;
static const Word GL_TEXTURE_COORD_ARRAY_TYPE = 0x8089;
static const Word GL_TEXTURE_COORD_ARRAY_STRIDE = 0x808a;
static const Word GL_EDGE_FLAG_ARRAY_STRIDE = 0x808c;
static const Word GL_VERTEX_ARRAY_POINTER = 0x808e;
static const Word GL_NORMAL_ARRAY_POINTER = 0x808f;
static const Word GL_COLOR_ARRAY_POINTER = 0x8090;
static const Word GL_INDEX_ARRAY_POINTER = 0x8091;
static const Word GL_TEXTURE_COORD_ARRAY_POINTER = 0x8092;
static const Word GL_EDGE_FLAG_ARRAY_POINTER = 0x8093;
static const Word GL_V2F = 0x2a20;
static const Word GL_V3F = 0x2a21;
static const Word GL_C4UB_V2F = 0x2a22;
static const Word GL_C4UB_V3F = 0x2a23;
static const Word GL_C3F_V3F = 0x2a24;
static const Word GL_N3F_V3F = 0x2a25;
static const Word GL_C4F_N3F_V3F = 0x2a26;
static const Word GL_T2F_V3F = 0x2a27;
static const Word GL_T4F_V4F = 0x2a28;
static const Word GL_T2F_C4UB_V3F = 0x2a29;
static const Word GL_T2F_C3F_V3F = 0x2a2a;
static const Word GL_T2F_N3F_V3F = 0x2a2b;
static const Word GL_T2F_C4F_N3F_V3F = 0x2a2c;
static const Word GL_T4F_C4F_N3F_V4F = 0x2a2d;
static const Word GL_COLOR_TABLE_FORMAT_EXT = 0x80d8;
static const Word GL_COLOR_TABLE_WIDTH_EXT = 0x80d9;
static const Word GL_COLOR_TABLE_RED_SIZE_EXT = 0x80da;
static const Word GL_COLOR_TABLE_GREEN_SIZE_EXT = 0x80db;
static const Word GL_COLOR_TABLE_BLUE_SIZE_EXT = 0x80dc;
static const Word GL_COLOR_TABLE_ALPHA_SIZE_EXT = 0x80dd;
static const Word GL_COLOR_TABLE_LUMINANCE_SIZE_EXT = 0x80de;
static const Word GL_COLOR_TABLE_INTENSITY_SIZE_EXT = 0x80df;
static const Word GL_LOGIC_OP = 0xbf1;
static const Word GL_TEXTURE_COMPONENTS = 0x1003;
static const Word GL_UNSIGNED_BYTE_3_3_2 = 0x8032;
static const Word GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033;
static const Word GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034;
static const Word GL_UNSIGNED_INT_8_8_8_8 = 0x8035;
static const Word GL_UNSIGNED_INT_10_10_10_2 = 0x8036;
static const Word GL_RESCALE_NORMAL = 0x803a;
static const Word GL_TEXTURE_BINDING_3D = 0x806a;
static const Word GL_PACK_SKIP_IMAGES = 0x806b;
static const Word GL_PACK_IMAGE_HEIGHT = 0x806c;
static const Word GL_UNPACK_SKIP_IMAGES = 0x806d;
static const Word GL_UNPACK_IMAGE_HEIGHT = 0x806e;
static const Word GL_TEXTURE_3D = 0x806f;
static const Word GL_PROXY_TEXTURE_3D = 0x8070;
static const Word GL_TEXTURE_DEPTH = 0x8071;
static const Word GL_TEXTURE_WRAP_R = 0x8072;
static const Word GL_MAX_3D_TEXTURE_SIZE = 0x8073;
static const Word GL_UNSIGNED_BYTE_2_3_3_REV = 0x8362;
static const Word GL_UNSIGNED_SHORT_5_6_5 = 0x8363;
static const Word GL_UNSIGNED_SHORT_5_6_5_REV = 0x8364;
static const Word GL_UNSIGNED_SHORT_4_4_4_4_REV = 0x8365;
static const Word GL_UNSIGNED_SHORT_1_5_5_5_REV = 0x8366;
static const Word GL_UNSIGNED_INT_8_8_8_8_REV = 0x8367;
static const Word GL_UNSIGNED_INT_2_10_10_10_REV = 0x8368;
static const Word GL_BGR = 0x80e0;
static const Word GL_BGRA = 0x80e1;
static const Word GL_MAX_ELEMENTS_VERTICES = 0x80e8;
static const Word GL_MAX_ELEMENTS_INDICES = 0x80e9;
static const Word GL_CLAMP_TO_EDGE = 0x812f;
static const Word GL_TEXTURE_MIN_LOD = 0x813a;
static const Word GL_TEXTURE_MAX_LOD = 0x813b;
static const Word GL_TEXTURE_BASE_LEVEL = 0x813c;
static const Word GL_TEXTURE_MAX_LEVEL = 0x813d;
static const Word GL_LIGHT_MODEL_COLOR_CONTROL = 0x81f8;
static const Word GL_SINGLE_COLOR = 0x81f9;
static const Word GL_SEPARATE_SPECULAR_COLOR = 0x81fa;
static const Word GL_SMOOTH_POINT_SIZE_RANGE = 0xb12;
static const Word GL_SMOOTH_POINT_SIZE_GRANULARITY = 0xb13;
static const Word GL_SMOOTH_LINE_WIDTH_RANGE = 0xb22;
static const Word GL_SMOOTH_LINE_WIDTH_GRANULARITY = 0xb23;
static const Word GL_ALIASED_POINT_SIZE_RANGE = 0x846d;
static const Word GL_ALIASED_LINE_WIDTH_RANGE = 0x846e;
static const Word GL_TEXTURE0 = 0x84c0;
static const Word GL_TEXTURE1 = 0x84c1;
static const Word GL_TEXTURE2 = 0x84c2;
static const Word GL_TEXTURE3 = 0x84c3;
static const Word GL_TEXTURE4 = 0x84c4;
static const Word GL_TEXTURE5 = 0x84c5;
static const Word GL_TEXTURE6 = 0x84c6;
static const Word GL_TEXTURE7 = 0x84c7;
static const Word GL_TEXTURE8 = 0x84c8;
static const Word GL_TEXTURE9 = 0x84c9;
static const Word GL_TEXTURE10 = 0x84ca;
static const Word GL_TEXTURE11 = 0x84cb;
static const Word GL_TEXTURE12 = 0x84cc;
static const Word GL_TEXTURE13 = 0x84cd;
static const Word GL_TEXTURE14 = 0x84ce;
static const Word GL_TEXTURE15 = 0x84cf;
static const Word GL_TEXTURE16 = 0x84d0;
static const Word GL_TEXTURE17 = 0x84d1;
static const Word GL_TEXTURE18 = 0x84d2;
static const Word GL_TEXTURE19 = 0x84d3;
static const Word GL_TEXTURE20 = 0x84d4;
static const Word GL_TEXTURE21 = 0x84d5;
static const Word GL_TEXTURE22 = 0x84d6;
static const Word GL_TEXTURE23 = 0x84d7;
static const Word GL_TEXTURE24 = 0x84d8;
static const Word GL_TEXTURE25 = 0x84d9;
static const Word GL_TEXTURE26 = 0x84da;
static const Word GL_TEXTURE27 = 0x84db;
static const Word GL_TEXTURE28 = 0x84dc;
static const Word GL_TEXTURE29 = 0x84dd;
static const Word GL_TEXTURE30 = 0x84de;
static const Word GL_TEXTURE31 = 0x84df;
static const Word GL_ACTIVE_TEXTURE = 0x84e0;
static const Word GL_CLIENT_ACTIVE_TEXTURE = 0x84e1;
static const Word GL_MAX_TEXTURE_UNITS = 0x84e2;
static const Word GL_TRANSPOSE_MODELVIEW_MATRIX = 0x84e3;
static const Word GL_TRANSPOSE_PROJECTION_MATRIX = 0x84e4;
static const Word GL_TRANSPOSE_TEXTURE_MATRIX = 0x84e5;
static const Word GL_TRANSPOSE_COLOR_MATRIX = 0x84e6;
static const Word GL_MULTISAMPLE = 0x809d;
static const Word GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809e;
static const Word GL_SAMPLE_ALPHA_TO_ONE = 0x809f;
static const Word GL_SAMPLE_COVERAGE = 0x80a0;
static const Word GL_SAMPLE_BUFFERS = 0x80a8;
static const Word GL_SAMPLES = 0x80a9;
static const Word GL_SAMPLE_COVERAGE_VALUE = 0x80aa;
static const Word GL_SAMPLE_COVERAGE_INVERT = 0x80ab;
static const int GL_MULTISAMPLE_BIT = 0x20000000;
static const Word GL_NORMAL_MAP = 0x8511;
static const Word GL_REFLECTION_MAP = 0x8512;
static const Word GL_TEXTURE_CUBE_MAP = 0x8513;
static const Word GL_TEXTURE_BINDING_CUBE_MAP = 0x8514;
static const Word GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
static const Word GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
static const Word GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
static const Word GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
static const Word GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
static const Word GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851a;
static const Word GL_PROXY_TEXTURE_CUBE_MAP = 0x851b;
static const Word GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851c;
static const Word GL_COMPRESSED_ALPHA = 0x84e9;
static const Word GL_COMPRESSED_LUMINANCE = 0x84ea;
static const Word GL_COMPRESSED_LUMINANCE_ALPHA = 0x84eb;
static const Word GL_COMPRESSED_INTENSITY = 0x84ec;
static const Word GL_COMPRESSED_RGB = 0x84ed;
static const Word GL_COMPRESSED_RGBA = 0x84ee;
static const Word GL_TEXTURE_COMPRESSION_HINT = 0x84ef;
static const Word GL_TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86a0;
static const Word GL_TEXTURE_COMPRESSED = 0x86a1;
static const Word GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86a2;
static const Word GL_COMPRESSED_TEXTURE_FORMATS = 0x86a3;
static const Word GL_CLAMP_TO_BORDER = 0x812d;
static const Word GL_CLAMP_TO_BORDER_SGIS = 0x812d;
static const Word GL_COMBINE = 0x8570;
static const Word GL_COMBINE_RGB = 0x8571;
static const Word GL_COMBINE_ALPHA = 0x8572;
static const Word GL_SOURCE0_RGB = 0x8580;
static const Word GL_SOURCE1_RGB = 0x8581;
static const Word GL_SOURCE2_RGB = 0x8582;
static const Word GL_SOURCE0_ALPHA = 0x8588;
static const Word GL_SOURCE1_ALPHA = 0x8589;
static const Word GL_SOURCE2_ALPHA = 0x858a;
static const Word GL_OPERAND0_RGB = 0x8590;
static const Word GL_OPERAND1_RGB = 0x8591;
static const Word GL_OPERAND2_RGB = 0x8592;
static const Word GL_OPERAND0_ALPHA = 0x8598;
static const Word GL_OPERAND1_ALPHA = 0x8599;
static const Word GL_OPERAND2_ALPHA = 0x859a;
static const Word GL_RGB_SCALE = 0x8573;
static const Word GL_ADD_SIGNED = 0x8574;
static const Word GL_INTERPOLATE = 0x8575;
static const Word GL_SUBTRACT = 0x84e7;
static const Word GL_CONSTANT = 0x8576;
static const Word GL_PRIMARY_COLOR = 0x8577;
static const Word GL_PREVIOUS = 0x8578;
static const Word GL_DOT3_RGB = 0x86ae;
static const Word GL_DOT3_RGBA = 0x86af;
static const Word GL_BLEND_DST_RGB = 0x80c8;
static const Word GL_BLEND_SRC_RGB = 0x80c9;
static const Word GL_BLEND_DST_ALPHA = 0x80ca;
static const Word GL_BLEND_SRC_ALPHA = 0x80cb;
static const Word GL_POINT_SIZE_MIN = 0x8126;
static const Word GL_POINT_SIZE_MAX = 0x8127;
static const Word GL_POINT_FADE_THRESHOLD_SIZE = 0x8128;
static const Word GL_POINT_DISTANCE_ATTENUATION = 0x8129;
static const Word GL_GENERATE_MIPMAP = 0x8191;
static const Word GL_GENERATE_MIPMAP_HINT = 0x8192;
static const Word GL_DEPTH_COMPONENT16 = 0x81a5;
static const Word GL_DEPTH_COMPONENT24 = 0x81a6;
static const Word GL_DEPTH_COMPONENT32 = 0x81a7;
static const Word GL_MIRRORED_REPEAT = 0x8370;
static const Word GL_FOG_COORDINATE_SOURCE = 0x8450;
static const Word GL_FOG_COORDINATE = 0x8451;
static const Word GL_FRAGMENT_DEPTH = 0x8452;
static const Word GL_CURRENT_FOG_COORDINATE = 0x8453;
static const Word GL_FOG_COORDINATE_ARRAY_TYPE = 0x8454;
static const Word GL_FOG_COORDINATE_ARRAY_STRIDE = 0x8455;
static const Word GL_FOG_COORDINATE_ARRAY_POINTER = 0x8456;
static const Word GL_FOG_COORDINATE_ARRAY = 0x8457;
static const Word GL_COLOR_SUM = 0x8458;
static const Word GL_CURRENT_SECONDARY_COLOR = 0x8459;
static const Word GL_SECONDARY_COLOR_ARRAY_SIZE = 0x845a;
static const Word GL_SECONDARY_COLOR_ARRAY_TYPE = 0x845b;
static const Word GL_SECONDARY_COLOR_ARRAY_STRIDE = 0x845c;
static const Word GL_SECONDARY_COLOR_ARRAY_POINTER = 0x845d;
static const Word GL_SECONDARY_COLOR_ARRAY = 0x845e;
static const Word GL_MAX_TEXTURE_LOD_BIAS = 0x84fd;
static const Word GL_TEXTURE_FILTER_CONTROL = 0x8500;
static const Word GL_TEXTURE_LOD_BIAS = 0x8501;
static const Word GL_INCR_WRAP = 0x8507;
static const Word GL_DECR_WRAP = 0x8508;
static const Word GL_TEXTURE_DEPTH_SIZE = 0x884a;
static const Word GL_DEPTH_TEXTURE_MODE = 0x884b;
static const Word GL_TEXTURE_COMPARE_MODE = 0x884c;
static const Word GL_TEXTURE_COMPARE_FUNC = 0x884d;
static const Word GL_COMPARE_R_TO_TEXTURE = 0x884e;
static const Word GL_BUFFER_SIZE = 0x8764;
static const Word GL_BUFFER_USAGE = 0x8765;
static const Word GL_QUERY_COUNTER_BITS = 0x8864;
static const Word GL_CURRENT_QUERY = 0x8865;
static const Word GL_QUERY_RESULT = 0x8866;
static const Word GL_QUERY_RESULT_AVAILABLE = 0x8867;
static const Word GL_ARRAY_BUFFER = 0x8892;
static const Word GL_ELEMENT_ARRAY_BUFFER = 0x8893;
static const Word GL_ARRAY_BUFFER_BINDING = 0x8894;
static const Word GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
static const Word GL_VERTEX_ARRAY_BUFFER_BINDING = 0x8896;
static const Word GL_NORMAL_ARRAY_BUFFER_BINDING = 0x8897;
static const Word GL_COLOR_ARRAY_BUFFER_BINDING = 0x8898;
static const Word GL_INDEX_ARRAY_BUFFER_BINDING = 0x8899;
static const Word GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING = 0x889a;
static const Word GL_EDGE_FLAG_ARRAY_BUFFER_BINDING = 0x889b;
static const Word GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING = 0x889c;
static const Word GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING = 0x889d;
static const Word GL_WEIGHT_ARRAY_BUFFER_BINDING = 0x889e;
static const Word GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889f;
static const Word GL_READ_ONLY = 0x88b8;
static const Word GL_WRITE_ONLY = 0x88b9;
static const Word GL_READ_WRITE = 0x88ba;
static const Word GL_BUFFER_ACCESS = 0x88bb;
static const Word GL_BUFFER_MAPPED = 0x88bc;
static const Word GL_BUFFER_MAP_POINTER = 0x88bd;
static const Word GL_STREAM_DRAW = 0x88e0;
static const Word GL_STREAM_READ = 0x88e1;
static const Word GL_STREAM_COPY = 0x88e2;
static const Word GL_STATIC_DRAW = 0x88e4;
static const Word GL_STATIC_READ = 0x88e5;
static const Word GL_STATIC_COPY = 0x88e6;
static const Word GL_DYNAMIC_DRAW = 0x88e8;
static const Word GL_DYNAMIC_READ = 0x88e9;
static const Word GL_DYNAMIC_COPY = 0x88ea;
static const Word GL_SAMPLES_PASSED = 0x8914;
static const Word GL_FOG_COORD_SRC = 0x8450;
static const Word GL_FOG_COORD = 0x8451;
static const Word GL_CURRENT_FOG_COORD = 0x8453;
static const Word GL_FOG_COORD_ARRAY_TYPE = 0x8454;
static const Word GL_FOG_COORD_ARRAY_STRIDE = 0x8455;
static const Word GL_FOG_COORD_ARRAY_POINTER = 0x8456;
static const Word GL_FOG_COORD_ARRAY = 0x8457;
static const Word GL_FOG_COORD_ARRAY_BUFFER_BINDING = 0x889d;
static const Word GL_SRC0_RGB = 0x8580;
static const Word GL_SRC1_RGB = 0x8581;
static const Word GL_SRC2_RGB = 0x8582;
static const Word GL_SRC0_ALPHA = 0x8588;
static const Word GL_SRC1_ALPHA = 0x8589;
static const Word GL_SRC2_ALPHA = 0x858a;
static const Word GL_BLEND_EQUATION_RGB = 0x8009;
static const Word GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
static const Word GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
static const Word GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
static const Word GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
static const Word GL_CURRENT_VERTEX_ATTRIB = 0x8626;
static const Word GL_VERTEX_PROGRAM_POINT_SIZE = 0x8642;
static const Word GL_VERTEX_PROGRAM_TWO_SIDE = 0x8643;
static const Word GL_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
static const Word GL_STENCIL_BACK_FUNC = 0x8800;
static const Word GL_STENCIL_BACK_FAIL = 0x8801;
static const Word GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
static const Word GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
static const Word GL_MAX_DRAW_BUFFERS = 0x8824;
static const Word GL_DRAW_BUFFER0 = 0x8825;
static const Word GL_DRAW_BUFFER1 = 0x8826;
static const Word GL_DRAW_BUFFER2 = 0x8827;
static const Word GL_DRAW_BUFFER3 = 0x8828;
static const Word GL_DRAW_BUFFER4 = 0x8829;
static const Word GL_DRAW_BUFFER5 = 0x882a;
static const Word GL_DRAW_BUFFER6 = 0x882b;
static const Word GL_DRAW_BUFFER7 = 0x882c;
static const Word GL_DRAW_BUFFER8 = 0x882d;
static const Word GL_DRAW_BUFFER9 = 0x882e;
static const Word GL_DRAW_BUFFER10 = 0x882f;
static const Word GL_DRAW_BUFFER11 = 0x8830;
static const Word GL_DRAW_BUFFER12 = 0x8831;
static const Word GL_DRAW_BUFFER13 = 0x8832;
static const Word GL_DRAW_BUFFER14 = 0x8833;
static const Word GL_DRAW_BUFFER15 = 0x8834;
static const Word GL_BLEND_EQUATION_ALPHA = 0x883d;
static const Word GL_POINT_SPRITE = 0x8861;
static const Word GL_COORD_REPLACE = 0x8862;
static const Word GL_MAX_VERTEX_ATTRIBS = 0x8869;
static const Word GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886a;
static const Word GL_MAX_TEXTURE_COORDS = 0x8871;
static const Word GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872;
static const Word GL_FRAGMENT_SHADER = 0x8b30;
static const Word GL_VERTEX_SHADER = 0x8b31;
static const Word GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8b49;
static const Word GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8b4a;
static const Word GL_MAX_VARYING_FLOATS = 0x8b4b;
static const Word GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8b4c;
static const Word GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8b4d;
static const Word GL_SHADER_TYPE = 0x8b4f;
static const Word GL_FLOAT_VEC2 = 0x8b50;
static const Word GL_FLOAT_VEC3 = 0x8b51;
static const Word GL_FLOAT_VEC4 = 0x8b52;
static const Word GL_INT_VEC2 = 0x8b53;
static const Word GL_INT_VEC3 = 0x8b54;
static const Word GL_INT_VEC4 = 0x8b55;
static const Word GL_BOOL = 0x8b56;
static const Word GL_BOOL_VEC2 = 0x8b57;
static const Word GL_BOOL_VEC3 = 0x8b58;
static const Word GL_BOOL_VEC4 = 0x8b59;
static const Word GL_FLOAT_MAT2 = 0x8b5a;
static const Word GL_FLOAT_MAT3 = 0x8b5b;
static const Word GL_FLOAT_MAT4 = 0x8b5c;
static const Word GL_SAMPLER_1D = 0x8b5d;
static const Word GL_SAMPLER_2D = 0x8b5e;
static const Word GL_SAMPLER_3D = 0x8b5f;
static const Word GL_SAMPLER_CUBE = 0x8b60;
static const Word GL_SAMPLER_1D_SHADOW = 0x8b61;
static const Word GL_SAMPLER_2D_SHADOW = 0x8b62;
static const Word GL_DELETE_STATUS = 0x8b80;
static const Word GL_COMPILE_STATUS = 0x8b81;
static const Word GL_LINK_STATUS = 0x8b82;
static const Word GL_VALIDATE_STATUS = 0x8b83;
static const Word GL_INFO_LOG_LENGTH = 0x8b84;
static const Word GL_ATTACHED_SHADERS = 0x8b85;
static const Word GL_ACTIVE_UNIFORMS = 0x8b86;
static const Word GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8b87;
static const Word GL_SHADER_SOURCE_LENGTH = 0x8b88;
static const Word GL_ACTIVE_ATTRIBUTES = 0x8b89;
static const Word GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8b8a;
static const Word GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8b8b;
static const Word GL_SHADING_LANGUAGE_VERSION = 0x8b8c;
static const Word GL_CURRENT_PROGRAM = 0x8b8d;
static const Word GL_POINT_SPRITE_COORD_ORIGIN = 0x8ca0;
static const Word GL_LOWER_LEFT = 0x8ca1;
static const Word GL_UPPER_LEFT = 0x8ca2;
static const Word GL_STENCIL_BACK_REF = 0x8ca3;
static const Word GL_STENCIL_BACK_VALUE_MASK = 0x8ca4;
static const Word GL_STENCIL_BACK_WRITEMASK = 0x8ca5;
static const Word GL_MULTISAMPLE_3DFX = 0x86b2;
static const Word GL_SAMPLE_BUFFERS_3DFX = 0x86b3;
static const Word GL_SAMPLES_3DFX = 0x86b4;
static const int GL_MULTISAMPLE_BIT_3DFX = 0x20000000;
static const Word GL_COMPRESSED_RGB_FXT1_3DFX = 0x86b0;
static const Word GL_COMPRESSED_RGBA_FXT1_3DFX = 0x86b1;
static const Word GL_UNPACK_CLIENT_STORAGE_APPLE = 0x85b2;
static const Word GL_ELEMENT_ARRAY_APPLE = 0x8768;
static const Word GL_ELEMENT_ARRAY_TYPE_APPLE = 0x8769;
static const Word GL_ELEMENT_ARRAY_POINTER_APPLE = 0x876a;
static const Word GL_DRAW_PIXELS_APPLE = 0x8a0a;
static const Word GL_FENCE_APPLE = 0x8a0b;
static const Word GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE = 0x85b0;
static const Word GL_TRANSFORM_HINT_APPLE = 0x85b1;
static const Word GL_VERTEX_ARRAY_BINDING_APPLE = 0x85b5;
static const Word GL_VERTEX_ARRAY_RANGE_APPLE = 0x851d;
static const Word GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE = 0x851e;
static const Word GL_VERTEX_ARRAY_STORAGE_HINT_APPLE = 0x851f;
static const Word GL_VERTEX_ARRAY_RANGE_POINTER_APPLE = 0x8521;
static const Word GL_STORAGE_CACHED_APPLE = 0x85be;
static const Word GL_STORAGE_SHARED_APPLE = 0x85bf;
static const Word GL_YCBCR_422_APPLE = 0x85b9;
static const Word GL_UNSIGNED_SHORT_8_8_APPLE = 0x85ba;
static const Word GL_UNSIGNED_SHORT_8_8_REV_APPLE = 0x85bb;
static const Word GL_DEPTH_COMPONENT16_ARB = 0x81a5;
static const Word GL_DEPTH_COMPONENT24_ARB = 0x81a6;
static const Word GL_DEPTH_COMPONENT32_ARB = 0x81a7;
static const Word GL_TEXTURE_DEPTH_SIZE_ARB = 0x884a;
static const Word GL_DEPTH_TEXTURE_MODE_ARB = 0x884b;
static const Word GL_FRAGMENT_PROGRAM_ARB = 0x8804;
static const Word GL_PROGRAM_ALU_INSTRUCTIONS_ARB = 0x8805;
static const Word GL_PROGRAM_TEX_INSTRUCTIONS_ARB = 0x8806;
static const Word GL_PROGRAM_TEX_INDIRECTIONS_ARB = 0x8807;
static const Word GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB = 0x8808;
static const Word GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB = 0x8809;
static const Word GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB = 0x880a;
static const Word GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB = 0x880b;
static const Word GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB = 0x880c;
static const Word GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB = 0x880d;
static const Word GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB = 0x880e;
static const Word GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB = 0x880f;
static const Word GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB = 0x8810;
static const Word GL_MAX_TEXTURE_COORDS_ARB = 0x8871;
static const Word GL_MAX_TEXTURE_IMAGE_UNITS_ARB = 0x8872;
static const Word GL_CONSTANT_COLOR_ARB = 0x8001;
static const Word GL_ONE_MINUS_CONSTANT_COLOR = 0x8002;
static const Word GL_CONSTANT_ALPHA = 0x8003;
static const Word GL_ONE_MINUS_CONSTANT_ALPHA = 0x8004;
static const Word GL_BLEND_COLOR = 0x8005;
static const Word GL_FUNC_ADD = 0x8006;
static const Word GL_MIN = 0x8007;
static const Word GL_MAX = 0x8008;
static const Word GL_BLEND_EQUATION = 0x8009;
static const Word GL_FUNC_SUBTRACT = 0x800a;
static const Word GL_FUNC_REVERSE_SUBTRACT = 0x800b;
static const Word GL_CONVOLUTION_1D = 0x8010;
static const Word GL_CONVOLUTION_2D = 0x8011;
static const Word GL_SEPARABLE_2D = 0x8012;
static const Word GL_CONVOLUTION_BORDER_MODE = 0x8013;
static const Word GL_CONVOLUTION_FILTER_SCALE = 0x8014;
static const Word GL_CONVOLUTION_FILTER_BIAS = 0x8015;
static const Word GL_REDUCE = 0x8016;
static const Word GL_CONVOLUTION_FORMAT = 0x8017;
static const Word GL_CONVOLUTION_WIDTH = 0x8018;
static const Word GL_CONVOLUTION_HEIGHT = 0x8019;
static const Word GL_MAX_CONVOLUTION_WIDTH = 0x801a;
static const Word GL_MAX_CONVOLUTION_HEIGHT = 0x801b;
static const Word GL_POST_CONVOLUTION_RED_SCALE = 0x801c;
static const Word GL_POST_CONVOLUTION_GREEN_SCALE = 0x801d;
static const Word GL_POST_CONVOLUTION_BLUE_SCALE = 0x801e;
static const Word GL_POST_CONVOLUTION_ALPHA_SCALE = 0x801f;
static const Word GL_POST_CONVOLUTION_RED_BIAS = 0x8020;
static const Word GL_POST_CONVOLUTION_GREEN_BIAS = 0x8021;
static const Word GL_POST_CONVOLUTION_BLUE_BIAS = 0x8022;
static const Word GL_POST_CONVOLUTION_ALPHA_BIAS = 0x8023;
static const Word GL_HISTOGRAM = 0x8024;
static const Word GL_PROXY_HISTOGRAM = 0x8025;
static const Word GL_HISTOGRAM_WIDTH = 0x8026;
static const Word GL_HISTOGRAM_FORMAT = 0x8027;
static const Word GL_HISTOGRAM_RED_SIZE = 0x8028;
static const Word GL_HISTOGRAM_GREEN_SIZE = 0x8029;
static const Word GL_HISTOGRAM_BLUE_SIZE = 0x802a;
static const Word GL_HISTOGRAM_ALPHA_SIZE = 0x802b;
static const Word GL_HISTOGRAM_LUMINANCE_SIZE = 0x802c;
static const Word GL_HISTOGRAM_SINK = 0x802d;
static const Word GL_MINMAX = 0x802e;
static const Word GL_MINMAX_FORMAT = 0x802f;
static const Word GL_MINMAX_SINK = 0x8030;
static const Word GL_TABLE_TOO_LARGE = 0x8031;
static const Word GL_COLOR_MATRIX = 0x80b1;
static const Word GL_COLOR_MATRIX_STACK_DEPTH = 0x80b2;
static const Word GL_MAX_COLOR_MATRIX_STACK_DEPTH = 0x80b3;
static const Word GL_POST_COLOR_MATRIX_RED_SCALE = 0x80b4;
static const Word GL_POST_COLOR_MATRIX_GREEN_SCALE = 0x80b5;
static const Word GL_POST_COLOR_MATRIX_BLUE_SCALE = 0x80b6;
static const Word GL_POST_COLOR_MATRIX_ALPHA_SCALE = 0x80b7;
static const Word GL_POST_COLOR_MATRIX_RED_BIAS = 0x80b8;
static const Word GL_POST_COLOR_MATRIX_GREEN_BIAS = 0x80b9;
static const Word GL_POST_COLOR_MATRIX_BLUE_BIAS = 0x80ba;
static const Word GL_POST_COLOR_MATRIX_ALPHA_BIAS = 0x80bb;
static const Word GL_COLOR_TABLE = 0x80d0;
static const Word GL_POST_CONVOLUTION_COLOR_TABLE = 0x80d1;
static const Word GL_POST_COLOR_MATRIX_COLOR_TABLE = 0x80d2;
static const Word GL_PROXY_COLOR_TABLE = 0x80d3;
static const Word GL_PROXY_POST_CONVOLUTION_COLOR_TABLE = 0x80d4;
static const Word GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE = 0x80d5;
static const Word GL_COLOR_TABLE_SCALE = 0x80d6;
static const Word GL_COLOR_TABLE_BIAS = 0x80d7;
static const Word GL_COLOR_TABLE_FORMAT = 0x80d8;
static const Word GL_COLOR_TABLE_WIDTH = 0x80d9;
static const Word GL_COLOR_TABLE_RED_SIZE = 0x80da;
static const Word GL_COLOR_TABLE_GREEN_SIZE = 0x80db;
static const Word GL_COLOR_TABLE_BLUE_SIZE = 0x80dc;
static const Word GL_COLOR_TABLE_ALPHA_SIZE = 0x80dd;
static const Word GL_COLOR_TABLE_LUMINANCE_SIZE = 0x80de;
static const Word GL_COLOR_TABLE_INTENSITY_SIZE = 0x80df;
static const Word GL_CONSTANT_BORDER = 0x8151;
static const Word GL_REPLICATE_BORDER = 0x8153;
static const Word GL_CONVOLUTION_BORDER_COLOR = 0x8154;
static const Word GL_MATRIX_PALETTE_ARB = 0x8840;
static const Word GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB = 0x8841;
static const Word GL_MAX_PALETTE_MATRICES_ARB = 0x8842;
static const Word GL_CURRENT_PALETTE_MATRIX_ARB = 0x8843;
static const Word GL_MATRIX_INDEX_ARRAY_ARB = 0x8844;
static const Word GL_CURRENT_MATRIX_INDEX_ARB = 0x8845;
static const Word GL_MATRIX_INDEX_ARRAY_SIZE_ARB = 0x8846;
static const Word GL_MATRIX_INDEX_ARRAY_TYPE_ARB = 0x8847;
static const Word GL_MATRIX_INDEX_ARRAY_STRIDE_ARB = 0x8848;
static const Word GL_MATRIX_INDEX_ARRAY_POINTER_ARB = 0x8849;
static const Word GL_MULTISAMPLE_ARB = 0x809d;
static const Word GL_SAMPLE_ALPHA_TO_COVERAGE_ARB = 0x809e;
static const Word GL_SAMPLE_ALPHA_TO_ONE_ARB = 0x809f;
static const Word GL_SAMPLE_COVERAGE_ARB = 0x80a0;
static const Word GL_SAMPLE_BUFFERS_ARB = 0x80a8;
static const Word GL_SAMPLES_ARB = 0x80a9;
static const Word GL_SAMPLE_COVERAGE_VALUE_ARB = 0x80aa;
static const Word GL_SAMPLE_COVERAGE_INVERT_ARB = 0x80ab;
static const int GL_MULTISAMPLE_BIT_ARB = 0x20000000;
static const Word GL_TEXTURE0_ARB = 0x84c0;
static const Word GL_TEXTURE1_ARB = 0x84c1;
static const Word GL_TEXTURE2_ARB = 0x84c2;
static const Word GL_TEXTURE3_ARB = 0x84c3;
static const Word GL_TEXTURE4_ARB = 0x84c4;
static const Word GL_TEXTURE5_ARB = 0x84c5;
static const Word GL_TEXTURE6_ARB = 0x84c6;
static const Word GL_TEXTURE7_ARB = 0x84c7;
static const Word GL_TEXTURE8_ARB = 0x84c8;
static const Word GL_TEXTURE9_ARB = 0x84c9;
static const Word GL_TEXTURE10_ARB = 0x84ca;
static const Word GL_TEXTURE11_ARB = 0x84cb;
static const Word GL_TEXTURE12_ARB = 0x84cc;
static const Word GL_TEXTURE13_ARB = 0x84cd;
static const Word GL_TEXTURE14_ARB = 0x84ce;
static const Word GL_TEXTURE15_ARB = 0x84cf;
static const Word GL_TEXTURE16_ARB = 0x84d0;
static const Word GL_TEXTURE17_ARB = 0x84d1;
static const Word GL_TEXTURE18_ARB = 0x84d2;
static const Word GL_TEXTURE19_ARB = 0x84d3;
static const Word GL_TEXTURE20_ARB = 0x84d4;
static const Word GL_TEXTURE21_ARB = 0x84d5;
static const Word GL_TEXTURE22_ARB = 0x84d6;
static const Word GL_TEXTURE23_ARB = 0x84d7;
static const Word GL_TEXTURE24_ARB = 0x84d8;
static const Word GL_TEXTURE25_ARB = 0x84d9;
static const Word GL_TEXTURE26_ARB = 0x84da;
static const Word GL_TEXTURE27_ARB = 0x84db;
static const Word GL_TEXTURE28_ARB = 0x84dc;
static const Word GL_TEXTURE29_ARB = 0x84dd;
static const Word GL_TEXTURE30_ARB = 0x84de;
static const Word GL_TEXTURE31_ARB = 0x84df;
static const Word GL_ACTIVE_TEXTURE_ARB = 0x84e0;
static const Word GL_CLIENT_ACTIVE_TEXTURE_ARB = 0x84e1;
static const Word GL_MAX_TEXTURE_UNITS_ARB = 0x84e2;
static const Word GL_POINT_SIZE_MIN_ARB = 0x8126;
static const Word GL_POINT_SIZE_MAX_ARB = 0x8127;
static const Word GL_POINT_FADE_THRESHOLD_SIZE_ARB = 0x8128;
static const Word GL_POINT_DISTANCE_ATTENUATION_ARB = 0x8129;
static const Word GL_TEXTURE_COMPARE_MODE_ARB = 0x884c;
static const Word GL_TEXTURE_COMPARE_FUNC_ARB = 0x884d;
static const Word GL_COMPARE_R_TO_TEXTURE_ARB = 0x884e;
static const Word GL_TEXTURE_COMPARE_FAIL_VALUE_ARB = 0x80bf;
static const Word GL_CLAMP_TO_BORDER_ARB = 0x812d;
static const Word GL_COMPRESSED_ALPHA_ARB = 0x84e9;
static const Word GL_COMPRESSED_LUMINANCE_ARB = 0x84ea;
static const Word GL_COMPRESSED_LUMINANCE_ALPHA_ARB = 0x84eb;
static const Word GL_COMPRESSED_INTENSITY_ARB = 0x84ec;
static const Word GL_COMPRESSED_RGB_ARB = 0x84ed;
static const Word GL_COMPRESSED_RGBA_ARB = 0x84ee;
static const Word GL_TEXTURE_COMPRESSION_HINT_ARB = 0x84ef;
static const Word GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB = 0x86a0;
static const Word GL_TEXTURE_COMPRESSED_ARB = 0x86a1;
static const Word GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB = 0x86a2;
static const Word GL_COMPRESSED_TEXTURE_FORMATS_ARB = 0x86a3;
static const Word GL_NORMAL_MAP_ARB = 0x8511;
static const Word GL_REFLECTION_MAP_ARB = 0x8512;
static const Word GL_TEXTURE_CUBE_MAP_ARB = 0x8513;
static const Word GL_TEXTURE_BINDING_CUBE_MAP_ARB = 0x8514;
static const Word GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB = 0x8515;
static const Word GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB = 0x8516;
static const Word GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB = 0x8517;
static const Word GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB = 0x8518;
static const Word GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB = 0x8519;
static const Word GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB = 0x851a;
static const Word GL_PROXY_TEXTURE_CUBE_MAP_ARB = 0x851b;
static const Word GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB = 0x851c;
static const Word GL_COMBINE_ARB = 0x8570;
static const Word GL_COMBINE_RGB_ARB = 0x8571;
static const Word GL_COMBINE_ALPHA_ARB = 0x8572;
static const Word GL_SOURCE0_RGB_ARB = 0x8580;
static const Word GL_SOURCE1_RGB_ARB = 0x8581;
static const Word GL_SOURCE2_RGB_ARB = 0x8582;
static const Word GL_SOURCE0_ALPHA_ARB = 0x8588;
static const Word GL_SOURCE1_ALPHA_ARB = 0x8589;
static const Word GL_SOURCE2_ALPHA_ARB = 0x858a;
static const Word GL_OPERAND0_RGB_ARB = 0x8590;
static const Word GL_OPERAND1_RGB_ARB = 0x8591;
static const Word GL_OPERAND2_RGB_ARB = 0x8592;
static const Word GL_OPERAND0_ALPHA_ARB = 0x8598;
static const Word GL_OPERAND1_ALPHA_ARB = 0x8599;
static const Word GL_OPERAND2_ALPHA_ARB = 0x859a;
static const Word GL_RGB_SCALE_ARB = 0x8573;
static const Word GL_ADD_SIGNED_ARB = 0x8574;
static const Word GL_INTERPOLATE_ARB = 0x8575;
static const Word GL_SUBTRACT_ARB = 0x84e7;
static const Word GL_CONSTANT_ARB = 0x8576;
static const Word GL_PRIMARY_COLOR_ARB = 0x8577;
static const Word GL_PREVIOUS_ARB = 0x8578;
static const Word GL_DOT3_RGB_ARB = 0x86ae;
static const Word GL_DOT3_RGBA_ARB = 0x86af;
static const Word GL_MIRRORED_REPEAT_ARB = 0x8370;
static const Word GL_TRANSPOSE_MODELVIEW_MATRIX_ARB = 0x84e3;
static const Word GL_TRANSPOSE_PROJECTION_MATRIX_ARB = 0x84e4;
static const Word GL_TRANSPOSE_TEXTURE_MATRIX_ARB = 0x84e5;
static const Word GL_TRANSPOSE_COLOR_MATRIX_ARB = 0x84e6;
static const Word GL_MAX_VERTEX_UNITS_ARB = 0x86a4;
static const Word GL_ACTIVE_VERTEX_UNITS_ARB = 0x86a5;
static const Word GL_WEIGHT_SUM_UNITY_ARB = 0x86a6;
static const Word GL_VERTEX_BLEND_ARB = 0x86a7;
static const Word GL_CURRENT_WEIGHT_ARB = 0x86a8;
static const Word GL_WEIGHT_ARRAY_TYPE_ARB = 0x86a9;
static const Word GL_WEIGHT_ARRAY_STRIDE_ARB = 0x86aa;
static const Word GL_WEIGHT_ARRAY_SIZE_ARB = 0x86ab;
static const Word GL_WEIGHT_ARRAY_POINTER_ARB = 0x86ac;
static const Word GL_WEIGHT_ARRAY_ARB = 0x86ad;
static const Word GL_MODELVIEW0_ARB = 0x1700;
static const Word GL_MODELVIEW1_ARB = 0x850a;
static const Word GL_MODELVIEW2_ARB = 0x8722;
static const Word GL_MODELVIEW3_ARB = 0x8723;
static const Word GL_MODELVIEW4_ARB = 0x8724;
static const Word GL_MODELVIEW5_ARB = 0x8725;
static const Word GL_MODELVIEW6_ARB = 0x8726;
static const Word GL_MODELVIEW7_ARB = 0x8727;
static const Word GL_MODELVIEW8_ARB = 0x8728;
static const Word GL_MODELVIEW9_ARB = 0x8729;
static const Word GL_MODELVIEW10_ARB = 0x872a;
static const Word GL_MODELVIEW11_ARB = 0x872b;
static const Word GL_MODELVIEW12_ARB = 0x872c;
static const Word GL_MODELVIEW13_ARB = 0x872d;
static const Word GL_MODELVIEW14_ARB = 0x872e;
static const Word GL_MODELVIEW15_ARB = 0x872f;
static const Word GL_MODELVIEW16_ARB = 0x8730;
static const Word GL_MODELVIEW17_ARB = 0x8731;
static const Word GL_MODELVIEW18_ARB = 0x8732;
static const Word GL_MODELVIEW19_ARB = 0x8733;
static const Word GL_MODELVIEW20_ARB = 0x8734;
static const Word GL_MODELVIEW21_ARB = 0x8735;
static const Word GL_MODELVIEW22_ARB = 0x8736;
static const Word GL_MODELVIEW23_ARB = 0x8737;
static const Word GL_MODELVIEW24_ARB = 0x8738;
static const Word GL_MODELVIEW25_ARB = 0x8739;
static const Word GL_MODELVIEW26_ARB = 0x873a;
static const Word GL_MODELVIEW27_ARB = 0x873b;
static const Word GL_MODELVIEW28_ARB = 0x873c;
static const Word GL_MODELVIEW29_ARB = 0x873d;
static const Word GL_MODELVIEW30_ARB = 0x873e;
static const Word GL_MODELVIEW31_ARB = 0x873f;
static const Word GL_BUFFER_SIZE_ARB = 0x8764;
static const Word GL_BUFFER_USAGE_ARB = 0x8765;
static const Word GL_ARRAY_BUFFER_ARB = 0x8892;
static const Word GL_ELEMENT_ARRAY_BUFFER_ARB = 0x8893;
static const Word GL_ARRAY_BUFFER_BINDING_ARB = 0x8894;
static const Word GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB = 0x8895;
static const Word GL_VERTEX_ARRAY_BUFFER_BINDING_ARB = 0x8896;
static const Word GL_NORMAL_ARRAY_BUFFER_BINDING_ARB = 0x8897;
static const Word GL_COLOR_ARRAY_BUFFER_BINDING_ARB = 0x8898;
static const Word GL_INDEX_ARRAY_BUFFER_BINDING_ARB = 0x8899;
static const Word GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB = 0x889a;
static const Word GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB = 0x889b;
static const Word GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB = 0x889c;
static const Word GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB = 0x889d;
static const Word GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB = 0x889e;
static const Word GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB = 0x889f;
static const Word GL_READ_ONLY_ARB = 0x88b8;
static const Word GL_WRITE_ONLY_ARB = 0x88b9;
static const Word GL_READ_WRITE_ARB = 0x88ba;
static const Word GL_BUFFER_ACCESS_ARB = 0x88bb;
static const Word GL_BUFFER_MAPPED_ARB = 0x88bc;
static const Word GL_BUFFER_MAP_POINTER_ARB = 0x88bd;
static const Word GL_STREAM_DRAW_ARB = 0x88e0;
static const Word GL_STREAM_READ_ARB = 0x88e1;
static const Word GL_STREAM_COPY_ARB = 0x88e2;
static const Word GL_STATIC_DRAW_ARB = 0x88e4;
static const Word GL_STATIC_READ_ARB = 0x88e5;
static const Word GL_STATIC_COPY_ARB = 0x88e6;
static const Word GL_DYNAMIC_DRAW_ARB = 0x88e8;
static const Word GL_DYNAMIC_READ_ARB = 0x88e9;
static const Word GL_DYNAMIC_COPY_ARB = 0x88ea;
static const Word GL_COLOR_SUM_ARB = 0x8458;
static const Word GL_VERTEX_PROGRAM_ARB = 0x8620;
static const Word GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB = 0x8622;
static const Word GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB = 0x8623;
static const Word GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB = 0x8624;
static const Word GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB = 0x8625;
static const Word GL_CURRENT_VERTEX_ATTRIB_ARB = 0x8626;
static const Word GL_PROGRAM_LENGTH_ARB = 0x8627;
static const Word GL_PROGRAM_STRING_ARB = 0x8628;
static const Word GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB = 0x862e;
static const Word GL_MAX_PROGRAM_MATRICES_ARB = 0x862f;
static const Word GL_CURRENT_MATRIX_STACK_DEPTH_ARB = 0x8640;
static const Word GL_CURRENT_MATRIX_ARB = 0x8641;
static const Word GL_VERTEX_PROGRAM_POINT_SIZE_ARB = 0x8642;
static const Word GL_VERTEX_PROGRAM_TWO_SIDE_ARB = 0x8643;
static const Word GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB = 0x8645;
static const Word GL_PROGRAM_ERROR_POSITION_ARB = 0x864b;
static const Word GL_PROGRAM_BINDING_ARB = 0x8677;
static const Word GL_MAX_VERTEX_ATTRIBS_ARB = 0x8869;
static const Word GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB = 0x886a;
static const Word GL_PROGRAM_ERROR_STRING_ARB = 0x8874;
static const Word GL_PROGRAM_FORMAT_ASCII_ARB = 0x8875;
static const Word GL_PROGRAM_FORMAT_ARB = 0x8876;
static const Word GL_PROGRAM_INSTRUCTIONS_ARB = 0x88a0;
static const Word GL_MAX_PROGRAM_INSTRUCTIONS_ARB = 0x88a1;
static const Word GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB = 0x88a2;
static const Word GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB = 0x88a3;
static const Word GL_PROGRAM_TEMPORARIES_ARB = 0x88a4;
static const Word GL_MAX_PROGRAM_TEMPORARIES_ARB = 0x88a5;
static const Word GL_PROGRAM_NATIVE_TEMPORARIES_ARB = 0x88a6;
static const Word GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB = 0x88a7;
static const Word GL_PROGRAM_PARAMETERS_ARB = 0x88a8;
static const Word GL_MAX_PROGRAM_PARAMETERS_ARB = 0x88a9;
static const Word GL_PROGRAM_NATIVE_PARAMETERS_ARB = 0x88aa;
static const Word GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB = 0x88ab;
static const Word GL_PROGRAM_ATTRIBS_ARB = 0x88ac;
static const Word GL_MAX_PROGRAM_ATTRIBS_ARB = 0x88ad;
static const Word GL_PROGRAM_NATIVE_ATTRIBS_ARB = 0x88ae;
static const Word GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB = 0x88af;
static const Word GL_PROGRAM_ADDRESS_REGISTERS_ARB = 0x88b0;
static const Word GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB = 0x88b1;
static const Word GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB = 0x88b2;
static const Word GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB = 0x88b3;
static const Word GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB = 0x88b4;
static const Word GL_MAX_PROGRAM_ENV_PARAMETERS_ARB = 0x88b5;
static const Word GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB = 0x88b6;
static const Word GL_TRANSPOSE_CURRENT_MATRIX_ARB = 0x88b7;
static const Word GL_MATRIX0_ARB = 0x88c0;
static const Word GL_MATRIX1_ARB = 0x88c1;
static const Word GL_MATRIX2_ARB = 0x88c2;
static const Word GL_MATRIX3_ARB = 0x88c3;
static const Word GL_MATRIX4_ARB = 0x88c4;
static const Word GL_MATRIX5_ARB = 0x88c5;
static const Word GL_MATRIX6_ARB = 0x88c6;
static const Word GL_MATRIX7_ARB = 0x88c7;
static const Word GL_MATRIX8_ARB = 0x88c8;
static const Word GL_MATRIX9_ARB = 0x88c9;
static const Word GL_MATRIX10_ARB = 0x88ca;
static const Word GL_MATRIX11_ARB = 0x88cb;
static const Word GL_MATRIX12_ARB = 0x88cc;
static const Word GL_MATRIX13_ARB = 0x88cd;
static const Word GL_MATRIX14_ARB = 0x88ce;
static const Word GL_MATRIX15_ARB = 0x88cf;
static const Word GL_MATRIX16_ARB = 0x88d0;
static const Word GL_MATRIX17_ARB = 0x88d1;
static const Word GL_MATRIX18_ARB = 0x88d2;
static const Word GL_MATRIX19_ARB = 0x88d3;
static const Word GL_MATRIX20_ARB = 0x88d4;
static const Word GL_MATRIX21_ARB = 0x88d5;
static const Word GL_MATRIX22_ARB = 0x88d6;
static const Word GL_MATRIX23_ARB = 0x88d7;
static const Word GL_MATRIX24_ARB = 0x88d8;
static const Word GL_MATRIX25_ARB = 0x88d9;
static const Word GL_MATRIX26_ARB = 0x88da;
static const Word GL_MATRIX27_ARB = 0x88db;
static const Word GL_MATRIX28_ARB = 0x88dc;
static const Word GL_MATRIX29_ARB = 0x88dd;
static const Word GL_MATRIX30_ARB = 0x88de;
static const Word GL_MATRIX31_ARB = 0x88df;
static const Word GL_MAX_DRAW_BUFFERS_ARB = 0x8824;
static const Word GL_DRAW_BUFFER0_ARB = 0x8825;
static const Word GL_DRAW_BUFFER1_ARB = 0x8826;
static const Word GL_DRAW_BUFFER2_ARB = 0x8827;
static const Word GL_DRAW_BUFFER3_ARB = 0x8828;
static const Word GL_DRAW_BUFFER4_ARB = 0x8829;
static const Word GL_DRAW_BUFFER5_ARB = 0x882a;
static const Word GL_DRAW_BUFFER6_ARB = 0x882b;
static const Word GL_DRAW_BUFFER7_ARB = 0x882c;
static const Word GL_DRAW_BUFFER8_ARB = 0x882d;
static const Word GL_DRAW_BUFFER9_ARB = 0x882e;
static const Word GL_DRAW_BUFFER10_ARB = 0x882f;
static const Word GL_DRAW_BUFFER11_ARB = 0x8830;
static const Word GL_DRAW_BUFFER12_ARB = 0x8831;
static const Word GL_DRAW_BUFFER13_ARB = 0x8832;
static const Word GL_DRAW_BUFFER14_ARB = 0x8833;
static const Word GL_DRAW_BUFFER15_ARB = 0x8834;
static const Word GL_TEXTURE_RECTANGLE_ARB = 0x84f5;
static const Word GL_TEXTURE_BINDING_RECTANGLE_ARB = 0x84f6;
static const Word GL_PROXY_TEXTURE_RECTANGLE_ARB = 0x84f7;
static const Word GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB = 0x84f8;
static const Word GL_RGBA_FLOAT_MODE_ARB = 0x8820;
static const Word GL_CLAMP_VERTEX_COLOR_ARB = 0x891a;
static const Word GL_CLAMP_FRAGMENT_COLOR_ARB = 0x891b;
static const Word GL_CLAMP_READ_COLOR_ARB = 0x891c;
static const Word GL_FIXED_ONLY_ARB = 0x891d;
static const Word WGL_TYPE_RGBA_FLOAT_ARB = 0x21a0;
static const Word GLX_RGBA_FLOAT_TYPE = 0x20b9;
static const Shortint GLX_RGBA_FLOAT_BIT = 0x4;
static const Word GL_HALF_FLOAT_ARB = 0x140b;
static const Word GL_TEXTURE_RED_TYPE_ARB = 0x8c10;
static const Word GL_TEXTURE_GREEN_TYPE_ARB = 0x8c11;
static const Word GL_TEXTURE_BLUE_TYPE_ARB = 0x8c12;
static const Word GL_TEXTURE_ALPHA_TYPE_ARB = 0x8c13;
static const Word GL_TEXTURE_LUMINANCE_TYPE_ARB = 0x8c14;
static const Word GL_TEXTURE_INTENSITY_TYPE_ARB = 0x8c15;
static const Word GL_TEXTURE_DEPTH_TYPE_ARB = 0x8c16;
static const Word GL_UNSIGNED_NORMALIZED_ARB = 0x8c17;
static const Word GL_RGBA32F_ARB = 0x8814;
static const Word GL_RGB32F_ARB = 0x8815;
static const Word GL_ALPHA32F_ARB = 0x8816;
static const Word GL_INTENSITY32F_ARB = 0x8817;
static const Word GL_LUMINANCE32F_ARB = 0x8818;
static const Word GL_LUMINANCE_ALPHA32F_ARB = 0x8819;
static const Word GL_RGBA16F_ARB = 0x881a;
static const Word GL_RGB16F_ARB = 0x881b;
static const Word GL_ALPHA16F_ARB = 0x881c;
static const Word GL_INTENSITY16F_ARB = 0x881d;
static const Word GL_LUMINANCE16F_ARB = 0x881e;
static const Word GL_LUMINANCE_ALPHA16F_ARB = 0x881f;
static const Word GL_PIXEL_PACK_BUFFER_ARB = 0x88eb;
static const Word GL_PIXEL_UNPACK_BUFFER_ARB = 0x88ec;
static const Word GL_PIXEL_PACK_BUFFER_BINDING_ARB = 0x88ed;
static const Word GL_PIXEL_UNPACK_BUFFER_BINDING_ARB = 0x88ef;
static const Word GL_MAX_DRAW_BUFFERS_ATI = 0x8824;
static const Word GL_DRAW_BUFFER0_ATI = 0x8825;
static const Word GL_DRAW_BUFFER1_ATI = 0x8826;
static const Word GL_DRAW_BUFFER2_ATI = 0x8827;
static const Word GL_DRAW_BUFFER3_ATI = 0x8828;
static const Word GL_DRAW_BUFFER4_ATI = 0x8829;
static const Word GL_DRAW_BUFFER5_ATI = 0x882a;
static const Word GL_DRAW_BUFFER6_ATI = 0x882b;
static const Word GL_DRAW_BUFFER7_ATI = 0x882c;
static const Word GL_DRAW_BUFFER8_ATI = 0x882d;
static const Word GL_DRAW_BUFFER9_ATI = 0x882e;
static const Word GL_DRAW_BUFFER10_ATI = 0x882f;
static const Word GL_DRAW_BUFFER11_ATI = 0x8830;
static const Word GL_DRAW_BUFFER12_ATI = 0x8831;
static const Word GL_DRAW_BUFFER13_ATI = 0x8832;
static const Word GL_DRAW_BUFFER14_ATI = 0x8833;
static const Word GL_DRAW_BUFFER15_ATI = 0x8834;
static const Word GL_ELEMENT_ARRAY_ATI = 0x8768;
static const Word GL_ELEMENT_ARRAY_TYPE_ATI = 0x8769;
static const Word GL_ELEMENT_ARRAY_POINTER_ATI = 0x876a;
static const Word GL_BUMP_ROT_MATRIX_ATI = 0x8775;
static const Word GL_BUMP_ROT_MATRIX_SIZE_ATI = 0x8776;
static const Word GL_BUMP_NUM_TEX_UNITS_ATI = 0x8777;
static const Word GL_BUMP_TEX_UNITS_ATI = 0x8778;
static const Word GL_DUDV_ATI = 0x8779;
static const Word GL_DU8DV8_ATI = 0x877a;
static const Word GL_BUMP_ENVMAP_ATI = 0x877b;
static const Word GL_BUMP_TARGET_ATI = 0x877c;
static const Word GL_FRAGMENT_SHADER_ATI = 0x8920;
static const Word GL_REG_0_ATI = 0x8921;
static const Word GL_REG_1_ATI = 0x8922;
static const Word GL_REG_2_ATI = 0x8923;
static const Word GL_REG_3_ATI = 0x8924;
static const Word GL_REG_4_ATI = 0x8925;
static const Word GL_REG_5_ATI = 0x8926;
static const Word GL_REG_6_ATI = 0x8927;
static const Word GL_REG_7_ATI = 0x8928;
static const Word GL_REG_8_ATI = 0x8929;
static const Word GL_REG_9_ATI = 0x892a;
static const Word GL_REG_10_ATI = 0x892b;
static const Word GL_REG_11_ATI = 0x892c;
static const Word GL_REG_12_ATI = 0x892d;
static const Word GL_REG_13_ATI = 0x892e;
static const Word GL_REG_14_ATI = 0x892f;
static const Word GL_REG_15_ATI = 0x8930;
static const Word GL_REG_16_ATI = 0x8931;
static const Word GL_REG_17_ATI = 0x8932;
static const Word GL_REG_18_ATI = 0x8933;
static const Word GL_REG_19_ATI = 0x8934;
static const Word GL_REG_20_ATI = 0x8935;
static const Word GL_REG_21_ATI = 0x8936;
static const Word GL_REG_22_ATI = 0x8937;
static const Word GL_REG_23_ATI = 0x8938;
static const Word GL_REG_24_ATI = 0x8939;
static const Word GL_REG_25_ATI = 0x893a;
static const Word GL_REG_26_ATI = 0x893b;
static const Word GL_REG_27_ATI = 0x893c;
static const Word GL_REG_28_ATI = 0x893d;
static const Word GL_REG_29_ATI = 0x893e;
static const Word GL_REG_30_ATI = 0x893f;
static const Word GL_REG_31_ATI = 0x8940;
static const Word GL_CON_0_ATI = 0x8941;
static const Word GL_CON_1_ATI = 0x8942;
static const Word GL_CON_2_ATI = 0x8943;
static const Word GL_CON_3_ATI = 0x8944;
static const Word GL_CON_4_ATI = 0x8945;
static const Word GL_CON_5_ATI = 0x8946;
static const Word GL_CON_6_ATI = 0x8947;
static const Word GL_CON_7_ATI = 0x8948;
static const Word GL_CON_8_ATI = 0x8949;
static const Word GL_CON_9_ATI = 0x894a;
static const Word GL_CON_10_ATI = 0x894b;
static const Word GL_CON_11_ATI = 0x894c;
static const Word GL_CON_12_ATI = 0x894d;
static const Word GL_CON_13_ATI = 0x894e;
static const Word GL_CON_14_ATI = 0x894f;
static const Word GL_CON_15_ATI = 0x8950;
static const Word GL_CON_16_ATI = 0x8951;
static const Word GL_CON_17_ATI = 0x8952;
static const Word GL_CON_18_ATI = 0x8953;
static const Word GL_CON_19_ATI = 0x8954;
static const Word GL_CON_20_ATI = 0x8955;
static const Word GL_CON_21_ATI = 0x8956;
static const Word GL_CON_22_ATI = 0x8957;
static const Word GL_CON_23_ATI = 0x8958;
static const Word GL_CON_24_ATI = 0x8959;
static const Word GL_CON_25_ATI = 0x895a;
static const Word GL_CON_26_ATI = 0x895b;
static const Word GL_CON_27_ATI = 0x895c;
static const Word GL_CON_28_ATI = 0x895d;
static const Word GL_CON_29_ATI = 0x895e;
static const Word GL_CON_30_ATI = 0x895f;
static const Word GL_CON_31_ATI = 0x8960;
static const Word GL_MOV_ATI = 0x8961;
static const Word GL_ADD_ATI = 0x8963;
static const Word GL_MUL_ATI = 0x8964;
static const Word GL_SUB_ATI = 0x8965;
static const Word GL_DOT3_ATI = 0x8966;
static const Word GL_DOT4_ATI = 0x8967;
static const Word GL_MAD_ATI = 0x8968;
static const Word GL_LERP_ATI = 0x8969;
static const Word GL_CND_ATI = 0x896a;
static const Word GL_CND0_ATI = 0x896b;
static const Word GL_DOT2_ADD_ATI = 0x896c;
static const Word GL_SECONDARY_INTERPOLATOR_ATI = 0x896d;
static const Word GL_NUM_FRAGMENT_REGISTERS_ATI = 0x896e;
static const Word GL_NUM_FRAGMENT_CONSTANTS_ATI = 0x896f;
static const Word GL_NUM_PASSES_ATI = 0x8970;
static const Word GL_NUM_INSTRUCTIONS_PER_PASS_ATI = 0x8971;
static const Word GL_NUM_INSTRUCTIONS_TOTAL_ATI = 0x8972;
static const Word GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI = 0x8973;
static const Word GL_NUM_LOOPBACK_COMPONENTS_ATI = 0x8974;
static const Word GL_COLOR_ALPHA_PAIRING_ATI = 0x8975;
static const Word GL_SWIZZLE_STR_ATI = 0x8976;
static const Word GL_SWIZZLE_STQ_ATI = 0x8977;
static const Word GL_SWIZZLE_STR_DR_ATI = 0x8978;
static const Word GL_SWIZZLE_STQ_DQ_ATI = 0x8979;
static const Word GL_SWIZZLE_STRQ_ATI = 0x897a;
static const Word GL_SWIZZLE_STRQ_DQ_ATI = 0x897b;
static const Shortint GL_RED_BIT_ATI = 0x1;
static const Shortint GL_GREEN_BIT_ATI = 0x2;
static const Shortint GL_BLUE_BIT_ATI = 0x4;
static const Shortint GL_2X_BIT_ATI = 0x1;
static const Shortint GL_4X_BIT_ATI = 0x2;
static const Shortint GL_8X_BIT_ATI = 0x4;
static const Shortint GL_HALF_BIT_ATI = 0x8;
static const Shortint GL_QUARTER_BIT_ATI = 0x10;
static const Shortint GL_EIGHTH_BIT_ATI = 0x20;
static const Shortint GL_SATURATE_BIT_ATI = 0x40;
static const Shortint GL_COMP_BIT_ATI = 0x2;
static const Shortint GL_NEGATE_BIT_ATI = 0x4;
static const Shortint GL_BIAS_BIT_ATI = 0x8;
static const Word GL_PN_TRIANGLES_ATI = 0x87f0;
static const Word GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI = 0x87f1;
static const Word GL_PN_TRIANGLES_POINT_MODE_ATI = 0x87f2;
static const Word GL_PN_TRIANGLES_NORMAL_MODE_ATI = 0x87f3;
static const Word GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI = 0x87f4;
static const Word GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI = 0x87f5;
static const Word GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI = 0x87f6;
static const Word GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI = 0x87f7;
static const Word GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI = 0x87f8;
static const Word GL_STENCIL_BACK_FUNC_ATI = 0x8800;
static const Word GL_STENCIL_BACK_FAIL_ATI = 0x8801;
static const Word GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI = 0x8802;
static const Word GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI = 0x8803;
static const Word GL_TEXT_FRAGMENT_SHADER_ATI = 0x8200;
static const Word GL_MODULATE_ADD_ATI = 0x8744;
static const Word GL_MODULATE_SIGNED_ADD_ATI = 0x8745;
static const Word GL_MODULATE_SUBTRACT_ATI = 0x8746;
static const Word GL_RGBA_FLOAT32_ATI = 0x8814;
static const Word GL_RGB_FLOAT32_ATI = 0x8815;
static const Word GL_ALPHA_FLOAT32_ATI = 0x8816;
static const Word GL_INTENSITY_FLOAT32_ATI = 0x8817;
static const Word GL_LUMINANCE_FLOAT32_ATI = 0x8818;
static const Word GL_LUMINANCE_ALPHA_FLOAT32_ATI = 0x8819;
static const Word GL_RGBA_FLOAT16_ATI = 0x881a;
static const Word GL_RGB_FLOAT16_ATI = 0x881b;
static const Word GL_ALPHA_FLOAT16_ATI = 0x881c;
static const Word GL_INTENSITY_FLOAT16_ATI = 0x881d;
static const Word GL_LUMINANCE_FLOAT16_ATI = 0x881e;
static const Word GL_LUMINANCE_ALPHA_FLOAT16_ATI = 0x881f;
static const Word GL_MIRROR_CLAMP_ATI = 0x8742;
static const Word GL_MIRROR_CLAMP_TO_EDGE_ATI = 0x8743;
static const Word GL_STATIC_ATI = 0x8760;
static const Word GL_DYNAMIC_ATI = 0x8761;
static const Word GL_PRESERVE_ATI = 0x8762;
static const Word GL_DISCARD_ATI = 0x8763;
static const Word GL_OBJECT_BUFFER_SIZE_ATI = 0x8764;
static const Word GL_OBJECT_BUFFER_USAGE_ATI = 0x8765;
static const Word GL_ARRAY_OBJECT_BUFFER_ATI = 0x8766;
static const Word GL_ARRAY_OBJECT_OFFSET_ATI = 0x8767;
static const Word GL_MAX_VERTEX_STREAMS_ATI = 0x876b;
static const Word GL_VERTEX_STREAM0_ATI = 0x876c;
static const Word GL_VERTEX_STREAM1_ATI = 0x876d;
static const Word GL_VERTEX_STREAM2_ATI = 0x876e;
static const Word GL_VERTEX_STREAM3_ATI = 0x876f;
static const Word GL_VERTEX_STREAM4_ATI = 0x8770;
static const Word GL_VERTEX_STREAM5_ATI = 0x8771;
static const Word GL_VERTEX_STREAM6_ATI = 0x8772;
static const Word GL_VERTEX_STREAM7_ATI = 0x8773;
static const Word GL_VERTEX_SOURCE_ATI = 0x8774;
static const Word GL_422_EXT = 0x80cc;
static const Word GL_422_REV_EXT = 0x80cd;
static const Word GL_422_AVERAGE_EXT = 0x80ce;
static const Word GL_422_REV_AVERAGE_EXT = 0x80cf;
static const Word GL_ABGR_EXT = 0x8000;
static const Word GL_BGR_EXT = 0x80e0;
static const Word GL_BGRA_EXT = 0x80e1;
static const Word GL_CONSTANT_COLOR_EXT = 0x8001;
static const Word GL_ONE_MINUS_CONSTANT_COLOR_EXT = 0x8002;
static const Word GL_CONSTANT_ALPHA_EXT = 0x8003;
static const Word GL_ONE_MINUS_CONSTANT_ALPHA_EXT = 0x8004;
static const Word GL_BLEND_COLOR_EXT = 0x8005;
static const Word GL_BLEND_DST_RGB_EXT = 0x80c8;
static const Word GL_BLEND_SRC_RGB_EXT = 0x80c9;
static const Word GL_BLEND_DST_ALPHA_EXT = 0x80ca;
static const Word GL_BLEND_SRC_ALPHA_EXT = 0x80cb;
static const Word GL_FUNC_ADD_EXT = 0x8006;
static const Word GL_MIN_EXT = 0x8007;
static const Word GL_MAX_EXT = 0x8008;
static const Word GL_BLEND_EQUATION_EXT = 0x8009;
static const Word GL_FUNC_SUBTRACT_EXT = 0x800a;
static const Word GL_FUNC_REVERSE_SUBTRACT_EXT = 0x800b;
static const Word GL_CLIP_VOLUME_CLIPPING_HINT_EXT = 0x80f0;
static const Word GL_CMYK_EXT = 0x800c;
static const Word GL_CMYKA_EXT = 0x800d;
static const Word GL_PACK_CMYK_HINT_EXT = 0x800e;
static const Word GL_UNPACK_CMYK_HINT_EXT = 0x800f;
static const Word GL_ARRAY_ELEMENT_LOCK_FIRST_EXT = 0x81a8;
static const Word GL_ARRAY_ELEMENT_LOCK_COUNT_EXT = 0x81a9;
static const Word GL_CONVOLUTION_1D_EXT = 0x8010;
static const Word GL_CONVOLUTION_2D_EXT = 0x8011;
static const Word GL_SEPARABLE_2D_EXT = 0x8012;
static const Word GL_CONVOLUTION_BORDER_MODE_EXT = 0x8013;
static const Word GL_CONVOLUTION_FILTER_SCALE_EXT = 0x8014;
static const Word GL_CONVOLUTION_FILTER_BIAS_EXT = 0x8015;
static const Word GL_REDUCE_EXT = 0x8016;
static const Word GL_CONVOLUTION_FORMAT_EXT = 0x8017;
static const Word GL_CONVOLUTION_WIDTH_EXT = 0x8018;
static const Word GL_CONVOLUTION_HEIGHT_EXT = 0x8019;
static const Word GL_MAX_CONVOLUTION_WIDTH_EXT = 0x801a;
static const Word GL_MAX_CONVOLUTION_HEIGHT_EXT = 0x801b;
static const Word GL_POST_CONVOLUTION_RED_SCALE_EXT = 0x801c;
static const Word GL_POST_CONVOLUTION_GREEN_SCALE_EXT = 0x801d;
static const Word GL_POST_CONVOLUTION_BLUE_SCALE_EXT = 0x801e;
static const Word GL_POST_CONVOLUTION_ALPHA_SCALE_EXT = 0x801f;
static const Word GL_POST_CONVOLUTION_RED_BIAS_EXT = 0x8020;
static const Word GL_POST_CONVOLUTION_GREEN_BIAS_EXT = 0x8021;
static const Word GL_POST_CONVOLUTION_BLUE_BIAS_EXT = 0x8022;
static const Word GL_POST_CONVOLUTION_ALPHA_BIAS_EXT = 0x8023;
static const Word GL_TANGENT_ARRAY_EXT = 0x8439;
static const Word GL_BINORMAL_ARRAY_EXT = 0x843a;
static const Word GL_CURRENT_TANGENT_EXT = 0x843b;
static const Word GL_CURRENT_BINORMAL_EXT = 0x843c;
static const Word GL_TANGENT_ARRAY_TYPE_EXT = 0x843e;
static const Word GL_TANGENT_ARRAY_STRIDE_EXT = 0x843f;
static const Word GL_BINORMAL_ARRAY_TYPE_EXT = 0x8440;
static const Word GL_BINORMAL_ARRAY_STRIDE_EXT = 0x8441;
static const Word GL_TANGENT_ARRAY_POINTER_EXT = 0x8442;
static const Word GL_BINORMAL_ARRAY_POINTER_EXT = 0x8443;
static const Word GL_MAP1_TANGENT_EXT = 0x8444;
static const Word GL_MAP2_TANGENT_EXT = 0x8445;
static const Word GL_MAP1_BINORMAL_EXT = 0x8446;
static const Word GL_MAP2_BINORMAL_EXT = 0x8447;
static const Word GL_CULL_VERTEX_EXT = 0x81aa;
static const Word GL_CULL_VERTEX_EYE_POSITION_EXT = 0x81ab;
static const Word GL_CULL_VERTEX_OBJECT_POSITION_EXT = 0x81ac;
static const Word GL_MAX_ELEMENTS_VERTICES_EXT = 0x80e8;
static const Word GL_MAX_ELEMENTS_INDICES_EXT = 0x80e9;
static const Word GL_FOG_COORDINATE_SOURCE_EXT = 0x8450;
static const Word GL_FOG_COORDINATE_EXT = 0x8451;
static const Word GL_FRAGMENT_DEPTH_EXT = 0x8452;
static const Word GL_CURRENT_FOG_COORDINATE_EXT = 0x8453;
static const Word GL_FOG_COORDINATE_ARRAY_TYPE_EXT = 0x8454;
static const Word GL_FOG_COORDINATE_ARRAY_STRIDE_EXT = 0x8455;
static const Word GL_FOG_COORDINATE_ARRAY_POINTER_EXT = 0x8456;
static const Word GL_FOG_COORDINATE_ARRAY_EXT = 0x8457;
static const Word GL_FRAMEBUFFER_EXT = 0x8d40;
static const Word GL_RENDERBUFFER_EXT = 0x8d41;
static const Word GL_STENCIL_INDEX_EXT = 0x8d45;
static const Word GL_STENCIL_INDEX1_EXT = 0x8d46;
static const Word GL_STENCIL_INDEX4_EXT = 0x8d47;
static const Word GL_STENCIL_INDEX8_EXT = 0x8d48;
static const Word GL_STENCIL_INDEX16_EXT = 0x8d49;
static const Word GL_RENDERBUFFER_WIDTH_EXT = 0x8d42;
static const Word GL_RENDERBUFFER_HEIGHT_EXT = 0x8d43;
static const Word GL_RENDERBUFFER_INTERNAL_FORMAT_EXT = 0x8d44;
static const Word GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT = 0x8cd0;
static const Word GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT = 0x8cd1;
static const Word GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT = 0x8cd2;
static const Word GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT = 0x8cd3;
static const Word GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT = 0x8cd4;
static const Word GL_COLOR_ATTACHMENT0_EXT = 0x8ce0;
static const Word GL_COLOR_ATTACHMENT1_EXT = 0x8ce1;
static const Word GL_COLOR_ATTACHMENT2_EXT = 0x8ce2;
static const Word GL_COLOR_ATTACHMENT3_EXT = 0x8ce3;
static const Word GL_COLOR_ATTACHMENT4_EXT = 0x8ce4;
static const Word GL_COLOR_ATTACHMENT5_EXT = 0x8ce5;
static const Word GL_COLOR_ATTACHMENT6_EXT = 0x8ce6;
static const Word GL_COLOR_ATTACHMENT7_EXT = 0x8ce7;
static const Word GL_COLOR_ATTACHMENT8_EXT = 0x8ce8;
static const Word GL_COLOR_ATTACHMENT9_EXT = 0x8ce9;
static const Word GL_COLOR_ATTACHMENT10_EXT = 0x8cea;
static const Word GL_COLOR_ATTACHMENT11_EXT = 0x8ceb;
static const Word GL_COLOR_ATTACHMENT12_EXT = 0x8cec;
static const Word GL_COLOR_ATTACHMENT13_EXT = 0x8ced;
static const Word GL_COLOR_ATTACHMENT14_EXT = 0x8cee;
static const Word GL_COLOR_ATTACHMENT15_EXT = 0x8cef;
static const Word GL_DEPTH_ATTACHMENT_EXT = 0x8d00;
static const Word GL_STENCIL_ATTACHMENT_EXT = 0x8d20;
static const Word GL_FRAMEBUFFER_COMPLETE_EXT = 0x8cd5;
static const Word GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT = 0x8cd6;
static const Word GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT = 0x8cd7;
static const Word GL_FRAMEBUFFER_INCOMPLETE_DUPLICATE_ATTACHMENT_EXT = 0x8cd8;
static const Word GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT = 0x8cd9;
static const Word GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT = 0x8cda;
static const Word GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT = 0x8cdb;
static const Word GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT = 0x8cdc;
static const Word GL_FRAMEBUFFER_UNSUPPORTED_EXT = 0x8cdd;
static const Word GL_FRAMEBUFFER_STATUS_ERROR_EXT = 0x8cde;
static const Word GL_FRAMEBUFFER_BINDING_EXT = 0x8ca6;
static const Word GL_RENDERBUFFER_BINDING_EXT = 0x8ca7;
static const Word GL_MAX_COLOR_ATTACHMENTS_EXT = 0x8cdf;
static const Word GL_MAX_RENDERBUFFER_SIZE_EXT = 0x84e8;
static const Word GL_INVALID_FRAMEBUFFER_OPERATION_EXT = 0x506;
static const Word GL_HISTOGRAM_EXT = 0x8024;
static const Word GL_PROXY_HISTOGRAM_EXT = 0x8025;
static const Word GL_HISTOGRAM_WIDTH_EXT = 0x8026;
static const Word GL_HISTOGRAM_FORMAT_EXT = 0x8027;
static const Word GL_HISTOGRAM_RED_SIZE_EXT = 0x8028;
static const Word GL_HISTOGRAM_GREEN_SIZE_EXT = 0x8029;
static const Word GL_HISTOGRAM_BLUE_SIZE_EXT = 0x802a;
static const Word GL_HISTOGRAM_ALPHA_SIZE_EXT = 0x802b;
static const Word GL_HISTOGRAM_LUMINANCE_SIZE_EXT = 0x802c;
static const Word GL_HISTOGRAM_SINK_EXT = 0x802d;
static const Word GL_MINMAX_EXT = 0x802e;
static const Word GL_MINMAX_FORMAT_EXT = 0x802f;
static const Word GL_MINMAX_SINK_EXT = 0x8030;
static const Word GL_TABLE_TOO_LARGE_EXT = 0x8031;
static const Word GL_IUI_V2F_EXT = 0x81ad;
static const Word GL_IUI_V3F_EXT = 0x81ae;
static const Word GL_IUI_N3F_V2F_EXT = 0x81af;
static const Word GL_IUI_N3F_V3F_EXT = 0x81b0;
static const Word GL_T2F_IUI_V2F_EXT = 0x81b1;
static const Word GL_T2F_IUI_V3F_EXT = 0x81b2;
static const Word GL_T2F_IUI_N3F_V2F_EXT = 0x81b3;
static const Word GL_T2F_IUI_N3F_V3F_EXT = 0x81b4;
static const Word GL_INDEX_TEST_EXT = 0x81b5;
static const Word GL_INDEX_TEST_FUNC_EXT = 0x81b6;
static const Word GL_INDEX_TEST_REF_EXT = 0x81b7;
static const Word GL_INDEX_MATERIAL_EXT = 0x81b8;
static const Word GL_INDEX_MATERIAL_PARAMETER_EXT = 0x81b9;
static const Word GL_INDEX_MATERIAL_FACE_EXT = 0x81ba;
static const Word GL_FRAGMENT_MATERIAL_EXT = 0x8349;
static const Word GL_FRAGMENT_NORMAL_EXT = 0x834a;
static const Word GL_FRAGMENT_COLOR_EXT = 0x834c;
static const Word GL_ATTENUATION_EXT = 0x834d;
static const Word GL_SHADOW_ATTENUATION_EXT = 0x834e;
static const Word GL_TEXTURE_APPLICATION_MODE_EXT = 0x834f;
static const Word GL_TEXTURE_LIGHT_EXT = 0x8350;
static const Word GL_TEXTURE_MATERIAL_FACE_EXT = 0x8351;
static const Word GL_TEXTURE_MATERIAL_PARAMETER_EXT = 0x8352;
static const Word GL_MULTISAMPLE_EXT = 0x809d;
static const Word GL_SAMPLE_ALPHA_TO_MASK_EXT = 0x809e;
static const Word GL_SAMPLE_ALPHA_TO_ONE_EXT = 0x809f;
static const Word GL_SAMPLE_MASK_EXT = 0x80a0;
static const Word GL_1PASS_EXT = 0x80a1;
static const Word GL_2PASS_0_EXT = 0x80a2;
static const Word GL_2PASS_1_EXT = 0x80a3;
static const Word GL_4PASS_0_EXT = 0x80a4;
static const Word GL_4PASS_1_EXT = 0x80a5;
static const Word GL_4PASS_2_EXT = 0x80a6;
static const Word GL_4PASS_3_EXT = 0x80a7;
static const Word GL_SAMPLE_BUFFERS_EXT = 0x80a8;
static const Word GL_SAMPLES_EXT = 0x80a9;
static const Word GL_SAMPLE_MASK_VALUE_EXT = 0x80aa;
static const Word GL_SAMPLE_MASK_INVERT_EXT = 0x80ab;
static const Word GL_SAMPLE_PATTERN_EXT = 0x80ac;
static const int GL_MULTISAMPLE_BIT_EXT = 0x20000000;
static const Word GL_UNSIGNED_BYTE_3_3_2_EXT = 0x8032;
static const Word GL_UNSIGNED_SHORT_4_4_4_4_EXT = 0x8033;
static const Word GL_UNSIGNED_SHORT_5_5_5_1_EXT = 0x8034;
static const Word GL_UNSIGNED_INT_8_8_8_8_EXT = 0x8035;
static const Word GL_UNSIGNED_INT_10_10_10_2_EXT = 0x8036;
static const Word GL_COLOR_INDEX1_EXT = 0x80e2;
static const Word GL_COLOR_INDEX2_EXT = 0x80e3;
static const Word GL_COLOR_INDEX4_EXT = 0x80e4;
static const Word GL_COLOR_INDEX8_EXT = 0x80e5;
static const Word GL_COLOR_INDEX12_EXT = 0x80e6;
static const Word GL_COLOR_INDEX16_EXT = 0x80e7;
static const Word GL_TEXTURE_INDEX_SIZE_EXT = 0x80ed;
static const Word GL_PIXEL_TRANSFORM_2D_EXT = 0x8330;
static const Word GL_PIXEL_MAG_FILTER_EXT = 0x8331;
static const Word GL_PIXEL_MIN_FILTER_EXT = 0x8332;
static const Word GL_PIXEL_CUBIC_WEIGHT_EXT = 0x8333;
static const Word GL_CUBIC_EXT = 0x8334;
static const Word GL_AVERAGE_EXT = 0x8335;
static const Word GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT = 0x8336;
static const Word GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT = 0x8337;
static const Word GL_PIXEL_TRANSFORM_2D_MATRIX_EXT = 0x8338;
static const Word GL_POINT_SIZE_MIN_EXT = 0x8126;
static const Word GL_POINT_SIZE_MAX_EXT = 0x8127;
static const Word GL_POINT_FADE_THRESHOLD_SIZE_EXT = 0x8128;
static const Word GL_DISTANCE_ATTENUATION_EXT = 0x8129;
static const Word GL_POLYGON_OFFSET_EXT = 0x8037;
static const Word GL_POLYGON_OFFSET_FACTOR_EXT = 0x8038;
static const Word GL_POLYGON_OFFSET_BIAS_EXT = 0x8039;
static const Word GL_RESCALE_NORMAL_EXT = 0x803a;
static const Word GL_COLOR_SUM_EXT = 0x8458;
static const Word GL_CURRENT_SECONDARY_COLOR_EXT = 0x8459;
static const Word GL_SECONDARY_COLOR_ARRAY_SIZE_EXT = 0x845a;
static const Word GL_SECONDARY_COLOR_ARRAY_TYPE_EXT = 0x845b;
static const Word GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT = 0x845c;
static const Word GL_SECONDARY_COLOR_ARRAY_POINTER_EXT = 0x845d;
static const Word GL_SECONDARY_COLOR_ARRAY_EXT = 0x845e;
static const Word GL_LIGHT_MODEL_COLOR_CONTROL_EXT = 0x81f8;
static const Word GL_SINGLE_COLOR_EXT = 0x81f9;
static const Word GL_SEPARATE_SPECULAR_COLOR_EXT = 0x81fa;
static const Word GL_SHARED_TEXTURE_PALETTE_EXT = 0x81fb;
static const Word GL_STENCIL_TEST_TWO_SIDE_EXT = 0x8910;
static const Word GL_ACTIVE_STENCIL_FACE_EXT = 0x8911;
static const Word GL_INCR_WRAP_EXT = 0x8507;
static const Word GL_DECR_WRAP_EXT = 0x8508;
static const Word GL_ALPHA4_EXT = 0x803b;
static const Word GL_ALPHA8_EXT = 0x803c;
static const Word GL_ALPHA12_EXT = 0x803d;
static const Word GL_ALPHA16_EXT = 0x803e;
static const Word GL_LUMINANCE4_EXT = 0x803f;
static const Word GL_LUMINANCE8_EXT = 0x8040;
static const Word GL_LUMINANCE12_EXT = 0x8041;
static const Word GL_LUMINANCE16_EXT = 0x8042;
static const Word GL_LUMINANCE4_ALPHA4_EXT = 0x8043;
static const Word GL_LUMINANCE6_ALPHA2_EXT = 0x8044;
static const Word GL_LUMINANCE8_ALPHA8_EXT = 0x8045;
static const Word GL_LUMINANCE12_ALPHA4_EXT = 0x8046;
static const Word GL_LUMINANCE12_ALPHA12_EXT = 0x8047;
static const Word GL_LUMINANCE16_ALPHA16_EXT = 0x8048;
static const Word GL_INTENSITY_EXT = 0x8049;
static const Word GL_INTENSITY4_EXT = 0x804a;
static const Word GL_INTENSITY8_EXT = 0x804b;
static const Word GL_INTENSITY12_EXT = 0x804c;
static const Word GL_INTENSITY16_EXT = 0x804d;
static const Word GL_RGB2_EXT = 0x804e;
static const Word GL_RGB4_EXT = 0x804f;
static const Word GL_RGB5_EXT = 0x8050;
static const Word GL_RGB8_EXT = 0x8051;
static const Word GL_RGB10_EXT = 0x8052;
static const Word GL_RGB12_EXT = 0x8053;
static const Word GL_RGB16_EXT = 0x8054;
static const Word GL_RGBA2_EXT = 0x8055;
static const Word GL_RGBA4_EXT = 0x8056;
static const Word GL_RGB5_A1_EXT = 0x8057;
static const Word GL_RGBA8_EXT = 0x8058;
static const Word GL_RGB10_A2_EXT = 0x8059;
static const Word GL_RGBA12_EXT = 0x805a;
static const Word GL_RGBA16_EXT = 0x805b;
static const Word GL_TEXTURE_RED_SIZE_EXT = 0x805c;
static const Word GL_TEXTURE_GREEN_SIZE_EXT = 0x805d;
static const Word GL_TEXTURE_BLUE_SIZE_EXT = 0x805e;
static const Word GL_TEXTURE_ALPHA_SIZE_EXT = 0x805f;
static const Word GL_TEXTURE_LUMINANCE_SIZE_EXT = 0x8060;
static const Word GL_TEXTURE_INTENSITY_SIZE_EXT = 0x8061;
static const Word GL_REPLACE_EXT = 0x8062;
static const Word GL_PROXY_TEXTURE_1D_EXT = 0x8063;
static const Word GL_PROXY_TEXTURE_2D_EXT = 0x8064;
static const Word GL_TEXTURE_TOO_LARGE_EXT = 0x8065;
static const Word GL_PACK_SKIP_IMAGES_EXT = 0x806b;
static const Word GL_PACK_IMAGE_HEIGHT_EXT = 0x806c;
static const Word GL_UNPACK_SKIP_IMAGES_EXT = 0x806d;
static const Word GL_UNPACK_IMAGE_HEIGHT_EXT = 0x806e;
static const Word GL_TEXTURE_3D_EXT = 0x806f;
static const Word GL_PROXY_TEXTURE_3D_EXT = 0x8070;
static const Word GL_TEXTURE_DEPTH_EXT = 0x8071;
static const Word GL_TEXTURE_WRAP_R_EXT = 0x8072;
static const Word GL_MAX_3D_TEXTURE_SIZE_EXT = 0x8073;
static const Word GL_COMPRESSED_RGB_S3TC_DXT1_EXT = 0x83f0;
static const Word GL_COMPRESSED_RGBA_S3TC_DXT1_EXT = 0x83f1;
static const Word GL_COMPRESSED_RGBA_S3TC_DXT3_EXT = 0x83f2;
static const Word GL_COMPRESSED_RGBA_S3TC_DXT5_EXT = 0x83f3;
static const Word GL_NORMAL_MAP_EXT = 0x8511;
static const Word GL_REFLECTION_MAP_EXT = 0x8512;
static const Word GL_TEXTURE_CUBE_MAP_EXT = 0x8513;
static const Word GL_TEXTURE_BINDING_CUBE_MAP_EXT = 0x8514;
static const Word GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT = 0x8515;
static const Word GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT = 0x8516;
static const Word GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT = 0x8517;
static const Word GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT = 0x8518;
static const Word GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT = 0x8519;
static const Word GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT = 0x851a;
static const Word GL_PROXY_TEXTURE_CUBE_MAP_EXT = 0x851b;
static const Word GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT = 0x851c;
static const Word GL_CLAMP_TO_EDGE_EXT = 0x812f;
static const Word GL_COMBINE_EXT = 0x8570;
static const Word GL_COMBINE_RGB_EXT = 0x8571;
static const Word GL_COMBINE_ALPHA_EXT = 0x8572;
static const Word GL_RGB_SCALE_EXT = 0x8573;
static const Word GL_ADD_SIGNED_EXT = 0x8574;
static const Word GL_INTERPOLATE_EXT = 0x8575;
static const Word GL_CONSTANT_EXT = 0x8576;
static const Word GL_PRIMARY_COLOR_EXT = 0x8577;
static const Word GL_PREVIOUS_EXT = 0x8578;
static const Word GL_SOURCE0_RGB_EXT = 0x8580;
static const Word GL_SOURCE1_RGB_EXT = 0x8581;
static const Word GL_SOURCE2_RGB_EXT = 0x8582;
static const Word GL_SOURCE0_ALPHA_EXT = 0x8588;
static const Word GL_SOURCE1_ALPHA_EXT = 0x8589;
static const Word GL_SOURCE2_ALPHA_EXT = 0x858a;
static const Word GL_OPERAND0_RGB_EXT = 0x8590;
static const Word GL_OPERAND1_RGB_EXT = 0x8591;
static const Word GL_OPERAND2_RGB_EXT = 0x8592;
static const Word GL_OPERAND0_ALPHA_EXT = 0x8598;
static const Word GL_OPERAND1_ALPHA_EXT = 0x8599;
static const Word GL_OPERAND2_ALPHA_EXT = 0x859a;
static const Word GL_DOT3_RGB_EXT = 0x8740;
static const Word GL_DOT3_RGBA_EXT = 0x8741;
static const Word GL_TEXTURE_MAX_ANISOTROPY_EXT = 0x84fe;
static const Word GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT = 0x84ff;
static const Word GL_MAX_TEXTURE_LOD_BIAS_EXT = 0x84fd;
static const Word GL_TEXTURE_FILTER_CONTROL_EXT = 0x8500;
static const Word GL_TEXTURE_LOD_BIAS_EXT = 0x8501;
static const Word GL_TEXTURE_PRIORITY_EXT = 0x8066;
static const Word GL_TEXTURE_RESIDENT_EXT = 0x8067;
static const Word GL_TEXTURE_1D_BINDING_EXT = 0x8068;
static const Word GL_TEXTURE_2D_BINDING_EXT = 0x8069;
static const Word GL_TEXTURE_3D_BINDING_EXT = 0x806a;
static const Word GL_PERTURB_EXT = 0x85ae;
static const Word GL_TEXTURE_NORMAL_EXT = 0x85af;
static const Word GL_TEXTURE_RECTANGLE_EXT = 0x84f5;
static const Word GL_TEXTURE_BINDING_RECTANGLE_EXT = 0x84f6;
static const Word GL_PROXY_TEXTURE_RECTANGLE_EXT = 0x84f7;
static const Word GL_MAX_RECTANGLE_TEXTURE_SIZE_EXT = 0x84f8;
static const Word GL_VERTEX_ARRAY_EXT = 0x8074;
static const Word GL_NORMAL_ARRAY_EXT = 0x8075;
static const Word GL_COLOR_ARRAY_EXT = 0x8076;
static const Word GL_INDEX_ARRAY_EXT = 0x8077;
static const Word GL_TEXTURE_COORD_ARRAY_EXT = 0x8078;
static const Word GL_EDGE_FLAG_ARRAY_EXT = 0x8079;
static const Word GL_VERTEX_ARRAY_SIZE_EXT = 0x807a;
static const Word GL_VERTEX_ARRAY_TYPE_EXT = 0x807b;
static const Word GL_VERTEX_ARRAY_STRIDE_EXT = 0x807c;
static const Word GL_VERTEX_ARRAY_COUNT_EXT = 0x807d;
static const Word GL_NORMAL_ARRAY_TYPE_EXT = 0x807e;
static const Word GL_NORMAL_ARRAY_STRIDE_EXT = 0x807f;
static const Word GL_NORMAL_ARRAY_COUNT_EXT = 0x8080;
static const Word GL_COLOR_ARRAY_SIZE_EXT = 0x8081;
static const Word GL_COLOR_ARRAY_TYPE_EXT = 0x8082;
static const Word GL_COLOR_ARRAY_STRIDE_EXT = 0x8083;
static const Word GL_COLOR_ARRAY_COUNT_EXT = 0x8084;
static const Word GL_INDEX_ARRAY_TYPE_EXT = 0x8085;
static const Word GL_INDEX_ARRAY_STRIDE_EXT = 0x8086;
static const Word GL_INDEX_ARRAY_COUNT_EXT = 0x8087;
static const Word GL_TEXTURE_COORD_ARRAY_SIZE_EXT = 0x8088;
static const Word GL_TEXTURE_COORD_ARRAY_TYPE_EXT = 0x8089;
static const Word GL_TEXTURE_COORD_ARRAY_STRIDE_EXT = 0x808a;
static const Word GL_TEXTURE_COORD_ARRAY_COUNT_EXT = 0x808b;
static const Word GL_EDGE_FLAG_ARRAY_STRIDE_EXT = 0x808c;
static const Word GL_EDGE_FLAG_ARRAY_COUNT_EXT = 0x808d;
static const Word GL_VERTEX_ARRAY_POINTER_EXT = 0x808e;
static const Word GL_NORMAL_ARRAY_POINTER_EXT = 0x808f;
static const Word GL_COLOR_ARRAY_POINTER_EXT = 0x8090;
static const Word GL_INDEX_ARRAY_POINTER_EXT = 0x8091;
static const Word GL_TEXTURE_COORD_ARRAY_POINTER_EXT = 0x8092;
static const Word GL_EDGE_FLAG_ARRAY_POINTER_EXT = 0x8093;
static const Word GL_VERTEX_SHADER_EXT = 0x8780;
static const Word GL_VERTEX_SHADER_BINDING_EXT = 0x8781;
static const Word GL_OP_INDEX_EXT = 0x8782;
static const Word GL_OP_NEGATE_EXT = 0x8783;
static const Word GL_OP_DOT3_EXT = 0x8784;
static const Word GL_OP_DOT4_EXT = 0x8785;
static const Word GL_OP_MUL_EXT = 0x8786;
static const Word GL_OP_ADD_EXT = 0x8787;
static const Word GL_OP_MADD_EXT = 0x8788;
static const Word GL_OP_FRAC_EXT = 0x8789;
static const Word GL_OP_MAX_EXT = 0x878a;
static const Word GL_OP_MIN_EXT = 0x878b;
static const Word GL_OP_SET_GE_EXT = 0x878c;
static const Word GL_OP_SET_LT_EXT = 0x878d;
static const Word GL_OP_CLAMP_EXT = 0x878e;
static const Word GL_OP_FLOOR_EXT = 0x878f;
static const Word GL_OP_ROUND_EXT = 0x8790;
static const Word GL_OP_EXP_BASE_2_EXT = 0x8791;
static const Word GL_OP_LOG_BASE_2_EXT = 0x8792;
static const Word GL_OP_POWER_EXT = 0x8793;
static const Word GL_OP_RECIP_EXT = 0x8794;
static const Word GL_OP_RECIP_SQRT_EXT = 0x8795;
static const Word GL_OP_SUB_EXT = 0x8796;
static const Word GL_OP_CROSS_PRODUCT_EXT = 0x8797;
static const Word GL_OP_MULTIPLY_MATRIX_EXT = 0x8798;
static const Word GL_OP_MOV_EXT = 0x8799;
static const Word GL_OUTPUT_VERTEX_EXT = 0x879a;
static const Word GL_OUTPUT_COLOR0_EXT = 0x879b;
static const Word GL_OUTPUT_COLOR1_EXT = 0x879c;
static const Word GL_OUTPUT_TEXTURE_COORD0_EXT = 0x879d;
static const Word GL_OUTPUT_TEXTURE_COORD1_EXT = 0x879e;
static const Word GL_OUTPUT_TEXTURE_COORD2_EXT = 0x879f;
static const Word GL_OUTPUT_TEXTURE_COORD3_EXT = 0x87a0;
static const Word GL_OUTPUT_TEXTURE_COORD4_EXT = 0x87a1;
static const Word GL_OUTPUT_TEXTURE_COORD5_EXT = 0x87a2;
static const Word GL_OUTPUT_TEXTURE_COORD6_EXT = 0x87a3;
static const Word GL_OUTPUT_TEXTURE_COORD7_EXT = 0x87a4;
static const Word GL_OUTPUT_TEXTURE_COORD8_EXT = 0x87a5;
static const Word GL_OUTPUT_TEXTURE_COORD9_EXT = 0x87a6;
static const Word GL_OUTPUT_TEXTURE_COORD10_EXT = 0x87a7;
static const Word GL_OUTPUT_TEXTURE_COORD11_EXT = 0x87a8;
static const Word GL_OUTPUT_TEXTURE_COORD12_EXT = 0x87a9;
static const Word GL_OUTPUT_TEXTURE_COORD13_EXT = 0x87aa;
static const Word GL_OUTPUT_TEXTURE_COORD14_EXT = 0x87ab;
static const Word GL_OUTPUT_TEXTURE_COORD15_EXT = 0x87ac;
static const Word GL_OUTPUT_TEXTURE_COORD16_EXT = 0x87ad;
static const Word GL_OUTPUT_TEXTURE_COORD17_EXT = 0x87ae;
static const Word GL_OUTPUT_TEXTURE_COORD18_EXT = 0x87af;
static const Word GL_OUTPUT_TEXTURE_COORD19_EXT = 0x87b0;
static const Word GL_OUTPUT_TEXTURE_COORD20_EXT = 0x87b1;
static const Word GL_OUTPUT_TEXTURE_COORD21_EXT = 0x87b2;
static const Word GL_OUTPUT_TEXTURE_COORD22_EXT = 0x87b3;
static const Word GL_OUTPUT_TEXTURE_COORD23_EXT = 0x87b4;
static const Word GL_OUTPUT_TEXTURE_COORD24_EXT = 0x87b5;
static const Word GL_OUTPUT_TEXTURE_COORD25_EXT = 0x87b6;
static const Word GL_OUTPUT_TEXTURE_COORD26_EXT = 0x87b7;
static const Word GL_OUTPUT_TEXTURE_COORD27_EXT = 0x87b8;
static const Word GL_OUTPUT_TEXTURE_COORD28_EXT = 0x87b9;
static const Word GL_OUTPUT_TEXTURE_COORD29_EXT = 0x87ba;
static const Word GL_OUTPUT_TEXTURE_COORD30_EXT = 0x87bb;
static const Word GL_OUTPUT_TEXTURE_COORD31_EXT = 0x87bc;
static const Word GL_OUTPUT_FOG_EXT = 0x87bd;
static const Word GL_SCALAR_EXT = 0x87be;
static const Word GL_VECTOR_EXT = 0x87bf;
static const Word GL_MATRIX_EXT = 0x87c0;
static const Word GL_VARIANT_EXT = 0x87c1;
static const Word GL_INVARIANT_EXT = 0x87c2;
static const Word GL_LOCAL_CONSTANT_EXT = 0x87c3;
static const Word GL_LOCAL_EXT = 0x87c4;
static const Word GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT = 0x87c5;
static const Word GL_MAX_VERTEX_SHADER_VARIANTS_EXT = 0x87c6;
static const Word GL_MAX_VERTEX_SHADER_INVARIANTS_EXT = 0x87c7;
static const Word GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT = 0x87c8;
static const Word GL_MAX_VERTEX_SHADER_LOCALS_EXT = 0x87c9;
static const Word GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT = 0x87ca;
static const Word GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT = 0x87cb;
static const Word GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT = 0x87cc;
static const Word GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT = 0x87cd;
static const Word GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT = 0x87ce;
static const Word GL_VERTEX_SHADER_INSTRUCTIONS_EXT = 0x87cf;
static const Word GL_VERTEX_SHADER_VARIANTS_EXT = 0x87d0;
static const Word GL_VERTEX_SHADER_INVARIANTS_EXT = 0x87d1;
static const Word GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT = 0x87d2;
static const Word GL_VERTEX_SHADER_LOCALS_EXT = 0x87d3;
static const Word GL_VERTEX_SHADER_OPTIMIZED_EXT = 0x87d4;
static const Word GL_X_EXT = 0x87d5;
static const Word GL_Y_EXT = 0x87d6;
static const Word GL_Z_EXT = 0x87d7;
static const Word GL_W_EXT = 0x87d8;
static const Word GL_NEGATIVE_X_EXT = 0x87d9;
static const Word GL_NEGATIVE_Y_EXT = 0x87da;
static const Word GL_NEGATIVE_Z_EXT = 0x87db;
static const Word GL_NEGATIVE_W_EXT = 0x87dc;
static const Word GL_ZERO_EXT = 0x87dd;
static const Word GL_ONE_EXT = 0x87de;
static const Word GL_NEGATIVE_ONE_EXT = 0x87df;
static const Word GL_NORMALIZED_RANGE_EXT = 0x87e0;
static const Word GL_FULL_RANGE_EXT = 0x87e1;
static const Word GL_CURRENT_VERTEX_EXT = 0x87e2;
static const Word GL_MVP_MATRIX_EXT = 0x87e3;
static const Word GL_VARIANT_VALUE_EXT = 0x87e4;
static const Word GL_VARIANT_DATATYPE_EXT = 0x87e5;
static const Word GL_VARIANT_ARRAY_STRIDE_EXT = 0x87e6;
static const Word GL_VARIANT_ARRAY_TYPE_EXT = 0x87e7;
static const Word GL_VARIANT_ARRAY_EXT = 0x87e8;
static const Word GL_VARIANT_ARRAY_POINTER_EXT = 0x87e9;
static const Word GL_INVARIANT_VALUE_EXT = 0x87ea;
static const Word GL_INVARIANT_DATATYPE_EXT = 0x87eb;
static const Word GL_LOCAL_CONSTANT_VALUE_EXT = 0x87ec;
static const Word GL_LOCAL_CONSTANT_DATATYPE_EXT = 0x87ed;
static const Word GL_MODELVIEW0_STACK_DEPTH_EXT = 0xba3;
static const Word GL_MODELVIEW1_STACK_DEPTH_EXT = 0x8502;
static const Word GL_MODELVIEW0_MATRIX_EXT = 0xba6;
static const Word GL_MODELVIEW1_MATRIX_EXT = 0x8506;
static const Word GL_VERTEX_WEIGHTING_EXT = 0x8509;
static const Word GL_MODELVIEW0_EXT = 0x1700;
static const Word GL_MODELVIEW1_EXT = 0x850a;
static const Word GL_CURRENT_VERTEX_WEIGHT_EXT = 0x850b;
static const Word GL_VERTEX_WEIGHT_ARRAY_EXT = 0x850c;
static const Word GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT = 0x850d;
static const Word GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT = 0x850e;
static const Word GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT = 0x850f;
static const Word GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT = 0x8510;
static const Word GL_DEPTH_BOUNDS_TEST_EXT = 0x8890;
static const Word GL_DEPTH_BOUNDS_EXT = 0x8891;
static const Word GL_MIRROR_CLAMP_EXT = 0x8742;
static const Word GL_MIRROR_CLAMP_TO_EDGE_EXT = 0x8743;
static const Word GL_MIRROR_CLAMP_TO_BORDER_EXT = 0x8912;
static const Word GL_BLEND_EQUATION_RGB_EXT = 0x8009;
static const Word GL_BLEND_EQUATION_ALPHA_EXT = 0x883d;
static const Word GL_PIXEL_PACK_BUFFER_EXT = 0x88eb;
static const Word GL_PIXEL_UNPACK_BUFFER_EXT = 0x88ec;
static const Word GL_PIXEL_PACK_BUFFER_BINDING_EXT = 0x88ed;
static const Word GL_PIXEL_UNPACK_BUFFER_BINDING_EXT = 0x88ef;
static const Word GL_STENCIL_TAG_BITS_EXT = 0x88f2;
static const Word GL_STENCIL_CLEAR_TAG_VALUE_EXT = 0x88f3;
static const Shortint GL_TEXTURE_DEFORMATION_BIT_SGIX = 0x1;
static const Shortint GL_GEOMETRY_DEFORMATION_BIT_SGIX = 0x2;
static const Word GL_IGNORE_BORDER_HP = 0x8150;
static const Word GL_CONSTANT_BORDER_HP = 0x8151;
static const Word GL_REPLICATE_BORDER_HP = 0x8153;
static const Word GL_CONVOLUTION_BORDER_COLOR_HP = 0x8154;
static const Word GL_IMAGE_SCALE_X_HP = 0x8155;
static const Word GL_IMAGE_SCALE_Y_HP = 0x8156;
static const Word GL_IMAGE_TRANSLATE_X_HP = 0x8157;
static const Word GL_IMAGE_TRANSLATE_Y_HP = 0x8158;
static const Word GL_IMAGE_ROTATE_ANGLE_HP = 0x8159;
static const Word GL_IMAGE_ROTATE_ORIGIN_X_HP = 0x815a;
static const Word GL_IMAGE_ROTATE_ORIGIN_Y_HP = 0x815b;
static const Word GL_IMAGE_MAG_FILTER_HP = 0x815c;
static const Word GL_IMAGE_MIN_FILTER_HP = 0x815d;
static const Word GL_IMAGE_CUBIC_WEIGHT_HP = 0x815e;
static const Word GL_CUBIC_HP = 0x815f;
static const Word GL_AVERAGE_HP = 0x8160;
static const Word GL_IMAGE_TRANSFORM_2D_HP = 0x8161;
static const Word GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP = 0x8162;
static const Word GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP = 0x8163;
static const Word GL_OCCLUSION_TEST_HP = 0x8165;
static const Word GL_OCCLUSION_TEST_RESULT_HP = 0x8166;
static const Word GL_TEXTURE_LIGHTING_MODE_HP = 0x8167;
static const Word GL_TEXTURE_POST_SPECULAR_HP = 0x8168;
static const Word GL_TEXTURE_PRE_SPECULAR_HP = 0x8169;
static const int GL_CULL_VERTEX_IBM = 0x1928a;
static const int GL_RASTER_POSITION_UNCLIPPED_IBM = 0x19262;
static const Word GL_MIRRORED_REPEAT_IBM = 0x8370;
static const int GL_VERTEX_ARRAY_LIST_IBM = 0x1929e;
static const int GL_NORMAL_ARRAY_LIST_IBM = 0x1929f;
static const int GL_COLOR_ARRAY_LIST_IBM = 0x192a0;
static const int GL_INDEX_ARRAY_LIST_IBM = 0x192a1;
static const int GL_TEXTURE_COORD_ARRAY_LIST_IBM = 0x192a2;
static const int GL_EDGE_FLAG_ARRAY_LIST_IBM = 0x192a3;
static const int GL_FOG_COORDINATE_ARRAY_LIST_IBM = 0x192a4;
static const int GL_SECONDARY_COLOR_ARRAY_LIST_IBM = 0x192a5;
static const int GL_VERTEX_ARRAY_LIST_STRIDE_IBM = 0x192a8;
static const int GL_NORMAL_ARRAY_LIST_STRIDE_IBM = 0x192a9;
static const int GL_COLOR_ARRAY_LIST_STRIDE_IBM = 0x192aa;
static const int GL_INDEX_ARRAY_LIST_STRIDE_IBM = 0x192ab;
static const int GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM = 0x192ac;
static const int GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM = 0x192ad;
static const int GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM = 0x192ae;
static const int GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM = 0x192af;
static const Word GL_RED_MIN_CLAMP_INGR = 0x8560;
static const Word GL_GREEN_MIN_CLAMP_INGR = 0x8561;
static const Word GL_BLUE_MIN_CLAMP_INGR = 0x8562;
static const Word GL_ALPHA_MIN_CLAMP_INGR = 0x8563;
static const Word GL_RED_MAX_CLAMP_INGR = 0x8564;
static const Word GL_GREEN_MAX_CLAMP_INGR = 0x8565;
static const Word GL_BLUE_MAX_CLAMP_INGR = 0x8566;
static const Word GL_ALPHA_MAX_CLAMP_INGR = 0x8567;
static const Word GL_INTERLACE_READ_INGR = 0x8568;
static const Word GL_PARALLEL_ARRAYS_INTEL = 0x83f4;
static const Word GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL = 0x83f5;
static const Word GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL = 0x83f6;
static const Word GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL = 0x83f7;
static const Word GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL = 0x83f8;
static const Word GL_DEPTH_STENCIL_TO_RGBA_NV = 0x886e;
static const Word GL_DEPTH_STENCIL_TO_BGRA_NV = 0x886f;
static const Word GL_DEPTH_CLAMP_NV = 0x864f;
static const Word GL_EVAL_2D_NV = 0x86c0;
static const Word GL_EVAL_TRIANGULAR_2D_NV = 0x86c1;
static const Word GL_MAP_TESSELLATION_NV = 0x86c2;
static const Word GL_MAP_ATTRIB_U_ORDER_NV = 0x86c3;
static const Word GL_MAP_ATTRIB_V_ORDER_NV = 0x86c4;
static const Word GL_EVAL_FRACTIONAL_TESSELLATION_NV = 0x86c5;
static const Word GL_EVAL_VERTEX_ATTRIB0_NV = 0x86c6;
static const Word GL_EVAL_VERTEX_ATTRIB1_NV = 0x86c7;
static const Word GL_EVAL_VERTEX_ATTRIB2_NV = 0x86c8;
static const Word GL_EVAL_VERTEX_ATTRIB3_NV = 0x86c9;
static const Word GL_EVAL_VERTEX_ATTRIB4_NV = 0x86ca;
static const Word GL_EVAL_VERTEX_ATTRIB5_NV = 0x86cb;
static const Word GL_EVAL_VERTEX_ATTRIB6_NV = 0x86cc;
static const Word GL_EVAL_VERTEX_ATTRIB7_NV = 0x86cd;
static const Word GL_EVAL_VERTEX_ATTRIB8_NV = 0x86ce;
static const Word GL_EVAL_VERTEX_ATTRIB9_NV = 0x86cf;
static const Word GL_EVAL_VERTEX_ATTRIB10_NV = 0x86d0;
static const Word GL_EVAL_VERTEX_ATTRIB11_NV = 0x86d1;
static const Word GL_EVAL_VERTEX_ATTRIB12_NV = 0x86d2;
static const Word GL_EVAL_VERTEX_ATTRIB13_NV = 0x86d3;
static const Word GL_EVAL_VERTEX_ATTRIB14_NV = 0x86d4;
static const Word GL_EVAL_VERTEX_ATTRIB15_NV = 0x86d5;
static const Word GL_MAX_MAP_TESSELLATION_NV = 0x86d6;
static const Word GL_MAX_RATIONAL_EVAL_ORDER_NV = 0x86d7;
static const Word GL_ALL_COMPLETED_NV = 0x84f2;
static const Word GL_FENCE_STATUS_NV = 0x84f3;
static const Word GL_FENCE_CONDITION_NV = 0x84f4;
static const Word GL_FLOAT_R_NV = 0x8880;
static const Word GL_FLOAT_RG_NV = 0x8881;
static const Word GL_FLOAT_RGB_NV = 0x8882;
static const Word GL_FLOAT_RGBA_NV = 0x8883;
static const Word GL_FLOAT_R16_NV = 0x8884;
static const Word GL_FLOAT_R32_NV = 0x8885;
static const Word GL_FLOAT_RG16_NV = 0x8886;
static const Word GL_FLOAT_RG32_NV = 0x8887;
static const Word GL_FLOAT_RGB16_NV = 0x8888;
static const Word GL_FLOAT_RGB32_NV = 0x8889;
static const Word GL_FLOAT_RGBA16_NV = 0x888a;
static const Word GL_FLOAT_RGBA32_NV = 0x888b;
static const Word GL_TEXTURE_FLOAT_COMPONENTS_NV = 0x888c;
static const Word GL_FLOAT_CLEAR_COLOR_VALUE_NV = 0x888d;
static const Word GL_FLOAT_RGBA_MODE_NV = 0x888e;
static const Word GL_FOG_DISTANCE_MODE_NV = 0x855a;
static const Word GL_EYE_RADIAL_NV = 0x855b;
static const Word GL_EYE_PLANE_ABSOLUTE_NV = 0x855c;
static const Word GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV = 0x8868;
static const Word GL_FRAGMENT_PROGRAM_NV = 0x8870;
static const Word GL_MAX_TEXTURE_COORDS_NV = 0x8871;
static const Word GL_MAX_TEXTURE_IMAGE_UNITS_NV = 0x8872;
static const Word GL_FRAGMENT_PROGRAM_BINDING_NV = 0x8873;
static const Word GL_PROGRAM_ERROR_STRING_NV = 0x8874;
static const Word GL_HALF_FLOAT_NV = 0x140b;
static const Word GL_MAX_SHININESS_NV = 0x8504;
static const Word GL_MAX_SPOT_EXPONENT_NV = 0x8505;
static const Word GL_MULTISAMPLE_FILTER_HINT_NV = 0x8534;
static const Word GL_PIXEL_COUNTER_BITS_NV = 0x8864;
static const Word GL_CURRENT_OCCLUSION_QUERY_ID_NV = 0x8865;
static const Word GL_PIXEL_COUNT_NV = 0x8866;
static const Word GL_PIXEL_COUNT_AVAILABLE_NV = 0x8867;
static const Word GL_DEPTH_STENCIL_NV = 0x84f9;
static const Word GL_UNSIGNED_INT_24_8_NV = 0x84fa;
static const Word GL_WRITE_PIXEL_DATA_RANGE_NV = 0x8878;
static const Word GL_READ_PIXEL_DATA_RANGE_NV = 0x8879;
static const Word GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV = 0x887a;
static const Word GL_READ_PIXEL_DATA_RANGE_LENGTH_NV = 0x887b;
static const Word GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV = 0x887c;
static const Word GL_READ_PIXEL_DATA_RANGE_POINTER_NV = 0x887d;
static const Word GL_POINT_SPRITE_NV = 0x8861;
static const Word GL_COORD_REPLACE_NV = 0x8862;
static const Word GL_POINT_SPRITE_R_MODE_NV = 0x8863;
static const Word GL_PRIMITIVE_RESTART_NV = 0x8558;
static const Word GL_PRIMITIVE_RESTART_INDEX_NV = 0x8559;
static const Word GL_REGISTER_COMBINERS_NV = 0x8522;
static const Word GL_VARIABLE_A_NV = 0x8523;
static const Word GL_VARIABLE_B_NV = 0x8524;
static const Word GL_VARIABLE_C_NV = 0x8525;
static const Word GL_VARIABLE_D_NV = 0x8526;
static const Word GL_VARIABLE_E_NV = 0x8527;
static const Word GL_VARIABLE_F_NV = 0x8528;
static const Word GL_VARIABLE_G_NV = 0x8529;
static const Word GL_CONSTANT_COLOR0_NV = 0x852a;
static const Word GL_CONSTANT_COLOR1_NV = 0x852b;
static const Word GL_PRIMARY_COLOR_NV = 0x852c;
static const Word GL_SECONDARY_COLOR_NV = 0x852d;
static const Word GL_SPARE0_NV = 0x852e;
static const Word GL_SPARE1_NV = 0x852f;
static const Word GL_DISCARD_NV = 0x8530;
static const Word GL_E_TIMES_F_NV = 0x8531;
static const Word GL_SPARE0_PLUS_SECONDARY_COLOR_NV = 0x8532;
static const Word GL_UNSIGNED_IDENTITY_NV = 0x8536;
static const Word GL_UNSIGNED_INVERT_NV = 0x8537;
static const Word GL_EXPAND_NORMAL_NV = 0x8538;
static const Word GL_EXPAND_NEGATE_NV = 0x8539;
static const Word GL_HALF_BIAS_NORMAL_NV = 0x853a;
static const Word GL_HALF_BIAS_NEGATE_NV = 0x853b;
static const Word GL_SIGNED_IDENTITY_NV = 0x853c;
static const Word GL_SIGNED_NEGATE_NV = 0x853d;
static const Word GL_SCALE_BY_TWO_NV = 0x853e;
static const Word GL_SCALE_BY_FOUR_NV = 0x853f;
static const Word GL_SCALE_BY_ONE_HALF_NV = 0x8540;
static const Word GL_BIAS_BY_NEGATIVE_ONE_HALF_NV = 0x8541;
static const Word GL_COMBINER_INPUT_NV = 0x8542;
static const Word GL_COMBINER_MAPPING_NV = 0x8543;
static const Word GL_COMBINER_COMPONENT_USAGE_NV = 0x8544;
static const Word GL_COMBINER_AB_DOT_PRODUCT_NV = 0x8545;
static const Word GL_COMBINER_CD_DOT_PRODUCT_NV = 0x8546;
static const Word GL_COMBINER_MUX_SUM_NV = 0x8547;
static const Word GL_COMBINER_SCALE_NV = 0x8548;
static const Word GL_COMBINER_BIAS_NV = 0x8549;
static const Word GL_COMBINER_AB_OUTPUT_NV = 0x854a;
static const Word GL_COMBINER_CD_OUTPUT_NV = 0x854b;
static const Word GL_COMBINER_SUM_OUTPUT_NV = 0x854c;
static const Word GL_MAX_GENERAL_COMBINERS_NV = 0x854d;
static const Word GL_NUM_GENERAL_COMBINERS_NV = 0x854e;
static const Word GL_COLOR_SUM_CLAMP_NV = 0x854f;
static const Word GL_COMBINER0_NV = 0x8550;
static const Word GL_COMBINER1_NV = 0x8551;
static const Word GL_COMBINER2_NV = 0x8552;
static const Word GL_COMBINER3_NV = 0x8553;
static const Word GL_COMBINER4_NV = 0x8554;
static const Word GL_COMBINER5_NV = 0x8555;
static const Word GL_COMBINER6_NV = 0x8556;
static const Word GL_COMBINER7_NV = 0x8557;
static const Word GL_PER_STAGE_CONSTANTS_NV = 0x8535;
static const Word GL_EMBOSS_LIGHT_NV = 0x855d;
static const Word GL_EMBOSS_CONSTANT_NV = 0x855e;
static const Word GL_EMBOSS_MAP_NV = 0x855f;
static const Word GL_NORMAL_MAP_NV = 0x8511;
static const Word GL_REFLECTION_MAP_NV = 0x8512;
static const Word GL_COMBINE4_NV = 0x8503;
static const Word GL_SOURCE3_RGB_NV = 0x8583;
static const Word GL_SOURCE3_ALPHA_NV = 0x858b;
static const Word GL_OPERAND3_RGB_NV = 0x8593;
static const Word GL_OPERAND3_ALPHA_NV = 0x859b;
static const Word GL_TEXTURE_UNSIGNED_REMAP_MODE_NV = 0x888f;
static const Word GL_TEXTURE_RECTANGLE_NV = 0x84f5;
static const Word GL_TEXTURE_BINDING_RECTANGLE_NV = 0x84f6;
static const Word GL_PROXY_TEXTURE_RECTANGLE_NV = 0x84f7;
static const Word GL_MAX_RECTANGLE_TEXTURE_SIZE_NV = 0x84f8;
static const Word GL_OFFSET_TEXTURE_RECTANGLE_NV = 0x864c;
static const Word GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV = 0x864d;
static const Word GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV = 0x864e;
static const Word GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV = 0x86d9;
static const Word GL_UNSIGNED_INT_S8_S8_8_8_NV = 0x86da;
static const Word GL_UNSIGNED_INT_8_8_S8_S8_REV_NV = 0x86db;
static const Word GL_DSDT_MAG_INTENSITY_NV = 0x86dc;
static const Word GL_SHADER_CONSISTENT_NV = 0x86dd;
static const Word GL_TEXTURE_SHADER_NV = 0x86de;
static const Word GL_SHADER_OPERATION_NV = 0x86df;
static const Word GL_CULL_MODES_NV = 0x86e0;
static const Word GL_OFFSET_TEXTURE_MATRIX_NV = 0x86e1;
static const Word GL_OFFSET_TEXTURE_SCALE_NV = 0x86e2;
static const Word GL_OFFSET_TEXTURE_BIAS_NV = 0x86e3;
static const Word GL_OFFSET_TEXTURE_2D_MATRIX_NV = 0x86e1;
static const Word GL_OFFSET_TEXTURE_2D_SCALE_NV = 0x86e2;
static const Word GL_OFFSET_TEXTURE_2D_BIAS_NV = 0x86e3;
static const Word GL_PREVIOUS_TEXTURE_INPUT_NV = 0x86e4;
static const Word GL_CONST_EYE_NV = 0x86e5;
static const Word GL_PASS_THROUGH_NV = 0x86e6;
static const Word GL_CULL_FRAGMENT_NV = 0x86e7;
static const Word GL_OFFSET_TEXTURE_2D_NV = 0x86e8;
static const Word GL_DEPENDENT_AR_TEXTURE_2D_NV = 0x86e9;
static const Word GL_DEPENDENT_GB_TEXTURE_2D_NV = 0x86ea;
static const Word GL_DOT_PRODUCT_NV = 0x86ec;
static const Word GL_DOT_PRODUCT_DEPTH_REPLACE_NV = 0x86ed;
static const Word GL_DOT_PRODUCT_TEXTURE_2D_NV = 0x86ee;
static const Word GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV = 0x86f0;
static const Word GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV = 0x86f1;
static const Word GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV = 0x86f2;
static const Word GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV = 0x86f3;
static const Word GL_HILO_NV = 0x86f4;
static const Word GL_DSDT_NV = 0x86f5;
static const Word GL_DSDT_MAG_NV = 0x86f6;
static const Word GL_DSDT_MAG_VIB_NV = 0x86f7;
static const Word GL_HILO16_NV = 0x86f8;
static const Word GL_SIGNED_HILO_NV = 0x86f9;
static const Word GL_SIGNED_HILO16_NV = 0x86fa;
static const Word GL_SIGNED_RGBA_NV = 0x86fb;
static const Word GL_SIGNED_RGBA8_NV = 0x86fc;
static const Word GL_SIGNED_RGB_NV = 0x86fe;
static const Word GL_SIGNED_RGB8_NV = 0x86ff;
static const Word GL_SIGNED_LUMINANCE_NV = 0x8701;
static const Word GL_SIGNED_LUMINANCE8_NV = 0x8702;
static const Word GL_SIGNED_LUMINANCE_ALPHA_NV = 0x8703;
static const Word GL_SIGNED_LUMINANCE8_ALPHA8_NV = 0x8704;
static const Word GL_SIGNED_ALPHA_NV = 0x8705;
static const Word GL_SIGNED_ALPHA8_NV = 0x8706;
static const Word GL_SIGNED_INTENSITY_NV = 0x8707;
static const Word GL_SIGNED_INTENSITY8_NV = 0x8708;
static const Word GL_DSDT8_NV = 0x8709;
static const Word GL_DSDT8_MAG8_NV = 0x870a;
static const Word GL_DSDT8_MAG8_INTENSITY8_NV = 0x870b;
static const Word GL_SIGNED_RGB_UNSIGNED_ALPHA_NV = 0x870c;
static const Word GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV = 0x870d;
static const Word GL_HI_SCALE_NV = 0x870e;
static const Word GL_LO_SCALE_NV = 0x870f;
static const Word GL_DS_SCALE_NV = 0x8710;
static const Word GL_DT_SCALE_NV = 0x8711;
static const Word GL_MAGNITUDE_SCALE_NV = 0x8712;
static const Word GL_VIBRANCE_SCALE_NV = 0x8713;
static const Word GL_HI_BIAS_NV = 0x8714;
static const Word GL_LO_BIAS_NV = 0x8715;
static const Word GL_DS_BIAS_NV = 0x8716;
static const Word GL_DT_BIAS_NV = 0x8717;
static const Word GL_MAGNITUDE_BIAS_NV = 0x8718;
static const Word GL_VIBRANCE_BIAS_NV = 0x8719;
static const Word GL_TEXTURE_BORDER_VALUES_NV = 0x871a;
static const Word GL_TEXTURE_HI_SIZE_NV = 0x871b;
static const Word GL_TEXTURE_LO_SIZE_NV = 0x871c;
static const Word GL_TEXTURE_DS_SIZE_NV = 0x871d;
static const Word GL_TEXTURE_DT_SIZE_NV = 0x871e;
static const Word GL_TEXTURE_MAG_SIZE_NV = 0x871f;
static const Word GL_DOT_PRODUCT_TEXTURE_3D_NV = 0x86ef;
static const Word GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV = 0x8850;
static const Word GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV = 0x8851;
static const Word GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV = 0x8852;
static const Word GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV = 0x8853;
static const Word GL_OFFSET_HILO_TEXTURE_2D_NV = 0x8854;
static const Word GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV = 0x8855;
static const Word GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV = 0x8856;
static const Word GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV = 0x8857;
static const Word GL_DEPENDENT_HILO_TEXTURE_2D_NV = 0x8858;
static const Word GL_DEPENDENT_RGB_TEXTURE_3D_NV = 0x8859;
static const Word GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV = 0x885a;
static const Word GL_DOT_PRODUCT_PASS_THROUGH_NV = 0x885b;
static const Word GL_DOT_PRODUCT_TEXTURE_1D_NV = 0x885c;
static const Word GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV = 0x885d;
static const Word GL_HILO8_NV = 0x885e;
static const Word GL_SIGNED_HILO8_NV = 0x885f;
static const Word GL_FORCE_BLUE_TO_ONE_NV = 0x8860;
static const Word GL_VERTEX_ARRAY_RANGE_NV = 0x851d;
static const Word GL_VERTEX_ARRAY_RANGE_LENGTH_NV = 0x851e;
static const Word GL_VERTEX_ARRAY_RANGE_VALID_NV = 0x851f;
static const Word GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV = 0x8520;
static const Word GL_VERTEX_ARRAY_RANGE_POINTER_NV = 0x8521;
static const Word GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV = 0x8533;
static const Word GL_VERTEX_PROGRAM_NV = 0x8620;
static const Word GL_VERTEX_STATE_PROGRAM_NV = 0x8621;
static const Word GL_ATTRIB_ARRAY_SIZE_NV = 0x8623;
static const Word GL_ATTRIB_ARRAY_STRIDE_NV = 0x8624;
static const Word GL_ATTRIB_ARRAY_TYPE_NV = 0x8625;
static const Word GL_CURRENT_ATTRIB_NV = 0x8626;
static const Word GL_PROGRAM_LENGTH_NV = 0x8627;
static const Word GL_PROGRAM_STRING_NV = 0x8628;
static const Word GL_MODELVIEW_PROJECTION_NV = 0x8629;
static const Word GL_IDENTITY_NV = 0x862a;
static const Word GL_INVERSE_NV = 0x862b;
static const Word GL_TRANSPOSE_NV = 0x862c;
static const Word GL_INVERSE_TRANSPOSE_NV = 0x862d;
static const Word GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV = 0x862e;
static const Word GL_MAX_TRACK_MATRICES_NV = 0x862f;
static const Word GL_MATRIX0_NV = 0x8630;
static const Word GL_MATRIX1_NV = 0x8631;
static const Word GL_MATRIX2_NV = 0x8632;
static const Word GL_MATRIX3_NV = 0x8633;
static const Word GL_MATRIX4_NV = 0x8634;
static const Word GL_MATRIX5_NV = 0x8635;
static const Word GL_MATRIX6_NV = 0x8636;
static const Word GL_MATRIX7_NV = 0x8637;
static const Word GL_CURRENT_MATRIX_STACK_DEPTH_NV = 0x8640;
static const Word GL_CURRENT_MATRIX_NV = 0x8641;
static const Word GL_VERTEX_PROGRAM_POINT_SIZE_NV = 0x8642;
static const Word GL_VERTEX_PROGRAM_TWO_SIDE_NV = 0x8643;
static const Word GL_PROGRAM_PARAMETER_NV = 0x8644;
static const Word GL_ATTRIB_ARRAY_POINTER_NV = 0x8645;
static const Word GL_PROGRAM_TARGET_NV = 0x8646;
static const Word GL_PROGRAM_RESIDENT_NV = 0x8647;
static const Word GL_TRACK_MATRIX_NV = 0x8648;
static const Word GL_TRACK_MATRIX_TRANSFORM_NV = 0x8649;
static const Word GL_VERTEX_PROGRAM_BINDING_NV = 0x864a;
static const Word GL_PROGRAM_ERROR_POSITION_NV = 0x864b;
static const Word GL_VERTEX_ATTRIB_ARRAY0_NV = 0x8650;
static const Word GL_VERTEX_ATTRIB_ARRAY1_NV = 0x8651;
static const Word GL_VERTEX_ATTRIB_ARRAY2_NV = 0x8652;
static const Word GL_VERTEX_ATTRIB_ARRAY3_NV = 0x8653;
static const Word GL_VERTEX_ATTRIB_ARRAY4_NV = 0x8654;
static const Word GL_VERTEX_ATTRIB_ARRAY5_NV = 0x8655;
static const Word GL_VERTEX_ATTRIB_ARRAY6_NV = 0x8656;
static const Word GL_VERTEX_ATTRIB_ARRAY7_NV = 0x8657;
static const Word GL_VERTEX_ATTRIB_ARRAY8_NV = 0x8658;
static const Word GL_VERTEX_ATTRIB_ARRAY9_NV = 0x8659;
static const Word GL_VERTEX_ATTRIB_ARRAY10_NV = 0x865a;
static const Word GL_VERTEX_ATTRIB_ARRAY11_NV = 0x865b;
static const Word GL_VERTEX_ATTRIB_ARRAY12_NV = 0x865c;
static const Word GL_VERTEX_ATTRIB_ARRAY13_NV = 0x865d;
static const Word GL_VERTEX_ATTRIB_ARRAY14_NV = 0x865e;
static const Word GL_VERTEX_ATTRIB_ARRAY15_NV = 0x865f;
static const Word GL_MAP1_VERTEX_ATTRIB0_4_NV = 0x8660;
static const Word GL_MAP1_VERTEX_ATTRIB1_4_NV = 0x8661;
static const Word GL_MAP1_VERTEX_ATTRIB2_4_NV = 0x8662;
static const Word GL_MAP1_VERTEX_ATTRIB3_4_NV = 0x8663;
static const Word GL_MAP1_VERTEX_ATTRIB4_4_NV = 0x8664;
static const Word GL_MAP1_VERTEX_ATTRIB5_4_NV = 0x8665;
static const Word GL_MAP1_VERTEX_ATTRIB6_4_NV = 0x8666;
static const Word GL_MAP1_VERTEX_ATTRIB7_4_NV = 0x8667;
static const Word GL_MAP1_VERTEX_ATTRIB8_4_NV = 0x8668;
static const Word GL_MAP1_VERTEX_ATTRIB9_4_NV = 0x8669;
static const Word GL_MAP1_VERTEX_ATTRIB10_4_NV = 0x866a;
static const Word GL_MAP1_VERTEX_ATTRIB11_4_NV = 0x866b;
static const Word GL_MAP1_VERTEX_ATTRIB12_4_NV = 0x866c;
static const Word GL_MAP1_VERTEX_ATTRIB13_4_NV = 0x866d;
static const Word GL_MAP1_VERTEX_ATTRIB14_4_NV = 0x866e;
static const Word GL_MAP1_VERTEX_ATTRIB15_4_NV = 0x866f;
static const Word GL_MAP2_VERTEX_ATTRIB0_4_NV = 0x8670;
static const Word GL_MAP2_VERTEX_ATTRIB1_4_NV = 0x8671;
static const Word GL_MAP2_VERTEX_ATTRIB2_4_NV = 0x8672;
static const Word GL_MAP2_VERTEX_ATTRIB3_4_NV = 0x8673;
static const Word GL_MAP2_VERTEX_ATTRIB4_4_NV = 0x8674;
static const Word GL_MAP2_VERTEX_ATTRIB5_4_NV = 0x8675;
static const Word GL_MAP2_VERTEX_ATTRIB6_4_NV = 0x8676;
static const Word GL_MAP2_VERTEX_ATTRIB7_4_NV = 0x8677;
static const Word GL_MAP2_VERTEX_ATTRIB8_4_NV = 0x8678;
static const Word GL_MAP2_VERTEX_ATTRIB9_4_NV = 0x8679;
static const Word GL_MAP2_VERTEX_ATTRIB10_4_NV = 0x867a;
static const Word GL_MAP2_VERTEX_ATTRIB11_4_NV = 0x867b;
static const Word GL_MAP2_VERTEX_ATTRIB12_4_NV = 0x867c;
static const Word GL_MAP2_VERTEX_ATTRIB13_4_NV = 0x867d;
static const Word GL_MAP2_VERTEX_ATTRIB14_4_NV = 0x867e;
static const Word GL_MAP2_VERTEX_ATTRIB15_4_NV = 0x867f;
static const Word GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV = 0x88f4;
static const Word GL_MAX_PROGRAM_CALL_DEPTH_NV = 0x88f5;
static const Word GL_MAX_PROGRAM_IF_DEPTH_NV = 0x88f6;
static const Word GL_MAX_PROGRAM_LOOP_DEPTH_NV = 0x88f7;
static const Word GL_MAX_PROGRAM_LOOP_COUNT_NV = 0x88f8;
static const Word MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB = 0x8b4c;
static const Word GL_INTERLACE_OML = 0x8980;
static const Word GL_INTERLACE_READ_OML = 0x8981;
static const Word GL_PACK_RESAMPLE_OML = 0x8984;
static const Word GL_UNPACK_RESAMPLE_OML = 0x8985;
static const Word GL_RESAMPLE_REPLICATE_OML = 0x8986;
static const Word GL_RESAMPLE_ZERO_FILL_OML = 0x8987;
static const Word GL_RESAMPLE_AVERAGE_OML = 0x8988;
static const Word GL_RESAMPLE_DECIMATE_OML = 0x8989;
static const Word GL_FORMAT_SUBSAMPLE_24_24_OML = 0x8982;
static const Word GL_FORMAT_SUBSAMPLE_244_244_OML = 0x8983;
static const int GL_PREFER_DOUBLEBUFFER_HINT_PGI = 0x1a1f8;
static const int GL_CONSERVE_MEMORY_HINT_PGI = 0x1a1fd;
static const int GL_RECLAIM_MEMORY_HINT_PGI = 0x1a1fe;
static const int GL_NATIVE_GRAPHICS_HANDLE_PGI = 0x1a202;
static const int GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI = 0x1a203;
static const int GL_NATIVE_GRAPHICS_END_HINT_PGI = 0x1a204;
static const int GL_ALWAYS_FAST_HINT_PGI = 0x1a20c;
static const int GL_ALWAYS_SOFT_HINT_PGI = 0x1a20d;
static const int GL_ALLOW_DRAW_OBJ_HINT_PGI = 0x1a20e;
static const int GL_ALLOW_DRAW_WIN_HINT_PGI = 0x1a20f;
static const int GL_ALLOW_DRAW_FRG_HINT_PGI = 0x1a210;
static const int GL_ALLOW_DRAW_MEM_HINT_PGI = 0x1a211;
static const int GL_STRICT_DEPTHFUNC_HINT_PGI = 0x1a216;
static const int GL_STRICT_LIGHTING_HINT_PGI = 0x1a217;
static const int GL_STRICT_SCISSOR_HINT_PGI = 0x1a218;
static const int GL_FULL_STIPPLE_HINT_PGI = 0x1a219;
static const int GL_CLIP_NEAR_HINT_PGI = 0x1a220;
static const int GL_CLIP_FAR_HINT_PGI = 0x1a221;
static const int GL_WIDE_LINE_HINT_PGI = 0x1a222;
static const int GL_BACK_NORMALS_HINT_PGI = 0x1a223;
static const int GL_VERTEX_DATA_HINT_PGI = 0x1a22a;
static const int GL_VERTEX_CONSISTENT_HINT_PGI = 0x1a22b;
static const int GL_MATERIAL_SIDE_HINT_PGI = 0x1a22c;
static const int GL_MAX_VERTEX_HINT_PGI = 0x1a22d;
static const int GL_COLOR3_BIT_PGI = 0x10000;
static const int GL_COLOR4_BIT_PGI = 0x20000;
static const int GL_EDGEFLAG_BIT_PGI = 0x40000;
static const int GL_INDEX_BIT_PGI = 0x80000;
static const int GL_MAT_AMBIENT_BIT_PGI = 0x100000;
static const int GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI = 0x200000;
static const int GL_MAT_DIFFUSE_BIT_PGI = 0x400000;
static const int GL_MAT_EMISSION_BIT_PGI = 0x800000;
static const int GL_MAT_COLOR_INDEXES_BIT_PGI = 0x1000000;
static const int GL_MAT_SHININESS_BIT_PGI = 0x2000000;
static const int GL_MAT_SPECULAR_BIT_PGI = 0x4000000;
static const int GL_NORMAL_BIT_PGI = 0x8000000;
static const int GL_TEXCOORD1_BIT_PGI = 0x10000000;
static const int GL_TEXCOORD2_BIT_PGI = 0x20000000;
static const int GL_TEXCOORD3_BIT_PGI = 0x40000000;
static const unsigned GL_TEXCOORD4_BIT_PGI = 0x80000000;
static const Shortint GL_VERTEX23_BIT_PGI = 0x4;
static const Shortint GL_VERTEX4_BIT_PGI = 0x8;
static const Word GL_SCREEN_COORDINATES_REND = 0x8490;
static const Word GL_INVERTED_SCREEN_W_REND = 0x8491;
static const Word GL_RGB_S3TC = 0x83a0;
static const Word GL_RGB4_S3TC = 0x83a1;
static const Word GL_RGBA_S3TC = 0x83a2;
static const Word GL_RGBA4_S3TC = 0x83a3;
static const Word GL_DETAIL_TEXTURE_2D_SGIS = 0x8095;
static const Word GL_DETAIL_TEXTURE_2D_BINDING_SGIS = 0x8096;
static const Word GL_LINEAR_DETAIL_SGIS = 0x8097;
static const Word GL_LINEAR_DETAIL_ALPHA_SGIS = 0x8098;
static const Word GL_LINEAR_DETAIL_COLOR_SGIS = 0x8099;
static const Word GL_DETAIL_TEXTURE_LEVEL_SGIS = 0x809a;
static const Word GL_DETAIL_TEXTURE_MODE_SGIS = 0x809b;
static const Word GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS = 0x809c;
static const Word GL_FOG_FUNC_SGIS = 0x812a;
static const Word GL_FOG_FUNC_POINTS_SGIS = 0x812b;
static const Word GL_MAX_FOG_FUNC_POINTS_SGIS = 0x812c;
static const Word GL_GENERATE_MIPMAP_SGIS = 0x8191;
static const Word GL_GENERATE_MIPMAP_HINT_SGIS = 0x8192;
static const Word GL_MULTISAMPLE_SGIS = 0x809d;
static const Word GL_SAMPLE_ALPHA_TO_MASK_SGIS = 0x809e;
static const Word GL_SAMPLE_ALPHA_TO_ONE_SGIS = 0x809f;
static const Word GL_SAMPLE_MASK_SGIS = 0x80a0;
static const Word GL_1PASS_SGIS = 0x80a1;
static const Word GL_2PASS_0_SGIS = 0x80a2;
static const Word GL_2PASS_1_SGIS = 0x80a3;
static const Word GL_4PASS_0_SGIS = 0x80a4;
static const Word GL_4PASS_1_SGIS = 0x80a5;
static const Word GL_4PASS_2_SGIS = 0x80a6;
static const Word GL_4PASS_3_SGIS = 0x80a7;
static const Word GL_SAMPLE_BUFFERS_SGIS = 0x80a8;
static const Word GL_SAMPLES_SGIS = 0x80a9;
static const Word GL_SAMPLE_MASK_VALUE_SGIS = 0x80aa;
static const Word GL_SAMPLE_MASK_INVERT_SGIS = 0x80ab;
static const Word GL_SAMPLE_PATTERN_SGIS = 0x80ac;
static const Word GL_PIXEL_TEXTURE_SGIS = 0x8353;
static const Word GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS = 0x8354;
static const Word GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS = 0x8355;
static const Word GL_PIXEL_GROUP_COLOR_SGIS = 0x8356;
static const Word GL_EYE_DISTANCE_TO_POINT_SGIS = 0x81f0;
static const Word GL_OBJECT_DISTANCE_TO_POINT_SGIS = 0x81f1;
static const Word GL_EYE_DISTANCE_TO_LINE_SGIS = 0x81f2;
static const Word GL_OBJECT_DISTANCE_TO_LINE_SGIS = 0x81f3;
static const Word GL_EYE_POINT_SGIS = 0x81f4;
static const Word GL_OBJECT_POINT_SGIS = 0x81f5;
static const Word GL_EYE_LINE_SGIS = 0x81f6;
static const Word GL_OBJECT_LINE_SGIS = 0x81f7;
static const Word GL_POINT_SIZE_MIN_SGIS = 0x8126;
static const Word GL_POINT_SIZE_MAX_SGIS = 0x8127;
static const Word GL_POINT_FADE_THRESHOLD_SIZE_SGIS = 0x8128;
static const Word GL_DISTANCE_ATTENUATION_SGIS = 0x8129;
static const Word GL_LINEAR_SHARPEN_SGIS = 0x80ad;
static const Word GL_LINEAR_SHARPEN_ALPHA_SGIS = 0x80ae;
static const Word GL_LINEAR_SHARPEN_COLOR_SGIS = 0x80af;
static const Word GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS = 0x80b0;
static const Word GL_PACK_SKIP_VOLUMES_SGIS = 0x8130;
static const Word GL_PACK_IMAGE_DEPTH_SGIS = 0x8131;
static const Word GL_UNPACK_SKIP_VOLUMES_SGIS = 0x8132;
static const Word GL_UNPACK_IMAGE_DEPTH_SGIS = 0x8133;
static const Word GL_TEXTURE_4D_SGIS = 0x8134;
static const Word GL_PROXY_TEXTURE_4D_SGIS = 0x8135;
static const Word GL_TEXTURE_4DSIZE_SGIS = 0x8136;
static const Word GL_TEXTURE_WRAP_Q_SGIS = 0x8137;
static const Word GL_MAX_4D_TEXTURE_SIZE_SGIS = 0x8138;
static const Word GL_TEXTURE_4D_BINDING_SGIS = 0x814f;
static const Word GL_TEXTURE_COLOR_WRITEMASK_SGIS = 0x81ef;
static const Word GL_CLAMP_TO_EDGE_SGIS = 0x812f;
static const Word GL_FILTER4_SGIS = 0x8146;
static const Word GL_TEXTURE_FILTER4_SIZE_SGIS = 0x8147;
static const Word GL_TEXTURE_MIN_LOD_SGIS = 0x813a;
static const Word GL_TEXTURE_MAX_LOD_SGIS = 0x813b;
static const Word GL_TEXTURE_BASE_LEVEL_SGIS = 0x813c;
static const Word GL_TEXTURE_MAX_LEVEL_SGIS = 0x813d;
static const Word GL_DUAL_ALPHA4_SGIS = 0x8110;
static const Word GL_DUAL_ALPHA8_SGIS = 0x8111;
static const Word GL_DUAL_ALPHA12_SGIS = 0x8112;
static const Word GL_DUAL_ALPHA16_SGIS = 0x8113;
static const Word GL_DUAL_LUMINANCE4_SGIS = 0x8114;
static const Word GL_DUAL_LUMINANCE8_SGIS = 0x8115;
static const Word GL_DUAL_LUMINANCE12_SGIS = 0x8116;
static const Word GL_DUAL_LUMINANCE16_SGIS = 0x8117;
static const Word GL_DUAL_INTENSITY4_SGIS = 0x8118;
static const Word GL_DUAL_INTENSITY8_SGIS = 0x8119;
static const Word GL_DUAL_INTENSITY12_SGIS = 0x811a;
static const Word GL_DUAL_INTENSITY16_SGIS = 0x811b;
static const Word GL_DUAL_LUMINANCE_ALPHA4_SGIS = 0x811c;
static const Word GL_DUAL_LUMINANCE_ALPHA8_SGIS = 0x811d;
static const Word GL_QUAD_ALPHA4_SGIS = 0x811e;
static const Word GL_QUAD_ALPHA8_SGIS = 0x811f;
static const Word GL_QUAD_LUMINANCE4_SGIS = 0x8120;
static const Word GL_QUAD_LUMINANCE8_SGIS = 0x8121;
static const Word GL_QUAD_INTENSITY4_SGIS = 0x8122;
static const Word GL_QUAD_INTENSITY8_SGIS = 0x8123;
static const Word GL_DUAL_TEXTURE_SELECT_SGIS = 0x8124;
static const Word GL_QUAD_TEXTURE_SELECT_SGIS = 0x8125;
static const Word GL_ASYNC_MARKER_SGIX = 0x8329;
static const Word GL_ASYNC_HISTOGRAM_SGIX = 0x832c;
static const Word GL_MAX_ASYNC_HISTOGRAM_SGIX = 0x832d;
static const Word GL_ASYNC_TEX_IMAGE_SGIX = 0x835c;
static const Word GL_ASYNC_DRAW_PIXELS_SGIX = 0x835d;
static const Word GL_ASYNC_READ_PIXELS_SGIX = 0x835e;
static const Word GL_MAX_ASYNC_TEX_IMAGE_SGIX = 0x835f;
static const Word GL_MAX_ASYNC_DRAW_PIXELS_SGIX = 0x8360;
static const Word GL_MAX_ASYNC_READ_PIXELS_SGIX = 0x8361;
static const Word GL_ALPHA_MIN_SGIX = 0x8320;
static const Word GL_ALPHA_MAX_SGIX = 0x8321;
static const Word GL_CALLIGRAPHIC_FRAGMENT_SGIX = 0x8183;
static const Word GL_LINEAR_CLIPMAP_LINEAR_SGIX = 0x8170;
static const Word GL_TEXTURE_CLIPMAP_CENTER_SGIX = 0x8171;
static const Word GL_TEXTURE_CLIPMAP_FRAME_SGIX = 0x8172;
static const Word GL_TEXTURE_CLIPMAP_OFFSET_SGIX = 0x8173;
static const Word GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX = 0x8174;
static const Word GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX = 0x8175;
static const Word GL_TEXTURE_CLIPMAP_DEPTH_SGIX = 0x8176;
static const Word GL_MAX_CLIPMAP_DEPTH_SGIX = 0x8177;
static const Word GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX = 0x8178;
static const Word GL_NEAREST_CLIPMAP_NEAREST_SGIX = 0x844d;
static const Word GL_NEAREST_CLIPMAP_LINEAR_SGIX = 0x844e;
static const Word GL_LINEAR_CLIPMAP_NEAREST_SGIX = 0x844f;
static const Word GL_CONVOLUTION_HINT_SGIX = 0x8316;
static const Word GL_DEPTH_COMPONENT16_SGIX = 0x81a5;
static const Word GL_DEPTH_COMPONENT24_SGIX = 0x81a6;
static const Word GL_DEPTH_COMPONENT32_SGIX = 0x81a7;
static const Word GL_FOG_OFFSET_SGIX = 0x8198;
static const Word GL_FOG_OFFSET_VALUE_SGIX = 0x8199;
static const Word GL_FOG_SCALE_SGIX = 0x81fc;
static const Word GL_FOG_SCALE_VALUE_SGIX = 0x81fd;
static const Word GL_FRAGMENT_LIGHTING_SGIX = 0x8400;
static const Word GL_FRAGMENT_COLOR_MATERIAL_SGIX = 0x8401;
static const Word GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX = 0x8402;
static const Word GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX = 0x8403;
static const Word GL_MAX_FRAGMENT_LIGHTS_SGIX = 0x8404;
static const Word GL_MAX_ACTIVE_LIGHTS_SGIX = 0x8405;
static const Word GL_CURRENT_RASTER_NORMAL_SGIX = 0x8406;
static const Word GL_LIGHT_ENV_MODE_SGIX = 0x8407;
static const Word GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX = 0x8408;
static const Word GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX = 0x8409;
static const Word GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX = 0x840a;
static const Word GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX = 0x840b;
static const Word GL_FRAGMENT_LIGHT0_SGIX = 0x840c;
static const Word GL_FRAGMENT_LIGHT1_SGIX = 0x840d;
static const Word GL_FRAGMENT_LIGHT2_SGIX = 0x840e;
static const Word GL_FRAGMENT_LIGHT3_SGIX = 0x840f;
static const Word GL_FRAGMENT_LIGHT4_SGIX = 0x8410;
static const Word GL_FRAGMENT_LIGHT5_SGIX = 0x8411;
static const Word GL_FRAGMENT_LIGHT6_SGIX = 0x8412;
static const Word GL_FRAGMENT_LIGHT7_SGIX = 0x8413;
static const Word GL_FRAMEZOOM_SGIX = 0x818b;
static const Word GL_FRAMEZOOM_FACTOR_SGIX = 0x818c;
static const Word GL_MAX_FRAMEZOOM_FACTOR_SGIX = 0x818d;
static const Word GL_PIXEL_TEX_GEN_Q_CEILING_SGIX = 0x8184;
static const Word GL_PIXEL_TEX_GEN_Q_ROUND_SGIX = 0x8185;
static const Word GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX = 0x8186;
static const Word GL_PIXEL_TEX_GEN_ALPHA_REPLACE_SGIX = 0x8187;
static const Word GL_PIXEL_TEX_GEN_ALPHA_NO_REPLACE_SGIX = 0x8188;
static const Word GL_PIXEL_TEX_GEN_ALPHA_LS_SGIX = 0x8189;
static const Word GL_PIXEL_TEX_GEN_ALPHA_MS_SGIX = 0x818a;
static const Word GL_INSTRUMENT_BUFFER_POINTER_SGIX = 0x8180;
static const Word GL_INSTRUMENT_MEASUREMENTS_SGIX = 0x8181;
static const Word GL_INTERLACE_SGIX = 0x8094;
static const Word GL_IR_INSTRUMENT1_SGIX = 0x817f;
static const Word GL_LIST_PRIORITY_SGIX = 0x8182;
static const Word GL_PIXEL_TEX_GEN_SGIX = 0x8139;
static const Word GL_PIXEL_TEX_GEN_MODE_SGIX = 0x832b;
static const Word GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX = 0x813e;
static const Word GL_PIXEL_TILE_CACHE_INCREMENT_SGIX = 0x813f;
static const Word GL_PIXEL_TILE_WIDTH_SGIX = 0x8140;
static const Word GL_PIXEL_TILE_HEIGHT_SGIX = 0x8141;
static const Word GL_PIXEL_TILE_GRID_WIDTH_SGIX = 0x8142;
static const Word GL_PIXEL_TILE_GRID_HEIGHT_SGIX = 0x8143;
static const Word GL_PIXEL_TILE_GRID_DEPTH_SGIX = 0x8144;
static const Word GL_PIXEL_TILE_CACHE_SIZE_SGIX = 0x8145;
static const Word GL_GEOMETRY_DEFORMATION_SGIX = 0x8194;
static const Word GL_TEXTURE_DEFORMATION_SGIX = 0x8195;
static const Word GL_DEFORMATIONS_MASK_SGIX = 0x8196;
static const Word GL_MAX_DEFORMATION_ORDER_SGIX = 0x8197;
static const Word GL_REFERENCE_PLANE_SGIX = 0x817d;
static const Word GL_REFERENCE_PLANE_EQUATION_SGIX = 0x817e;
static const Word GL_PACK_RESAMPLE_SGIX = 0x842c;
static const Word GL_UNPACK_RESAMPLE_SGIX = 0x842d;
static const Word GL_RESAMPLE_REPLICATE_SGIX = 0x842e;
static const Word GL_RESAMPLE_ZERO_FILL_SGIX = 0x842f;
static const Word GL_RESAMPLE_DECIMATE_SGIX = 0x8430;
static const Word GL_SCALEBIAS_HINT_SGIX = 0x8322;
static const Word GL_TEXTURE_COMPARE_SGIX = 0x819a;
static const Word GL_TEXTURE_COMPARE_OPERATOR_SGIX = 0x819b;
static const Word GL_TEXTURE_LEQUAL_R_SGIX = 0x819c;
static const Word GL_TEXTURE_GEQUAL_R_SGIX = 0x819d;
static const Word GL_SHADOW_AMBIENT_SGIX = 0x80bf;
static const Word GL_SPRITE_SGIX = 0x8148;
static const Word GL_SPRITE_MODE_SGIX = 0x8149;
static const Word GL_SPRITE_AXIS_SGIX = 0x814a;
static const Word GL_SPRITE_TRANSLATION_SGIX = 0x814b;
static const Word GL_SPRITE_AXIAL_SGIX = 0x814c;
static const Word GL_SPRITE_OBJECT_ALIGNED_SGIX = 0x814d;
static const Word GL_SPRITE_EYE_ALIGNED_SGIX = 0x814e;
static const Word GL_PACK_SUBSAMPLE_RATE_SGIX = 0x85a0;
static const Word GL_UNPACK_SUBSAMPLE_RATE_SGIX = 0x85a1;
static const Word GL_PIXEL_SUBSAMPLE_4444_SGIX = 0x85a2;
static const Word GL_PIXEL_SUBSAMPLE_2424_SGIX = 0x85a3;
static const Word GL_PIXEL_SUBSAMPLE_4242_SGIX = 0x85a4;
static const Word GL_TEXTURE_ENV_BIAS_SGIX = 0x80be;
static const Word GL_TEXTURE_MAX_CLAMP_S_SGIX = 0x8369;
static const Word GL_TEXTURE_MAX_CLAMP_T_SGIX = 0x836a;
static const Word GL_TEXTURE_MAX_CLAMP_R_SGIX = 0x836b;
static const Word GL_TEXTURE_LOD_BIAS_S_SGIX = 0x818e;
static const Word GL_TEXTURE_LOD_BIAS_T_SGIX = 0x818f;
static const Word GL_TEXTURE_LOD_BIAS_R_SGIX = 0x8190;
static const Word GL_TEXTURE_MULTI_BUFFER_HINT_SGIX = 0x812e;
static const Word GL_POST_TEXTURE_FILTER_BIAS_SGIX = 0x8179;
static const Word GL_POST_TEXTURE_FILTER_SCALE_SGIX = 0x817a;
static const Word GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX = 0x817b;
static const Word GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX = 0x817c;
static const Word GL_VERTEX_PRECLIP_SGIX = 0x83ee;
static const Word GL_VERTEX_PRECLIP_HINT_SGIX = 0x83ef;
static const Word GL_YCRCB_422_SGIX = 0x81bb;
static const Word GL_YCRCB_444_SGIX = 0x81bc;
static const Word GL_YCRCB_SGIX = 0x8318;
static const Word GL_YCRCBA_SGIX = 0x8319;
static const Word GL_COLOR_MATRIX_SGI = 0x80b1;
static const Word GL_COLOR_MATRIX_STACK_DEPTH_SGI = 0x80b2;
static const Word GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI = 0x80b3;
static const Word GL_POST_COLOR_MATRIX_RED_SCALE_SGI = 0x80b4;
static const Word GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI = 0x80b5;
static const Word GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI = 0x80b6;
static const Word GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI = 0x80b7;
static const Word GL_POST_COLOR_MATRIX_RED_BIAS_SGI = 0x80b8;
static const Word GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI = 0x80b9;
static const Word GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI = 0x80ba;
static const Word GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI = 0x80bb;
static const Word GL_COLOR_TABLE_SGI = 0x80d0;
static const Word GL_POST_CONVOLUTION_COLOR_TABLE_SGI = 0x80d1;
static const Word GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI = 0x80d2;
static const Word GL_PROXY_COLOR_TABLE_SGI = 0x80d3;
static const Word GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI = 0x80d4;
static const Word GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI = 0x80d5;
static const Word GL_COLOR_TABLE_SCALE_SGI = 0x80d6;
static const Word GL_COLOR_TABLE_BIAS_SGI = 0x80d7;
static const Word GL_COLOR_TABLE_FORMAT_SGI = 0x80d8;
static const Word GL_COLOR_TABLE_WIDTH_SGI = 0x80d9;
static const Word GL_COLOR_TABLE_RED_SIZE_SGI = 0x80da;
static const Word GL_COLOR_TABLE_GREEN_SIZE_SGI = 0x80db;
static const Word GL_COLOR_TABLE_BLUE_SIZE_SGI = 0x80dc;
static const Word GL_COLOR_TABLE_ALPHA_SIZE_SGI = 0x80dd;
static const Word GL_COLOR_TABLE_LUMINANCE_SIZE_SGI = 0x80de;
static const Word GL_COLOR_TABLE_INTENSITY_SIZE_SGI = 0x80df;
static const Word GL_DEPTH_PASS_INSTRUMENT_SGIX = 0x8310;
static const Word GL_DEPTH_PASS_INSTRUMENT_COUNTERS_SGIX = 0x8311;
static const Word GL_DEPTH_PASS_INSTRUMENT_MAX_SGIX = 0x8312;
static const Word GL_TEXTURE_COLOR_TABLE_SGI = 0x80bc;
static const Word GL_PROXY_TEXTURE_COLOR_TABLE_SGI = 0x80bd;
static const Word GL_UNPACK_CONSTANT_DATA_SUNX = 0x81d5;
static const Word GL_TEXTURE_CONSTANT_DATA_SUNX = 0x81d6;
static const Word GL_WRAP_BORDER_SUN = 0x81d4;
static const Word GL_GLOBAL_ALPHA_SUN = 0x81d9;
static const Word GL_GLOBAL_ALPHA_FACTOR_SUN = 0x81da;
static const Word GL_QUAD_MESH_SUN = 0x8614;
static const Word GL_TRIANGLE_MESH_SUN = 0x8615;
static const Word GL_SLICE_ACCUM_SUN = 0x85cc;
static const Shortint GL_RESTART_SUN = 0x1;
static const Shortint GL_REPLACE_MIDDLE_SUN = 0x2;
static const Shortint GL_REPLACE_OLDEST_SUN = 0x3;
static const Word GL_TRIANGLE_LIST_SUN = 0x81d7;
static const Word GL_REPLACEMENT_CODE_SUN = 0x81d8;
static const Word GL_REPLACEMENT_CODE_ARRAY_SUN = 0x85c0;
static const Word GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN = 0x85c1;
static const Word GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN = 0x85c2;
static const Word GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN = 0x85c3;
static const Word GL_R1UI_V3F_SUN = 0x85c4;
static const Word GL_R1UI_C4UB_V3F_SUN = 0x85c5;
static const Word GL_R1UI_C3F_V3F_SUN = 0x85c6;
static const Word GL_R1UI_N3F_V3F_SUN = 0x85c7;
static const Word GL_R1UI_C4F_N3F_V3F_SUN = 0x85c8;
static const Word GL_R1UI_T2F_V3F_SUN = 0x85c9;
static const Word GL_R1UI_T2F_N3F_V3F_SUN = 0x85ca;
static const Word GL_R1UI_T2F_C4F_N3F_V3F_SUN = 0x85cb;
static const Word GL_PHONG_WIN = 0x80ea;
static const Word GL_PHONG_HINT_WIN = 0x80eb;
static const Word GL_FOG_SPECULAR_TEXTURE_WIN = 0x80ec;
static const Word GL_VERTEX_SHADER_ARB = 0x8b31;
static const Word GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB = 0x8b4a;
static const Word GL_MAX_VARYING_FLOATS_ARB = 0x8b4b;
static const Word GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB = 0x8b4c;
static const Word GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB = 0x8b4d;
static const Word GL_OBJECT_ACTIVE_ATTRIBUTES_ARB = 0x8b89;
static const Word GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB = 0x8b8a;
static const Word GL_FRAGMENT_SHADER_ARB = 0x8b30;
static const Word GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB = 0x8b49;
static const Word GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB = 0x8b8b;
static const Word GL_SAMPLES_PASSED_ARB = 0x8914;
static const Word GL_QUERY_COUNTER_BITS_ARB = 0x8864;
static const Word GL_CURRENT_QUERY_ARB = 0x8865;
static const Word GL_QUERY_RESULT_ARB = 0x8866;
static const Word GL_QUERY_RESULT_AVAILABLE_ARB = 0x8867;
static const Word GL_POINT_SPRITE_ARB = 0x8861;
static const Word GL_COORD_REPLACE_ARB = 0x8862;
static const Word GL_SHADING_LANGUAGE_VERSION_ARB = 0x8b8c;
static const Word GL_PROGRAM_OBJECT_ARB = 0x8b40;
static const Word GL_OBJECT_TYPE_ARB = 0x8b4e;
static const Word GL_OBJECT_SUBTYPE_ARB = 0x8b4f;
static const Word GL_OBJECT_DELETE_STATUS_ARB = 0x8b80;
static const Word GL_OBJECT_COMPILE_STATUS_ARB = 0x8b81;
static const Word GL_OBJECT_LINK_STATUS_ARB = 0x8b82;
static const Word GL_OBJECT_VALIDATE_STATUS_ARB = 0x8b83;
static const Word GL_OBJECT_INFO_LOG_LENGTH_ARB = 0x8b84;
static const Word GL_OBJECT_ATTACHED_OBJECTS_ARB = 0x8b85;
static const Word GL_OBJECT_ACTIVE_UNIFORMS_ARB = 0x8b86;
static const Word GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB = 0x8b87;
static const Word GL_OBJECT_SHADER_SOURCE_LENGTH_ARB = 0x8b88;
static const Word GL_SHADER_OBJECT_ARB = 0x8b48;
static const Word GL_FLOAT_VEC2_ARB = 0x8b50;
static const Word GL_FLOAT_VEC3_ARB = 0x8b51;
static const Word GL_FLOAT_VEC4_ARB = 0x8b52;
static const Word GL_INT_VEC2_ARB = 0x8b53;
static const Word GL_INT_VEC3_ARB = 0x8b54;
static const Word GL_INT_VEC4_ARB = 0x8b55;
static const Word GL_BOOL_ARB = 0x8b56;
static const Word GL_BOOL_VEC2_ARB = 0x8b57;
static const Word GL_BOOL_VEC3_ARB = 0x8b58;
static const Word GL_BOOL_VEC4_ARB = 0x8b59;
static const Word GL_FLOAT_MAT2_ARB = 0x8b5a;
static const Word GL_FLOAT_MAT3_ARB = 0x8b5b;
static const Word GL_FLOAT_MAT4_ARB = 0x8b5c;
static const Word GL_SAMPLER_1D_ARB = 0x8b5d;
static const Word GL_SAMPLER_2D_ARB = 0x8b5e;
static const Word GL_SAMPLER_3D_ARB = 0x8b5f;
static const Word GL_SAMPLER_CUBE_ARB = 0x8b60;
static const Word GL_SAMPLER_1D_SHADOW_ARB = 0x8b61;
static const Word GL_SAMPLER_2D_SHADOW_ARB = 0x8b62;
static const Word GL_SAMPLER_2D_RECT_ARB = 0x8b63;
static const Word GL_SAMPLER_2D_RECT_SHADOW_ARB = 0x8b64;
static const Word WGL_SAMPLE_BUFFERS_3DFX = 0x2060;
static const Word WGL_SAMPLES_3DFX = 0x2061;
static const Shortint WGL_FRONT_COLOR_BUFFER_BIT_ARB = 0x1;
static const Shortint WGL_BACK_COLOR_BUFFER_BIT_ARB = 0x2;
static const Shortint WGL_DEPTH_BUFFER_BIT_ARB = 0x4;
static const Shortint WGL_STENCIL_BUFFER_BIT_ARB = 0x8;
static const Word ERROR_INVALID_PIXEL_TYPE_ARB = 0x2043;
static const Word ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB = 0x2054;
static const Word WGL_SAMPLE_BUFFERS_ARB = 0x2041;
static const Word WGL_SAMPLES_ARB = 0x2042;
static const Word WGL_DRAW_TO_PBUFFER_ARB = 0x202d;
static const Word WGL_MAX_PBUFFER_PIXELS_ARB = 0x202e;
static const Word WGL_MAX_PBUFFER_WIDTH_ARB = 0x202f;
static const Word WGL_MAX_PBUFFER_HEIGHT_ARB = 0x2030;
static const Word WGL_PBUFFER_LARGEST_ARB = 0x2033;
static const Word WGL_PBUFFER_WIDTH_ARB = 0x2034;
static const Word WGL_PBUFFER_HEIGHT_ARB = 0x2035;
static const Word WGL_PBUFFER_LOST_ARB = 0x2036;
static const Word WGL_NUMBER_PIXEL_FORMATS_ARB = 0x2000;
static const Word WGL_DRAW_TO_WINDOW_ARB = 0x2001;
static const Word WGL_DRAW_TO_BITMAP_ARB = 0x2002;
static const Word WGL_ACCELERATION_ARB = 0x2003;
static const Word WGL_NEED_PALETTE_ARB = 0x2004;
static const Word WGL_NEED_SYSTEM_PALETTE_ARB = 0x2005;
static const Word WGL_SWAP_LAYER_BUFFERS_ARB = 0x2006;
static const Word WGL_SWAP_METHOD_ARB = 0x2007;
static const Word WGL_NUMBER_OVERLAYS_ARB = 0x2008;
static const Word WGL_NUMBER_UNDERLAYS_ARB = 0x2009;
static const Word WGL_TRANSPARENT_ARB = 0x200a;
static const Word WGL_TRANSPARENT_RED_VALUE_ARB = 0x2037;
static const Word WGL_TRANSPARENT_GREEN_VALUE_ARB = 0x2038;
static const Word WGL_TRANSPARENT_BLUE_VALUE_ARB = 0x2039;
static const Word WGL_TRANSPARENT_ALPHA_VALUE_ARB = 0x203a;
static const Word WGL_TRANSPARENT_INDEX_VALUE_ARB = 0x203b;
static const Word WGL_SHARE_DEPTH_ARB = 0x200c;
static const Word WGL_SHARE_STENCIL_ARB = 0x200d;
static const Word WGL_SHARE_ACCUM_ARB = 0x200e;
static const Word WGL_SUPPORT_GDI_ARB = 0x200f;
static const Word WGL_SUPPORT_OPENGL_ARB = 0x2010;
static const Word WGL_DOUBLE_BUFFER_ARB = 0x2011;
static const Word WGL_STEREO_ARB = 0x2012;
static const Word WGL_PIXEL_TYPE_ARB = 0x2013;
static const Word WGL_COLOR_BITS_ARB = 0x2014;
static const Word WGL_RED_BITS_ARB = 0x2015;
static const Word WGL_RED_SHIFT_ARB = 0x2016;
static const Word WGL_GREEN_BITS_ARB = 0x2017;
static const Word WGL_GREEN_SHIFT_ARB = 0x2018;
static const Word WGL_BLUE_BITS_ARB = 0x2019;
static const Word WGL_BLUE_SHIFT_ARB = 0x201a;
static const Word WGL_ALPHA_BITS_ARB = 0x201b;
static const Word WGL_ALPHA_SHIFT_ARB = 0x201c;
static const Word WGL_ACCUM_BITS_ARB = 0x201d;
static const Word WGL_ACCUM_RED_BITS_ARB = 0x201e;
static const Word WGL_ACCUM_GREEN_BITS_ARB = 0x201f;
static const Word WGL_ACCUM_BLUE_BITS_ARB = 0x2020;
static const Word WGL_ACCUM_ALPHA_BITS_ARB = 0x2021;
static const Word WGL_DEPTH_BITS_ARB = 0x2022;
static const Word WGL_STENCIL_BITS_ARB = 0x2023;
static const Word WGL_AUX_BUFFERS_ARB = 0x2024;
static const Word WGL_NO_ACCELERATION_ARB = 0x2025;
static const Word WGL_GENERIC_ACCELERATION_ARB = 0x2026;
static const Word WGL_FULL_ACCELERATION_ARB = 0x2027;
static const Word WGL_SWAP_EXCHANGE_ARB = 0x2028;
static const Word WGL_SWAP_COPY_ARB = 0x2029;
static const Word WGL_SWAP_UNDEFINED_ARB = 0x202a;
static const Word WGL_TYPE_RGBA_ARB = 0x202b;
static const Word WGL_TYPE_COLORINDEX_ARB = 0x202c;
static const Word WGL_RGBA_FLOAT_MODE_ARB = 0x8820;
static const Word WGL_CLAMP_VERTEX_COLOR_ARB = 0x891a;
static const Word WGL_CLAMP_FRAGMENT_COLOR_ARB = 0x891b;
static const Word WGL_CLAMP_READ_COLOR_ARB = 0x891c;
static const Word WGL_FIXED_ONLY_ARB = 0x891d;
static const Word WGL_BIND_TO_TEXTURE_RGB_ARB = 0x2070;
static const Word WGL_BIND_TO_TEXTURE_RGBA_ARB = 0x2071;
static const Word WGL_TEXTURE_FORMAT_ARB = 0x2072;
static const Word WGL_TEXTURE_TARGET_ARB = 0x2073;
static const Word WGL_MIPMAP_TEXTURE_ARB = 0x2074;
static const Word WGL_TEXTURE_RGB_ARB = 0x2075;
static const Word WGL_TEXTURE_RGBA_ARB = 0x2076;
static const Word WGL_NO_TEXTURE_ARB = 0x2077;
static const Word WGL_TEXTURE_CUBE_MAP_ARB = 0x2078;
static const Word WGL_TEXTURE_1D_ARB = 0x2079;
static const Word WGL_TEXTURE_2D_ARB = 0x207a;
static const Word WGL_MIPMAP_LEVEL_ARB = 0x207b;
static const Word WGL_CUBE_MAP_FACE_ARB = 0x207c;
static const Word WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB = 0x207d;
static const Word WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB = 0x207e;
static const Word WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB = 0x207f;
static const Word WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB = 0x2080;
static const Word WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB = 0x2081;
static const Word WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB = 0x2082;
static const Word WGL_FRONT_LEFT_ARB = 0x2083;
static const Word WGL_FRONT_RIGHT_ARB = 0x2084;
static const Word WGL_BACK_LEFT_ARB = 0x2085;
static const Word WGL_BACK_RIGHT_ARB = 0x2086;
static const Word WGL_AUX0_ARB = 0x2087;
static const Word WGL_AUX1_ARB = 0x2088;
static const Word WGL_AUX2_ARB = 0x2089;
static const Word WGL_AUX3_ARB = 0x208a;
static const Word WGL_AUX4_ARB = 0x208b;
static const Word WGL_AUX5_ARB = 0x208c;
static const Word WGL_AUX6_ARB = 0x208d;
static const Word WGL_AUX7_ARB = 0x208e;
static const Word WGL_AUX8_ARB = 0x208f;
static const Word WGL_AUX9_ARB = 0x2090;
static const Word WGL_TYPE_RGBA_FLOAT_ATI = 0x21a0;
static const Word GL_TYPE_RGBA_FLOAT_ATI = 0x8820;
static const Word GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI = 0x8835;
static const Word WGL_DEPTH_FLOAT_EXT = 0x2040;
static const Word ERROR_INVALID_PIXEL_TYPE_EXT = 0x2043;
static const Word WGL_SAMPLE_BUFFERS_EXT = 0x2041;
static const Word WGL_SAMPLES_EXT = 0x2042;
static const Word WGL_DRAW_TO_PBUFFER_EXT = 0x202d;
static const Word WGL_MAX_PBUFFER_PIXELS_EXT = 0x202e;
static const Word WGL_MAX_PBUFFER_WIDTH_EXT = 0x202f;
static const Word WGL_MAX_PBUFFER_HEIGHT_EXT = 0x2030;
static const Word WGL_OPTIMAL_PBUFFER_WIDTH_EXT = 0x2031;
static const Word WGL_OPTIMAL_PBUFFER_HEIGHT_EXT = 0x2032;
static const Word WGL_PBUFFER_LARGEST_EXT = 0x2033;
static const Word WGL_PBUFFER_WIDTH_EXT = 0x2034;
static const Word WGL_PBUFFER_HEIGHT_EXT = 0x2035;
static const Word WGL_NUMBER_PIXEL_FORMATS_EXT = 0x2000;
static const Word WGL_DRAW_TO_WINDOW_EXT = 0x2001;
static const Word WGL_DRAW_TO_BITMAP_EXT = 0x2002;
static const Word WGL_ACCELERATION_EXT = 0x2003;
static const Word WGL_NEED_PALETTE_EXT = 0x2004;
static const Word WGL_NEED_SYSTEM_PALETTE_EXT = 0x2005;
static const Word WGL_SWAP_LAYER_BUFFERS_EXT = 0x2006;
static const Word WGL_SWAP_METHOD_EXT = 0x2007;
static const Word WGL_NUMBER_OVERLAYS_EXT = 0x2008;
static const Word WGL_NUMBER_UNDERLAYS_EXT = 0x2009;
static const Word WGL_TRANSPARENT_EXT = 0x200a;
static const Word WGL_TRANSPARENT_VALUE_EXT = 0x200b;
static const Word WGL_SHARE_DEPTH_EXT = 0x200c;
static const Word WGL_SHARE_STENCIL_EXT = 0x200d;
static const Word WGL_SHARE_ACCUM_EXT = 0x200e;
static const Word WGL_SUPPORT_GDI_EXT = 0x200f;
static const Word WGL_SUPPORT_OPENGL_EXT = 0x2010;
static const Word WGL_DOUBLE_BUFFER_EXT = 0x2011;
static const Word WGL_STEREO_EXT = 0x2012;
static const Word WGL_PIXEL_TYPE_EXT = 0x2013;
static const Word WGL_COLOR_BITS_EXT = 0x2014;
static const Word WGL_RED_BITS_EXT = 0x2015;
static const Word WGL_RED_SHIFT_EXT = 0x2016;
static const Word WGL_GREEN_BITS_EXT = 0x2017;
static const Word WGL_GREEN_SHIFT_EXT = 0x2018;
static const Word WGL_BLUE_BITS_EXT = 0x2019;
static const Word WGL_BLUE_SHIFT_EXT = 0x201a;
static const Word WGL_ALPHA_BITS_EXT = 0x201b;
static const Word WGL_ALPHA_SHIFT_EXT = 0x201c;
static const Word WGL_ACCUM_BITS_EXT = 0x201d;
static const Word WGL_ACCUM_RED_BITS_EXT = 0x201e;
static const Word WGL_ACCUM_GREEN_BITS_EXT = 0x201f;
static const Word WGL_ACCUM_BLUE_BITS_EXT = 0x2020;
static const Word WGL_ACCUM_ALPHA_BITS_EXT = 0x2021;
static const Word WGL_DEPTH_BITS_EXT = 0x2022;
static const Word WGL_STENCIL_BITS_EXT = 0x2023;
static const Word WGL_AUX_BUFFERS_EXT = 0x2024;
static const Word WGL_NO_ACCELERATION_EXT = 0x2025;
static const Word WGL_GENERIC_ACCELERATION_EXT = 0x2026;
static const Word WGL_FULL_ACCELERATION_EXT = 0x2027;
static const Word WGL_SWAP_EXCHANGE_EXT = 0x2028;
static const Word WGL_SWAP_COPY_EXT = 0x2029;
static const Word WGL_SWAP_UNDEFINED_EXT = 0x202a;
static const Word WGL_TYPE_RGBA_EXT = 0x202b;
static const Word WGL_TYPE_COLORINDEX_EXT = 0x202c;
static const Word WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D = 0x2050;
static const Word WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D = 0x2051;
static const Word WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D = 0x2052;
static const Word WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D = 0x2053;
static const Word WGL_GAMMA_TABLE_SIZE_I3D = 0x204e;
static const Word WGL_GAMMA_EXCLUDE_DESKTOP_I3D = 0x204f;
static const Word WGL_GENLOCK_SOURCE_MULTIVIEW_I3D = 0x2044;
static const Word WGL_GENLOCK_SOURCE_EXTENAL_SYNC_I3D = 0x2045;
static const Word WGL_GENLOCK_SOURCE_EXTENAL_FIELD_I3D = 0x2046;
static const Word WGL_GENLOCK_SOURCE_EXTENAL_TTL_I3D = 0x2047;
static const Word WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D = 0x2048;
static const Word WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D = 0x2049;
static const Word WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D = 0x204a;
static const Word WGL_GENLOCK_SOURCE_EDGE_RISING_I3D = 0x204b;
static const Word WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D = 0x204c;
static const Shortint WGL_IMAGE_BUFFER_MIN_ACCESS_I3D = 0x1;
static const Shortint WGL_IMAGE_BUFFER_LOCK_I3D = 0x2;
static const Word WGL_FLOAT_COMPONENTS_NV = 0x20b0;
static const Word WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV = 0x20b1;
static const Word WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV = 0x20b2;
static const Word WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV = 0x20b3;
static const Word WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV = 0x20b4;
static const Word WGL_TEXTURE_FLOAT_R_NV = 0x20b5;
static const Word WGL_TEXTURE_FLOAT_RG_NV = 0x20b6;
static const Word WGL_TEXTURE_FLOAT_RGB_NV = 0x20b7;
static const Word WGL_TEXTURE_FLOAT_RGBA_NV = 0x20b8;
static const Word WGL_BIND_TO_TEXTURE_DEPTH_NV = 0x20a3;
static const Word WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV = 0x20a4;
static const Word WGL_DEPTH_TEXTURE_FORMAT_NV = 0x20a5;
static const Word WGL_TEXTURE_DEPTH_COMPONENT_NV = 0x20a6;
static const Word WGL_DEPTH_COMPONENT_NV = 0x20a7;
static const Word WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV = 0x20a0;
static const Word WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV = 0x20a1;
static const Word WGL_TEXTURE_RECTANGLE_NV = 0x20a2;
static const Word GL_MAX_ELEMENTS_VERTICES_WIN = 0x80e8;
static const Word GL_MAX_ELEMENTS_INDICES_WIN = 0x80e9;
static const int GLU_INVALID_ENUM = 0x18a24;
static const int GLU_INVALID_VALUE = 0x18a25;
static const int GLU_OUT_OF_MEMORY = 0x18a26;
static const int GLU_INCOMPATIBLE_GL_VERSION = 0x18a27;
static const int GLU_VERSION = 0x189c0;
static const int GLU_EXTENSIONS = 0x189c1;
static const Shortint GLU_TRUE = 0x1;
static const Shortint GLU_FALSE = 0x0;
static const int GLU_SMOOTH = 0x186a0;
static const int GLU_FLAT = 0x186a1;
static const int GLU_NONE = 0x186a2;
static const int GLU_POINT = 0x186aa;
static const int GLU_LINE = 0x186ab;
static const int GLU_FILL = 0x186ac;
static const int GLU_SILHOUETTE = 0x186ad;
static const int GLU_OUTSIDE = 0x186b4;
static const int GLU_INSIDE = 0x186b5;
static const Extended GLU_TESS_MAX_COORD = 1.000000E+150;
static const int GLU_TESS_WINDING_RULE = 0x1872c;
static const int GLU_TESS_BOUNDARY_ONLY = 0x1872d;
static const int GLU_TESS_TOLERANCE = 0x1872e;
static const int GLU_TESS_WINDING_ODD = 0x18722;
static const int GLU_TESS_WINDING_NONZERO = 0x18723;
static const int GLU_TESS_WINDING_POSITIVE = 0x18724;
static const int GLU_TESS_WINDING_NEGATIVE = 0x18725;
static const int GLU_TESS_WINDING_ABS_GEQ_TWO = 0x18726;
static const int GLU_TESS_BEGIN = 0x18704;
static const int GLU_TESS_VERTEX = 0x18705;
static const int GLU_TESS_END = 0x18706;
static const int GLU_TESS_ERROR = 0x18707;
static const int GLU_TESS_EDGE_FLAG = 0x18708;
static const int GLU_TESS_COMBINE = 0x18709;
static const int GLU_TESS_BEGIN_DATA = 0x1870a;
static const int GLU_TESS_VERTEX_DATA = 0x1870b;
static const int GLU_TESS_END_DATA = 0x1870c;
static const int GLU_TESS_ERROR_DATA = 0x1870d;
static const int GLU_TESS_EDGE_FLAG_DATA = 0x1870e;
static const int GLU_TESS_COMBINE_DATA = 0x1870f;
static const int GLU_TESS_ERROR1 = 0x18737;
static const int GLU_TESS_ERROR2 = 0x18738;
static const int GLU_TESS_ERROR3 = 0x18739;
static const int GLU_TESS_ERROR4 = 0x1873a;
static const int GLU_TESS_ERROR5 = 0x1873b;
static const int GLU_TESS_ERROR6 = 0x1873c;
static const int GLU_TESS_ERROR7 = 0x1873d;
static const int GLU_TESS_ERROR8 = 0x1873e;
static const int GLU_TESS_MISSING_BEGIN_POLYGON = 0x18737;
static const int GLU_TESS_MISSING_BEGIN_CONTOUR = 0x18738;
static const int GLU_TESS_MISSING_END_POLYGON = 0x18739;
static const int GLU_TESS_MISSING_END_CONTOUR = 0x1873a;
static const int GLU_TESS_COORD_TOO_LARGE = 0x1873b;
static const int GLU_TESS_NEED_COMBINE_CALLBACK = 0x1873c;
static const int GLU_AUTO_LOAD_MATRIX = 0x18768;
static const int GLU_CULLING = 0x18769;
static const int GLU_SAMPLING_TOLERANCE = 0x1876b;
static const int GLU_DISPLAY_MODE = 0x1876c;
static const int GLU_PARAMETRIC_TOLERANCE = 0x1876a;
static const int GLU_SAMPLING_METHOD = 0x1876d;
static const int GLU_U_STEP = 0x1876e;
static const int GLU_V_STEP = 0x1876f;
static const int GLU_PATH_LENGTH = 0x18777;
static const int GLU_PARAMETRIC_ERROR = 0x18778;
static const int GLU_DOMAIN_DISTANCE = 0x18779;
static const int GLU_MAP1_TRIM_2 = 0x18772;
static const int GLU_MAP1_TRIM_3 = 0x18773;
static const int GLU_OUTLINE_POLYGON = 0x18790;
static const int GLU_OUTLINE_PATCH = 0x18791;
static const int GLU_NURBS_ERROR1 = 0x1879b;
static const int GLU_NURBS_ERROR2 = 0x1879c;
static const int GLU_NURBS_ERROR3 = 0x1879d;
static const int GLU_NURBS_ERROR4 = 0x1879e;
static const int GLU_NURBS_ERROR5 = 0x1879f;
static const int GLU_NURBS_ERROR6 = 0x187a0;
static const int GLU_NURBS_ERROR7 = 0x187a1;
static const int GLU_NURBS_ERROR8 = 0x187a2;
static const int GLU_NURBS_ERROR9 = 0x187a3;
static const int GLU_NURBS_ERROR10 = 0x187a4;
static const int GLU_NURBS_ERROR11 = 0x187a5;
static const int GLU_NURBS_ERROR12 = 0x187a6;
static const int GLU_NURBS_ERROR13 = 0x187a7;
static const int GLU_NURBS_ERROR14 = 0x187a8;
static const int GLU_NURBS_ERROR15 = 0x187a9;
static const int GLU_NURBS_ERROR16 = 0x187aa;
static const int GLU_NURBS_ERROR17 = 0x187ab;
static const int GLU_NURBS_ERROR18 = 0x187ac;
static const int GLU_NURBS_ERROR19 = 0x187ad;
static const int GLU_NURBS_ERROR20 = 0x187ae;
static const int GLU_NURBS_ERROR21 = 0x187af;
static const int GLU_NURBS_ERROR22 = 0x187b0;
static const int GLU_NURBS_ERROR23 = 0x187b1;
static const int GLU_NURBS_ERROR24 = 0x187b2;
static const int GLU_NURBS_ERROR25 = 0x187b3;
static const int GLU_NURBS_ERROR26 = 0x187b4;
static const int GLU_NURBS_ERROR27 = 0x187b5;
static const int GLU_NURBS_ERROR28 = 0x187b6;
static const int GLU_NURBS_ERROR29 = 0x187b7;
static const int GLU_NURBS_ERROR30 = 0x187b8;
static const int GLU_NURBS_ERROR31 = 0x187b9;
static const int GLU_NURBS_ERROR32 = 0x187ba;
static const int GLU_NURBS_ERROR33 = 0x187bb;
static const int GLU_NURBS_ERROR34 = 0x187bc;
static const int GLU_NURBS_ERROR35 = 0x187bd;
static const int GLU_NURBS_ERROR36 = 0x187be;
static const int GLU_NURBS_ERROR37 = 0x187bf;
static const int GLU_CW = 0x18718;
static const int GLU_CCW = 0x18719;
static const int GLU_INTERIOR = 0x1871a;
static const int GLU_EXTERIOR = 0x1871b;
static const int GLU_UNKNOWN = 0x1871c;
static const int GLU_BEGIN = 0x18704;
static const int GLU_VERTEX = 0x18705;
static const int GLU_END = 0x18706;
static const int GLU_ERROR = 0x18707;
static const int GLU_EDGE_FLAG = 0x18708;
extern PACKAGE TglAccum glAccum;
extern PACKAGE TglAlphaFunc glAlphaFunc;
extern PACKAGE TglAreTexturesResident glAreTexturesResident;
extern PACKAGE TglArrayElement glArrayElement;
extern PACKAGE TglBegin glBegin;
extern PACKAGE TglBindTexture glBindTexture;
extern PACKAGE TglBitmap glBitmap;
extern PACKAGE TglBlendFunc glBlendFunc;
extern PACKAGE TglCallList glCallList;
extern PACKAGE TglCallLists glCallLists;
extern PACKAGE TglClear glClear;
extern PACKAGE TglClearAccum glClearAccum;
extern PACKAGE TglClearColor glClearColor;
extern PACKAGE TglClearDepth glClearDepth;
extern PACKAGE TglClearIndex glClearIndex;
extern PACKAGE TglClearStencil glClearStencil;
extern PACKAGE TglClipPlane glClipPlane;
extern PACKAGE TglColor3b glColor3b;
extern PACKAGE TglColor3bv glColor3bv;
extern PACKAGE TglColor3d glColor3d;
extern PACKAGE TglColor3dv glColor3dv;
extern PACKAGE TglColor3f glColor3f;
extern PACKAGE TglColor3fv glColor3fv;
extern PACKAGE TglColor3i glColor3i;
extern PACKAGE TglColor3iv glColor3iv;
extern PACKAGE TglColor3s glColor3s;
extern PACKAGE TglColor3sv glColor3sv;
extern PACKAGE TglColor3ub glColor3ub;
extern PACKAGE TglColor3ubv glColor3ubv;
extern PACKAGE TglColor3ui glColor3ui;
extern PACKAGE TglColor3uiv glColor3uiv;
extern PACKAGE TglColor3us glColor3us;
extern PACKAGE TglColor3usv glColor3usv;
extern PACKAGE TglColor4b glColor4b;
extern PACKAGE TglColor4bv glColor4bv;
extern PACKAGE TglColor4d glColor4d;
extern PACKAGE TglColor4dv glColor4dv;
extern PACKAGE TglColor4f glColor4f;
extern PACKAGE TglColor4fv glColor4fv;
extern PACKAGE TglColor4i glColor4i;
extern PACKAGE TglColor4iv glColor4iv;
extern PACKAGE TglColor4s glColor4s;
extern PACKAGE TglColor4sv glColor4sv;
extern PACKAGE TglColor4ub glColor4ub;
extern PACKAGE TglColor4ubv glColor4ubv;
extern PACKAGE TglColor4ui glColor4ui;
extern PACKAGE TglColor4uiv glColor4uiv;
extern PACKAGE TglColor4us glColor4us;
extern PACKAGE TglColor4usv glColor4usv;
extern PACKAGE TglColorMask glColorMask;
extern PACKAGE TglColorMaterial glColorMaterial;
extern PACKAGE TglCopyPixels glCopyPixels;
extern PACKAGE TglCopyTexImage1D glCopyTexImage1D;
extern PACKAGE TglCopyTexImage2D glCopyTexImage2D;
extern PACKAGE TglCopyTexSubImage1D glCopyTexSubImage1D;
extern PACKAGE TglCopyTexSubImage2D glCopyTexSubImage2D;
extern PACKAGE TglCullFace glCullFace;
extern PACKAGE TglDeleteLists glDeleteLists;
extern PACKAGE TglDeleteTextures glDeleteTextures;
extern PACKAGE TglDepthFunc glDepthFunc;
extern PACKAGE TglDepthMask glDepthMask;
extern PACKAGE TglDepthRange glDepthRange;
extern PACKAGE TglDisable glDisable;
extern PACKAGE TglDisableClientState glDisableClientState;
extern PACKAGE TglDrawArrays glDrawArrays;
extern PACKAGE TglDrawBuffer glDrawBuffer;
extern PACKAGE TglDrawElements glDrawElements;
extern PACKAGE TglDrawPixels glDrawPixels;
extern PACKAGE TglEdgeFlag glEdgeFlag;
extern PACKAGE TglEdgeFlagPointer glEdgeFlagPointer;
extern PACKAGE TglEdgeFlagv glEdgeFlagv;
extern PACKAGE TglEnable glEnable;
extern PACKAGE TglEnableClientState glEnableClientState;
extern PACKAGE TglEnd glEnd;
extern PACKAGE TglEndList glEndList;
extern PACKAGE TglEvalCoord1d glEvalCoord1d;
extern PACKAGE TglEvalCoord1dv glEvalCoord1dv;
extern PACKAGE TglEvalCoord1f glEvalCoord1f;
extern PACKAGE TglEvalCoord1fv glEvalCoord1fv;
extern PACKAGE TglEvalCoord2d glEvalCoord2d;
extern PACKAGE TglEvalCoord2dv glEvalCoord2dv;
extern PACKAGE TglEvalCoord2f glEvalCoord2f;
extern PACKAGE TglEvalCoord2fv glEvalCoord2fv;
extern PACKAGE TglEvalMesh1 glEvalMesh1;
extern PACKAGE TglEvalMesh2 glEvalMesh2;
extern PACKAGE TglEvalPoint1 glEvalPoint1;
extern PACKAGE TglEvalPoint2 glEvalPoint2;
extern PACKAGE TglFeedbackBuffer glFeedbackBuffer;
extern PACKAGE TglFinish glFinish;
extern PACKAGE TglFlush glFlush;
extern PACKAGE TglFogf glFogf;
extern PACKAGE TglFogfv glFogfv;
extern PACKAGE TglFogi glFogi;
extern PACKAGE TglFogiv glFogiv;
extern PACKAGE TglFrontFace glFrontFace;
extern PACKAGE TglFrustum glFrustum;
extern PACKAGE TglGenLists glGenLists;
extern PACKAGE TglGetBooleanv glGetBooleanv;
extern PACKAGE TglGetClipPlane glGetClipPlane;
extern PACKAGE TglGetDoublev glGetDoublev;
extern PACKAGE TglGetError glGetError;
extern PACKAGE TglGetFloatv glGetFloatv;
extern PACKAGE TglGetIntegerv glGetIntegerv;
extern PACKAGE TglGetLightfv glGetLightfv;
extern PACKAGE TglGetLightiv glGetLightiv;
extern PACKAGE TglGetMapdv glGetMapdv;
extern PACKAGE TglGetMapfv glGetMapfv;
extern PACKAGE TglGetMapiv glGetMapiv;
extern PACKAGE TglGetMaterialfv glGetMaterialfv;
extern PACKAGE TglGetMaterialiv glGetMaterialiv;
extern PACKAGE TglGetPixelMapfv glGetPixelMapfv;
extern PACKAGE TglGetPixelMapuiv glGetPixelMapuiv;
extern PACKAGE TglGetPixelMapusv glGetPixelMapusv;
extern PACKAGE TglGetPointerv glGetPointerv;
extern PACKAGE TglGetPolygonStipple glGetPolygonStipple;
extern PACKAGE TglGetTexEnvfv glGetTexEnvfv;
extern PACKAGE TglGetTexEnviv glGetTexEnviv;
extern PACKAGE TglGetTexGendv glGetTexGendv;
extern PACKAGE TglGetTexGenfv glGetTexGenfv;
extern PACKAGE TglGetTexGeniv glGetTexGeniv;
extern PACKAGE TglGetTexImage glGetTexImage;
extern PACKAGE TglGetTexLevelParameterfv glGetTexLevelParameterfv;
extern PACKAGE TglGetTexLevelParameteriv glGetTexLevelParameteriv;
extern PACKAGE TglGetTexParameterfv glGetTexParameterfv;
extern PACKAGE TglGetTexParameteriv glGetTexParameteriv;
extern PACKAGE TglHint glHint;
extern PACKAGE TglIndexMask glIndexMask;
extern PACKAGE TglIndexPointer glIndexPointer;
extern PACKAGE TglIndexd glIndexd;
extern PACKAGE TglIndexdv glIndexdv;
extern PACKAGE TglIndexf glIndexf;
extern PACKAGE TglIndexfv glIndexfv;
extern PACKAGE TglIndexi glIndexi;
extern PACKAGE TglIndexiv glIndexiv;
extern PACKAGE TglIndexs glIndexs;
extern PACKAGE TglIndexsv glIndexsv;
extern PACKAGE TglIndexub glIndexub;
extern PACKAGE TglIndexubv glIndexubv;
extern PACKAGE TglInitNames glInitNames;
extern PACKAGE TglInterleavedArrays glInterleavedArrays;
extern PACKAGE TglIsEnabled glIsEnabled;
extern PACKAGE TglIsList glIsList;
extern PACKAGE TglIsTexture glIsTexture;
extern PACKAGE TglLightModelf glLightModelf;
extern PACKAGE TglLightModelfv glLightModelfv;
extern PACKAGE TglLightModeli glLightModeli;
extern PACKAGE TglLightModeliv glLightModeliv;
extern PACKAGE TglLightf glLightf;
extern PACKAGE TglLightfv glLightfv;
extern PACKAGE TglLighti glLighti;
extern PACKAGE TglLightiv glLightiv;
extern PACKAGE TglLineStipple glLineStipple;
extern PACKAGE TglLineWidth glLineWidth;
extern PACKAGE TglListBase glListBase;
extern PACKAGE TglLoadIdentity glLoadIdentity;
extern PACKAGE TglLoadMatrixd glLoadMatrixd;
extern PACKAGE TglLoadMatrixf glLoadMatrixf;
extern PACKAGE TglLoadName glLoadName;
extern PACKAGE TglLogicOp glLogicOp;
extern PACKAGE TglMap1d glMap1d;
extern PACKAGE TglMap1f glMap1f;
extern PACKAGE TglMap2d glMap2d;
extern PACKAGE TglMap2f glMap2f;
extern PACKAGE TglMapGrid1d glMapGrid1d;
extern PACKAGE TglMapGrid1f glMapGrid1f;
extern PACKAGE TglMapGrid2d glMapGrid2d;
extern PACKAGE TglMapGrid2f glMapGrid2f;
extern PACKAGE TglMaterialf glMaterialf;
extern PACKAGE TglMaterialfv glMaterialfv;
extern PACKAGE TglMateriali glMateriali;
extern PACKAGE TglMaterialiv glMaterialiv;
extern PACKAGE TglMatrixMode glMatrixMode;
extern PACKAGE TglMultMatrixd glMultMatrixd;
extern PACKAGE TglMultMatrixf glMultMatrixf;
extern PACKAGE TglNewList glNewList;
extern PACKAGE TglNormal3b glNormal3b;
extern PACKAGE TglNormal3bv glNormal3bv;
extern PACKAGE TglNormal3d glNormal3d;
extern PACKAGE TglNormal3dv glNormal3dv;
extern PACKAGE TglNormal3f glNormal3f;
extern PACKAGE TglNormal3fv glNormal3fv;
extern PACKAGE TglNormal3i glNormal3i;
extern PACKAGE TglNormal3iv glNormal3iv;
extern PACKAGE TglNormal3s glNormal3s;
extern PACKAGE TglNormal3sv glNormal3sv;
extern PACKAGE TglOrtho glOrtho;
extern PACKAGE TglPassThrough glPassThrough;
extern PACKAGE TglPixelMapfv glPixelMapfv;
extern PACKAGE TglPixelMapuiv glPixelMapuiv;
extern PACKAGE TglPixelMapusv glPixelMapusv;
extern PACKAGE TglPixelStoref glPixelStoref;
extern PACKAGE TglPixelStorei glPixelStorei;
extern PACKAGE TglPixelTransferf glPixelTransferf;
extern PACKAGE TglPixelTransferi glPixelTransferi;
extern PACKAGE TglPixelZoom glPixelZoom;
extern PACKAGE TglPointSize glPointSize;
extern PACKAGE TglPolygonMode glPolygonMode;
extern PACKAGE TglPolygonOffset glPolygonOffset;
extern PACKAGE TglPolygonStipple glPolygonStipple;
extern PACKAGE TglPopAttrib glPopAttrib;
extern PACKAGE TglPopClientAttrib glPopClientAttrib;
extern PACKAGE TglPopMatrix glPopMatrix;
extern PACKAGE TglPopName glPopName;
extern PACKAGE TglPrioritizeTextures glPrioritizeTextures;
extern PACKAGE TglPushAttrib glPushAttrib;
extern PACKAGE TglPushClientAttrib glPushClientAttrib;
extern PACKAGE TglPushMatrix glPushMatrix;
extern PACKAGE TglPushName glPushName;
extern PACKAGE TglRasterPos2d glRasterPos2d;
extern PACKAGE TglRasterPos2dv glRasterPos2dv;
extern PACKAGE TglRasterPos2f glRasterPos2f;
extern PACKAGE TglRasterPos2fv glRasterPos2fv;
extern PACKAGE TglRasterPos2i glRasterPos2i;
extern PACKAGE TglRasterPos2iv glRasterPos2iv;
extern PACKAGE TglRasterPos2s glRasterPos2s;
extern PACKAGE TglRasterPos2sv glRasterPos2sv;
extern PACKAGE TglRasterPos3d glRasterPos3d;
extern PACKAGE TglRasterPos3dv glRasterPos3dv;
extern PACKAGE TglRasterPos3f glRasterPos3f;
extern PACKAGE TglRasterPos3fv glRasterPos3fv;
extern PACKAGE TglRasterPos3i glRasterPos3i;
extern PACKAGE TglRasterPos3iv glRasterPos3iv;
extern PACKAGE TglRasterPos3s glRasterPos3s;
extern PACKAGE TglRasterPos3sv glRasterPos3sv;
extern PACKAGE TglRasterPos4d glRasterPos4d;
extern PACKAGE TglRasterPos4dv glRasterPos4dv;
extern PACKAGE TglRasterPos4f glRasterPos4f;
extern PACKAGE TglRasterPos4fv glRasterPos4fv;
extern PACKAGE TglRasterPos4i glRasterPos4i;
extern PACKAGE TglRasterPos4iv glRasterPos4iv;
extern PACKAGE TglRasterPos4s glRasterPos4s;
extern PACKAGE TglRasterPos4sv glRasterPos4sv;
extern PACKAGE TglReadBuffer glReadBuffer;
extern PACKAGE TglRectd glRectd;
extern PACKAGE TglRectdv glRectdv;
extern PACKAGE TglRectf glRectf;
extern PACKAGE TglRectfv glRectfv;
extern PACKAGE TglRecti glRecti;
extern PACKAGE TglRectiv glRectiv;
extern PACKAGE TglRects glRects;
extern PACKAGE TglRectsv glRectsv;
extern PACKAGE TglRenderMode glRenderMode;
extern PACKAGE TglRotated glRotated;
extern PACKAGE TglRotatef glRotatef;
extern PACKAGE TglScaled glScaled;
extern PACKAGE TglScalef glScalef;
extern PACKAGE TglScissor glScissor;
extern PACKAGE TglSelectBuffer glSelectBuffer;
extern PACKAGE TglShadeModel glShadeModel;
extern PACKAGE TglStencilFunc glStencilFunc;
extern PACKAGE TglStencilMask glStencilMask;
extern PACKAGE TglStencilOp glStencilOp;
extern PACKAGE TglTexCoord1d glTexCoord1d;
extern PACKAGE TglTexCoord1dv glTexCoord1dv;
extern PACKAGE TglTexCoord1f glTexCoord1f;
extern PACKAGE TglTexCoord1fv glTexCoord1fv;
extern PACKAGE TglTexCoord1i glTexCoord1i;
extern PACKAGE TglTexCoord1iv glTexCoord1iv;
extern PACKAGE TglTexCoord1s glTexCoord1s;
extern PACKAGE TglTexCoord1sv glTexCoord1sv;
extern PACKAGE TglTexCoord2d glTexCoord2d;
extern PACKAGE TglTexCoord2dv glTexCoord2dv;
extern PACKAGE TglTexCoord2f glTexCoord2f;
extern PACKAGE TglTexCoord2fv glTexCoord2fv;
extern PACKAGE TglTexCoord2i glTexCoord2i;
extern PACKAGE TglTexCoord2iv glTexCoord2iv;
extern PACKAGE TglTexCoord2s glTexCoord2s;
extern PACKAGE TglTexCoord2sv glTexCoord2sv;
extern PACKAGE TglTexCoord3d glTexCoord3d;
extern PACKAGE TglTexCoord3dv glTexCoord3dv;
extern PACKAGE TglTexCoord3f glTexCoord3f;
extern PACKAGE TglTexCoord3fv glTexCoord3fv;
extern PACKAGE TglTexCoord3i glTexCoord3i;
extern PACKAGE TglTexCoord3iv glTexCoord3iv;
extern PACKAGE TglTexCoord3s glTexCoord3s;
extern PACKAGE TglTexCoord3sv glTexCoord3sv;
extern PACKAGE TglTexCoord4d glTexCoord4d;
extern PACKAGE TglTexCoord4dv glTexCoord4dv;
extern PACKAGE TglTexCoord4f glTexCoord4f;
extern PACKAGE TglTexCoord4fv glTexCoord4fv;
extern PACKAGE TglTexCoord4i glTexCoord4i;
extern PACKAGE TglTexCoord4iv glTexCoord4iv;
extern PACKAGE TglTexCoord4s glTexCoord4s;
extern PACKAGE TglTexCoord4sv glTexCoord4sv;
extern PACKAGE TglTexEnvf glTexEnvf;
extern PACKAGE TglTexEnvfv glTexEnvfv;
extern PACKAGE TglTexEnvi glTexEnvi;
extern PACKAGE TglTexEnviv glTexEnviv;
extern PACKAGE TglTexGend glTexGend;
extern PACKAGE TglTexGendv glTexGendv;
extern PACKAGE TglTexGenf glTexGenf;
extern PACKAGE TglTexGenfv glTexGenfv;
extern PACKAGE TglTexGeni glTexGeni;
extern PACKAGE TglTexGeniv glTexGeniv;
extern PACKAGE TglTexImage1D glTexImage1D;
extern PACKAGE TglTexParameterf glTexParameterf;
extern PACKAGE TglTexParameterfv glTexParameterfv;
extern PACKAGE TglTexParameteri glTexParameteri;
extern PACKAGE TglTexParameteriv glTexParameteriv;
extern PACKAGE TglTexSubImage1D glTexSubImage1D;
extern PACKAGE TglTexSubImage2D glTexSubImage2D;
extern PACKAGE TglTranslated glTranslated;
extern PACKAGE TglTranslatef glTranslatef;
extern PACKAGE TglVertex2d glVertex2d;
extern PACKAGE TglVertex2dv glVertex2dv;
extern PACKAGE TglVertex2f glVertex2f;
extern PACKAGE TglVertex2fv glVertex2fv;
extern PACKAGE TglVertex2i glVertex2i;
extern PACKAGE TglVertex2iv glVertex2iv;
extern PACKAGE TglVertex2s glVertex2s;
extern PACKAGE TglVertex2sv glVertex2sv;
extern PACKAGE TglVertex3d glVertex3d;
extern PACKAGE TglVertex3dv glVertex3dv;
extern PACKAGE TglVertex3f glVertex3f;
extern PACKAGE TglVertex3fv glVertex3fv;
extern PACKAGE TglVertex3i glVertex3i;
extern PACKAGE TglVertex3iv glVertex3iv;
extern PACKAGE TglVertex3s glVertex3s;
extern PACKAGE TglVertex3sv glVertex3sv;
extern PACKAGE TglVertex4d glVertex4d;
extern PACKAGE TglVertex4dv glVertex4dv;
extern PACKAGE TglVertex4f glVertex4f;
extern PACKAGE TglVertex4fv glVertex4fv;
extern PACKAGE TglVertex4i glVertex4i;
extern PACKAGE TglVertex4iv glVertex4iv;
extern PACKAGE TglVertex4s glVertex4s;
extern PACKAGE TglVertex4sv glVertex4sv;
extern PACKAGE TglViewport glViewport;
extern PACKAGE TglBlendColor glBlendColor;
extern PACKAGE TglBlendEquation glBlendEquation;
extern PACKAGE TglDrawRangeElements glDrawRangeElements;
extern PACKAGE TglColorTable glColorTable;
extern PACKAGE TglColorTableParameterfv glColorTableParameterfv;
extern PACKAGE TglColorTableParameteriv glColorTableParameteriv;
extern PACKAGE TglCopyColorTable glCopyColorTable;
extern PACKAGE TglGetColorTable glGetColorTable;
extern PACKAGE TglGetColorTableParameterfv glGetColorTableParameterfv;
extern PACKAGE TglGetColorTableParameteriv glGetColorTableParameteriv;
extern PACKAGE TglColorSubTable glColorSubTable;
extern PACKAGE TglCopyColorSubTable glCopyColorSubTable;
extern PACKAGE TglConvolutionFilter1D glConvolutionFilter1D;
extern PACKAGE TglConvolutionFilter2D glConvolutionFilter2D;
extern PACKAGE TglConvolutionParameterf glConvolutionParameterf;
extern PACKAGE TglConvolutionParameterfv glConvolutionParameterfv;
extern PACKAGE TglConvolutionParameteri glConvolutionParameteri;
extern PACKAGE TglConvolutionParameteriv glConvolutionParameteriv;
extern PACKAGE TglCopyConvolutionFilter1D glCopyConvolutionFilter1D;
extern PACKAGE TglCopyConvolutionFilter2D glCopyConvolutionFilter2D;
extern PACKAGE TglGetConvolutionFilter glGetConvolutionFilter;
extern PACKAGE TglGetConvolutionParameterfv glGetConvolutionParameterfv;
extern PACKAGE TglGetConvolutionParameteriv glGetConvolutionParameteriv;
extern PACKAGE TglGetSeparableFilter glGetSeparableFilter;
extern PACKAGE TglSeparableFilter2D glSeparableFilter2D;
extern PACKAGE TglGetHistogram glGetHistogram;
extern PACKAGE TglGetHistogramParameterfv glGetHistogramParameterfv;
extern PACKAGE TglGetHistogramParameteriv glGetHistogramParameteriv;
extern PACKAGE TglGetMinmax glGetMinmax;
extern PACKAGE TglGetMinmaxParameterfv glGetMinmaxParameterfv;
extern PACKAGE TglGetMinmaxParameteriv glGetMinmaxParameteriv;
extern PACKAGE TglHistogram glHistogram;
extern PACKAGE TglMinmax glMinmax;
extern PACKAGE TglResetHistogram glResetHistogram;
extern PACKAGE TglResetMinmax glResetMinmax;
extern PACKAGE TglTexImage3D glTexImage3D;
extern PACKAGE TglTexSubImage3D glTexSubImage3D;
extern PACKAGE TglCopyTexSubImage3D glCopyTexSubImage3D;
extern PACKAGE TglActiveTexture glActiveTexture;
extern PACKAGE TglClientActiveTexture glClientActiveTexture;
extern PACKAGE TglMultiTexCoord1d glMultiTexCoord1d;
extern PACKAGE TglMultiTexCoord1dv glMultiTexCoord1dv;
extern PACKAGE TglMultiTexCoord1f glMultiTexCoord1f;
extern PACKAGE TglMultiTexCoord1fv glMultiTexCoord1fv;
extern PACKAGE TglMultiTexCoord1i glMultiTexCoord1i;
extern PACKAGE TglMultiTexCoord1iv glMultiTexCoord1iv;
extern PACKAGE TglMultiTexCoord1s glMultiTexCoord1s;
extern PACKAGE TglMultiTexCoord1sv glMultiTexCoord1sv;
extern PACKAGE TglMultiTexCoord2d glMultiTexCoord2d;
extern PACKAGE TglMultiTexCoord2dv glMultiTexCoord2dv;
extern PACKAGE TglMultiTexCoord2f glMultiTexCoord2f;
extern PACKAGE TglMultiTexCoord2fv glMultiTexCoord2fv;
extern PACKAGE TglMultiTexCoord2i glMultiTexCoord2i;
extern PACKAGE TglMultiTexCoord2iv glMultiTexCoord2iv;
extern PACKAGE TglMultiTexCoord2s glMultiTexCoord2s;
extern PACKAGE TglMultiTexCoord2sv glMultiTexCoord2sv;
extern PACKAGE TglMultiTexCoord3d glMultiTexCoord3d;
extern PACKAGE TglMultiTexCoord3dv glMultiTexCoord3dv;
extern PACKAGE TglMultiTexCoord3f glMultiTexCoord3f;
extern PACKAGE TglMultiTexCoord3fv glMultiTexCoord3fv;
extern PACKAGE TglMultiTexCoord3i glMultiTexCoord3i;
extern PACKAGE TglMultiTexCoord3iv glMultiTexCoord3iv;
extern PACKAGE TglMultiTexCoord3s glMultiTexCoord3s;
extern PACKAGE TglMultiTexCoord3sv glMultiTexCoord3sv;
extern PACKAGE TglMultiTexCoord4d glMultiTexCoord4d;
extern PACKAGE TglMultiTexCoord4dv glMultiTexCoord4dv;
extern PACKAGE TglMultiTexCoord4f glMultiTexCoord4f;
extern PACKAGE TglMultiTexCoord4fv glMultiTexCoord4fv;
extern PACKAGE TglMultiTexCoord4i glMultiTexCoord4i;
extern PACKAGE TglMultiTexCoord4iv glMultiTexCoord4iv;
extern PACKAGE TglMultiTexCoord4s glMultiTexCoord4s;
extern PACKAGE TglMultiTexCoord4sv glMultiTexCoord4sv;
extern PACKAGE TglLoadTransposeMatrixf glLoadTransposeMatrixf;
extern PACKAGE TglLoadTransposeMatrixd glLoadTransposeMatrixd;
extern PACKAGE TglMultTransposeMatrixf glMultTransposeMatrixf;
extern PACKAGE TglMultTransposeMatrixd glMultTransposeMatrixd;
extern PACKAGE TglSampleCoverage glSampleCoverage;
extern PACKAGE TglCompressedTexImage3D glCompressedTexImage3D;
extern PACKAGE TglCompressedTexImage2D glCompressedTexImage2D;
extern PACKAGE TglCompressedTexImage1D glCompressedTexImage1D;
extern PACKAGE TglCompressedTexSubImage3D glCompressedTexSubImage3D;
extern PACKAGE TglCompressedTexSubImage2D glCompressedTexSubImage2D;
extern PACKAGE TglCompressedTexSubImage1D glCompressedTexSubImage1D;
extern PACKAGE TglGetCompressedTexImage glGetCompressedTexImage;
extern PACKAGE TglBlendFuncSeparate glBlendFuncSeparate;
extern PACKAGE TglFogCoordf glFogCoordf;
extern PACKAGE TglFogCoordfv glFogCoordfv;
extern PACKAGE TglFogCoordd glFogCoordd;
extern PACKAGE TglFogCoorddv glFogCoorddv;
extern PACKAGE TglFogCoordPointer glFogCoordPointer;
extern PACKAGE TglMultiDrawArrays glMultiDrawArrays;
extern PACKAGE TglMultiDrawElements glMultiDrawElements;
extern PACKAGE TglPointParameterf glPointParameterf;
extern PACKAGE TglPointParameterfv glPointParameterfv;
extern PACKAGE TglPointParameteri glPointParameteri;
extern PACKAGE TglPointParameteriv glPointParameteriv;
extern PACKAGE TglSecondaryColor3b glSecondaryColor3b;
extern PACKAGE TglSecondaryColor3bv glSecondaryColor3bv;
extern PACKAGE TglSecondaryColor3d glSecondaryColor3d;
extern PACKAGE TglSecondaryColor3dv glSecondaryColor3dv;
extern PACKAGE TglSecondaryColor3f glSecondaryColor3f;
extern PACKAGE TglSecondaryColor3fv glSecondaryColor3fv;
extern PACKAGE TglSecondaryColor3i glSecondaryColor3i;
extern PACKAGE TglSecondaryColor3iv glSecondaryColor3iv;
extern PACKAGE TglSecondaryColor3s glSecondaryColor3s;
extern PACKAGE TglSecondaryColor3sv glSecondaryColor3sv;
extern PACKAGE TglSecondaryColor3ub glSecondaryColor3ub;
extern PACKAGE TglSecondaryColor3ubv glSecondaryColor3ubv;
extern PACKAGE TglSecondaryColor3ui glSecondaryColor3ui;
extern PACKAGE TglSecondaryColor3uiv glSecondaryColor3uiv;
extern PACKAGE TglSecondaryColor3us glSecondaryColor3us;
extern PACKAGE TglSecondaryColor3usv glSecondaryColor3usv;
extern PACKAGE TglSecondaryColorPointer glSecondaryColorPointer;
extern PACKAGE TglWindowPos2d glWindowPos2d;
extern PACKAGE TglWindowPos2dv glWindowPos2dv;
extern PACKAGE TglWindowPos2f glWindowPos2f;
extern PACKAGE TglWindowPos2fv glWindowPos2fv;
extern PACKAGE TglWindowPos2i glWindowPos2i;
extern PACKAGE TglWindowPos2iv glWindowPos2iv;
extern PACKAGE TglWindowPos2s glWindowPos2s;
extern PACKAGE TglWindowPos2sv glWindowPos2sv;
extern PACKAGE TglWindowPos3d glWindowPos3d;
extern PACKAGE TglWindowPos3dv glWindowPos3dv;
extern PACKAGE TglWindowPos3f glWindowPos3f;
extern PACKAGE TglWindowPos3fv glWindowPos3fv;
extern PACKAGE TglWindowPos3i glWindowPos3i;
extern PACKAGE TglWindowPos3iv glWindowPos3iv;
extern PACKAGE TglWindowPos3s glWindowPos3s;
extern PACKAGE TglWindowPos3sv glWindowPos3sv;
extern PACKAGE TglGenQueries glGenQueries;
extern PACKAGE TglDeleteQueries glDeleteQueries;
extern PACKAGE TglIsQuery glIsQuery;
extern PACKAGE TglBeginQuery glBeginQuery;
extern PACKAGE TglEndQuery glEndQuery;
extern PACKAGE TglGetQueryiv glGetQueryiv;
extern PACKAGE TglGetQueryObjectiv glGetQueryObjectiv;
extern PACKAGE TglGetQueryObjectuiv glGetQueryObjectuiv;
extern PACKAGE TglBindBuffer glBindBuffer;
extern PACKAGE TglDeleteBuffers glDeleteBuffers;
extern PACKAGE TglGenBuffers glGenBuffers;
extern PACKAGE TglIsBuffer glIsBuffer;
extern PACKAGE TglGetBufferSubData glGetBufferSubData;
extern PACKAGE TglMapBuffer glMapBuffer;
extern PACKAGE TglUnmapBuffer glUnmapBuffer;
extern PACKAGE TglGetBufferParameteriv glGetBufferParameteriv;
extern PACKAGE TglGetBufferPointerv glGetBufferPointerv;
extern PACKAGE TglBlendEquationSeparate glBlendEquationSeparate;
extern PACKAGE TglDrawBuffers glDrawBuffers;
extern PACKAGE TglStencilOpSeparate glStencilOpSeparate;
extern PACKAGE TglStencilFuncSeparate glStencilFuncSeparate;
extern PACKAGE TglStencilMaskSeparate glStencilMaskSeparate;
extern PACKAGE TglAttachShader glAttachShader;
extern PACKAGE TglBindAttribLocation glBindAttribLocation;
extern PACKAGE TglCompileShader glCompileShader;
extern PACKAGE TglCreateProgram glCreateProgram;
extern PACKAGE TglCreateShader glCreateShader;
extern PACKAGE TglDeleteProgram glDeleteProgram;
extern PACKAGE TglDeleteShader glDeleteShader;
extern PACKAGE TglDetachShader glDetachShader;
extern PACKAGE TglDisableVertexAttribArray glDisableVertexAttribArray;
extern PACKAGE TglEnableVertexAttribArray glEnableVertexAttribArray;
extern PACKAGE TglGetActiveAttrib glGetActiveAttrib;
extern PACKAGE TglGetActiveUniform glGetActiveUniform;
extern PACKAGE TglGetAttachedShaders glGetAttachedShaders;
extern PACKAGE TglGetAttribLocation glGetAttribLocation;
extern PACKAGE TglGetProgramiv glGetProgramiv;
extern PACKAGE TglGetProgramInfoLog _glGetProgramInfoLog;
extern PACKAGE TglGetShaderiv glGetShaderiv;
extern PACKAGE TglGetShaderInfoLog _glGetShaderInfoLog;
extern PACKAGE TglGetShaderSource glGetShaderSource;
extern PACKAGE TglGetUniformLocation glGetUniformLocation;
extern PACKAGE TglGetUniformfv glGetUniformfv;
extern PACKAGE TglGetUniformiv glGetUniformiv;
extern PACKAGE TglGetVertexAttribfv glGetVertexAttribfv;
extern PACKAGE TglGetVertexAttribiv glGetVertexAttribiv;
extern PACKAGE TglGetVertexAttribPointerv glGetVertexAttribPointerv;
extern PACKAGE TglIsProgram glIsProgram;
extern PACKAGE TglIsShader glIsShader;
extern PACKAGE TglLinkProgram glLinkProgram;
extern PACKAGE TglShaderSource _glShaderSource;
extern PACKAGE TglUseProgram glUseProgram;
extern PACKAGE TglUniform1f glUniform1f;
extern PACKAGE TglUniform2f glUniform2f;
extern PACKAGE TglUniform3f glUniform3f;
extern PACKAGE TglUniform4f glUniform4f;
extern PACKAGE TglUniform1i glUniform1i;
extern PACKAGE TglUniform2i glUniform2i;
extern PACKAGE TglUniform3i glUniform3i;
extern PACKAGE TglUniform4i glUniform4i;
extern PACKAGE TglUniform1fv glUniform1fv;
extern PACKAGE TglUniform2fv glUniform2fv;
extern PACKAGE TglUniform3fv glUniform3fv;
extern PACKAGE TglUniform4fv glUniform4fv;
extern PACKAGE TglUniform1iv glUniform1iv;
extern PACKAGE TglUniform2iv glUniform2iv;
extern PACKAGE TglUniform3iv glUniform3iv;
extern PACKAGE TglUniform4iv glUniform4iv;
extern PACKAGE TglUniformMatrix2fv glUniformMatrix2fv;
extern PACKAGE TglUniformMatrix3fv glUniformMatrix3fv;
extern PACKAGE TglUniformMatrix4fv glUniformMatrix4fv;
extern PACKAGE TglValidateProgram glValidateProgram;
extern PACKAGE TglVertexAttrib1d glVertexAttrib1d;
extern PACKAGE TglVertexAttrib1dv glVertexAttrib1dv;
extern PACKAGE TglVertexAttrib1f glVertexAttrib1f;
extern PACKAGE TglVertexAttrib1fv glVertexAttrib1fv;
extern PACKAGE TglVertexAttrib1s glVertexAttrib1s;
extern PACKAGE TglVertexAttrib1sv glVertexAttrib1sv;
extern PACKAGE TglVertexAttrib2d glVertexAttrib2d;
extern PACKAGE TglVertexAttrib2dv glVertexAttrib2dv;
extern PACKAGE TglVertexAttrib2f glVertexAttrib2f;
extern PACKAGE TglVertexAttrib2fv glVertexAttrib2fv;
extern PACKAGE TglVertexAttrib2s glVertexAttrib2s;
extern PACKAGE TglVertexAttrib2sv glVertexAttrib2sv;
extern PACKAGE TglVertexAttrib3d glVertexAttrib3d;
extern PACKAGE TglVertexAttrib3dv glVertexAttrib3dv;
extern PACKAGE TglVertexAttrib3f glVertexAttrib3f;
extern PACKAGE TglVertexAttrib3fv glVertexAttrib3fv;
extern PACKAGE TglVertexAttrib3s glVertexAttrib3s;
extern PACKAGE TglVertexAttrib3sv glVertexAttrib3sv;
extern PACKAGE TglVertexAttrib4Nbv glVertexAttrib4Nbv;
extern PACKAGE TglVertexAttrib4Niv glVertexAttrib4Niv;
extern PACKAGE TglVertexAttrib4Nsv glVertexAttrib4Nsv;
extern PACKAGE TglVertexAttrib4Nub glVertexAttrib4Nub;
extern PACKAGE TglVertexAttrib4Nubv glVertexAttrib4Nubv;
extern PACKAGE TglVertexAttrib4Nuiv glVertexAttrib4Nuiv;
extern PACKAGE TglVertexAttrib4Nusv glVertexAttrib4Nusv;
extern PACKAGE TglVertexAttrib4bv glVertexAttrib4bv;
extern PACKAGE TglVertexAttrib4d glVertexAttrib4d;
extern PACKAGE TglVertexAttrib4dv glVertexAttrib4dv;
extern PACKAGE TglVertexAttrib4f glVertexAttrib4f;
extern PACKAGE TglVertexAttrib4fv glVertexAttrib4fv;
extern PACKAGE TglVertexAttrib4iv glVertexAttrib4iv;
extern PACKAGE TglVertexAttrib4s glVertexAttrib4s;
extern PACKAGE TglVertexAttrib4sv glVertexAttrib4sv;
extern PACKAGE TglVertexAttrib4ubv glVertexAttrib4ubv;
extern PACKAGE TglVertexAttrib4uiv glVertexAttrib4uiv;
extern PACKAGE TglVertexAttrib4usv glVertexAttrib4usv;
extern PACKAGE TglVertexAttribPointer glVertexAttribPointer;
extern PACKAGE TglTbufferMask3DFX glTbufferMask3DFX;
extern PACKAGE TglElementPointerAPPLE glElementPointerAPPLE;
extern PACKAGE TglDrawElementArrayAPPLE glDrawElementArrayAPPLE;
extern PACKAGE TglDrawRangeElementArrayAPPLE glDrawRangeElementArrayAPPLE;
extern PACKAGE TglMultiDrawElementArrayAPPLE glMultiDrawElementArrayAPPLE;
extern PACKAGE TglMultiDrawRangeElementArrayAPPLE glMultiDrawRangeElementArrayAPPLE;
extern PACKAGE TglGenFencesAPPLE glGenFencesAPPLE;
extern PACKAGE TglDeleteFencesAPPLE glDeleteFencesAPPLE;
extern PACKAGE TglSetFenceAPPLE glSetFenceAPPLE;
extern PACKAGE TglIsFenceAPPLE glIsFenceAPPLE;
extern PACKAGE TglTestFenceAPPLE glTestFenceAPPLE;
extern PACKAGE TglFinishFenceAPPLE glFinishFenceAPPLE;
extern PACKAGE TglTestObjectAPPLE glTestObjectAPPLE;
extern PACKAGE TglFinishObjectAPPLE glFinishObjectAPPLE;
extern PACKAGE TglBindVertexArrayAPPLE glBindVertexArrayAPPLE;
extern PACKAGE TglDeleteVertexArraysAPPLE glDeleteVertexArraysAPPLE;
extern PACKAGE TglGenVertexArraysAPPLE glGenVertexArraysAPPLE;
extern PACKAGE TglIsVertexArrayAPPLE glIsVertexArrayAPPLE;
extern PACKAGE TglVertexArrayRangeAPPLE glVertexArrayRangeAPPLE;
extern PACKAGE TglFlushVertexArrayRangeAPPLE glFlushVertexArrayRangeAPPLE;
extern PACKAGE TglVertexArrayParameteriAPPLE glVertexArrayParameteriAPPLE;
extern PACKAGE TglCurrentPaletteMatrixARB glCurrentPaletteMatrixARB;
extern PACKAGE TglMatrixIndexubvARB glMatrixIndexubvARB;
extern PACKAGE TglMatrixIndexusvARB glMatrixIndexusvARB;
extern PACKAGE TglMatrixIndexuivARB glMatrixIndexuivARB;
extern PACKAGE TglMatrixIndexPointerARB glMatrixIndexPointerARB;
extern PACKAGE TglSampleCoverageARB glSampleCoverageARB;
extern PACKAGE TglActiveTextureARB glActiveTextureARB;
extern PACKAGE TglClientActiveTextureARB glClientActiveTextureARB;
extern PACKAGE TglMultiTexCoord1dARB glMultiTexCoord1dARB;
extern PACKAGE TglMultiTexCoord1dvARB glMultiTexCoord1dvARB;
extern PACKAGE TglMultiTexCoord1fARB glMultiTexCoord1fARB;
extern PACKAGE TglMultiTexCoord1fvARB glMultiTexCoord1fvARB;
extern PACKAGE TglMultiTexCoord1iARB glMultiTexCoord1iARB;
extern PACKAGE TglMultiTexCoord1ivARB glMultiTexCoord1ivARB;
extern PACKAGE TglMultiTexCoord1sARB glMultiTexCoord1sARB;
extern PACKAGE TglMultiTexCoord1svARB glMultiTexCoord1svARB;
extern PACKAGE TglMultiTexCoord2dARB glMultiTexCoord2dARB;
extern PACKAGE TglMultiTexCoord2dvARB glMultiTexCoord2dvARB;
extern PACKAGE TglMultiTexCoord2fARB glMultiTexCoord2fARB;
extern PACKAGE TglMultiTexCoord2fvARB glMultiTexCoord2fvARB;
extern PACKAGE TglMultiTexCoord2iARB glMultiTexCoord2iARB;
extern PACKAGE TglMultiTexCoord2ivARB glMultiTexCoord2ivARB;
extern PACKAGE TglMultiTexCoord2sARB glMultiTexCoord2sARB;
extern PACKAGE TglMultiTexCoord2svARB glMultiTexCoord2svARB;
extern PACKAGE TglMultiTexCoord3dARB glMultiTexCoord3dARB;
extern PACKAGE TglMultiTexCoord3dvARB glMultiTexCoord3dvARB;
extern PACKAGE TglMultiTexCoord3fARB glMultiTexCoord3fARB;
extern PACKAGE TglMultiTexCoord3fvARB glMultiTexCoord3fvARB;
extern PACKAGE TglMultiTexCoord3iARB glMultiTexCoord3iARB;
extern PACKAGE TglMultiTexCoord3ivARB glMultiTexCoord3ivARB;
extern PACKAGE TglMultiTexCoord3sARB glMultiTexCoord3sARB;
extern PACKAGE TglMultiTexCoord3svARB glMultiTexCoord3svARB;
extern PACKAGE TglMultiTexCoord4dARB glMultiTexCoord4dARB;
extern PACKAGE TglMultiTexCoord4dvARB glMultiTexCoord4dvARB;
extern PACKAGE TglMultiTexCoord4fARB glMultiTexCoord4fARB;
extern PACKAGE TglMultiTexCoord4fvARB glMultiTexCoord4fvARB;
extern PACKAGE TglMultiTexCoord4iARB glMultiTexCoord4iARB;
extern PACKAGE TglMultiTexCoord4ivARB glMultiTexCoord4ivARB;
extern PACKAGE TglMultiTexCoord4sARB glMultiTexCoord4sARB;
extern PACKAGE TglMultiTexCoord4svARB glMultiTexCoord4svARB;
extern PACKAGE TglPointParameterfARB glPointParameterfARB;
extern PACKAGE TglPointParameterfvARB glPointParameterfvARB;
extern PACKAGE TglCompressedTexImage3DARB glCompressedTexImage3DARB;
extern PACKAGE TglCompressedTexImage2DARB glCompressedTexImage2DARB;
extern PACKAGE TglCompressedTexImage1DARB glCompressedTexImage1DARB;
extern PACKAGE TglCompressedTexSubImage3DARB glCompressedTexSubImage3DARB;
extern PACKAGE TglCompressedTexSubImage2DARB glCompressedTexSubImage2DARB;
extern PACKAGE TglCompressedTexSubImage1DARB glCompressedTexSubImage1DARB;
extern PACKAGE TglGetCompressedTexImageARB glGetCompressedTexImageARB;
extern PACKAGE TglLoadTransposeMatrixfARB glLoadTransposeMatrixfARB;
extern PACKAGE TglLoadTransposeMatrixdARB glLoadTransposeMatrixdARB;
extern PACKAGE TglMultTransposeMatrixfARB glMultTransposeMatrixfARB;
extern PACKAGE TglMultTransposeMatrixdARB glMultTransposeMatrixdARB;
extern PACKAGE TglWeightbvARB glWeightbvARB;
extern PACKAGE TglWeightsvARB glWeightsvARB;
extern PACKAGE TglWeightivARB glWeightivARB;
extern PACKAGE TglWeightfvARB glWeightfvARB;
extern PACKAGE TglWeightdvARB glWeightdvARB;
extern PACKAGE TglWeightubvARB glWeightubvARB;
extern PACKAGE TglWeightusvARB glWeightusvARB;
extern PACKAGE TglWeightuivARB glWeightuivARB;
extern PACKAGE TglWeightPointerARB glWeightPointerARB;
extern PACKAGE TglVertexBlendARB glVertexBlendARB;
extern PACKAGE TglBindBufferARB glBindBufferARB;
extern PACKAGE TglDeleteBuffersARB glDeleteBuffersARB;
extern PACKAGE TglGenBuffersARB glGenBuffersARB;
extern PACKAGE TglIsBufferARB glIsBufferARB;
extern PACKAGE TglGetBufferSubDataARB glGetBufferSubDataARB;
extern PACKAGE TglMapBufferARB glMapBufferARB;
extern PACKAGE TglUnmapBufferARB glUnmapBufferARB;
extern PACKAGE TglGetBufferParameterivARB glGetBufferParameterivARB;
extern PACKAGE TglGetBufferPointervARB glGetBufferPointervARB;
extern PACKAGE TglVertexAttrib1dARB glVertexAttrib1dARB;
extern PACKAGE TglVertexAttrib1dvARB glVertexAttrib1dvARB;
extern PACKAGE TglVertexAttrib1fARB glVertexAttrib1fARB;
extern PACKAGE TglVertexAttrib1fvARB glVertexAttrib1fvARB;
extern PACKAGE TglVertexAttrib1sARB glVertexAttrib1sARB;
extern PACKAGE TglVertexAttrib1svARB glVertexAttrib1svARB;
extern PACKAGE TglVertexAttrib2dARB glVertexAttrib2dARB;
extern PACKAGE TglVertexAttrib2dvARB glVertexAttrib2dvARB;
extern PACKAGE TglVertexAttrib2fARB glVertexAttrib2fARB;
extern PACKAGE TglVertexAttrib2fvARB glVertexAttrib2fvARB;
extern PACKAGE TglVertexAttrib2sARB glVertexAttrib2sARB;
extern PACKAGE TglVertexAttrib2svARB glVertexAttrib2svARB;
extern PACKAGE TglVertexAttrib3dARB glVertexAttrib3dARB;
extern PACKAGE TglVertexAttrib3dvARB glVertexAttrib3dvARB;
extern PACKAGE TglVertexAttrib3fARB glVertexAttrib3fARB;
extern PACKAGE TglVertexAttrib3fvARB glVertexAttrib3fvARB;
extern PACKAGE TglVertexAttrib3sARB glVertexAttrib3sARB;
extern PACKAGE TglVertexAttrib3svARB glVertexAttrib3svARB;
extern PACKAGE TglVertexAttrib4NbvARB glVertexAttrib4NbvARB;
extern PACKAGE TglVertexAttrib4NivARB glVertexAttrib4NivARB;
extern PACKAGE TglVertexAttrib4NsvARB glVertexAttrib4NsvARB;
extern PACKAGE TglVertexAttrib4NubARB glVertexAttrib4NubARB;
extern PACKAGE TglVertexAttrib4NubvARB glVertexAttrib4NubvARB;
extern PACKAGE TglVertexAttrib4NuivARB glVertexAttrib4NuivARB;
extern PACKAGE TglVertexAttrib4NusvARB glVertexAttrib4NusvARB;
extern PACKAGE TglVertexAttrib4bvARB glVertexAttrib4bvARB;
extern PACKAGE TglVertexAttrib4dARB glVertexAttrib4dARB;
extern PACKAGE TglVertexAttrib4dvARB glVertexAttrib4dvARB;
extern PACKAGE TglVertexAttrib4fARB glVertexAttrib4fARB;
extern PACKAGE TglVertexAttrib4fvARB glVertexAttrib4fvARB;
extern PACKAGE TglVertexAttrib4ivARB glVertexAttrib4ivARB;
extern PACKAGE TglVertexAttrib4sARB glVertexAttrib4sARB;
extern PACKAGE TglVertexAttrib4svARB glVertexAttrib4svARB;
extern PACKAGE TglVertexAttrib4ubvARB glVertexAttrib4ubvARB;
extern PACKAGE TglVertexAttrib4uivARB glVertexAttrib4uivARB;
extern PACKAGE TglVertexAttrib4usvARB glVertexAttrib4usvARB;
extern PACKAGE TglEnableVertexAttribArrayARB glEnableVertexAttribArrayARB;
extern PACKAGE TglDisableVertexAttribArrayARB glDisableVertexAttribArrayARB;
extern PACKAGE TglProgramStringARB glProgramStringARB;
extern PACKAGE TglBindProgramARB glBindProgramARB;
extern PACKAGE TglDeleteProgramsARB glDeleteProgramsARB;
extern PACKAGE TglGenProgramsARB glGenProgramsARB;
extern PACKAGE TglProgramEnvParameter4dARB glProgramEnvParameter4dARB;
extern PACKAGE TglProgramEnvParameter4dvARB glProgramEnvParameter4dvARB;
extern PACKAGE TglProgramEnvParameter4fARB glProgramEnvParameter4fARB;
extern PACKAGE TglProgramEnvParameter4fvARB glProgramEnvParameter4fvARB;
extern PACKAGE TglProgramLocalParameter4dARB glProgramLocalParameter4dARB;
extern PACKAGE TglProgramLocalParameter4dvARB glProgramLocalParameter4dvARB;
extern PACKAGE TglProgramLocalParameter4fARB glProgramLocalParameter4fARB;
extern PACKAGE TglProgramLocalParameter4fvARB glProgramLocalParameter4fvARB;
extern PACKAGE TglGetProgramEnvParameterdvARB glGetProgramEnvParameterdvARB;
extern PACKAGE TglGetProgramEnvParameterfvARB glGetProgramEnvParameterfvARB;
extern PACKAGE TglGetProgramLocalParameterdvARB glGetProgramLocalParameterdvARB;
extern PACKAGE TglGetProgramLocalParameterfvARB glGetProgramLocalParameterfvARB;
extern PACKAGE TglGetProgramivARB glGetProgramivARB;
extern PACKAGE TglGetProgramStringARB glGetProgramStringARB;
extern PACKAGE TglGetVertexAttribdvARB glGetVertexAttribdvARB;
extern PACKAGE TglGetVertexAttribfvARB glGetVertexAttribfvARB;
extern PACKAGE TglGetVertexAttribivARB glGetVertexAttribivARB;
extern PACKAGE TglGetVertexAttribPointervARB glGetVertexAttribPointervARB;
extern PACKAGE TglIsProgramARB glIsProgramARB;
extern PACKAGE TglWindowPos2dARB glWindowPos2dARB;
extern PACKAGE TglWindowPos2dvARB glWindowPos2dvARB;
extern PACKAGE TglWindowPos2fARB glWindowPos2fARB;
extern PACKAGE TglWindowPos2fvARB glWindowPos2fvARB;
extern PACKAGE TglWindowPos2iARB glWindowPos2iARB;
extern PACKAGE TglWindowPos2ivARB glWindowPos2ivARB;
extern PACKAGE TglWindowPos2sARB glWindowPos2sARB;
extern PACKAGE TglWindowPos2svARB glWindowPos2svARB;
extern PACKAGE TglWindowPos3dARB glWindowPos3dARB;
extern PACKAGE TglWindowPos3dvARB glWindowPos3dvARB;
extern PACKAGE TglWindowPos3fARB glWindowPos3fARB;
extern PACKAGE TglWindowPos3fvARB glWindowPos3fvARB;
extern PACKAGE TglWindowPos3iARB glWindowPos3iARB;
extern PACKAGE TglWindowPos3ivARB glWindowPos3ivARB;
extern PACKAGE TglWindowPos3sARB glWindowPos3sARB;
extern PACKAGE TglWindowPos3svARB glWindowPos3svARB;
extern PACKAGE TglDrawBuffersARB glDrawBuffersARB;
extern PACKAGE TglClampColorARB glClampColorARB;
extern PACKAGE TglGetActiveAttribARB glGetActiveAttribARB;
extern PACKAGE TglGetAttribLocationARB glGetAttribLocationARB;
extern PACKAGE TglBindAttribLocationARB glBindAttribLocationARB;
extern PACKAGE TglDeleteObjectARB glDeleteObjectARB;
extern PACKAGE TglGetHandleARB glGetHandleARB;
extern PACKAGE TglDetachObjectARB glDetachObjectARB;
extern PACKAGE TglCompileShaderARB glCompileShaderARB;
extern PACKAGE TglCreateProgramObjectARB glCreateProgramObjectARB;
extern PACKAGE TglAttachObjectARB glAttachObjectARB;
extern PACKAGE TglLinkProgramARB glLinkProgramARB;
extern PACKAGE TglUseProgramObjectARB glUseProgramObjectARB;
extern PACKAGE TglValidateProgramARB glValidateProgramARB;
extern PACKAGE TglUniform1fARB glUniform1fARB;
extern PACKAGE TglUniform2fARB glUniform2fARB;
extern PACKAGE TglUniform3fARB glUniform3fARB;
extern PACKAGE TglUniform4fARB glUniform4fARB;
extern PACKAGE TglUniform1iARB glUniform1iARB;
extern PACKAGE TglUniform2iARB glUniform2iARB;
extern PACKAGE TglUniform3iARB glUniform3iARB;
extern PACKAGE TglUniform4iARB glUniform4iARB;
extern PACKAGE TglUniform1fvARB glUniform1fvARB;
extern PACKAGE TglUniform2fvARB glUniform2fvARB;
extern PACKAGE TglUniform3fvARB glUniform3fvARB;
extern PACKAGE TglUniform4fvARB glUniform4fvARB;
extern PACKAGE TglUniform1ivARB glUniform1ivARB;
extern PACKAGE TglUniform2ivARB glUniform2ivARB;
extern PACKAGE TglUniform3ivARB glUniform3ivARB;
extern PACKAGE TglUniform4ivARB glUniform4ivARB;
extern PACKAGE TglUniformMatrix2fvARB glUniformMatrix2fvARB;
extern PACKAGE TglUniformMatrix3fvARB glUniformMatrix3fvARB;
extern PACKAGE TglUniformMatrix4fvARB glUniformMatrix4fvARB;
extern PACKAGE TglGetObjectParameterfvARB glGetObjectParameterfvARB;
extern PACKAGE TglGetObjectParameterivARB glGetObjectParameterivARB;
extern PACKAGE TglGetAttachedObjectsARB glGetAttachedObjectsARB;
extern PACKAGE TglGetUniformLocationARB glGetUniformLocationARB;
extern PACKAGE TglGetActiveUniformARB glGetActiveUniformARB;
extern PACKAGE TglGetUniformfvARB glGetUniformfvARB;
extern PACKAGE TglGetUniformivARB glGetUniformivARB;
extern PACKAGE TglGetShaderSourceARB glGetShaderSourceARB;
extern PACKAGE TglGenQueriesARB glGenQueriesARB;
extern PACKAGE TglDeleteQueriesARB glDeleteQueriesARB;
extern PACKAGE TglIsQueryARB glIsQueryARB;
extern PACKAGE TglBeginQueryARB glBeginQueryARB;
extern PACKAGE TglEndQueryARB glEndQueryARB;
extern PACKAGE TglGetQueryivARB glGetQueryivARB;
extern PACKAGE TglGetQueryObjectivARB glGetQueryObjectivARB;
extern PACKAGE TglGetQueryObjectuivARB glGetQueryObjectuivARB;
extern PACKAGE TglDrawBuffersATI glDrawBuffersATI;
extern PACKAGE TglElementPointerATI glElementPointerATI;
extern PACKAGE TglDrawElementArrayATI glDrawElementArrayATI;
extern PACKAGE TglDrawRangeElementArrayATI glDrawRangeElementArrayATI;
extern PACKAGE TglTexBumpParameterivATI glTexBumpParameterivATI;
extern PACKAGE TglTexBumpParameterfvATI glTexBumpParameterfvATI;
extern PACKAGE TglGetTexBumpParameterivATI glGetTexBumpParameterivATI;
extern PACKAGE TglGetTexBumpParameterfvATI glGetTexBumpParameterfvATI;
extern PACKAGE TglGenFragmentShadersATI glGenFragmentShadersATI;
extern PACKAGE TglBindFragmentShaderATI glBindFragmentShaderATI;
extern PACKAGE TglDeleteFragmentShaderATI glDeleteFragmentShaderATI;
extern PACKAGE TglBeginFragmentShaderATI glBeginFragmentShaderATI;
extern PACKAGE TglEndFragmentShaderATI glEndFragmentShaderATI;
extern PACKAGE TglPassTexCoordATI glPassTexCoordATI;
extern PACKAGE TglSampleMapATI glSampleMapATI;
extern PACKAGE TglColorFragmentOp1ATI glColorFragmentOp1ATI;
extern PACKAGE TglColorFragmentOp2ATI glColorFragmentOp2ATI;
extern PACKAGE TglColorFragmentOp3ATI glColorFragmentOp3ATI;
extern PACKAGE TglAlphaFragmentOp1ATI glAlphaFragmentOp1ATI;
extern PACKAGE TglAlphaFragmentOp2ATI glAlphaFragmentOp2ATI;
extern PACKAGE TglAlphaFragmentOp3ATI glAlphaFragmentOp3ATI;
extern PACKAGE TglSetFragmentShaderConstantATI glSetFragmentShaderConstantATI;
extern PACKAGE TglMapObjectBufferATI glMapObjectBufferATI;
extern PACKAGE TglUnmapObjectBufferATI glUnmapObjectBufferATI;
extern PACKAGE TglPNTrianglesiATI glPNTrianglesiATI;
extern PACKAGE TglPNTrianglesfATI glPNTrianglesfATI;
extern PACKAGE TglStencilOpSeparateATI glStencilOpSeparateATI;
extern PACKAGE TglStencilFuncSeparateATI glStencilFuncSeparateATI;
extern PACKAGE TglNewObjectBufferATI glNewObjectBufferATI;
extern PACKAGE TglIsObjectBufferATI glIsObjectBufferATI;
extern PACKAGE TglUpdateObjectBufferATI glUpdateObjectBufferATI;
extern PACKAGE TglGetObjectBufferfvATI glGetObjectBufferfvATI;
extern PACKAGE TglGetObjectBufferivATI glGetObjectBufferivATI;
extern PACKAGE TglFreeObjectBufferATI glFreeObjectBufferATI;
extern PACKAGE TglArrayObjectATI glArrayObjectATI;
extern PACKAGE TglGetArrayObjectfvATI glGetArrayObjectfvATI;
extern PACKAGE TglGetArrayObjectivATI glGetArrayObjectivATI;
extern PACKAGE TglVariantArrayObjectATI glVariantArrayObjectATI;
extern PACKAGE TglGetVariantArrayObjectfvATI glGetVariantArrayObjectfvATI;
extern PACKAGE TglGetVariantArrayObjectivATI glGetVariantArrayObjectivATI;
extern PACKAGE TglVertexAttribArrayObjectATI glVertexAttribArrayObjectATI;
extern PACKAGE TglGetVertexAttribArrayObjectfvATI glGetVertexAttribArrayObjectfvATI;
extern PACKAGE TglGetVertexAttribArrayObjectivATI glGetVertexAttribArrayObjectivATI;
extern PACKAGE TglVertexStream1sATI glVertexStream1sATI;
extern PACKAGE TglVertexStream1svATI glVertexStream1svATI;
extern PACKAGE TglVertexStream1iATI glVertexStream1iATI;
extern PACKAGE TglVertexStream1ivATI glVertexStream1ivATI;
extern PACKAGE TglVertexStream1fATI glVertexStream1fATI;
extern PACKAGE TglVertexStream1fvATI glVertexStream1fvATI;
extern PACKAGE TglVertexStream1dATI glVertexStream1dATI;
extern PACKAGE TglVertexStream1dvATI glVertexStream1dvATI;
extern PACKAGE TglVertexStream2sATI glVertexStream2sATI;
extern PACKAGE TglVertexStream2svATI glVertexStream2svATI;
extern PACKAGE TglVertexStream2iATI glVertexStream2iATI;
extern PACKAGE TglVertexStream2ivATI glVertexStream2ivATI;
extern PACKAGE TglVertexStream2fATI glVertexStream2fATI;
extern PACKAGE TglVertexStream2fvATI glVertexStream2fvATI;
extern PACKAGE TglVertexStream2dATI glVertexStream2dATI;
extern PACKAGE TglVertexStream2dvATI glVertexStream2dvATI;
extern PACKAGE TglVertexStream3sATI glVertexStream3sATI;
extern PACKAGE TglVertexStream3svATI glVertexStream3svATI;
extern PACKAGE TglVertexStream3iATI glVertexStream3iATI;
extern PACKAGE TglVertexStream3ivATI glVertexStream3ivATI;
extern PACKAGE TglVertexStream3fATI glVertexStream3fATI;
extern PACKAGE TglVertexStream3fvATI glVertexStream3fvATI;
extern PACKAGE TglVertexStream3dATI glVertexStream3dATI;
extern PACKAGE TglVertexStream3dvATI glVertexStream3dvATI;
extern PACKAGE TglVertexStream4sATI glVertexStream4sATI;
extern PACKAGE TglVertexStream4svATI glVertexStream4svATI;
extern PACKAGE TglVertexStream4iATI glVertexStream4iATI;
extern PACKAGE TglVertexStream4ivATI glVertexStream4ivATI;
extern PACKAGE TglVertexStream4fATI glVertexStream4fATI;
extern PACKAGE TglVertexStream4fvATI glVertexStream4fvATI;
extern PACKAGE TglVertexStream4dATI glVertexStream4dATI;
extern PACKAGE TglVertexStream4dvATI glVertexStream4dvATI;
extern PACKAGE TglNormalStream3bATI glNormalStream3bATI;
extern PACKAGE TglNormalStream3bvATI glNormalStream3bvATI;
extern PACKAGE TglNormalStream3sATI glNormalStream3sATI;
extern PACKAGE TglNormalStream3svATI glNormalStream3svATI;
extern PACKAGE TglNormalStream3iATI glNormalStream3iATI;
extern PACKAGE TglNormalStream3ivATI glNormalStream3ivATI;
extern PACKAGE TglNormalStream3fATI glNormalStream3fATI;
extern PACKAGE TglNormalStream3fvATI glNormalStream3fvATI;
extern PACKAGE TglNormalStream3dATI glNormalStream3dATI;
extern PACKAGE TglNormalStream3dvATI glNormalStream3dvATI;
extern PACKAGE TglClientActiveVertexStreamATI glClientActiveVertexStreamATI;
extern PACKAGE TglVertexBlendEnviATI glVertexBlendEnviATI;
extern PACKAGE TglVertexBlendEnvfATI glVertexBlendEnvfATI;
extern PACKAGE TglBlendColorEXT glBlendColorEXT;
extern PACKAGE TglBlendFuncSeparateEXT glBlendFuncSeparateEXT;
extern PACKAGE TglBlendEquationEXT glBlendEquationEXT;
extern PACKAGE TglColorSubTableEXT glColorSubTableEXT;
extern PACKAGE TglCopyColorSubTableEXT glCopyColorSubTableEXT;
extern PACKAGE TglLockArraysEXT glLockArraysEXT;
extern PACKAGE TglUnlockArraysEXT glUnlockArraysEXT;
extern PACKAGE TglConvolutionFilter1DEXT glConvolutionFilter1DEXT;
extern PACKAGE TglConvolutionFilter2DEXT glConvolutionFilter2DEXT;
extern PACKAGE TglConvolutionParameterfEXT glConvolutionParameterfEXT;
extern PACKAGE TglConvolutionParameterfvEXT glConvolutionParameterfvEXT;
extern PACKAGE TglConvolutionParameteriEXT glConvolutionParameteriEXT;
extern PACKAGE TglConvolutionParameterivEXT glConvolutionParameterivEXT;
extern PACKAGE TglCopyConvolutionFilter1DEXT glCopyConvolutionFilter1DEXT;
extern PACKAGE TglCopyConvolutionFilter2DEXT glCopyConvolutionFilter2DEXT;
extern PACKAGE TglGetConvolutionFilterEXT glGetConvolutionFilterEXT;
extern PACKAGE TglGetConvolutionParameterfvEXT glGetConvolutionParameterfvEXT;
extern PACKAGE TglGetConvolutionParameterivEXT glGetConvolutionParameterivEXT;
extern PACKAGE TglGetSeparableFilterEXT glGetSeparableFilterEXT;
extern PACKAGE TglSeparableFilter2DEXT glSeparableFilter2DEXT;
extern PACKAGE TglTangent3bEXT glTangent3bEXT;
extern PACKAGE TglTangent3bvEXT glTangent3bvEXT;
extern PACKAGE TglTangent3dEXT glTangent3dEXT;
extern PACKAGE TglTangent3dvEXT glTangent3dvEXT;
extern PACKAGE TglTangent3fEXT glTangent3fEXT;
extern PACKAGE TglTangent3fvEXT glTangent3fvEXT;
extern PACKAGE TglTangent3iEXT glTangent3iEXT;
extern PACKAGE TglTangent3ivEXT glTangent3ivEXT;
extern PACKAGE TglTangent3sEXT glTangent3sEXT;
extern PACKAGE TglTangent3svEXT glTangent3svEXT;
extern PACKAGE TglBinormal3bEXT glBinormal3bEXT;
extern PACKAGE TglBinormal3bvEXT glBinormal3bvEXT;
extern PACKAGE TglBinormal3dEXT glBinormal3dEXT;
extern PACKAGE TglBinormal3dvEXT glBinormal3dvEXT;
extern PACKAGE TglBinormal3fEXT glBinormal3fEXT;
extern PACKAGE TglBinormal3fvEXT glBinormal3fvEXT;
extern PACKAGE TglBinormal3iEXT glBinormal3iEXT;
extern PACKAGE TglBinormal3ivEXT glBinormal3ivEXT;
extern PACKAGE TglBinormal3sEXT glBinormal3sEXT;
extern PACKAGE TglBinormal3svEXT glBinormal3svEXT;
extern PACKAGE TglTangentPointerEXT glTangentPointerEXT;
extern PACKAGE TglBinormalPointerEXT glBinormalPointerEXT;
extern PACKAGE TglCopyTexImage1DEXT glCopyTexImage1DEXT;
extern PACKAGE TglCopyTexImage2DEXT glCopyTexImage2DEXT;
extern PACKAGE TglCopyTexSubImage1DEXT glCopyTexSubImage1DEXT;
extern PACKAGE TglCopyTexSubImage2DEXT glCopyTexSubImage2DEXT;
extern PACKAGE TglCopyTexSubImage3DEXT glCopyTexSubImage3DEXT;
extern PACKAGE TglCullParameterdvEXT glCullParameterdvEXT;
extern PACKAGE TglCullParameterfvEXT glCullParameterfvEXT;
extern PACKAGE TglDrawRangeElementsEXT glDrawRangeElementsEXT;
extern PACKAGE TglFogCoordfEXT glFogCoordfEXT;
extern PACKAGE TglFogCoordfvEXT glFogCoordfvEXT;
extern PACKAGE TglFogCoorddEXT glFogCoorddEXT;
extern PACKAGE TglFogCoorddvEXT glFogCoorddvEXT;
extern PACKAGE TglFogCoordPointerEXT glFogCoordPointerEXT;
extern PACKAGE TglIsRenderbufferEXT glIsRenderbufferEXT;
extern PACKAGE TglBindRenderbufferEXT glBindRenderbufferEXT;
extern PACKAGE TglDeleteRenderbuffersEXT glDeleteRenderbuffersEXT;
extern PACKAGE TglGenRenderbuffersEXT glGenRenderbuffersEXT;
extern PACKAGE TglRenderbufferStorageEXT glRenderbufferStorageEXT;
extern PACKAGE TglGetRenderbufferParameterivEXT glGetRenderbufferParameterivEXT;
extern PACKAGE TglIsFramebufferEXT glIsFramebufferEXT;
extern PACKAGE TglBindFramebufferEXT glBindFramebufferEXT;
extern PACKAGE TglDeleteFramebuffersEXT glDeleteFramebuffersEXT;
extern PACKAGE TglGenFramebuffersEXT glGenFramebuffersEXT;
extern PACKAGE TglCheckFramebufferStatusEXT glCheckFramebufferStatusEXT;
extern PACKAGE TglFramebufferTexture1DEXT glFramebufferTexture1DEXT;
extern PACKAGE TglFramebufferTexture2DEXT glFramebufferTexture2DEXT;
extern PACKAGE TglFramebufferTexture3DEXT glFramebufferTexture3DEXT;
extern PACKAGE TglFramebufferRenderbufferEXT glFramebufferRenderbufferEXT;
extern PACKAGE TglGetFramebufferAttachmentParameterivEXT glGetFramebufferAttachmentParameterivEXT;
extern PACKAGE TglGenerateMipmapEXT glGenerateMipmapEXT;
extern PACKAGE TglGetHistogramEXT glGetHistogramEXT;
extern PACKAGE TglGetHistogramParameterfvEXT glGetHistogramParameterfvEXT;
extern PACKAGE TglGetHistogramParameterivEXT glGetHistogramParameterivEXT;
extern PACKAGE TglGetMinmaxEXT glGetMinmaxEXT;
extern PACKAGE TglGetMinmaxParameterfvEXT glGetMinmaxParameterfvEXT;
extern PACKAGE TglGetMinmaxParameterivEXT glGetMinmaxParameterivEXT;
extern PACKAGE TglHistogramEXT glHistogramEXT;
extern PACKAGE TglMinmaxEXT glMinmaxEXT;
extern PACKAGE TglResetHistogramEXT glResetHistogramEXT;
extern PACKAGE TglResetMinmaxEXT glResetMinmaxEXT;
extern PACKAGE TglIndexFuncEXT glIndexFuncEXT;
extern PACKAGE TglIndexMaterialEXT glIndexMaterialEXT;
extern PACKAGE TglApplyTextureEXT glApplyTextureEXT;
extern PACKAGE TglTextureLightEXT glTextureLightEXT;
extern PACKAGE TglTextureMaterialEXT glTextureMaterialEXT;
extern PACKAGE TglMultiDrawArraysEXT glMultiDrawArraysEXT;
extern PACKAGE TglMultiDrawElementsEXT glMultiDrawElementsEXT;
extern PACKAGE TglSampleMaskEXT glSampleMaskEXT;
extern PACKAGE TglSamplePatternEXT glSamplePatternEXT;
extern PACKAGE TglColorTableEXT glColorTableEXT;
extern PACKAGE TglGetColorTableEXT glGetColorTableEXT;
extern PACKAGE TglGetColorTableParameterivEXT glGetColorTableParameterivEXT;
extern PACKAGE TglGetColorTableParameterfvEXT glGetColorTableParameterfvEXT;
extern PACKAGE TglPixelTransformParameteriEXT glPixelTransformParameteriEXT;
extern PACKAGE TglPixelTransformParameterfEXT glPixelTransformParameterfEXT;
extern PACKAGE TglPixelTransformParameterivEXT glPixelTransformParameterivEXT;
extern PACKAGE TglPixelTransformParameterfvEXT glPixelTransformParameterfvEXT;
extern PACKAGE TglPointParameterfEXT glPointParameterfEXT;
extern PACKAGE TglPointParameterfvEXT glPointParameterfvEXT;
extern PACKAGE TglPolygonOffsetEXT glPolygonOffsetEXT;
extern PACKAGE TglSecondaryColor3bEXT glSecondaryColor3bEXT;
extern PACKAGE TglSecondaryColor3bvEXT glSecondaryColor3bvEXT;
extern PACKAGE TglSecondaryColor3dEXT glSecondaryColor3dEXT;
extern PACKAGE TglSecondaryColor3dvEXT glSecondaryColor3dvEXT;
extern PACKAGE TglSecondaryColor3fEXT glSecondaryColor3fEXT;
extern PACKAGE TglSecondaryColor3fvEXT glSecondaryColor3fvEXT;
extern PACKAGE TglSecondaryColor3iEXT glSecondaryColor3iEXT;
extern PACKAGE TglSecondaryColor3ivEXT glSecondaryColor3ivEXT;
extern PACKAGE TglSecondaryColor3sEXT glSecondaryColor3sEXT;
extern PACKAGE TglSecondaryColor3svEXT glSecondaryColor3svEXT;
extern PACKAGE TglSecondaryColor3ubEXT glSecondaryColor3ubEXT;
extern PACKAGE TglSecondaryColor3ubvEXT glSecondaryColor3ubvEXT;
extern PACKAGE TglSecondaryColor3uiEXT glSecondaryColor3uiEXT;
extern PACKAGE TglSecondaryColor3uivEXT glSecondaryColor3uivEXT;
extern PACKAGE TglSecondaryColor3usEXT glSecondaryColor3usEXT;
extern PACKAGE TglSecondaryColor3usvEXT glSecondaryColor3usvEXT;
extern PACKAGE TglSecondaryColorPointerEXT glSecondaryColorPointerEXT;
extern PACKAGE TglActiveStencilFaceEXT glActiveStencilFaceEXT;
extern PACKAGE TglTexSubImage1DEXT glTexSubImage1DEXT;
extern PACKAGE TglTexSubImage2DEXT glTexSubImage2DEXT;
extern PACKAGE TglTexImage3DEXT glTexImage3DEXT;
extern PACKAGE TglTexSubImage3DEXT glTexSubImage3DEXT;
extern PACKAGE TglAreTexturesResidentEXT glAreTexturesResidentEXT;
extern PACKAGE TglBindTextureEXT glBindTextureEXT;
extern PACKAGE TglDeleteTexturesEXT glDeleteTexturesEXT;
extern PACKAGE TglGenTexturesEXT glGenTexturesEXT;
extern PACKAGE TglIsTextureEXT glIsTextureEXT;
extern PACKAGE TglPrioritizeTexturesEXT glPrioritizeTexturesEXT;
extern PACKAGE TglTextureNormalEXT glTextureNormalEXT;
extern PACKAGE TglArrayElementEXT glArrayElementEXT;
extern PACKAGE TglColorPointerEXT glColorPointerEXT;
extern PACKAGE TglDrawArraysEXT glDrawArraysEXT;
extern PACKAGE TglEdgeFlagPointerEXT glEdgeFlagPointerEXT;
extern PACKAGE TglGetPointervEXT glGetPointervEXT;
extern PACKAGE TglIndexPointerEXT glIndexPointerEXT;
extern PACKAGE TglNormalPointerEXT glNormalPointerEXT;
extern PACKAGE TglTexCoordPointerEXT glTexCoordPointerEXT;
extern PACKAGE TglVertexPointerEXT glVertexPointerEXT;
extern PACKAGE TglBeginVertexShaderEXT glBeginVertexShaderEXT;
extern PACKAGE TglEndVertexShaderEXT glEndVertexShaderEXT;
extern PACKAGE TglBindVertexShaderEXT glBindVertexShaderEXT;
extern PACKAGE TglGenVertexShadersEXT glGenVertexShadersEXT;
extern PACKAGE TglDeleteVertexShaderEXT glDeleteVertexShaderEXT;
extern PACKAGE TglShaderOp1EXT glShaderOp1EXT;
extern PACKAGE TglShaderOp2EXT glShaderOp2EXT;
extern PACKAGE TglShaderOp3EXT glShaderOp3EXT;
extern PACKAGE TglSwizzleEXT glSwizzleEXT;
extern PACKAGE TglWriteMaskEXT glWriteMaskEXT;
extern PACKAGE TglInsertComponentEXT glInsertComponentEXT;
extern PACKAGE TglExtractComponentEXT glExtractComponentEXT;
extern PACKAGE TglGenSymbolsEXT glGenSymbolsEXT;
extern PACKAGE TglSetInvariantEXT glSetInvariantEXT;
extern PACKAGE TglSetLocalConstantEXT glSetLocalConstantEXT;
extern PACKAGE TglVariantbvEXT glVariantbvEXT;
extern PACKAGE TglVariantsvEXT glVariantsvEXT;
extern PACKAGE TglVariantivEXT glVariantivEXT;
extern PACKAGE TglVariantfvEXT glVariantfvEXT;
extern PACKAGE TglVariantdvEXT glVariantdvEXT;
extern PACKAGE TglVariantubvEXT glVariantubvEXT;
extern PACKAGE TglVariantusvEXT glVariantusvEXT;
extern PACKAGE TglVariantuivEXT glVariantuivEXT;
extern PACKAGE TglVariantPointerEXT glVariantPointerEXT;
extern PACKAGE TglEnableVariantClientStateEXT glEnableVariantClientStateEXT;
extern PACKAGE TglDisableVariantClientStateEXT glDisableVariantClientStateEXT;
extern PACKAGE TglBindLightParameterEXT glBindLightParameterEXT;
extern PACKAGE TglBindMaterialParameterEXT glBindMaterialParameterEXT;
extern PACKAGE TglBindTexGenParameterEXT glBindTexGenParameterEXT;
extern PACKAGE TglBindTextureUnitParameterEXT glBindTextureUnitParameterEXT;
extern PACKAGE TglBindParameterEXT glBindParameterEXT;
extern PACKAGE TglIsVariantEnabledEXT glIsVariantEnabledEXT;
extern PACKAGE TglGetVariantBooleanvEXT glGetVariantBooleanvEXT;
extern PACKAGE TglGetVariantIntegervEXT glGetVariantIntegervEXT;
extern PACKAGE TglGetVariantFloatvEXT glGetVariantFloatvEXT;
extern PACKAGE TglGetVariantPointervEXT glGetVariantPointervEXT;
extern PACKAGE TglGetInvariantBooleanvEXT glGetInvariantBooleanvEXT;
extern PACKAGE TglGetInvariantIntegervEXT glGetInvariantIntegervEXT;
extern PACKAGE TglGetInvariantFloatvEXT glGetInvariantFloatvEXT;
extern PACKAGE TglGetLocalConstantBooleanvEXT glGetLocalConstantBooleanvEXT;
extern PACKAGE TglGetLocalConstantIntegervEXT glGetLocalConstantIntegervEXT;
extern PACKAGE TglGetLocalConstantFloatvEXT glGetLocalConstantFloatvEXT;
extern PACKAGE TglVertexWeightfEXT glVertexWeightfEXT;
extern PACKAGE TglVertexWeightfvEXT glVertexWeightfvEXT;
extern PACKAGE TglVertexWeightPointerEXT glVertexWeightPointerEXT;
extern PACKAGE TglStencilClearTagEXT glStencilClearTagEXT;
extern PACKAGE TglImageTransformParameteriHP glImageTransformParameteriHP;
extern PACKAGE TglImageTransformParameterfHP glImageTransformParameterfHP;
extern PACKAGE TglImageTransformParameterivHP glImageTransformParameterivHP;
extern PACKAGE TglImageTransformParameterfvHP glImageTransformParameterfvHP;
extern PACKAGE TglGetImageTransformParameterivHP glGetImageTransformParameterivHP;
extern PACKAGE TglGetImageTransformParameterfvHP glGetImageTransformParameterfvHP;
extern PACKAGE TglDepthBoundsEXT glDepthBoundsEXT;
extern PACKAGE TglBlendEquationSeparateEXT glBlendEquationSeparateEXT;
extern PACKAGE TglMultiModeDrawArraysIBM glMultiModeDrawArraysIBM;
extern PACKAGE TglMultiModeDrawElementsIBM glMultiModeDrawElementsIBM;
extern PACKAGE TglColorPointerListIBM glColorPointerListIBM;
extern PACKAGE TglSecondaryColorPointerListIBM glSecondaryColorPointerListIBM;
extern PACKAGE TglEdgeFlagPointerListIBM glEdgeFlagPointerListIBM;
extern PACKAGE TglFogCoordPointerListIBM glFogCoordPointerListIBM;
extern PACKAGE TglIndexPointerListIBM glIndexPointerListIBM;
extern PACKAGE TglNormalPointerListIBM glNormalPointerListIBM;
extern PACKAGE TglTexCoordPointerListIBM glTexCoordPointerListIBM;
extern PACKAGE TglVertexPointerListIBM glVertexPointerListIBM;
extern PACKAGE TglBlendFuncSeparateINGR glBlendFuncSeparateINGR;
extern PACKAGE TglVertexPointervINTEL glVertexPointervINTEL;
extern PACKAGE TglNormalPointervINTEL glNormalPointervINTEL;
extern PACKAGE TglColorPointervINTEL glColorPointervINTEL;
extern PACKAGE TglTexCoordPointervINTEL glTexCoordPointervINTEL;
extern PACKAGE TglResizeBuffersMESA glResizeBuffersMESA;
extern PACKAGE TglWindowPos2dMESA glWindowPos2dMESA;
extern PACKAGE TglWindowPos2dvMESA glWindowPos2dvMESA;
extern PACKAGE TglWindowPos2fMESA glWindowPos2fMESA;
extern PACKAGE TglWindowPos2fvMESA glWindowPos2fvMESA;
extern PACKAGE TglWindowPos2iMESA glWindowPos2iMESA;
extern PACKAGE TglWindowPos2ivMESA glWindowPos2ivMESA;
extern PACKAGE TglWindowPos2sMESA glWindowPos2sMESA;
extern PACKAGE TglWindowPos2svMESA glWindowPos2svMESA;
extern PACKAGE TglWindowPos3dMESA glWindowPos3dMESA;
extern PACKAGE TglWindowPos3dvMESA glWindowPos3dvMESA;
extern PACKAGE TglWindowPos3fMESA glWindowPos3fMESA;
extern PACKAGE TglWindowPos3fvMESA glWindowPos3fvMESA;
extern PACKAGE TglWindowPos3iMESA glWindowPos3iMESA;
extern PACKAGE TglWindowPos3ivMESA glWindowPos3ivMESA;
extern PACKAGE TglWindowPos3sMESA glWindowPos3sMESA;
extern PACKAGE TglWindowPos3svMESA glWindowPos3svMESA;
extern PACKAGE TglWindowPos4dMESA glWindowPos4dMESA;
extern PACKAGE TglWindowPos4dvMESA glWindowPos4dvMESA;
extern PACKAGE TglWindowPos4fMESA glWindowPos4fMESA;
extern PACKAGE TglWindowPos4fvMESA glWindowPos4fvMESA;
extern PACKAGE TglWindowPos4iMESA glWindowPos4iMESA;
extern PACKAGE TglWindowPos4ivMESA glWindowPos4ivMESA;
extern PACKAGE TglWindowPos4sMESA glWindowPos4sMESA;
extern PACKAGE TglWindowPos4svMESA glWindowPos4svMESA;
extern PACKAGE TglMapControlPointsNV glMapControlPointsNV;
extern PACKAGE TglMapParameterivNV glMapParameterivNV;
extern PACKAGE TglMapParameterfvNV glMapParameterfvNV;
extern PACKAGE TglGetMapControlPointsNV glGetMapControlPointsNV;
extern PACKAGE TglGetMapParameterivNV glGetMapParameterivNV;
extern PACKAGE TglGetMapParameterfvNV glGetMapParameterfvNV;
extern PACKAGE TglGetMapAttribParameterivNV glGetMapAttribParameterivNV;
extern PACKAGE TglGetMapAttribParameterfvNV glGetMapAttribParameterfvNV;
extern PACKAGE TglEvalMapsNV glEvalMapsNV;
extern PACKAGE TglDeleteFencesNV glDeleteFencesNV;
extern PACKAGE TglGenFencesNV glGenFencesNV;
extern PACKAGE TglIsFenceNV glIsFenceNV;
extern PACKAGE TglTestFenceNV glTestFenceNV;
extern PACKAGE TglGetFenceivNV glGetFenceivNV;
extern PACKAGE TglFinishFenceNV glFinishFenceNV;
extern PACKAGE TglSetFenceNV glSetFenceNV;
extern PACKAGE TglProgramNamedParameter4fNV glProgramNamedParameter4fNV;
extern PACKAGE TglProgramNamedParameter4dNV glProgramNamedParameter4dNV;
extern PACKAGE TglProgramNamedParameter4fvNV glProgramNamedParameter4fvNV;
extern PACKAGE TglProgramNamedParameter4dvNV glProgramNamedParameter4dvNV;
extern PACKAGE TglGetProgramNamedParameterfvNV glGetProgramNamedParameterfvNV;
extern PACKAGE TglGetProgramNamedParameterdvNV glGetProgramNamedParameterdvNV;
extern PACKAGE TglVertex2hNV glVertex2hNV;
extern PACKAGE TglVertex2hvNV glVertex2hvNV;
extern PACKAGE TglVertex3hNV glVertex3hNV;
extern PACKAGE TglVertex3hvNV glVertex3hvNV;
extern PACKAGE TglVertex4hNV glVertex4hNV;
extern PACKAGE TglVertex4hvNV glVertex4hvNV;
extern PACKAGE TglNormal3hNV glNormal3hNV;
extern PACKAGE TglNormal3hvNV glNormal3hvNV;
extern PACKAGE TglColor3hNV glColor3hNV;
extern PACKAGE TglColor3hvNV glColor3hvNV;
extern PACKAGE TglColor4hNV glColor4hNV;
extern PACKAGE TglColor4hvNV glColor4hvNV;
extern PACKAGE TglTexCoord1hNV glTexCoord1hNV;
extern PACKAGE TglTexCoord1hvNV glTexCoord1hvNV;
extern PACKAGE TglTexCoord2hNV glTexCoord2hNV;
extern PACKAGE TglTexCoord2hvNV glTexCoord2hvNV;
extern PACKAGE TglTexCoord3hNV glTexCoord3hNV;
extern PACKAGE TglTexCoord3hvNV glTexCoord3hvNV;
extern PACKAGE TglTexCoord4hNV glTexCoord4hNV;
extern PACKAGE TglTexCoord4hvNV glTexCoord4hvNV;
extern PACKAGE TglMultiTexCoord1hNV glMultiTexCoord1hNV;
extern PACKAGE TglMultiTexCoord1hvNV glMultiTexCoord1hvNV;
extern PACKAGE TglMultiTexCoord2hNV glMultiTexCoord2hNV;
extern PACKAGE TglMultiTexCoord2hvNV glMultiTexCoord2hvNV;
extern PACKAGE TglMultiTexCoord3hNV glMultiTexCoord3hNV;
extern PACKAGE TglMultiTexCoord3hvNV glMultiTexCoord3hvNV;
extern PACKAGE TglMultiTexCoord4hNV glMultiTexCoord4hNV;
extern PACKAGE TglMultiTexCoord4hvNV glMultiTexCoord4hvNV;
extern PACKAGE TglFogCoordhNV glFogCoordhNV;
extern PACKAGE TglFogCoordhvNV glFogCoordhvNV;
extern PACKAGE TglSecondaryColor3hNV glSecondaryColor3hNV;
extern PACKAGE TglSecondaryColor3hvNV glSecondaryColor3hvNV;
extern PACKAGE TglVertexWeighthNV glVertexWeighthNV;
extern PACKAGE TglVertexWeighthvNV glVertexWeighthvNV;
extern PACKAGE TglVertexAttrib1hNV glVertexAttrib1hNV;
extern PACKAGE TglVertexAttrib1hvNV glVertexAttrib1hvNV;
extern PACKAGE TglVertexAttrib2hNV glVertexAttrib2hNV;
extern PACKAGE TglVertexAttrib2hvNV glVertexAttrib2hvNV;
extern PACKAGE TglVertexAttrib3hNV glVertexAttrib3hNV;
extern PACKAGE TglVertexAttrib3hvNV glVertexAttrib3hvNV;
extern PACKAGE TglVertexAttrib4hNV glVertexAttrib4hNV;
extern PACKAGE TglVertexAttrib4hvNV glVertexAttrib4hvNV;
extern PACKAGE TglVertexAttribs1hvNV glVertexAttribs1hvNV;
extern PACKAGE TglVertexAttribs2hvNV glVertexAttribs2hvNV;
extern PACKAGE TglVertexAttribs3hvNV glVertexAttribs3hvNV;
extern PACKAGE TglVertexAttribs4hvNV glVertexAttribs4hvNV;
extern PACKAGE TglGenOcclusionQueriesNV glGenOcclusionQueriesNV;
extern PACKAGE TglDeleteOcclusionQueriesNV glDeleteOcclusionQueriesNV;
extern PACKAGE TglIsOcclusionQueryNV glIsOcclusionQueryNV;
extern PACKAGE TglBeginOcclusionQueryNV glBeginOcclusionQueryNV;
extern PACKAGE TglEndOcclusionQueryNV glEndOcclusionQueryNV;
extern PACKAGE TglGetOcclusionQueryivNV glGetOcclusionQueryivNV;
extern PACKAGE TglGetOcclusionQueryuivNV glGetOcclusionQueryuivNV;
extern PACKAGE TglPixelDataRangeNV glPixelDataRangeNV;
extern PACKAGE TglFlushPixelDataRangeNV glFlushPixelDataRangeNV;
extern PACKAGE TglPointParameteriNV glPointParameteriNV;
extern PACKAGE TglPointParameterivNV glPointParameterivNV;
extern PACKAGE TglPrimitiveRestartNV glPrimitiveRestartNV;
extern PACKAGE TglPrimitiveRestartIndexNV glPrimitiveRestartIndexNV;
extern PACKAGE TglCombinerParameterfvNV glCombinerParameterfvNV;
extern PACKAGE TglCombinerParameterfNV glCombinerParameterfNV;
extern PACKAGE TglCombinerParameterivNV glCombinerParameterivNV;
extern PACKAGE TglCombinerParameteriNV glCombinerParameteriNV;
extern PACKAGE TglCombinerInputNV glCombinerInputNV;
extern PACKAGE TglCombinerOutputNV glCombinerOutputNV;
extern PACKAGE TglFinalCombinerInputNV glFinalCombinerInputNV;
extern PACKAGE TglGetCombinerInputParameterfvNV glGetCombinerInputParameterfvNV;
extern PACKAGE TglGetCombinerInputParameterivNV glGetCombinerInputParameterivNV;
extern PACKAGE TglGetCombinerOutputParameterfvNV glGetCombinerOutputParameterfvNV;
extern PACKAGE TglGetCombinerOutputParameterivNV glGetCombinerOutputParameterivNV;
extern PACKAGE TglGetFinalCombinerInputParameterfvNV glGetFinalCombinerInputParameterfvNV;
extern PACKAGE TglGetFinalCombinerInputParameterivNV glGetFinalCombinerInputParameterivNV;
extern PACKAGE TglCombinerStageParameterfvNV glCombinerStageParameterfvNV;
extern PACKAGE TglGetCombinerStageParameterfvNV glGetCombinerStageParameterfvNV;
extern PACKAGE TglFlushVertexArrayRangeNV glFlushVertexArrayRangeNV;
extern PACKAGE TglVertexArrayRangeNV glVertexArrayRangeNV;
extern PACKAGE TglAreProgramsResidentNV glAreProgramsResidentNV;
extern PACKAGE TglBindProgramNV glBindProgramNV;
extern PACKAGE TglDeleteProgramsNV glDeleteProgramsNV;
extern PACKAGE TglExecuteProgramNV glExecuteProgramNV;
extern PACKAGE TglGenProgramsNV glGenProgramsNV;
extern PACKAGE TglGetProgramParameterdvNV glGetProgramParameterdvNV;
extern PACKAGE TglGetProgramParameterfvNV glGetProgramParameterfvNV;
extern PACKAGE TglGetProgramivNV glGetProgramivNV;
extern PACKAGE TglGetProgramStringNV glGetProgramStringNV;
extern PACKAGE TglGetTrackMatrixivNV glGetTrackMatrixivNV;
extern PACKAGE TglGetVertexAttribdvNV glGetVertexAttribdvNV;
extern PACKAGE TglGetVertexAttribfvNV glGetVertexAttribfvNV;
extern PACKAGE TglGetVertexAttribivNV glGetVertexAttribivNV;
extern PACKAGE TglGetVertexAttribPointervNV glGetVertexAttribPointervNV;
extern PACKAGE TglIsProgramNV glIsProgramNV;
extern PACKAGE TglLoadProgramNV glLoadProgramNV;
extern PACKAGE TglProgramParameter4dNV glProgramParameter4dNV;
extern PACKAGE TglProgramParameter4dvNV glProgramParameter4dvNV;
extern PACKAGE TglProgramParameter4fNV glProgramParameter4fNV;
extern PACKAGE TglProgramParameter4fvNV glProgramParameter4fvNV;
extern PACKAGE TglProgramParameters4dvNV glProgramParameters4dvNV;
extern PACKAGE TglProgramParameters4fvNV glProgramParameters4fvNV;
extern PACKAGE TglRequestResidentProgramsNV glRequestResidentProgramsNV;
extern PACKAGE TglTrackMatrixNV glTrackMatrixNV;
extern PACKAGE TglVertexAttribPointerNV glVertexAttribPointerNV;
extern PACKAGE TglVertexAttrib1dNV glVertexAttrib1dNV;
extern PACKAGE TglVertexAttrib1dvNV glVertexAttrib1dvNV;
extern PACKAGE TglVertexAttrib1fNV glVertexAttrib1fNV;
extern PACKAGE TglVertexAttrib1fvNV glVertexAttrib1fvNV;
extern PACKAGE TglVertexAttrib1sNV glVertexAttrib1sNV;
extern PACKAGE TglVertexAttrib1svNV glVertexAttrib1svNV;
extern PACKAGE TglVertexAttrib2dNV glVertexAttrib2dNV;
extern PACKAGE TglVertexAttrib2dvNV glVertexAttrib2dvNV;
extern PACKAGE TglVertexAttrib2fNV glVertexAttrib2fNV;
extern PACKAGE TglVertexAttrib2fvNV glVertexAttrib2fvNV;
extern PACKAGE TglVertexAttrib2sNV glVertexAttrib2sNV;
extern PACKAGE TglVertexAttrib2svNV glVertexAttrib2svNV;
extern PACKAGE TglVertexAttrib3dNV glVertexAttrib3dNV;
extern PACKAGE TglVertexAttrib3dvNV glVertexAttrib3dvNV;
extern PACKAGE TglVertexAttrib3fNV glVertexAttrib3fNV;
extern PACKAGE TglVertexAttrib3fvNV glVertexAttrib3fvNV;
extern PACKAGE TglVertexAttrib3sNV glVertexAttrib3sNV;
extern PACKAGE TglVertexAttrib3svNV glVertexAttrib3svNV;
extern PACKAGE TglVertexAttrib4dNV glVertexAttrib4dNV;
extern PACKAGE TglVertexAttrib4dvNV glVertexAttrib4dvNV;
extern PACKAGE TglVertexAttrib4fNV glVertexAttrib4fNV;
extern PACKAGE TglVertexAttrib4fvNV glVertexAttrib4fvNV;
extern PACKAGE TglVertexAttrib4sNV glVertexAttrib4sNV;
extern PACKAGE TglVertexAttrib4svNV glVertexAttrib4svNV;
extern PACKAGE TglVertexAttrib4ubNV glVertexAttrib4ubNV;
extern PACKAGE TglVertexAttrib4ubvNV glVertexAttrib4ubvNV;
extern PACKAGE TglVertexAttribs1dvNV glVertexAttribs1dvNV;
extern PACKAGE TglVertexAttribs1fvNV glVertexAttribs1fvNV;
extern PACKAGE TglVertexAttribs1svNV glVertexAttribs1svNV;
extern PACKAGE TglVertexAttribs2dvNV glVertexAttribs2dvNV;
extern PACKAGE TglVertexAttribs2fvNV glVertexAttribs2fvNV;
extern PACKAGE TglVertexAttribs2svNV glVertexAttribs2svNV;
extern PACKAGE TglVertexAttribs3dvNV glVertexAttribs3dvNV;
extern PACKAGE TglVertexAttribs3fvNV glVertexAttribs3fvNV;
extern PACKAGE TglVertexAttribs3svNV glVertexAttribs3svNV;
extern PACKAGE TglVertexAttribs4dvNV glVertexAttribs4dvNV;
extern PACKAGE TglVertexAttribs4fvNV glVertexAttribs4fvNV;
extern PACKAGE TglVertexAttribs4svNV glVertexAttribs4svNV;
extern PACKAGE TglVertexAttribs4ubvNV glVertexAttribs4ubvNV;
extern PACKAGE TglHintPGI glHintPGI;
extern PACKAGE TglDetailTexFuncSGIS glDetailTexFuncSGIS;
extern PACKAGE TglGetDetailTexFuncSGIS glGetDetailTexFuncSGIS;
extern PACKAGE TglFogFuncSGIS glFogFuncSGIS;
extern PACKAGE TglGetFogFuncSGIS glGetFogFuncSGIS;
extern PACKAGE TglSampleMaskSGIS glSampleMaskSGIS;
extern PACKAGE TglSamplePatternSGIS glSamplePatternSGIS;
extern PACKAGE TglPixelTexGenParameteriSGIS glPixelTexGenParameteriSGIS;
extern PACKAGE TglPixelTexGenParameterivSGIS glPixelTexGenParameterivSGIS;
extern PACKAGE TglPixelTexGenParameterfSGIS glPixelTexGenParameterfSGIS;
extern PACKAGE TglPixelTexGenParameterfvSGIS glPixelTexGenParameterfvSGIS;
extern PACKAGE TglGetPixelTexGenParameterivSGIS glGetPixelTexGenParameterivSGIS;
extern PACKAGE TglGetPixelTexGenParameterfvSGIS glGetPixelTexGenParameterfvSGIS;
extern PACKAGE TglPointParameterfSGIS glPointParameterfSGIS;
extern PACKAGE TglPointParameterfvSGIS glPointParameterfvSGIS;
extern PACKAGE TglSharpenTexFuncSGIS glSharpenTexFuncSGIS;
extern PACKAGE TglGetSharpenTexFuncSGIS glGetSharpenTexFuncSGIS;
extern PACKAGE TglTexImage4DSGIS glTexImage4DSGIS;
extern PACKAGE TglTexSubImage4DSGIS glTexSubImage4DSGIS;
extern PACKAGE TglTextureColorMaskSGIS glTextureColorMaskSGIS;
extern PACKAGE TglGetTexFilterFuncSGIS glGetTexFilterFuncSGIS;
extern PACKAGE TglTexFilterFuncSGIS glTexFilterFuncSGIS;
extern PACKAGE TglAsyncMarkerSGIX glAsyncMarkerSGIX;
extern PACKAGE TglFinishAsyncSGIX glFinishAsyncSGIX;
extern PACKAGE TglPollAsyncSGIX glPollAsyncSGIX;
extern PACKAGE TglGenAsyncMarkersSGIX glGenAsyncMarkersSGIX;
extern PACKAGE TglDeleteAsyncMarkersSGIX glDeleteAsyncMarkersSGIX;
extern PACKAGE TglIsAsyncMarkerSGIX glIsAsyncMarkerSGIX;
extern PACKAGE TglFlushRasterSGIX glFlushRasterSGIX;
extern PACKAGE TglFragmentColorMaterialSGIX glFragmentColorMaterialSGIX;
extern PACKAGE TglFragmentLightfSGIX glFragmentLightfSGIX;
extern PACKAGE TglFragmentLightfvSGIX glFragmentLightfvSGIX;
extern PACKAGE TglFragmentLightiSGIX glFragmentLightiSGIX;
extern PACKAGE TglFragmentLightivSGIX glFragmentLightivSGIX;
extern PACKAGE TglFragmentLightModelfSGIX glFragmentLightModelfSGIX;
extern PACKAGE TglFragmentLightModelfvSGIX glFragmentLightModelfvSGIX;
extern PACKAGE TglFragmentLightModeliSGIX glFragmentLightModeliSGIX;
extern PACKAGE TglFragmentLightModelivSGIX glFragmentLightModelivSGIX;
extern PACKAGE TglFragmentMaterialfSGIX glFragmentMaterialfSGIX;
extern PACKAGE TglFragmentMaterialfvSGIX glFragmentMaterialfvSGIX;
extern PACKAGE TglFragmentMaterialiSGIX glFragmentMaterialiSGIX;
extern PACKAGE TglFragmentMaterialivSGIX glFragmentMaterialivSGIX;
extern PACKAGE TglGetFragmentLightfvSGIX glGetFragmentLightfvSGIX;
extern PACKAGE TglGetFragmentLightivSGIX glGetFragmentLightivSGIX;
extern PACKAGE TglGetFragmentMaterialfvSGIX glGetFragmentMaterialfvSGIX;
extern PACKAGE TglGetFragmentMaterialivSGIX glGetFragmentMaterialivSGIX;
extern PACKAGE TglLightEnviSGIX glLightEnviSGIX;
extern PACKAGE TglFrameZoomSGIX glFrameZoomSGIX;
extern PACKAGE TglIglooInterfaceSGIX glIglooInterfaceSGIX;
extern PACKAGE TglGetInstrumentsSGIX glGetInstrumentsSGIX;
extern PACKAGE TglInstrumentsBufferSGIX glInstrumentsBufferSGIX;
extern PACKAGE TglPollInstrumentsSGIX glPollInstrumentsSGIX;
extern PACKAGE TglReadInstrumentsSGIX glReadInstrumentsSGIX;
extern PACKAGE TglStartInstrumentsSGIX glStartInstrumentsSGIX;
extern PACKAGE TglStopInstrumentsSGIX glStopInstrumentsSGIX;
extern PACKAGE TglGetListParameterfvSGIX glGetListParameterfvSGIX;
extern PACKAGE TglGetListParameterivSGIX glGetListParameterivSGIX;
extern PACKAGE TglListParameterfSGIX glListParameterfSGIX;
extern PACKAGE TglListParameterfvSGIX glListParameterfvSGIX;
extern PACKAGE TglListParameteriSGIX glListParameteriSGIX;
extern PACKAGE TglListParameterivSGIX glListParameterivSGIX;
extern PACKAGE TglPixelTexGenSGIX glPixelTexGenSGIX;
extern PACKAGE TglDeformationMap3dSGIX glDeformationMap3dSGIX;
extern PACKAGE TglDeformationMap3fSGIX glDeformationMap3fSGIX;
extern PACKAGE TglDeformSGIX glDeformSGIX;
extern PACKAGE TglLoadIdentityDeformationMapSGIX glLoadIdentityDeformationMapSGIX;
extern PACKAGE TglReferencePlaneSGIX glReferencePlaneSGIX;
extern PACKAGE TglSpriteParameterfSGIX glSpriteParameterfSGIX;
extern PACKAGE TglSpriteParameterfvSGIX glSpriteParameterfvSGIX;
extern PACKAGE TglSpriteParameteriSGIX glSpriteParameteriSGIX;
extern PACKAGE TglSpriteParameterivSGIX glSpriteParameterivSGIX;
extern PACKAGE TglTagSampleBufferSGIX glTagSampleBufferSGIX;
extern PACKAGE TglColorTableSGI glColorTableSGI;
extern PACKAGE TglColorTableParameterfvSGI glColorTableParameterfvSGI;
extern PACKAGE TglColorTableParameterivSGI glColorTableParameterivSGI;
extern PACKAGE TglCopyColorTableSGI glCopyColorTableSGI;
extern PACKAGE TglGetColorTableSGI glGetColorTableSGI;
extern PACKAGE TglGetColorTableParameterfvSGI glGetColorTableParameterfvSGI;
extern PACKAGE TglGetColorTableParameterivSGI glGetColorTableParameterivSGI;
extern PACKAGE TglFinishTextureSUNX glFinishTextureSUNX;
extern PACKAGE TglGlobalAlphaFactorbSUN glGlobalAlphaFactorbSUN;
extern PACKAGE TglGlobalAlphaFactorsSUN glGlobalAlphaFactorsSUN;
extern PACKAGE TglGlobalAlphaFactoriSUN glGlobalAlphaFactoriSUN;
extern PACKAGE TglGlobalAlphaFactorfSUN glGlobalAlphaFactorfSUN;
extern PACKAGE TglGlobalAlphaFactordSUN glGlobalAlphaFactordSUN;
extern PACKAGE TglGlobalAlphaFactorubSUN glGlobalAlphaFactorubSUN;
extern PACKAGE TglGlobalAlphaFactorusSUN glGlobalAlphaFactorusSUN;
extern PACKAGE TglGlobalAlphaFactoruiSUN glGlobalAlphaFactoruiSUN;
extern PACKAGE TglDrawMeshArraysSUN glDrawMeshArraysSUN;
extern PACKAGE TglReplacementCodeuiSUN glReplacementCodeuiSUN;
extern PACKAGE TglReplacementCodeusSUN glReplacementCodeusSUN;
extern PACKAGE TglReplacementCodeubSUN glReplacementCodeubSUN;
extern PACKAGE TglReplacementCodeuivSUN glReplacementCodeuivSUN;
extern PACKAGE TglReplacementCodeusvSUN glReplacementCodeusvSUN;
extern PACKAGE TglReplacementCodeubvSUN glReplacementCodeubvSUN;
extern PACKAGE TglReplacementCodePointerSUN glReplacementCodePointerSUN;
extern PACKAGE TglColor4ubVertex2fSUN glColor4ubVertex2fSUN;
extern PACKAGE TglColor4ubVertex2fvSUN glColor4ubVertex2fvSUN;
extern PACKAGE TglColor4ubVertex3fSUN glColor4ubVertex3fSUN;
extern PACKAGE TglColor4ubVertex3fvSUN glColor4ubVertex3fvSUN;
extern PACKAGE TglColor3fVertex3fSUN glColor3fVertex3fSUN;
extern PACKAGE TglColor3fVertex3fvSUN glColor3fVertex3fvSUN;
extern PACKAGE TglNormal3fVertex3fSUN glNormal3fVertex3fSUN;
extern PACKAGE TglNormal3fVertex3fvSUN glNormal3fVertex3fvSUN;
extern PACKAGE TglColor4fNormal3fVertex3fSUN glColor4fNormal3fVertex3fSUN;
extern PACKAGE TglColor4fNormal3fVertex3fvSUN glColor4fNormal3fVertex3fvSUN;
extern PACKAGE TglTexCoord2fVertex3fSUN glTexCoord2fVertex3fSUN;
extern PACKAGE TglTexCoord2fVertex3fvSUN glTexCoord2fVertex3fvSUN;
extern PACKAGE TglTexCoord4fVertex4fSUN glTexCoord4fVertex4fSUN;
extern PACKAGE TglTexCoord4fVertex4fvSUN glTexCoord4fVertex4fvSUN;
extern PACKAGE TglTexCoord2fColor4ubVertex3fSUN glTexCoord2fColor4ubVertex3fSUN;
extern PACKAGE TglTexCoord2fColor4ubVertex3fvSUN glTexCoord2fColor4ubVertex3fvSUN;
extern PACKAGE TglTexCoord2fColor3fVertex3fSUN glTexCoord2fColor3fVertex3fSUN;
extern PACKAGE TglTexCoord2fColor3fVertex3fvSUN glTexCoord2fColor3fVertex3fvSUN;
extern PACKAGE TglTexCoord2fNormal3fVertex3fSUN glTexCoord2fNormal3fVertex3fSUN;
extern PACKAGE TglTexCoord2fNormal3fVertex3fvSUN glTexCoord2fNormal3fVertex3fvSUN;
extern PACKAGE TglTexCoord2fColor4fNormal3fVertex3fSUN glTexCoord2fColor4fNormal3fVertex3fSUN;
extern PACKAGE TglTexCoord2fColor4fNormal3fVertex3fvSUN glTexCoord2fColor4fNormal3fVertex3fvSUN;
extern PACKAGE TglTexCoord4fColor4fNormal3fVertex4fSUN glTexCoord4fColor4fNormal3fVertex4fSUN;
extern PACKAGE TglTexCoord4fColor4fNormal3fVertex4fvSUN glTexCoord4fColor4fNormal3fVertex4fvSUN;
extern PACKAGE TglReplacementCodeuiVertex3fSUN glReplacementCodeuiVertex3fSUN;
extern PACKAGE TglReplacementCodeuiVertex3fvSUN glReplacementCodeuiVertex3fvSUN;
extern PACKAGE TglReplacementCodeuiColor4ubVertex3fSUN glReplacementCodeuiColor4ubVertex3fSUN;
extern PACKAGE TglReplacementCodeuiColor4ubVertex3fvSUN glReplacementCodeuiColor4ubVertex3fvSUN;
extern PACKAGE TglReplacementCodeuiColor3fVertex3fSUN glReplacementCodeuiColor3fVertex3fSUN;
extern PACKAGE TglReplacementCodeuiColor3fVertex3fvSUN glReplacementCodeuiColor3fVertex3fvSUN;
extern PACKAGE TglReplacementCodeuiNormal3fVertex3fSUN glReplacementCodeuiNormal3fVertex3fSUN;
extern PACKAGE TglReplacementCodeuiNormal3fVertex3fvSUN glReplacementCodeuiNormal3fVertex3fvSUN;
extern PACKAGE TglReplacementCodeuiColor4fNormal3fVertex3fSUN glReplacementCodeuiColor4fNormal3fVertex3fSUN;
extern PACKAGE TglReplacementCodeuiColor4fNormal3fVertex3fvSUN glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
extern PACKAGE TglReplacementCodeuiTexCoord2fVertex3fSUN glReplacementCodeuiTexCoord2fVertex3fSUN;
extern PACKAGE TglReplacementCodeuiTexCoord2fVertex3fvSUN glReplacementCodeuiTexCoord2fVertex3fvSUN;
extern PACKAGE TglReplacementCodeuiTexCoord2fNormal3fVertex3fSUN glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
extern PACKAGE TglReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
extern PACKAGE TglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
extern PACKAGE TglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
extern PACKAGE TwglGetProcAddress wglGetProcAddress;
extern PACKAGE TwglCopyContext wglCopyContext;
extern PACKAGE TwglCreateContext wglCreateContext;
extern PACKAGE TwglCreateLayerContext wglCreateLayerContext;
extern PACKAGE TwglDeleteContext wglDeleteContext;
extern PACKAGE TwglDescribeLayerPlane wglDescribeLayerPlane;
extern PACKAGE TwglGetCurrentContext wglGetCurrentContext;
extern PACKAGE TwglGetCurrentDC wglGetCurrentDC;
extern PACKAGE TwglGetLayerPaletteEntries wglGetLayerPaletteEntries;
extern PACKAGE TwglMakeCurrent wglMakeCurrent;
extern PACKAGE TwglRealizeLayerPalette wglRealizeLayerPalette;
extern PACKAGE TwglSetLayerPaletteEntries wglSetLayerPaletteEntries;
extern PACKAGE TwglShareLists wglShareLists;
extern PACKAGE TwglSwapLayerBuffers wglSwapLayerBuffers;
extern PACKAGE TwglSwapMultipleBuffers wglSwapMultipleBuffers;
extern PACKAGE TwglUseFontBitmapsA wglUseFontBitmapsA;
extern PACKAGE TwglUseFontOutlinesA wglUseFontOutlinesA;
extern PACKAGE TwglUseFontBitmapsW wglUseFontBitmapsW;
extern PACKAGE TwglUseFontOutlinesW wglUseFontOutlinesW;
extern PACKAGE TwglUseFontBitmaps wglUseFontBitmaps;
extern PACKAGE TwglUseFontOutlines wglUseFontOutlines;
extern PACKAGE TwglCreateBufferRegionARB wglCreateBufferRegionARB;
extern PACKAGE TwglDeleteBufferRegionARB wglDeleteBufferRegionARB;
extern PACKAGE TwglSaveBufferRegionARB wglSaveBufferRegionARB;
extern PACKAGE TwglRestoreBufferRegionARB wglRestoreBufferRegionARB;
extern PACKAGE TwglMakeContextCurrentARB wglMakeContextCurrentARB;
extern PACKAGE TwglGetCurrentReadDCARB wglGetCurrentReadDCARB;
extern PACKAGE TwglCreatePbufferARB wglCreatePbufferARB;
extern PACKAGE TwglGetPbufferDCARB wglGetPbufferDCARB;
extern PACKAGE TwglReleasePbufferDCARB wglReleasePbufferDCARB;
extern PACKAGE TwglDestroyPbufferARB wglDestroyPbufferARB;
extern PACKAGE TwglQueryPbufferARB wglQueryPbufferARB;
extern PACKAGE TwglGetPixelFormatAttribivARB wglGetPixelFormatAttribivARB;
extern PACKAGE TwglGetPixelFormatAttribfvARB wglGetPixelFormatAttribfvARB;
extern PACKAGE TwglChoosePixelFormatARB wglChoosePixelFormatARB;
extern PACKAGE TwglClampColorARB wglClampColorARB;
extern PACKAGE TwglBindTexImageARB wglBindTexImageARB;
extern PACKAGE TwglReleaseTexImageARB wglReleaseTexImageARB;
extern PACKAGE TwglSetPbufferAttribARB wglSetPbufferAttribARB;
extern PACKAGE TwglCreateDisplayColorTableEXT wglCreateDisplayColorTableEXT;
extern PACKAGE TwglLoadDisplayColorTableEXT wglLoadDisplayColorTableEXT;
extern PACKAGE TwglBindDisplayColorTableEXT wglBindDisplayColorTableEXT;
extern PACKAGE TwglDestroyDisplayColorTableEXT wglDestroyDisplayColorTableEXT;
extern PACKAGE TwglMakeContextCurrentEXT wglMakeContextCurrentEXT;
extern PACKAGE TwglGetCurrentReadDCEXT wglGetCurrentReadDCEXT;
extern PACKAGE TwglCreatePbufferEXT wglCreatePbufferEXT;
extern PACKAGE TwglGetPbufferDCEXT wglGetPbufferDCEXT;
extern PACKAGE TwglReleasePbufferDCEXT wglReleasePbufferDCEXT;
extern PACKAGE TwglDestroyPbufferEXT wglDestroyPbufferEXT;
extern PACKAGE TwglQueryPbufferEXT wglQueryPbufferEXT;
extern PACKAGE TwglGetPixelFormatAttribivEXT wglGetPixelFormatAttribivEXT;
extern PACKAGE TwglGetPixelFormatAttribfvEXT wglGetPixelFormatAttribfvEXT;
extern PACKAGE TwglChoosePixelFormatEXT wglChoosePixelFormatEXT;
extern PACKAGE TwglSwapIntervalEXT wglSwapIntervalEXT;
extern PACKAGE TwglGetSwapIntervalEXT wglGetSwapIntervalEXT;
extern PACKAGE TwglGetDigitalVideoParametersI3D wglGetDigitalVideoParametersI3D;
extern PACKAGE TwglSetDigitalVideoParametersI3D wglSetDigitalVideoParametersI3D;
extern PACKAGE TwglGetGammaTableParametersI3D wglGetGammaTableParametersI3D;
extern PACKAGE TwglSetGammaTableParametersI3D wglSetGammaTableParametersI3D;
extern PACKAGE TwglGetGammaTableI3D wglGetGammaTableI3D;
extern PACKAGE TwglSetGammaTableI3D wglSetGammaTableI3D;
extern PACKAGE TwglEnableGenlockI3D wglEnableGenlockI3D;
extern PACKAGE TwglDisableGenlockI3D wglDisableGenlockI3D;
extern PACKAGE TwglIsEnabledGenlockI3D wglIsEnabledGenlockI3D;
extern PACKAGE TwglGenlockSourceI3D wglGenlockSourceI3D;
extern PACKAGE TwglGetGenlockSourceI3D wglGetGenlockSourceI3D;
extern PACKAGE TwglGenlockSourceEdgeI3D wglGenlockSourceEdgeI3D;
extern PACKAGE TwglGetGenlockSourceEdgeI3D wglGetGenlockSourceEdgeI3D;
extern PACKAGE TwglGenlockSampleRateI3D wglGenlockSampleRateI3D;
extern PACKAGE TwglGetGenlockSampleRateI3D wglGetGenlockSampleRateI3D;
extern PACKAGE TwglGenlockSourceDelayI3D wglGenlockSourceDelayI3D;
extern PACKAGE TwglGetGenlockSourceDelayI3D wglGetGenlockSourceDelayI3D;
extern PACKAGE TwglQueryGenlockMaxSourceDelayI3D wglQueryGenlockMaxSourceDelayI3D;
extern PACKAGE TwglCreateImageBufferI3D wglCreateImageBufferI3D;
extern PACKAGE TwglDestroyImageBufferI3D wglDestroyImageBufferI3D;
extern PACKAGE TwglAssociateImageBufferEventsI3D wglAssociateImageBufferEventsI3D;
extern PACKAGE TwglReleaseImageBufferEventsI3D wglReleaseImageBufferEventsI3D;
extern PACKAGE TwglEnableFrameLockI3D wglEnableFrameLockI3D;
extern PACKAGE TwglDisableFrameLockI3D wglDisableFrameLockI3D;
extern PACKAGE TwglIsEnabledFrameLockI3D wglIsEnabledFrameLockI3D;
extern PACKAGE TwglQueryFrameLockMasterI3D wglQueryFrameLockMasterI3D;
extern PACKAGE TwglGetFrameUsageI3D wglGetFrameUsageI3D;
extern PACKAGE TwglBeginFrameTrackingI3D wglBeginFrameTrackingI3D;
extern PACKAGE TwglEndFrameTrackingI3D wglEndFrameTrackingI3D;
extern PACKAGE TwglQueryFrameTrackingI3D wglQueryFrameTrackingI3D;
extern PACKAGE TwglAllocateMemoryNV wglAllocateMemoryNV;
extern PACKAGE TwglFreeMemoryNV wglFreeMemoryNV;
extern PACKAGE TwglGetSyncValuesOML wglGetSyncValuesOML;
extern PACKAGE TwglGetMscRateOML wglGetMscRateOML;
extern PACKAGE TwglSwapBuffersMscOML wglSwapBuffersMscOML;
extern PACKAGE TwglSwapLayerBuffersMscOML wglSwapLayerBuffersMscOML;
extern PACKAGE TwglWaitForMscOML wglWaitForMscOML;
extern PACKAGE TwglWaitForSbcOML wglWaitForSbcOML;
extern PACKAGE TglDrawRangeElementsWIN glDrawRangeElementsWIN;
extern PACKAGE TglAddSwapHintRectWIN glAddSwapHintRectWIN;
extern PACKAGE TgluErrorString gluErrorString;
extern PACKAGE TgluOrtho2D gluOrtho2D;
extern PACKAGE TgluPerspective gluPerspective;
extern PACKAGE TgluPickMatrix gluPickMatrix;
extern PACKAGE TgluLookAt gluLookAt;
extern PACKAGE TgluProject gluProject;
extern PACKAGE TgluUnProject gluUnProject;
extern PACKAGE TgluScaleImage gluScaleImage;
extern PACKAGE TgluBuild1DMipmaps gluBuild1DMipmaps;
extern PACKAGE TgluBuild2DMipmaps gluBuild2DMipmaps;
extern PACKAGE TgluNewQuadric gluNewQuadric;
extern PACKAGE TgluDeleteQuadric gluDeleteQuadric;
extern PACKAGE TgluQuadricNormals gluQuadricNormals;
extern PACKAGE TgluQuadricTexture gluQuadricTexture;
extern PACKAGE TgluQuadricOrientation gluQuadricOrientation;
extern PACKAGE TgluQuadricDrawStyle gluQuadricDrawStyle;
extern PACKAGE TgluCylinder gluCylinder;
extern PACKAGE TgluDisk gluDisk;
extern PACKAGE TgluPartialDisk gluPartialDisk;
extern PACKAGE TgluSphere gluSphere;
extern PACKAGE TgluQuadricCallback gluQuadricCallback;
extern PACKAGE TgluNewTess gluNewTess;
extern PACKAGE TgluDeleteTess gluDeleteTess;
extern PACKAGE TgluTessBeginPolygon gluTessBeginPolygon;
extern PACKAGE TgluTessBeginContour gluTessBeginContour;
extern PACKAGE TgluTessVertex gluTessVertex;
extern PACKAGE TgluTessEndContour gluTessEndContour;
extern PACKAGE TgluTessEndPolygon gluTessEndPolygon;
extern PACKAGE TgluTessProperty gluTessProperty;
extern PACKAGE TgluTessNormal gluTessNormal;
extern PACKAGE TgluTessCallback gluTessCallback;
extern PACKAGE TgluGetTessProperty gluGetTessProperty;
extern PACKAGE TgluNewNurbsRenderer gluNewNurbsRenderer;
extern PACKAGE TgluDeleteNurbsRenderer gluDeleteNurbsRenderer;
extern PACKAGE TgluBeginSurface gluBeginSurface;
extern PACKAGE TgluBeginCurve gluBeginCurve;
extern PACKAGE TgluEndCurve gluEndCurve;
extern PACKAGE TgluEndSurface gluEndSurface;
extern PACKAGE TgluBeginTrim gluBeginTrim;
extern PACKAGE TgluEndTrim gluEndTrim;
extern PACKAGE TgluPwlCurve gluPwlCurve;
extern PACKAGE TgluNurbsCurve gluNurbsCurve;
extern PACKAGE TgluNurbsSurface gluNurbsSurface;
extern PACKAGE TgluLoadSamplingMatrices gluLoadSamplingMatrices;
extern PACKAGE TgluNurbsProperty gluNurbsProperty;
extern PACKAGE TgluGetNurbsProperty gluGetNurbsProperty;
extern PACKAGE TgluNurbsCallback gluNurbsCallback;
extern PACKAGE TgluBeginPolygon gluBeginPolygon;
extern PACKAGE TgluNextContour gluNextContour;
extern PACKAGE TgluEndPolygon gluEndPolygon;
extern PACKAGE TglColorPointer _glColorPointer;
extern PACKAGE TglGenTextures _glGenTextures;
extern PACKAGE TglGetString _glGetString;
extern PACKAGE TglNormalPointer _glNormalPointer;
extern PACKAGE TglReadPixels _glReadPixels;
extern PACKAGE TglTexCoordPointer _glTexCoordPointer;
extern PACKAGE TglTexImage2D _glTexImage2D;
extern PACKAGE TglVertexPointer _glVertexPointer;
extern PACKAGE TglVertexAttribPointerARB _glVertexAttribPointerARB;
extern PACKAGE TglBufferData _glBufferData;
extern PACKAGE TglBufferSubData _glBufferSubData;
extern PACKAGE TwglGetExtensionsStringARB _wglGetExtensionsStringARB;
extern PACKAGE TwglGetExtensionsStringEXT _wglGetExtensionsStringEXT;
extern PACKAGE TglCreateShaderObjectARB _glCreateShaderObjectARB;
extern PACKAGE TglShaderSourceARB _glShaderSourceARB;
extern PACKAGE TglGetInfoLogARB _glGetInfoLogARB;
extern PACKAGE TglBufferDataARB _glBufferDataARB;
extern PACKAGE TglBufferSubDataARB _glBufferSubDataARB;
extern PACKAGE TgluGetString _gluGetString;
extern PACKAGE unsigned LibHandle;
extern PACKAGE unsigned GLULibHandle;
extern PACKAGE int LastPixelFormat;
extern PACKAGE bool ExtensionsRead;
extern PACKAGE bool ImplementationRead;
extern PACKAGE char * __fastcall glGetString(unsigned name);
extern PACKAGE char * __fastcall gluGetString(unsigned name);
extern PACKAGE char * __fastcall wglGetExtensionsStringEXT(void);
extern PACKAGE char * __fastcall wglGetExtensionsStringARB(HDC dc);
extern PACKAGE void __fastcall glTexImage2D(unsigned target, int level, int internalformat, int width, int height, int border, unsigned format, unsigned _type, const void * pixels)/* overload */;
extern PACKAGE void __fastcall glGenTextures(int n, PGLuint textures)/* overload */;
extern PACKAGE void __fastcall glVertexPointer(int size, unsigned _type, int stride, const void * _pointer)/* overload */;
extern PACKAGE void __fastcall glColorPointer(int size, unsigned _type, int stride, const void * _pointer)/* overload */;
extern PACKAGE void __fastcall glTexCoordPointer(int size, unsigned _type, int stride, const void * _pointer)/* overload */;
extern PACKAGE void __fastcall glNormalPointer(unsigned _type, int stride, const void * _pointer)/* overload */;
extern PACKAGE void __fastcall glVertexAttribPointerARB(unsigned index, int size, unsigned _type, Byte normalized, int stride, const void * _pointer)/* overload */;
extern PACKAGE void __fastcall glReadPixels(int x, int y, int width, int height, unsigned format, unsigned _type, void * pixels)/* overload */;
extern PACKAGE void __fastcall glBufferDataARB(unsigned target, int size, const void * data, unsigned usage)/* overload */;
extern PACKAGE void __fastcall glBufferSubDataARB(unsigned target, int offset, int size, const void * data)/* overload */;
extern PACKAGE void __fastcall glBufferData(unsigned target, int size, const void * data, unsigned usage)/* overload */;
extern PACKAGE void __fastcall glBufferSubData(unsigned target, int offset, int size, const void * data)/* overload */;
extern PACKAGE int __fastcall glCreateShaderObjectARB(unsigned shaderType)/* overload */;
extern PACKAGE void __fastcall glShaderSourceARB(int shaderObj, int count, PPGLCharARB _string, PGLInt lengths)/* overload */;
extern PACKAGE void __fastcall glGetInfoLogARB(int shaderObj, int maxLength, int &length, char * infoLog);
extern PACKAGE void __fastcall glGetProgramInfoLog(int programObj, int maxLength, int &length, char * infoLog)/* overload */;
extern PACKAGE void __fastcall glGetShaderInfoLog(int shaderObj, int maxLength, int &length, char * infoLog)/* overload */;
extern PACKAGE void __fastcall glShaderSource(int shaderObj, int count, PPGLChar _string, PGLInt lengths)/* overload */;
extern PACKAGE bool __fastcall InitOpenGL(AnsiString LibName = "OpenGL32.dll", AnsiString GLULibName = "GLU32.dll");
extern PACKAGE void __fastcall ReadOpenGLCore(void);
extern PACKAGE void __fastcall Read_GL_3DFX_tbuffer(void);
extern PACKAGE void __fastcall Read_GL_APPLE_element_array(void);
extern PACKAGE void __fastcall Read_GL_APPLE_fence(void);
extern PACKAGE void __fastcall Read_GL_APPLE_vertex_array_object(void);
extern PACKAGE void __fastcall Read_GL_APPLE_vertex_array_range(void);
extern PACKAGE void __fastcall Read_GL_ARB_matrix_palette(void);
extern PACKAGE void __fastcall Read_GL_ARB_multitexture(void);
extern PACKAGE void __fastcall Read_GL_ARB_point_parameters(void);
extern PACKAGE void __fastcall Read_GL_ARB_texture_compression(void);
extern PACKAGE void __fastcall Read_GL_ARB_transpose_matrix(void);
extern PACKAGE void __fastcall Read_GL_ARB_vertex_blend(void);
extern PACKAGE void __fastcall Read_GL_ARB_buffer_object(void);
extern PACKAGE void __fastcall Read_GL_ARB_vertex_program(void);
extern PACKAGE void __fastcall Read_GL_ARB_window_pos(void);
extern PACKAGE void __fastcall Read_GL_ARB_color_buffer_float(void);
extern PACKAGE void __fastcall Read_GL_ATI_draw_buffers(void);
extern PACKAGE void __fastcall Read_GL_ATI_element_array(void);
extern PACKAGE void __fastcall Read_GL_ATI_envmap_bumpmap(void);
extern PACKAGE void __fastcall Read_GL_ATI_fragment_shader(void);
extern PACKAGE void __fastcall Read_GL_ATI_map_object_buffer(void);
extern PACKAGE void __fastcall Read_GL_ATI_pn_triangles(void);
extern PACKAGE void __fastcall Read_GL_ATI_separate_stencil(void);
extern PACKAGE void __fastcall Read_GL_ATI_vertex_array_object(void);
extern PACKAGE void __fastcall Read_GL_ATI_vertex_attrib_array_object(void);
extern PACKAGE void __fastcall Read_GL_ATI_vertex_streams(void);
extern PACKAGE void __fastcall Read_GL_EXT_blend_color(void);
extern PACKAGE void __fastcall Read_GL_EXT_blend_func_separate(void);
extern PACKAGE void __fastcall Read_GL_EXT_blend_minmax(void);
extern PACKAGE void __fastcall Read_GL_EXT_color_subtable(void);
extern PACKAGE void __fastcall Read_GL_EXT_compiled_vertex_array(void);
extern PACKAGE void __fastcall Read_GL_EXT_convolution(void);
extern PACKAGE void __fastcall Read_GL_EXT_coordinate_frame(void);
extern PACKAGE void __fastcall Read_GL_EXT_copy_texture(void);
extern PACKAGE void __fastcall Read_GL_EXT_cull_vertex(void);
extern PACKAGE void __fastcall Read_GL_EXT_draw_range_elements(void);
extern PACKAGE void __fastcall Read_GL_EXT_fog_coord(void);
extern PACKAGE void __fastcall Read_GL_EXT_framebuffer_object(void);
extern PACKAGE void __fastcall Read_GL_EXT_histogram(void);
extern PACKAGE void __fastcall Read_GL_EXT_index_func(void);
extern PACKAGE void __fastcall Read_GL_EXT_index_material(void);
extern PACKAGE void __fastcall Read_GL_EXT_multi_draw_arrays(void);
extern PACKAGE void __fastcall Read_GL_EXT_multisample(void);
extern PACKAGE void __fastcall Read_GL_EXT_paletted_texture(void);
extern PACKAGE void __fastcall Read_GL_EXT_pixel_transform(void);
extern PACKAGE void __fastcall Read_GL_EXT_point_parameters(void);
extern PACKAGE void __fastcall Read_GL_EXT_polygon_offset(void);
extern PACKAGE void __fastcall Read_GL_EXT_secondary_color(void);
extern PACKAGE void __fastcall Read_GL_EXT_stencil_two_side(void);
extern PACKAGE void __fastcall Read_GL_EXT_subtexture(void);
extern PACKAGE void __fastcall Read_GL_EXT_texture3D(void);
extern PACKAGE void __fastcall Read_GL_EXT_texture_object(void);
extern PACKAGE void __fastcall Read_GL_EXT_texture_perturb_normal(void);
extern PACKAGE void __fastcall Read_GL_EXT_vertex_array(void);
extern PACKAGE void __fastcall Read_GL_EXT_vertex_shader(void);
extern PACKAGE void __fastcall Read_GL_EXT_vertex_weighting(void);
extern PACKAGE void __fastcall Read_GL_EXT_depth_bounds_test(void);
extern PACKAGE void __fastcall Read_GL_EXT_blend_equation_separate(void);
extern PACKAGE void __fastcall Read_GL_EXT_stencil_clear_tag(void);
extern PACKAGE void __fastcall Read_GL_HP_image_transform(void);
extern PACKAGE void __fastcall Read_GL_IBM_multimode_draw_arrays(void);
extern PACKAGE void __fastcall Read_GL_IBM_vertex_array_lists(void);
extern PACKAGE void __fastcall Read_GL_INGR_blend_func_separate(void);
extern PACKAGE void __fastcall Read_GL_INTEL_parallel_arrays(void);
extern PACKAGE void __fastcall Read_GL_MESA_resize_buffers(void);
extern PACKAGE void __fastcall Read_GL_MESA_window_pos(void);
extern PACKAGE void __fastcall Read_GL_NV_evaluators(void);
extern PACKAGE void __fastcall Read_GL_NV_fence(void);
extern PACKAGE void __fastcall Read_GL_NV_fragment_program(void);
extern PACKAGE void __fastcall Read_GL_NV_half_float(void);
extern PACKAGE void __fastcall Read_GL_NV_occlusion_query(void);
extern PACKAGE void __fastcall Read_GL_NV_pixel_data_range(void);
extern PACKAGE void __fastcall Read_GL_NV_point_sprite(void);
extern PACKAGE void __fastcall Read_GL_NV_primitive_restart(void);
extern PACKAGE void __fastcall Read_GL_NV_register_combiners(void);
extern PACKAGE void __fastcall Read_GL_NV_register_combiners2(void);
extern PACKAGE void __fastcall Read_GL_NV_vertex_array_range(void);
extern PACKAGE void __fastcall Read_GL_NV_vertex_program(void);
extern PACKAGE void __fastcall Read_GL_PGI_misc_hints(void);
extern PACKAGE void __fastcall Read_GL_SGIS_detail_texture(void);
extern PACKAGE void __fastcall Read_GL_SGIS_fog_function(void);
extern PACKAGE void __fastcall Read_GL_SGIS_multisample(void);
extern PACKAGE void __fastcall Read_GL_SGIS_pixel_texture(void);
extern PACKAGE void __fastcall Read_GL_SGIS_point_parameters(void);
extern PACKAGE void __fastcall Read_GL_SGIS_sharpen_texture(void);
extern PACKAGE void __fastcall Read_GL_SGIS_texture4D(void);
extern PACKAGE void __fastcall Read_GL_SGIS_texture_color_mask(void);
extern PACKAGE void __fastcall Read_GL_SGIS_texture_filter4(void);
extern PACKAGE void __fastcall Read_GL_SGIX_async(void);
extern PACKAGE void __fastcall Read_GL_SGIX_flush_raster(void);
extern PACKAGE void __fastcall Read_GL_SGIX_fragment_lighting(void);
extern PACKAGE void __fastcall Read_GL_SGIX_framezoom(void);
extern PACKAGE void __fastcall Read_GL_SGIX_igloo_interface(void);
extern PACKAGE void __fastcall Read_GL_SGIX_instruments(void);
extern PACKAGE void __fastcall Read_GL_SGIX_list_priority(void);
extern PACKAGE void __fastcall Read_GL_SGIX_pixel_texture(void);
extern PACKAGE void __fastcall Read_GL_SGIX_polynomial_ffd(void);
extern PACKAGE void __fastcall Read_GL_SGIX_reference_plane(void);
extern PACKAGE void __fastcall Read_GL_SGIX_sprite(void);
extern PACKAGE void __fastcall Read_GL_SGIX_tag_sample_buffer(void);
extern PACKAGE void __fastcall Read_GL_SGI_color_table(void);
extern PACKAGE void __fastcall Read_GL_SUNX_constant_data(void);
extern PACKAGE void __fastcall Read_GL_SUN_global_alpha(void);
extern PACKAGE void __fastcall Read_GL_SUN_mesh_array(void);
extern PACKAGE void __fastcall Read_GL_SUN_triangle_list(void);
extern PACKAGE void __fastcall Read_GL_SUN_vertex(void);
extern PACKAGE void __fastcall Read_WGL_ARB_buffer_region(void);
extern PACKAGE void __fastcall Read_WGL_ARB_extensions_string(void);
extern PACKAGE void __fastcall Read_WGL_ARB_make_current_read(void);
extern PACKAGE void __fastcall Read_WGL_ARB_pbuffer(void);
extern PACKAGE void __fastcall Read_WGL_ARB_pixel_format(void);
extern PACKAGE void __fastcall Read_WGL_ARB_pixel_format_float(void);
extern PACKAGE void __fastcall Read_WGL_ARB_render_texture(void);
extern PACKAGE void __fastcall Read_WGL_EXT_display_color_table(void);
extern PACKAGE void __fastcall Read_WGL_EXT_extensions_string(void);
extern PACKAGE void __fastcall Read_WGL_EXT_make_current_read(void);
extern PACKAGE void __fastcall Read_WGL_EXT_pbuffer(void);
extern PACKAGE void __fastcall Read_WGL_EXT_pixel_format(void);
extern PACKAGE void __fastcall Read_WGL_EXT_swap_control(void);
extern PACKAGE void __fastcall Read_WGL_I3D_digital_video_control(void);
extern PACKAGE void __fastcall Read_WGL_I3D_gamma(void);
extern PACKAGE void __fastcall Read_WGL_I3D_genlock(void);
extern PACKAGE void __fastcall Read_WGL_I3D_image_buffer(void);
extern PACKAGE void __fastcall Read_WGL_I3D_swap_frame_lock(void);
extern PACKAGE void __fastcall Read_WGL_I3D_swap_frame_usage(void);
extern PACKAGE void __fastcall Read_WGL_NV_vertex_array_range(void);
extern PACKAGE void __fastcall Read_WGL_OML_sync_control(void);
extern PACKAGE void __fastcall Read_WIN_draw_range_elements(void);
extern PACKAGE void __fastcall Read_WIN_swap_hint(void);
extern PACKAGE void __fastcall Read_GL_ARB_Shader_Objects(void);
extern PACKAGE void __fastcall Read_GL_ARB_occlusion_query(void);
extern PACKAGE void __fastcall ReadExtensions(void);
extern PACKAGE void __fastcall ReadImplementationProperties(void);
extern PACKAGE HGLRC __fastcall CreateRenderingContext(HDC DC, TRCOptions Options, int ColorBits, int ZBits, int StencilBits, int AccumBits, int AuxBuffers, int Layer);
extern PACKAGE void __fastcall ActivateRenderingContext(HDC DC, HGLRC RC, bool loadext = true);
extern PACKAGE void __fastcall DeactivateRenderingContext(void);
extern PACKAGE void __fastcall DestroyRenderingContext(HGLRC RC);

}	/* namespace Dglopengl */
using namespace Dglopengl;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dglopengl
