#include <stdbool.h>
#include <SDL2/SDL.h>
#include "../include/being.h"

void move (struct being *self, SDL_Event event) {
    int speed;

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT: self -> moving.right = true; break;
            case SDLK_UP: self -> moving.up = true; break;
            case SDLK_LEFT: self -> moving.left = true; break;
            case SDLK_DOWN: self -> moving.down = true; break;
            case SDLK_LSHIFT: self -> moving.run = true; break;
        }

    } else if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT: self -> moving.right = false; break;
            case SDLK_UP: self -> moving.up = false; break;
            case SDLK_LEFT: self -> moving.left = false; break;
            case SDLK_DOWN: self -> moving.down = false; break;
            case SDLK_LSHIFT: self -> moving.run = false; break;
        }
    }

    if (self -> moving.right)
        self -> pos.x += 1;

    if (self -> moving.up)
        self -> pos.y -= 1;

    if (self -> moving.left)
        self -> pos.x -= 1;

    if (self -> moving.down)
        self -> pos.y += 1;

    speed = self -> moving.run ? 4 : 7;
        
    SDL_Delay (speed);
}

struct being* createBeing (SDL_Texture *texture, int x, int y) {
    struct being *being = (struct being *) malloc (sizeof (struct being));

    being -> img = texture;

    being -> pos.x = x;
    being -> pos.y = y;
    being -> pos.w = 32;
    being -> pos.h = 32;

    being -> moving.right = false;
    being -> moving.up = false;
    being -> moving.left = false;
    being -> moving.down = false;
    being -> moving.run = false;

    being -> move = &move;

    return being;
}
