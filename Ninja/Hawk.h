#pragma once
#pragma once
#include "PhysicsObject.h"

enum HAWK_STATE
{
	HAWK_STATE_INVISIBLE,
	HAWK_STATE_FOLLOW_PLAYER,
	HAWK_STATE_RUN_UNTIL_RETURN,
	HAWK_STATE_STOP_FOLLOW,
};

enum HAWK_ACTION
{
	Hawk_ACTION_FLY
};

class Hawk : public PhysicsObject
{
	HAWK_STATE hawkState;
	int limitLeft;
	int limitRight;
public:
	void setHawkState(HAWK_STATE hawkState);
	void onUpdate(float dt) override;
	Hawk();
	~Hawk();
};

