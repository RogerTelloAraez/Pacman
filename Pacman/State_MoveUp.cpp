#include "State_MoveUp.h"
#include "GameEntity.h"
#include "RenderModule.h"
#include "Texture.h"

State_MoveUp::State_MoveUp( GameEntity& gameEntity ) : State("open_up_32.png", gameEntity)
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

void State_MoveUp::Update()
{

}
