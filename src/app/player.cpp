#include "player.hpp"

float H = 5;
float jump_time=0.5;
float g = 2*H/jump_time;
float v = g*jump_time;

Player::Player(float tex_id):Sprite(tex_id)
{
    pos.x = -2.0;
    uv_rect = {0.05,0.05,0.128,0.256};
    //uv_rect = {0.05+0.128,0.05,0.128,0.256};
    updateUVRect(uv_rect);

    
}

void Player::update()
{
    //cpllosion code
    
    if (hit_by_enemy)
    {
        cout << "joe hit me" <<endl;
    }
    
    //motion code
    velocity.y +=g*1/60.0f ;
    
    //update position within limit
    if (pos.x < 7.0 || pos.x >-7.0)
    {
        pos.x += velocity.x*1/60.0f;
        pos.y += velocity.y*1/60.0f;
    }
   
    
    
    if (pos.y>3.0)
        {
            on_ground = true;
            pos.y = 3.0;
            velocity.y = 0;
        }
    else if (pos.y<3.0)
    {
        on_ground = false;
    }
    
    //update pos and rot of the quad
    //pos.x=body->position.x;
    //pos.y=body->position.y;
    //rot=body->rotation;
    
    left  =  input->is_action_pressed("left");
    right = input->is_action_pressed("right");
    up = input->is_action_pressed("up");


    if (input->is_action_pressed("up") && on_ground)
    {
         //body->velocity.y = -v;
         velocity.y = -v;
    }
    
    if(!left && !right )
    
    {
        if(on_ground && !up )
            //body->velocity.x = 0;
            velocity.x = 0;
            //velocity.y = 0;
        //cout<< "keys up" <<endl;
    }

    else
    {
        //cout<< "keys down" <<endl;

        if (left )
        {
            //pos.x -= 0.1;
            velocity.x = -10;
            cout<< pos.x<<endl;
        }

        else if (right )
        {
            //pos.x += 0.1;
            velocity.x = 10;
        }
    }
    
    

    if (input->is_action_pressed("down"))
    {
        //pos.y += 0.1;
    }
    
    //rot += 1.0f;
}