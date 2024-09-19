#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>

struct loadedTexture {
    char fileName [32];
    SDL_Texture *texture;
};

void showErrorMessage (char *);
SDL_Texture *checkTexture (struct loadedTexture *, int, char *);
SDL_Texture *createTextureFromImage (SDL_Renderer *, char *);

#endif 
