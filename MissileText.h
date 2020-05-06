#pragma once
#include "TextureManager.h"
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class MissileText {
private:

	vector<SDL_Texture*> texts;

	SDL_Rect desRect;

public:

	MissileText() = default;
	MissileText(SDL_Renderer* ren) {

		texts.push_back(TextureManager::getTex(ren, "assets/missileText0.bmp"));
		texts.push_back(TextureManager::getTex(ren, "assets/missileText1.bmp"));
		texts.push_back(TextureManager::getTex(ren, "assets/missileText2.bmp"));
		texts.push_back(TextureManager::getTex(ren, "assets/missileText3.bmp"));

		desRect.h = 90;
		desRect.w = 240;
		desRect.x = desRect.y = 10;

	}
	~MissileText() {
		for (auto& i : texts) {
			i = nullptr;
		}
	}

	void renderMissileText(SDL_Renderer* ren, int nNumber) {

		if (nNumber >= 0 && nNumber <= 3) {
			SDL_RenderCopy(ren, texts[3 - nNumber], nullptr, &desRect);
		}

	}

};