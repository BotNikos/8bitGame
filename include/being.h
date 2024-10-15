 /******************************//*!
 * \file	being.h
 * \brief	Описание
 * \author	bolotovN
 * \date	Создан: 15.10.2024
 * \date	Изменён: 15.10.2024
 */
#ifndef _BEING_H
#define _BEING_H

#include <SDL3/SDL.h>

/*
 *	Macros definition
 */



/*
 *	Type declaration
 */

struct _being_ {
	SDL_Texture *texture;	
	SDL_FRect pos;
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

	struct _being_ *initb (SDL_Renderer *, const char *, unsigned, unsigned);

#ifdef __cplusplus
}
#endif
#endif /* _BEING_H */
