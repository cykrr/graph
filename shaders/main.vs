#version 330 core

layout (location = 0) in vec3 aPos;

out vec3 near_point;
out vec3 far_point;

uniform mat4 MVP;

vec3 
unproject_point(float x, float y, float z, mat4 MVP){
	mat4 inv_mvp = inverse(MVP);

	vec4 unprojected_point = 
		inv_mvp * vec4(x, y, z, 1.0f);

	return unprojected_point.xyz / unprojected_point.w;
}



void main(){
	near_point = unproject_point(aPos.x, aPos.y, 
			0.0f, view, projection).xyz;
	far_point = unproject_point(aPos.x, aPos.y, 
			1.0f, view, projection).xyz;
	gl_Position = vec4(aPos, 1.0);
}
