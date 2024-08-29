#ifndef TESTLVL_H
#define TESTLVL_H

enum tileNames {grass, flowersGrass, pathHorizontal, pathVertical,
                pathLeftUp, pathDownLeft, pathDownRight, pathUpLeft,
                pathUpRight};

static int levelWidth = 5; 

static enum tileNames testlevel[][5] = { // 5 is levelWidth
    {grass, flowersGrass, flowersGrass, grass, flowersGrass},
    {grass, pathDownRight, pathHorizontal, pathDownLeft, flowersGrass},
    {grass, pathVertical, grass, grass, pathHorizontal},
    {flowersGrass, pathUpRight, grass, flowersGrass, pathUpLeft},
    {grass, flowersGrass, flowersGrass, grass, flowersGrass}
};

#endif
