#include "input.hpp"
Input::Input()
{
    
    //INPUT MAP
    
    key_map =   {
                    {"esc",SDLK_ESCAPE},

                    {"up",SDLK_UP},
                    {"left",SDLK_LEFT},
                    {"right",SDLK_RIGHT},
                    {"down",SDLK_DOWN}

                };
}
//connect the input map to the event pointer 
bool Input::is_action_pressed(string key)
{
     if (e->type == SDL_KEYDOWN && e->key.keysym.sym == key_map.find(key)->second)
     {

         return true;
     }
     else
     {
         return false;
     }
     
     
}

//called every frame inside the 
void Input::processInput(bool* quit)
{
    if (SDL_PollEvent(e)!=0)
      {
          //point event to the Input
          //this->e = event;
          if (e->type == SDL_QUIT)
          {
              *quit = true;
          }
        
         //keyboard events
         if  (is_action_pressed("esc"))
                *quit = true;

         if (is_action_pressed("up"))
         {
            // cout << "up button pressen \n" ;
         }
      }
}