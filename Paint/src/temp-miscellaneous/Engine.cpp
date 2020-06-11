#include "Engine.h"
#include "Cleanup.h"
#include <iostream>

//#include "SDL.h"

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	int flags = 0;
	if (fullScreen) { flags = SDL_WINDOW_FULLSCREEN; }

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created successfully!" << std::endl;
		}
	}
}

void Engine::handleEvents()
{

}

void Engine::cleanup()
{
	
}
