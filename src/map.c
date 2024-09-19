#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "testlvl.h"
#include "map.h"
#include "sdlHelper.h"

struct tile* createTile (char *tileName, SDL_Texture *texutre,
                         SDL_Rect pos, SDL_Rect closedZone) {

    struct tile* tile = (struct tile *) malloc (sizeof (struct tile));
    
    strcpy (tile -> tileName, tileName);
    tile -> texture = texutre;
    tile -> pos = pos;
    tile -> closedZone = closedZone;

    return tile;
}

struct tile **initMap (SDL_Renderer *renderer, int rows, int cols, enum tileNames level[rows][cols]) {

    char *tileNames [] = {
        "grass",
        "flowersGrass",
        "pathHorizontal",
        "pathVertical",
        "pathLeftUp",
        "pathDownLeft",
        "pathDownRight",
        "pathUpLeft",
        "pathUpRight",
        "trees",
        "lakeRight",
        "lake"
    };

    size_t allTilesSize = rows * cols * sizeof (struct tile *);
    struct tile **initedTiles = (struct tile **) malloc (allTilesSize);

    SDL_Rect tilePos;
    tilePos.x = 0;
    tilePos.y = 0;
    tilePos.w = 32;
    tilePos.h = 32;

    SDL_Rect closedZone;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char tilePath [32];
            sprintf (tilePath, "./sprites/%s.png", tileNames [level [i][j]]);

            SDL_Texture *tileTexture = createTextureFromImage(renderer, tilePath);

            tilePos.x = j * 32;
            tilePos.y = i * 32;

            closedZone.x = 0; closedZone.y = 0;
            closedZone.w = 0; closedZone.h = 0;

            switch (level [i][j]) {
                case trees: case lake:
                    closedZone.w = 32;
                    closedZone.h = 32;
                    break;
                case lakeRight:
                    closedZone.x = 24;
                    closedZone.w = 32;
                    closedZone.h = 32;
                    break;
            }

            struct tile *tile = createTile (tilePath, tileTexture, tilePos, closedZone);

            int currentTileIndex = i * cols + j;
            initedTiles [currentTileIndex] = tile;
        }
    }

    return initedTiles;
}

void drawMap (SDL_Renderer *renderer, struct tile *initedTiles [], int mapSize) {
    
    for (int i = 0; i < mapSize; i++) {
        SDL_RenderCopy (renderer, initedTiles [i] -> texture, NULL, &initedTiles [i] -> pos);
    }

}
