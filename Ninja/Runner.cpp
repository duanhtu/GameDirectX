#include "Runner.h"
#include "Player.h"

void Runner::setRunnerState(RUNNER_STATE runnerState)
{
	this->runnerState = runnerState;
}

void Runner::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void Runner::onUpdate(float dt)
{
	switch (runnerState)
	{
	case RUNNER_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (getDirection() == TEXTURE_DIRECTION_RIGHT)
		{
			if (Player::getInstance()->getMidX() - getMidX() >= GLOBALS_D("runner_distance_to_activ"))
			{
				setRunnerState(RUNNER_STATE_VISIBLE);
				setRenderActive(true);
			}
		}
		else
		{
			if (getMidX() - Player::getInstance()->getMidX() <= GLOBALS_D("runner_distance_to_activ"))
			{
				setRunnerState(RUNNER_STATE_VISIBLE);
				setRenderActive(true);
			}
		}
		break;
	case RUNNER_STATE_VISIBLE:
		setVx(GLOBALS_D("runner_vx")*getDirection());
		setAnimation(RUNNER_ACTION_RUN);
		break;
	}
	PhysicsObject::onUpdate(dt);
}

void Runner::onInit(ifstream& fs)
{
	int direction;
	fs >> direction;
	setDirection((TEXTTURE_DIRECTION)direction);
}


Runner::Runner()
{
	setRunnerState(RUNNER_STATE_INVISIBLE);
}


Runner::~Runner()
{
}