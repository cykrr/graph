#ifndef CAMERA_H
#	define CAMERA_H
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <iostream>
class Camera { 


	float 
		yaw, pitch,
		last_x, last_y;

	public:
		Camera();
		void set_speed(float speed);
		float speed, FOV;

	glm::vec3 
		position, front, up;

	public:
		bool first_mouse_cam;
		void update(double, double);

};
#endif
