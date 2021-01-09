//player inherits from the sprite class
#pragma once
#include "libs/classes/sprite.hpp"

class Player:public Sprite
{
    public:
    bool hit_by_enemy = false;
    bool hit_by_bullet = false;
    bool on_ground = false;
    
    Player(float texture_id);
    void update();
    bool left;
    bool right;
    bool up;
    vec2 velocity = vec2(0.0,0.0);
};
