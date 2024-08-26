#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main (void) {

    SDL_Init (SDL_INIT_EVERYTHING);
    IMG_Init (IMG_INIT_PNG);

    SDL_Window *window = SDL_CreateWindow ("test?", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Surface *winSurf = SDL_GetWindowSurface (window);

    SDL_Surface *image = IMG_Load ("./sprites/allSpritesUpscale-Sheet1.png");

    bool running = true;

    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;

    while (running) {

        SDL_Event event;
        SDL_PollEvent (&event);

        if (event.type == SDL_QUIT) 
            running = false;

        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_RIGHT)
                dest.x += 10;
            if (event.key.keysym.sym == SDLK_LEFT)
                dest.x -= 10;
            if (event.key.keysym.sym == SDLK_DOWN)
                dest.y += 10;
            if (event.key.keysym.sym == SDLK_UP)
                dest.y -= 10;
        }


        SDL_FillRect (winSurf, NULL, SDL_MapRGB (winSurf -> format, 0, 200, 50));
        SDL_BlitSurface (image, NULL, winSurf, &dest);

        SDL_UpdateWindowSurface (window);
    }

    SDL_DestroyWindow (window);
    window = NULL;
    winSurf = NULL;

    SDL_Quit ();

    return 0;
}
