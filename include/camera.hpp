#ifndef CAMERA_H
#	define CAMERA_H
#include <glm/vec3.hpp>
class Camera { 
	bool first_mouse_cam;

	glm::vec3 
		position, front, up;

	float 
		yaw, pitch,
		last_x, last_y,
		FOV;
	public:
		Camera();

};
#endif
