unit PrimitiveCollsTesters;

interface
Uses Math, PhysicsArifm;

{Обменять A и B, если A > B, и взвести флаг результата}
Function Sort2f (Var A, B: Single): boolean;
Function Sort2d (Var A, B: Double): boolean;

Procedure ISect2 (VTX0, VTX1, VTX2: TVector3;
                  VV0, VV1, VV2: Single;
                  D0, D1, D2: Single;
                  Var ISect0, ISect1: Single;
                  Var ISectPoint0, ISectPoint1: TVector3);

{Проверка, лежат ли треугольники в одной плоскости}
Function AreTrianglesCoplanar (const Normal,
                               V0, V1, V2,
                               U0, U1, U2: TVector3): boolean;
{Получить точки пересечения треугольников с прямой, по которой
 пересекаются плоскости, в которой они лежат}
Function ComputeIntervalsISectLine (
    const V0, V1, V2: TVector3;
    U0, U1, U2: TVector3;
    VV0, VV1, VV2: Single;
    D0, D1, D2: Single;
    D0D1, D0D2: Single;
    Var ISect0, ISect1: Single;
    Var ISectPoint0, ISectPoint1: TVector3;
    const Normal1: TVector3): boolean;

implementation

Function Sort2f (Var A, B: Single): boolean;
Var Temp: Single;
begin
    If A > B then
    begin
        Temp := A;
        A := B;
        B := Temp;
        Result := true;
    end
    else Result := false;
end;

Function Sort2d (Var A, B: Double): boolean;
Var Temp: Double;
begin
    If A > B then
    begin
        Temp := A;
        A := B;
        B := Temp;
        Result := true;
    end
    else Result := false;
end;

Procedure ISect2 (VTX0, VTX1, VTX2: TVector3;
                  VV0, VV1, VV2: Single;
                  D0, D1, D2: Single;
                  Var ISect0, ISect1: Single;
                  Var ISectPoint0, ISectPoint1: TVector3);
Var Tmp: Double;
    Diff: TVector3;
begin
    Tmp := D0 / (D0 - D1);
    ISect0 := VV0 + (VV1 - VV0) * Tmp;
    Diff := V3Mul (V3Sub (VTX1, VTX0), Tmp);
    ISectPoint0 := V3Add (Diff, VTX0);

    Tmp := D0 / (D0 - D2);
    ISect1 := VV0 + (VV2 - VV0) * Tmp;
    Diff := V3Mul (V3Sub (VTX2, VTX0), Tmp);
    ISectPoint1 := V3Add (VTX0, Diff);
end;

Function CoordByIndex (const AVector: TVector3; const Index: byte): Single;
begin
    Case Index of
    0: Result := AVector.X;
    1: Result := AVector.Y;
    2: Result := AVector.Z
    else Result := -Infinity;
    End;
end;

{Проверяет, лежит ли точка Point в треугольнике, заданном вершинами TrA, TrB, TrC}
Function PointInTriangle (const Point, TrA, TrB, TrC: TVector3;
                          const Index0, Index1: byte): boolean;
Var A, B, C, D0, D1, D2: Single;
begin
    Result := false;
    A := CoordByIndex(TrB, Index1) - CoordByIndex(TrA, Index1);
    B := CoordByIndex(TrA, Index0) - CoordByIndex(TrB, Index0);
    C := - A*CoordByIndex(TrA, Index0) - B*CoordByIndex(TrA, Index1);
    D0 := A*CoordByIndex(TrA, Index0) + B*CoordByIndex(TrA, Index1) + C;

    A := CoordByIndex(TrC, Index1) - CoordByIndex(TrB, Index1);
    B := CoordByIndex(TrB, Index0) - CoordByIndex(TrC, Index0);
    C := - A*CoordByIndex(TrB, Index0) - B*CoordByIndex(TrB, Index1);
    D1 := A*CoordByIndex(TrA, Index0) + B*CoordByIndex(TrA, Index1) + C;

    A := CoordByIndex(TrA, Index1) - CoordByIndex(TrC, Index1);
    B := CoordByIndex(TrC, Index0) - CoordByIndex(TrA, Index0);
    C := -A*CoordByIndex(TrC, Index0) - B*CoordByIndex(TrC, Index1);
    D2 := A*CoordByIndex(TrA, Index0) + B*CoordByIndex(TrA, Index1) + C;

    If (D0 * D1 > 0) and (D0 * D2 > 0) then Result := true;
end;

(* this edge to edge test is based on Franlin Antonio's gem:
   "Faster Line Segment Intersection", in Graphics Gems III,
   pp. 199-202 *)
Function EdgeToEdgeTest (const V0, U0, U1: TVector3;
                         const AX, AY: Single;
                         const Index0, Index1: byte): boolean;
Var BX, CX, BY, CY: Single;
    F, D, E: Single;
