//player inherits from the sprite class
#pragma once
#include "libs/classes/sprite.hpp"



class Enemy:public Sprite
{
    public:
    bool hit_by_enemy = false;
    bool hit_by_bullet = false;
    bool on_ground = false;
    Enemy(float texture_id);
    void update();
};