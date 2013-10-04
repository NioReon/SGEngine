(*
    Модуль интерпретатора спаун-скриптов.
    Автор оригинальной версии - Иван Смирнов.
    Последняя модификация: 07.07.2013 (Алексей Токмаков).

    ФОРМАТ ВХОДНОГО ФАЙЛА СО СКРИПТОМ

    //СЕКЦИЯ НАЧАЛА ОПИСАНИЯ ЧАСТИЦ
    particles

    //ОПИСАНИЕ ШАБЛОНА ДЛЯ ЧАСТИЦ
    particle template=qqq
    begin
        xyz 10 10 10          положение центра масс
        mass 10               масса
        radius 0.1            радиус
        velocity 0 0 0        скорость
        damping 0.99          демпинг-фактор (сопротивление среды, от 0 (максимум) до 1 (минимум))
    end

    //ОПИСАНИЕ ОДИНОЧНОЙ ЧАСТИЦЫ
    particle
    begin
        template qqq          используемый шаблон
        xyz 11 10 10          #переопределяемые/добавляемые характеристики#
    end

    //ЦИКЛ ДЛЯ СОЗДАНИЯ НЕПРЕРЫВНЫХ ПРЯМОЛИНЕЙНЫХ СТРУКТУР ИЗ ЧАСТИЦ
    particle_loop
    begin
        template qqq          используемый шаблон
        n 100                 количество частиц в линии
        xyz 0.1 0.1 0.01      шаг размещения частиц
    end

    ## СЕКЦИЯ ГЕНЕРАТОРОВ СИЛ ##
    generators

    {ДОБАВИЛ АЛЕКСЕЙ ТОКМАКОВ}
    //ГЕНЕРАТОР ГРАВИТАЦИОННОГО ВЗАИМОДЕЙСТВИЯ С ЗЕМЛЁЙ
    gravity
    begin
        xyz 0 -9.8 0          направление и модуль вектора гравитации
    end;

    //ОБЫЧНАЯ ПРУЖИНА
    spring
    begin
        k 1000                коэффициент жёсткости
        l 10                  длина покоя пружины
        inf_forcelimit        предел силы, при превышении которого пружина рвётся
                              (inf_forcelimit, если рвать не надо, иначе указать
                               'forcelimit ' и численное значение (в ньютонах))
    end

    {ДОБАВИЛ АЛЕКСЕЙ ТОКМАКОВ}
    //КАНАТ (см. ОБЫЧНАЯ ПРУЖИНА)
    bungee
    begin
        k 1000
        l 10
        forcelimit 10000
    end;

    {ДОБАВИЛ АЛЕКСЕЙ ТОКМАКОВ}
    //ПРУЖИНА С ЗАКРЕПЛЁННЫМ КОНЦОМ (ЯКОРЕМ)
    anchored_spring
    begin
        k 1000                коэффициент жёсткости
        l 10                  длина покоя
        xyz 0 0 0             положение якоря
        forcelimit 10000      предел силы натяжения пружины в ньютонах
    end;

    {ДОБАВИЛ АЛЕКСЕЙ ТОКМАКОВ}
    //ЖЁСТКАЯ СВЯЗЬ
    stiff_joint
    begin
        rest_length 10        длина связи
    end;

    //ЗАПИСЬ РЕЕСТРА (ДЛЯ СВЯЗИ ЧАСТИЦ С ГЕНЕРАТОРАМИ СИЛ)
    //В полях index1 или index2 указать 'nil', если не используется 
    //Возможные значения gen_type: gravity, string, bungee, anchored_spring, stiff_joint
    entry
    begin
        index1 0              номер первой частицы (по спаун-скрипту, начало от 0)
        index2 1              номер второй частицы (по спаун-скрипту, начало от 0)
        gen_type stiff_joint  тип генератора силы (как название секции)
        indexg 0              номер генератора силы указанного типа (по спаун-скрипту, начало от 0)
    end;
*)
unit spawnscripts;
{$O-}
interface
uses PhysicsArifm,SysUtils, math,ParticleWorldStructure,PhysicsParticles,ParticleForceGen, dglOpenGL;
type
     PAction=^tAction;
     PAct_NewParticle=^Act_NewParticle;
     PAct_NewGravity=^Act_NewGravity;
     PAct_NewSpring=^Act_NewSpring;
     PAct_newAnchoredSpring=^Act_NewAnchoredSpring;
     PAct_NewStiffJoint=^Act_NewStiffJoint;
     PAct_Entry=^Act_Entry;
     PAct_ParticleLoop=^Act_Loop;
     Act_NewParticle= record
                        x,y,z:double;
                        velocityx,velocityy,velocityz:Double;
                        ParticleMass,radius,damping:double;
                        Texture: GLUInt;
                      end;
     Act_NewRigidBody= record
                        x,y,z:double;
                        velocityx,velocityy,velocityz:Double;
                        ParticleMass,radius,damping:double;
                        Texture: GLUInt;
                      end;
     Act_NewTemplate= record
                        name:string;
                        act:pAct_newparticle;
                      end;
     Act_Loop= record
                 n:integer;
                 x,y,z,sx,sy,sz:double;
                 velocityx,velocityy,velocityz:Double;
                 ParticleMass,radius,damping:double;
               end;
     Act_NewGravity = record
         Gravity: TVector3;
         Res:Pointer;
     end;
     Act_NewSpring= record
                      k,l,forcelimit:Double;
                      res:Pointer;
                    end;
     Act_NewStiffJoint = record
         RestLength: Double;
     end;
     Act_NewAnchoredSpring= record
                      k,l,forcelimit:Double;
                      Anchor: TVector3;
                      res:Pointer;
                    end;
     Act_Entry= record
                  i1,i2:Integer;
                  iGen:Integer;
                  Gen_Type: Integer;
                end;
     TAction= record
                obj:word;
                params:pointer;
                next:pAction;
              end;
     TTemplate= record
                  name:string;
                  p:pAction;
                end;

