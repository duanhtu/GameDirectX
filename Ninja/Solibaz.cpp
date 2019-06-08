#include "Solibaz.h"
#include "Player.h"
#include "SolibazBullet.h"

Solibaz::Solibaz()
{
	setSolibazState(SOLIBAZ_STATE_SIT);
	setSprite(SPR(SPRITE_INFO_SOLIBAZ));
	setDirection(TEXTURE_DIRECTION_LEFT);
	fireTime.init(GLOBALS_D("solibaz_fire_time"));
	fireDelay.init(GLOBALS_D("solibaz_fire_delay"));
	setRenderActive(true);
	
}
void Solibaz::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}
void Solibaz::onUpdate(float dt)
{
	fireDelay.update();
	switch(solibazState){
	case SOLIBAZ_STATE_SIT:
		setVx(0);
		setAnimation(SOLIBAZ_ACTION_SIT);
		if (getMidX() - Player::getInstance()->getMidX() <= GLOBALS_D("solibaz_distance_to_activ"))
		{
			setSolibazState(SOLIBAZ_STATE_ATTACK);
			fireDelay.start();
		}
		break;
	case SOLIBAZ_STATE_ATTACK:
		setAnimation(SOLIBAZ_ACTION_ATTACK);
		setVx(0);
		if (fireTime.atTime())
		{
			SolibazBullet* bullet = new SolibazBullet();
			bullet->setVx(getDirection()* GLOBALS_D("solibaz_bullet_vx"));
			bullet->setX(getX());
			bullet->setY(getY() - 2);
			bullet->setRenderActive(true);
		}
		if (fireDelay.isTerminated())
		{
			setSolibazState(SOLIBAZ_STATE_SIT);
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
