#ifndef PROGRAM_H
#define PROGRAM_H
#include "glm/mat4x4.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

#include "shaders.hpp"
class Program{
	public:
		/* receives the vertex and the fragment names to be used */
		Program(std::string shader_name);
		void use();
		void bare_use();
		void set_mat4(std::string name, glm::mat4 & matrix);
		void set_vec3(std::string name, glm::vec3 & vec);
		void set_vec3(std::string name, glm::vec3  vec);

		unsigned int VAO, VBO;

	private:
		void check_compile_errors(Shader* shader);

		Shader* vertex;
		Shader* fragment;

		unsigned int program;

		void init_vertex_arrays();
};

#endif