function LoadSSL(name:string):pAction;
procedure RunSSl(act:pAction;var WorldStruc: TParticleWorldStruc);
implementation
const
  aNoAction=-1;
  aParticle=0;
  aParticleloop=1;
  aGravity=2;
  aSpring=3;
  aBungee=4;
  aAnchoredSpring=5;
  aStiffJoint=6;
  aEntry=7;
  aParticleTemplate=8;

procedure ReadStr(var f: textfile; var s: string);
begin
  readln(f,s);
  while ((copy(s, 1, 1) = '/') or (length(s) = 0)) do
    readln(f,s);
end;

function LoadSSL(name:string):pAction;
var f:text; s:string; act,sact:pAction; tempdatum:string;templates:array of tTemplate;
procedure NewAction(var act:pAction);
var tz:pAction;
begin
  if act=nil
  then
  begin
    New(act);
    act^.next:=nil;
    sact:=act;
  end
  else
  begin
    tz:=act;
    while tz^.next<>nil do
    begin
      tz:=tz^.next;
    end;
    New(tz^.next);
    tz^.next^.next:=nil;
    act:=act^.next;
  end;
end;
procedure Create_ParticleTemplate(name:string;template:pAction);
begin
  SetLength(templates,Length(templates)+1);
  templates[Length(templates)-1].name:=name;
  templates[Length(templates)-1].p:=template;
