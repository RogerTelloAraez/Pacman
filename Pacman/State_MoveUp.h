#pragma once
#include "State.h"

class World;
class State_MoveUp : public State
{
public:
	State_MoveUp(GameEntity& gameEntity);
	~State_MoveUp();

	void OnEnter(World* aWorld) override;
	void Update(float aTime, World* aWorld) override;

private:
	Animation* animation;
};

