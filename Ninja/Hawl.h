#pragma once
#pragma once
#include "PhysicsObject.h"

enum HAWL_STATE
{
	BIRD_STATE_INVISIBLE,
	BIRD_STATE_FOLLOW_PLAYER,
	BIRD_STATE_RUN_UNTIL_RETURN
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

