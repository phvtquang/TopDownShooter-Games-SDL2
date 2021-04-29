#include "texturehandle.h"

SDL_Texture* texturehandle::LoadTexture(const std::string filepath, SDL_Renderer *render)
{
	//create temp surface then load IMG to it
	SDL_Surface* tmpsurface = NULL;
	tmpsurface = IMG_Load(filepath.c_str());

	//create texture to load it into
	SDL_Texture* texture = NULL;
	texture = SDL_CreateTextureFromSurface(render, tmpsurface);

	//free temp surface
	SDL_FreeSurface(tmpsurface);

	//return the loadedtexture
	return texture;
}

