#version 330 core

layout (location = 0) in vec3 aPos;

out vec3 near_point;
out vec3 far_point;

vec3 
unproject_point(float x, float y, float z, mat4 view, mat4 proj){
	mat4 inv_view = inverse(view);
	mat4 inv_proj = inverse(view);

	vec4 unprojected_point = 
		inv_view * inv_proj * vec4(x, y, z, 1.0f);

	return unprojected_point.xyz / unprojected_point.w;
}


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
	near_point = unproject_point(aPos.x, aPos.y, 
			0.0f, view, projection).xyz;
	far_point = unproject_point(aPos.x, aPos.y, 
			1.0f, view, projection).xyz;
	gl_Position = vec4(aPos, 1.0);
}
