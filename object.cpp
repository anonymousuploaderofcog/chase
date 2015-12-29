#include "object.h"

// Constructor with vector push_back
Object::Object(SDL_Renderer *ren, std::vector<Object*> &vec, std::string texLoc, SDL_bool colorKey, int wh, int hh, int px, int py) {
    this->mTexture = loadTexture(texLoc, ren, colorKey);
    this->posX = px;
    this->posY = py;
    this->width = wh;
    this->height = hh;
    if (wh == 0) {
        SDL_QueryTexture(this->mTexture, NULL, NULL, &this->mRect.w, &this->mRect.h);
        this->width = this->mRect.w;
        this->height = this->mRect.h;
    }
    
    this->mColl = this->mRect;
    
    
    vec.push_back(this);
}

// Input
void Object::GetInput(const Uint8* keys, int cx, int cy, bool m1, bool m2) {
    this->keyStates = keys;
    this->cursorX = cx;
    this->cursorY = cy;
    this->mOne = m1;
    this->mTwo = m2;
}

// Update
void Object::Update() {
    
    // Apply velocity
    
    this->veloX = this->veloX * 4 / 5;
    this->posX += this->veloX;
    
    this->veloY += 1;
    this->posY += this->veloY;
    
    if (this->posY + height > 300) {
        this->posY = 300 - height;
        this->veloY = 0;
    }
    
    // Update render attributes
    this->mRect.x = this->posX;
    this->mRect.y = this->posY;
    this->mRect.w = this->width;
    this->mRect.h = this->height;
    this->mColl = this->mRect;
}

// Render normally
void Object::Render(SDL_Renderer *ren) {
    SDL_RenderCopy(ren, this->mTexture, NULL, &this->mRect);
}

// Render clippingly
void Object::RenderClip(SDL_Renderer *ren, double x, double y, double w, double h) {
    
    SDL_Rect clipRect;
    SDL_QueryTexture(this->mTexture, NULL, NULL, &clipRect.w, &clipRect.h);
    clipRect.x = clipRect.w * x;
    clipRect.y = clipRect.h * y;
    clipRect.w = clipRect.w * w;
    clipRect.h = clipRect.h * h;
    
    SDL_Rect tarRect = this->mRect;
    tarRect.w = clipRect.w;
    tarRect.h = clipRect.h;
    
    
    SDL_RenderCopy(ren, this->mTexture, &clipRect, &tarRect);
}