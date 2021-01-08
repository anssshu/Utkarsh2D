#include "input.hpp"
Input::Input(SDL_Event* event)
{
    //connect the event pointer from the display
    e = event;
    
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
     
     bool down = false;
     
     if (e->type == SDL_KEYDOWN && e->key.keysym.sym == key_map.find(key)->second)
     {

         down = true;
     }
     else if (e->type == SDL_KEYUP && e->key.keysym.sym == key_map.find(key)->second)
     {
         down =  false;
     }

     return down;
     
     
}

int Input::check_mouseWheel()
{
    if (e->type == SDL_MOUSEWHEEL && e->wheel.y > 0)
    {
        return 1;
    }
    else if(e->type == SDL_MOUSEWHEEL && e->wheel.y < 0)
    {
        return -1;
    }
    else
    {
        return 0;
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