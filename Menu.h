#pragma once
#include "TextureManager.h"

class Menu {
private:

	SDL_Texture* texture;
	SDL_Texture* missionTex;
	SDL_Texture* goBackButtonTex;
	SDL_Texture* goBackOptionTex;

	SDL_Rect menuRect;
	SDL_Rect missionRect;
	SDL_Rect goBackButtonRect;
	SDL_Rect goBackOptionRect;

public:

	Menu() = default;
	Menu(SDL_Renderer* ren) {

		texture = TextureManager::getTex(ren, "assets/mainMenu2.bmp");
		missionTex = TextureManager::getTex(ren, "assets/missionMenu.bmp");
		goBackButtonTex = TextureManager::getTex(ren, "assets/goBackButton.bmp");
		goBackOptionTex = TextureManager::getTex(ren, "assets/pressPButton.bmp");

		menuRect = { 1080/3 + 20, 720/3 + 20,320, 222 };
		missionRect = { 1080 / 3 , 720 / 3 , 360 , 240 };
		goBackButtonRect = { 20, 20, 150, 70 };
		goBackOptionRect = { 1080 / 3 - 50 , 720 / 3, 500 , 220 };

	}
	~Menu() {
		texture = nullptr;
		missionTex = nullptr;
		goBackButtonTex = nullptr;
	}

	void render(SDL_Renderer* ren) {

		SDL_RenderCopy(ren, texture, nullptr, &menuRect);

	}

	void renderMissionText(SDL_Renderer* ren) {

		SDL_RenderCopy(ren, missionTex, nullptr, &missionRect);
		SDL_RenderCopy(ren, goBackButtonTex, nullptr, &goBackButtonRect);

	}

	void renderGoBackOption(SDL_Renderer* ren) {

		SDL_RenderCopy(ren, goBackOptionTex, nullptr, &goBackOptionRect);

	}

};
