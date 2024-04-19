#include "GameEntity.h"
#include "Drawer.h"
#include <SDL_image.h>

GameEntity::GameEntity(const Vector2f& aPosition, const char* anImage)
	:myPosition(aPosition)
	, myImage(anImage)
	, myIdMarkedForDeleteFlag(false)
	, width(0)
	, height(0)
	, texture(nullptr)
{
}

GameEntity::~GameEntity(void)
{
}

void GameEntity::Load(SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(myImage);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	width = surface->w;
	height = surface->h;
}

bool GameEntity::Intersect(GameEntity* aGameEntity)
{
	return false;
}

void GameEntity::Draw(Drawer* aDrawer)
{
	aDrawer->Draw(texture, width, height, (int)myPosition.myX + 220, (int)myPosition.myY + 60);
}

void GameEntity::InitStates()
{

}

SDL_Texture* GameEntity::GetTexture()
{
	return texture;
}

void GameEntity::SetTexture(SDL_Texture* newTexture)
{
	texture = newTexture;
	//width = 
}

void GameEntity::SetTextureSize(const int aWidth, const int aHeight)
{
	width = aWidth;
	height = aHeight;
}

