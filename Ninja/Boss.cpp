#include "Boss.h"
#include "Player.h"
#include "BossBomb.h"
#include "ScoreBoard.h"

Boss::Boss()
{
	
	setDirection(TEXTURE_DIRECTION_LEFT);
	setRenderActive(true);
	standDelay.init(GLOBALS_D("boss_stand_delay"));
	standDelay.start();
	isFirstJump = true;
}

void Boss::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Boss::onUpdate(float dt)
{
	standDelay.update();
	switch (bossState)
	{
	case BOSS_STATE_SIT:
		if (standDelay.isTerminated())
		{
			if (!isFirstJump)
			{
				if (getDirection() == TEXTURE_DIRECTION_RIGHT)
				{
					setDirection(TEXTURE_DIRECTION_LEFT);
					//setX(getX() + 64);
					setX(192);
				}
				else
				{
					setDirection(TEXTURE_DIRECTION_RIGHT);
					//setX(getX() - 64);
					setX(32);
				}
			}
			setVy(GLOBALS_D("boss_vy"));
			setVx(getDirection() * GLOBALS_D("boss_vx"));
			setBossState(BOSS_STATE_JUMP);
			isFirstJump = false;
		}
		else
		{
			setAnimation(BOSS_ACTION_SIT);
			setVx(0);
		}
		break;
	case BOSS_STATE_JUMP:
		if (getIsOnGround())
		{
			standDelay.start();
			setBossState(BOSS_STATE_SIT);
			BossBomb* bullet = new BossBomb();
			bullet->setX(getX());
			bullet->setY(getY());
			if (getDirection() == TEXTURE_DIRECTION_RIGHT)
			{
				bullet->setDirection(TEXTURE_DIRECTION_LEFT);
			}
			else
			{
				bullet->setDirection(TEXTURE_DIRECTION_RIGHT);
			}
			bullet->setVx(bullet->getDirection() * 100);
			bullet->setRenderActive(true);
		}
		else
		{
			setAnimation(BOSS_ACTION_JUMP);
		}
		break;
	default:
		break;
	}
	PhysicsObject::onUpdate(dt);
}


Boss::~Boss()
{
}

void Boss::setBossState(BOSS_STATE bossState)
{
	this->bossState = bossState;
}

void Boss::onIntersect(MovableRect * other)
{
	Player* player = Player::getInstance();
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER_WEAPON && player->isUsingWeapon)
	{
		ScoreBoard::getInstance()->setBossHealth(ScoreBoard::getInstance()->getBossHealth() - 1);
		player->isUsingWeapon = false;
	}

	if (other->getCollisionType() == COLLISION_TYPE_PLAYER_WEAPON && getRenderActive() && ScoreBoard::getInstance()->getBossHealth() <= 0)
	{
		/*
		setIsAlive(false);
		auto effect = new ExplosionEffect();
		effect->setX(getMidX());
		effect->setY(getMidY());
		ScoreBar::getInstance()->setScore(ScoreBar::getInstance()->getScore() + 100);
		*/
	}
}