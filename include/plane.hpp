#ifndef PLANE_H
#define PLANE_H
#include "glad/glad.h"
#include "shaders.hpp"
class Plane {
	public: 
		Plane();
		void draw();
		void use();
	private:
		unsigned int VAO, VBO;

		Shader*  vertex_shader;
		Shader*  fragment_shader;
		unsigned int program;
};
#endif
