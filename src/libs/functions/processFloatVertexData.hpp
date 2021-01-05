#pragma once
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <GLES3/gl3.h>

#include "../data_structures/data_structures.hpp"


//vertices with floats
struct VertexData{
    //vertices
    vector<float> vertices = {
     //pos                  //uv cord   
     0.5f,  0.5f, 0.0f,     1.0f,1.0f,// top right
     0.5f, -0.5f, 0.0f,     1.0f,0.0f, // bottom right
    -0.5f, -0.5f, 0.0f,     .0f,0.0f, // bottom left
    -0.5f,  0.5f, 0.0f,     0.0f,1.0f// top left 
    };
    //indices
    vector<unsigned int> indices={  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
    };
};

Mesh processFloatVertexData(VertexData vertex_data);