#include "libs/classes/batch_renderer.hpp"
#include "libs/classes/sprite.hpp"
//#include "libs/classes/input.hpp"

#include "box2d-lite/World.h"
#include "box2d-lite/Body.h"
#include "box2d-lite/Joint.h"

#include "player.hpp"
#include "libs/functions/checkCollision.hpp"

class MainBatch:public Batch
{
    public:
    int* foo;
    Sprite* joe;
    Player* player;
    
    //Contact* c;
    MainBatch(Input* inp);
    virtual ~MainBatch();
    void update();
};