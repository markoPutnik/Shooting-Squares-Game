#pragma once
#include "TextureManager.h"

class Menu {
private:

	SDL_Texture* texture;
	SDL_Texture* missionTex;

	SDL_Rect menuRect;
	SDL_Rect missionRect;

public:

	Menu() = default;
	Menu(SDL_Renderer* ren) {

		texture = TextureManager::getTex(ren, "assets/mainMenu2.bmp");
		missionTex = TextureManager::getTex(ren, "assets/missionMenu.bmp");

		menuRect = { 1080/3 + 20, 720/3 + 20,320, 222 };
		missionRect = { 1080 / 3 , 720 / 3 , 360 , 240 };

	}
	~Menu() = default;

	void render(SDL_Renderer* ren) {

		SDL_RenderCopy(ren, texture, nullptr, &menuRect);

	}

	void renderMissionText(SDL_Renderer* ren) {

		SDL_RenderCopy(ren, missionTex, nullptr, &missionRect);

	}

};
