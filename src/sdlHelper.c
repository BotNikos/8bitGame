#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include "sdlHelper.h"

void showErrorMessage (char *message) {
    printf ("Error: %s, %s", message, SDL_GetError());
    exit (1);
}

SDL_Texture *checkTexture (struct loadedTexture *allTextures, int texturesCount, char *fileName) {
    for (int i = 0; i < texturesCount; i++) {
        if (strcmp (allTextures [i].fileName, fileName) == 0)
            return allTextures [i].texture;
    }

    return NULL;
}

SDL_Texture *createTextureFromImage (SDL_Renderer *renderer, char *fileName) {

    // Not sure this is a good decision
    static struct loadedTexture *allTextures;
    static size_t allTextureSize = 0;
    static int texturesCount = 0;

    SDL_Texture *texture;
    texture = checkTexture (allTextures, texturesCount, fileName);

    if (texture)
        return texture;

    SDL_Surface *image = IMG_Load (fileName);

    if (!image)
        showErrorMessage (fileName);

    texture = SDL_CreateTextureFromSurface(renderer, image);

    if (!texture)
        showErrorMessage ("texture create");

    struct loadedTexture textureInfo;
    strcpy (textureInfo.fileName, fileName);
    textureInfo.texture = texture;

    allTextureSize += sizeof (textureInfo);
    allTextures = realloc (allTextures, allTextureSize);

    allTextures [texturesCount++] = textureInfo;

    SDL_FreeSurface (image);
    return texture;
}
