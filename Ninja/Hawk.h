#pragma once
#include "Enemy.h"

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

class Hawk : public Enemy
{
	HAWK_STATE hawkState;
	int limitLeft;
	int limitRight;
public:
	void setHawkState(HAWK_STATE hawkState);
	void backToTheFirstState() override;
	void onUpdate(float dt) override;
	Hawk();
	~Hawk();
};

