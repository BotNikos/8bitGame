 /******************************//*!
 * \file	sprites.h
 * \brief	Описание
 * \author	bolotovN
 * \date	Создан: 15.10.2024
 * \date	Изменён: 15.10.2024
 */
#ifndef _SPRITES_H
#define _SPRITES_H

#include <SDL3_image/SDL_image.h>

/*
 *	Macros definition
 */



/*
 *	Type declaration
 */

enum tile_names {
	GRASS,
	FLW_GRASS,

	PATH_UD,	// up-down (vertical)
	PATH_UL,	// up-left
	PATH_UR,	// up-right
	PATH_DL,	// down-left
	PATH_DR,	// down-right 
	PATH_LR,	// left-right (horizontal)

	TREES,
	LAKE,
	LAKE_R,
	TILE_LAST = LAKE_R,
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

	SDL_Texture *gettexture (SDL_Renderer *, enum tile_names);

#ifdef __cplusplus
}
#endif
#endif /* _SPRITES_H */
