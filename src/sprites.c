 /******************************//*!
 * \file	sprites.c
 * \brief	Описание
 * \author	Nikita Bolotov 
 * \date	Создан: 15.11.2024
 * \date	Изменён: 15.11.2024
 */
#include <SDL3_image/SDL_image.h>

#include "sprites.h"

/*
 *	Data definition:
 */

static char *tile_names [] = {
	"grass",
	"flowersGrass",

	"pathVertical",
	"pathUpLeft",
	"pathUpRight",
	"pathDownLeft,"
	"pathDownRight",
	"pathHorizontal",

	"trees",
	"lake",
	"lakeRight",
};

static SDL_Texture *loaded_textures [TILE_LAST];


/*
 *	Functions(s) definitions:
 */

SDL_Texture * gettexture (SDL_Renderer *r, enum tile_names n) {
	SDL_Texture *t;

	if (loaded_textures [n] == NULL) {
		t = IMG_LoadTexture (r, tile_names [n]); // сделать имя правильным: "sprites/<tile_names [n]>.png"
		loaded_textures [n] = t;
	} else {
		t = loaded_textures [n];
	}

	return t;
}
