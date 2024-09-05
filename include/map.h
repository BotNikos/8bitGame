#ifndef MAP_H
#define MAP_H

#include "tileNames.h"

struct tile {
    char tileName [32];
    SDL_Texture *texture; 
    SDL_Rect pos;
    SDL_Rect closedZone;
};

struct tile* createTile (char *tileName, SDL_Texture *texutre,
                         SDL_Rect pos, SDL_Rect closedZone);

struct tile **initMap (SDL_Renderer *renderer, int rows,
                       int cols, enum tileNames level[rows][cols]);

void drawMap (SDL_Renderer *renderer, struct tile *initedTiles [], int mapSize);

#endif
