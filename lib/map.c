#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../include/map.h"
#include "../include/sdlHelper.h"
#include "../levels/testlvl.h"

void drawMap (SDL_Renderer *renderer) {

    char *tileNames [] = {
        "grass",
        "flowersGrass",
        "pathHorizontal",
        "pathVertical",
        "pathLeftUp",
        "pathDownLeft",
        "pathDownRight",
        "pathUpLeft",
        "pathUpRight"
    };

    SDL_Rect tilePos;
    tilePos.x = 0;
    tilePos.y = 0;
    tilePos.w = 32;
    tilePos.h = 32;

    for (int i = 0; i < sizeof (testlevel) / (levelWidth * sizeof (int)); i++) {
        for (int j = 0; j < sizeof (testlevel [i]) / sizeof (int); j++) {
            char tile [32];
            sprintf (tile, "./sprites/%s.png", tileNames [testlevel [i][j]]);

            SDL_Texture *tileTexture = createTextureFromImage(renderer, tile);

            tilePos.x = j * 32;
            tilePos.y = i * 32;

            SDL_RenderCopy (renderer, tileTexture, NULL, &tilePos);
        }
    }
    
}
