#ifndef CONTAINER_H
#define CONTAINER_H
#include "camera.hpp"
#include "window_manager.hpp"
#include "program.hpp"


#include <vector>
class Container {
    public:
        Camera *camera;
        WindowManager *wm;
        std::vector<Program *> programs;
        void addProgram(Program *program);
};
#endif 
