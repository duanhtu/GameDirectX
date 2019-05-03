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

	if (keyAttackPress && !isOnAttack) {
		setIsOnAttack(true);
		setVx(0);
		if(keyDownDown) {
			setAnimation(PLAYER_ACTION_ATTACK_SIT);
		}
		else
		{
			setAnimation(PLAYER_ACTION_ATTACK);
		}
	}

	if (getIsLastFrameAnimationDone() && isOnAttack) {
		setIsOnAttack(false);
	}

	if (!isOnAttack)
	{
		if (getIsOnGround())
		{
			if (keyLeftDown)
			{
				setAnimation(PLAYER_ACTION_RUN);
				setVx(-vx);
				setDirection(TEXTURE_DIRECTION_LEFT);
			}
			else if (keyRightDown)
			{
				setAnimation(PLAYER_ACTION_RUN);
				setVx(vx);
				setDirection(TEXTURE_DIRECTION_RIGHT);
			}
			else  if (keyDownDown) //is sit
			{
				setVx(0);
				setAnimation(PLAYER_ACTION_SIT);
			}
			else if (keyJumpPress) {
				setVy(GLOBALS_D("player_vy_jump"));
			}
			else
			{
				setVx(0);
				setAnimation(PLAYER_ACTION_STAND);
				/*
				if (keyAttackPress)
				{
					setAnimation(PLAYER_ACTION_ATTACK);
				}
				else {

				}
				*/
			}
		}
		else
		{
			setAnimation(PLAYER_ACTION_JUMP);
		}
	}

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
}


Player::~Player()
{
}
