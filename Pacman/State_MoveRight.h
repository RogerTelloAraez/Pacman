#pragma once
#include "State.h"

class State_MoveRight : public State
{
public:
	State_MoveRight(GameEntity& gameEntity);
	~State_MoveRight();

	void OnEnter() override;
	void Update() override;
};

