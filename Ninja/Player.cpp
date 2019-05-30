#include "Player.h"
#include "PhysicsObject.h"
#include "ScoreBoard.h"
#include "PlayerSword.h"


Player * Player::instance = 0;
Player * Player::getInstance()
{
	if (instance == 0)
	{
		instance = new Player();
	}
	return instance;
}

void Player::onUpdate(float dt)
{
	if (this->getTop() < Camera::getInstance()->getBottom())
	{
		ScoreBoard* scoreBoard = ScoreBoard::getInstance();
		scoreBoard->restoreHealth();
		scoreBoard->increasePlayerLife(-1);
		restoreLocation();
		Camera::getInstance()->setX(0);
		Camera::getInstance()->setY(200);
		return;
	}

	blinkDelay.update();
	if (blinkDelay.isOnTime())
	{
		if (invisibleTime.atTime())
		{
			setRenderActive(true);
		}
		else
		{
			setRenderActive(false);
		}
	}
	if (blinkDelay.isTerminated())
	{
		setRenderActive(true);
	}
	if (isHit)
	{
		PhysicsObject::onUpdate(dt);
		if (getIsOnGround())
		{
			isHit = false;
		}
		else
		{
			setAnimation(PLAYER_ACTION::PLAYER_ACTION_JUMP);
			return;
		}
	}

	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown, keyJumpPress, keyAttackPress, keyAttackSurikenDown;
	keyLeftDown = KEY::getInstance()->isLeftDown;
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;
	keyJumpPress = KEY::getInstance()->isJumpPress;
	keyAttackPress = KEY::getInstance()->isAttackPress;
	keyAttackSurikenDown = KEY::getInstance()->isAttackSurikenDown;

	float vx = GLOBALS_D("player_vx");

	PLAYER_ACTION action;

	if (keyAttackPress  && !isOnAttack) {
		setIsOnAttack(true);
	}

	if (getIsLastFrameAnimationDone() && isOnAttack) {
		setIsOnAttack(false);
	}

	if (keyAttackSurikenDown && !isOnAttackSuriken && !isOnAttack) {
		setIsOnAttackSuriken(true);
	}

	if (getIsLastFrameAnimationDone() && isOnAttackSuriken) {
		setIsOnAttackSuriken(false);
	}

	if (getIsOnGround())
	{
		if (keyLeftDown)
		{
			setDirection(TEXTURE_DIRECTION_LEFT);
		}
		if (keyRightDown)
		{
			setDirection(TEXTURE_DIRECTION_RIGHT);
		}
		if (keyDownDown)
		{
			action = PLAYER_ACTION::PLAYER_ACTION_SIT;
			setVx(0);

			if (isOnAttack)
			{
				action = PLAYER_ACTION::PLAYER_ACTION_ATTACK_SIT;
				drawPlayerSword();
			}
		}
		else
		{
			bool isMoveDown = keyLeftDown || keyRightDown;
			if (isMoveDown)
			{
				setVx(getDirection()* vx);
				action = PLAYER_ACTION::PLAYER_ACTION_RUN;
			}
			else
			{
				setVx(0);
				action = PLAYER_ACTION::PLAYER_ACTION_STAND;
			}

			if (isOnAttack)
			{
				action = PLAYER_ACTION::PLAYER_ACTION_ATTACK;
				drawPlayerSword();
			}

			if (isOnAttackSuriken)
			{
				action = PLAYER_ACTION::PLAYER_ACTION_ATTACK_SURIKEN;
			}

			if (keyJumpPress)
			{
				setVy(GLOBALS_D("player_vy_jump"));
			}
		}
	}
	else
	{
		action = PLAYER_ACTION::PLAYER_ACTION_JUMP;
		if (isOnAttack)
		{
			action = PLAYER_ACTION::PLAYER_ACTION_ATTACK;
			drawPlayerSword();
		}
		if (isOnAttackSuriken)
		{
			action = PLAYER_ACTION::PLAYER_ACTION_ATTACK_SURIKEN;
		}
	}

	if (isOnAttack && getIsOnGround())
	{
		setVx(0);
	}

	setAnimation(action);
	PhysicsObject::onUpdate(dt);
}

void Player::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		PhysicsObject::onCollision(other, collisionTime, nx, ny);
		preventMovementWhenCollision(collisionTime, nx, ny);
		if (ny == 1)
		{
			isHit = false;
		}
	}
}

void Player::onIntersect(MovableRect* other)
{
	if ((other->getCollisionType() == COLLISION_TYPE_ENEMY || other->getCollisionType() == COLLISION_TYPE_WEAPON) && !blinkDelay.isOnTime() && ((BaseObject*)other)->getRenderActive())
	{
		blinkDelay.start();
		isHit = true;
		setVy(GLOBALS_D("player_hit_vy"));
		setVx(-getDirection() * GLOBALS_D("player_hit_vx"));
		ScoreBoard::getInstance()->setHealth(ScoreBoard::getInstance()->getHealth() - 1);
	}
}

void Player::setIsOnAttack(bool isOnAttack)
{
	this->isOnAttack = isOnAttack;
}

Player::Player()
{
	setSprite(SPR(SPRITE_INFO_RYU));
	setIsOnAttack(false);
	setIsOnAttackSuriken(false);
	setRenderActive(true);
	blinkTime.setDeltaTime(GLOBALS_D("player_blink_time"));
	blinkDelay.init(GLOBALS_D("player_blink_delay"));
	invisibleDelay.init(GLOBALS_D("player_invisible_delay"));
	invisibleTime.init(GLOBALS_D("player_invisible_time"));
	isHit = false;
	setDirection(TEXTURE_DIRECTION_RIGHT);
}

void Player::setIsOnAttackSuriken(bool isOnAttack)
{
	this->isOnAttackSuriken = isOnAttack;
}


Player::~Player()
{
}

void Player::drawPlayerSword()
{
	auto sword = new PlayerSword();
	if (getDirection() == TEXTURE_DIRECTION_RIGHT)
	{
		sword->setX(getRight());
	}
	else
	{
		sword->setX(getleft() - 20);
	}
	sword->setY(getTop() + 10);
	sword->setWidth(30);
	sword->setHeight(30);
}
