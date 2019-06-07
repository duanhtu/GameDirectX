#include "Solicol.h"
#include"Player.h"
#include "SolicolBullet.h"

Solicol::Solicol()
{
	setSolicolState(SOLICOL_STATE_INVISIBLE);
	setDirection(TEXTURE_DIRECTION_LEFT);
	fireTime.init(GLOBALS_D("solicol_fire_time"));
	runDelay.init(GLOBALS_D("solicol_run_delay"));
	fireDelay.init(GLOBALS_D("solicol_fire_delay"));
	runDelay.start();
}

void Solicol::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void Solicol::onUpdate(float dt)
{
	runDelay.update();
	fireDelay.update();

	switch (solicolState)
	{
	case SOLICOL_STATE_INVISIBLE:
		setRenderActive(false);
		if (getMidX() - Player::getInstance()->getMidX() <= GLOBALS_D("solicol_distance_to_activ"))
		{
			setSolicolState(SOLICOL_STATE_RUN);
			setRenderActive(true);
			runDelay.start();
		}
		break;
	case SOLICOL_STATE_RUN:
		setVx(GLOBALS_D("solicol_vx")* getDirection());
		setAnimation(SOLICOL_ACTION_WALK);
		if (runDelay.isTerminated())
		{
			setSolicolState(SOLICOL_STATE_FIRE);
			fireDelay.start();
		}
		break;
	case SOLICOL_STATE_FIRE:
		setVx(0);
		setAnimation(SOLICOL_ACTION_FIRE);
		if (fireTime.atTime())
		{
			SolicolBullet* bullet = new SolicolBullet();
			bullet->setVx(getDirection()* GLOBALS_D("solicol_bullet_vx"));
			bullet->setX(getX());
			bullet->setY(getY() - 20);
			bullet->setRenderActive(true);
		}
		if (fireDelay.isTerminated())
		{
			setSolicolState(SOLICOL_STATE_RUN);
			runDelay.start();
		}
		break;
	default:
		break;
	}
	PhysicsObject::onUpdate(dt);
}

void Solicol::onInit(ifstream& fs)
{

}

void Solicol::setSolicolState(SOLICOL_STATE solicolState)
{
	this->solicolState = solicolState;
}

Solicol::~Solicol()
{
}
