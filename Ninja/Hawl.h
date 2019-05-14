#pragma once
#pragma once
#include "PhysicsObject.h"

enum HAWL_STATE
{
	/*
	HAWl_STATE_WAIT,
	HAWL_STATE_VISIBLE
	*/
	BIRDWAIT,
	BIRDPREPARE,
	BIRDATTACK1,
	BIRDSLOW_DOWN_RIGHT,
	BIRDFLY_DOWN_RIGHT,
	BIRDATTACK2,
	BIRDSLOW_DOWN_LEFT,
	BIRDFLY_DOWN_LEFT,
};

enum HAWL_ACTION
{
	HAWL_ACTION_FLY
};

class Hawl : public PhysicsObject
{
	HAWL_STATE hawlState;
	int alpha;
	Rect discoverSpace;
	TEXTTURE_DIRECTION discoverDirection;
	// dam bao trong vung chi co 1 con bat xuat hien
	// neu isActivity = true thi cho phep con bat xuat hien
	static bool isActivity;
public:
	void setHawlState(HAWL_STATE hawlState);
	void onUpdate(float dt) override;
	Hawl(int worldHeight);
	~Hawl();
};

