#ifndef BEING_H
#define BEING_H

#include <SDL2/SDL.h>
#include "map.h"

struct moving {
	unsigned char right: 	1;
	unsigned char up: 	1;
	unsigned char left: 	1;
	unsigned char down: 	1;
	unsigned char run: 	1;
};

struct being {
	SDL_Rect 	pos;
	SDL_Texture 	*img;
	struct moving 	moving;
	void 		(*move) (struct being *, SDL_Event, struct tile **, int);
};

unsigned char checkMove (struct being *, int, int, struct tile **, int);
void move (struct being *, SDL_Event, struct tile **, int);
struct being* createBeing (SDL_Texture *, int, int);

#endif
