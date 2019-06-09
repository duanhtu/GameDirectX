#include "PlayerSword.h"

void PlayerSword::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY || other->getCollisionType() == COLLISION_TYPE_MISC)
	{
		remove();
	}
}

PlayerSword::PlayerSword()
{
	setCollisionType(COLLISION_TYPE::COLLISION_TYPE_PLAYER_WEAPON);
	setPhysicsEnable(false);
}


PlayerSword::~PlayerSword()
{
}
