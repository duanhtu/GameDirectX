#pragma once
#include "Enemy.h"
#include "Delay.h"

enum BOSS_ACTION
{
	BOSS_ACTION_SIT,
	BOSS_ACTION_JUMP,
};

enum BOSS_STATE
{
	BOSS_STATE_SIT,
	BOSS_STATE_JUMP
};
class Boss : public Enemy
{
	Delay standDelay;
	BOSS_STATE bossState;
	bool isFirstJump;
public:
	
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void setBossState(BOSS_STATE bossState);
	void onIntersect(MovableRect* other) override;
	Boss();
	~Boss();
};