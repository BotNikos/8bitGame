 /******************************//*!
 * \file	map.h
 * \brief	Описание
 * \author	Nikita Bolotov	
 * \date	Создан: 06.11.2024
 * \date	Изменён: 06.11.2024
 */
#ifndef _MAP_H
#define _MAP_H

#include <SDL3/SDL.h>
#include "hero.h"



/*
 *	Macros definition
 */



/*
 *	Type declaration
 */

struct _cell_ {
	SDL_Texture 	texture;
	SDL_FRect 	pos;
	void 		(*onstep) 	(struct _hero_ *);
	void 		(*onuse) 	(struct _hero_ *);
}

/*
 *	Data declaration
 */



/*
 *	Function declaration
 */



#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif
#endif /* _MAP_H */
