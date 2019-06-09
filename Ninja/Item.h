#pragma once
#include "PhysicsObject.h"
class Item : public PhysicsObject
{
	
public:
	boolean hasEaten;
	Item();
	~Item();
	void onIntersect(MovableRect* other) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny);

};