#ifndef GHOST_H
#define GHOST_H

#include <list>
#include "MovableGameEntity.h"

class World;
class PathmapTile;
struct SDL_Texture;
struct SDL_Renderer;

enum GhostStateType
{
	ROAMING,
	VULNERABLE,
	DEAD
};

class Ghost : public MovableGameEntity
{
public:
	Ghost(const Vector2f& aPosition, SDL_Renderer* renderer);
	~Ghost(void);

	void InitStates() override;
	void Update(float aTime, World* aWorld);

	bool myIsClaimableFlag;
	bool myIsDeadFlag;

	void SetImage(const char* anImage);

	void Die(World* aWorld);

	void Draw(Drawer* aDrawer);

	void AddState(State* newState, GhostStateType stateType);
	void ChangeState(const GhostStateType newState);

	Vector2f GetDesiredMovement() const;
	void SetDesiredMovement(const Vector2f aDesiredMovement);

	std::list<PathmapTile*> GetPath() const;

private:
	std::map<GhostStateType, State*> stateList;

protected:

	int myDesiredMovementX;
	int myDesiredMovementY;

	Vector2f desiredMovement;

	std::list<PathmapTile*> myPath;
	SDL_Texture* deadTexture;
	SDL_Texture* vulnerableTexture;

};

#endif // GHOST_H