#include "SpriteManager.h"
SpriteManager * SpriteManager::instance = 0;
SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SpriteManager();
	}
	return instance;
}
Sprite * SpriteManager::getSprite(int spriteInfo)
{
	return getInstance()->sprites[spriteInfo];
}
SpriteManager::SpriteManager()
{
	for (size_t i = 0; i < SPRITE_COUNT; i++)
	{
		sprites._Add(new Sprite());
	}
	sprites[SPRITE_INFO_RYU]->InitFromFile("assets/sprites/ryu/ryu.png", "assets/sprites/ryu/ryu.info.dat");
	sprites[SPRITE_INFO_RYU]->image->direction = TEXTURE_DIRECTION_RIGHT;
	sprites[SPRITE_INFO_SAMURAI]->InitFromFile("assets/sprites/enemy/samurai/image.png", "assets/sprites/enemy/samurai/samurai.info.dat");
	sprites[SPRITE_INFO_CHEETAH]->InitFromFile("assets/sprites/enemy/cheetah/image.png", "assets/sprites/enemy/cheetah/cheetah.info.dat");
	sprites[SPRITE_INFO_HAWK]->InitFromFile("assets/sprites/enemy/hawk/image.png", "assets/sprites/enemy/hawk/hawk.info.dat");
	sprites[SPRITE_INFO_BUTTERFLY]->InitFromFile("assets/sprites/butterfly/image.png", "assets/sprites/butterfly/butterfly.info.dat");
	sprites[SPRITE_INFO_DEATH]->InitFromFile("assets/sprites/enemy/death/image.png","assets/sprites/enemy/death/death.info.dat");
	sprites[SPRITE_INFO_SOLICOL]->InitFromFile("assets/sprites/enemy/solicol/image.png","assets/sprites/enemy/solicol/solidercol.info.dat");
	sprites[SPRITE_INFO_DEATH_WEAPON]->InitFromFile("assets/sprites/weapon/death_weapon/image.png", "assets/sprites/weapon/death_weapon/death_weapon.info.dat");
}
SpriteManager::~SpriteManager()
{
}
