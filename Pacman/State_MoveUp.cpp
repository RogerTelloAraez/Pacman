#include "State_MoveUp.h"
#include "GameEntity.h"
#include "MovableGameEntity.h"
#include "RenderModule.h"
#include "Texture.h"

State_MoveUp::State_MoveUp(GameEntity& gameEntity) : State("open_up_32.png", gameEntity)
{

}

State_MoveUp::~State_MoveUp()
{
}

void State_MoveUp::OnEnter()
{
	Texture textureData = renderModule->LoadImage("open_up_32.png");
	subjectEntity->SetTexture(textureData.texture);
	subjectEntity->SetTextureSize(textureData.width, textureData.height);
}

void State_MoveUp::Update(float aTime, World* aWorld)
{
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
