#include "Avatar.h"
#include "State.h"
#include "MovementStates.h";

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
		currentState->Update();
	}

	int tileSize = 22;

	Vector2f destination((float)myNextTileX * tileSize, (float)myNextTileY * tileSize);
	Vector2f direction = destination - myPosition;

	float distanceToMove = aTime * 250.f;

	if (distanceToMove > direction.Length())
	{
		myPosition = destination;
		myCurrentTileX = myNextTileX;
		myCurrentTileY = myNextTileY;
	}
	else
	{
		direction.Normalize();
		myPosition += direction * distanceToMove;
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

	State_MoveRight* state_moveRight = new State_MoveRight(*this);
	AddState(state_moveRight, MOVING_RIGHT);

	ChangeState(MOVING_UP);
}

void Avatar::AddState(State* newState, AvatarStateType stateType)
{
	stateList.insert(std::pair<AvatarStateType, State*>(stateType, newState));
}

void Avatar::ChangeState(const AvatarStateType newState)
{
	currentState = stateList[newState];
	currentState->OnEnter();
}
