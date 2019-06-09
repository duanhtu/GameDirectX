#pragma once
#include "Enemy.h"

enum RUNNER_STATE
{
	RUNNER_STATE_INVISIBLE,
	RUNNER_STATE_VISIBLE,
};

enum RUNNER_ACTION
{
	RUNNER_ACTION_RUN
};
class Runner : public Enemy
{
	RUNNER_STATE runnerState;
public:
	void setRunnerState(RUNNER_STATE runnerState);
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void backToTheFirstState() override;
	void onInit(ifstream& fs) override;
	Runner();
	~Runner();
};