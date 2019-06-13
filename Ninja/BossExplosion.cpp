#include "BossExplosion.h"
#include"SpriteManager.h"

BossExplosion::BossExplosion()
{
	setSprite(SpriteManager::getInstance()->getSprite(SPRITE_BOSS_EXPLOSION));
	setDirection(TEXTURE_DIRECTION_RIGHT);
	animationGameTime.init(50);
	setRenderActive(true);
	setPhysicsEnable(false);
}

void BossExplosion::render(Camera* camera)
{
	Weapon::render(camera);
}
