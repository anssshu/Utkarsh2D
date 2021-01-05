#pragma once

#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <GLES3/gl3.h>

#include <stb_image.h>

#include "file.hpp"


unsigned int loadTexture(const char* filePath);