#pragma once
#include <SDL.h>
#include "TextureManager.h"

class GameObject {
private:

	SDL_Texture* objTexture;
	SDL_Rect desRect, srcRect;

	SDL_Texture* missileTex;
	SDL_Rect missileRect;

	int counter = 0;

public:

	GameObject() = default;
	GameObject(SDL_Renderer* ren) {

		objTexture = TextureManager::getTex(ren, "assets/char.bmp");
		missileTex = TextureManager::getTex(ren, "assets/missile.bmp");

		desRect.y = 595;
		desRect.x = 1080 / 2 - 16;
		desRect.h = desRect.w = 65;

		missileRect.y = desRect.y;

		missileRect.h = 50;
		missileRect.w = 18;

	}
	~GameObject() = default;

	void renderObject(SDL_Renderer* ren) {

		SDL_RenderCopy(ren, objTexture, nullptr, &desRect);

	}

	void renderMissile(SDL_Renderer* ren) {

		counter++;

		if (counter == 1) {
			missileRect.x = desRect.x + 22;
		}
		missileRect.y -= 2;

		SDL_RenderCopy(ren, missileTex, nullptr, &missileRect);

	}

	void updateObject(int x) {

		desRect.x += x;

	}

};