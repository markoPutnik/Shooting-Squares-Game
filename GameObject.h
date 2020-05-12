#pragma once
#include <SDL.h>
#include <vector>
#include <random>
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

	vector<bool> booleans;

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

	bool checkCollision(int nNumber);

};