end;
procedure Insert_CreateParticle(var act:pAction;template:boolean=false);
var s,s2:string;x,i:Integer; params:pAct_newparticle; ff:Boolean;
begin
  New(params);
  act^.obj:=aParticle;
  while s<>'end' do
  begin
    ReadStr(f,s);
    x:=Pos('xyz',s);
    if x<>0
    then
    begin
      Delete(s,1,x+3);
      s2:='';
      i:=1;
      while s[i]<>' ' do
      begin
        s2:=s2+s[i];
        inc(i);
        i:=i;
      end;
      Delete(s,1,Length(s2)+1);
      params^.x:=strtofloat(s2);
      s2:='';
      i:=1;
      while s[i]<>' ' do
      begin
        s2:=s2+s[i];
        inc(i);
      end;
      Delete(s,1,Length(s2)+1);
      params^.y:=strtofloat(s2);
      s2:='';
      i:=1;
      while (i<=length(s))and(s[i]<>' ') do
      begin
        s2:=s2+s[i];
        inc(i);
      end;
      Delete(s,1,Length(s2)+1);
      params^.z:=strtofloat(s2);
    end
    else
    begin
      x:=Pos('mass',s);
      if x<>0
      then
      begin
        Delete(s,1,x+4);
        params^.ParticleMass:=StrToFloat(s);
      end
      else
      begin
        x:=Pos('radius',s);
        if x<>0
        then
        begin
          Delete(s,1,x+6);
          params^.radius:=StrToFloat(s);
        end
        else
        begin
          x:=Pos('velocity',s);
          if x<>0
          then
          begin
            Delete(s,1,x+8);
            s2:='';
            i:=1;
            while s[i]<>' ' do
            begin
              s2:=s2+s[i];
              inc(i);
            end;
            Delete(s,1,Length(s2)+1);
            params^.velocityx:=strtofloat(s2);
            s2:='';
            i:=1;
            while s[i]<>' ' do
            begin
              s2:=s2+s[i];
              inc(i);
            end;
            Delete(s,1,Length(s2)+1);
            params^.velocityy:=strtofloat(s2);
            s2:='';
            i:=1;
            while (i<=Length(s))and(s[i]<>' ') do
            begin
              s2:=s2+s[i];
              inc(i);
            end;
            Delete(s,1,Length(s2)+1);
            params^.velocityz:=strtofloat(s2);
          end
          else
          begin
            x:=Pos('damping',s);
            if x<>0
            then
            begin
              Delete(s,1,x+7);
              params^.damping:=StrToFloat(s);
            end
            else
            begin
              X := Pos ('texture', s);
              if x <> 0 then
              begin
                Delete(s,1,x+7);
                params^.Texture:=StrToInt(s);
              end
              else
              begin
                x:=Pos('template',s);
                if x<>0
                then
                begin
                  Delete(s,1,x+8);
                  for i:=0 to High(templates) do
                  begin
                    ff:=False;
                    if templates[i].name=s
                    then
                    begin
                      ff:=True;
                      Break;
                    end;
                  end;
                  if ff=True
                  then
                  begin
                    params^:=pAct_newparticle(templates[i].p^.params)^;
                  end;
                end;
              end;
            end;
          end;
        end;
      end;
    end;
  end;
  new(act^.params);
  act^.params:=params;
  if template then
  begin
    SetLength(templates,Length(templates)+1);
    templates[High(templates)].name:=tempdatum;
    Act^.obj := AParticleTemplate;
    templates[High(templates)].p:=act;
  end;
end;

procedure Insert_CreateGravity(var act:pAction);
var X, I: Integer; params: pAct_newGravity; S, S2:string;
begin
  New(params);
  act^.obj:=aGravity;
  while s<>'end' do
  begin
    ReadStr(f,s);
    x:=Pos('xyz',s);
    if x<>0
    then
    begin
      Delete(s,1,x+3);
      s2:='';
      i:=1;
      while s[i]<>' ' do
      begin
        s2:=s2+s[i];
        inc(i);
        i:=i;
      end;
      Delete(s,1,Length(s2)+1);
      params^.Gravity.X:=strtofloat(s2);
      s2:='';
      i:=1;
      while s[i]<>' ' do
      begin
        s2:=s2+s[i];
        inc(i);
      end;
      Delete(s,1,Length(s2)+1);
      params^.Gravity.Y:=strtofloat(s2);
      s2:='';
      i:=1;
      while (i<=length(s))and(s[i]<>' ') do
      begin
        s2:=s2+s[i];
        inc(i);
      end;
      Delete(s,1,Length(s2)+1);
      params^.Gravity.Z:=strtofloat(s2);
    end
  end;
  new(act^.params);
  act^.params:=params;
end;

