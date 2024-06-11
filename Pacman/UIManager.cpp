#include "UIManager.h"

UIManager::UIManager() : Observer()
{

}

UIManager::~UIManager() // Here we need to call the destructor for the observer parent
{

}

void UIManager::SetFPS(const int newFPS)
{
	uiData.fps = newFPS;
}

int UIManager::GetFPS() const
{
	return uiData.fps;
}

void UIManager::SetLives(const int aLives)
{
	uiData.lives = aLives;
}

int UIManager::GetLives() const
{
	return uiData.lives;
}

void UIManager::SetScore(const int aScore)
{
	uiData.score = aScore;
}

int UIManager::GetScore() const
{
	return  uiData.score;
}
