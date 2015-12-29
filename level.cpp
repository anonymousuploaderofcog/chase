#include "level.h"

Level::Level(SDL_Renderer* gRenderer, Level* &lvl) {
    
    new Object(gRenderer, objects, "matrix.jpg", SDL_FALSE, 320, 320);
    new Object(gRenderer, objects, "space.bmp", SDL_TRUE, 0, 0);
    new Character(gRenderer, objects, "man.jpg", SDL_TRUE, 100, 200, 220, 140);
    
    
    
    lvl = this;
}


std::vector<Object*>* Level::GetObjects() {
    return &this->objects;
}
