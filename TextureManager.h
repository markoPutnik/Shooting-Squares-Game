#pragma once
#include <SDL.h>

class TextureManager {
public:

	TextureManager() = default;
	~TextureManager() = default;

	static SDL_Texture* getTex(SDL_Renderer* ren, const char* path) {

		SDL_Surface* surface = SDL_LoadBMP(path);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);

		SDL_FreeSurface(surface);

		return tex;
	}

};
