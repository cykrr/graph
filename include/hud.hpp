#ifndef HUD_H
#define HUD_H
#include "program.hpp"
#include "window_manager.hpp"
class Hud {
	public:
		Hud(WindowManager* wm);
		void draw();
		void update_matrix(float, float);

		Program* program;
	private:
		glm::mat4 Projection;

		float triangle[9] = {  0.0f,   0.0f, 0.0f,
							200.0f, 200.0f, 0.0f,
							200.0f,   0.0f, 0.0f
		};

};
#endif 
