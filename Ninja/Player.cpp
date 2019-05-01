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
	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown, keyJumpPress;
	keyLeftDown = KEY::getInstance()->isLeftDown;
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;

	keyJumpPress = KEY::getInstance()->isJumpPress;

	float vx = GLOBALS_D("player_vx");

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
		else
		{
			setAnimation(PLAYER_ACTION_STAND);
			setVx(0);
		}
		
		if (keyJumpPress)
		{
			setVy(100);
		}
	}
	else 
	{
		setAnimation(PLAYER_ACTION_JUMP);
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

Player::Player()
{
	setSprite(SPR(SPRITE_INFO_RYU));
}


Player::~Player()
{
}
