 /******************************//*!
 * \file	testlvl.c
 * \brief	Описание
 * \author	Nikita Bolotov 
 * \date	Создан: 07.11.2024
 * \date	Изменён: 07.11.2024
 */
#include "level.h"
#include "hero.h"
#include "tile_names.h"

#include "testlvl.h"

/*
 *	Functions(s) definitions:
 */

static void __damage (struct _hero_ *h) {
	h->hp -= 20;
}

/*
 *	Data definition:
 */

static enum tile_names __matrix [TESTLVL_HEIGHT][TESTLVL_WIDTH] = {
	{GRASS,		GRASS,		FLW_GRASS,	GRASS},
	{TREES,		PATH_UD,	TREES,		FLW_GRASS},
	{TREES,		PATH_UD,	TREES,		FLW_GRASS},
	{GRASS,		GRASS,		FLW_GRASS,	GRASS},
};


static struct _event_ __scripts [] = {
	{3, 0, __damage, NULL}
};

struct _lvl_data_ testlvl = {__matrix, __scripts, TESTLVL_WIDTH, TESTLVL_HEIGHT};

