#include "Engine.h"

SDL_Init_::SDL_Init_(int SCREEN_HEIGHT, int SCREEN_WIDTH)
{
	//Initialize SDL
	if ((SDL_INIT_VIDEO) == NULL)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 0, 255));

			//Update the surface
			SDL_UpdateWindowSurface(window);
		}
	}

	if (renderer == NULL)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}
	else printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
}

SDL_Init_::~SDL_Init_()
{
	//Destroy window
	SDL_DestroyWindow(window);

	std::cout << "\nInit Destructor Called.";
}
