 /******************************//*!
 * \file	hero.c
 * \brief	Описание
 * \author	bolotovN
 * \date	Создан: 15.10.2024
 * \date	Изменён: 15.10.2024
 */
#include <stdlib.h>
#include <SDL3/SDL.h>

#include "being.h"
#include "hero.h"
#include "game_globals.h"



/*
 *	Data definition:
 */

static unsigned char __ckcolls (struct _hero_ *h) {
	unsigned char 	rc 		= 1;
	SDL_FRect 	screen_box 	= {0 + 32, 0 + 32, SCREEN_WIDTH - 32, SCREEN_HEIGHT - 32};


	if (!SDL_HasRectIntersectionFloat(&h->being.pos, &screen_box)) {
		rc = 0;
	}
	

	return rc;
}

/*
 *	Functions(s) definitions:
 */

/**
	Chagne hero position by 1 pixel

	param[in]	e	event
	param[out]	h	hero struct
 */
static void __move (struct _hero_ *h, SDL_Event *e) {
	unsigned char s = !(e->key.type - SDL_EVENT_KEY_DOWN);

	switch (e->key.key) {
		case SDLK_UP:		h->moving.up	= s; break;
		case SDLK_DOWN:		h->moving.down	= s; break;
		case SDLK_LEFT:		h->moving.left	= s; break;
		case SDLK_RIGHT:	h->moving.right	= s; break;
		default: break;
	}

	if (h->moving.up && __ckcolls(h))
		h->being.pos.y -= 1;

	else if (h->moving.down && __ckcolls(h))
		h->being.pos.y += 1;

	if (h->moving.left && __ckcolls(h))
		h->being.pos.x -= 1;

	else if (h->moving.right && __ckcolls(h))
		h->being.pos.x += 1;
}

/**
	Init hero struct and return it

	params[in]	rnd	SDL Renderer
			spr 	Sprite name
			x	Start x pos
			y	Start y pos
			hp	Start hp
 */
struct _hero_ *inith (SDL_Renderer *rnd, const char *spr, unsigned x, unsigned y, unsigned hp) {
	struct _hero_ *h = (struct _hero_ *) malloc (sizeof (struct _hero_));

	h->being 	= *initb (rnd, spr, x, y);

	h->moving.up	= 0;
	h->moving.down	= 0;
	h->moving.left	= 0;
	h->moving.right	= 0;

	h->hp 		= hp;
	h->move 	= __move;

	return h;
}

