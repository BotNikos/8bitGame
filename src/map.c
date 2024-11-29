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
#include "level.h"
#include "map.h"

/*
 *	Data definition:
 */


/*
 *	Functions(s) definitions:
 */


static void __draw (struct _map_ *m, struct SDL_Renderer *r) {
	for (int i = 0; i < m->width * m->height; i++) {
		SDL_RenderTexture (r, (m->tiles + i)->texture, NULL, &(m->tiles + i)->pos);
	}
}

/**
	Init map according to passed level info

	param[in]	r	SDL_Renderer
			l	Level data
	return		map	Inited map
 */
struct _map_ *initm (SDL_Renderer *r, struct _lvl_data_ *l) {
	struct _map_ 	*m 	= (struct _map_ *) malloc (sizeof (struct _map_));
	int 		m_sz	= l->width * l->height;
	int 		x 	= 0;
	int 		y 	= 0;
	int		e 	= 0;

	m->width = l->width;
	m->height = l->height;
	m->draw = __draw;

	assert (m);
	m->tiles = (struct _cell_ *) malloc (sizeof (struct _cell_) * m_sz);
	assert (m->tiles);
	memset (m->tiles, 0, sizeof (struct _cell_) * m_sz);

	for (int i = 0; i < m_sz; i++) {
		x = i % l->width;
		y = i / l->width;

		m->tiles->texture = gettexture (r, l->matrix[i]);

		m->tiles->pos.x = x * 32;
		m->tiles->pos.y = y * 32;
		m->tiles->pos.w = 32;
		m->tiles->pos.h = 32;

		if (l->scripts[e].x == x && l->scripts[e].y == y) {
			m->tiles->onstep = l->scripts[e].onstep;
			m->tiles->onuse = l->scripts[e].onuse;
		}
		
		m->tiles += 1;
	}

	m->tiles -= m_sz;
	return m;
}



