#include "Solibaz.h"
#include "Player.h"
#include "SolibazBullet.h"

Solibaz::Solibaz()
{
	setSolibazState(SOLIBAZ_STATE_INVISIBLE);
	setDirection(TEXTURE_DIRECTION_LEFT);
	fireTime.init(GLOBALS_D("solibaz_fire_time"));
	
}
void Solibaz::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}
void Solibaz::onUpdate(float dt)
{
	switch(solibazState){
	case SOLIBAZ_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setVy(0);
		if (getMidX() - Player::getInstance()->getMidX() <= GLOBALS_D("solibaz_distance_to_activ"))
		{
			setSolibazState(SOLIBAZ_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case SOLIBAZ_STATE_VISIBLE:
		setAnimation(SOLIBAZ_ACTION_ATTACK);
		setVx(GLOBALS_D("solibaz_vx")*getDirection());
		if (fireTime.atTime())
		{
			SolibazBullet* bullet = new SolibazBullet();
			bullet->setVx(getDirection()* GLOBALS_D("solibaz_bullet_vx"));
			bullet->setX(getX());
			bullet->setY(getY());
			bullet->setRenderActive(true);
		}
		break;
	}
	PhysicsObject::onUpdate(dt);
}
void Solibaz::onInit(ifstream& fs)
{

}
void Solibaz::setSolibazState(SOLIBAZ_STATE solibazState)
{
	this->solibazState = solibazState;
}

Solibaz::~Solibaz()
{
}
