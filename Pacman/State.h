#pragma once

#include "Animation.h"
#include "RenderModule.h"

enum StateId {
	STATE_MOVE_UP,
	STATE_MOVE_DOWN,
	STATE_MOVE_LEFT,
	STATE_MOVE_RIGHT,
};

class GameEntity;
class World;
class State
{
public:
	State(const char* defaultImage, GameEntity& subjectEntity);
	~State();

	virtual void OnEnter();
	virtual void Update(float aTime, World* aWorld); // This aWorld, when state inheritance is done, it should only be existing for movement states

protected:
	GameEntity* subjectEntity;
};

extern RenderModule* renderModule;

