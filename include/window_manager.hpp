#ifndef WM_H
#define WM_H
#include <GLFW/glfw3.h>
#include <iostream>
class WindowManager{
		float delta_time, last_frame;
	public:
		WindowManager();
		void update_dt();
		void init_gl();

		void framebuffer_callback(GLFWwindow* window, int x, int y );
		
		GLFWwindow*  window;
};
#endif
