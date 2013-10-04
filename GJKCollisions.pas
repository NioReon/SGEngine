{## http://www.codezealot.org/archives/88 -- �������� GJK ##
 ## http://www.codezealot.org/archives/180 -- �������� EPA ##}
unit GJKCollisions;
interface
uses Math, PhysicsArifm, PhysicsRigidBody, SysUtils;

Type

TSimplex = class
  protected
    Elements: TVectors3;
  public
    Constructor Create;
    Destructor Destroy;
    Function GetLast: TVector3;
    Procedure Add (const El: TVector3);
    Procedure AddAt(const El: TVector3; const PositionIndex: Integer);
    Procedure RemoveDuplicates;
    Procedure RemoveElement (const ElementIndex: Integer);
    Function ContainsOrigin (var SearchDirection: TVector3): boolean;
end;

TEdge = record
    Distance: Double;
    Normal: TVector3;
    Index: Integer;
end;

{��������� ����������� ���� �������� ���, ��������� �������� ��������-��������-ʸ��� (GJK)}
Function GJKTestInterSection (const Body1, Body2: TRigidBody; var TerminatedSimplex: TSimplex;
    var CurrentDirection: TVector3): boolean;
{��������� �������� �������������� ��������}
Procedure EPA (const Body1, Body2: TRigidBody; var TerminatedSimplex: TSimplex;
    var ContactNormal: TVector3; var ContactPenetrationDepth: Double);

implementation

{������� �� ������� ������� �� ��� �������}
Procedure RemoveArrayEl (Var A: TVectors3; const Index: Integer); overload;
Var Len: Integer;
begin
    Len := High (A);
    If Index > Len then Exit;
    A[Index] := A[Len];
    SetLength (A, Len);
end;

{������� ������������� �������� � ������� ��������}
Procedure ClearDuplicates (Var A: TVectors3; StartIndex, EndIndex: Integer);
Var I, J: Integer;
begin
    I := StartIndex;
    If EndIndex > High (A) then EndIndex := High (A);
    While (I <= EndIndex) do
    begin
        J := StartIndex;
        While J <= EndIndex do
        begin
            While not V3Equal (A[I], A[J]) and (J < EndIndex) do
                Inc (J);
            If J <> I
            then
            begin
                RemoveArrayEl (A, J);
                Dec (EndIndex);
            end
            else Inc (J);
        end;
        If High (A) < EndIndex then EndIndex := High (A);
        Inc (I);
    end;
end;

{������� �������� �������, ������ 0 �� �����}
Procedure ClearZeroEqualElements (Var A: TVectors3);
Var J: Integer;
begin
    J := 0;
    While J <= High (A) do
    begin
        If not V3Equal (A[J], V3 (0))
        then Inc (J)
        else
        begin
            A[J] := V3Normalize (A[J]);
            If V3Equal (A[J], V3 (0))
            then RemoveArrayEl (A, J);
        end;
    end;
end;

{################################################################################################################
                                              TSIMPLEX
################################################################################################################}

Constructor TSimplex.Create;
begin
    inherited Create;
    SetLength (Elements, 0);
end;

Destructor TSimplex.Destroy;
begin
    SetLength (Elements, 0);
    inherited Destroy;
end;

Function TSimplex.GetLast: TVector3;
begin
    Result := Elements[High (Elements)];
end;

Procedure TSimplex.Add(const El: TVector3);
Var I: Integer;
begin
    I := Length (Elements);
    SetLength (Elements, I + 1);
    Elements[I] := El;
end;

Procedure TSimplex.AddAt(const El: TVector3; const PositionIndex: Integer);
Var I, Len: Integer;
begin
    Len := Length (Elements);
    If PositionIndex >= Len then
    begin
        Add (El);
    end else If (PositionIndex > 0) and (Len > 0) then
    begin
        SetLength (Elements, Len + 1);
        {���������� �������� �������� ������� ������}
        For I := Len downto PositionIndex do Elements[I] := Elements[I - 1];

        Elements[PositionIndex] := El;
    end else If (PositionIndex = 0) then
    begin
        SetLength (Elements, Len + 1);
        {���������� �������� �������� ������� ������}
        For I := Len downto 1 do Elements[I] := Elements[I - 1];

        Elements[PositionIndex] := El;
    end;
end;

Procedure TSimplex.RemoveElement(const ElementIndex: Integer);
Var Len: Integer;
begin
    Len := High (Elements);
    If ElementIndex > Len then Exit;
    Elements[ElementIndex] := Elements[Len];
    SetLength (Elements, Len);
end;

Procedure TSimplex.RemoveDuplicates;
Var I, J, EndIndex: Integer;
    AreEqual: boolean;
begin
    I := 0;
    EndIndex := High (Elements);
    If EndIndex <= 0 then Exit;
    
    While (I <= EndIndex) do
    begin
        J := 1;
        While J <= EndIndex do
        begin
            AreEqual := V3Equal (Elements[I], Elements[J]);
            While not AreEqual and (J < EndIndex) do
            begin
                Inc (J);
                AreEqual := V3Equal (Elements[I], Elements[J]);
            end;
            If (J <> I) and AreEqual then
            begin
                RemoveElement (J);
                Dec (EndIndex);
            end
            else Inc (J);
        end;
        If High (Elements) < EndIndex then EndIndex := High (Elements);
        Inc (I);
    end;
end;

Function TSimplex.ContainsOrigin (var SearchDirection: TVector3): boolean;
Var A, B, C, AO, AB, AC, ABPerp, ACPerp: TVector3;
    Len: Integer;
begin
    {�������� ����������� ��������� ����� ���������}
    A := GetLast;
    {��������������� ������-������ A}
    AO := V3Invert (A);
    Len := Length (Elements);

    RemoveDuplicates;
    If Len = 3 then
    begin
        {������ ������������ (2-��������)}
        B := Elements[1];
        C := Elements[0];
        {�������}
        AB := V3Sub (B, A);
        AC := V3Sub (C, A);
        {�������������� � ���}
        ABPerp := V3TripleProduct (AC, AB, AB);
        ACPerp := V3TripleProduct (AB, AC, AC);
        {������ ��������� � ������� �������� R4?}
        If V3ScalarProduct (ABPerp, AO) > 0 then
        begin
            {������� ����� B}
            RemoveElement (2);
            {���������� ����������� ������ �� ������� � AB}
            SearchDirection := ABPerp;
        end else
            If V3ScalarProduct (ACPerp, AO) > 0 then
            begin
                {������� ����� C}
                RemoveElement (1);
                {���������� ����������� ������ �� ������� � AC}
                SearchDirection := ACPerp;
            end else
            begin
                Result := true;
                Exit;
            end;
    end else If Len = 2 then
    begin
        {������ ����� (1-��������)}
        B := Elements[0];
        AB := V3Sub (B, A);
        ABPerp := V3TripleProduct (AB, AO, AB);
        SearchDirection := ABPerp;
    end;
    Result := false;
end;

{����� �� ��������� ������� � ����������� ���� (Separating Axis Theorem, SAT) �������� ��,
 ��� ��� ������ �������������� �������������� ���� ���� ������ ����� ���� ������� ������ �� ������,
 ���� ��������� ������������ ������������ ���� ����, ��� ���� ����� ����������� ������ �������������,
 � ������ � �������. �� ����, ��� ������ �������������� ��������������, ���� �������� ��� �����������,
 �������� ������ SAT �������� � ��������� ���� ��������:
  a) ��������� ������ ������������� ����������� ����, ��������� �� ���� �������� ������
     � ���� ��������� ��� ����,
  �) ��������� �������� ����������� �������� ����� ��������� �� ������ �� ����. ���,
     �� ������� �������� �������� �����������, ������ �����������
     (����� ��, ��� �� ������ �����, ��� ��� ��������� ������������), � ���������
     �������� ����������� �������� ������ penetration depth ��� PD.
     �������, ��� ���� ������ ���� �������� �� ������ PD, �� ����������� ��������������.}
