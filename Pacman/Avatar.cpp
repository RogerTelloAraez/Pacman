#include "Avatar.h"
#include "State.h"
#include "State_MoveUp.h"

Avatar::Avatar(const Vector2f& aPosition)
	: MovableGameEntity(aPosition, "open_32.png")
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

	float distanceToMove = aTime * 30.f;

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
	State_MoveUp* state_moveUp = new State_MoveUp(*this);
	currentState = state_moveUp;
}
