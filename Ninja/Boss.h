#pragma once
#include "Enemy.h"

enum BOSS_ACTION
{
	BOSS_ACTION_SIT,
	BOSS_ACTION_JUM,
};
class Boss : public Enemy
{
	
	boolean hasChangedDirectionRight;
	boolean hasChangedDirectionLeft;
public:
	
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	Boss();
	~Boss();
};