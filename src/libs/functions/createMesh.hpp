#pragma once

#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <GLES3/gl3.h>

#include "../data_structures/data_structures.hpp"

Mesh createMesh(MeshData vertex_data);