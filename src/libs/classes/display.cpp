#include "display.hpp"
#include "model.hpp"
#include "shader.hpp"
#include "../functions/createMesh.hpp"

Display::Display(int WIDTH,int HEIGHT,const char* TITLE)
{
    //first create the display
    initDisplay(WIDTH,HEIGHT,TITLE);
    
    //create the input pointer  with the pointer of events on display
    input = new Input(&event);
    

    //create the renderer pointer
    //renderer = new Renderer2D();
    
    batch_renderer = new BatchRenderer();
  
    //r = new Rect();
     //create a scene
    //Scene* scene = new Scene();

    //create a model and add it to the scene

    //Model* plane = new Model("textures/mouse.jpg");
    //plane->input = &input;
    //scene->addModel(plane);

    //add a scene to the renderer
    //renderer->addScene(scene);

    //set the current scene and load it
    
}
void Display::initDisplay(int WIDTH,int HEIGHT, const char* TITLE)
{
    

    //init SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << stderr << "SDL failed to initialise:" << SDL_GetError();
        
    }

    //hookup exit
    atexit(SDL_Quit);

    //  Request OpenGL ES 3.0
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,0);

    //set a double buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    /* Creates a SDL window */
    window = SDL_CreateWindow(TITLE, /* Title of the SDL window */
                    SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
                    SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
                    WIDTH, /* Width of the window in pixels */
                    HEIGHT, /* Height of the window in pixels */
                    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN); /* Additional flag(s) */

    
    /* Checks if window has been created; if not, exits program */
    if (window == NULL) {
        cout<< stderr << "SDL window failed to initialise:" << SDL_GetError();

    }

    //create context
    context = SDL_GL_CreateContext(window);
    
    if (!context)
    {
        cout <<"context not created" ;
    }
    

}


void Display::run()

{
   
  
   
    
   
    //main loop
 glEnable(GL_DEPTH_TEST);
  while(!quit)
  {
      

     //processInput(&event,&quit); 
    input->processInput(&quit);

    //main loop
    glClearColor(1.0,0.5,0.5,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  
    //render here
    //renderer->renderScene();
    batch_renderer->renderBatch();
    //shader->render();
    //r->shader->render();
   

    //SDL_PollEvent(&event);
    SDL_GL_SwapWindow(window);
  }

  
 
  

}


void Display::cleanup()
{
    /* Pauses all SDL subsystems for a variable amount of milliseconds */
    //SDL_Delay(DELAY);
    delete batch_renderer;
    delete input;
    /* Frees memory */
    SDL_DestroyWindow(window);
  
    /* Shuts down all SDL subsystems */
    SDL_Quit(); 
}
/*
void Display::processInput(SDL_Event* event,bool* quit)
{
    if (SDL_PollEvent(event)!=0)
      {
          if (event->type == SDL_QUIT)
          {
              *quit = true;
          }
        
         //keyboard events
          if (event->type == SDL_KEYDOWN)
          {
              if (event->key.keysym.sym == SDLK_ESCAPE)
              *quit = true;
          }
      }
}
*/