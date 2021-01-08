#pragma once
#include "quad.hpp"
#include "input.hpp"
class Sprite:public Quad
{
    public:
    Input* input;
    Sprite(float ID = 0.0f,Rect rect = {0.0f,0.0f,1.0f,1.0f});
    Rect uv_rect = {0.0f,0.0f,1.0f,1.0f};


    void setPos(float x, float y);
    void setRot(float rot);
    void setScale(float x, float y);

    void update();


};