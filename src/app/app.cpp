#include "app.hpp"
#include "mainBatch.hpp"
Application::Application():Display(1200,900,"CPP GLES3 APPLICATION")
{
    //init the display
    //give input object of the display to main batch
    MainBatch* batch = new MainBatch(input);
    batch_renderer->addBatch(batch);


    
    
    //connect the input object to all inputs
    batch->input = input;
    batch->camera->input = input;
   
   

    //choose a batch to render
    batch_renderer->loadBatch(0);
}