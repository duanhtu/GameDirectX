#pragma once


#include "PhysicsObject.h"
enum DEATH_STATE
{
	DEATH_STATE_INVISIBLE,
	DEATH_STATE_VISIBLE
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
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void onUpdate(float dt) override;
	void setDeathState(DEATH_STATE deathState);
	void onInit(ifstream& fs) override;
	Death();
	~Death();
};
