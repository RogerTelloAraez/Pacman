#include "State_MoveRight.h"
#include "GameEntity.h"
#include "RenderModule.h"
#include "Texture.h"

State_MoveRight::State_MoveRight(GameEntity& gameEntity) : State("open_32.png", gameEntity)
{
}

State_MoveRight::~State_MoveRight()
{
}

void State_MoveRight::OnEnter()
{
	Texture textureData = renderModule->LoadImage("open_32.png");
	subjectEntity->SetTexture(textureData.texture);
	subjectEntity->SetTextureSize(textureData.width, textureData.height);
}

void State_MoveRight::Update()
{
}
