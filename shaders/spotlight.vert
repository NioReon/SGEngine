varying vec3 normal, lightDir, eyeVec;
varying vec2 texture_coordinate;

void main()
{
    normal = gl_NormalMatrix * gl_Normal;

    vec3 vVertex = vec3(gl_ModelViewMatrix * gl_Vertex);
    texture_coordinate = gl_MultiTexCoord0;
    lightDir = vec3(gl_LightSource[0].position.xyz - vVertex);
    eyeVec = -vVertex;

    gl_Position = ftransform();
}