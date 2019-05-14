#include "Hawl.h"
#include"Collision.h"
#include "Player.h"
#include "Tilemap.h"

bool Hawl::isActivity = false;

void Hawl::setHawlState(HAWL_STATE hawlState)
{
	this->hawlState = hawlState;
}

void Hawl::onUpdate(float dt)
{
	/*
	setAnimation(HAWL_ACTION_FLY);
	MovableRect* broadPhaseBox = Collision::GetSweptBroadPhaseBox(Player::getInstance());
	boolean test = Collision::AABBCheck(broadPhaseBox, &discoverSpace);
	switch (hawlState)
	{
	case HAWl_STATE_WAIT:
		if (Collision::AABBCheck(broadPhaseBox, &discoverSpace)
			&& !isActivity
			)
		{
			setHawlState(HAWL_STATE_VISIBLE);
			isActivity = true;
		}
		break;
	case HAWL_STATE_VISIBLE:
	{
		int d = 20;
		alpha += 1;
		if (alpha >= 360)
		{
			alpha -= 360;
		}
		setY(getY() + d * sin(alpha * 0.1));
		break;
	}
	default:
		break;
	}
	*/

	switch (hawlState)
	{
	case BIRDWAIT:
		if (getX() - Player::getInstance()->getX() < 100)
			setHawlState(BIRDPREPARE);
		break;
	case BIRDPREPARE:
		setVy(Player::getInstance()->getY() - getY() - 80);
		setVx(Player::getInstance()->getX() - getX() - 80);
		if (Player::getInstance()->getY() - getY() > 10 && Player::getInstance()->getY() - getY() > 10)
		{
			setAx(80);
			setAy(10);
			setVy(-20);
		}

		if (Player::getInstance()->getX() - getX() > 40)
		{
			setVx((Player::getInstance()->getMidX() - getMidX()) * 2);
			setVy((50 - getMidY()) * 2);
			setDirection(TEXTURE_DIRECTION_RIGHT);
			setHawlState(BIRDATTACK1);
		}
		break;
	case BIRDATTACK1:
		if (getMidX() > Player::getInstance()->getMidX())
		{
			setAy(-50);
			setAx(-150);
			setHawlState(BIRDSLOW_DOWN_RIGHT);
		}
		break;
	case BIRDSLOW_DOWN_RIGHT:
		setVx(getVx() + getAx()*dt);
		setVy(getVy() + getAy()*dt);
		setDx(getVx()*dt);
		setDy(getVy()*dt);
		if (getMidY() >= 55)
		{
			setVy(-50);
			setVx(50);
			setHawlState(BIRDFLY_DOWN_RIGHT);
		}
		break;
	case BIRDFLY_DOWN_RIGHT:
		if (getY() < 20) {
			setVx(-(getMidX() - Player::getInstance()->getMidX()) * 2);
			setVy((50 - getMidY()) * 2);
			setHawlState(BIRDATTACK2);
		}
		break;
	case BIRDATTACK2:
		if (getMidX() < Player::getInstance()->getMidX())
		{
			setAy(-50);
			setAx(150);
			setHawlState(BIRDSLOW_DOWN_LEFT);
		}
		break;
	case BIRDSLOW_DOWN_LEFT:
		setVx(getVx() + getAx()*dt);
		setVy(getVy() + getAy()*dt);
		setDx(getVx()*dt);
		setDy(getVy()*dt);
		if (getMidY() >= 55)
		{
			setVy(-50);
			setVx(-50);
			setHawlState(BIRDFLY_DOWN_LEFT);
		}
		break;
	case BIRDFLY_DOWN_LEFT:
		if (getY() < 20) {
			setVx((Player::getInstance()->getMidX() - getMidX()) * 2);
			setVy((50 - getMidY()) * 2);
			setHawlState(BIRDATTACK1);
		}
		break;
	}
	//PhysicsObject::onUpdate(dt);
}


Hawl::Hawl(int worldHeight)
{
	float y = (float)worldHeight - getY();
	discoverSpace.set(getX(), getY(), getWidth(), worldHeight);
	discoverDirection = TEXTURE_DIRECTION_LEFT;
	setDirection(TEXTURE_DIRECTION_LEFT);
	//setHawlState(HAWL_STATE_VISIBLE);
	setRenderActive(true);
}

Hawl::~Hawl()
{
}
