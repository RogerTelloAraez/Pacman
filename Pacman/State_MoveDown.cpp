#include "State_MoveDown.h"
#include "GameEntity.h"
#include "RenderModule.h"
#include "Texture.h"

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

void State_MoveDown::Update()
{
	// Update Movement
}
