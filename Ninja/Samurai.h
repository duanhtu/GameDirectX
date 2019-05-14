﻿
#pragma once

#include "PhysicsObject.h"
enum SAMURAI_STATE
{
	SAMURAI_STATE_INVISIBLE,
	SAMURAI_STATE_VISIBLE
};

enum SAMURAI_ACTION
{
	SAMURAI_ACTION_STAND,
	SAMURAI_ACTION_WALK,
};

class Samurai :
	public PhysicsObject
{
	SAMURAI_STATE samuraiState;
	boolean isOnBridge ;
	int distanceChangeDirection;
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void onUpdate(float dt) override;
	void setSamuraiState(SAMURAI_STATE samuraiState);
	void onInit(ifstream& fs) override;
	Samurai();
	~Samurai();
};

