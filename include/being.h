#ifndef BEING_H
#define BEING_H

#include <SDL2/SDL.h>

struct moving {
    bool right;
    bool up;
    bool left;
    bool down;
    bool run;
};

struct being {
    SDL_Rect pos;
    SDL_Texture *img;
    struct moving moving;
    void (*move) (struct being *, SDL_Event event);
};

void move (struct being *self, SDL_Event event);
struct being* createBeing (SDL_Texture *texture, int x, int y);

#endif
