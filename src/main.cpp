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
void onFramebufferResize(GLFWwindow *window, int x, int y);

int main () {
    Container container;
    WindowManager wm;
    Camera cam;

    container.camera = &cam;
    container.wm = &wm;


    glfwSetFramebufferSizeCallback(wm.window, onFramebufferResize);

    auto mouse_func = [](GLFWwindow* w, double pos_x, double pos_y){
        static_cast<Container*>(glfwGetWindowUserPointer(w))->camera->update(pos_x, pos_y);
    };

    glfwSetCursorPosCallback(wm.window, mouse_func);

    glfwSetInputMode(wm.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetWindowUserPointer(wm.window, &container);


    Plane* plane = new Plane();
    container.programs.push_back(plane->program);


    glClearColor(0.2f, 0.2f, 0.f, 1.f);
    while (!glfwWindowShouldClose(wm.window)){
        Time::update();

        glm::mat4 View = glm::lookAt(
                cam.position, 

                cam.position + 
                cam.front, 

                cam.up);

        wm.process_input();

        glClear(
                
                GL_COLOR_BUFFER_BIT |
                GL_DEPTH_BUFFER_BIT);

        plane->program->use();
        plane->program->set_mat4("View", View);

        plane->draw();

        glfwSwapBuffers(wm.window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}


void onFramebufferResize(GLFWwindow *window, int x, int y) {
    Container *container = static_cast<Container*>
        (glfwGetWindowUserPointer(window));
    Camera *camera = container->camera;
    glViewport(0, 0, static_cast<GLsizei>(x),
            static_cast<GLsizei>(y));

    camera->resizeCallback(x, y);
    for(Program *program : container->programs) {
        program->use();
        program->set_mat4("Projection", camera->projection);
    }

    WindowManager::width = x;
    WindowManager::height = y;
}
