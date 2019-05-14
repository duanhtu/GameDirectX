#include "Samurai.h"
#include"Player.h"

Samurai::Samurai()
{
	setSamuraiState(SAMURAI_STATE_INVISIBLE);
	//setDirection(TEXTURE_DIRECTION_LEFT);
}

void Samurai::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void Samurai::onUpdate(float dt)
{
	switch (samuraiState)
	{
	case SAMURAI_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (getMidX() - Player::getInstance()->getMidX() <= GLOBALS_D("samurai_distance_to_activ"))
		{
			setSamuraiState(SAMURAI_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case SAMURAI_STATE_VISIBLE:
		if (Samurai::isOnBridge)
		{
			int end = getInitBox()->getX() - 16;
			int begin = getInitBox()->getX() - Samurai::distanceChangeDirection ;
			if (getX() <= begin)
			{
				setDirection(TEXTURE_DIRECTION_RIGHT);
				setVx(GLOBALS_D("samurai_vx")*1);
			}
			if (getX() >= end)
			{
				setDirection(TEXTURE_DIRECTION_LEFT);
				setVx(GLOBALS_D("samurai_vx")*-1);
			}
			setAnimation(SAMURAI_ACTION_WALK);
		}
		else
		{
			setDirection(TEXTURE_DIRECTION_LEFT);
			setVx(GLOBALS_D("samurai_vx")*-1);
			setAnimation(SAMURAI_ACTION_WALK);
		}
		break;
	}
	PhysicsObject::onUpdate(dt);
}

void Samurai::onInit(ifstream& fs)
{
	int onBridge;
	fs >> onBridge;
	if (onBridge) {
		Samurai::isOnBridge = true;
		fs >> Samurai::distanceChangeDirection;
	}
	else {
		Samurai::isOnBridge = false;
	}
	//setDirection((TEXTTURE_DIRECTION)direction);
}

void Samurai::setSamuraiState(SAMURAI_STATE samuraiState)
{
	this->samuraiState = samuraiState;
}

Samurai::~Samurai()
{
}
