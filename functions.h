#pragma once
#include <iostream>
#include "includer.h"



// A general texture loading function
SDL_Texture* loadTexture(std::string path, SDL_Renderer *ren, SDL_bool colorKey);