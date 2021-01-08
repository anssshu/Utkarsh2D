#include "player.hpp"

float H = 5;
float jump_time=0.5;
float g = 2*H/jump_time;
float v = g*jump_time;

Player::Player(float tex_id):Sprite(tex_id)
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
    updateUVRect(uv_rect);

    
}

void Player::update()
{
    //update pos and rot of the quad
    pos.x=body->position.x;
    pos.y=body->position.y;
    //rot=body->rotation;

    if (input->is_action_pressed("up") && on_ground)
    {
         body->velocity.y = -v;
    }
    

    if (input->is_action_pressed("left"))
    {
        //pos.x -= 0.1;
        body->velocity.x = -10;
    }

    else if (input->is_action_pressed("right"))
    {
        //pos.x += 0.1;
        body->velocity.x = 10;
    }
    else if(!input->is_action_pressed("right") && !input->is_action_pressed("left"))
    {
        if(on_ground)
            body->velocity.x = 0;
    }
    

    if (input->is_action_pressed("down"))
    {
        //pos.y += 0.1;
    }
    
    //rot += 1.0f;
}