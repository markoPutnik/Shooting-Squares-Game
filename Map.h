#pragma once
#include <SDL.h>
#include "TextureManager.h"
#include <vector>

class Map {
private:

	SDL_Texture* floorTex;
	SDL_Texture* grassTex;

	SDL_Texture* hillTex1;
	SDL_Texture* hillTex2;

	SDL_Rect srcRect, desRect;

	SDL_Rect hillRect1, hillRect2;

	vector<vector<int> > map;

public:

	Map() = default;
	Map(SDL_Renderer* ren);
	~Map() = default;

	void drawMap(SDL_Renderer* ren);

	void drawHills(SDL_Renderer* ren);

	void updateHills();

};