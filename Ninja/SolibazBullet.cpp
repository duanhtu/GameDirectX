#include "SolibazBullet.h"
#include"SpriteManager.h"
#include"Player.h"


void SolibazBullet::onUpdate(float dt)
{
	Weapon::onUpdate(dt);
}

SolibazBullet::SolibazBullet()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_SOLIBAZ_BULLET));
	setAy(0);
	setCollisionType(COLLISION_TYPE::COLLISION_TYPE_WEAPON);
}


SolibazBullet::~SolibazBullet()
{
}
