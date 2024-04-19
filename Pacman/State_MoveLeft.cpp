#include "State_MoveLeft.h"
#include "GameEntity.h"
#include "RenderModule.h"
#include "Texture.h"

State_MoveLeft::State_MoveLeft(GameEntity& gameEntity) : State("open_left_32.png", gameEntity)
{
}

State_MoveLeft::~State_MoveLeft()
{
}

void State_MoveLeft::OnEnter()
{
	Texture textureData = renderModule->LoadImage("open_left_32.png");
	subjectEntity->SetTexture(textureData.texture);
	subjectEntity->SetTextureSize(textureData.width, textureData.height);
}

void State_MoveLeft::Update()
{
}