Procedure GeneratePossibleSATs2RB (const Body1, Body2: TRigidBody; Var Results: TVectors3);
Var I, J: Integer;
    Count: Integer;
    Offset: Integer;
begin
    {����������� ������� � ������}
    SetLength (Results, Length (Body1.Ribs) + Length (Body2.Ribs) + Sqr (Length (Body1.Ribs))
                        + Sqr (Length (Body1.Ribs)));
    {������� � ������ 1 ����}
    Count := High (Body1.Faces);
    For I := 0 to Count do
    With Body1 do
        Results[i] := GetNormalToPlane (GlobalVertexes [Faces[I].Vertexes[0]].Pos,
                                        GlobalVertexes [Faces[I].Vertexes[1]].Pos,
                                        GlobalVertexes [Faces[I].Vertexes[2]].Pos);
    {������� � ������ 2 ����}
    Offset := Count + 1;
    Count := High (Body2.Faces);
    For I := 0 to Count do
    With Body2 do
        Results[i + Offset] := GetNormalToPlane (GlobalVertexes [Faces[I].Vertexes[0]].Pos,
                                        GlobalVertexes [Faces[I].Vertexes[1]].Pos,
                                        GlobalVertexes [Faces[I].Vertexes[2]].Pos);
    Offset := Offset + Count + 1;

    {��������� ��������� ������������ ���� 1 ���� �� ���� 2 ����}
    Count := 0;
    For I := 0 to High (Body1.Ribs) do
    begin
        For J := 0 to High (Body2.Ribs) do
        begin
            Results[Count + Offset] := V3Mul (V3Sub (Body1.GlobalVertexes [Body1.Ribs[I, 1]].Pos,
                                  Body1.GlobalVertexes [Body1.Ribs[I, 0]].Pos),
                                  V3Sub (Body2.GlobalVertexes [Body2.Ribs[J, 1]].Pos,
                                  Body2.GlobalVertexes [Body2.Ribs[J, 0]].Pos));
            Inc (Count);
        end;
    end;

    SetLength (Results, Offset + Count);

    {������������� ������������ ���}
    For J := 0 to High (Results) do
        Results[J] := V3Normalize (Results[J]);

    {������� ������������� ������}
    ClearDuplicates (Results, 0, High (Results));
    {������� ��������, ������ 0 �� �����}
    ClearZeroEqualElements (Results);
