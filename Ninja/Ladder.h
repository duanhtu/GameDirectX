#pragma once
#include "BaseObject.h"

class Ladder :
	public BaseObject
{
public:
	Ladder();
	~Ladder();
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
};
