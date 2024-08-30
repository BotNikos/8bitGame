#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>

struct loadedTexture {
    char fileName [32];
    SDL_Texture *texture;
};

void showErrorMessage (char *message);
SDL_Texture *checkTexture (struct loadedTexture *allTextures, int texturesCount, char *fileName);
SDL_Texture *createTextureFromImage (SDL_Renderer *renderer, char *fileName);

#endif 
