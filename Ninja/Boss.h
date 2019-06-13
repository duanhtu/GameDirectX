#pragma once
#include "Enemy.h"
#include "Delay.h"
#include "BossExplosion.h"

enum BOSS_ACTION
{
	BOSS_ACTION_SIT,
	BOSS_ACTION_JUMP,
};

enum BOSS_STATE
{
	BOSS_STATE_SIT,
	BOSS_STATE_JUMP,
	BOSS_STATE_DYING
};
class Boss : public Enemy
{
	Delay standDelay;
	BOSS_STATE bossState;
	bool isFirstJump;
	int explosionTimes;
	bool hasExploded;
	BossExplosion* explosion1;
	BossExplosion* explosion2;
	BossExplosion* explosion3;
	BossExplosion* explosion4;
	Delay explodeDelay;
public:
	
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void setBossState(BOSS_STATE bossState);
	void onIntersect(MovableRect* other) override;
	Boss();
	~Boss();
};