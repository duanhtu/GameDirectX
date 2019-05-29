#pragma once


#include "PhysicsObject.h"
#include"Delay.h"

enum DEATH_STATE
{
	DEATH_STATE_RUN,
	DEATH_STATE_FIRE
};

enum DEATH_ACTION
{
	DEATH_ACTION_WALK,
};

class Death :
	public PhysicsObject
{
	DEATH_STATE deathState;
	boolean isOnBridge;
	int distanceChangeDirection;
	Delay runDelay;
	Delay fireDelay;
	int vDirection ;
	int worldHeight;
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void onUpdate(float dt) override;
	void setDeathState(DEATH_STATE deathState);
	Death();
	~Death();
};
