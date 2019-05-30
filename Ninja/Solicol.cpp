#include "Solicol.h"
#include"Player.h"
#include "SolicolBullet.h"

Solicol::Solicol()
{
	setSolicolState(SOLICOL_STATE_INVISIBLE);
	setDirection(TEXTURE_DIRECTION_LEFT);
	fireTime.init(GLOBALS_D("solicol_fire_time"));
}

void Solicol::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void Solicol::onUpdate(float dt)
{
	switch (solicolState)
	{
	case SOLICOL_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (getMidX() - Player::getInstance()->getMidX() <= GLOBALS_D("solicol_distance_to_activ"))
		{
			setSolicolState(SOLICOL_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case SOLICOL_STATE_VISIBLE:
		setAnimation(SOLICOL_ACTION_WALK);
		setVx(GLOBALS_D("solicol_vx")*getDirection());
		if (fireTime.atTime())
		{
			SolicolBullet* bullet = new SolicolBullet();
			bullet->setVx(getDirection()* GLOBALS_D("solicol_bullet_vx"));
			bullet->setX(getX());
			bullet->setY(getY() - 20);
			bullet->setRenderActive(true);
		}
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
