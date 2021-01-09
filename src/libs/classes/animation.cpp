#include "animation.hpp"

//represents a single animation 
Animation::Animation(float textureID)
{
   //get the rects 

   //each rect represents an image 

   //the animation loops through the rect with a delay

   float frame_rate = 60.0;//60 frames per second
   float frame = rects.size();

   //suppose the animation duration is 1 sec

   //display time of each frame 1/frames delay

   //update each rect after 1/frames second
   

   //create the sprite
   sprite = Sprite(textureID);
   //set the first frame of the animation
   sprite.uv_rect = rects[0];

   


}

void Animation::update()
{
    //wait for anim_duration/frames sec and 
}