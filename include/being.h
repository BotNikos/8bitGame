#ifndef BEING_H
#define BEING_H

#include <SDL2/SDL.h>
#include "map.h"

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
    void (*move) (struct being *, SDL_Event, struct tile **, int);
};

bool checkMove (struct being *, int, int, struct tile **, int);
void move (struct being *, SDL_Event, struct tile **, int);
struct being* createBeing (SDL_Texture *, int, int);

#endif
