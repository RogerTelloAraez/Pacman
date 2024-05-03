#include "Ghost.h"
#include "World.h"
#include "PathmapTile.h"
#include "GhostStates.h"
#include "Drawer.h"
#include "State.h"
#include <SDL_image.h>

Ghost::Ghost(const Vector2f& aPosition, SDL_Renderer* renderer)
: MovableGameEntity(aPosition, "ghost_32_red.png")
{
	myIsClaimableFlag = false;
	myIsDeadFlag = false;

	myDesiredMovementX = 0;
	myDesiredMovementY = -1;
	desiredMovement.myX = 0;
	desiredMovement.myY = -1;
	SDL_Surface* deadSurface = IMG_Load("Ghost_Dead_32.png");
	deadTexture = SDL_CreateTextureFromSurface(renderer, deadSurface);
	SDL_Surface* vulnerableSurface = IMG_Load("Ghost_Vulnerable_32.png");
	vulnerableTexture = SDL_CreateTextureFromSurface(renderer, vulnerableSurface);
}

Ghost::~Ghost(void)
{
}

void Ghost::Die(World* aWorld)
{
	myPath.clear();
	aWorld->GetPath(myCurrentTileX, myCurrentTileY, 13, 13, myPath);
}

void Ghost::InitStates()
{
	State_Roaming* state_roaming = new State_Roaming(*this);
	AddState(state_roaming, ROAMING);

	State_Vulnerable* state_vulnerable = new State_Vulnerable(*this);
	AddState(state_vulnerable, VULNERABLE);

	State_Dead* state_dead = new State_Dead(*this);
	AddState(state_dead, DEAD);

	ChangeState(ROAMING);
}

void Ghost::Update(float aTime, World* aWorld)
{
	if (currentState)
	{
		currentState->Update(aTime, aWorld);
	}
}

void Ghost::SetImage(const char* anImage)
{
	myImage = anImage;
}

void Ghost::Draw(Drawer* aDrawer)
{
	if (myIsDeadFlag)
		aDrawer->Draw(deadTexture, width, height, (int)myPosition.myX + 220, (int)myPosition.myY + 60);
	else if (myIsClaimableFlag)
		aDrawer->Draw(vulnerableTexture, width, height, (int)myPosition.myX + 220, (int)myPosition.myY + 60);
	else
		aDrawer->Draw(texture, width, height, (int)myPosition.myX + 220, (int)myPosition.myY + 60);
}

void Ghost::AddState(State* newState, GhostStateType stateType)
{
	stateList.insert(std::pair<GhostStateType, State*>(stateType, newState));
}

void Ghost::ChangeState(const GhostStateType newState, World* aWorld )
{
	currentState = stateList[newState];
	currentState->OnEnter(aWorld);
}

Vector2f Ghost::GetDesiredMovement() const
{
	return desiredMovement;
}

void Ghost::SetDesiredMovement(const Vector2f aDesiredMovement)
{
	desiredMovement = aDesiredMovement;
}

