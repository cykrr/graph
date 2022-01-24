#version 330 core
out vec4 frag_color;
uniform  vec3 in_color;

in vec2 TexCoord;

uniform sampler2D texture1;




void main()
{
    frag_color = texture(texture1, TexCoord);
}
