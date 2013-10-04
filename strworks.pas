unit strworks;

interface
function CutWord(Str, Smb: string; WordNmbr: Byte): string;
function trimmer(s:string):string;
implementation
function CutWord(Str, Smb: string; WordNmbr: Byte): string;
var
  SWord: string;
  StrLen, N: Byte;
begin
  StrLen := length(Str);
  N := 1;

  while ((WordNmbr >= N) and (StrLen <> 0)) do
  begin
    StrLen := Pos(Smb, str);
    if StrLen <> 0 then
    begin
      SWord := Copy(Str, 1, StrLen - 1);
      Delete(Str, 1, StrLen);
      Inc(N);
    end
    else
      SWord := Str;
  end;

  if WordNmbr <= N then
    Result := SWord
  else
    Result := '';
end;
function trimmer(s:string):string;
label m1;
var i,j:integer;
begin
  for i:=1 to length(s) do
  begin
    if s[i]<>' '
    then break;
  end;
  i:=0;
  {trimmer:=copy(s,i,length(s)-i);}
  for j:=i to length(s)-i do
  begin
    trimmer[j-i+1]:=s[i];
  end;
end;
end.
