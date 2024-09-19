#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "testlvl.h"

#include "being.h"
#include "sdlHelper.h"
#include "map.h"
#include "game_globals.h"

int main (void) {

    if (SDL_Init (SDL_INIT_EVERYTHING) < 0) 
        showErrorMessage ("init everything");
        
    if (IMG_Init (IMG_INIT_PNG) < 0)
        showErrorMessage ("image init");

    SDL_Window *window = SDL_CreateWindow ("8bitGame", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED);

    if (!window)
        showErrorMessage ("window creation");

    if (!renderer)
        showErrorMessage ("renderer creation");

    struct tile **initedTiles = initMap (renderer, TEST_LEVEL_ROWS, TEST_LEVEL_COLS, testlevel);
    struct being *hero = createBeing (createTextureFromImage (renderer, "./sprites/mainHero.png"), 32, 32);

    bool running = true;

    while (running) {
        SDL_Event event;
        SDL_PollEvent (&event);

        if (event.type == SDL_QUIT)
            running = false;

        SDL_SetRenderDrawColor(renderer, 0, 200, 50, 255);
        SDL_RenderClear (renderer);

        hero -> move (hero, event, initedTiles, TEST_LEVEL_ROWS * TEST_LEVEL_COLS);
        drawMap (renderer, initedTiles, TEST_LEVEL_ROWS * TEST_LEVEL_COLS);
        SDL_RenderCopy (renderer, hero -> img, NULL, &hero -> pos);

        SDL_RenderPresent (renderer);
    }

    SDL_DestroyTexture(hero -> img);
    SDL_DestroyWindow (window);
    SDL_DestroyRenderer (renderer);

    SDL_Quit ();

    return 0;
}
