#ifndef PACMAN_H
#define PACMAN_H

#include "Vector2f.h"

struct SDL_Surface;
class Drawer;
class Avatar;
class World;
class Ghost;

class Pacman
{
public:
	static Pacman* Create(Drawer* aDrawer);
	~Pacman(void);

	bool Update(float aTime);
	bool Draw();

	void UpdateGameEntities(float aTime);

	void UpdateAvatar(float aTime);
	void UpdateGhosts(float aTime);

	void CreateAvatar();
	void CreateGhosts();

private:
	Pacman(Drawer* aDrawer);
	bool Init();
	bool UpdateInput();
	void MoveAvatar();
	bool CheckEndGameCondition();

	// This could be added into a struct
	Drawer* myDrawer;
	Avatar* myAvatar;
	Ghost* myGhost;
	World* myWorld;

	float		myTimeToNextUpdate;
	float		myGhostGhostCounter;

	int			myLives;
	int			myScore;
	int			myFps;

	Vector2f	myNextMovement;
};

#endif // PACMAN_H