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
	auto ryu = Player::getInstance();
	switch (hawlState)
	{
	case BIRD_STATE_INVISIBLE:
		setRenderActive(false);
		if (Collision::AABBCheck(Camera::getInstance(), this))
		{
			setHawlState(BIRD_STATE_FOLLOW_PLAYER);
			setRenderActive(true);
		}
		break;
	case BIRD_STATE_FOLLOW_PLAYER:
	{
		auto r = GLOBALS_D("bird_r");

		float dy = 0;
		auto x = getX(), y = getY(), xr = ryu->getX(), yr = ryu->getY();

		auto deltax = x - xr, deltay = y - yr;

		if (abs(deltax) < GLOBALS_D("bird_min_x") || abs(deltay) < GLOBALS_D("bird_min_x"))
		{
			setHawlState(BIRD_STATE_RUN_UNTIL_RETURN);
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

		break;
	}
	case BIRD_STATE_RUN_UNTIL_RETURN:
	{
		auto x = getX(), y = getY(), xr = ryu->getX(), yr = ryu->getY();
		auto deltax = x - xr, deltay = y - yr;
		if (deltax*deltax + deltay * deltay  > GLOBALS_D("bird_max_x")*GLOBALS_D("bird_max_x"))
		{
			setHawlState(BIRD_STATE_FOLLOW_PLAYER);
		}
		break;
	}
	default:
		break;
	}
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
