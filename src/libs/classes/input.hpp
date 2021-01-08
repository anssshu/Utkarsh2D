#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include  <map>
using namespace std;

class Input
{
    public:
    SDL_Event* e;
    map<string,unsigned int> key_map;

    Input(SDL_Event* event);
    void processInput(bool* quit);
    bool is_action_pressed(string key);
    int check_mouseWheel();
    //bool is_mouse_wheel_down();
};