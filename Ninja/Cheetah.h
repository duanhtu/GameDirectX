#pragma once
#include "PhysicsObject.h"

enum CHEETAH_STATE
{
	CHEETAH_STATE_INVISIBLE,
	CHEETAH_STATE_VISIBLE,
};

enum CHEETAH_ACTION
{
	CHEETAH_ACTION_RUN
};

class Cheetah : public PhysicsObject
{
	CHEETAH_STATE cheetahState;
public:
	void setCheetahState(CHEETAH_STATE cheetahState);
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void onInit(ifstream& fs) override;
	Cheetah();
	~Cheetah();
};