 /******************************//*!
 * \file	map.c
 * \brief	Описание
 * \author	Nikita Bolotov
 * \date	Создан: 06.11.2024
 * \date	Изменён: 06.11.2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "hero.h"
#include "level.h"
#include "map.h"



/*
 *	Data definition:
 */


/*
 *	Functions(s) definitions:
 */

/*

TODO: 
Загрузка скриптов в клетку карты

*/
struct _map_ *initm (SDL_Renderer *r, struct _lvl_data_ *l) {
	struct _map_ 	*m 	= (struct _map_ *) malloc (sizeof (struct _map_));
	int 		m_sz	= l->width * l->height;
	int 		x 	= 0;
	int 		y 	= 0;
	char		n [128];

	assert (m);
	m->tiles = (struct _cell_ *) malloc (sizeof (struct _cell_) * m_sz);
	assert (m->tiles);

	for (int i = 0; i < m_sz; i++) {
		x = i % l->width;
		y = i / l->width;

		m->tiles->texture = gettexture (r, l->matrix[i]);

		m->tiles->pos.x = x * 32;
		m->tiles->pos.y = y * 32;
		m->tiles->pos.w = 32;
		m->tiles->pos.h = 32;

		m->tiles->onstep = NULL;
		m->tiles->onuse = NULL;
		
		m->tiles += 1;
	}

	return m;
}



