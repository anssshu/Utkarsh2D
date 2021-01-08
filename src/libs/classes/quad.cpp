#include "quad.hpp"

Quad::Quad(float x ,float y ,float textureID)
{
    //this->texture_path = texture_path;
    this->pos = vec2(x,y);
    this->vertex_texture_ID = textureID;


    float size = 0.5;
    
    Vertex2D v0,v1,v2,v3;
    
        //top left
    v0.Position = vec3(-1.0f*size,size,0.0f);
    v0.TexCoords = vec2(0.0f,1.0f);
    v0.TextureID = textureID;
    v0.Color = vec4(0.0,1.0,0.0,1.0);

    //top right
    v1.Position = vec3(size,size,0.0f);
    v1.TexCoords = vec2(1.0f,1.0f);
    v1.TextureID = textureID;
    v1.Color = vec4(1.0);

    //bottom right
    v2.Position = vec3(size,-1*size,0.0f);
    v2.TexCoords = vec2(1.0f,0.0f);
    v2.TextureID = textureID;
    v2.Color = vec4(1.0);
    //bottom left
    v3.Position = vec3(-1.0f*size,-1.0f*size,0.0f);
    v3.TexCoords = vec2(0.0f,0.0f);
    v3.TextureID = textureID;
    v3.Color = vec4(1.0);

    this->vertices = {v0,v1,v2,v3};
    this->_vertices = {v0,v1,v2,v3};

    width = std::abs(v1.Position.x-v0.Position.x);
    height = std::abs(v3.Position.y-v0.Position.y);

}

//update the position location and scale of each vertices
void Quad::updateTransform()
{
    
   
    
    
    transform = mat4(1.0);
    transform = glm::translate(mat4(1.0),vec3(pos.x,pos.y,0.0))*glm::rotate(mat4(1.0),glm::radians(rot),vec3(0.0,0.0,1.0))*glm::scale(mat4(1.0),vec3(scale.x,scale.y,1.0));
    //transform = ;
    //transform = ;
    
    //update all vertices of the quad
    for (int i=0;i<4;i++)
    {
        vec4 my_vec4 = transform*vec4(this->_vertices[i].Position,1.0);
        this->vertices[i].Position = vec3(my_vec4.x/my_vec4.w,my_vec4.y/my_vec4.w,my_vec4.z/my_vec4.w);
    }
    
}
/*
void Quad::update()
{
    //rot += 1.0;
}
*/
void Quad::updateUVRect(Rect r)
{
    this->vertices[0].TexCoords = vec2(r.x,r.y+r.height);
    this->vertices[1].TexCoords = vec2(r.x+r.width,r.y+r.height);
    this->vertices[2].TexCoords = vec2(r.x+r.width,r.y);
    this->vertices[3].TexCoords = vec2(r.x,r.y);
}