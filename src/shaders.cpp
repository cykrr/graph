#include "shaders.hpp"

Shader::Shader(std::string name, unsigned int shader_type){
	this->name = name;

	std::string add = "";
	
	std::ifstream input;
	std::stringstream buffer;
	std::string source_string;
	/* catch exception */
	input.exceptions(std::ifstream::badbit|std::ifstream::failbit);
	try {
		if(shader_type == GL_VERTEX_SHADER)
			add = ".vs";
		else if (shader_type == GL_FRAGMENT_SHADER)
			add = ".fs";
		input.open("./shaders/" + name + add);
		buffer << input.rdbuf();
		input.close();
		source_string = buffer.str();
	} catch (std::ifstream::failure error){
		std::cout << name + add + " not found" << std::endl;
		exit(3);
	}

	this->shader = glCreateShader(shader_type);
	const char* source_cstr = source_string.c_str();
	glShaderSource(this->shader, 1, &(source_cstr), NULL);
	glCompileShader(this->shader);
	
	int  success = 1;
	char log[512];
	glGetShaderiv(this->shader, GL_COMPILE_STATUS, &success);
	if (!success){ 
		glGetShaderInfoLog(this->shader, 
				512, NULL, log);

		std::cout << "error compiling shader "  << this->name
			<< add << "\n" << log;
	}
}

