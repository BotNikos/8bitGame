#ifndef TESTLVL_H
#define TESTLVL_H

enum tileNames {grass, flowersGrass, pathHorizontal, pathVertical,
                pathLeftUp, pathDownLeft, pathDownRight, pathUpLeft,
                pathUpRight, trees};

/* static int testLevelRows = 7; */
/* static int testLevelCols = 6;  */

#define TEST_LEVEL_ROWS 7
#define TEST_LEVEL_COLS 6

static enum tileNames testlevel[TEST_LEVEL_ROWS][TEST_LEVEL_COLS] = {
    {trees, trees, trees, trees, trees, trees},
    {trees, flowersGrass, flowersGrass, grass, flowersGrass, trees},
    {trees, pathDownRight, pathHorizontal, pathHorizontal, pathDownLeft, trees},
    {trees, pathVertical, grass, flowersGrass, pathVertical, trees},
    {trees, pathUpRight, pathHorizontal, pathHorizontal, pathUpLeft, trees},
    {trees, flowersGrass, flowersGrass, grass, flowersGrass, trees},
    {trees, trees, trees, trees, trees, trees}
};

#endif
