#version 330 core

layout (location = 0) in vec3 aPos;

out vec3 near_point;
out vec3 far_point;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;


vec3 
unproject_point(float x, float y, float z, mat4 Model, mat4 View, mat4 Poojection){
	mat4 inv_m = inverse(Model);
	mat4 inv_v = inverse(View);
	mat4 inv_p = inverse(Projection);

	vec4 unprojected_point = 
		inv_m * inv_v * inv_p * vec4(x, y, z, 1.0f);

	return unprojected_point.xyz / unprojected_point.w;
}



void main(){
	near_point = unproject_point(aPos.x, aPos.y, 
			0.0f, Model, View, Projection).xyz;
	far_point = unproject_point(aPos.x, aPos.y, 
			1.0f, Model, View, Projection).xyz;
	gl_Position = vec4(aPos, 1.0);
}
