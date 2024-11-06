 /******************************//*!
 * \file	hero.c
 * \brief	Описание
 * \author	bolotovN
 * \date	Создан: 15.10.2024
 * \date	Изменён: 15.10.2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

#include "being.h"
#include "hero.h"
#include "game_globals.h"



/*
 *	Data definition:
 */

/*
 *	Functions(s) definitions:
 */

/**
	Get next posision of the hero based on hero->moving struct


	params[in]	h	Hero struct
	params[out]	p	Next hero position
 */
static void __getnpos (struct _hero_ *h, SDL_FRect *p) {
	if (h->moving.up)
		p->y -= 1;

	else if (h->moving.down)
		p->y += 1;

	if (h->moving.left)
		p->x -= 1;

	else if (h->moving.right)
		p->x += 1;
}

/**
	Check collisions with screen and closzed zones
	in a 9 blocks around the hero

	params[in]	h	Hero struct
	params[out]	np	Next hero position
 */
static void __ckcolls (struct _hero_ *h, SDL_FRect *np) {
	if (np->x < 0 || np->x > SCREEN_WIDTH) {
		np->x = h->being.pos.x;
	}

	if (np->y < 0 || np->y > SCREEN_HEIGHT) {
		np->y = h->being.pos.y;
	}
}

/**
	Chagne the hero position by 1 pixel

	param[in]	e	Event
	param[out]	h	Hero struct
 */
static void __move (struct _hero_ *h, SDL_Event *e) {
	unsigned char 	s	= !(e->key.type - SDL_EVENT_KEY_DOWN);
	SDL_FRect	p	= h->being.pos;

	switch (e->key.key) {
		case SDLK_UP:		h->moving.up	= s; break;
		case SDLK_DOWN:		h->moving.down	= s; break;
		case SDLK_LEFT:		h->moving.left	= s; break;
		case SDLK_RIGHT:	h->moving.right	= s; break;
		default: break;
	}

	__getnpos (h, &p);
	__ckcolls (h ,&p);
	h->being.pos = p;
}

/**
	Init a hero struct and return it

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

