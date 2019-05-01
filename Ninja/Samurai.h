
#pragma once

#include "PhysicsObject.h"

class Samurai :
	public PhysicsObject
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	Samurai();
	~Samurai();
};

