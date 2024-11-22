 /******************************//*!
 * \file	sprites.c
 * \brief	Описание
 * \author	Nikita Bolotov 
 * \date	Создан: 15.11.2024
 * \date	Изменён: 15.11.2024
 */
#include <stdio.h>
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
	"pathDownLeft",
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
	char s [128];

	if (loaded_textures [n] == NULL) {
		sprintf (s, "sprites/%s.png", tile_names [n]);
		t = IMG_LoadTexture (r, s);
		loaded_textures [n] = t;
	} else {
		t = loaded_textures [n];
	}

	return t;
}
