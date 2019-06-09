
#pragma once
#include "Enemy.h"

enum SAMURAI_STATE
{
	SAMURAI_STATE_INVISIBLE,
	SAMURAI_STATE_VISIBLE
};

enum SAMURAI_ACTION
{
	SAMURAI_ACTION_STAND,
	SAMURAI_ACTION_WALK_ATTACK,
	SAMURAI_ACTION_WALK,
};

class Samurai :
	public Enemy
{
	SAMURAI_STATE samuraiState;
	boolean isOnBridge ;
	int distanceChangeDirection;
	boolean hasChangedDirectionRight;
	boolean hasChangedDirectionLeft ;
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void onUpdate(float dt) override;
	void setSamuraiState(SAMURAI_STATE samuraiState);
	void backToTheFirstState() override;
	void onInit(ifstream& fs) override;
	Samurai();
	~Samurai();
};

