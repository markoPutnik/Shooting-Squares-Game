#include "Game.h"
#include "TextureManager.h"
#include "Menu.h"
#include "Map.h"
#include "GameObject.h"
#include "MissileText.h"

Menu* menu = nullptr;
Map* map = nullptr;
GameObject* playerObject = nullptr;
MissileText* missileText = nullptr;


void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		window = SDL_CreateWindow(title, x, y, width, height, fullscreen);

		renderer = SDL_CreateRenderer(window, -1, 0);

		menu = new Menu(renderer);
		map = new Map(renderer);
		playerObject = new GameObject(renderer);
		missileText = new MissileText(renderer);

		m_Running = true;
		m_Running2 = true;
		mouseMenuClicked = false;
		mouseMissionOptionClicked = false;
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
		m_Running2 = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT) {
			SDL_GetMouseState(&mouseX, &mouseY);
			if (mouseX < 700 && mouseX > 380 && mouseY < 485 && mouseY > 260) {
				if (mouseY > 337 && mouseY < 410 && !mouseMissionOptionClicked)
					m_Running = false;
				else if (mouseY >= 410) {
					if (mouseX > 20 && mouseX < 170 && mouseY > 20 && mouseY < 90)
					mouseMissionOptionClicked = true;
				}
				else if(!mouseMissionOptionClicked)
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
			if (!m_Running) {
				m_Running = true;
			}
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

		for (int i = 0; i < 7; ++i) {
			if (spacePresses[i] && spacePresses2[i]) {
				playerObject->createMissile();
				spacePresses2[i] = false;
			}
		}

		map->updateHills();
		playerObject->updateFallingObjects();

		if (!playerObject->checkCollisionMissiles(counter2)) {
			m_Running = false;
		}
		if (!playerObject->checkCollisionObjectFallingObject()) {
			m_Running = false;
		}

		if (playerObject->returnCounterMissedObjects() == 3) {
			m_Running = false;
		}

		if (playerObject->returnCounterHitObjects() == 10) {
			m_Running = false;
		}

	}

}

void Game::render() {

	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 200, 255);

	if (m_Running) {

		if (!mouseMenuClicked) {
			if (!mouseMissionOptionClicked) {
				menu->render(renderer);
			}
			else {
				menu->renderMissionText(renderer);
			}
		}
		else {

			map->drawHills(renderer);
			map->drawMap(renderer);

			missileText->renderMissedObjectsText(renderer, playerObject->returnCounterMissedObjects());
			missileText->renderHitObjectsText(renderer, playerObject->returnCounterHitObjects());

			for (int i = 0; i < 3; ++i) {
				if (spacePresses[i]) {
					playerObject->renderMissile(renderer, counter2);
				}
			}

			playerObject->renderObject(renderer);
			playerObject->renderFallingObjects(renderer);

		}

	}
	else {

		menu->renderGoBackOption(renderer);

	}


	SDL_RenderPresent(renderer);

}

void Game::clean() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

}