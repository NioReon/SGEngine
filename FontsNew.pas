unit FontsNew;

interface
uses OpenGl, Windows, PhysicsArifm;

Procedure TextCreate(DC:HDC; Enable3D: boolean);
Procedure TextGetSymbols(DC: HDC);
Procedure TextDraw (const Text: string; const ScreenResolutionX, ScreenResolutionY: Float;
    const Pos, Scale, Rotation: TVector3);

implementation
var
Font: TLOGFONT;
List:DWord;
T3d:boolean;
Depth:single;

procedure TextGetSymbols(DC: HDC);
var hFontNew, hOldFont : HFONT;
begin
 hFontNew := CreateFontIndirect(Font);
 hOldFont := SelectObject(DC,hFontNew);

 if t3d
 then
 wglUseFontOutlines(DC, 0, 255, LIST, 0, Depth, 1, nil)
 else
 wglUseFontBitmaps (DC, 0, 255, LIST);

 DeleteObject(SelectObject(DC,hOldFont));
 DeleteObject(SelectObject(DC,hFontNew));
end;

procedure TextCreate(DC:HDC; Enable3D: boolean);
begin
 FillChar(Font, SizeOf(Font), 0);
 Font.lfHeight               :=   -28 ;
 Font.lfWeight               :=   FW_NORMAL ;
 Font.lfCharSet              :=   ANSI_CHARSET ;
 Font.lfOutPrecision         :=   OUT_DEFAULT_PRECIS ;
 Font.lfClipPrecision        :=   CLIP_DEFAULT_PRECIS ;
 Font.lfQuality              :=   DEFAULT_QUALITY ;
 Font.lfPitchAndFamily       :=   FF_DONTCARE OR DEFAULT_PITCH;
 lstrcpy (Font.lfFaceName, 'Arial') ;
 T3D:=Enable3D;
 Depth:=0;
 List:=glGenLists(1);
 TextGetSymbols(DC);
end;

Procedure TextDraw (const Text: string; const ScreenResolutionX, ScreenResolutionY: Float;
    const Pos, Scale, Rotation: TVector3);
begin
    {Установим рисование на фронтальную плоскость экрана через ортогональную проекцию}
    glMatrixMode (GL_PROJECTION);
    glPushMatrix;
    glLoadIdentity;
    gluOrtho2D (0, 0, ScreenResolutionX, ScreenResolutionY);

    glMatrixMode (GL_MODELVIEW);
    glPushMatrix;
    glLoadIdentity;

    {Сместимся на позицию текста}
    glTranslatef(pos.x,pos.y,pos.z);
    {Отмасштабируем текст и повернём его}
    glScalef(scale.x,scale.y,scale.z);
    glRotatef(rotation.x,1,0,0);
    glRotatef(-rotation.z,0,0,1);
    glRotatef(rotation.y,0,1,0);

    {Выведем текст на экран}
    glListBase(LIST);
    glCallLists(Length (Text), GL_UNSIGNED_BYTE, PChar(Text));

    glMatrixMode (GL_PROJECTION);
    glPopMatrix;
    glMatrixMode (GL_MODELVIEW);
    glPopMatrix;
end;

end.
