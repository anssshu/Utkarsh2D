#include "enemy.hpp"








Enemy::Enemy(float tex_id):Sprite(tex_id)
{
    //create the box 2d body

    
    //body->rotation = rot;

    //create the contact for collision detection
  

    //add body to the box 2d world;
    //w->Add(body);
    
    uv_rect = {0.05,0.05,0.128,0.256};
    //uv_rect = {0.05+0.128,0.05,0.128,0.256};
    updateUVRect(uv_rect);

    
}

void Enemy::update()
{
    //update pos and rot of the quad
    //pos.x=body->position.x;
    //pos.y=body->position.y;
    //rot=body->rotation;

    
    
    //rot += 1.0f;
}