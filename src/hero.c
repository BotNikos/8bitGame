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



/*
 *	Data definition:
 */



/*
 *	Functions(s) definitions:
 */

static void __chgmove (struct _hero_ *h, SDL_Event *e, unsigned char s) {
	switch (e->key.key) {
	    case SDLK_UP: 	h->moving.up = s; break;
	    case SDLK_DOWN: 	h->moving.down = s; break;
	    case SDLK_LEFT: 	h->moving.left = s; break;
	    case SDLK_RIGHT: 	h->moving.right = s; break;
	    default: break;
	}
}


static void __move (struct _hero_ *h, SDL_Event *e) {
	if (e->key.type == SDL_EVENT_KEY_DOWN)
		__chgmove (h, e, 1);

	else if (e->key.type == SDL_EVENT_KEY_UP)
		__chgmove (h, e, 0);


	if (h->moving.up)
		h->being.pos.y -= 1;

	if (h->moving.down)
		h->being.pos.y += 1;

	if (h->moving.left)
		h->being.pos.x -= 1;

	if (h->moving.right)
		h->being.pos.x += 1;
}


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