end;

{Support Mapping: ������� ����� ���� � ������� �����������,
 ������� ���������� �������� �� �������� �����������}
Function Support (const Body1, Body2: TRigidBody; const Direction: TVector3): TVector3;
begin
    Result := V3Sub (Body1.GetFarthestPointInDirection (Direction).Pos,
        Body2.GetFarthestPointInDirection (V3Invert (Direction)).Pos);
end;

Function GJKTestInterSection (const Body1, Body2: TRigidBody; var TerminatedSimplex: TSimplex;
    var CurrentDirection: TVector3): boolean;
begin
    {������� ��������}
    TerminatedSimplex := TSimplex.Create;

    {������� ����������� ��� ������ Support Point'��}
    With Body1 do
        CurrentDirection := GetNormalToPlane (GlobalVertexes [Faces[0].Vertexes[0]].Pos,
                                        GlobalVertexes [Faces[0].Vertexes[1]].Pos,
                                        GlobalVertexes [Faces[0].Vertexes[2]].Pos);
    {�������� � �������� ������ ����� �� ����� �����������}
    TerminatedSimplex.Add(Support (Body1, Body2, CurrentDirection));
    {������������� ����������� ��� ��������� �����}
    CurrentDirection := V3Invert (CurrentDirection);

    While true do
    begin
        {�������� � �������� ��������� ����� ����� �����������}
        TerminatedSimplex.Add(Support (Body1, Body2, CurrentDirection));
        {� ������� ������������� �����}
        TerminatedSimplex.RemoveDuplicates;

        If V3ScalarProduct (TerminatedSimplex.GetLast, CurrentDirection) <= 0 then
        begin
            Result := false;
            CurrentDirection := V3 (0);
            Break;
        end else
        {���� �������� �������� ������ ���������, �� �� ����� �����������.}
        If TerminatedSimplex.ContainsOrigin(CurrentDirection) then
        begin
            Result := true;
            CurrentDirection := V3Normalize (CurrentDirection);
            Exit;
        end;
    end;
end;

Function FindClosestEdgeInSimplex (const Simplex: TSimplex): TEdge;
Var I, J, Len: Integer;
    EdgeVector, Normal: TVector3;
    Dist: Double;
    Edge: TEdge;
begin
    Edge.Distance := +Infinity;
    Len := High (Simplex.Elements);

    For I := 0 to Len do
    begin
        {������� ������ ��������� �����}
        If I = Len
        then J := 0
        else J := I + 1;

        With Simplex do
        begin
            {������ �� ����� � �������� J � ����� � �������� I}
            EdgeVector := V3Sub (Elements[J], Elements[I]);
            {������ �� ������� �� ������ ���������}
            Normal := V3Normalize (V3TripleProduct (EdgeVector, Elements[I], EdgeVector));
            {���������� �� ������� �� ������ ���������}
            Dist := V3ScalarProduct (Elements[I], Normal);
        end;

        {�� ���� ���������� ���������� �� ������ ���������. �������� ������ �������.}
        If Dist < Edge.Distance then
        begin
            Edge.Distance := Dist;
            Edge.Normal := Normal;
            Edge.Index := J;
        end;
    end;
    Result := Edge;
end;

Procedure EPA (const Body1, Body2: TRigidBody; var TerminatedSimplex: TSimplex;
    var ContactNormal: TVector3; var ContactPenetrationDepth: Double);
Var Edge: TEdge;
    SupportPoint: TVector3;
    DistanceToOrigin: Double;
begin
    While true do
    begin
        {����� � ��������� �������, �������� ������� � ������ ���������}
        Edge := FindClosestEdgeInSimplex (TerminatedSimplex);
        {�������� Support Point � ����������� ������� ���������� �������}
        SupportPoint := Support (Body1, Body2, Edge.Normal);
        {�������� ���������� �� ������ ��������� �� ������� Support Point'�}
        DistanceToOrigin := -V3ScalarProduct (SupportPoint, Edge.Normal);
        {���� ����� ����� ����� � ������ ���������, �����}
        If DistanceToOrigin + Edge.Distance < 0.000001 then
        begin
            ContactNormal := Edge.Normal;
            ContactPenetrationDepth := Abs (DistanceToOrigin);
            Exit;
        end else TerminatedSimplex.AddAt (SupportPoint, Edge.Index);
    end;
end;

end.
