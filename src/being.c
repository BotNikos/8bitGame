#include <stdbool.h>
#include <SDL2/SDL.h>
#include "being.h"
#include "game_globals.h"
#include "map.h"

bool checkMove (struct being *being, int nextX, int nextY, struct tile **initedTiles, int levelSize) {
    bool canMove = true;

    if (nextX < 0 || nextX > WINDOW_WIDTH - being -> pos.w)
        canMove = false;

    if (nextY < 0 || nextY > WINDOW_HEIGHT - being -> pos.h)
        canMove = false;

    for (int i = 0; i < levelSize; i++) {
        if (initedTiles [i] -> closedZone.h == 0)
            continue;

        int closedZoneX = initedTiles [i] -> closedZone.x + initedTiles [i] -> pos.x;
        int closedZoneEndX = closedZoneX + initedTiles [i] -> closedZone.w;

        int closedZoneY = initedTiles [i] -> closedZone.y + initedTiles [i] -> pos.y;
        int closedZoneEndY = closedZoneY + initedTiles [i] -> closedZone.h;

        if (nextX < closedZoneEndX && nextX + being -> pos.w > closedZoneX && nextY < closedZoneEndY && nextY + being -> pos.h > closedZoneY)
            canMove = false;
    }
    
    return canMove;
}

void move (struct being *self, SDL_Event event, struct tile **initedTiles, int levelSize) {
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

    if (self -> moving.right &&
        checkMove (self, self -> pos.x + 1, self -> pos.y, initedTiles, levelSize))
        self -> pos.x += 1;

    if (self -> moving.up &&
        checkMove (self, self -> pos.x, self -> pos.y - 1, initedTiles, levelSize))
        self -> pos.y -= 1;

    if (self -> moving.left &&
        checkMove (self, self -> pos.x - 1, self -> pos.y, initedTiles, levelSize))
        self -> pos.x -= 1;

    if (self -> moving.down &&
        checkMove (self, self -> pos.x, self -> pos.y + 1, initedTiles, levelSize))
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
