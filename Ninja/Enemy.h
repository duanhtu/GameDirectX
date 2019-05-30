#pragma once
#include"PhysicsObject.h"

class Enemy :
	public PhysicsObject
{
	int health;
public:
	void setHealth(int health);
	int getHealth();
	void setDirectionFollowPlayer();
	void onIntersect(MovableRect* other) override;
	void restoreLocation() override;
	virtual void onDeath();
	virtual void onDecreaseHealth();
	virtual void onCollisionWithWeapon();
	virtual bool canAttackPlayer();
	Enemy();
	~Enemy();
};