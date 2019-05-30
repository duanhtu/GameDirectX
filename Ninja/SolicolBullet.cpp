#include "SolicolBullet.h"
#include"SpriteManager.h"
#include"Player.h"


void SolicolBullet::onUpdate(float dt)
{
	Weapon::onUpdate(dt);
}

SolicolBullet::SolicolBullet()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_SOLICOL_BULLET));
	setAy(0);
	setCollisionType(COLLISION_TYPE::COLLISION_TYPE_WEAPON);
}


SolicolBullet::~SolicolBullet()
{
}
