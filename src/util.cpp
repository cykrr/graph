#include "util.hpp"
#include "GLFW/glfw3.h"
namespace Time {
    float dt = 0;
    double now = 0;
    double then = 0;

    void update() {
        now = glfwGetTime();
        dt = now - then;
        then = now;
    }
}


