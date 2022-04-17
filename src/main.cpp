const float near_plane = 0.1f;
const float far_plane = 100.0f;


#include "camera.hpp"
#include "window_manager.hpp"
#include "shaders.hpp"
#include "program.hpp"
#include "color.hpp"
#include "element.hpp"


#include "hud.hpp"
#include "plane.hpp"
#include "container.hpp"

#include "util.hpp"

#include <GLFW/glfw3.h>



void show_fps(GLFWwindow* window);

int main () {
    Container container;
    WindowManager wm;
    Camera cam;

    container.camera = &cam;
    container.wm = &wm;

    glfwSetWindowUserPointer(wm.window, &container);


    Plane* plane = new Plane();
    container.programs.push_back(plane->program);


    while (!glfwWindowShouldClose(wm.window)){
        Time::update();
        wm.process_input();
        wm.clear();

        glm::mat4 View = glm::lookAt(
                cam.position, 

                cam.position + 
                cam.front, 

                cam.up);


        plane->program->bare_use();
        plane->program->set_mat4("View", View);

        plane->draw();

        glfwSwapBuffers(wm.window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

