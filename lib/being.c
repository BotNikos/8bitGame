#include <SDL2/SDL.h>
#include "../include/being.h"

struct being* createBeing (SDL_Texture *texture, int x, int y) {
    struct being *being = (struct being *) malloc (sizeof (struct being));

    being -> img = texture;
    being -> pos.x = x;
    being -> pos.y = y;
    being -> pos.w = 32;
    being -> pos.h = 32;

    return being;
}
