#include <iostream>
#include <vector>
#include "includer.h"
#include "functions.h"
#include "object.h"
#include "game.h"

// Initialize needed things
//Meraba CEO
//lololol
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


//hmmmmmmmm chocolate

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

const bool vSyncSwitch = true;

int xMouse = 0, yMouse = 0;
bool mouseOne = false, mouseTwo = false;
const Uint8* keyState = nullptr;

SDL_Event event;
bool quitFlag = false;

int main(int argc, const char * argv[]) {

    // General Initialization
    SDL_Init(SDL_INIT_VIDEO);
    /*SDL_DisplayMode mode;
     SDL_GetCurrentDisplayMode(0, &mode);
     const int SCREEN_WIDTH = mode.w*2;
     const int SCREEN_HEIGHT = mode.h*2;*/
    //std::cout << mode.w;
    IMG_Init(IMG_INIT_PNG);
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | (SDL_RENDERER_PRESENTVSYNC * vSyncSwitch));
    Game myGame(gRenderer);

    // Program / Game Loop
    while (!quitFlag) {
        quitFlag = myGame.GetFlag(0);

        // Input
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quitFlag = true;
            }
            else if(event.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&xMouse, &yMouse);
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    mouseOne = true;
                }
                else if (event.button.button == SDL_BUTTON_RIGHT) {
                    mouseTwo = true;
                }
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    mouseOne = false;
                }
                else if (event.button.button == SDL_BUTTON_RIGHT) {
                    mouseTwo = false;
                }
            }
        }
        keyState = SDL_GetKeyboardState(NULL);
        myGame.GetInput(keyState, xMouse, yMouse, mouseOne, mouseTwo);

        // Run game
        myGame.Update();
        myGame.Render();
    }

    // Close / Exit
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
    return 0;
}
