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

using namespace std;
class Display
{
    public:
    SDL_Window* window;
    SDL_Event event;

    //Renderer* renderer;

    void initDisplay(int WIDTH,int HEIGHT,const char* TITLE);

    void run();

    void cleanup();

};