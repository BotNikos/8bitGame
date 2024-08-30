#ifndef TESTLVL_H
#define TESTLVL_H

enum tileNames {grass, flowersGrass, pathHorizontal, pathVertical,
                pathLeftUp, pathDownLeft, pathDownRight, pathUpLeft,
                pathUpRight};

static int levelWidth = 6; 

static enum tileNames testlevel[][6] = { // 5 is levelWidth
    {grass, flowersGrass, flowersGrass, grass, flowersGrass, grass},
    {grass, pathDownRight, pathHorizontal, pathHorizontal, pathDownLeft, flowersGrass},
    {grass, pathVertical, grass, flowersGrass, pathVertical, flowersGrass},
    {flowersGrass, pathUpRight, pathHorizontal, pathHorizontal, pathUpLeft, grass},
    {grass, flowersGrass, flowersGrass, grass, flowersGrass, flowersGrass}
};

#endif
