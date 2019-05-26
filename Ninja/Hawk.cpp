#include "Hawk.h"
#include"Collision.h"
#include "Player.h"
#include "Tilemap.h"

void Hawk::setHawkState(HAWK_STATE hawkState)
{
	this->hawkState = hawkState;
}

void Hawk::onUpdate(float dt)
{
	auto ryu = Player::getInstance();
	switch (hawkState)
	{
	case HAWK_STATE_INVISIBLE:
		setRenderActive(false);
		if (Collision::AABBCheck(Camera::getInstance(), this))
		{
			setHawkState(HAWK_STATE_FOLLOW_PLAYER);
			setRenderActive(true);
		}
		break;
	case HAWK_STATE_FOLLOW_PLAYER:
	{
		auto r = GLOBALS_D("bird_r");

		float dy = 0;
		auto x = getX(), y = getY(), xr = ryu->getX(), yr = ryu->getY();

		auto deltax = x - xr, deltay = y - yr;

		if (abs(deltax) < GLOBALS_D("bird_min_x") || abs(deltay) < GLOBALS_D("bird_min_x"))
		{
			setHawkState(HAWK_STATE_RUN_UNTIL_RETURN);
		}

		dy = r * sqrt((deltay*deltay) / (deltax*deltax + deltay * deltay));

		if (y - yr > 0)
		{
			dy = -dy;
		}

		auto dx = dy * deltax / deltay;
		if (dx < 0)
		{
			setDirection(TEXTURE_DIRECTION_LEFT);
		}
		else
		{
			setDirection(TEXTURE_DIRECTION_RIGHT);
		}

		setDx(dx);
		setDy(dy);

		limitLeft = getInitBox()->getX() - GLOBALS_D("bird_active_length");
		limitRight = getInitBox()->getX() + GLOBALS_D("bird_active_length");
		if (x < limitLeft || x > limitRight)
		{
			setHawkState(HAWK_STATE_STOP_FOLLOW);
		}
		break;
	}
	case HAWK_STATE_RUN_UNTIL_RETURN:
	{
		auto x = getX(), y = getY(), xr = ryu->getX(), yr = ryu->getY();
		auto deltax = x - xr, deltay = y - yr;
		if (deltax*deltax + deltay * deltay  > GLOBALS_D("bird_max_x")*GLOBALS_D("bird_max_x"))
		{
			setHawkState(HAWK_STATE_FOLLOW_PLAYER);
		}
		break;
	}
	case HAWK_STATE_STOP_FOLLOW:
	{
		auto x = getX();
		setDx(0);
		setDy(0);
	}
	default:
		break;
	}
}


Hawk::Hawk()
{
	setDirection(TEXTURE_DIRECTION_LEFT);
	setRenderActive(true);
}

Hawk::~Hawk()
{
}
