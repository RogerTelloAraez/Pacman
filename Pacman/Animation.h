#pragma once

#include <vector>

struct SDL_Texture;
class Animation
{
public:
	Animation();
	~Animation();

private:
	// For now we will just hold one sprite, but this will be changed to an array
	std::vector<SDL_Texture*> spriteList;
};

