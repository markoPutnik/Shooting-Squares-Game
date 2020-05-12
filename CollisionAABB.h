#pragma once
#include <SDL.h>

class Collision {
private:


public:

	static bool AABB(SDL_Rect& recA, SDL_Rect& recB) {
		if (recA.x + recA.w >= recB.x &&
			recB.x + recB.w >= recA.x &&
			recA.y + recA.h >= recB.y &&
			recB.y + recB.h >= recA.y) {
			
			return true;

		}
		else {
			return false;
		}
	}

};