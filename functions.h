#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>


// A general texture loading function
SDL_Texture* loadTexture(std::string path, SDL_Renderer *ren, SDL_bool colorKey);