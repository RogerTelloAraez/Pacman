#include "State.h"
#include "GameEntity.h"
#include "Texture.h"

State::State(const char* defaultImageName, GameEntity& _subjectEntity)
{	
	subjectEntity = &_subjectEntity;
	Texture textureData = renderModule->LoadImage(defaultImageName);
	subjectEntity->SetTexture(textureData.texture);
	subjectEntity->SetTextureSize(textureData.width, textureData.height);
}

State::~State()
{
}

void State::OnEnter()
{
}

void State::Update()
{
}
