#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "Vector2f.h"
//#include "State.h"
#include <map>

class State;
class Drawer;
struct SDL_Renderer;
struct SDL_Texture;

class GameEntity
{
public:
	GameEntity(const Vector2f& aPosition, const char* anImage);
	~GameEntity(void);
	void Load(SDL_Renderer* renderer);
	Vector2f GetPosition() const { return myPosition; }
	void SetPosition(const Vector2f& aPosition) { myPosition = aPosition; }

	bool Intersect(GameEntity* aGameEntity);
	virtual void Draw(Drawer* aDrawer);

	void MarkForDelete() { myIdMarkedForDeleteFlag = true; }
	bool IsMarkedForDelete() const { return myIdMarkedForDeleteFlag; }

	virtual void InitStates();

	SDL_Texture* GetTexture();
	void SetTexture(SDL_Texture* newTexture);
	void SetTextureSize(const int width, const int height);

protected:
	State* currentState;

protected:
	bool myIdMarkedForDeleteFlag;
	Vector2f myPosition;
	const char* myImage;
	SDL_Texture* texture;
	int width;
	int height;
};

#endif // GAMEENTITY_H