#include "program.hpp"

Program::Program(std::string vertex, std::string fragment){
	this->vertex = new Shader(vertex, GL_VERTEX_SHADER);
	this->fragment = new Shader(fragment, GL_FRAGMENT_SHADER);
	this->program = glCreateProgram();

	glAttachShader(this->program, this->vertex->shader);
	glAttachShader(this->program, this->fragment->shader);
	glLinkProgram(this->program);
	check_compile_errors(this->vertex);
	check_compile_errors(this->fragment);

	init_vertex_arrays();
}
void Program::use(){
	glUseProgram(this->program);
	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
}

void Program::set_mat4(std::string name, glm::mat4 & matrix){
	int location = glGetUniformLocation(this->program, name.c_str());
	glUniformMatrix4fv(location, 1, false, &matrix[0][0]);
}

void Program::check_compile_errors(Shader* shader){
	GLint success;
	GLchar info_log[1024];
	glGetShaderiv(shader->shader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(shader->shader, 1024, NULL, info_log);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << "PROGRAM" << "\n" << 
			info_log << "\n -- --------------------------------------------------- -- " << std::endl;
	}
}

void Program::set_vec3(std::string name, glm::vec3 vec){
	int location = glGetUniformLocation(this->program, name.c_str());
	glUniform3fv(location, 1, &vec[0]);

}

void Program::init_vertex_arrays(){
	glGenVertexArrays(1, &(this->VAO) );
	glGenBuffers(1, &(this->VBO));

	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

