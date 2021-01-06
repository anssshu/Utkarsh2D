#include "model.hpp"


//--------------------------------------------MODEL IMPLEMENTATION----------------------------------------------------------------------------------


Model::Model(string const &path,const char* vertex_shader_path,const char* frag_shader_path)
{
    
    //load the mesh data
    
    Vertex v0,v1,v2,v3;

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

    

    //MeshData mesh_data;
    mesh_data.vertices = {v0,v1,v2,v3};
    mesh_data.indices = {0,1,2,2,3,0};
    
    
    
   
    
    

    //get the shader data 
    shader_data.vs_path = vertex_shader_path;
    shader_data.fs_path = frag_shader_path;

    mesh_data.texture = {0,path,"texture1"};

    //for creating mesh_arry connect to the renderer
    //shader = new Shader(vertex_shader_path,frag_shader_path);
    //load textures to the shader
    //shader->loadTextureList(data.loaded_textures);
    //cout<<"loaded--textures--count:::"<<data.loaded_textures.size()<<endl;

    //cout<<data.mesh_data_array.size()<<endl;
    //printModelData(mesh);
}
Model::~Model(){
    //delete shader;
    cout <<"model"<<ID<<" is dead"<<endl;
}

    
void Model::setPos(float x,float y,float z){
    pos.x =x ;
    pos.y = y;
    pos.z = z;
    //this->model = updateModelMatrix();
}

void Model::setRotZ(float angle_in_degree){
    rot.z = angle_in_degree;
    //this->model = updateModelMatrix();
}
void Model::setRotY(float angle_in_degree){
    rot.y = angle_in_degree;
    //this->model = updateModelMatrix();
}
void Model::setRotX(float angle_in_degree){
    rot.x = angle_in_degree;
    //this->model = updateModelMatrix();
}
void Model::setScale(float x,float y,float z){
    scale.x = x;
    scale.y = y;
    scale.z = z;
    //this->model = updateModelMatrix();
}
mat4 Model::updateModelMatrix(){
    model = mat4(1.0);
    model=translate(model,pos);
    model=rotate(model,radians(rot.x),vec3(1.0,0.0,0.0));
    model=rotate(model,radians(rot.y),vec3(0.0,1.0,0.0));
    model=rotate(model,radians(rot.z),vec3(0.0,0.0,1.0));
    model = glm::scale(model,scale);
    return model;
    //shader->setUniformMat4("model",model);
}
void Model::updateModelViewProjectionMatrix(Camera* cam){
    model = updateModelMatrix();
    shader->setUniformMat4("model",model);
    shader->setUniformMat4("view",cam->view);
    shader->setUniformMat4("projection",cam->projection);
}

void Model::update()
{
    float speed = 2.0;
    
    if (input->is_action_pressed("up"))
    {
        rot.z += 1.0*speed;
    }

    if (input->is_action_pressed("down"))
    {
        rot.z -= 1.0*speed;
    }

    if (input->is_action_pressed("left"))
    {
         pos.x -= 0.10*speed;
    }

    if (input->is_action_pressed("right"))
    {
        pos.x += 0.10*speed;
    }
}

void Model::loadModel()
{
    mesh = createMesh(mesh_data);

    //create a shader
    shader = new Shader(shader_data);

    shader->loadTextureData(mesh_data.texture);

    shader->loadVertexData(mesh);

    cout << "model loaded\n" << mesh.VAO;
}

void Model::renderModel(Camera* cam)
{
    shader->use();
    //calculate model matrix
    model = updateModelMatrix();
    //update model matrix
    shader->setUniformMat4("model",model);
    //upate view matrix
    shader->setUniformMat4("view",cam->view);
    //update projection matrix
    shader->setUniformMat4("projection",cam->projection);

    //shader->loadVertexData(mesh);
    //bind textures
    shader->bindTextures();
    //render container
    shader->renderContainer();
}