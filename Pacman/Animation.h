#pragma once

#include <list>
#include <vector>

struct SDL_Texture;
class RenderModule;
class Animation
{
public:
	Animation(const float speed, std::vector<const char*> animationNames);
	~Animation();

	// ASK: This method should be moved to a factory
	// I don't think it's responsablity from the Animation class, but neither want to create a singleton "cajon de sastre"
	void FillSpriteListFromSpriteNames(std::vector<const char*> animationNames);
	SDL_Texture* GetCurrentFrame(const float aTime);
	int GetNextFrameIndex();

	void SetSpeed(const float newSpeed);
	float GetSpeed() const;

private:
	std::vector<SDL_Texture*>	spriteList;
	float						speed = 1.0f;
	float						timer = 0;
	int							currentFrame;
};

extern RenderModule* renderModule;

