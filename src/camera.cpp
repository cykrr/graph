#include "camera.hpp"

Camera::Camera(){

	this->position = glm::vec3(0.0f, 1.0f, -3.0f);
	this->front = glm::vec3(0.0f, 0.0f, -1.0f);
	this->up = glm::vec3(0.0f, 1.0f, 0.0f);

	this->yaw = 90.0f;
	this->pitch = -5.0f;

	this->last_x = 800/2;
	this->last_y = 600/2;

	this->FOV = 45.0f;

	this-> first_mouse_cam = true;

}

void Camera::update(double pos_x, double pos_y){
	if(this->first_mouse_cam){
		this->last_x = pos_x;
		this->last_y = pos_y;
		this->first_mouse_cam = false;
	}
	float offset_x = pos_x - last_x;
	float offset_y = last_y - pos_y; /* y is upside down */

	this->last_x = pos_x;
	this->last_y = pos_y;

	float sensitivity = 0.1f;
	offset_x *= sensitivity;
	offset_y *= sensitivity;

	yaw += offset_x;
	pitch += offset_y;

	 // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

	glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    this->front = glm::normalize(front);
}

