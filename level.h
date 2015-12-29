#pragma once
#include <iostream>
#include <vector>
#include "includer.h"

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