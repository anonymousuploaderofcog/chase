#include "functions.h"

// The universal colorkey (this implementation can be changed)
#define COLORKEY_RED 255
#define COLORKEY_GREEN 255
#define COLORKEY_BLUE 255

SDL_Texture* loadTexture(std::string path, SDL_Renderer *ren, SDL_bool colorKey)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        std::cout << "Unable to load image " << path.c_str() << "! " << "SDL Error: " << SDL_GetError() << "\n";
    }
    else
    {
        SDL_SetColorKey(loadedSurface, colorKey, SDL_MapRGB(loadedSurface->format, COLORKEY_RED, COLORKEY_GREEN, COLORKEY_BLUE));
        newTexture = SDL_CreateTextureFromSurface(ren, loadedSurface);
        if (newTexture == NULL)
        {
            std::cout << "Unable to create texture from " << path.c_str() << "! " << "SDL Error: " << SDL_GetError() << "\n";
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}