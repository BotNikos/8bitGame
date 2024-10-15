 /******************************//*!
 * \file	tile_names.h
 * \brief	Описание
 * \author	bolotovN
 * \date	Создан: 15.10.2024
 * \date	Изменён: 15.10.2024
 */
#ifndef _TILE_NAMES_H
#define _TILE_NAMES_H



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
	LAKE_R
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
#endif /* _TILE_NAMES_H */
