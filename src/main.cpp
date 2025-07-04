const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const float near_plane = 0.01f;
const float far_plane = 100.0f;

#include "stb_image.h"

#include "camera.hpp"
#include "window_manager.hpp"
#include "program.hpp"


#include "hud.hpp"
#include "plane.hpp"

#include <GLFW/glfw3.h>

double lastTime=0, nbFrames=0;

void show_fps(GLFWwindow *pWindow){
  // Measure speed
  double currentTime = glfwGetTime();
  double delta = currentTime - lastTime;
  nbFrames++;

  double fps = 1 / delta;

  printf("[FPS]: %f.00\n", fps);

  nbFrames = 0;
  lastTime = currentTime;
}


int main () {
  WindowManager* wm = new WindowManager();
  Plane* plane = new Plane();

  Program* common_program = new Program("common");

  Hud* hud = new Hud(wm);

  glm::mat4 Projection;


  float cube_vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,          
    0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
  };


  unsigned int texture1;
  glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);

  /* set wrapping params */
  glTexParameteri(GL_TEXTURE_2D,
                  GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,
                  GL_TEXTURE_WRAP_T, GL_REPEAT);

  /* set texture filter params */
  glTexParameteri(GL_TEXTURE_2D, 
                  GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,
                  GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  /* load img */
  int width, height, nr_channels;
  stbi_set_flip_vertically_on_load(true);

  unsigned char* data = stbi_load("wall.jpg", 
                                  &width, &height, &nr_channels, 0);

  if(data){
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture;\n";
  }


  stbi_image_free(data);

  common_program->bare_use();
  common_program->set_int("texture1", 0);


  glVertexAttribPointer(0, 3, GL_FLOAT, 
                        GL_FALSE, 3*sizeof(float), (void*)0);

  glEnableVertexAttribArray(0);


  while (!glfwWindowShouldClose(wm->window)){
    wm->update_dt();
    show_fps(wm->window);
    wm->process_input();
    wm->clear();

    glm::mat4 Projection = glm::perspective(
      glm::radians(wm->cam->FOV), 
      wm->get_width()/wm->get_height(), 
      near_plane, far_plane);

    glm::mat4 View = glm::lookAt(
      wm->cam->position, 

      wm->cam->position + 
      wm->cam->front, 

      wm->cam->up);

    glm::mat4 Model = glm::mat4(1.0f);
    plane->program->use();

    common_program->bare_use();
    common_program->set_mat4("View", View);
    common_program->set_mat4("Projection", 
                             Projection);

    glBufferSubData(GL_ARRAY_BUFFER, 0,
                    sizeof(cube_vertices), 
                    cube_vertices);

    if(glfwGetKey(wm->window, GLFW_KEY_P) == 
      GLFW_PRESS)
      plane->draw(&Model, &View, 
                  &Projection);



    for(int i=0; i < 10; i++){
      for(int j=0; j < 10; j++){
        Model = glm::translate(
          glm::mat4(1.0f), 
          glm::vec3(
            i + 0.5f,
            0.5f,
            j + 0.5f)
        );
        common_program->set_mat4("Model",
                                 Model);

        glDrawArrays(GL_TRIANGLES, 0, 36);
      }
    }

    hud->update_matrix(wm->get_width(), 
                       wm->get_height()
                       );
    hud->draw();





    glfwSwapBuffers(wm->window);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}
