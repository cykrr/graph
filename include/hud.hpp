#ifndef HUD_H
#define HUD_H
#include "program.hpp"
class Hud {
	public:
		Hud();
	private:
		glm::mat4 projection;
		Program* program;
};
#endif 
