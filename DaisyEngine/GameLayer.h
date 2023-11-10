#pragma once
#include "SDL2/include/SDL_events.h"
#include "SDL2/include/SDL_syswm.h"

class GameLayer
{
public:
	void Create() {};
	void Start() {};
	void Loop() {};
	void Draw() {};
	void Predraw() {};
	void EventPolled(SDL_Event e) {};
};