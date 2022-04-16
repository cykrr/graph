#ifndef CAMERA_H
#	define CAMERA_H
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <iostream>
class Camera { 
public:
    Camera();

    // Possible camera movements to abstract keyboard
    enum Direction {
        Forward, // W
        Backwards, // S
        Left, // A
        Right // D
    };

    glm::mat4 projection, view;
    glm::vec3 position, up, front, right, worldUp;

		float speed, FOV;
    float 
            last_x, last_y,
            yaw = -90.f,
            pitch = 0.f,

	glm::vec3 
		position, front, up;

    bool first_mouse_cam;


    void set_speed(float speed);
    void resizeCallback(double, double);
    private:
            void set_front();

};
#endif
