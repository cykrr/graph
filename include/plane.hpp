#ifndef PLANE_H
#define PLANE_H
#include "glad/glad.h"
#include "shaders.hpp"
#include "program.hpp"


class Plane {
	public: 
		Plane();
		Program* program;
		void draw(glm::mat4 * Model, glm::mat4 * View, glm::mat4 * Projection);
	private:
		float vertices[18] = {
		 1.0f, 	1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,

		-1.0f, -1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		};
		int vertices_size = 18;
};
#endif
