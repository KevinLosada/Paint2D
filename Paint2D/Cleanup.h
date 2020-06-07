#pragma once

#include <utility>
#include <SDL.h>

class Cleanup
{
	template<typename T, typename... Args>
	void cleanup(T *t, Args&&)
};