procedure Insert_CreateSpring(var act:pAction);
var x:Integer; params:pAct_newspring;s:string;
begin
  New(params);
  act^.obj:=aSpring;
  while s<>'end' do
  begin
    ReadStr(f,s);
    x:=Pos('k ',s);
    if x<>0
    then
    begin
      Delete(s,1,x+1);
      params^.k:=StrToFloat(s);
    end
    else
    begin
      x:=Pos('l ',s);
      if x<>0
      then
      begin
        Delete(s,1,x+1);
        params^.l:=StrToFloat(s);
      end
      else
      begin
        x:=Pos('inf_forcelimit',s);
        if x<>0
        then
        begin
          Delete(s,1,x+13);
          params^.forcelimit:=+infinity;
        end
        else
        begin
          x:=Pos(' forcelimit',s);
          if x<>0
          then
          begin
            Delete(s,1,x+11);
            params^.forcelimit:=StrToFloat(s);
          end;
        end;
      end;
    end;
  end;
  new(act^.params);
  act^.params:=params;
end;

procedure Insert_CreateBungee(var act:pAction);
var x:Integer; params:pAct_newspring;s:string;
begin
  New(params);
  act^.obj:=aBungee;
  while s<>'end' do
  begin
    ReadStr(f,s);
    x:=Pos('k ',s);
    if x<>0
    then
    begin
      Delete(s,1,x+1);
      params^.k:=StrToFloat(s);
    end
    else
    begin
      x:=Pos('l ',s);
      if x<>0
      then
      begin
        Delete(s,1,x+1);
        params^.l:=StrToFloat(s);
      end
      else
      begin
        x:=Pos('inf_forcelimit',s);
        if x<>0
        then
        begin
          Delete(s,1,x+13);
          params^.forcelimit:=+infinity;
        end
        else
        begin
          x:=Pos(' forcelimit',s);
          if x<>0
          then
          begin
            Delete(s,1,x+11);
            params^.forcelimit:=StrToFloat(s);
          end;
        end;
      end;
    end;
  end;
  new(act^.params);
  act^.params:=params;
end;

procedure Insert_CreateAnchoredSpring(var act:pAction);
var x, I:Integer; params:pAct_newAnchoredSpring;s, s2:string;
begin
  New(params);
  act^.obj:=aAnchoredSpring;
  while s<>'end' do
  begin
    ReadStr(f,s);
    x:=Pos('k ',s);
    if x<>0
    then
    begin
      Delete(s,1,x+1);
      params^.k:=StrToFloat(s);
    end
    else
    begin
      x:=Pos('l ',s);
      if x<>0
      then
      begin
        Delete(s,1,x+1);
        params^.l:=StrToFloat(s);
      end else
      begin
          x:=Pos('xyz',s);
          if x<>0 then
          begin
              Delete(s,1,x+3);
              s2:='';
              i:=1;
              while s[i]<>' ' do
              begin
                  s2:=s2+s[i];
                  inc(i);
                  i:=i;
              end;
              Delete(s,1,Length(s2)+1);
              params^.Anchor.x:=strtofloat(s2);
              s2:='';
              i:=1;
              while s[i]<>' ' do
              begin
                  s2:=s2+s[i];
                  inc(i);
              end;
              Delete(s,1,Length(s2)+1);
              params^.Anchor.y:=strtofloat(s2);
              s2:='';
              i:=1;
              while (i<=length(s))and(s[i]<>' ') do
              begin
                  s2:=s2+s[i];
                  inc(i);
              end;
              Delete(s,1,Length(s2)+1);
              params^.Anchor.z:=strtofloat(s2);
          end
      else
      begin
        x:=Pos('inf_forcelimit',s);
        if x<>0
        then
        begin
          Delete(s,1,x+13);
          params^.forcelimit:=+infinity;
        end
        else
        begin
          x:=Pos(' forcelimit',s);
          if x<>0
          then
          begin
            Delete(s,1,x+11);
            params^.forcelimit:=StrToFloat(s);
          end;
        end;
      end;
    end;
    end;
  end;
  new(act^.params);
  act^.params:=params;
end;

