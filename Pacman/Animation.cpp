#include "Animation.h"
#include "Texture.h"
#include "RenderModule.h"
#include <SDL_image.h>

Animation::Animation(const float aSpeed, std::vector<const char*> animationNames)
{
	timer = 0;
	speed = aSpeed;
	FillSpriteListFromSpriteNames(animationNames);
}

Animation::~Animation()
{
}

void Animation::FillSpriteListFromSpriteNames(std::vector<const char*> animationNames)
{
	for (int i = 0; i <= animationNames.size() - 1; i++) 
	{
		SDL_Texture* newTexture = renderModule->LoadImage(animationNames[i]).texture;
		spriteList.push_back(newTexture);
	}
}

int Animation::GetNextFrameIndex()
{
	if (currentFrame >= spriteList.size() - 1)
	{
		return 0;
	}
	else
	{
		return currentFrame + 1;
	}
}

SDL_Texture* Animation::GetCurrentFrame(const float aTime)
{
	timer += aTime;
	if (timer >= speed)
	{
		currentFrame = GetNextFrameIndex();
		timer = 0;
	}
	return spriteList[currentFrame];
}

void Animation::SetSpeed(const float newSpeed)
{
	speed = newSpeed;
}

float Animation::GetSpeed() const
{
	return 0.0f;
}
