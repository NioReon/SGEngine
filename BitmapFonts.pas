unit BitmapFonts;

interface
Uses OpenGL, Windows, SysUtils;
{$R+ Q+ O-}
Var Base: GLUint;
    //GMF: array [0..255] of PGlyphMetricsFloat;

Procedure BuildFont (DC: HDC{; Scale: double});
Procedure DestroyFont;
Procedure OutText(text: string{; Texture: GLUint; Zoom, x, y, z: double});
Procedure glBindTexture(target: GLenum; texture: GLuint); stdcall; external opengl32;

implementation

Procedure BuildFont (DC: HDC{; Scale: double});
Var OldFont, Font: HFont;

begin
    Base := glGenLists (96);
    Font := CreateFont ( -20,                           //высота
                         0,                             //ширина
                         0,                             //угол отношения
                         0,                             //угол наклона
                         FW_NORMAL,                       //ширина шрифта
                         0,                         //курсив
                         0,                         //подчёркивание
                         0,                         //перечёркивание
                         ANSI_CHARSET,                  //Идентификатор набора символов
                         OUT_TT_PRECIS,                 //точность вывода (TrueType)
                         CLIP_DEFAULT_PRECIS,           //точность отсечения
                         ANTIALIASED_QUALITY,           //качество вывода
                         FF_DONTCARE or DEFAULT_PITCH,  //семейство и шаг
                         'Times New Roman');                //имя используемого шрифта
    OldFont := SelectObject (DC, Font);
    glColor3F (1.0, 1.0, 1.0);
    wglUseFontBitmaps(DC, 32, 96, 33);
    SelectObject (DC, OldFont);
    DeleteObject (Font);
end;

Procedure DestroyFont;
begin
    glDeleteLists(base, 96);        // Удаление всех 96 списков отображения
end;

Procedure OutText(text: string{; Texture: GLUint; Zoom, x, y, z: double});
begin
  if text = '' then exit;
  //glBindTexture (GL_TEXTURE_2D, Texture);
  glColor3F (1,1,1);
  glRasterPos (0, 0);
  glPushAttrib (GL_LIST_BIT);
  glListBase (base);
  glCallLists (length(text), GL_UNSIGNED_BYTE, Pchar(text));
  glPopAttrib;
end;
end.
