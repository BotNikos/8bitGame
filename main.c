#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "testlvl.h"

#include "being.h"
#include "sdlHelper.h"
#include "map.h"
#include "game_globals.h"

int main (void) {
	SDL_Window 	*window;
	SDL_Renderer 	*renderer;
	SDL_Event 	event;

	struct tile	**initedTiles;
	struct being	*hero;

	unsigned char	running = 1;

	if (SDL_Init (SDL_INIT_EVERYTHING) < 0 || IMG_Init (IMG_INIT_PNG) < 0)  {
		showErrorMessage ("Init error");
	}

	window = SDL_CreateWindow ("8bitGame", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED);

	if (!window || !renderer) {
		showErrorMessage ("Window or renderer error");
	}

	initedTiles = initMap (renderer, TEST_LEVEL_ROWS, TEST_LEVEL_COLS, testlevel);
	hero = createBeing (createTextureFromImage (renderer, "./sprites/mainHero.png"), 32, 32);

	while (running) {
		SDL_PollEvent (&event);

		if (event.type == SDL_QUIT) {
			running = 0;
		}

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
