#pragma once

#include "scene.hpp"
#include "rect.hpp"
class Renderer2D
{   
    public:
   
    //container for the scene
    Scene* current_scene;//----interface has a current scene
 
    vector<Scene*> scene_array;

    //constructor
    Renderer2D();
    //destructor
    ~Renderer2D();
    void addScene(Scene* scene);
   
    //load scene 
    void loadScene(unsigned int ID);
    //function to render the current scene
    void renderScene();

   
    void update();
    void reset();



};
