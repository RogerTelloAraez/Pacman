#ifndef GHOST_H
#define GHOST_H

#include <list>
#include "MovableGameEntity.h"

class World;
class PathmapTile;
struct SDL_Texture;
struct SDL_Renderer;

class Ghost : public MovableGameEntity
{
public:
	Ghost(const Vector2f& aPosition, SDL_Renderer* renderer);
	~Ghost(void);

	void Update(float aTime, World* aWorld);

	bool myIsClaimableFlag;
	bool myIsDeadFlag;

	void SetImage(const char* anImage);

	void Die(World* aWorld);

	void Draw(Drawer* aDrawer);

protected:

	int myDesiredMovementX;
	int myDesiredMovementY;

	std::list<PathmapTile*> myPath;
	SDL_Texture* deadTexture;
	SDL_Texture* vulnerableTexture;

};

#endif // GHOST_H