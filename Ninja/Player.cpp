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
	/* kiểm tra key bên trái có được nhấn */
	keyLeftDown = KEY::getInstance()->isLeftDown;
	/* kiểm tra key bên phải có được nhấn */
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;
	/* kiểm tra key jump có được nhấn */
	keyJumpPress = KEY::getInstance()->isJumpPress;

	float vx = GLOBALS_D("player_vx");

	/* nếu vật đứng trên sàn */
	if (getIsOnGround())
	{
		/* nếu nhấn key trái */
		if (keyLeftDown)
		{
			setVx(-vx);
		}
		/* nếu nhấn key phải */
		else if (keyRightDown)
		{
			setVx(vx);
		}
		else
		{
			setVx(0);
		}
		if (keyJumpPress) 
		{
			setVy(100);
		}
	}

	/* gọi lại phương thức xử lý onUpdate đã được định nghĩa ở lớp cha control click vào PhysicsObject::onUpdate để biết */

	PhysicsObject::onUpdate(dt);

}

void Player::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	/* ngăn chặn di chuyển */
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

Player::Player()
{
	setSprite(SPR(SPRITE_INFO_RYU));
}


Player::~Player()
{
}
