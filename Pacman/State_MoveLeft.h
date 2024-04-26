#pragma once
#include "State.h"

class World;
class State_MoveLeft : public State
{
public:
	State_MoveLeft(GameEntity& gameEntity);
	~State_MoveLeft();

	void OnEnter() override;
	void Update(float aTime, World* aWorld) override;
};

