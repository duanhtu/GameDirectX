#include "PlayerSword.h"

void PlayerSword::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY)
	{
		remove();
	}
}

PlayerSword::PlayerSword()
{
	setCollisionType(COLLISION_TYPE::COLLISION_TYPE_WEAPON);
}


PlayerSword::~PlayerSword()
{
}
