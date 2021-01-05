#pragma once

#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <GLES3/gl3.h>

#include "file.hpp"
#include "../data_structures/data_structures.hpp"

unsigned int loadShader(string vertex_shader_path,string fragment_shader_path);