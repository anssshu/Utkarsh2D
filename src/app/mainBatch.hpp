#include "libs/classes/batch_renderer.hpp"
#include "libs/classes/sprite.hpp"
//#include "libs/classes/input.hpp"

#include "box2d-lite/World.h"
#include "box2d-lite/Body.h"
#include "box2d-lite/Joint.h"

#include "player.hpp"
#include "enemy.hpp"

class MainBatch:public Batch
{
    public:
    Enemy* enemy;
    Player* player;
    World* b2_world;
    Body *box,*base;
    //Contact* c;
    MainBatch(Input* inp);
    ~MainBatch();
    void update();
};