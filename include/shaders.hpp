#ifndef SHADERS_H
#    define SHADERS_H


#include <fstream>
#include <sstream>
#include <iostream>

#include "glad/glad.h"

#include <glm/glm.hpp>

#include <string>


class Shader {
	public:
		Shader(std::string name, unsigned int shader_type);
		~Shader();
		unsigned int shader;
	private:
		std::string name;
};

#endif
