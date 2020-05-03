#include "Game.h"


Game* game = nullptr;

int main(int argc, char* argv[]) {

	game = new Game();

	game->init("SHOOTING SQUARES", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720);

	const int frameDelay = 1000 / 60;

	Uint32 frameStart;
	int frameTime;

	while (game->isRunning()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);

	}

	game->clean();

	system("pause");
	return 0;
}