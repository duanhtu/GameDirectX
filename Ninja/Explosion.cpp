#include "Explosion.h"
#include"SpriteManager.h"

Explosion::Explosion()
{
	setSprite(SpriteManager::getInstance()->getSprite(SPRITE_EXPLOSION));
	setDirection(TEXTURE_DIRECTION_RIGHT);
	animationGameTime.init(50);
	setRenderActive(true);
}

void Explosion::onUpdate(float dt)
{
	if (getIsLastFrameAnimationDone())
	{
		remove();
		setRenderActive(false);
	}
}

void Explosion::render(Camera* camera)
{
	Weapon::render(camera);
}
