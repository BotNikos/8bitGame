#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "hero.h"

int main () {
	SDL_Window	*window		= NULL;
	SDL_Renderer	*renderer	= NULL;
	SDL_Event	event;

	char 		running 	= 1;

	struct _hero_ *hero;

	if (SDL_Init (SDL_INIT_VIDEO) == false || IMG_Init (IMG_INIT_PNG) == false) {
		printf ("Error: %s", SDL_GetError ());
	}

	window = SDL_CreateWindow ("8bitgame", 640, 480, 0);
	renderer = SDL_CreateRenderer (window, NULL);

	if (!renderer || !window) {
		printf ("Error: %s", SDL_GetError ());
	}

	hero = init_h (renderer, "sprites/mainHero.png", 0, 0, 100);

	while (running) {
		SDL_PollEvent (&event);

		if (event.type == SDL_EVENT_QUIT) {
			running = 0;
		}

		SDL_SetRenderDrawColor (renderer, 0, 200, 50, 255);
		SDL_RenderClear (renderer);

		SDL_RenderTexture (renderer, hero->being->texture, NULL, &hero->being->pos);

		SDL_RenderPresent (renderer);
		SDL_Delay (5);
	}

	SDL_DestroyRenderer (renderer);
	SDL_DestroyWindow (window);
	IMG_Quit ();
	SDL_Quit ();

	return 0;
}
