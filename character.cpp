#include "character.h"

// Constructor which calls the not pushing-back to vector one of base constructors and which pushes itself back to it's own place
Character::Character(SDL_Renderer *ren, std::vector<Object*> &vec, std::string texLoc, SDL_bool colorKey, int w, int h, int px, int py) : Object(ren, vec, texLoc, colorKey, w, h, px, py) {
    
}

// Extra Update for characters
void Character::Update() {
    
    if (keyStates[SDL_SCANCODE_D]) {
        this->veloX = 7;
    }
    if (keyStates[SDL_SCANCODE_A]) {
        this->veloX = -7;
    }
    if (keyStates[SDL_SCANCODE_SPACE] && avail) {
        this->veloY = -10;
        avail = false;
    }
    veloX = veloX;
    veloY = veloY;
    
    
    this->veloX = this->veloX * 4 / 5;
    this->posX += this->veloX;
    
    this->veloY += 1;
    this->posY += this->veloY;
    
    if (this->posY + height > 300) {
        this->posY = 300 - height;
        this->veloY = 0;
        avail = true;
    }
    
    // Update render attributes
    this->mRect.x = this->posX;
    this->mRect.y = this->posY;
    this->mRect.w = this->width;
    this->mRect.h = this->height;
}

// Extra Render for characters
void Character::Render(SDL_Renderer *ren)
 {
    
    SDL_RenderCopy(ren, this->mTexture, NULL, &this->mRect);
    
}
