#include "renderer.hpp"
#include "../functions/createMesh.hpp"
Renderer2D::Renderer2D()//:default_shader("shaders/default_shader.vs","shaders/default_shader.fs")
{
    

};

Renderer2D::~Renderer2D(){
    
    
};

void Renderer2D::addScene(Scene* scene){
    scene_array.push_back(scene);
}
void Renderer2D::loadScene(unsigned int ID){
    //if scene is loaed from the file then process it
                //LATER
    if (scene_array.size()>0)
    {
        //point this->scene to the input scene
        this->current_scene = scene_array[ID];

        //process all the model of the scene
        for (unsigned int j=0;j<current_scene->model_array.size();j++)
        {
            //process model data,shader data and load texture to each model
            //create a mesh array
            Model* Pmodel = current_scene->model_array[j];
            //Pmodel->mesh = createMesh(Pmodel->mesh_data);

            //create a shader nad point it to the the model
            //Pmodel->shader = new Shader(Pmodel->shader_data);

            //load texture
            //Pmodel->shader->loadTextureData(Pmodel->mesh_data.texture);
            Pmodel->loadModel();
            
            //give model an ID;
            Pmodel->ID = current_scene->model_array.size();
            
        }
    }
    
}

void Renderer2D::renderScene()
{
    
    
    //check for current_scene then render the model array
    if (current_scene != nullptr){

        //update the view matrix of camera and call the update function of each model
        this->update();

        for (unsigned int j=0;j<current_scene->model_array.size();j++)
        {
            //process each model in the model_arrray
        
            Model* model = current_scene->model_array[j];
            model->renderModel(current_scene->camera);
            
            
        }
    }
    //render each model inside the scene model_array
    
}


//load model to the curren scene
//process model data,shader data and load texture to a  model








//update camera and each model
void Renderer2D::update()
{
    //update the model and view matrix of the camera
    current_scene->camera->updateCamera();
    //update all the models
    for(unsigned int i=0;i<current_scene->model_array.size();i++)
    {
        current_scene->model_array[i]->update();
    }

    //  
}

void Renderer2D::reset()
{

}