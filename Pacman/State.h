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
class State
{
public:
	State(const char* defaultImage, GameEntity& subjectEntity);
	~State();

	virtual void OnEnter();
	virtual void Update();

protected:
	GameEntity* subjectEntity;
};

extern RenderModule* renderModule;

