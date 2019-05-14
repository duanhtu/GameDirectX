#pragma once

#include"List.h"
#include"Sprite.h"

#define SPR SpriteManager::getSprite

enum SPRITE_INFO
{
	SPRITE_INFO_GROUND = -1,
	SPRITE_INFO_RYU = 0,
	SPRITE_INFO_SAMURAI = 1,
	SPRITE_INFO_CHEETAH = 2,
	SPRITE_INFO_HAWL = 3,
	SPRITE_INFO_BUTTERFLY = 4,
	SPRITE_INFO_DEATH = 5,
	SPRITE_COUNT
};

class SpriteManager
{
	List<Sprite*> sprites;

	static SpriteManager* instance;
public:
	static SpriteManager* getInstance();

	static Sprite* getSprite(int spriteInfo);

	SpriteManager();
	~SpriteManager();
};

