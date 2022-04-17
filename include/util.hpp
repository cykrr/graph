#ifndef util_h
#define util_h
#include "GLFW/glfw3.h"
namespace Time {
    extern float dt;
    extern double now, then;

    void update();
}
#endif
