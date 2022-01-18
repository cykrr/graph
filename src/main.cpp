const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

#include "camera.hpp"
#include "window_manager.hpp"
#include "shaders.hpp"
#include "program.hpp"
#include "color.hpp"
#include "element.hpp"

#include "plane.hpp"


int main () {
	WindowManager* wm = new WindowManager();
	Program* program = new Program("plane.vs", "plane.fs");
	
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

	glBindVertexArray(program->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, program->VBO);

		
	glBufferData(GL_ARRAY_BUFFER, 30*sizeof(float) , nullptr, GL_DYNAMIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof (float), (void*)0);
	glEnableVertexAttribArray(0);


	while (!glfwWindowShouldClose(wm->window)){
		wm->update_dt();
		wm->process_input();
		wm->clear();


		
		glm::mat4 projection = glm::perspective(glm::radians(wm->cam->FOV), 
				 wm->get_width() / wm->get_height(), 0.1f, 100.0f);
		

		 glm::mat4 view = glm::lookAt(wm->cam->position, wm->cam->position + wm->cam->front, 
				 wm->cam->up);

		 glm::mat4 model = glm::mat4(1.0f);

		 glm::mat4 MVP =  projection * view *  model;
		 
		 element->set_mat4("MVP", MVP);
		 program->set_mat4("MVP", MVP);


		element->draw();
		program->use();
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

		glDrawArrays(GL_TRIANGLES, 0, 6);



		glfwSwapBuffers(wm->window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
