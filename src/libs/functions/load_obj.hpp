/*
This file contains all the helper functions for the current application
*/
#pragma once

#include <fstream>
#include <sstream>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_opengles2.h>
#include <GLES3/gl3.h>

#include <stb_image.h>

#include "../classes/obj_model_loader.hpp"



//load an obj file with ASSIMP library and extract the ModelData data_structure
ModelData loadModel(string const &path);


