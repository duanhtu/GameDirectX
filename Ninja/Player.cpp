#include "Player.h"
#include "PhysicsObject.h"


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
	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown, keyJumpPress, keyAttackPress;
	keyLeftDown = KEY::getInstance()->isLeftDown;
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;
	keyJumpPress = KEY::getInstance()->isJumpPress;
	keyAttackPress = KEY::getInstance()->isAttackPress;

	float vx = GLOBALS_D("player_vx");

	PLAYER_ACTION action;

	if (keyAttackPress && !isOnAttack) {
		setIsOnAttack(true);
	}

	if (getIsLastFrameAnimationDone() && isOnAttack) {
		setIsOnAttack(false);
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
	//if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	//{
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
	//}
}

void Player::setIsOnAttack(bool isOnAttack)
{
	this->isOnAttack = isOnAttack;
}

Player::Player()
{
	setSprite(SPR(SPRITE_INFO_RYU));
	setIsOnAttack(false);
	setRenderActive(true);
}


Player::~Player()
{
}
