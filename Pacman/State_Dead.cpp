#include "State_Dead.h"

State_Dead::State_Dead(GameEntity& gameEntity) : State("ghost_32_red.png", gameEntity)
{
}

State_Dead::~State_Dead()
{
}

void State_Dead::OnEnter()
{
}

void State_Dead::Update(float aTime, World* aWorld)
{

}
