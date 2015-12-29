#pragma once
#include "object.h"

class Character : public Object {
    
protected:
    bool avail = true;
public:
    
    // Constructor which calls the not pushing-back to vector one of base constructors
    Character(SDL_Renderer *ren, std::vector<Object*> &vec, std::string texLoc, SDL_bool colorKey, int w = 0, int h = 0, int px = 0, int py = 0);
    
    virtual void Update();
    virtual void Render(SDL_Renderer *ren);
    
};