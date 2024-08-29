#ifndef BEING_H
#define BEING_H

#include <SDL2/SDL.h>

struct being {
    SDL_Rect pos;
    SDL_Texture *img;
};

struct being* createBeing (SDL_Texture *texture, int x, int y);

#endif
