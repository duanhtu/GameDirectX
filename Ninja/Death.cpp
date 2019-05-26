#include "Death.h"
#include"Player.h"
#include "DeathWeapon.h"

Death::Death()
{
	setDeathState(DEATH_STATE_RUN);
	setDirection(TEXTURE_DIRECTION_LEFT);
	setRenderActive(true);
	runDelay.init(GLOBALS_D("death_time_run"));
	fireDelay.init(GLOBALS_D("death_time_fire"));
	runDelay.start();
	vDirection = -1;
}

void Death::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void Death::onUpdate(float dt)
{
	runDelay.update();
	fireDelay.update();
	switch (deathState)
	{
	case DEATH_STATE_RUN:
		if (getDx() < 0 && ((getMidX() - getInitBox()->getMidX()) < -10))
		{
			vDirection = 1;
		}

		if (getDx() > 0 && ((getMidX() - getInitBox()->getMidX()) > 10))
		{
			vDirection = -1;
		}

		if (runDelay.isTerminated())
		{
			DeathWeapon* weapon = new DeathWeapon();
			weapon->setVx(getDirection()* GLOBALS_D("death_weapon_vx"));
			weapon->setVy(GLOBALS_D("death_weapon_vy"));
			weapon->setX(getX() - 16);
			weapon->setY(getY());
			weapon->setRenderActive(true);
			setDeathState(DEATH_STATE_FIRE);
			fireDelay.start();
		}
		setVx(GLOBALS_D("death_vx") * vDirection);
		break;
	case DEATH_STATE_FIRE:
		setVx(0);
		if (fireDelay.isTerminated())
		{
			setDeathState(DEATH_STATE_RUN);
			runDelay.start();
		}
		break;
	default:
		break;
	}
	PhysicsObject::onUpdate(dt);
}

void Death::setDeathState(DEATH_STATE deathState)
{
	this->deathState = deathState;
}

Death::~Death()
{
}
