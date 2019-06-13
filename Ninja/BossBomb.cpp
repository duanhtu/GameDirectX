#include "BossBomb.h"
#include"SpriteManager.h"
#include"Player.h"


void BossBomb::onUpdate(float dt)
{
	Weapon::onUpdate(dt);
}

BossBomb::BossBomb()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_BOSS_BOMB));
	setAy(0);
	setCollisionType(COLLISION_TYPE::COLLISION_TYPE_WEAPON);
}


BossBomb::~BossBomb()
{
}
