#include "rect.hpp"

Rect2::Rect2()
{
    //top left
    v0.Position = vec3(-1.0f,1.0f,0.0f);
    v0.Normal = vec3(0.0f,0.0f,-1.0f);
    v0.TexCoords = vec2(0.0f,1.0f);
    v0.Tangent = vec3(1.0f,0.0f,0.0f);
    v0.Bitangent = vec3(0.0f,1.0f,0.0f);

    //top right
    v1.Position = vec3(1.0f,1.0f,0.0f);
    v1.Normal = vec3(0.0f,0.0f,-1.0f);
    v1.TexCoords = vec2(1.0f,1.0f);
    v1.Tangent = vec3(1.0f,0.0f,0.0f);
    v1.Bitangent = vec3(0.0f,1.0f,0.0f);

    //bottom right
    v2.Position = vec3(1.0f,-1.0f,0.0f);
    v2.Normal = vec3(0.0f,0.0f,-1.0f);
    v2.TexCoords = vec2(1.0f,0.0f);
    v2.Tangent = vec3(1.0f,0.0f,0.0f);
    v2.Bitangent = vec3(0.0f,1.0f,0.0f);

    //bottom left
    v3.Position = vec3(-1.0f,-1.0f,0.0f);
    v3.Normal = vec3(0.0f,0.0f,-1.0f);
    v3.TexCoords = vec2(0.0f,0.0f);
    v3.Tangent = vec3(1.0f,0.0f,0.0f);
    v3.Bitangent = vec3(0.0f,1.0f,0.0f);

    mesh_data.vertices = {v0,v1,v2,v3};
    mesh_data.indices = {0,1,2,2,3,0};

    mesh = createMesh(mesh_data);

    this->shader = new Shader("shaders/sprite.vs","shaders/sprite.fs");
    this->shader->use();
    shader->loadTextureData({12,"textures/wood.jpg","texture1"});

    shader->loadVertexData(mesh);

    
}

