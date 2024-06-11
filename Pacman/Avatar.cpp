#include "Avatar.h"
#include "State.h"
#include "AvatarStates.h";

Avatar::Avatar(const Vector2f& aPosition)
	: MovableGameEntity(aPosition, "")
{

}

Avatar::~Avatar(void)
{
}

void Avatar::Update(float aTime)
{
	if (currentState)
	{
		currentState->Update(aTime, nullptr);
	}
}

void Avatar::InitStates()
{
	State_MoveDown* state_moveDown = new State_MoveDown(*this);
	AddState(state_moveDown, MOVING_DOWN);

	State_MoveLeft* state_moveLeft = new State_MoveLeft(*this);
	AddState(state_moveLeft, MOVING_LEFT);

	State_MoveUp* state_moveUp = new State_MoveUp(*this);
	AddState(state_moveUp, MOVING_UP);

	State_Move* state_moveRight = new State_Move(*this, "open_right_32.png", "closed_right_32.png");
	AddState(state_moveRight, MOVING_RIGHT);

	ChangeState(MOVING_LEFT);
}

void Avatar::AddState(State* newState, AvatarStateType stateType)
{
	stateList.insert(std::pair<AvatarStateType, State*>(stateType, newState));
}

void Avatar::ChangeState(const AvatarStateType newState)
{
	currentState = stateList[newState];
	currentState->OnEnter(nullptr);
}
