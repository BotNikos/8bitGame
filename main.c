#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "./levels/testlvl.h"

#include "./include/being.h"
#include "./include/sdlHelper.h"
#include "./include/map.h"

int main (void) {

    if (SDL_Init (SDL_INIT_EVERYTHING) < 0) 
        showErrorMessage ("init everything");
        
    if (IMG_Init (IMG_INIT_PNG) < 0)
        showErrorMessage ("image init");

    SDL_Window *window = SDL_CreateWindow ("8bitGame", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED);

    if (!window)
        showErrorMessage ("window creation");

    if (!renderer)
        showErrorMessage ("renderer creation");

    struct being *hero = createBeing (createTextureFromImage (renderer, "./sprites/mainHero.png"), 0, 0);

    bool running = true;

    while (running) {

        SDL_Event event;
        SDL_PollEvent (&event);

        if (event.type == SDL_QUIT) 
            running = false;

        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_RIGHT)
                hero -> pos.x += 10;
            if (event.key.keysym.sym == SDLK_LEFT)
                hero -> pos.x -= 10;
            if (event.key.keysym.sym == SDLK_DOWN)
                hero -> pos.y += 10;
            if (event.key.keysym.sym == SDLK_UP)
                hero -> pos.y -= 10;
        }

        SDL_SetRenderDrawColor(renderer, 0, 200, 50, 255);
        SDL_RenderClear (renderer);

        drawMap (renderer);
        SDL_RenderCopy (renderer, hero -> img, NULL, &hero -> pos);

        SDL_RenderPresent (renderer);
    }

    SDL_DestroyTexture(hero -> img);
    SDL_DestroyWindow (window);
    SDL_DestroyRenderer (renderer);

    SDL_Quit ();

    return 0;
}
