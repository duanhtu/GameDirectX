#include "Cheetah.h"
#include "Player.h"

void Cheetah::setCheetahState(CHEETAH_STATE cheetahState)
{
	this->cheetahState = cheetahState;
}

void Cheetah::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void Cheetah::onUpdate(float dt)
{
	switch (cheetahState)
	{
	case CHEETAH_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (getDirection() == TEXTURE_DIRECTION_RIGHT)
		{
			if (Player::getInstance()->getMidX() - getMidX() >= GLOBALS_D("cheetah_distance_to_activ"))
			{
				setCheetahState(CHEETAH_STATE_VISIBLE);
				setRenderActive(true);
			}
		}
		else
		{
			if (getMidX() - Player::getInstance()->getMidX() <= GLOBALS_D("cheetah_distance_to_activ"))
			{
				setCheetahState(CHEETAH_STATE_VISIBLE);
				setRenderActive(true);
			}
		}
		break;
	case CHEETAH_STATE_VISIBLE:
		setVx(GLOBALS_D("cheetah_vx")*getDirection());
		setAnimation(CHEETAH_ACTION_RUN);
		break;
	}
	PhysicsObject::onUpdate(dt);
}

void Cheetah::onInit(ifstream& fs)
{
	int direction;
	fs >> direction;
	setDirection((TEXTTURE_DIRECTION)direction);
}


Cheetah::Cheetah()
{
	setCheetahState(CHEETAH_STATE_INVISIBLE);
}


Cheetah::~Cheetah()
{
}
#pragma once
