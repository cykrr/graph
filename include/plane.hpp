#ifndef PLANE_H
#define PLANE_H
#include "glad/glad.h"
#include "shaders.hpp"
#include "program.hpp"


class Plane {
public: 

    Plane();
    void draw();

    unsigned int Vao, Vbo; // IDK 
    static Program* program;

private:

    static size_t vertices_size;
    static float vertices[30];

    void createBuffers();
    void bindBuffers();
    void enableAttribArray();
    void allocateVertexData();
};
#endif
