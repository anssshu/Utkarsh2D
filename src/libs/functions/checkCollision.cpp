#include "checkCollision.hpp"

bool checkCollision(Quad* q1,Quad* q2)
{
    bool col = false;
    const float WIDTH = 0.5*(q1->width+q2->width); //half 
    const float HEIGHT = 0.5*(q1->height+q2->height);


    if (    (std::abs(q2->pos.x-q1->pos.x) < WIDTH)     &&      (std::abs(q2->pos.y-q1->pos.y) < HEIGHT)     )
    {
        col = true;
        //cout<<WIDTH << "-w:h-" << HEIGHT<<endl;
    }

    return col;
}