#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* ren) {

	objTexture = TextureManager::getTex(ren, "assets/char.bmp");
	missileTex = TextureManager::getTex(ren, "assets/missile.bmp");
	fallingObjectTex = TextureManager::getTex(ren, "assets/fallingSquare.bmp");

	desRect.y = 595;
	desRect.x = 1080 / 2 - 16;
	desRect.h = desRect.w = 65;

	fallingObjectRect.w = 65;
	fallingObjectRect.h = 72;
	fallingObjectRect.y = 0;

	for (int i = 0; i < 3; ++i) {
		fallingObjectRect.x = rand() % 1018;
		fallingObjectsVec.push_back(fallingObjectRect);
	}

	fallingObjectsVec[0].x += 500;
	fallingObjectsVec[1].y -= 500;
	fallingObjectsVec[2].y -= 250;

	missileRect.h = 50;
	missileRect.w = 18;
	missileRect.y = desRect.y;

	for (int i = 0; i < 14; ++i) {
		missileRects.push_back(missileRect);
	}

	nCounterMissedObjects = 0;
	nCounterHitObjects = 0;
	numberN = 0;
	nMakeSpeedSlower = 0;

}

void GameObject::renderObject(SDL_Renderer* ren) {

	SDL_RenderCopy(ren, objTexture, nullptr, &desRect);

}

void GameObject::renderFallingObjects(SDL_Renderer* ren) {

	for (auto rec : fallingObjectsVec) {
		SDL_RenderCopy(ren, fallingObjectTex, nullptr, &rec);
	}

}

void GameObject::renderMissile(SDL_Renderer* ren, int nNumber) {


	if (nNumber > 0 && nNumber < 14 && numberN < 14) {

		if (missileRects[nNumber - 1].y <= 700) {
			missileRects[nNumber - 1].y -= (5 - (int)(nNumber/3));
		}

		SDL_RenderCopy(ren, missileTex, nullptr, &missileRects[nNumber - 1]);

	}

}

void GameObject::reset() {

	missileRects.clear();
	for (int i = 0; i < 14; ++i) {
		missileRects.push_back(missileRect);
	}

}

void GameObject::updateFallingObjects() {

	for (int i = 0; i < fallingObjectsVec.size(); ++i) {
		if (fallingObjectsVec[i].y <= 710) {
			fallingObjectsVec[i].y += 2;
		}
		else if (fallingObjectsVec[i].y == 712) {
			nCounterMissedObjects++;
			fallingObjectsVec[i].y = -200;
			fallingObjectsVec[i].x = rand() % 1018;
		}
	}

}

void GameObject::updateObject(int x) {

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

void GameObject::createMissile() {

	if (numberN >= 0 && numberN < 13) {

		missileRects[numberN].x = desRect.x + 23;

		cout << "Created a missile\n";

	}

	numberN++;

}

bool GameObject::checkCollisionMissiles(int nNumber) {

	if (nNumber > 0 && nNumber < 14) {

		for (auto &rec : fallingObjectsVec) {

			if (Collision::AABB(rec, missileRects[nNumber - 1])) {

				if (rec.y >= 250) {
					rec.y = -450;
				}
				else {
					rec.y -= 250;
				}
				rec.x = rand() % 1018;

				missileRects[nNumber - 1].y = 720;

				nCounterHitObjects++;

			}

		}

	}

	return true;

}

bool GameObject::checkCollisionObjectFallingObject() {

	for (auto &rec : fallingObjectsVec) {
		if (Collision::AABB(rec, desRect)) {
			return false;
		}
	}

	return true;
}

GameObject::~GameObject() {

	objTexture = nullptr;
	fallingObjectTex = nullptr;
	missileTex = nullptr;

}