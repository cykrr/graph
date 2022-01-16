#ifndef PROGRAM_H
#define PROGRAM_H
#include "glm/mat4x4.hpp"
#include <iostream>

#include "shaders.hpp"
class Program{
	public:
		Program();
		void use();
		void set_mat4(std::string name, glm::mat4 & matrix);
	private:
		void check_compile_errors(Shader* shader);

		Shader* vertex;
		Shader* fragment;

		unsigned int program;
};

#endif
