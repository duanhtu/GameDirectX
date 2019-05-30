#pragma once
#include "Rect.h"
#include"CollisionType.h"

class MovableRect :
	public Rect
{
	float dx, dy;
	COLLISION_TYPE collisionType;
	bool isAlive;
public :
	COLLISION_TYPE getCollisionType();
	void setCollisionType(COLLISION_TYPE collisionType);
	virtual void setDx(float dx);
	virtual void setDy(float dy);
	float getDx();
	float getDy();
	void goX();
	void goY();
	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny);
	virtual void onIntersect(MovableRect* other) {}
	void preventMovementWhenCollision(float collisionTime, int nx, int ny);
	bool getIsAlive();
	void setIsAlive(bool isAlive);
	MovableRect();
	~MovableRect();
};
