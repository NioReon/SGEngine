unit PhysicsContacts;
interface
Uses MapStructure, PhysicsParticles, PhysicsArifm, SysUtils, Windows, Math;
Const EPS = 0.000001;
    VELOCITY_EPS = 0.00001;
    PullBack = 0.8;
Type

{###############################################################################
                                 TContact2P
Класс контакта двух частиц или частицы с плоскостью (во втором случае Particlez[1] = nil)
Содержит необходимые для разрешения столкновения данные:
    ПОЛЯ:
  - Particles: сталкивающиеся частицы
  - PullBackCoefficient: коэффициент упругости столкновения
  - Normal: нормаль контакта
  - Penetration: проникновение одной частицы внутрь другой
    или частицы в плоскость вдоль нормали
    МЕТОДЫ:
  - CalculateVelocityDifference: найти скорость сближения контактирующих
    объектов
  - ProcessContact: обработать контакт
###############################################################################}
TContact2P = class
  public
    {Частицы}
    Particles: array [0..1] of TParticle;
    {Отскок}
    BounceCoefficient: Float;
    {Трение}
    FrictionCoefficient: Float;
    {Нормаль контакта}
    Normal: TVector3;
    {взаимопроникновение вдоль нормали контакта}
    Penetration: Float;
    {На эту величину раздвигаются частицы}
    DeltaPos: array [0..1] of TVector3;
  private
    {найти разностную скорость (скорость взаимного сближения/удаления)}
    Function CalculateVelocityDifference (const DeltaTime: Float): Float;
    Procedure HandleVelocities (const DeltaTime: Float);
    Procedure HandleInterPenetration;
    Procedure ProcessContact(const DeltaTime: Float);
end;

TContacts2P = array of TContact2P;    //массив контактов

{###############################################################################
                              TContactHandler2P
Обработчик контактов частиц. В его задачу входит изменение взаимного проникновения
частиц в конкретном контакте, а также удаления из общего массива тех контактов,
чьё взаимопроникновение (поле Penetration) неположительно.
    ПОЛЯ:
  - WorkIterations: максимум итераций, которые нужно выполнить; это значит, что
    если выполнено ровно WorkIterations итераций, то осуществляется выход из
    подпрограммы обработки
  - CompletedIterations: количество выполненных на текущий момент итераций основной
    подпрограммы обработки
    МЕТОДЫ:
  - SetIterationsCount: задать значение поля WorkIterations
  - RemoveContactByIndex: удаляет контакт из общего массива по индексу
  - HandleContacts: обработать не более WorkIterations контактов
Один экземпляр может быть использован для работы со всеми контактами.
###############################################################################}
TContactHandler2P = class
  protected
    WorkIterations: Cardinal;          //максимум итераций обработки, которые надо выполнить
    CompletedIterations: Cardinal;     //выполненные итерации
  public
    Constructor Create (Iterations: Cardinal);
    Procedure SetIterationsCount (const Iterations: Cardinal);     //задать верхний предел для количества итераций
    Procedure RemoveContactByIndex (Var Contacts: TContacts2P; const Index: LongInt);
    Procedure HandleContacts (Var Contacts: TContacts2P; {const ContactsCount: Cardinal;} const DeltaTime: Float);    //обработать имеющиеся контакты
end;

{###############################################################################}
                              {TContactGenerator2P}
{###############################################################################}
TContactGenerator2P = class
  public
    Procedure AddContact (var Contacts: TContacts2P; const NewContact: TContact2P);
end;

{###############################################################################
                             T2PContactGenerator
###############################################################################}
T2PContactGenerator = class (TContactGenerator2P)
  public
    Function AddContacts (Var AContacts: TContacts2P; const AParticles: TParticles): Cardinal;
end;

TPPlaneContactGenerator = class (TContactGenerator2P)
  public
    Function AddContacts (Var AContacts: TContacts2P; const AParticles: TParticles; const WorldSector: TSector): Cardinal;
end;

{###############################################################################}
                                implementation
{###############################################################################}

{###############################################################################}
                                 {TContact2P}
{###############################################################################}
Function TContact2P.CalculateVelocityDifference (const DeltaTime: Float): Float;
Var RelVelocity: TVector3;
begin
    RelVelocity := Particles[0].Velocity;
    If Particles [1] <> nil then
        RelVelocity := V3Sub (RelVelocity, Particles[1].Velocity);
    Result := V3ScalarProduct (RelVelocity, Normal);
end;

Procedure TContact2P.HandleVelocities(const DeltaTime: Float);
Var SeparationVelocity: Float;
    NewSeparationVelocity: Float;
    AddedVelocity: TVector3;
    AddedDeltaVelocity: Float;
    OneOverTotalMass: Float;
    InvMasses: array [0..1] of Float;
    CommonImpulse: TVector3;
begin
    {Рассчитать скорость удаления одной частицы от второй}
    SeparationVelocity := CalculateVelocityDifference (DeltaTime);
    {Если частицы отдаляются одна от другой или контакт
     покоящийся, то выйти}
    If SeparationVelocity > VELOCITY_EPS then Exit;
    {Рассчитать новую скорость удаления}
    NewSeparationVelocity := -SeparationVelocity * BounceCoefficient;
    {Рассчитать добавленную ускорением скорость}
    AddedVelocity := Particles[0].Acceleration;
    If Particles[1] <> nil
    then AddedVelocity := V3Sub (AddedVelocity, Particles[1].Acceleration);
    AddedDeltaVelocity := V3ScalarProduct (AddedVelocity, Normal) * DeltaTime;
    {и вычесть её из новой скорости}
    If AddedDeltaVelocity < 0 then
    begin
        NewSeparationVelocity := NewSeparationVelocity + BounceCoefficient * AddedDeltaVelocity;
        {Удостовериться, что мы удалили не больше, чем было}
        If NewSeparationVelocity < VELOCITY_EPS then NewSeparationVelocity := 0;
    end;
    {Подсчитать общую инвертированную массу}
    InvMasses[0] := Particles[0].GetInvMass;
    If Particles[1] <> nil
    then InvMasses[1] := Particles[1].GetInvMass
    else InvMasses[1] := 0;
    OneOverTotalMass := InvMasses[0] + InvMasses[1];
    {Если массы не являются конечными, то выйти}
    If OneOverTotalMass <= 0 then Exit;
    {Рассчитать общий импульс}
    CommonImpulse := V3Mul (Normal, (NewSeparationVelocity - SeparationVelocity) / OneOverTotalMass);
    {Пересчитать скорости частиц}
    With Particles[0] do
        Velocity := V3AddScaledVector (Velocity, CommonImpulse, InvMasses[0]);
    If Particles[1] <> nil then
    With Particles[1] do
        Velocity := V3AddScaledVector (Velocity, CommonImpulse, -InvMasses[1]);
end;

Procedure TContact2P.HandleInterPenetration;
Var OneOverTotalMass: Float;
    MovementOverInvMass: TVector3;
    InvMasses: array [0..1] of Float;
    I: Integer;
begin
    If Penetration = 0 then Exit;
    {Подсчитать общую инвертированную массу}
    InvMasses[0] := Particles[0].GetInvMass;
    If Particles[1] <> nil
    then InvMasses[1] := Particles[1].GetInvMass
    else InvMasses[1] := 0;
    OneOverTotalMass := InvMasses[0] + InvMasses[1];
    {Если массы не являются конечными, то выйти}
    If OneOverTotalMass <= 0 then Exit;
    {Рассчитать, на сколько требуется сместить каждую из двух частиц}
    MovementOverInvMass := V3Mul (Normal, Penetration / OneOverTotalMass);
    DeltaPos[0] := V3Mul (MovementOverInvMass, InvMasses[0]);
    If Particles[1] <> nil
    then DeltaPos[1] := V3Mul (MovementOverInvMass, -InvMasses[1])
    else DeltaPos[1] := V3 (0, 0, 0);
    {Сместить частицы}
    For I := 0 to 1 do
    If Particles[I] <> nil then
    With Particles[I] do
    begin
        PreviousPosition := Position;
        Position := V3Add (Position, DeltaPos[I]);
    end;
end;

Procedure TContact2P.ProcessContact(const DeltaTime: Float);
begin
    HandleVelocities (DeltaTime);
    HandleInterPenetration;
end;

{###############################################################################}
                              {TContactHandler2P}
{###############################################################################}

Constructor TContactHandler2P.Create(Iterations: Cardinal);
begin
    inherited Create;
    WorkIterations := Iterations;
    CompletedIterations := 0;
end;

Procedure TContactHandler2P.SetIterationsCount(const Iterations: Cardinal);
begin
    WorkIterations := Iterations;
end;

Procedure TContactHandler2P.RemoveContactByIndex (Var Contacts: TContacts2P; const Index: LongInt);
Var Len: Integer;
begin
    Len := Length (Contacts);
    Dec (Len);
    If Len >= 0 then
    begin
        If Index = Len then
        begin
            FreeAndNil (Contacts[Len]);
            SetLength (Contacts, Len);
        end
        else
        begin
            FreeAndNil (Contacts[Index]);
            Contacts[Index] := Contacts[Len];
            SetLength (Contacts, Len);
        end;
    end;
end;

Procedure TContactHandler2P.HandleContacts(var Contacts: TContacts2P; const DeltaTime: Float);
Var I: LongInt;
    MaxClosingVelocity: Float;
    MaxFoundIndex: LongInt;
    ContactsCount: LongInt;
    TempMovement: array [0..1] of TVector3;
begin
    {Задача:
    1. найти контакт с наибольшей по модулю разностной скоростью частиц
    2. обработать этот контакт
    3. обновить данные о взаимном проникновении для всех контактов
    4. если итерации не закончились, продолжить обработку}
    CompletedIterations := 0;
    ContactsCount := High (Contacts);
    If ContactsCount = -1 then Exit;
    While CompletedIterations < WorkIterations do
    begin
        MaxClosingVelocity := 0;
        MaxFoundIndex := 0;
        {Выбрать среди имеющихся контактов контакт с максимальной скоростью
         сближения и неотрицательным взаимным проникновением}
        For I := 0 to ContactsCount do
        With Contacts[i] do
        begin
            If {(CurClosingVelocity > MaxClosingVelocity)}{ and
            (CurClosingVelocity > 0) or (Penetration > 0)}
            (Penetration > MaxClosingVelocity) then
            begin
                MaxClosingVelocity := Penetration;
                MaxFoundIndex := i;
            end;
        end;
        Contacts[MaxFoundIndex].ProcessContact(DeltaTime);

        TempMovement[0] := Contacts[MaxFoundIndex].DeltaPos[0];
        TempMovement[1] := Contacts[MaxFoundIndex].DeltaPos[1];
        {обновить данные о взаимопроникновении частиц}
        For I := 0 to ContactsCount do
        With Contacts[i] do
        begin
            If (Particles[0] = Contacts[MaxFoundIndex].Particles[0])
            then Penetration := Penetration - V3ScalarProduct (TempMovement[0], Normal)
            else If (Particles[0] = Contacts[MaxFoundIndex].Particles[1])
            then Penetration := Penetration - V3ScalarProduct (TempMovement[1], Normal);

            If Particles[1] <> nil then
                If (Particles[1] = Contacts[MaxFoundIndex].Particles[0])
                then Penetration := Penetration + V3ScalarProduct (TempMovement[0], Normal)
                else If (Particles[1] = Contacts[MaxFoundIndex].Particles[1])
                then Penetration := Penetration + V3ScalarProduct (TempMovement[1], Normal);
        end;

        Inc (CompletedIterations);
    end;
end;

{Подпрограммы для работы с массивами контактов}

{Соединить воедино два массива контактов и поместить результат на место первого параметра}
Procedure ContactsConcat (var TargetContacts: TContacts2P; const NewContacts: TContacts2P);
Var Total, First, I: Integer;
begin
    First := Length (TargetContacts);
    Total := Length (NewContacts) + First;
    SetLength (TargetContacts, Total);
    Dec (Total);

    For I := First to Total do
        TargetContacts[I] := NewContacts[I - First];
end;

{##############################################################################}
                       {TContactGenerator2P}
{##############################################################################}
Procedure TContactGenerator2P.AddContact (var Contacts: TContacts2P; const NewContact: TContact2P);
Var Len: Integer;
begin
    Len := Length (Contacts);
    SetLength (Contacts, Len + 1);
    Contacts[Len] := NewContact;
end;

Function T2PContactGenerator.AddContacts (Var AContacts: TContacts2P; const AParticles: TParticles): Cardinal;
Var DistanceVector: TVector3;     //расстояние меджу центрами частиц
    Index: Cardinal;         //номер текущего контакта
    Len: Cardinal;           //длина массива частиц
    I, J: Cardinal;             //просто счётчики
    Size: Float;
    Normal: TVector3;
    CurrentContact: TContact2P;
begin
    Index := Length (AContacts);
    Len := High (AParticles);

    For I := 0 to Len - 1 do
    For J := I + 1 to Len do
    begin
        {столкновение между двумя частицами произошло, если квадрат длины вектора между их центрами меньше квадрата суммы их радиусов}
        DistanceVector := V3Sub (AParticles[j].Position, AParticles[i].Position);
        Size := V3Length (DistanceVector);
        {Если есть гарантированная коллизия, то заполнить данные о контакте}
        If (Size <= AParticles[i].Radius + AParticles[j].Radius) then
        begin
            Normal.X := DistanceVector.X / Size;
            Normal.Y := DistanceVector.Y / Size;
            Normal.Z := DistanceVector.Z / Size;

            CurrentContact := TContact2P.Create;
            CurrentContact.Particles[0] := AParticles[J];
            CurrentContact.Particles[1] := AParticles[I];
            {Получить нормаль к плоскости столкновения}
            CurrentContact.Normal := Normal;
            CurrentContact.BounceCoefficient := PullBack;
            CurrentContact.FrictionCoefficient := 1;
            CurrentContact.Penetration := AParticles[j].Radius + AParticles[i].Radius - Size;
            AddContact (AContacts, CurrentContact);
            Inc (Index);
        end;
    end;
    Result := Index;
end;

{###############################################################################
                 ПРОВЕРКА КОЛЛИЗИЙ МЕЖДУ СФЕРОЙ И ПЛОСКОСТЬЮ
###############################################################################}

Function TPPlaneContactGenerator.AddContacts (Var AContacts: TContacts2P; const AParticles: TParticles; const WorldSector: TSector): Cardinal;
function CDSphereAndPlane(sphere:TParticle;plane:TPlane;var ResultC:TContact2P):Integer;
var centreDistance,penetration:Double;normal:TVector3;AContact:TContact2P;
begin
  centreDistance:=V3ScalarProduct(sphere.Position,plane.Normal)-plane.Offset;
  if (centreDistance*centreDistance>sphere.Radius*sphere.Radius)
  then
  begin
    result:=0;
    Exit;
  end;
  normal:=plane.Normal;
  penetration:=-centreDistance;
  if centreDistance<0
  then
  begin
    normal:=V3Mul(normal,-1);
    penetration:=-penetration;
  end;
  penetration:=penetration+sphere.Radius;
  AContact.Create;
  AContact.Particles[0]:=sphere;
  AContact.Particles[1]:=nil;
  AContact.Normal:=normal;
  AContact.Penetration:=penetration;
  AContact.BounceCoefficient := PullBack;
  AContact.FrictionCoefficient := 1;
  ResultC:=AContact;
end;
Var Normal: TVector3;     //нормаль к плоскости треугольника
    {Вершины текущего полигона}
    Offset: Float;       //расстояние от неё до начала координат
    J, I: Cardinal;
    {Расстояние от НАЧАЛЬНОГО положения до плоскости
    и от НАЧАЛЬНОГО до КОНЕЧНОГО соответственно}
    DO1, DO2, DO3, DO4: Float;
    Temp: Integer;
    StartLen: Integer;     //номер первого генерируемого контакта
    ParticleCount: Integer;
    CurrentContact: TContact2P;
begin
    StartLen := Length (AContacts);
    ParticleCount := High (AParticles);
    Temp := 0;

    For I := 0 to WorldSector.NumTriangles - 1 do
    begin
        With WorldSector do
        begin
            {Рассчитать параметры плоскости текущего полигона}
            {Рассчитать нормаль к плоскости треугольника и
             расстояние от неё до начала координат}
            Normal.X := Normals[I].X;
            Normal.Y := Normals[I].Y;
            Normal.Z := Normals[I].Z;

            With Vertexs[Temp] do
                Offset := -V3ScalarProduct (Normal, V3 (X, Y, Z));
            Temp := Temp + 3;
        end;

        For J := 0 to ParticleCount do
        With AParticles[J] do
        begin
            {Вычислим расстояния от предыдущего положения центра частицы до плоскости}
            DO1 := V3ScalarProduct (Normal, PreviousPosition) + Offset;
            {Вычислим расстояния от центра частицы до плоскости}
            DO2 := V3ScalarProduct (Normal, Position) + Offset;
            DO3 := DO2 - Radius;
            DO4 := DO2 + Radius;

            If DO3 * DO4 <= 0 then
            begin
                If DO2 <= Radius then
                begin
                    {Заполнить данные контакта, так как коллизия всё-таки была}
                    CurrentContact := TContact2P.Create;
                    CurrentContact.Particles[0] := AParticles[J];
                    CurrentContact.Particles[1] := nil;
                    {Получить нормаль к плоскости столкновения}
                    CurrentContact.Normal := Normal;
                    CurrentContact.BounceCoefficient := PullBack;
                    CurrentContact.FrictionCoefficient := 1;
                    CurrentContact.Penetration := Abs (Min (DO3, DO4));
                    AddContact (AContacts, CurrentContact);
                end;
            end else If DO1 * DO2 <= 0 then
            begin
                If DO1 <= 0 then
                begin
                    {Заполнить данные контакта, так как коллизия всё-таки была}
                    CurrentContact := TContact2P.Create;
                    CurrentContact.Particles[0] := AParticles[J];
                    CurrentContact.Particles[1] := nil;
                    {Получить нормаль к плоскости столкновения}
                    CurrentContact.Normal := V3Invert (Normal);
                    CurrentContact.BounceCoefficient := PullBack;
                    CurrentContact.FrictionCoefficient := 1;
                    CurrentContact.Penetration := DO2;
                    AddContact (AContacts, CurrentContact);
                end else
                begin
                    {Заполнить данные контакта, так как коллизия всё-таки была}
                    CurrentContact := TContact2P.Create;
                    CurrentContact.Particles[0] := AParticles[J];
                    CurrentContact.Particles[1] := nil;
                    {Получить нормаль к плоскости столкновения}
                    CurrentContact.Normal := Normal;
                    CurrentContact.BounceCoefficient := PullBack;
                    CurrentContact.FrictionCoefficient := 1;
                    CurrentContact.Penetration := DO1;
                    AddContact (AContacts, CurrentContact);
                end;
            end;
        end;
    end;
    Result := Length (AContacts) - StartLen;
end;

end.
