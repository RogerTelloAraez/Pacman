#include "State_Roaming.h"
#include "Ghost.h"
#include "World.h"

State_Roaming::State_Roaming(GameEntity& gameEntity) : State("ghost_32_red.png", gameEntity)
{
}

State_Roaming::~State_Roaming()
{
}

void State_Roaming::OnEnter()
{
}

void State_Roaming::Update(float aTime, World* aWorld)
{
	Ghost* subjectGhost = (Ghost*)subjectEntity;
	int nextTileX = subjectGhost->GetCurrentTileX() + subjectGhost->GetDesiredMovement().myX;
	int nextTileY = subjectGhost->GetCurrentTileY() + subjectGhost->GetDesiredMovement().myY;

	if (aWorld->TileIsValid(nextTileX, nextTileY))
	{
		subjectGhost->SetNextTile(nextTileX, nextTileY);
	}
	else if (subjectGhost->GetDesiredMovement().myX == 1)
	{
		subjectGhost->SetDesiredMovement({ 0,1 });
	}
	else if (subjectGhost->GetDesiredMovement().myY == 1)
	{
		subjectGhost->SetDesiredMovement({ -1,0 });
	}
	else if (subjectGhost->GetDesiredMovement().myX == -1)
	{
		subjectGhost->SetDesiredMovement({ 0,-1 });
	}
	else
	{
		subjectGhost->SetDesiredMovement({ 1,0 });
	}

	// General Part this needs inheritance
	//int tileSize = 22;
	//MovableGameEntity* movableSubjectEntity = (MovableGameEntity*)subjectEntity;

	//Vector2f destination((float)movableSubjectEntity->GetNextTileX() * tileSize, (float)movableSubjectEntity->GetNextTileY() * tileSize);
	//Vector2f direction = destination - movableSubjectEntity->GetPosition();

	//float distanceToMove = aTime * 250.f;
	//if (distanceToMove > direction.Length())
	//{
	//	movableSubjectEntity->SetPosition(destination);
	//	movableSubjectEntity->SetNextTileAsCurrent();
	//}
	//else
	//{
	//	direction.Normalize();
	//	Vector2f currentPos = movableSubjectEntity->GetPosition();
	//	movableSubjectEntity->SetPosition(currentPos + (direction * distanceToMove));
	//}

	//subjectGhost->myIsDeadFlag = false;
}
