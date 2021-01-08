#pragma once
#include <iostream>
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <GLES3/gl3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "input.hpp"
#include "sprite.hpp"
using namespace std;
using namespace glm;
//-----------------------------------------------------------------------CAMERA 2D----------------------------------------------------------
class Camera{
    public:
    Sprite* player;
    Input* input;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    glm::vec3 up;
    glm::vec3 pos;
    glm::vec3 target;
    glm::vec3 rot;
    float fov = 45.0f;
    int width = 800;
    int height = 600;
    float near = 0.1f;
    float far = 100.0f;
    //constructor
    Camera();
    
    ~Camera();
    
    void updateCamera();
    void processInput();



    void setUniforms(unsigned int shaderProgram);
   
};






