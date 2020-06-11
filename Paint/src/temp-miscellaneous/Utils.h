#pragma once

#include "SDL.h"
#include <iostream>


class Utils
{
public:
	void logSDLError(std::ostream& os, const std::string& msg);
	SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren);
};

