#pragma once
#include "State.h"

class State_MoveUp : public State
{
public:
	State_MoveUp(GameEntity& gameEntity);
	~State_MoveUp();
	void Update() override;
};

