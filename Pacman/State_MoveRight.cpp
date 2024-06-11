#include "State_MoveRight.h"
#include "GameEntity.h"
#include "MovableGameEntity.h"
#include "RenderModule.h"
#include "Texture.h"
#include "World.h"

State_MoveRight::State_MoveRight(GameEntity& gameEntity) : State("open_32.png", gameEntity)
{
	animation = new Animation(.25f, { "open_right_32.png", "closed_right_32.png" });
}

State_MoveRight::~State_MoveRight()
{
	delete animation;
}

void State_MoveRight::OnEnter(World* aWorld)
{
	Texture textureData = renderModule->LoadImage("open_32.png");
	subjectEntity->SetTexture(textureData.texture);
	subjectEntity->SetTextureSize(textureData.width, textureData.height);
}

void State_MoveRight::Update(float aTime, World* aWorld)
{
	SDL_Texture* currentTexture = animation->GetCurrentFrame(aTime);
	subjectEntity->SetTexture(currentTexture);

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
