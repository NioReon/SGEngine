varying vec2 texture_coordinate;
varying float texnum;

void main()
{
gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
texture_coordinate = vec2 (gl_MultiTexCoord0);
} 