
/*
This file defines all the data structures
used in the application
*/

#pragma once


//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>



#include <iostream>
#include <string>
#include <vector>



#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;


struct Rect
{
    float x = 0.0f;
    float y = 0.0f;
    float width = 1.0f;
    float height = 1.0f;
};

struct Vertex2D {
    // position
    glm::vec3 Position;
    
    // uv
    glm::vec2 TexCoords;

    //texture ID
    float TextureID;

    //color
    glm::vec4 Color;
};


struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};

//for retrive data with ASSIMP library during obj file loading
struct Texture {
    unsigned int id;
    string type;
    string path;
};

struct TextureData{
    unsigned int ID;
    //const char* path;
    //const char* name;
    string path;
    string name;
};

struct Mesh2DData
{
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<TextureData> textures;
};
struct MeshData
{
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    TextureData texture;
};


struct Mesh2D{
    unsigned int VAO;
    unsigned int indices_size;
};
struct Mesh{
    unsigned int VAO;
    unsigned int indices_size;
};


struct TransformData{
    vec3 pos = vec3(0.0f,0.0f,0.0f);
    vec3 rot = vec3(0.0f,0.0f,0.0f);
    vec3 scale = vec3(1.0f,1.0f,1.0f);
};

struct ShaderData{
    const char* vs_path;
    const char* fs_path;
};

struct MatrialData{

};


/*
struct VertexData {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};
*/

/*
struct TextureData {
    unsigned int id;
    string type;
    string path;
};
*/


//for loading and saving to file
struct ModelData
{
    vector<MeshData> mesh_data_array;
    vector<TextureData> loaded_textures;
    string path;
};


struct CameraData
{

};

struct LightData
{

};
//for loading and saving to file
struct SceneData
{
    vector<ModelData> model_data_array;
    vector<LightData> light_data_array;
    CameraData camera_data;
    string path;
};


