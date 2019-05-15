#pragma once
#include "PhysicsObject.h"
enum SOLICOL_STATE
{
	SOLICOL_STATE_INVISIBLE,
	SOLICOL_STATE_VISIBLE
};

enum SOLICOL_ACTION
{
	SOLICOL_ACTION_WALK,
};

class Solicol :
	public PhysicsObject
{
	SOLICOL_STATE solicolState;
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void onUpdate(float dt) override;
	void setSolicolState(SOLICOL_STATE solicolState);
	void onInit(ifstream& fs) override;
	Solicol();
	~Solicol();
};