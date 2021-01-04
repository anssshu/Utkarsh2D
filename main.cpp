#include <iostream>
#include <cstdio>
#include <cstdlib>
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else


#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <GLES3/gl3.h>
#endif

/* Sets constants */
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000
#define SDL_main main

using namespace std;

void processInput(SDL_Event* e,bool* quit);
int SDL_main (int argc, char* argv[])
{
  /* Initialises data */
  SDL_Window* window ;

  SDL_GLContext context;
  
  /*
  * Initialises the SDL video subsystem (as well as the events subsystem).
  * Returns 0 on success or a negative error code on failure using SDL_GetError().
  */

 if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cout << stderr << "SDL failed to initialise:" << SDL_GetError();
    return 1;
  }

atexit(SDL_Quit);

//  Request OpenGL ES 3.0
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_ES);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,0);

SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

  /* Creates a SDL window */
 window = SDL_CreateWindow("SDL Example", /* Title of the SDL window */
			    SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
			    SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
			    WIDTH, /* Width of the window in pixels */
			    HEIGHT, /* Height of the window in pixels */
			    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN); /* Additional flag(s) */

  /* Checks if window has been created; if not, exits program */
  if (window == NULL) {
    cout<< stderr << "SDL window failed to initialise:" << SDL_GetError();
    return 1;
  }

  //create context
  context = SDL_GL_CreateContext(window);
  if (!context)
  {
      cout <<"context not created" ;
  }
  bool quit = false;
  SDL_Event event;

  //main loop
  while(!quit)
  {
      

     processInput(&event,&quit); 

    //main loop
    glClearColor(1.0,0.5,0.5,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    


    //SDL_PollEvent(&event);
    SDL_GL_SwapWindow(window);
  }

  /* Pauses all SDL subsystems for a variable amount of milliseconds */
  //SDL_Delay(DELAY);

  /* Frees memory */
  SDL_DestroyWindow(window);
  
  /* Shuts down all SDL subsystems */
  SDL_Quit(); 
 
  return EXIT_SUCCESS;
}


//input processing through the event pointer
void processInput(SDL_Event* event,bool* quit)
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