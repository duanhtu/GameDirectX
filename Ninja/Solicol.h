#pragma once
#include "Enemy.h"
#include "Delay.h"

enum SOLICOL_STATE
{
	SOLICOL_STATE_INVISIBLE,
	SOLICOL_STATE_RUN,
	SOLICOL_STATE_FIRE
};

enum SOLICOL_ACTION
{
	SOLICOL_ACTION_WALK,
	SOLICOL_ACTION_FIRE
};

class Solicol :
	public Enemy
{
	SOLICOL_STATE solicolState;
	Delay runDelay;
	Delay fireDelay;
	GameTime fireTime;
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void onUpdate(float dt) override;
	void setSolicolState(SOLICOL_STATE solicolState);
	void onInit(ifstream& fs) override;
	Solicol();
	~Solicol();
};