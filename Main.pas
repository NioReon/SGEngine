unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, _Shader, dglOpenGL, MapStructure, Cameras, PhysicsArifm, FontsNew,
  BitmapFonts, Textures, Math, ExtCtrls, AppEvnts, ParticleWorldStructure, SpawnScripts,
  ParticleForceGen, PhysicsParticles, PhysicsRigidBody, RigidBodyContacts, RigidBodyForceGen, ShadowCaster;

type
    TShittyGameEngine = class(TForm)
        FPSTimer: TTimer;
        ShittyGameEngineEvents: TApplicationEvents;
        procedure FormCreate(Sender: TObject);
        procedure FormResize(Sender: TObject);
        procedure FPSTimerTimer(Sender: TObject);
        procedure FormDestroy(Sender: TObject);
        procedure ShittyGameEngineEventsIdle(Sender: TObject; var Done: Boolean);
        procedure FormKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
        procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure FormMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure FormMouseWheel(Sender: TObject; Shift: TShiftState;
      WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
    procedure FormMouseWheelDown(Sender: TObject; Shift: TShiftState;
      MousePos: TPoint; var Handled: Boolean);
      private
      { Private declarations }
      public
      { Public declarations }
        PWorldStruc: TParticleWorldStruc;
        WorldStruc: TWorldStruc;
        UseShaders: boolean;
        Shaders: array of glHandleARB;
        VVBO: GLUInt;    //вершины
        NVBO: GLUInt;    //нормали
        TCVBO: GLUInt;    //текстурные координаты
        CVBO: GLUInt;    //цвет
    end;

    TGraphics = array of GLUint;

    TFPSCounter = record     //подсчёт числа кадров за секунду
                   DemoStart,
                   LastTime: Cardinal;
                   FPSCount,
                   ElapsedTime,
                   FrameTime: Cardinal;
               end;

    TFogSettings = record
        Density: Double;                 //плотность тумана
        Colour: array [0..3] of Double;  //цвет тумана
        FogStartDistance: Double;        //дистанция начала тумана
        FogEndDistance: Double;          //дистанция конца тумана
    end;

Const PiOver180 = 0.0174532925;
      PLAYERHEIGHT = 0.75;     //Высота игрока и, соответственно, камеры
      ModelZoom = 0.01;  //Для корректного отображения модели
      MAX_CAM_ZOOM = 2.5;  //Наибольшее увеличение камеры
      MIN_CAM_ZOOM = 0.1;
      ZOOM_SPEED = 0.05;
      MaxDT: Float = 0.05;
      IterationsCount = 10;
      SpringColor: TGLArray4ub = (255, 0, 0, 255);
      BungeeSpringColor: TGLArray4ub = (0, 255, 255, 255);
      AnchoredSpringColor: TGLArray4ub = (0, 0, 255, 255);

var
    MapGraphics, MonsterGraphics: TGraphics; {Текстуры игрока}
    MoveSpeed: Single = 0.04;
    MouseSpeed: Single = 7;  {"чувствительность" мыши}
    Paused: boolean;    //поставлена ли симуляция на паузу
    ShowDolbagInfo: boolean = true;   {показывать ли отладочную информацию}
    Keys: array [0..255] of boolean;

    WorldMap: array of TSector;     {массив секторов мира}
    Blend: boolean;    {включить ли смешивание текстур}

    AmbientLight : TGlArrayf4 = (0.5,0.5,0.5,1.0);      {параметры источников освещения}
    DiffuseLight : TGlArrayf4 = (1.0,1.0,1.0,1.0);
    SpecularLight : TGlArrayf4 = (1.0,1.0,1.0,1.0);
    SpecularReflection : TGlArrayf4 = (0.4,0.4,0.4,1.0);
    LightPosition : TGlArray4f;
    FPSCounter: TFPSCounter;
    Camera: TCamera;   {Наша камера}
    FogParams: TFogSettings;

    DC: HDC;
    HRC: HGLRC;
    Dt: Single = 0.01;

    CurrentWeapon: Word = 0;
    BulletSpeed: Float = 5;

    OneSimulation:Integer=0;
var
  ShittyGameEngine: TShittyGameEngine;

implementation

{$R *.dfm}

Procedure LoadShaders;
begin
    With ShittyGameEngine do
    begin
        SetLength (Shaders, 3);
        Shaders[0] := _Shader.LoadShaderFromFile('shaders\gourand.vert', GL_VERTEX_SHADER_ARB);
        Shaders[1] := _Shader.LoadShaderFromFile('shaders\gourand.frag', GL_FRAGMENT_SHADER_ARB);
        Shaders[2] := _Shader.LinkPrograms ([Shaders[0], Shaders[1]]);
    end;
end;

Procedure InitVBOs;
Var Count: Integer;
begin
    Count := High (WorldMap[0].Vertexs) + 1;
    glGenBuffers( 1, @ShittyGameEngine.VVBO);
    glBindBuffer(GL_ARRAY_BUFFER, ShittyGameEngine.VVBO);
    glBufferData(GL_ARRAY_BUFFER, 3*sizeof(GLFloat)*Count, @WorldMap[0].Vertexs[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);

    glGenBuffers (1, @ShittyGameEngine.NVBO);
    glBindBuffer(GL_ARRAY_BUFFER, ShittyGameEngine.NVBO);
    glBufferData(GL_ARRAY_BUFFER, 2*sizeof(GLFloat)*Count, @WorldMap[0].Normals[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);

    glGenBuffers (1, @ShittyGameEngine.TCVBO);
    glBindBuffer(GL_ARRAY_BUFFER, ShittyGameEngine.TCVBO);
    glBufferData(GL_ARRAY_BUFFER, 2*sizeof(GLFloat)*Count, @WorldMap[0].TextureCoords[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);

{    For I := 0 to 7 do
        glUniform1iARB(shader_myTexture[i], i);

    For I := 0 to 7 do
    begin
        glActiveTexture (GL_TEXTURE0 + i);
      	glBindTexture (GL_TEXTURE_2D, i + 1);
    end;}
end;

Procedure OpenGL_Init;
begin
    DecimalSeparator := '.';
    SetCursorPos (ShittyGameEngine.ClientHeight div 2, ShittyGameEngine.ClientHeight div 2);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLoadIdentity;
    ShittyGameEngine.Resize;
    glEnable(GL_COLOR_MATERIAL);
    glClearDepth (1.0);
    glEnable(GL_DEPTH_TEST);        
    glDepthFunc (GL_LESS);
    glEnable (GL_TEXTURE_2D);
    glShadeModel (GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable (GL_NORMALIZE);
    {Освещение}
    glEnable (GL_LIGHTING);
    glLightfv (GL_LIGHT0, GL_AMBIENT, @AmbientLight);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, @DiffuseLight);
    glLightfv (GL_LIGHT0, GL_SPECULAR, @SpecularLight);
    glEnable (GL_LIGHT0);
    LightPosition[0] := 0.0;
    LightPosition[1] := 100.0;
    LightPosition[2] := 0.0;
    LightPosition[3] := 1.0;
    glLightfv (GL_LIGHT0, GL_POSITION, @LightPosition);
    glEnable (GL_COLOR_MATERIAL);
    glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv (GL_FRONT, GL_SPECULAR, @SpecularReflection);
    glMateriali (GL_FRONT, GL_SHININESS, 10);
    {Включить обрезку невидимых поверхностей}
    glCullFace (GL_FRONT_AND_BACK);
    {Создать шрифт}
    TextCreate (GetDC (ShittyGameEngine.Handle), True);
    {Инициализировать счётчик кадров}
    FPSCounter.FPSCount := 100;
    FPSCounter.DemoStart := GetTickCount;
    FPSCounter.LastTime := 0;
    FPSCounter.ElapsedTime := 0;
    FPSCounter.FrameTime := 0;
    ShowCursor (False);
    {Туман}
    glEnable(GL_FOG);
    FogParams.Density := 0.05;
    FogParams.Colour[0] := 0;
    FogParams.Colour[1] := 0;
    FogParams.Colour[2] := 1;
    FogParams.Colour[3] := 0;
    FogParams.FogStartDistance := 0.1;
    FogParams.FogEndDistance := 50;
    glFogi(GL_FOG_MODE, GL_EXP2);
    glFogfv(GL_FOG_COLOR, @FogParams.Colour);
    glFogf(GL_FOG_DENSITY, FogParams.Density);
    glHint(GL_FOG_HINT, GL_DONT_CARE);
    glFogf(GL_FOG_START, FogParams.FogStartDistance);
    glFogf(GL_FOG_END, FogParams.FogEndDistance);
end;

{################## ЗАГРУЗКА КАРТЫ #################################}

procedure ReadStr(var f: textfile; var s: string);
begin
  readln(f,s);
  while ((copy(s, 1, 1) = '/') or (length(s) = 0)) do
    readln(f,s);
end;

Function ReadVertex (S: String): TTriangleVertex;
Var I: word;
begin
    S := Trim (S);
    I := Pos (' ', S);
    Result.Vertex.x := StrToFloat (Trim (Copy (S, 1, I)));
    Delete (S, 1, I);
    I := Pos (' ', S);
    Result.Vertex.y := StrToFloat (Trim (Copy (S, 1, I)));
    Delete (S, 1, I);
    I := Pos (' ', S);
    Result.Vertex.z := StrToFloat (Trim (Copy (S, 1, I)));
    Delete (S, 1, I);
    I := Pos (' ', S);
    Result.TextureCoord.x := StrToFloat (Trim (Copy (S, 1, I)));
    Delete (S, 1, I);
    Result.TextureCoord.y := StrToFloat (Trim (S));
end;

procedure LoadMap (const WorldFileName: string = 'maps\world.dat');
var
  numtriangles: integer;               //Количество четырёхугольников
  F: textfile;                         //Ссылка на файл карты
  oneline: string;                     //Буфер чтения
  TextureCount: word;                  //число текстур, используемых в нашей карте
  Textures: array of string;           //Массив с "переменными" - путями к текстурам
  loop, i, vert, TempCounter: word;    //Счётчики
  TempPoint: TTriangleVertex;
  TempTrianglesCount: Integer;
  TempNormal: TVector3;                //текущая нормаль к полигону
begin
    AssignFile(F, WorldFileName);
    Reset(F);
    Readstr(F, oneline);
    Delete(oneline, 1, 11);
    numtriangles := StrToIntDef(oneline, 0);
    Readstr(F, oneline);
    TextureCount := StrToInt (Copy (OneLine, 1, (Pos (' ', OneLine) - 1)));
    SetLength (Textures, TextureCount);
    SetLength (MapGraphics, TextureCount);
    For I := 0 to (TextureCount - 1) do
    begin
        Readln(F, OneLine);
        Textures[i]:=Copy (OneLine, 1, Pos (' ', OneLine) - 1);
        OneLine := Copy (OneLine, Pos(' ', OneLine) + 1, length (OneLine));
        Insert ('Data\Textures\', OneLine, 1);
        LoadTexture (OneLine, MapGraphics[i], FALSE);
    end;
    SetLength (WorldMap, 1);
    TempTrianglesCount := NumTriangles * 3;
    SetLength(WorldMap[0].Vertexs, TempTrianglesCount);
    SetLength(WorldMap[0].TextureCoords, TempTrianglesCount);
    SetLength (WorldMap[0].Normals, TempTrianglesCount);
    SetLength (WorldMap[0].Colors, TempTrianglesCount);
    SetLength (WorldMap[0].Texturez, TempTrianglesCount);
    WorldMap[0].numtriangles := NumTriangles;
    For Loop := 0 to NumTriangles - 1 do
    With WorldMap[0] do
    begin
        TempCounter := Loop * 3;
        {Заполнить координаты вершин и текстурные координаты}
        For Vert := 0 to 2 do
        begin
            Readstr(F, oneline);
            TempPoint := ReadVertex (OneLine);
            Vertexs[TempCounter + Vert] := TempPoint.Vertex;
            TextureCoords[TempCounter + Vert] := TempPoint.TextureCoord;
        end;
            {Заполнить данные нормалей}
        TempNormal := GetNormalToPlane (V3 (Vertexs[TempCounter].X, Vertexs[TempCounter].Y, Vertexs[TempCounter].Z),
                                        V3 (Vertexs[TempCounter + 1].X, Vertexs[TempCounter + 1].Y, Vertexs[TempCounter + 1].Z),
                                        V3 (Vertexs[TempCounter + 2].X, Vertexs[TempCounter + 2].Y, Vertexs[TempCounter + 2].Z));
        For Vert := 0 to 2 do
        begin
            Normals[TempCounter + Vert].X := TempNormal.X;
            Normals[TempCounter + Vert].Y := TempNormal.Y;
            Normals[TempCounter + Vert].Z := TempNormal.Z;
        end;

        ReadStr (F, OneLine);
        OneLine := Trim (Copy (OneLine, 1, 12));
        For I := 0 to (TextureCount - 1) do
            If Textures [i] = OneLine then
            begin
                For Vert := 0 to 2 do
                    Texturez[TempCounter + Vert] := i;
                Break;
            end;
    end;
    CloseFile(F);
end;

Procedure InitObjects;
Var I: integer;
    Body: TRigidBody;
begin
    With ShittyGameEngine.PWorldStruc do
    begin
        RunSSL (LoadSSL ('.\spawnscripts\particlerain.ssl'), ShittyGameEngine.PWorldStruc);

        For I := 0 to High (Particles) do
            Registrations.AddEntry(Particles[i], Generators.Force.Gravity[0]);
    end;

    With ShittyGameEngine.WorldStruc do
    begin
        Body := TRigidBody.Create(Quaternion (1, 0, 0, 0), V3 (0), V3 (0), V3 (0), V3 (0), false, true,
            0.99, 0.99, 50, '.\objects\cube\cube.txt');
        AddBody (Body, true);
        Body := TRigidBody.Create(Quaternion (1, 0, 0, 0), V3 (0), V3 (0), V3 (0), V3 (0), false, true,
            0.99, 0.99, 50, '.\objects\cube\cube2.txt');
        AddBody (Body, true);
    end;
end;

{############### ОТЛАДОЧНАЯ ИНФОРМАЦИЯ #############################}
Procedure DrawInfo;
begin
    glMatrixMode (GL_PROJECTION);
    glPushMatrix;
    glLoadIdentity;
    gluOrtho2D (0, 0, ShittyGameEngine.ClientWidth, ShittyGameEngine.ClientHeight);

    glMatrixMode (GL_MODELVIEW);
    glPushMatrix;
    glLoadIdentity;
    {Нарисовать курсор}
    glLineWidth(2);
    glColor3ub (255, 255, 255);
    glBegin(gl_Lines);
      glVertex3f(0.02, 0, 0);
      glVertex3f(-0.02, 0, 0);
    glEnd;
    glBegin(gl_Lines);
      glVertex3f(0, 0.02, 0);
      glVertex3f(0, -0.02, 0);
    glEnd;
    glLineWidth(1);

    glMatrixMode (GL_PROJECTION);
    glPopMatrix;
    glMatrixMode (GL_MODELVIEW);
    glPopMatrix;
    
    {Вывести текст}
    With ShittyGameEngine do
    begin
        TextDraw ('Camera.Position.x: ' + FloatToStr (camera.Position.X),
            ClientWidth, ClientHeight, V3 (-1, 0, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Camera.Position.y: ' + FloatToStr (camera.Position.Y),
            ClientWidth, ClientHeight, V3 (-1, 0.05, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Camera.Position.z: ' + FloatToStr (camera.Position.Z),
            ClientWidth, ClientHeight, V3 (-1, 0.1, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Camera.LookDirection.x: ' + FloatToStr (camera.LookDirection.X),
            ClientWidth, ClientHeight, V3 (-1, 0.15, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Camera.LookDirection.y: ' + FloatToStr (camera.LookDirection.Y),
            ClientWidth, ClientHeight, V3 (-1, 0.2, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Camera.LookDirection.z: ' + FloatToStr (camera.LookDirection.Z),
            ClientWidth, ClientHeight, V3 (-1, 0.25, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('UseShaders: ' + BoolToStr (UseShaders),
            ClientWidth, ClientHeight, V3 (-1, 0.3, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Spheres Rendered: ' + IntToStr (Length (PWorldStruc.Particles)),
            ClientWidth, ClientHeight, V3 (-1, 0.35, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Dt: ' + FloatToStr(Dt),
            ClientWidth, ClientHeight, V3 (-1, 0.40, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Cube XYZ: '+floattostr(WorldStruc.Bodies[0].Position.x)+' '+floattostr(WorldStruc.Bodies[0].Position.y)+' '+floattostr(WorldStruc.Bodies[0].Position.z),
            ClientWidth, ClientHeight, V3 (-1, 0.45, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Cube Velocity(Components): '+floattostr(WorldStruc.Bodies[0].Velocity.x)+' '+floattostr(WorldStruc.Bodies[0].Velocity.y)+' '+floattostr(WorldStruc.Bodies[0].Velocity.z),
            ClientWidth, ClientHeight, V3 (-1, 0.50, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Cube Velocity(Absolute): '+floattostr(Sqrt(Power(WorldStruc.Bodies[0].Velocity.x,2)+power(WorldStruc.Bodies[0].Velocity.y,2)+power(WorldStruc.Bodies[0].Velocity.z,2))),
            ClientWidth, ClientHeight, V3 (-1, 0.55, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Cube Force(Components): '+floattostr(WorldStruc.Bodies[0].ForceAccumulator.x)+' '+floattostr(WorldStruc.Bodies[0].ForceAccumulator.y)+' '+floattostr(WorldStruc.Bodies[0].ForceAccumulator.z),
            ClientWidth, ClientHeight, V3 (-1, 0.60, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Cube Force(Absolute): '+floattostr(Sqrt(Power(WorldStruc.Bodies[0].ForceAccumulator.x,2)+power(WorldStruc.Bodies[0].ForceAccumulator.y,2)+power(WorldStruc.Bodies[0].ForceAccumulator.z,2))),
            ClientWidth, ClientHeight, V3 (-1, 0.65, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));
        TextDraw ('Cube Acceleration (Absolute)'+floattostr(Sqrt(Power(WorldStruc.Bodies[0].Acceleration.x,2)+power(WorldStruc.Bodies[0].Acceleration.y,2)+power(WorldStruc.Bodies[0].Acceleration.z,2))),ClientWidth, ClientHeight, V3 (-1, 0.70, 0), V3 (0.03, 0.03, 0.03), V3 (0, 0, 0));

    end;
end;

{############################## ОТРИСОВКА ###################################}
Procedure DrawVBOs;
Var Count, CountOver3, I: Integer;
    CurrentTexture: GLUint;
begin
    Count := High (WorldMap[0].Vertexs);
    CountOver3 := Count div 3;
    glBindTexture (GL_TEXTURE_2D, MapGraphics[4]);
    glEnableClientState( GL_NORMAL_ARRAY );
    glBindBuffer( GL_ARRAY_BUFFER, ShittyGameEngine.NVBO);
    glNormalPointer(GL_FLOAT, 0, nil );

    glEnableClientState( GL_TEXTURE_COORD_ARRAY );
    glBindBuffer( GL_ARRAY_BUFFER, ShittyGameEngine.TCVBO);
    glTexCoordPointer(2, GL_FLOAT, 0, nil );

    glEnableClientState (GL_VERTEX_ARRAY);
    glBindBuffer (GL_ARRAY_BUFFER, ShittyGameEngine.VVBO);
    glVertexPointer (3, GL_FLOAT, 0, nil);

    CurrentTexture := 0;
    glActiveTextureARB (GL_TEXTURE0);
    For I := 0 to CountOver3 do
    With WorldMap[0] do
    begin
        Count := I * 3;
        If I = CountOver3 then Dec (Count);
        If CurrentTexture <> Texturez [Count] then
        begin
            CurrentTexture := Texturez [Count];
            glBindTexture (GL_TEXTURE_2D, CurrentTexture);
        end;
        glDrawArrays (GL_TRIANGLES, Count, 3);
    end;
    glBindBuffer (GL_ARRAY_BUFFER, 0);

    glDisableClientState (GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
end;

Procedure DrawGLScene;
begin
    glUseProgramObjectARB (0);
    DrawInfo;
    glLineWidth(2);
    glColor3ub (255, 255, 255);
    glBegin(gl_Lines);
      glVertex3f(0.02, 0, 0);
      glVertex3f(-0.02, 0, 0);
    glEnd;
    glBegin(gl_Lines);
      glVertex3f(0, 0.02, 0);
      glVertex3f(0, -0.02, 0);
    glEnd;
    glLineWidth(1);

{    glLightfv (GL_LIGHT0, GL_POSITION, @LightPosition);}

    If ShittyGameEngine.UseShaders then glUseProgramObjectARB (ShittyGameEngine.Shaders[2]);
{    For I := 0 to Length (WorldMap[0].Triangles) - 1 do
    begin
        glBindTexture (GL_TEXTURE_2D, MapGraphics [WorldMap[0].Triangles[i].Texture]);
        glBegin (GL_TRIANGLES);
            glNormal3F (0.0, 0.0, 1.0);
            With WorldMap[0].Triangles[I].Vertexs[0] do
            begin
                glTexCoord2F (u, v);
                glVertex3F (Position.x, Position.y, Position.z);
            end;
            With WorldMap[0].Triangles[I].Vertexs[1] do
            begin
                glTexCoord2F (u, v);
                glVertex3F (Position.x, Position.y, Position.z);
            end;
            With WorldMap[0].Triangles[I].Vertexs[2] do
            begin
                glTexCoord2F (u, v);
                glVertex3F (Position.x, Position.y, Position.z);
            end;
        glEnd;
    end;}
    DrawVBOs;
end;
Procedure RunPhysics (const DeltaTime: Float; const FullSimCyclesPerFrame: Integer; const WorldSector: TSector);
begin
    ShittyGameEngine.PWorldStruc.Simulate (DeltaTime, FullSimCyclesPerFrame, WorldSector);
    ShittyGameEngine.WorldStruc.Simulate(WorldSector, DeltaTime);
end;
Procedure ProcessKeyboard;
Var TmpMul: Single;
    TmpSin, TmpCos: Extended;
    I: Integer;
begin
    TmpMul := 300 * Dt;
    SinCos ((Camera.HeadingAngle - 90) * PiOver180, TmpSin, TmpCos);
    If Keys [VK_ESCAPE] then Application.Terminate;
    if (keys[ord('B')]) then
    begin
        blend := not(blend);
        if (blend) then
        begin
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        end
        else
        begin
            glDisable(GL_BLEND);
        end;
    end;
    if (keys[Ord ('W')]) then
    begin
        If not (Keys[Ord ('S')]) then
            Camera.Update(dvForward, -MoveSpeed * TmpMul);
    end;
    if (keys[Ord ('S')]) then
    begin
        If not (Keys[Ord ('W')]) then
            Camera.Update(dvBackward, -MoveSpeed * TmpMul);
    end;
    if (keys[Ord ('D')]) then
    begin
        If not (Keys[Ord ('A')]) then
            Camera.Update(dvRight, -MoveSpeed * TmpMul);
    end;
    if (keys[Ord ('A')]) then
    begin
        If not (Keys[Ord ('D')]) then
            Camera.Update(dvLeft, -MoveSpeed * TmpMul);
    end;
    if (keys[VK_SPACE]) then
    begin
        Camera.Position.Y := Camera.Position.Y + 0.03 * TmpMul;
    end;
    if keys[VK_CONTROL]
    then Camera.Position.Y := Camera.Position.Y - 0.03 * TmpMul;

    if (Keys[ord('N')])and(OneSimulation=0)
    then
    begin
      RunPhysics (0.01, 1, WorldMap[0]);
      OneSimulation:=1;
    end;

    if Keys[ord('M')]
    then OneSimulation:=0;

    If Keys[Ord ('H')] then ShittyGameEngine.UseShaders := not ShittyGameEngine.UseShaders;

    If Keys [Ord ('1')]
    then CurrentWeapon := 0;
    If Keys [Ord ('2')]
    then CurrentWeapon := 1;
    If ((GetKeyState (VK_LSHIFT) and $8000) <> 0) then
    begin
        MoveSpeed := 0.04;
    end else
    begin
        MoveSpeed := 0.01;
    end;

    Paused := not Keys [Ord ('P')];

    If Keys [Ord ('R')] then
    begin
        FreeAndNil (ShittyGameEngine.PWorldStruc);
        With ShittyGameEngine.WorldStruc do
        begin
            Registry.ClearEntries;
            For I := High (Bodies) downto 0 do
                If Assigned (Bodies) then FreeAndNil (Bodies[I]);
            SetLength (Bodies, 0);
        end;

        ShittyGameEngine.PWorldStruc := TParticleWorldStruc.Create(200, 100);
        InitObjects;
    end;
end;

Procedure ProcessMouse;
Var MPos: TPoint;
begin
    If GetForeGroundWindow = ShittyGameEngine.Handle then
    begin
        GetCursorPos (MPos);
        With ShittyGameEngine do
        begin
            SetCursorPos (Left + ClientWidth div 2, Top + ClientHeight div 2);
            Camera.HeadingAngle := Camera.HeadingAngle + (mpos.x - (Left + ClientWidth div 2)) / 100 * MouseSpeed;
            Camera.TiltAngle := Camera.TiltAngle - ((Top + ClientHeight div 2) - mpos.y) / 100 * MouseSpeed;
        end;
        If (Camera.TiltAngle > 80) then Camera.TiltAngle := 80;
        If (Camera.TiltAngle < -80) then Camera.TiltAngle := -80;
    end
    else Paused := true;
end;



Procedure Shoot (const Mass, Speed: Float);
Var Bullet: TParticle;
begin
    Bullet := TParticle.Create(Camera.Position,
                               V3Mul (Camera.LookDirection, -Speed),
                               V3Mul (Gravity, Mass),
                               0,
                               Mass,
                               0.1);
    With ShittyGameEngine.PWorldStruc do
        AddParticle (Bullet, true);
end;

{###############################################################################
#######################  ГЛАВНАЯ ЦИКЛИЧЕСКАЯ ПОДПРОГРАММА  #####################
###############################################################################}

Procedure TimerProc;
Const SpringColor: TGLArray4ub = (1, 0, 0, 0);
      BungeeColor: TGLArray4ub = (0, 1, 0, 0);
      AnchoredSpringColor: TGLArray4ub = (1, 1, 0, 0);
Var   Lights: TGLArray4fs;
begin
    //Очистить экран, буферы цвета и глубины
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT xor GL_DEPTH_BUFFER_BIT);

    DrawInfo;
    //Разместить необходимым образом камеру
    glLoadIdentity;
    Camera.Update;

    //Проанализировать средства ввода
    ProcessKeyboard;
    ProcessMouse;

    //Рассчитать FPS
    Inc (FPSCounter.FPSCount);
    FPSCounter.FrameTime := GetTickCount - FPSCounter.ElapsedTime - FPSCounter.DemoStart;
    FPSCounter.LastTime := FPSCounter.ElapsedTime;
    FPSCounter.ElapsedTime := GetTickCount - FPSCounter.DemoStart;
    FPSCounter.ElapsedTime := (FPSCounter.LastTime + FPSCounter.ElapsedTime) div 2;
    //Запустить физику
    If not Paused then RunPhysics (0.01, 10, WorldMap[0]);

    //Отрисовать сцену, частицы, пружины и твёрдые тела
    {DrawGLScene;}
    ShittyGameEngine.PWorldStruc.DrawParticles;
    ShittyGameEngine.PWorldStruc.Registrations.DrawAllSprings(SpringColor,
        BungeeColor, AnchoredSpringColor);
    ShittyGameEngine.WorldStruc.Registry.DrawAllSprings(SpringColor,
        BungeeColor, AnchoredSpringColor);

    SetLength (Lights, 1);
    Lights[0] := LightPosition;
    CastShadowOnWorldPolygon (Lights, ShittyGameEngine.WorldStruc, WorldMap[0]);
    
    ShittyGameEngine.WorldStruc.DrawBodies;

    //Вывести содержимое на экран
    SwapBuffers (DC);
end;

procedure TShittyGameEngine.ShittyGameEngineEventsIdle(Sender: TObject; var Done: Boolean);
begin
    TimerProc;
    Done := false;
end;

procedure TShittyGameEngine.FormCreate(Sender: TObject);
begin
    DC := GetDC (Handle);
    If not InitOpenGL then
        Application.Terminate;
    HRC := CreateRenderingContext (DC, [opDoubleBuffered], 32, 24, 0, 0, 0, 0);
    wglMakeCurrent (DC, HRC);
    ReadExtensions;
    ReadImplementationProperties;
    Camera := TCamera.Create(0, 0, 0, 45, 0.1, 500);
    OpenGL_Init;
    glEnableClientState(GL_VERTEX_ARRAY);
    LoadShaders;
    Application.OnIdle := ShittyGameEngineEventsIdle;
    SetLength (WorldMap, 0);

    LoadMap ('maps\world.dat');
    InitVBOs;
    UseShaders := false;
    PWorldStruc := TParticleWorldStruc.Create(100, 100);
    WorldStruc := TWorldStruc.Create(100, 1000);
    InitObjects;
end;

procedure TShittyGameEngine.FormDestroy(Sender: TObject);
Var I: Integer;
begin
    PWorldStruc.Destroy;
    WorldStruc.Destroy;
    
    glBindTexture (GL_TEXTURE_2D, 0);
    For I := High (MapGraphics) downto 0 do
        glDeleteTextures (1, @MapGraphics[i]);
    glUseProgramObjectARB (0);
    glBindBuffer (GL_ARRAY_BUFFER, 0);
    For I := 0 to Length (Shaders) - 1 do
        glDeleteProgram (Shaders[i]);

    glDeleteBuffers (1, @VVBO);
    glDeleteBuffers (1, @NVBO);
    glDeleteBuffers (1, @TCVBO);
    glDeleteBuffers (1, @CVBO);
    if HRC<>0 then
    begin
        wglMakeCurrent(DC,0);
        wglDeleteContext(HRC);
    end;
    if DC<>0 then ReleaseDC(Handle, DC);
end;

procedure TShittyGameEngine.FormKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
    Keys[Key] := true;
end;

procedure TShittyGameEngine.FormKeyUp(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
    Keys[Key] := false;
end;

procedure TShittyGameEngine.FormMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
    Shoot (100, BulletSpeed);
end;

procedure TShittyGameEngine.FormMouseWheel(Sender: TObject; Shift: TShiftState;
  WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
begin
    If BulletSpeed > 1000
    then BulletSpeed := 1000
    else BulletSpeed := BulletSpeed + 5;
end;

procedure TShittyGameEngine.FormMouseWheelDown(Sender: TObject;
  Shift: TShiftState; MousePos: TPoint; var Handled: Boolean);
begin
    If BulletSpeed < 0.5
    then BulletSpeed := 0.5
    else BulletSpeed := BulletSpeed - 5;
end;

procedure TShittyGameEngine.FormResize(Sender: TObject);
begin
    glClear (GL_COLOR_BUFFER_BIT OR GL_DEPTH_BUFFER_BIT);
    glViewport( 0, 0, ClientWidth, ClientHeight );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective (Camera.FoVAngle,
                    (ClientWidth / ClientHeight),
                    Camera.NearClippingDistance, Camera.FarClippingDistance);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
end;

procedure TShittyGameEngine.FPSTimerTimer(Sender: TObject);
begin
    FPSCounter.FPSCount := Round (FPSCounter.FPSCount*1000/FPSTimer.Interval);
    SetWindowText (Handle, PChar(Application.Title + ' [ ' + IntToStr (FPSCounter.FPSCount) + ' FPS ]'));
    DT := 1 / FPSCounter.FPSCount;
    If DT > MaxDT then DT := MaxDT;
    FPSCounter.FPSCount := 0;
end;

end.
