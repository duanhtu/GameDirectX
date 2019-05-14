#include "Death.h"
#include"Player.h"

Death::Death()
{
	setDeathState(DEATH_STATE_INVISIBLE);
	setDirection(TEXTURE_DIRECTION_LEFT);
}

void Death::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void Death::onUpdate(float dt)
{
	switch (deathState)
	{
	case DEATH_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (getMidX() - Player::getInstance()->getMidX() <= GLOBALS_D("death_distance_to_activ"))
		{
			setDeathState(DEATH_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case DEATH_STATE_VISIBLE:
		int end = getInitBox()->getX() + 32 ;
		int begin = getInitBox()->getX() - 32;
		if (getX() <= begin)
		{
			//setDirection(TEXTURE_DIRECTION_RIGHT);
			setVx(GLOBALS_D("death_vx") * 1);
		}
		if (getX() >= end)
		{
			//setDirection(TEXTURE_DIRECTION_LEFT);
			setVx(GLOBALS_D("death_vx")*-1);
		}
		setAnimation(DEATH_ACTION_WALK);
		break;
	}
	PhysicsObject::onUpdate(dt);
}

void Death::onInit(ifstream& fs)
{
	fs >> Death::distanceChangeDirection;
}

void Death::setDeathState(DEATH_STATE deathState)
{
	this->deathState = deathState;
}

Death::~Death()
{
}
