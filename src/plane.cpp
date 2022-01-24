#include "plane.hpp"
Plane::Plane(){
	this->program = new Program("plane");
	glBindVertexArray(this->program->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->program->VBO);
	glBufferData(GL_ARRAY_BUFFER, 110*sizeof(float), nullptr, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Plane::draw(glm::mat4 *Model, glm::mat4 * View, glm::mat4 *Projection){
	this->program->bare_use();

	*Model = glm::mat4(1.0f);
	this->program->set_mat4("Model", *Model);
	this->program->set_mat4("View", *View);
	this->program->set_mat4("Projection", *Projection);


	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)*this->vertices_size, vertices);

	glDrawArrays(GL_TRIANGLES, 0, 6);
}

