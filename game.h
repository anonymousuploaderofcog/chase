#pragma once
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "functions.h"
#include "object.h"
#include "character.h"
#include "level.h"

class Game {
    
protected:
    
    // General
    SDL_Renderer* gRenderer = NULL;
    enum Flag {
        GAME_QUIT,
        GAME_ACTIVE,
        GAME_PAUSE,
        GAME_TOTAL_FLAGS
    };
    bool gameFlags[GAME_TOTAL_FLAGS];
    
    // Les indicateurs
    std::vector<Object*> tout;
    
    Level* currentLvl = nullptr;
    Level* nextLvl = nullptr;
    
    // Input
    const Uint8* keyStates;
    int mouseX, mouseY, cursorX, cursorY;
    bool mOne = false, mTwo = false;
    
    // For game logic
    //unsigned long long lastFrame = 0, deltaTime = 0;
    
public:
    
    // Clear enough (at least hope so)
    Game(SDL_Renderer *providedRenderer);
    
    void Update();
    void Render();
    
    void GetInput(const Uint8* keys, int mx, int my, bool m1, bool m2);
    void ProcessInput();
    
    bool GetFlag(int i){return this->gameFlags[i];}
    
    void GenerateLevel();

};