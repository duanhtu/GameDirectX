﻿#pragma once

#include"List.h"
#include"Sprite.h"

#define SPR SpriteManager::getSprite

enum SPRITE_INFO
{
	SPRITE_INFO_LADDER = -2,
	SPRITE_INFO_GROUND = -1,
	SPRITE_INFO_RYU = 0,
	SPRITE_INFO_SAMURAI = 1,
	SPRITE_INFO_CHEETAH = 2,
	SPRITE_INFO_HAWK = 3,
	SPRITE_INFO_BUTTERFLY = 4,
	SPRITE_INFO_DEATH = 5,
	SPRITE_INFO_SOLICOL = 6,
	SPRITE_INFO_DEATH_WEAPON = 7,
	SPRITE_MISC = 8,
	SPRITE_EXPLOSION = 9,
	SPRITE_INFO_SOLICOL_BULLET = 10,
	SPRITE_INFO_ITEM_BLOOD = 11,
	SPRITE_INFO_SOLIBAZ = 12,
	SPRITE_INFO_BIRD = 13,
	SPRITE_INFO_RUNNER = 14,
	SPRITE_INFO_SOLIBAZ_BULLET = 15,
	SPRITE_INFO_PLAYER_SHURIKEN = 16,
	SPRITE_COUNT
};

enum MISC_SPRITE_ID
{
	MISC_SPRITE_ID_NUMBER,
	MISC_SPRITE_ID_MORNING_STAR,
	MISC_SPRITE_ID_LOST_HEALTH,
	MISC_SPRITE_ID_KNIFE_ITEM,
	MISC_SPRITE_ID_TORCH,
	MISC_SPRITE_ID_EXPLOSION_EFFECT,
	MISC_SPRITE_ID_CANDLE,
	MISC_SPRITE_ID_MERMAN_BULLET,
	MISC_SPRITE_ID_ITEM_MORNING_STAR,
	MISC_SPRITE_ID_ITEM_SMALLHEART,
	MISC_SPRITE_ID_ITEM_WATER,
	MISC_SPRITE_ID_ITEM_BIGHEART,
	MISC_SPRITE_ID_ITEM_DAGGER,
	MISC_SPRITE_ID_ITEM_HOLYWATER,
	MISC_SPRITE_ID_ITEM_HOLYCROSS,
	MISC_SPRITE_ID_ITEM_AXE,
	MISC_SPRITE_ID_ITEM_GOLDPOTION,
	MISC_SPRITE_ID_ITEM_STOPWATCH,
	MISC_SPRITE_ID_ITEM_BREAK_WALL1,
	MISC_SPRITE_ID_ITEM_BREAK_WALL,
	MISC_SPRITE_ID_ITEM_400PTS,
	MISC_SPRITE_ID_ITEM_700PTS,
	MISC_SPRITE_ID_ITEM_1000PTS,
	MISC_SPRITE_ID_ITEM_BOOMERANG,
	MISC_SPRITE_ID_BOOMERANG,
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

