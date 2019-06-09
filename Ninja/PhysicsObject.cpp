#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
	setAx(0);
	setAy(GLOBALS_D("object_default_ay"));
	setVx(0);
	setVy(0);
	setPhysicsEnable(true);
}

void PhysicsObject::onUpdate(float dt)
{
	if (getPhysicsEnable())
	{
		setVx(getVx() + getAx()*dt);
		setVy(getVy() + getAy()*dt);
		setDx(getVx()*dt);
		setDy(getVy()*dt);
	}
	setIsOnGround(false);
	/*
	if (this->getTop() < Camera::getInstance()->getBottom() && getCollisionType() != COLLISION_TYPE_PLAYER)
	{
		setIsAlive(false);
	}
	*/
}

PhysicsObject::~PhysicsObject()
{
}

float PhysicsObject::getAx()
{
	return ax;
}

float PhysicsObject::getAy()
{
	return ay;
}

float PhysicsObject::getVx()
{
	return vx;
}

float PhysicsObject::getVy()
{
	return vy;
}

void PhysicsObject::setAx(float ax)
{
	this->ax = ax;
}

void PhysicsObject::setAy(float ay)
{
	this->ay = ay;
}

void PhysicsObject::setVx(float vx)
{
	this->vx = vx;
}

void PhysicsObject::setVy(float vy)
{
	this->vy = vy;
}

bool PhysicsObject::getPhysicsEnable()
{
	return physicsEnable;
}

void PhysicsObject::setPhysicsEnable(bool physicsEnable)
{
	this->physicsEnable = physicsEnable;
}

void PhysicsObject::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (ny == 1)
	{
		setIsOnGround(true);
	}
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

bool PhysicsObject::getIsOnGround()
{
	return isOnGround;
}

void PhysicsObject::setIsOnGround(bool isOnGround)
{
	this->isOnGround = isOnGround;
}