varying vec3 n;
varying vec3 v;
uniform sampler2D texture; 
varying vec2 texture_coordinate;
 
void main(void)
{
    vec4 result = vec4(0.0);
    for (int li = 0; li < gl_MaxLights; ++li)
    {
        //vec3 l;
        //if (gl_LightSource[li].position.w != 0.0)
        //{
        //    l = normalize(gl_LightSource[li].position.xyz - v);
        //}
        //else
        //{
        vec3 l = normalize(gl_LightSource[li].position.xyz);
        //}
        vec3 e = normalize(-v);
        vec3 r = normalize(-reflect(l, n));
 
        vec4 Iamb = gl_FrontLightProduct[li].ambient;
 
        vec4 Idiff = gl_FrontLightProduct[li].diffuse * dot(n, l);
        Idiff = clamp(Idiff, 0.0, 1.0);
 
        vec4 Ispec = gl_FrontLightProduct[li].specular
                     * pow(dot(r, e), gl_FrontMaterial.shininess);
        Ispec = clamp(Ispec, 0.0, 1.0);
 
        result += Iamb + Idiff + Ispec;
    }
 
    gl_FragColor = gl_FrontLightModelProduct.sceneColor + result * texture2D (texture, texture_coordinate);
}