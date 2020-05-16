#pragma once
#include <SDL.h>
#include <vector>
#include <random>
#include <iostream>
#include "TextureManager.h"
#include "CollisionAABB.h"

using namespace std;

class GameObject {
private:

	SDL_Texture* objTexture;
	SDL_Rect desRect;

	SDL_Texture* fallingObjectTex;
	SDL_Rect fallingObjectRect;
	vector<SDL_Rect> fallingObjectsVec;

	SDL_Texture* missileTex;
	vector<SDL_Rect> missileRects;

	SDL_Rect missileRect;

	int nCounterMissedObjects, nCounterHitObjects;

	int numberN;

public:

	GameObject() = default;
	GameObject(SDL_Renderer* ren);
	~GameObject();

	void renderObject(SDL_Renderer* ren);
	void renderFallingObjects(SDL_Renderer* ren);
	void renderMissile(SDL_Renderer* ren, int nNumber);

	void updateFallingObjects();
	void updateObject(int x);

	void createMissile();

	bool checkCollisionMissiles(int nNumber);
	bool checkCollisionObjectFallingObject();

	int returnCounterMissedObjects() {
		return nCounterMissedObjects;
	}

	int returnCounterHitObjects() {
		return nCounterHitObjects;
	}

};