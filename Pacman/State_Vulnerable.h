#pragma once
#include "State.h"

class World;
class State_Vulnerable : public State
{
public:
	State_Vulnerable(GameEntity& gameEntity);
	~State_Vulnerable();

	void OnEnter() override;
	void Update(float aTime, World* aWorld);
};

