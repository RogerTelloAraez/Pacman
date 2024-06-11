#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_

#include "Observer.h"
#include "UIData.h"

class UIManager : Observer
{
public:
	UIManager();
	~UIManager();

	void SetFPS(const int newFPS);
	int GetFPS() const;
	void SetLives(const int newLives);
	int GetLives() const;
	void SetScore(const int newScore);
	int GetScore() const;

private:
	UIData uiData;
};

#endif // !_SCORE_MANAGER_H_