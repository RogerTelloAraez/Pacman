#pragma once

#include "Animation.h"
#include "RenderModule.h"

class GameEntity;
class State
{
public:
	State(const char* defaultImage, GameEntity& subjectEntity);
	~State();

	virtual void Update();

private:
	GameEntity* subjectEntity;
};

extern RenderModule* renderModule; 

