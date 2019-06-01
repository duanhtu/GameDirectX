#include "Bird.h"
#include "Explosion.h"

void Bird::onUpdate(float dt)
{
}
Bird::Bird()
{
	setAnimation(BIRD_ACTION_FLY);
	setDirection(TEXTURE_DIRECTION_LEFT);
	setRenderActive(true);
}
void Bird::onIntersect(MovableRect* other)
{
	if (getRenderActive() && other->getCollisionType() == COLLISION_TYPE_WEAPON)
	{
		auto effect = new Explosion();
		effect->setX(getMidX());
		effect->setY(getMidY());
		setRenderActive(false);
	}
}
Bird::~Bird()
{
}