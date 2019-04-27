
#pragma once

#include "BaseObject.h"
class Samurai :
	public BaseObject
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	Samurai();
	~Samurai();
};

