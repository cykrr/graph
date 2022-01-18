#include "plane.hpp"
Plane::Plane(){
	glGenVertexArrays(1, &(this->VAO));
	glGenBuffers(1, &(this->VBO));

	this->vertex_shader = new Shader("plane.vs", GL_VERTEX_SHADER);
	this->fragment_shader = new Shader("plane.fs", GL_FRAGMENT_SHADER);

	this->program = glCreateProgram();

	glAttachShader(this->program, this->vertex_shader->shader);
	glAttachShader(this->program, this->fragment_shader->shader);

	glLinkProgram(this->program);

	GLint success;
	GLchar info_log[1024];
	glGetShaderiv(vertex_shader->shader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(vertex_shader->shader, 1024, NULL, info_log);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << "PROGRAM" << "\n" << 
			info_log << "\n -- --------------------------------------------------- -- " << std::endl;
	}

	glGetShaderiv(fragment_shader->shader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(fragment_shader->shader, 1024, NULL, info_log);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << "PROGRAM" << "\n" << 
			info_log << "\n -- --------------------------------------------------- -- " << std::endl;
	}

	 float vertices[] = {
		 0.0f, 0.0f, 0.0f,
		 0.0f, 0.0f, 0.1f
	 };

	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0 );
	glEnableVertexAttribArray(0);

	 glBindBuffer(GL_ARRAY_BUFFER, 0); 
     glBindVertexArray(0); 
	

}

void Plane::use(){
	glUseProgram(this->program);
	glBindVertexArray(this->VAO);
}
void Plane::draw(){
	 this->use();
	 glDrawArrays(GL_LINES, 0, 2);
}
