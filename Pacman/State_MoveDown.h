#pragma once
#include "State.h"

class World;
class State_MoveDown : public State
{
public:
	State_MoveDown(GameEntity& gameEntity);
	~State_MoveDown();

	void OnEnter() override;
	void Update(float aTime, World* aWorld) override;
};

