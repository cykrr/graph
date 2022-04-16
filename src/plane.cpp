#include "plane.hpp"
// init program
// bind plane VAO
// enable attribute pointers
Plane::Plane(){
        if(!this->program) {
            this->program = new Program("plane");
            this->program->use();
            this->program->set_mat4("View", glm::mat4(1.f));
            this->program->set_mat4("Projection", glm::mat4(1.f));
        }
        this->createBuffers();
        this->enableAttribArray();
        this->allocateVertexData();
} 

// use plane program
// send matrices
// send buffer data
// draw
void Plane::draw(){
	this->program->bare_use();
        this->bindBuffers();

	glBufferSubData(GL_ARRAY_BUFFER, 0, 
                sizeof(float)*this->vertices_size, vertices);

	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Plane::createBuffers() {
    glGenVertexArrays(1, &Vao);
    glGenBuffers(1, &Vbo);
}

void Plane::bindBuffers() {
    glBindVertexArray(this->Vao);
    glBindBuffer(GL_ARRAY_BUFFER, this->Vbo);
}

void Plane::enableAttribArray() {
    this->bindBuffers();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Plane::allocateVertexData() {
    this->bindBuffers();
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), this->vertices,
            GL_STATIC_DRAW);
}

float Plane::vertices[30] = {
		 1.0f, 	1.0f, 0.0f, 
		-1.0f, -1.0f, 0.0f, 
		-1.0f,  1.0f, 0.0f, 
		-1.0f, -1.0f, 0.0f, 
		 1.0f,  1.0f, 0.0f, 
		 1.0f, -1.0f, 0.0f, 
		};

size_t Plane::vertices_size = 30;
Program *Plane::program = NULL;
