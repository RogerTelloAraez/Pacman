#pragma once

#include "Animation.h"

class State
{
public:
	State(SDL_Texture* sprite, void (*movementCallback)());
	~State();

private:
	SDL_Texture* sprite;
	void (*movementCallback)();
};

