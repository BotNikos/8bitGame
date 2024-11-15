 /******************************//*!
 * \file	level.h
 * \brief	Описание
 * \author	Nikita Bolotov
 * \date	Создан: 07.11.2024
 * \date	Изменён: 07.11.2024
 */
#ifndef _LEVEL_H
#define _LEVEL_H

#include "sprites.h"
#include "hero.h"



/*
 *	Macros definition
 */


/*
 *	Type declaration
 */

struct _event_ {
	int 	x;
	int 	y;
	void 	(*onstep) (struct _hero_ *);
	void 	(*onuse) (struct _hero_ *);
};

struct _lvl_data_ {
	enum tile_names 	*matrix;
	struct _event_		*scripts;
	unsigned int		width;
	unsigned int		height;
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



#ifdef __cplusplus
}
#endif
#endif /* _LEVEL_H */
