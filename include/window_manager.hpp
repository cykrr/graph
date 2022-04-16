#ifndef WM_H
#define WM_H
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "camera.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

#include "color.hpp"
class WindowManager{
		float delta_time, last_frame;
	public:
		GLFWwindow*  window;

		WindowManager();
		void update_dt();
		void init_gl();

		void framebuffer_callback(GLFWwindow* window, int x, int y );
		void mouse_callback(GLFWwindow* window, double pos_x, double pos_y);

		void process_input();

		float get_width(), get_height();
		

		void set_bg_color(Color color);
		void clear();

	private:
		Color bg_color;
};
#endif
