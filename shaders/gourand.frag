varying vec4 color;
uniform sampler2D texture;
varying vec2 texture_coordinate;

void main()
{
    gl_FragColor = clamp (texture2D(texture, texture_coordinate) * length (color), 0.0, 1.0);
}