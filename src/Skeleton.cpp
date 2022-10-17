#include "Skeleton.h"

void Skeleton::update()
{
	if (patrollingLeft)
	{
		setX(x() - 1);
		if (x() == 0) patrollingLeft = false;
	}
	else
	{
		setX(x() + 1);
		if (x() == 100) patrollingLeft = true;
	}
}

void Skeleton::render(SDL_Renderer* renderer)
{
	SDL_Rect spawn = { x(), y(),64,64 };
	SDL_RenderFillRect(renderer, &spawn);
}