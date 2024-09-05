#ifndef BEING_H
#define BEING_H

#include <SDL2/SDL.h>
#include "../include/map.h"

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

bool checkMove (struct being *being, int nextX, int nextY, struct tile **initedTiles, int levelSize);
void move (struct being *self, SDL_Event event, struct tile **initedTiles, int levelSize);
struct being* createBeing (SDL_Texture *texture, int x, int y);

#endif
