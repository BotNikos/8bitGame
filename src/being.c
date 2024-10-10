#include <SDL2/SDL.h>

#include "being.h"
#include "game_globals.h"
#include "map.h"

static unsigned char __checkMove (struct being *being, int nextX, int nextY, struct tile **initedTiles, int levelSize) {
	unsigned char canMove = 1;

	if (nextX < 0 || nextX > WINDOW_WIDTH - being -> pos.w)
		canMove = 0;

	if (nextY < 0 || nextY > WINDOW_HEIGHT - being -> pos.h)
		canMove = 0;

	for (int i = 0; i < levelSize; i++) {
		if (initedTiles [i] -> closedZone.h == 0)
			continue;

		int closedZoneX = initedTiles [i] -> closedZone.x + initedTiles [i] -> pos.x;
		int closedZoneEndX = closedZoneX + initedTiles [i] -> closedZone.w;

		int closedZoneY = initedTiles [i] -> closedZone.y + initedTiles [i] -> pos.y;
		int closedZoneEndY = closedZoneY + initedTiles [i] -> closedZone.h;

		if (nextX < closedZoneEndX && nextX + being -> pos.w > closedZoneX && nextY < closedZoneEndY && nextY + being -> pos.h > closedZoneY)
			canMove = 0;
	}
    
	return canMove;
}

static void __changeMoveState (struct being *self, SDL_Event event, unsigned char state) {
	switch (event.key.keysym.sym) {
		case SDLK_RIGHT: 	self -> moving.right 	= state; break;
		case SDLK_UP: 		self -> moving.up 	= state; break;
		case SDLK_LEFT: 	self -> moving.left 	= state; break;
		case SDLK_DOWN: 	self -> moving.down 	= state; break;
		case SDLK_LSHIFT: 	self -> moving.run 	= state; break;
	}
}

void move (struct being *self, SDL_Event event, struct tile **initedTiles, int levelSize) {
	int speed;

	if (event.type == SDL_KEYDOWN) {
		__changeMoveState (self, event, 1);
	} else if (event.type == SDL_KEYUP) {
		__changeMoveState (self, event, 0);
	}

	if (self -> moving.right && __checkMove (self, self -> pos.x + 1, self -> pos.y, initedTiles, levelSize))
		self -> pos.x += 1;

	if (self -> moving.up && __checkMove (self, self -> pos.x, self -> pos.y - 1, initedTiles, levelSize))
		self -> pos.y += -1;

	if (self -> moving.left && __checkMove (self, self -> pos.x - 1, self -> pos.y, initedTiles, levelSize))
		self -> pos.x += -1;

	if (self -> moving.down && __checkMove (self, self -> pos.x, self -> pos.y + 1, initedTiles, levelSize))
		self -> pos.y += 1;

	speed = self -> moving.run ? 4 : 7;
        
	SDL_Delay (speed);
}

struct being* createBeing (SDL_Texture *texture, int x, int y) {
	struct being *being = (struct being *) malloc (sizeof (struct being));

	being -> img 		= texture;

	being -> pos.x 		= x;
	being -> pos.y 		= y;
	being -> pos.w 		= 32;
	being -> pos.h 		= 32;

	being -> moving.right 	= 0;
	being -> moving.up 		= 0;
	being -> moving.left 	= 0;
	being -> moving.down 	= 0;
	being -> moving.run 	= 0;

	being -> move 		= move;

	return being;
}
