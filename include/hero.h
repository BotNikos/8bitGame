 /******************************//*!
 * \file	hero.h
 * \brief	Описание
 * \author	bolotovN
 * \date	Создан: 15.10.2024
 * \date	Изменён: 15.10.2024
 */
#ifndef _HERO_H
#define _HERO_H

#include <SDL3/SDL.h>

#include "being.h"

/*
 *	Macros definition
 */



/*
 *	Type declaration
 */

struct _moving_ {
	unsigned up: 	1;
	unsigned down: 	1;
	unsigned left: 	1;
	unsigned right: 1;
};

struct _hero_ {
	struct _being_ being;
	struct _moving_ moving;
	unsigned hp;
	void (*move) (struct _hero_ *, SDL_Event *);
};


/*
 *	Data declaration
 */



/*
 *	Function declaration
 */



#ifdef __cplusplus
extern "C" {
#endif
	struct _hero_ *inith (SDL_Renderer *, const char *, unsigned, unsigned, unsigned);

#ifdef __cplusplus
}
#endif
#endif /* _HERO_H */
