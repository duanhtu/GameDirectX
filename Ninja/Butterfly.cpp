#include "Butterfly.h"
#include "Explosion.h"

void Butterfly::onUpdate(float dt)
{
}

Butterfly::Butterfly()
{
	setAnimation(BUTTERFLY_ACTION_FLY);
	setDirection(TEXTURE_DIRECTION_LEFT);
	setRenderActive(true);
}

void Butterfly::onIntersect(MovableRect* other)
{
	if (getRenderActive() && other->getCollisionType() == COLLISION_TYPE_PLAYER_WEAPON)
	{
		auto effect = new Explosion();
		effect->setX(getMidX());
		effect->setY(getMidY());
		setRenderActive(false);
	}
}

Butterfly::~Butterfly()
{
}
