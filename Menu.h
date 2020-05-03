#pragma once
#include "TextureManager.h"

class Menu {
private:

	SDL_Texture* texture;

	SDL_Rect menuRect;

public:

	Menu() = default;
	Menu(SDL_Renderer* ren) {

		texture = TextureManager::getTex(ren, "assets/mainMenu.bmp");

		menuRect = { 1080/3 + 20, 720/3 + 20,320, 150 };

	}
	~Menu() = default;

	void render(SDL_Renderer* ren) {

		SDL_RenderCopy(ren, texture, nullptr, &menuRect);

	}


};
