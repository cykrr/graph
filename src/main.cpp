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
	Program* plane_program = new Program("plane.vs", "plane.fs");
	Program* common_program = new Program("common.vs", "common.fs");

	//	Plane* plane = new Plane();

	Element* element = new Element();

	float cube_vertices[] = {
		-0.5f, -0.5f, -0.5f,  
		0.5f, -0.5f, -0.5f,  
		0.5f,  0.5f, -0.5f,  
		0.5f,  0.5f, -0.5f,  
		-0.5f,  0.5f, -0.5f,  
		-0.5f, -0.5f, -0.5f,  
		-0.5f, -0.5f,  0.5f,  
		0.5f, -0.5f,  0.5f,  
		0.5f,  0.5f,  0.5f,  
		0.5f,  0.5f,  0.5f,  
		-0.5f,  0.5f,  0.5f,  
		-0.5f, -0.5f,  0.5f,  
		-0.5f,  0.5f,  0.5f,  
		-0.5f,  0.5f, -0.5f,  
		-0.5f, -0.5f, -0.5f,  
		-0.5f, -0.5f, -0.5f,  
		-0.5f, -0.5f,  0.5f,  
		-0.5f,  0.5f,  0.5f,  

		0.5f,  0.5f,  0.5f,  
		0.5f,  0.5f, -0.5f,  
		0.5f, -0.5f, -0.5f,  
		0.5f, -0.5f, -0.5f,  
		0.5f, -0.5f,  0.5f,  
		0.5f,  0.5f,  0.5f,  

		-0.5f, -0.5f, -0.5f,  
		0.5f, -0.5f, -0.5f,  
		0.5f, -0.5f,  0.5f,  
		0.5f, -0.5f,  0.5f,  
		-0.5f, -0.5f,  0.5f,  
		-0.5f, -0.5f, -0.5f,  

		-0.5f,  0.5f, -0.5f,  
		0.5f,  0.5f, -0.5f,  
		0.5f,  0.5f,  0.5f,  
		0.5f,  0.5f,  0.5f,  
		-0.5f,  0.5f,  0.5f,  
		-0.5f,  0.5f, -0.5f,  
	};
	element->set_vertices(cube_vertices, 36, 3);

	float vertices[] = {
		1.0f, 	1.0f, 0.0f, 
		-1.0f, -1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,

		-1.0f, -1.0f, 0.0f,
		1.0f,  1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,


	};

	glBindVertexArray(plane_program->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, plane_program->VBO);


	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices) , nullptr, GL_DYNAMIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof (float), (void*)0);
	glEnableVertexAttribArray(0);


	while (!glfwWindowShouldClose(wm->window)){
		wm->update_dt();
		wm->process_input();
		wm->clear();

		glm::mat4 projection = glm::perspective(glm::radians(wm->cam->FOV), 
				wm->get_width() / wm->get_height(), near_plane, far_plane);

		glm::mat4 view = glm::lookAt(wm->cam->position, wm->cam->position + wm->cam->front, 
				wm->cam->up);

		glm::mat4 model = glm::mat4(1.0f);

		glm::mat4 MVP =  projection * view *  model;




		common_program->bare_use();
		common_program->set_mat4("MVP", MVP);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(cube_vertices), 
				cube_vertices);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		plane_program->bare_use();
		plane_program->set_mat4("MVP", MVP);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glDrawArrays(GL_TRIANGLES, 0, 6);





		glfwSwapBuffers(wm->window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
