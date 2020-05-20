#pragma once
#include <SDL.h>
#include <iostream>

using namespace std;

class KeyPressed {
private:

	SDL_Event e;
	bool spacePressed;

public:

	KeyPressed() {
		spacePressed = false;
	}

	bool checkSpacePressed() {

		SDL_PollEvent(&e);
		switch (e.type) {
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym) {
			case SDLK_SPACE:
				spacePressed = true;
				break;
			default:
				spacePressed = false;
				break;
			}
		}

		return spacePressed;

	}

	bool returnSpacePressed() {
		return spacePressed;
	}

	~KeyPressed() {

	}

};