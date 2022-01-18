#ifndef ELEMENT_H
#define ELEMENT_H
#include "window_manager.hpp"
#include "program.hpp"
class Element {
	friend class WindowManager;
	public:
		Element();
		void set_vertices(float* vertices, int vertices_count, int dim);
		virtual void draw();
		void set_mat4(std::string name, glm::mat4 & mat);
	protected:
		float* vertices;
		int vertices_count;
		unsigned int VAO;
		unsigned int VBO;
		Program* program;
		int dim;

		void init_vertex_arrays();
		void add_vertices_to_program();
};
#endif
