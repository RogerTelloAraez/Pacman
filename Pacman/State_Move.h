#pragma once
#include "State.h"

class World;
class State_Move : public State
{
public:
	State_Move(GameEntity& gameEntity, const char* directionOpen, const char* directionClose);
	~State_Move();

	void OnEnter(World* aWorld) override;
	void Update(float aTime, World* aWorld) override;

private:
	Animation* animation;
};

