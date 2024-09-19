#ifndef MAP_H
#define MAP_H

enum tileNames {grass, flowersGrass, pathHorizontal, pathVertical,
                pathLeftUp, pathDownLeft, pathDownRight, pathUpLeft,
                pathUpRight, trees, lakeRight, lake};

struct tile {
    char tileName [32];
    SDL_Texture *texture; 
    SDL_Rect pos;
    SDL_Rect closedZone;
};

struct tile* createTile (char *, SDL_Texture *, SDL_Rect, SDL_Rect);

struct tile **initMap (SDL_Renderer *, int rows,
                       int cols, enum tileNames level[rows][cols]);

void drawMap (SDL_Renderer *, struct tile *[], int);

#endif
