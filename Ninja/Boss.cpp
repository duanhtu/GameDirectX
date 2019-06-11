#include "Boss.h"
#include "Player.h"

Boss::Boss()
{
	
	setDirection(TEXTURE_DIRECTION_LEFT);
	hasChangedDirectionRight = false;
	hasChangedDirectionLeft = false;
	setRenderActive(true);
}

void Boss::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void Boss::onUpdate(float dt)
{
	/*
	int end = getInitBox()->getX() - 16;
	int begin = getInitBox()->getX() - 128;
	if (getX() <= begin &&  !hasChangedDirectionRight) 
	{
			
		setDirection(TEXTURE_DIRECTION_RIGHT);
		setX(begin - 32);
		hasChangedDirectionRight = true;
		hasChangedDirectionLeft = false;
		setVy(100);
		setAnimation(BOSS_ACTION_SIT);
	}
	else if (getX() >= end &&  !hasChangedDirectionLeft)
	{
		setDirection(TEXTURE_DIRECTION_LEFT);
		setX(begin - 32);
		hasChangedDirectionLeft = true;
		hasChangedDirectionRight = false;
		setVy(100);
		setAnimation(BOSS_ACTION_SIT);
	}
	else
	{
		setAnimation(BOSS_ACTION_JUM);
	}
	setVx(GLOBALS_D("samurai_vx")*getDirection());
	PhysicsObject::onUpdate(dt);
	*/
}


Boss::~Boss()
{
}