#include "hud.hpp"
/* as vao and vbo are not really part of Program() they should be instanciated as a class of its own?? */
Hud::Hud(WindowManager* wm){
	this->program = new Program("hud");
	this->Projection = glm::mat4(1.0f);

        /*
	glBindVertexArray(this->program->VAO);
	glBindBuffer(GL_ARRAY_BUFFER,  !!!!!!!! FIX
			this->program->VBO);
                        */

	glBufferData(GL_ARRAY_BUFFER, 
			sizeof(this->triangle), this->triangle, 
			GL_STATIC_DRAW);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
			3*sizeof(float), (void*)0);



}

/* we could only update the matrix when the size 
 * changes, we could make the resize callback part
 * of WindowManager so that it updates the
 * 2d_projection_matrix everytime the viewport has 
 * to be updated, so this setup is not ideal, but
 * it works as a PoC, so this comments works as a 
 * to-do */

/* will do ^ after i finish getting everything inside it's own class, which is the
 * part i usually struggle with :) */


/* hud is the same as scene in libmithra.. we have to have an add_element
 * method as well as a render method so we can freely add elements to the VAs*/

void Hud::update_matrix(float width, float height){
	this->program->use();
	this->Projection = glm::ortho(
			0.0f, width,
			0.0f, height, 0.f, 1.f);
	this->program->set_mat4("Projection", this->Projection);
}

void Hud::draw(){
		glDrawArrays(GL_TRIANGLES, 0, 3);
}
