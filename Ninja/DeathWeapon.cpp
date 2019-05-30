#include"SpriteManager.h"
#include "DeathWeapon.h"

DeathWeapon::DeathWeapon()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_DEATH_WEAPON));
	setWidth(8);
	setHeight(15);
	setCollisionType(COLLISION_TYPE::COLLISION_TYPE_WEAPON);
}


DeathWeapon::~DeathWeapon()
{
}

void DeathWeapon::onUpdate(float dt)
{
	Weapon::onUpdate(dt);
}

void DeathWeapon::render(Camera * camera)
{
	Weapon::render(camera);
}
