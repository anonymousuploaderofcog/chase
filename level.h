#pragma once
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "functions.h"
#include "object.h"
#include "character.h"

class Level {
    
private:
    std::vector<Object*> objects;
public:
    Level(SDL_Renderer* gRenderer, Level* &lvl);
    
    std::vector<Object*>* GetObjects();
};