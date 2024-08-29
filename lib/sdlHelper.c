#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/sdlHelper.h"

void showErrorMessage (char *message) {
    printf ("Error: %s, %s", message, SDL_GetError());
    exit (1);
}

SDL_Texture *createTextureFromImage (SDL_Renderer *renderer, char *fileName) {

    SDL_Surface *image = IMG_Load (fileName);

    if (!image)
        showErrorMessage (fileName);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

    if (!texture)
        showErrorMessage ("texture create");

    SDL_FreeSurface (image);
    return texture;
}
