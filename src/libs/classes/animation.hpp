
#include "../data_structures/data_structures.hpp"
#include "sprite.hpp"
class Animation
{
    public:
    Sprite sprite;
    vector<Rect> rects;// array of rectangles for playing the animation
    Animation(float textureID);
    void update();
};