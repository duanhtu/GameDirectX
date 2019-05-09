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
		setVx(0);
		setDx(0);
		setAnimation(SAMURAI_ACTION_STAND);
		if (getMidX() - Player::getInstance()->getMidX() <= GLOBALS_D("samurai_distance_to_activ"))
		{
			setSamuraiState(SAMURAI_STATE_VISIBLE);
		}
		break;
	case SAMURAI_STATE_VISIBLE:
		int direction = getDirection();
		setVx(GLOBALS_D("samurai_vx")*-1);
		setAnimation(SAMURAI_ACTION_WALK);
		break;
	}
	PhysicsObject::onUpdate(dt);
}

void Samurai::setSamuraiState(SAMURAI_STATE samuraiState)
{
	this->samuraiState = samuraiState;
}

Samurai::~Samurai()
{
}
