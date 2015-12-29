#include "game.h"

Game::Game(SDL_Renderer *providedRenderer) {
    
    // Flag Initialization
    for (int i = 0; i < GAME_TOTAL_FLAGS; i++) {
        gameFlags[i] = false;
    }
    gameFlags[GAME_ACTIVE] = true;
    
    // The renderer
    gRenderer = providedRenderer;
    
    new Level(gRenderer, this->currentLvl);

    // Other initializations for game logic
    }

void Game::Update() {
    
    // Input first
    ProcessInput();
    
    // Input for everything
    for (int i = 0; i < (*currentLvl->GetObjects()).size(); i++) {
        (*currentLvl->GetObjects())[i]->GetInput(keyStates, cursorX, cursorY, mOne, mTwo);
    }
    
    // Update everything
    for (int i = 0; i < (*currentLvl->GetObjects()).size(); i++) {
        (*currentLvl->GetObjects())[i]->Update();
    }
}

void Game::Render() {
    
    //change to render to texture
    SDL_SetRenderTarget(gRenderer, NULL);
    
    // Render everything as desired
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
    SDL_RenderClear(gRenderer);
    for (int i = 0; i < (*currentLvl->GetObjects()).size(); i++) {
        //tout[i]->Render(gRenderer);
        (*currentLvl->GetObjects())[i]->Render(gRenderer);
    }
    SDL_RenderPresent(gRenderer);
    
    //std::cout << deltaTime << std::endl;
}

// A function for getting input data from 'Program'
void Game::GetInput(const Uint8* keys, int mx, int my, bool m1, bool m2) {
    this->keyStates = keys;
    this->mouseX = mx;
    this->mouseY = my;
    this->mOne = m1;
    this->mTwo = m2;
}

// Input processing
void Game::ProcessInput() {
    this->cursorX = this->mouseX;
    this->cursorY = this->mouseY;
    
    if(keyStates[SDL_SCANCODE_ESCAPE])
    {
        this->gameFlags[GAME_QUIT] = true;
    }
}

void Game::GenerateLevel() {
    delete this->currentLvl;
    this->currentLvl = nextLvl;
    new Level(gRenderer, nextLvl);
}
