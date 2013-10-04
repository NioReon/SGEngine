{По материалам http://www.swsys.ru/index.php?page=article&id=863}
unit ShadowCaster;

interface
Uses dglOpenGL, MapStructure, PhysicsArifm, PhysicsRigidBody, RigidBodyContacts;

Type
TPlaneEquationData = record
    A, B, C, D: Float;
end;

Procedure CastShadowOnWorldPolygon (const LightPosition: TGLArray4fs; const WorldStruc: TWorldStruc;
    const WorldSector: TSector);

implementation

Function ComputeShadowProjectionMatrix (const LightPosition: TGLArray4f;
    const PointOnPlane, PlaneNormal: TVector3): TMatrix4x4;
Var ShadowPlane: TPlaneEquationData;
    DistanceToLightSource: Float;
begin
    {Рассчитать коэффициенты для уравнения плоскости затенения}
    ShadowPlane.A := PlaneNormal.X;
    ShadowPlane.B := PlaneNormal.Y;
    ShadowPlane.C := PlaneNormal.Z;
    ShadowPlane.D := - V3ScalarProduct (PlaneNormal, PointOnPlane);

    {Найти расстояние от источника света до плоскости и выйти в
     случае, если оно < 0}
    DistanceToLightSource := V3ScalarProduct (PlaneNormal, V3 (LightPosition[0], LightPosition[1], LightPosition[2]));
    If DistanceToLightSource < 0 then Exit;

    {Результатом работы подпрограммы является матрица проецирования тени}
    With Result do
    begin
        Data[0] := DistanceToLightSource - LightPosition[0] * ShadowPlane.A;
        Data[1] := -LightPosition[0] * ShadowPlane.B;
        Data[2] := -LightPosition[0] * ShadowPlane.C;
        Data[3] := -LightPosition[0] * ShadowPlane.D;

        Data[4] := -LightPosition[1] * ShadowPlane.A;
        Data[5] := DistanceToLightSource - LightPosition[1] * ShadowPlane.B;
        Data[6] := -LightPosition[1] * ShadowPlane.C;
        Data[7] := -LightPosition[1] * ShadowPlane.D;

        Data[8] := -LightPosition[2] * ShadowPlane.A;
        Data[9] := -LightPosition[2] * ShadowPlane.B;
        Data[10] := DistanceToLightSource - LightPosition[2] * ShadowPlane.C;
        Data[11] := -LightPosition[2] * ShadowPlane.D;

        Data[12] := -LightPosition[3] * ShadowPlane.A;
        Data[13] := -LightPosition[3] * ShadowPlane.B;
        Data[14] := -LightPosition[3] * ShadowPlane.C;
        Data[15] := DistanceToLightSource - LightPosition[3] * ShadowPlane.D;
    end;
end;

(*Procedure DrawVBOs;
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
end;*)

Procedure CastShadowOnWorldPolygon (const LightPosition: TGLArray4fs; const WorldStruc: TWorldStruc;
    const WorldSector: TSector);
Var I, J, K, CurrentVertex, Len: Integer;
    PointOnPlane: TVector3;
    ShadowMatrix: TMatrix4x4;
begin
    CurrentVertex := 0;
    For I := 0 to WorldSector.NumTriangles - 1 do
    begin
        {Очистить буфер трафарета}
        glClear (GL_STENCIL_BUFFER_BIT);
        {Включить проверку буфера трафарета}
        glEnable (GL_STENCIL_TEST);
        {}
        glStencilOp (GL_KEEP, GL_KEEP, GL_REPLACE);
        glStencilFunc (GL_ALWAYS, 1, 1);
        {Нарисовать данный полигон}
        glBindTexture (GL_TEXTURE_2D, WorldSector.Texturez[I]);
        glBegin (GL_TRIANGLES);
            With WorldSector do
            begin
                glNormal3Fv (@Normals[I]);
                With Vertexs[CurrentVertex] do
                    PointOnPlane := V3 (x, y, z);
                For K := 0 to 2 do
                begin
                    glTexCoord2Fv (@TextureCoords[CurrentVertex]);
                    glVertex3Fv (@Vertexs[CurrentVertex]);
                    Inc (CurrentVertex);
                end;
            end;
        glEnd;
    end;

    {}
    glDisable (GL_DEPTH_TEST);
    glDisable (GL_LIGHTING);
    glEnable (GL_BLEND);
    {}
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f (0, 0, 0, 0.5);
    {}
    glStencilOp (GL_KEEP, GL_DECR, GL_DECR);
    glStencilFunc (GL_EQUAL, 1, 1);
    {}
    Len := High (LightPosition);
    For J := 0 to Len do
    begin
        With WorldSector.Normals[I] do
        ShadowMatrix := ComputeShadowProjectionMatrix (LightPosition[J], PointOnPlane,
            V3 (x, y, z));
        glPushMatrix;
        glMultMatrixf (@ShadowMatrix);
        WorldStruc.DrawBodies;
        glPopMatrix;
    end;
    glDisable (GL_BLEND);
    glDisable (GL_STENCIL_TEST);
    glEnable (GL_LIGHTING);
    glEnable (GL_DEPTH_TEST);
end;

end.
