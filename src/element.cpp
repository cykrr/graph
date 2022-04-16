#include "element.hpp"

Element::Element(){
	this->vertices = NULL;
	this->vertices_count = 0;

	this->program = new Program("common");
}

void Element::set_vertices(float* vertices, int vertices_count, int dim){
	this->vertices = vertices;
	this->vertices_count = vertices_count;
	this->dim = dim;

	this->allocateVertexData();
}

void Element::allocateVertexData(){
        this->bindBuffers();

	glBufferData(GL_ARRAY_BUFFER,
			this->dim * this->vertices_count * sizeof(float), 
			this->vertices,
			GL_STATIC_DRAW);

	glVertexAttribPointer(0, dim, GL_FLOAT, GL_FALSE, dim* sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);

}

void Element::draw(){
	this->program->use();
	this->program->set_vec3("in_color", glm::vec3(1.0f, 1.0f, 1.0f));
	glDrawArrays(GL_TRIANGLES, 0, this->vertices_count);

}

void Element::set_mat4(std::string name, glm::mat4 & matrix){
	this->program->set_mat4(name, matrix);
}

void Element::bindBuffers() {
    glBindVertexArray(Vao);
    glBindBuffer(GL_ARRAY_BUFFER, Vbo);
}
