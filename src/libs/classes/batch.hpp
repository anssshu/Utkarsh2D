
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <GLES3/gl3.h>
#include "../data_structures/data_structures.hpp"

#include <array>
#include "quad.hpp"
using namespace std;
class Batch
{
    public:
   
    vector<Quad*> quad_array;

    vector<unsigned int> textures;
    
    unsigned int shaderProgram;
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

    
};