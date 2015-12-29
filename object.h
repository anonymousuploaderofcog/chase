#pragma once
#include <iostream>
#include <vector>
#include "includer.h"

#include "functions.h"


class Object {
    
protected:
    
    // General attributes
    int width = 0, height = 0;
    double mass = 1;
    double posX = 0, posY = 0;
    double veloX = 0, veloY = 0;
    
    // Input
    const Uint8* keyStates;
    int cursorX, cursorY;
    bool mOne = false, mTwo = false;
    
    // Visual attributes
    SDL_Texture* mTexture = NULL;
    SDL_Rect mRect, mClip, mColl;
    bool ghost = false;
    
public:
    
    // If this flag is set to TRUE, this object will disappear as soon as possible
    bool removeFlag = false;

    // Constructors for either vector push_back is required or not
    Object(SDL_Renderer *ren, std::vector<Object*> &vec, std::string texLoc, SDL_bool colorKey, int w = 0, int h = 0, int px = 0, int py = 0);
    
    // Input
    void GetInput(const Uint8* keys, int cx, int cy, bool m1, bool m2);
    
    // General update for all objects
    virtual void Update();
    
    // General render for all objects
    virtual void Render(SDL_Renderer *ren);
    virtual void RenderClip(SDL_Renderer *ren, double x, double y, double w, double h);

    // Gets
    int getWidth() {return width;}
    int getHeight() {return height;}
};