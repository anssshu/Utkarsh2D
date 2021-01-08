//player inherits from the sprite class
#pragma once
#include "libs/classes/sprite.hpp"

#include "box2d-lite/Body.h"
#include "box2d-lite/World.h"

class Enemy:public Sprite
{
    public:
    bool hit_by_enemy = false;
    bool hit_by_bullet = false;
    bool on_ground = false;
    Contact* contact;
    Body* body;
    Enemy(float texture_id);
    void update();
};