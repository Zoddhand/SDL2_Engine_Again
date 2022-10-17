//Using SDL and standard IO
#include "Engine.h"
#include "Skeleton.h"
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// Game Frames per Second in MS
#define FPS 60000

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Init_ Init(SCREEN_HEIGHT, SCREEN_WIDTH);
int numOfEntities = 0;

int main(int argc, char* args[])
{
	/* Creates of vector of Entity objects */
	std::vector<std::unique_ptr<Entity>> Entities;
	for (auto i = 0; i < 5; ++i) {
		Entities.push_back(std::make_unique<Skeleton>(32, 32));
	}

	double previous = SDL_GetTicks();
	double lag = 0.0;
	bool gameIsRunning = true;
	while (gameIsRunning)
	{
		double current = SDL_GetTicks();
		double elapsed = current = previous;
		previous = current;
		lag += elapsed;
		//processinput
		while (lag >= FPS)
		{
			std::cout << Entities.size();
			for (int i = 0; i < Entities.size(); i++)
			{
				Entities[i]->update();
			}
			lag -= FPS;
		}
		//render
		SDL_SetRenderDrawColor(Init.renderer, 0, 0, 0, 255);
		SDL_RenderClear(Init.renderer);
		SDL_SetRenderDrawColor(Init.renderer, 255, 0, 0, 255);
		for (int i = 0; i < Entities.size(); i++)
		{
			Entities[i]->render(Init.renderer);
		}
		SDL_RenderPresent(Init.renderer);
	}

	delete& Init;

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}


