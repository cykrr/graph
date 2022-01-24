const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const float near_plane = 0.01f;
const float far_plane = 100.0f;

#include "camera.hpp"
#include "window_manager.hpp"
#include "shaders.hpp"
#include "program.hpp"
#include "color.hpp"
#include "element.hpp"

#include "plane.hpp"


int main () {
	WindowManager* wm = new WindowManager();
	Plane* plane = new Plane();

	Program* common_program = new Program("common");
//	Program* gui_program = new Program("gui.vs", "gui.fs");


	float cube_vertices[] = {
		 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,          
		  0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 
		 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	while (!glfwWindowShouldClose(wm->window)){
		wm->update_dt();
		wm->process_input();
		wm->clear();

		glm::mat4 Projection = glm::perspective(glm::radians(wm->cam->FOV), 
				wm->get_width() / wm->get_height(), 
				near_plane, far_plane);

		glm::mat4 View = glm::lookAt(wm->cam->position, 
				wm->cam->position + wm->cam->front, 
				wm->cam->up);

		glm::mat4 Model = glm::mat4(1.0f);

		plane->program->use();

		common_program->bare_use();
		Model = glm::translate(Model, glm::vec3(-0.5f, 0.5f, 0.5f));
		common_program->set_mat4("Model", Model);
		common_program->set_mat4("View", View);
		common_program->set_mat4("Projection", Projection);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(cube_vertices), 
				cube_vertices);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		plane->draw(&Model, &View, &Projection);

		glfwSwapBuffers(wm->window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
