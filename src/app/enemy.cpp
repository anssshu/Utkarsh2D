#include "enemy.hpp"








Enemy::Enemy(float tex_id):Sprite(tex_id)
{
    //create the box 2d body

    body = new Body();
    body->Set(Vec2(1.0,1.0),100); //set bounds and mass
    body->position.x = 0.0;
    body->position.y = -2.5;
    //body->rotation = rot;

    //create the contact for collision detection
    contact = new Contact();

    //add body to the box 2d world;
    //w->Add(body);
    
    uv_rect = {0.05,0.05,0.128,0.256};
    //uv_rect = {0.05+0.128,0.05,0.128,0.256};
    //updateUVRect(uv_rect);

    
}

void Enemy::update()
{
    //update pos and rot of the quad
    //pos.x=body->position.x;
    //pos.y=body->position.y;
    //rot=body->rotation;

    
    
    //rot += 1.0f;
}