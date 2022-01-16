#include "camera.hpp"

Camera::Camera(){
	this-> first_mouse_cam = true;

	this->position = glm::vec3(0.0f, 0.0f, 3.0f);
	this->front = glm::vec3(0.0f, 0.0f, -1.0f);
	this->up = glm::vec3(0.0f, 0.0f, 1.0f);

	this->yaw = -90.0f;
	this->pitch = 0.0f;

	this->last_x = 800/2;
	this->last_y = 600/2;

	this->FOV = 45.0f;

}

