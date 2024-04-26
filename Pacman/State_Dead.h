#pragma once
#include "State.h"

class World;
class State_Dead : public State
{
public:
	State_Dead(GameEntity& gameEntity);
	~State_Dead();

	void OnEnter() override;
	void Update(float aTime, World* aWorld);
};

