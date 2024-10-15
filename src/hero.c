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



struct _hero_ *init_h (SDL_Renderer *rnd, const char *spr, unsigned x, unsigned y, unsigned hp) {
	struct _hero_ *h = (struct _hero_ *) malloc (sizeof (struct _hero_));

	h->being = init_b (rnd, spr, x, y);
	h->hp = hp;


	return h;
}