begin
    Result := false;
    BX := CoordByIndex(U0, Index0) - CoordByIndex(U1, Index0);
    BY := CoordByIndex(U0, Index1) - CoordByIndex(U1, Index1);
    CX := CoordByIndex(V0, Index0) - CoordByIndex(U0, Index0);
    CY := CoordByIndex(V0, Index1) - CoordByIndex(U0, Index1);
    F := AY * BX - AX * BY;
    D := BY * CX - BX * CY;

    If ((F > 0) and (D >= 0) and (D <= F))
        or ((F < 0) and (D <= 0) and (D >= F)) then
    begin
        E := AX * CY - AY * CX;
        If F > 0 then
            If (E >= 0) and (E <= f) then
                Result := true
            else If (E <= 0) and (E >= F) then
                Result := true;
    end;
end;

Function EdgeToTriangleEdgesTest (const V0, V1, U0, U1, U2: TVector3;
                                  const Index0, Index1: byte): boolean;
Var AX, AY: Single;
begin
    Result := false;
    AX := CoordByIndex(V1, Index0) - CoordByIndex(V0, Index0);
    AY := CoordByIndex(V1, Index1) - CoordByIndex(V0, Index1);
    (* test edge U0,U1 against V0,V1 *)
    If EdgeToEdgeTest (V0, U0, U1, AX, AY, Index0, Index1) or
    (* test edge U1,U2 against V0,V1 *)
    EdgeToEdgeTest (V0, U1, U2, AX, AY, Index0, Index1) or
    (* test edge U2,U1 against V0,V1 *)
    EdgeToEdgeTest (V0, U2, U0, AX, AY, Index0, Index1) then Result := true;
end;

Function AreTrianglesCoplanar (const Normal,
                               V0, V1, V2,
                               U0, U1, U2: TVector3): boolean;
Var A: TVector3;
    Index0, Index1: byte;
begin
    A.X := Abs (Normal.X);
    A.Y := Abs (Normal.Y);
    A.Z := Abs (Normal.Z);

    If A.X > A.Y then
    begin
        If A.X > A.Z then
        begin
            Index0 := 1;
            Index1 := 2;
        end
        else
        begin
            Index0 := 0;
            Index1 := 1;
        end;
    end else
    begin
        If A.Z > A.Y then
        begin
            Index0 := 0;
            Index1 := 1;
        end else
        begin
            Index0 := 0;
            Index1 := 2;
        end;
    end;

    Result := false;
    (* Проверить, пересекаются ли стороны первого треугольника со вторым.
       Возвращаем истину, если есть хотя бы одно пересечение *)
    If EdgeToTriangleEdgesTest (V0, V1, U0, U1, U2, Index0, Index1) or
    EdgeToTriangleEdgesTest (V1, V2, U0, U1, U2, Index0, Index1) or
    EdgeToTriangleEdgesTest (V2, V0, U0, U1, U2, Index0, Index1) then
    begin
        Result := true;
        Exit;
    end else
    (* Пересечений не нашлось. Осталось проверить, находится ли первый
       треугольник целиком во втором. Если все точки этого треугольника
       там содержатся, возвращаем истину *)
    If PointInTriangle (V0,U0,U1,U2, Index0, Index1) and
    PointInTriangle (U0,V0,V1,V2, Index0, Index1) then
    begin
        Result := true;
        Exit;
    end;
end;

Function ComputeIntervalsISectLine (
    const V0, V1, V2: TVector3;
    U0, U1, U2: TVector3;
    VV0, VV1, VV2: Single;
    D0, D1, D2: Single;
    D0D1, D0D2: Single;
    Var ISect0, ISect1: Single;
    Var ISectPoint0, ISectPoint1: TVector3;
    const Normal1: TVector3): boolean;
begin
    Result := False;
    If D0D1 > 0
    then
    ISect2 (V2, V0, V1, VV2, VV0, VV1, D2, D0, D1, ISect0, ISect1, ISectPoint0, ISectPoint1)
    else If (D0D2 > 0) then
    ISect2 (V1, V0, V2, VV1, VV0, VV2, D1, D0, D2, ISect0, ISect1, ISectPoint0, ISectPoint1)
    else If ((D1 * D2 > 0) or (D0 <> 0)) then
    ISect2 (V0, V1, V2, VV0, VV1, VV2, D0, D1, D2, ISect0, ISect1, ISectPoint0, ISectPoint1)
    else If (D1 <> 0) then
    ISect2 (V1, V0, V2, VV1, VV0, VV2, D1, D0, D2, ISect0, ISect1, ISectPoint0, ISectPoint1)
    else If (D2 <> 0) then
    ISect2 (V2, V0, V1, VV2, VV0, VV1, D2, D0, D1, ISect0, ISect1, ISectPoint0, ISectPoint1)
    else
    begin
        Result := AreTrianglesCoplanar (Normal1, V0, V1, V2, U0, U1, U2);
        Exit;
    end;
end;

end.
