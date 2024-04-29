#include "State_Vulnerable.h"
#include "Ghost.h"
#include "Texture.h"
#include "World.h"

State_Vulnerable::State_Vulnerable(GameEntity& gameEntity) : State("Ghost_Vulnerable_32.png", gameEntity)
{
}

State_Vulnerable::~State_Vulnerable()
{
}

void State_Vulnerable::OnEnter()
{
	Texture textureData = renderModule->LoadImage("Ghost_Vulnerable_32.png"); // Try to use same image is loaded above
	subjectEntity->SetTexture(textureData.texture);
	subjectEntity->SetTextureSize(textureData.width, textureData.height);
}

void State_Vulnerable::Update(float aTime, World* aWorld)
{
	Ghost* subjectGhost = (Ghost*)subjectEntity;
	if (subjectGhost->IsAtDestination())
	{
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

	}
	int tileSize = 22;
	Vector2f destination((float)subjectGhost->GetNextTileX() * tileSize, (float)subjectGhost->GetNextTileY() * tileSize);
	Vector2f direction = destination - subjectGhost->GetPosition();

	float distanceToMove = aTime * 30.0f;
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
}
