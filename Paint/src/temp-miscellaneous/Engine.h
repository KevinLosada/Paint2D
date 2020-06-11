#pragma once

#include "SDL.h"

class Engine
{
public:
	Engine();
	~Engine();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);

	void handleEvents();
	void update();
	void render();
	void cleanup();

	bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

