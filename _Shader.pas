// ======================================== //
// _shader.pas                              //
// ---------------------------------------- //
// Author: Tom Nuydens (tom@delphi3d.net)   //
// ======================================== //

unit _shader;

interface

uses
  Classes, SysUtils, DGLOpenGL;

function GetInfoLog(s: GLhandleARB): String;

function LoadShader(const src: String; const stype: GLenum): GLhandleARB;
function LoadShaderFromFile(const filename: String; const stype: GLenum): GLhandleARB;

function LoadProgram(const sources: array of const): GLhandleARB;
function LoadProgramFromFiles(const filenames: array of const): GLhandleARB;

function LinkPrograms(const programs: array of GLhandleARB): GLhandleARB;

implementation

function GetInfoLog(s: GLhandleARB): String;
var
  blen, slen: Integer;
  infolog: array of Char;
begin

  glGetObjectParameterivARB(s, GL_OBJECT_INFO_LOG_LENGTH_ARB, @blen);

  if blen > 1 then
  begin
    SetLength(infolog, blen);
    glGetInfoLogARB(s, blen, slen, @infolog[0]);
    Result := String(infolog);
    Exit;
  end;

  Result := '';

end;

function LoadShader(const src: String; const stype: GLenum): GLhandleARB;
var
  source: PChar;
  compiled, len: Integer;
  log: String;
begin

  source := PChar(src);
  len := Length(src);

  Result := glCreateShaderObjectARB(stype);

  glShaderSourceARB(Result, 1, @source, @len);
  glCompileShaderARB(Result);
  glGetObjectParameterivARB(Result, GL_OBJECT_COMPILE_STATUS_ARB, @compiled);
  log := GetInfoLog(Result);

  if compiled <> GL_TRUE then
  begin
    raise Exception.Create(log);
  end;

end;

function LoadShaderFromFile(const filename: String; const stype: GLenum): GLhandleARB;
var
  txt: TStringList;
begin

  txt := TStringList.Create;
  txt.LoadFromFile(filename);

  try
    Result := LoadShader(txt.Text, stype);
  except on E: Exception do
    raise Exception.Create(filename + ' contains errors!' + #10 + e.Message);
  end;

  txt.Free;

end;

function LoadProgram(const sources: array of const): GLhandleARB;
var
  i, linked: Integer;
  shader: GLhandleARB;
  log: String;
begin

  Result := glCreateProgramObjectARB;

  i := 0;
  while i < High(sources) do
  begin
    shader := LoadShader(sources[i+1].VPChar, sources[i].VInteger);

    glAttachObjectARB(Result, shader);
    glDeleteObjectARB(shader);

    INC(i, 2);
  end;

  glLinkProgramARB(Result);
  glGetObjectParameterivARB(Result, GL_OBJECT_LINK_STATUS_ARB, @linked);
  log := GetInfoLog(Result);

  if linked <> GL_TRUE then
    raise Exception.Create(log);

end;

function LoadProgramFromFiles(const filenames: array of const): GLhandleARB;
var
  i, linked: Integer;
  shader: GLhandleARB;
  log: String;
begin

  Result := glCreateProgramObjectARB;

  i := 0;
  while i < High(filenames) do
  begin
    shader := LoadShaderFromFile(filenames[i+1].VPChar, filenames[i].VInteger);

    glAttachObjectARB(Result, shader);

    INC(i, 2);
  end;

  glLinkProgramARB(Result);
  glGetObjectParameterivARB(Result, GL_OBJECT_LINK_STATUS_ARB, @linked);
  log := GetInfoLog(Result);

  if linked <> GL_TRUE then
    raise Exception.Create(log);

end;

function LinkPrograms(const programs: array of GLhandleARB): GLhandleARB;
var
  i, linked: Integer;
  shader: GLhandleARB;
  log: String;
begin

  Result := glCreateProgramObjectARB;

  i := 0;
  while i <= High(programs) do
  begin
    shader := programs[i];

    glAttachObjectARB(Result, shader);

    INC(i);
  end;

  glLinkProgramARB(Result);
  glGetObjectParameterivARB(Result, GL_OBJECT_LINK_STATUS_ARB, @linked);
  log := GetInfoLog(Result);

  if linked <> GL_TRUE then
    raise Exception.Create(log);

end;

end.
