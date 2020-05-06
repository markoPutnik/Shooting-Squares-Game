#pragma once
#include <SDL.h>
#include <vector>
#include "TextureManager.h"

class GameObject {
private:

	SDL_Texture* objTexture;
	SDL_Rect desRect, srcRect;

	SDL_Texture* missileTex;
	
	vector<SDL_Rect> missileRects;

	vector<bool> booleans;

public:

	GameObject() = default;
	GameObject(SDL_Renderer* ren) {

		objTexture = TextureManager::getTex(ren, "assets/char.bmp");
		missileTex = TextureManager::getTex(ren, "assets/missile.bmp");

		desRect.y = 595;
		desRect.x = 1080 / 2 - 16;
		desRect.h = desRect.w = 65;

		booleans = { false, false, false, false };

	}
	~GameObject() = default;

	void renderObject(SDL_Renderer* ren) {

		SDL_RenderCopy(ren, objTexture, nullptr, &desRect);

	}

	void renderMissile(SDL_Renderer* ren, int nNumber) {

		
		if (nNumber == 1 && !booleans[nNumber]) {
			missileRects[nNumber].x = desRect.x + 22;
			booleans[nNumber] = true;
		}
		else if (nNumber == 2 && !booleans[nNumber]) {
			missileRects[nNumber].x = desRect.x + 22;
			booleans[nNumber] = true;
		}
		else if (nNumber== 3 && !booleans[nNumber]) {
			missileRects[nNumber].x = desRect.x + 22;
			booleans[nNumber] = true;
		}

		if (missileRects[nNumber].y <= 700) {
			missileRects[nNumber].y -= 3;
		}

		SDL_RenderCopy(ren, missileTex, nullptr, &missileRects[nNumber]);

	}

	void updateObject(int x) {

		if (desRect.x >= 0)
			desRect.x += x * 2;
		else {
			desRect.x = 1;
		}

		if (desRect.x <= 1015)
			desRect.x += x * 2;
		else {
			desRect.x = 1015;
		}

	}

	void createMissile() {

		SDL_Rect missileRect;

		missileRect.y = desRect.y;

		missileRect.h = 50;
		missileRect.w = 18;

		missileRects.push_back(missileRect);

	}

};