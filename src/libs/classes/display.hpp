#pragma once
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

#define SDL_main main

#include "input.hpp"
#include "renderer.hpp"
#include "batch_renderer.hpp"


using namespace std;
class Display
{
    public:
    SDL_Window* window;
    SDL_Event event;
    SDL_GLContext context;
    bool quit = false;
    Input input;
    Renderer2D* renderer;
    BatchRenderer* batch_renderer;

    Display(int WIDTH,int HEIGHT,const char* TITLE);
    void run();
    void cleanup();
    
  

    private:
    void initDisplay(int WIDTH,int HEIGHT,const char* TITLE);
    void processInput(SDL_Event* event,bool* quit);

};