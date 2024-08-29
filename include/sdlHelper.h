#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>

void showErrorMessage (char *message);
SDL_Texture *createTextureFromImage (SDL_Renderer *renderer, char *fileName);

#endif 
