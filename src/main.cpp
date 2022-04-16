const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

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

#include <GLFW/glfw3.h>

double lastTime=0, nbFrames=0;


void show_fps(GLFWwindow* window);

int main () {
	WindowManager* wm = new WindowManager();
	Plane* plane = new Plane();

	while (!glfwWindowShouldClose(wm->window)){
		wm->update_dt();
		wm->process_input();
		wm->clear();

		glm::mat4 Projection = glm::perspective(
				glm::radians(wm->cam->FOV), 
				wm->get_width()/wm->get_height(), 
				near_plane, far_plane);

		glm::mat4 View = glm::lookAt(
				wm->cam->position, 

				wm->cam->position + 
					wm->cam->front, 

				wm->cam->up);


                plane->program->bare_use();
		plane->program->set_mat4("View", View);
		plane->program->set_mat4("Projection", 
				Projection);

                plane->draw(&View, &Projection);
	
		glfwSwapBuffers(wm->window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void show_fps(GLFWwindow *pWindow){
    // Measure speed
     double currentTime = glfwGetTime();
     double delta = currentTime - lastTime;
     nbFrames++;
     if ( delta >= 1.0 ){ // If last cout was more than 1 sec ago
		 std::cout << double(nbFrames) << std::endl;

         double fps = double(nbFrames) / delta;

         std::stringstream ss;
         ss << " [" << fps << " FPS]";

         nbFrames = 0;
         lastTime = currentTime;
     }
}
