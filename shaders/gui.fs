#version 330 core
out vec4 frag_color;
uniform  vec3 in_color;


void main()
{
    frag_color = vec4(1.0f);
	gl_FragDepth = 0.0f;
}
