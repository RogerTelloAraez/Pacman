#include "State_MoveDown.h"
#include "GameEntity.h"
#include "MovableGameEntity.h"
#include "RenderModule.h"
#include "Texture.h"
#include "World.h"

State_MoveDown::State_MoveDown(GameEntity& gameEntity) : State("open_down_32.png", gameEntity)
{
}

State_MoveDown::~State_MoveDown()
{
}

void State_MoveDown::OnEnter()
{
	// This needs to sabe the image inside to not hardcode it if I have time
	Texture textureData = renderModule->LoadImage("open_down_32.png");
	subjectEntity->SetTexture(textureData.texture);
	subjectEntity->SetTextureSize(textureData.width, textureData.height);
}

void State_MoveDown::Update(float aTime, World* aWorld)
{
	// If I have time we should move this code to a parent state class State_Move
	int tileSize = 22;
	MovableGameEntity* movableSubjectEntity = (MovableGameEntity*)subjectEntity;

	Vector2f destination((float)movableSubjectEntity->GetNextTileX() * tileSize, (float)movableSubjectEntity->GetNextTileY() * tileSize);
	Vector2f direction = destination - movableSubjectEntity->GetPosition();

	float distanceToMove = aTime * 250.f;
	if (distanceToMove > direction.Length())
	{
		movableSubjectEntity->SetPosition(destination);
		movableSubjectEntity->SetNextTileAsCurrent();
	}
	else
	{
		direction.Normalize();
		Vector2f currentPos = movableSubjectEntity->GetPosition();
		movableSubjectEntity->SetPosition(currentPos + (direction * distanceToMove));
	}
}
