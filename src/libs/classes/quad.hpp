#include <iostream>
#include <string>
#include <array>
#include "../data_structures/data_structures.hpp"
using namespace std;
class Quad
{
    public:
    string texture_path; //texture path of the corresponding quad
    float vertex_texture_ID; //texture id for each vertices for use in fragment shader
    array<Vertex2D,4> vertices; //all 4 vertices array 
    array<Vertex2D,4> _vertices;//original vertices
    mat4 transform = mat4(1.0); //transform matrix
    //pos rot scale
    vec2 pos = vec2(0.0,0.0);  
    vec2 scale = vec2(1.0,1.0);
    float rot = 180.0;

    Quad(float x = 0.0f ,float y = 0.0f,float vertex_texture_ID=0.0,string texture_path="");
    void updateTransform();

    void update();


};