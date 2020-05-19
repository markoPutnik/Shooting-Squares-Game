#pragma once
#include "TextureManager.h"
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class MissileText {
private:

	vector<SDL_Texture*> missedObjects;
	vector<SDL_Texture*> hitObjects;

	SDL_Rect missedObjectsRect;
	SDL_Rect hitObjectsRect;

public:

	MissileText() = default;
	MissileText(SDL_Renderer* ren) {

		missedObjects.push_back(TextureManager::getTex(ren, "assets/missedObjectsFiles/missedObject0.bmp"));
		missedObjects.push_back(TextureManager::getTex(ren, "assets/missedObjectsFiles/missedObject1.bmp"));
		missedObjects.push_back(TextureManager::getTex(ren, "assets/missedObjectsFiles/missedObject2.bmp"));
		missedObjects.push_back(TextureManager::getTex(ren, "assets/missedObjectsFiles/missedObject3.bmp"));
		missedObjects.push_back(TextureManager::getTex(ren, "assets/missedObjectsFiles/missedObject4.bmp"));
		missedObjects.push_back(TextureManager::getTex(ren, "assets/missedObjectsFiles/missedObject5.bmp"));

		missedObjectsRect.h = 90;
		missedObjectsRect.w = 240;
		missedObjectsRect.x = missedObjectsRect.y = 10;

		hitObjects.push_back(TextureManager::getTex(ren, "assets/hitObjectsFiles/hitObjects0.bmp"));
		hitObjects.push_back(TextureManager::getTex(ren, "assets/hitObjectsFiles/hitObjects1.bmp"));
		hitObjects.push_back(TextureManager::getTex(ren, "assets/hitObjectsFiles/hitObjects2.bmp"));
		hitObjects.push_back(TextureManager::getTex(ren, "assets/hitObjectsFiles/hitObjects3.bmp"));
		hitObjects.push_back(TextureManager::getTex(ren, "assets/hitObjectsFiles/hitObjects4.bmp"));
		hitObjects.push_back(TextureManager::getTex(ren, "assets/hitObjectsFiles/hitObjects5.bmp"));
		hitObjects.push_back(TextureManager::getTex(ren, "assets/hitObjectsFiles/hitObjects6.bmp"));
		hitObjects.push_back(TextureManager::getTex(ren, "assets/hitObjectsFiles/hitObjects7.bmp"));

		hitObjectsRect.h = 90;
		hitObjectsRect.w = 240;
		hitObjectsRect.x = 10;
		hitObjectsRect.y = 100;

	}
	~MissileText() {

		for (auto& i : missedObjects) {
			i = nullptr;
		}

		for (auto &i : hitObjects) {
			i = nullptr;
		}

	}

	void renderMissedObjectsText(SDL_Renderer* ren, int nNumber) {

		if (nNumber >= 0 && nNumber <= 5) {
			SDL_RenderCopy(ren, missedObjects[nNumber], nullptr, &missedObjectsRect);
		}
		else {
			SDL_RenderCopy(ren, missedObjects[0], nullptr, &missedObjectsRect);
		}

	}

	void renderHitObjectsText(SDL_Renderer* ren, int nNumber) {

		if (nNumber >= 0 && nNumber <= 5) {
			SDL_RenderCopy(ren, hitObjects[nNumber], nullptr, &hitObjectsRect);
		}
		else {
			SDL_RenderCopy(ren, hitObjects[5], nullptr, &hitObjectsRect);
		}

	}

};