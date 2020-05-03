#pragma once
#include <SDL.h>
#include "TextureManager.h"

class GameObject {
private:

	SDL_Texture* objTexture;

	SDL_Rect desRect, srcRect;

public:

	GameObject() = default;
	GameObject(SDL_Renderer* ren) {

		objTexture = TextureManager::getTex(ren, "assets/char.bmp");

		desRect.y = 595;
		desRect.x = 1080 / 2 - 16;
		desRect.h = desRect.w = 65;

	}
	~GameObject() = default;

	void renderObject(SDL_Renderer* ren) {

		SDL_RenderCopy(ren, objTexture, nullptr, &desRect);

	}

	void updateObject(int x) {

		desRect.x += x;

	}

};