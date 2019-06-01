#include "PlayerShuriken.h"
#include"SpriteManager.h"
#include"Player.h"


void PlayerShuriken::onUpdate(float dt)
{
	Weapon::onUpdate(dt);
}

PlayerShuriken::PlayerShuriken()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_PLAYER_SHURIKEN));
	setAy(0);
	setCollisionType(COLLISION_TYPE::COLLISION_TYPE_WEAPON);
}


PlayerShuriken::~PlayerShuriken()
{
}
