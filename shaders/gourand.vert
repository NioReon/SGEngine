varying vec4 color;

varying vec3 N;
varying vec3 v;
varying vec4 diffuse;
varying vec4 spec;
varying vec2 texture_coordinate;

void main()
{
    v = vec3(gl_ModelViewMatrix * gl_Vertex);
    N = normalize(gl_NormalMatrix * gl_Normal);
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;  
    texture_coordinate = vec2 (gl_MultiTexCoord0);
    vec3 E = -normalize (v);
    
    for (int LightIndex = 0; LightIndex < gl_MaxLights; ++LightIndex)
    {
        vec3 L = normalize(gl_LightSource[LightIndex].position.xyz - v);
        vec3 R = -reflect(L,N); 

        diffuse = clamp ( gl_FrontLightProduct[LightIndex].diffuse * abs(dot(N,L)), 0.0, 1.0 ) ;
        spec = clamp ( gl_FrontLightProduct[LightIndex].specular * pow(abs(dot(R,E)), gl_FrontMaterial.shininess), 0.0, 1.0 );

        color += gl_FrontLightProduct[LightIndex].ambient + diffuse + spec;
    }
    color = clamp (color, 0.0, 1.0);
}