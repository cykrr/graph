#include "util.hpp"
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


