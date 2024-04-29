#include "State_Dead.h"
#include "Ghost.h"
#include "Texture.h"
#include "PathmapTile.h"

State_Dead::State_Dead(GameEntity& gameEntity) : State("Ghost_Dead_32.png", gameEntity)
{
}

State_Dead::~State_Dead()
{
}

void State_Dead::OnEnter()
{
	Ghost* subjectGhost = (Ghost*)subjectEntity;
	subjectGhost->myIsDeadFlag = true;

	Texture textureData = renderModule->LoadImage("Ghost_Dead_32.png"); // Try to use same image is loaded above
	subjectEntity->SetTexture(textureData.texture);
	subjectEntity->SetTextureSize(textureData.width, textureData.height);
}

void State_Dead::Update(float aTime, World* aWorld)
{
	Ghost* subjectGhost = (Ghost*)subjectEntity;
	if (subjectGhost->IsAtDestination())
	{
		if (!subjectGhost->GetPath().empty())
		{
			PathmapTile* nextTile = subjectGhost->GetPath().front();
			subjectGhost->GetPath().pop_front();
			subjectGhost->SetNextTile(nextTile->myX, nextTile->myY);
		}
	}

	int tileSize = 22;
	Vector2f destination((float)subjectGhost->GetNextTileX() * tileSize, (float)subjectGhost->GetNextTileY() * tileSize);
	Vector2f direction = destination - subjectGhost->GetPosition();

	float distanceToMove = aTime * 30;
	if (distanceToMove > direction.Length())
	{
		subjectGhost->SetPosition(destination);
		subjectGhost->SetNextTileAsCurrent();
	}
	else
	{
		direction.Normalize();
		Vector2f currentPos = subjectGhost->GetPosition();
		subjectGhost->SetPosition(currentPos + (direction * distanceToMove));
	}

	subjectGhost->myIsDeadFlag = false;

}
