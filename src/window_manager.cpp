#include "window_manager.hpp"
WindowManager::WindowManager(){
	this->delta_time = 0.0f;
	this->last_frame = 0.0f;

	
	init_gl();

}

void WindowManager::framebuffer_callback(GLFWwindow* window, int x, int y){
	glViewport(0, 0, x, y);
}

void WindowManager::init_gl(){
	glfwInit();

	/* gl version */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* couldn't care less about supporting apple */
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif 

	this->window =  glfwCreateWindow(800, 600, "new", NULL, NULL);
	if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

	glfwMakeContextCurrent(this->window);

	glfwSetWindowUserPointer(this->window, this);

	auto func = [](GLFWwindow* w, int x, int y){
		static_cast<WindowManager*>(glfwGetWindowUserPointer(w))->framebuffer_callback(w, x, y);
	};

	glfwSetFramebufferSizeCallback(this->window, func);


}
