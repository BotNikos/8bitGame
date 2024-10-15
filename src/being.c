 /******************************//*!
 * \file	being.c
 * \brief	Описание
 * \author	bolotovN
 * \date	Создан: 15.10.2024
 * \date	Изменён: 15.10.2024
 */
#include <assert.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "being.h"



/*
 *	Data definition:
 */



/*
 *	Functions(s) definitions:
 */

struct _being_ *initb (SDL_Renderer *rnd, const char *spr, unsigned x, unsigned y) {
	struct _being_ *b = (struct _being_ *) malloc (sizeof (struct _being_));
	assert (b);

	b->texture = IMG_LoadTexture(rnd, spr);

	b->pos.x = x;
	b->pos.y = y;
	b->pos.w = 32;
	b->pos.h = 32;

	return b;
}

