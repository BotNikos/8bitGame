#ifndef TESTLVL_H
#define TESTLVL_H

#include "map.h"

#define TEST_LEVEL_ROWS 7
#define TEST_LEVEL_COLS 6

static enum tileNames testlevel[TEST_LEVEL_ROWS][TEST_LEVEL_COLS] = {
	{trees,	trees,		trees,		trees,		lakeRight,	lake},
	{trees,	flowersGrass,	flowersGrass,	grass,		lakeRight,	lake},
	{trees,	pathDownRight,	pathHorizontal,	pathHorizontal, lakeRight,	lake},
	{trees,	pathVertical,	trees,		flowersGrass,	lakeRight,	lake},
	{trees,	pathUpRight,	pathHorizontal,	pathHorizontal, lakeRight,	lake},
	{trees,	flowersGrass,	flowersGrass,	grass,		lakeRight,	lake},
	{trees,	flowersGrass,	trees,		trees,		lakeRight,	lake}
};

#endif
