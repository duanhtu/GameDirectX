#include"Enemy.h"
#include"Player.h"
#include"Collision.h"
#include"Weapon.h"
#include"Explosion.h"
#include"ScoreBoard.h"

Enemy::Enemy()
{
	setHealth(1);
}

void Enemy::setDirectionFollowPlayer()
{
	if (Player::getInstance()->getMidX() - getMidX() < 0)
	{
		setDirection(TEXTURE_DIRECTION_LEFT);
	}
	else
	{
		setDirection(TEXTURE_DIRECTION_RIGHT);
	}
}

void Enemy::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON && getRenderActive())
	{
		setRenderActive(false);
		setIsAlive(false);
		auto explosion = new Explosion();
		explosion->setX(getMidX());
		explosion->setY(getMidY());
		ScoreBoard::getInstance()->setScore(ScoreBoard::getInstance()->getScore() + 100);
	}
}

void Enemy::restoreLocation()
{
	setIsAlive(true);
	setRenderActive(true);
	setHealth(1);
	BaseObject::restoreLocation();
}

void Enemy::onDeath()
{
}

void Enemy::onDecreaseHealth()
{
}

void Enemy::setHealth(int health)
{
	this->health = health;
}

int Enemy::getHealth()
{
	return health;
}

void Enemy::onCollisionWithWeapon()
{
	setHealth(getHealth() - 1);
	onDecreaseHealth();
	if (getHealth() <= 0)
	{
		this->setIsAlive(false);
		onDeath();
	}
}

bool Enemy::canAttackPlayer()
{
	return this->getRenderActive();
}

Enemy::~Enemy()
{
}
