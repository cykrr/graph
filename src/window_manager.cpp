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
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1);

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

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(1);
    }


	auto func = [](GLFWwindow* w, int x, int y){
		static_cast<Container *>(glfwGetWindowUserPointer(w))->wm->framebuffer_callback(w, x, y);
	};

	glfwSetFramebufferSizeCallback(this->window, func);

	auto mouse_func = [](GLFWwindow* w, double pos_x, double pos_y){
		static_cast<Container*>(glfwGetWindowUserPointer(w))->camera->resizeCallback(pos_x, pos_y);
	};

	glfwSetCursorPosCallback(this->window, mouse_func);
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glEnable(GL_DEPTH_TEST);

}

void WindowManager::update_dt(){
	float current_frame = glfwGetTime();
	this->delta_time = current_frame - this->last_frame;
	this->last_frame = current_frame;
}

void WindowManager::process_input()
{
    Camera *camera = static_cast<Container *>(glfwGetWindowUserPointer(this->window))->camera;

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    camera->speed = 2.5f * this->delta_time;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera->position += camera->speed * camera->front;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera->position -= camera->speed * camera->front;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera->position -= glm::normalize(glm::cross(camera->front, camera->up)) * camera->speed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera->position += glm::normalize(glm::cross(camera->front, camera->up)) * camera->speed;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera->position += camera->up * camera->speed;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        camera->position -= camera->up * camera->speed;
    if(glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
        camera->FOV += 1.f;
        printf("FOV: %.02f\n", camera->FOV);

    }
    if(glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS){ 
        camera->FOV -= 1.f;
        printf("FOV: %.02f\n", camera->FOV);
    }
}

float WindowManager::get_width(){
	int width, height;
	glfwGetWindowSize(this->window, &width, &height);
	return width;
}

float WindowManager::get_height(){
	int width, height;
	glfwGetWindowSize( this->window, &width, &height);
	return height;

}

void WindowManager::set_bg_color(Color color){
	this->bg_color = color;
}

void WindowManager::clear(){
	glClearColor(0.03f, 0.03f, 0.03f, 0.8f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
}
