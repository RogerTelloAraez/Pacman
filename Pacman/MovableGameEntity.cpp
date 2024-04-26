#include "MovableGameEntity.h"

MovableGameEntity::MovableGameEntity(const Vector2f& aPosition, const char* anImage)
	: GameEntity(aPosition, anImage)
{
	myCurrentTileX = myNextTileX = (int)myPosition.myX / 22;
	myCurrentTileY = myNextTileY = (int)myPosition.myY / 22;
}

MovableGameEntity::~MovableGameEntity(void)
{
}

bool MovableGameEntity::IsAtDestination()
{
	if (myCurrentTileX == myNextTileX && myCurrentTileY == myNextTileY)
	{
		return true;
	}

	return false;
}

void MovableGameEntity::SetNextTile(int anX, int anY)
{
	myNextTileX = anX;
	myNextTileY = anY;
}

int MovableGameEntity::GetNextTileX() const
{
	return myNextTileX;
}

int MovableGameEntity::GetNextTileY() const
{
	return myNextTileY;
}

void MovableGameEntity::SetCurrentTile(const int anX, const int anY)
{
	myCurrentTileX = anX;
	myCurrentTileY = anY;
}

bool MovableGameEntity::SetNextTileAsCurrent()
{
	bool hasChanges = myCurrentTileX != myNextTileX || myCurrentTileY != myNextTileY;
	myCurrentTileX = myNextTileX;
	myCurrentTileY = myNextTileY;
	return hasChanges;
}
