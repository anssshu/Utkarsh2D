
#pragma once
#include "libs/classes/batch_renderer.hpp"
#include "libs/classes/sprite.hpp"
//#include "libs/classes/input.hpp"

#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <SDL2/SDL_mixer.h>
#include <GLES3/gl3.h>

#include "player.hpp"
#include "libs/functions/checkCollision.hpp"


#include "enemy.hpp"

class MainBatch:public Batch
{
    public:
    int* foo;
    Enemy* miku;
    Sprite* joe;
    Player* hero;
    
    //Contact* c;
    MainBatch(Input* inp);
    virtual ~MainBatch();
    void update();
};