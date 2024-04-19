#ifndef AVATAR_H
#define AVATAR_H

#include "MovableGameEntity.h"
#include "Vector2f.h"

enum AvatarStateType
{
	MOVING_UP,
	MOVING_DOWN,
	MOVING_LEFT,
	MOVING_RIGHT,
};

class Avatar : public MovableGameEntity
{
public:
	Avatar(const Vector2f& aPosition);
	~Avatar(void);

	void Update(float aTime);
	void InitStates() override;

	void AddState(State* newState, AvatarStateType stateType);
	void ChangeState(const AvatarStateType newState);

private:
	std::map<AvatarStateType, State*> stateList;

};

#endif //AVATAR_H