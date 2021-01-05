#include "scene.hpp"

Scene::Scene(){

    //create a camera pointer 
    camera = new Camera();
}

void Scene::addModel(Model* pModel ){
    model_array.push_back(pModel);
}

void Scene::addLight(Light* pLight){
    light_array.push_back(pLight);
}
