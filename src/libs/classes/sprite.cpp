#include "sprite.hpp"

Sprite::Sprite(float ID ,Rect rect ):Quad(0.0f,0.0f,ID)
{
    updateUVRect(rect);
    uv_rect = rect;
    updateTransform();
    
}

void Sprite::setPos(float x, float y)
{
    pos.x = x;
    pos.y = y;
    updateTransform();
}
void Sprite::setRot(float rot)
{
    this->rot = rot;
    updateTransform();
}
void Sprite::setScale(float x, float y)
{
    scale = vec2(x,y);
    updateTransform();
}
    //Rect uv_rect = {0.0f,0.0f,1.0f,1.0f};
void Sprite::update()
{

}