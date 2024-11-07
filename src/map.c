 /******************************//*!
 * \file	map.c
 * \brief	Описание
 * \author	Nikita Bolotov
 * \date	Создан: 06.11.2024
 * \date	Изменён: 06.11.2024
 */
#include <SDL3/SDL.h>
#include "hero.h"
#include "level.h"
#include "map.h"



/*
 *	Data definition:
 */


/*
 *	Functions(s) definitions:
 */

struct _map_ initm (SDL_Renderer *r, struct _lvl_data_ *l) {
	struct _map_ 	*m 	= (struct _map_ *) malloc (sizeof (struct _map_));
	int 		m_sz	= l.width * l.height;

	m.tiles = (struct _cell_ *) malloc (sizeof (struct _cell_));
	for (i = 0; i < m_sz; i++) {
		m.tiles [i] = 
	}

	return m;
}



