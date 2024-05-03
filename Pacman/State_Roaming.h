#pragma once
#include "State.h"

class World;
class State_Roaming : public State
{
public:
	State_Roaming(GameEntity& gameEntity);
	~State_Roaming();

	void OnEnter(World* aWorld) override;
	void Update(float aTime, World* aWorld);
};

