#pragma once
#include "State.h"

class State_MoveLeft : public State
{
public:
	State_MoveLeft(GameEntity& gameEntity);
	~State_MoveLeft();

	void OnEnter() override;
	void Update() override;
};

