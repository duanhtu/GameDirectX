#include"SpriteManager.h"
#include "DeathWeapon.h"

void DeathWeapon::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
}

DeathWeapon::DeathWeapon()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_DEATH_WEAPON));
	setWidth(8);
	setHeight(15);
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