procedure Insert_CreateStiffJoint(var act:pAction);
var x:Integer; params:pAct_newStiffJoint;s:string;
begin
  New(params);
  act^.obj:=aStiffJoint;
  while s<>'end' do
  begin
    ReadStr(f,s);
    x:=Pos('rest_length ',s);
    if x<>0
    then
    begin
      Delete(s,1,x+11);
      params^.RestLength:=StrToFloat(s);
    end
  end;
  new(act^.params);
  act^.params:=params;
end;

procedure Insert_CreateParticleLoop(var act:pAction);
var x,i:integer; params:pAct_particleloop;s2:string;s:string;ff:Boolean;
function ParamsFromParticleTemplate(o:Act_newparticle):Act_loop;
begin
  {velocityx,velocityy,velocityz:Double;
  ParticleMass,radius,damping:double;  }
  result.velocityx:=o.velocityx;
  result.velocityy:=o.velocityy;
  result.velocityz:=o.velocityz;
  result.ParticleMass:=o.ParticleMass;
  result.radius:=o.radius;
  result.damping:=o.damping;
  result.sx:=o.x;
  result.sy:=o.y;
  result.sz:=o.z;
end;
begin
  New(params);
  act^.obj:=aParticleloop;
  while s<>'end' do
  begin
    ReadStr(f,s);
    x:=Pos('n ',s);
    if x<>0
    then
    begin
      Delete(s,1,x+1);
      params^.n:=strtoint(s);
    end
    else
    begin
      x:=Pos('xyz',s);
      if x<>0
      then
      begin
        Delete(s,1,x+3);
        s2:='';
        i:=1;
        while s[i]<>' ' do
        begin
          s2:=s2+s[i];
          inc(i);
        end;
        Delete(s,1,Length(s2)+1);
        params^.x:=strtofloat(s2);
        s2:='';
        i:=1;
        while s[i]<>' ' do
        begin
          s2:=s2+s[i];
          inc(i);
        end;
        Delete(s,1,Length(s2)+1);
        params^.y:=strtofloat(s2);
        s2:='';
        i:=1;
        while (i<=Length(s))and(s[i]<>' ') do
        begin
          s2:=s2+s[i];
          inc(i);
        end;
        Delete(s,1,Length(s2)+1);
        params^.z:=strtofloat(s2);
      end
      else
      begin
        x:=Pos('template',s);
        if x<>0
        then
        begin
          Delete(s,1,x+8);
          for i:=0 to High(templates) do
          begin
            ff:=False;
            if templates[i].name=s
            then
            begin
              ff:=True;
              Break;
            end;
          end;
          if ff=True
          then
          begin
            params^:=ParamsFromParticleTemplate(pAct_newparticle(templates[i].p^.params)^);
          end;
        end;
      end;
    end;
  end;
  new(act^.params);
  act^.params:=params;
end;

Function GenTypeByName (const S: string): Integer;
begin
    If S = 'gravity'
    then Result := GRAVITY_FORCE_GEN
    else If S = 'spring'
    then Result := SPRING_FORCE_GEN
    else If s = 'bungee'
    then Result := BUNGEE_SPRING_FORCE_GEN
    else If s = 'anchored_spring'
    then Result := ANCHORED_SPRING_FORCE_GEN
    else If s = 'stiff_joint'
    then Result := STIFF_JOINT_FORCE_GEN
    else Result := NIL_FORCE_GEN;
end;

procedure Insert_CreateEntry(var act:pAction);
var x:Integer; params:pAct_Entry;s:string;
begin
  New(params);
  act^.obj:=aEntry;
  while s<>'end' do
  begin
    ReadStr(f,s);
    x:=Pos('index1',s);
    if x<>0
    then
    begin
      Delete(s,1,x+6);
      If Pos ('nil', s) <> 0
      then Params^.i1 := -1
      else Params^.i1 := strtoint(s)
    end
    else
    begin
      x:=Pos('index2',s);
      if x<>0
      then
      begin
        Delete(s,1,x+6);
        If Pos ('nil', s) <> 0
        then Params^.i2 := -1
        else params^.i2:=strtoint(s)
      end
      else
      begin
          X := Pos ('gen_type', s);
          If X <> 0 then
          begin
              Delete (s, 1, x + 8);
              Params^.Gen_Type := GenTypeByName (S);
          end
      else
      begin
        x:=Pos('indexg',s);
        if x<>0
        then
        begin
          Delete(s,1,x+6);
          params^.iGen:=strtoint(s)
        end;
      end;
      end;
    end;
  end;
  new(act^.params);
  act^.params:=params;
