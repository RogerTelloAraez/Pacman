#include "State.h"

State::State(SDL_Texture* sprite, void(*movementCallback)()) : 
	sprite(sprite), 
	movementCallback(movementCallback)
{
}

State::~State()
{
}
