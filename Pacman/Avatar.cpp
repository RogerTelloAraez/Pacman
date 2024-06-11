#include "Avatar.h"
#include "State.h"
#include "State_Move.h";

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
	State_Move* state_moveDown = new State_Move(*this, "open_down_32.png", "closed_down_32.png");
	AddState(state_moveDown, MOVING_DOWN);

	State_Move* state_moveLeft = new State_Move(*this, "open_left_32.png", "closed_left_32.png");
	AddState(state_moveLeft, MOVING_LEFT);

	State_Move* state_moveUp = new State_Move(*this, "open_up_32.png", "closed_up_32.png");
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
