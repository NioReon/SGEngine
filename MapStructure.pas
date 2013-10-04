unit MapStructure;

interface
Uses dglOpenGL, PhysicsArifm, Windows;
Type
    TMapVertex = record
        X, Y, Z: Single;
    end;
    TTextureCoord = record
        X, Y: Single;
    end;
    TTriangleVertex = record
        Vertex: TMapVertex;
        TextureCoord: TTextureCoord;
    end;
    TSector = record                       // Сектор
        NumTriangles: integer;
        Vertexs: array of TMapVertex;
        Colors: array of TRGBTriple;
        Normals: array of TMapVertex;
        TextureCoords: array of TTextureCoord;
        Texturez: array of GLUInt;
    end;

Function SetColor (const Red, Green, Blue: byte): TRGBTriple;

implementation

Function SetColor (const Red, Green, Blue: byte): TRGBTriple;
begin
    Result.rgbtRed := Red;
    Result.rgbtGreen := Green;
    Result.rgbtBlue := Blue;
end;

end.
