#pragma once
#include "State.h"

class World;
class State_MoveRight : public State
{
public:
	State_MoveRight(GameEntity& gameEntity);
	~State_MoveRight();

	void OnEnter(World* aWorld) override;
	void Update(float aTime, World* aWorld) override;

private:
	Animation* animation;
};

