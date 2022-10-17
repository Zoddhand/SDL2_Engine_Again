#pragma once
#include "Engine.h"

class Skeleton : public Entity
{
public:
	Skeleton(int xpos = 0, int ypos = 0)
		: patrollingLeft(false) {
		setX(xpos);
		setY(ypos);
	}

	virtual void update();

	virtual void render(SDL_Renderer*);
private:
	bool patrollingLeft;
};