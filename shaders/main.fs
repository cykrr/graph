#version 330 core

in vec3 near_point;
in vec3 far_point;

out vec4 frag_color;

uniform  vec4 my_color;

uniform vec3 light_color;
uniform vec3 object_color;

vec4 grid(vec3 frag_pos_3d, float scale){
	vec2 coord = frag_pos_3d.xz * scale;
	vec2 derivative = fwidth(coord);
	vec2 grid = abs(fract(coord - 0.5f) - 0.5f) / derivative;
	float line = min(grid.x, grid.y);
	float min_z = min(derivative.y, 1);
	float min_x = min(derivative.x, 1);
	vec4 color = vec4(0.03f, 0.03f, 0.03f, 0.8f - min(line, 1.0f));

	/* z axis */
	if ( frag_pos_3d.x > -0.1f * min_x && 
			frag_pos_3d.x  < 0.1f * min_x )
		color.z = 1.0f;

	/* x axis */
	if ( frag_pos_3d.z > -0.1f * min_z && 
			frag_pos_3d.z  < 0.1f * min_z )
		color.x = 1.0f;

	return color;
}

void main()
{
	float t = -near_point.y / (far_point.y - near_point.y);

	vec3 frag_pos_3d = near_point + t * (far_point - near_point);

    frag_color = grid(frag_pos_3d, 10) ;
	
}