end;

function GetActionNumber(s:string):integer;
var x:Integer;
begin
  S := LowerCase (S);
  if s='particle'
  then result:=aParticle
  else
  if s='particle_loop'
  then result:=aParticleloop
  else
  if s='gravity'
  then result:=aGravity
  else
  if s='spring'
  then result:=aSpring
  else
  if s='bungee'
  then result:=aBungee
  else
  if s='anchored_spring'
  then result:=aAnchoredSpring
  else
  if s='stiff_joint'
  then result:=aStiffJoint
  else
  if s='entry'
  then result:=aEntry
  else
  begin
    x:=Pos('template=',s);
    if x<>0
    then
    begin
      tempdatum:=Copy(s,x+length('template='),Length(s)-x-length('template=')+1);
      result:=aParticleTemplate;
    end
    else Result := ANoAction;
  end;
end;

begin
  assign(f,name);
  reset(f);
  act:=nil;
  while not (eof(f)) do
  begin
    ReadStr(f,s);
    if s='particles'
    then
    begin
      while s<>'generators' do
      begin
        ReadStr(f,s);
        If S <> 'generators' then
        begin
            case GetActionNumber(s) of
                aParticle:
                begin
                    NewAction(act);
                    Insert_CreateParticle(act);
                end;
                aParticleTemplate:
                begin
                    NewAction(act);
                    Insert_CreateParticle(act,True);
                end;
                aParticleLoop:
                begin
                    Insert_CreateParticleLoop(act);
                end;
            end;
        end;
      end;
    end;
    if s='generators'
    then
    begin
      while (s<>'end')and(not(eof(f))) do
      begin
        ReadStr(f,s);
        If S <> 'generators' then
        begin
            case GetActionNumber(s) of
              aGravity:
              begin
                  NewAction(act);
                  Insert_CreateGravity (act);
              end;
              aSpring:
              begin
                  NewAction(act);
                  Insert_CreateSpring(act);
              end;
              aBungee:
              begin
                  NewAction(act);
                  Insert_CreateBungee(act);
              end;
              aAnchoredSpring:
              begin
                  NewAction(act);
                  Insert_CreateAnchoredSpring(act);
              end;
              aStiffJoint:
              begin
                  NewAction(act);
                  Insert_CreateStiffJoint(act);
              end;
              aEntry:
              begin
                  NewAction(act);
                  Insert_CreateEntry(act);
              end;
            end;
        end;
      end;
    end;
  end;
  newaction(act);
  act:=sact;
  result:=act;
end;

Function CheckValidity (const CheckingValue, Max: Integer): boolean;
begin
    If (CheckingValue >= 0) and (CheckingValue <= Max)
    then Result := true
    else Result := false;
end;

