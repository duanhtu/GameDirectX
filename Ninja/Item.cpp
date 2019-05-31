#include "Item.h"

Item::Item()
{
	setCollisionType(COLLISION_TYPE_ITEM);
	setRenderActive(false);
	setPhysicsEnable(false);
}

void Item::onIntersect(MovableRect* other)
{
	if (!getRenderActive())
	{
		if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
		{
			setRenderActive(true);
			setPhysicsEnable(true);
		}
	}
	
}
void Item::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		preventMovementWhenCollision(collisionTime, nx, ny);
	}
}

Item::~Item()
{
}