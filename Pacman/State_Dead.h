#pragma once
#include "State.h"

class World;
class State_Dead : public State
{
public:
	State_Dead(GameEntity& gameEntity);
	~State_Dead();

	void OnEnter(World* aWorld) override;
	void Update(float aTime, World* aWorld);
};