procedure RunSSl(Act: PAction; var WorldStruc: TParticleWorldStruc);
var i:integer;x,y,z:double;
begin
  while act^.next<>nil do
  begin
    case act^.obj of
    aParticle :
    With WorldStruc do
    begin
      SetLength(Particles,Length(Particles)+1);
      Particles[High(Particles)] := TParticle.Create(V3 (pAct_newparticle(act^.params)^.x,
                                         pAct_newparticle(act^.params)^.y,
                                         pAct_newparticle(act^.params)^.z),
                                     V3 (pAct_newparticle(act^.params)^.velocityx,
                                         pAct_newparticle(act^.params)^.velocityy,
                                         pAct_newparticle(act^.params)^.velocityz),
                                     V3(0, 0, 0),
                                     0{pAct_newparticle(act^.params)^.damping},
                                     pAct_newparticle(act^.params)^.ParticleMass,
                                     pAct_newparticle(act^.params)^.radius);
    end;
    aGravity :
    With WorldStruc.Generators.Force do
    begin
      SetLength (Gravity, length(Gravity)+1);
      Gravity [high(Gravity)] := TGravityForceGen.Create (pAct_newGravity(act^.params)^.Gravity);
    end;
    aSpring :
    With WorldStruc.Generators.Force do
    begin
      SetLength (Spring, length(Spring)+1);
      Spring [high(Spring)] := TSpringForceGen.Create (pAct_newspring(act^.params)^.k,
                                                       pAct_newspring(act^.params)^.l,
                                                       pAct_newspring(act^.params)^.forcelimit);
    end;
    aBungee :
    With WorldStruc.Generators.Force do
    begin
      SetLength (Bungee, length(Bungee)+1);
      Bungee [high(Bungee)] := TBungeeSpringForceGen.Create (pAct_newspring(act^.params)^.k,
                                                             pAct_newspring(act^.params)^.l,
                                                             pAct_newspring(act^.params)^.forcelimit);
    end;
    aAnchoredSpring :
    With WorldStruc.Generators.Force do
    begin
      SetLength (AnchoredSpring, length(AnchoredSpring)+1);
      AnchoredSpring [high(AnchoredSpring)] := TAnchoredSpringForceGen.Create (
                                                             pAct_NewAnchoredSpring(act^.params)^.Anchor,
                                                             pAct_NewAnchoredSpring(act^.params)^.k,
                                                             pAct_newAnchoredSpring(act^.params)^.l,
                                                             pAct_newAnchoredSpring(act^.params)^.forcelimit);
    end;
    aStiffJoint :
    With WorldStruc.Generators.Contact do
    begin
      SetLength (StiffJoint, length(StiffJoint)+1);
      StiffJoint [high(StiffJoint)] := TStiffConnection.Create (pAct_newStiffJoint(act^.params)^.RestLength);
    end;
    aEntry :
    With WorldStruc do
    begin
        Case PAct_Entry(act^.params)^.Gen_Type of
          GRAVITY_FORCE_GEN:
            If CheckValidity (PAct_Entry(Act^.params)^.iGen, High (Generators.Force.Gravity)) then
            begin
                If PAct_Entry (Act^.params)^.i1 >= 0 then
                    Registrations.AddEntry(Particles[PAct_Entry(Act^.params)^.i1],
                        Generators.Force.Gravity[PAct_Entry(Act^.params)^.iGen]);
                If PAct_Entry (Act^.params)^.i2 >= 0 then
                    Registrations.AddEntry(Particles[PAct_Entry(Act^.params)^.i2],
                        Generators.Force.Gravity[PAct_Entry(Act^.params)^.iGen]);
            end else
            begin
                raise Exception.Create ('Gravity Force Generator Index Out Of Bounds: '
                        + IntToStr (PAct_Entry(Act^.Params)^.iGen) + ', Max: '
                        + IntToStr (High (Generators.Force.Gravity)) + '.' + #13 + #10
                        + 'The current entry was not added to the registry.');
            end;
          SPRING_FORCE_GEN:
            If CheckValidity (PAct_Entry(Act^.params)^.iGen, High (Generators.Force.Spring)) then
            begin
                If (PAct_Entry (Act^.params)^.i1 >= 0) and (PAct_Entry (Act^.params)^.i2 >= 0) then
                    Registrations.AddEntry(Particles[PAct_Entry(Act^.params)^.i1],
                    Particles[PAct_Entry(Act^.params)^.i2],
                    Generators.Force.Spring[PAct_Entry(Act^.params)^.iGen]);
            end else
            begin
                raise Exception.Create ('Spring Force Generator Index Out Of Bounds: '
                    + IntToStr (PAct_Entry(Act^.Params)^.iGen) + ', Max: '
                    + IntToStr (High (Generators.Force.Spring)) + '.' + #13 + #10
                    + 'The current entry was not added to the registry.');
            end;
          BUNGEE_SPRING_FORCE_GEN:
            If CheckValidity (PAct_Entry(Act^.params)^.iGen, High (Generators.Force.Bungee)) then
            begin
                If (PAct_Entry (Act^.params)^.i1 >= 0) and (PAct_Entry (Act^.params)^.i2 >= 0) then
                    Registrations.AddEntry(Particles[PAct_Entry(Act^.params)^.i1],
                    Particles[PAct_Entry(Act^.params)^.i2],
                    Generators.Force.Bungee[PAct_Entry(Act^.params)^.iGen]);
            end else
            begin
                raise Exception.Create ('Bungee Force Generator Index Out Of Bounds: '
                    + IntToStr (PAct_Entry(Act^.Params)^.iGen) + ', Max: '
                    + IntToStr (High (Generators.Force.Bungee)) + '.' + #13 + #10
                    + 'The current entry was not added to the registry.');
            end;
          ANCHORED_SPRING_FORCE_GEN:
            If CheckValidity (PAct_Entry(Act^.params)^.iGen, High (Generators.Force.AnchoredSpring)) then
            begin
                If (PAct_Entry (Act^.params)^.i1 >= 0) then
                    Registrations.AddEntry(Particles[PAct_Entry(Act^.params)^.i1],
                    Generators.Force.AnchoredSpring[PAct_Entry(Act^.params)^.iGen]);
                If (PAct_Entry (Act^.params)^.i2 >= 0) then
                    Registrations.AddEntry(Particles[PAct_Entry(Act^.params)^.i2],
                    Generators.Force.AnchoredSpring[PAct_Entry(Act^.params)^.iGen]);
            end else
            begin
                raise Exception.Create ('Anchored Spring Force Generator Index Out Of Bounds: '
                    + IntToStr (PAct_Entry(Act^.Params)^.iGen) + ', Max: '
                    + IntToStr (High (Generators.Force.Spring)) + '.' + #13 + #10
                    + 'The current entry was not added to the registry.');
            end;
          STIFF_JOINT_FORCE_GEN:
            If CheckValidity (PAct_Entry(Act^.params)^.iGen, High (Generators.Contact.StiffJoint)) then
            begin
                If (PAct_Entry (Act^.params)^.i1 >= 0) and (PAct_Entry (Act^.params)^.i2 >= 0) then
                    Registrations.AddEntry(Particles[PAct_Entry(Act^.params)^.i1],
                    Particles[PAct_Entry(Act^.params)^.i2],
                    Generators.Contact.StiffJoint[PAct_Entry(Act^.params)^.iGen]);
            end else
            begin
                raise Exception.Create ('Stiff Joint Force Generator Index Out Of Bounds: '
                    + IntToStr (PAct_Entry(Act^.Params)^.iGen) + ', Max: '
                    + IntToStr (High (Generators.Force.Bungee)) + '.' + #13 + #10
                    + 'The current entry was not added to the registry.');
            end;
        End;
    end;
    aParticleLoop :
    With WorldStruc do
    begin
      x:=pAct_Particleloop(act^.params)^.sx;
      y:=pAct_Particleloop(act^.params)^.sy;
      z:=pAct_Particleloop(act^.params)^.sz;
      for i:=1 to pAct_Particleloop(act^.params)^.n do
      begin
        SetLength(Particles,Length(Particles)+1);
        Particles[High(Particles)] := TParticle.Create(V3 (x, y, z),
                                       V3 (pAct_Particleloop(act^.params)^.velocityx,
                                           pAct_Particleloop(act^.params)^.velocityy,
                                           pAct_Particleloop(act^.params)^.velocityz),
                                       V3(0, 0, 0),
                                       0{pAct_Particleloop(act^.params)^.damping},
                                       pAct_Particleloop(act^.params)^.ParticleMass,
                                       pAct_Particleloop(act^.params)^.radius);
        x:=x+pAct_Particleloop(act^.params)^.x;
        y:=y+pAct_Particleloop(act^.params)^.y;
        z:=z+pAct_Particleloop(act^.params)^.z;
      end;
    end;
    end;
    act:=act^.next;
  end;
end;
end.
