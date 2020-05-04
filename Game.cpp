#include "Game.h"
#include "TextureManager.h"
#include "Menu.h"
#include "Map.h"
#include "GameObject.h"

Menu* menu = nullptr;
Map* map = nullptr;
GameObject* playerObject = nullptr;


void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		window = SDL_CreateWindow(title, x, y, width, height, fullscreen);

		renderer = SDL_CreateRenderer(window, -1, 0);

		menu = new Menu(renderer);
		map = new Map(renderer);
		playerObject = new GameObject(renderer);

		m_Running = true;
		mouseMenuClicked = false;
		spaceKeyPressed = false;
		spaceKeyReleased = false;
		bHoldingKey = false;

	}

}

void Game::handleEvents() {

	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		m_Running = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT) {
			SDL_GetMouseState(&mouseX, &mouseY);
			if (mouseX < 700 && mouseX > 380 && mouseY < 410 && mouseY > 260) {
				if (mouseY > 337)
					m_Running = false;
				mouseMenuClicked = true;
			}
		}
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			direction = -1;
			break;
		case SDLK_RIGHT:
			direction = 1;
			break;
		case SDLK_ESCAPE:
			m_Running = false;
			break;
		case SDLK_SPACE:
			if (spacePressedCounter == 0) {
				spacePresses[counter2] = true;
				counter2++;
			}
			spacePressedCounter++;
			break;
		default:
			break;
		}

		bHoldingKey = true;

		break;
	case SDL_KEYUP:
		bHoldingKey = false;
		direction = 0;
		switch (event.key.keysym.sym) {
		case SDLK_SPACE:
			spacePressedCounter = 0;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

}

void Game::update() {

	cout << m_counter++ << "\n";

	if (mouseMenuClicked) {

		if (bHoldingKey) {
			playerObject->updateObject(direction);
		}

		for (int i = 0; i < 3; ++i) {
			if (spacePresses[i]) {
				playerObject->createMissile();
			}
		}

		map->updateHills();
	}

}

void Game::render() {

	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 200, 255);

	if (!mouseMenuClicked) {
		menu->render(renderer);
	}
	else {

		map->drawHills(renderer);
		map->drawMap(renderer);

		for (int i = 0; i < 3; ++i) {
			if (spacePresses[i]) {
				playerObject->renderMissile(renderer, counter2);
			}
		}
		
		playerObject->renderObject(renderer);

	}
	

	SDL_RenderPresent(renderer);

}

void Game::clean() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();

}