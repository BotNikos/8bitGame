#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../include/map.h"
#include "../include/sdlHelper.h"
#include "../levels/testlvl.h"

void drawMap (SDL_Renderer *renderer) {

    for (int i = 0; i < sizeof (testlevel) / levelWidth * sizeof (int)) {
        for (int j = 0; j < sizeof (testlevel [i]) / levelWidth) {
            
        }
    }
    
}
