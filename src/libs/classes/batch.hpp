#pragma once
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <GLES3/gl3.h>
#include "../data_structures/data_structures.hpp"
#include "camera.hpp"
#include <array>
#include <map>
#include "quad.hpp"
#include  <string>
#include "input.hpp"
using namespace std;
class Batch
{
    public:
    Input* input;
    Camera* camera;
    
    vector<Quad*> quad_array;

    map<string,unsigned int> texture_map;//path,id
    vector<string> textures;
    
    unsigned int shaderProgram,texture1;
    static const unsigned int maxQuad = 1000;
    static const unsigned int maxVertices = 4*maxQuad;
    static const unsigned int maxIndices = maxQuad*6;

    Vertex2D vertices[maxVertices];
    unsigned int indices[maxIndices];

    unsigned int VAO,VBO,EBO;
    Batch();
    ~Batch();
   
    
    

    

    void loadBatch(); //create VAO from the vertex data and create the indices
    void unloadBatch();
    void renderBatch();
    void addQuad(Quad* q);
    void updateQuads();//update all the vertices of the quads and create the final batch vertices of a single geometry;
    void addtexture(string texture_path);
    virtual void update()=0;

    
};