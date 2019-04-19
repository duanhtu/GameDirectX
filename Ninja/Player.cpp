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
	/* kiểm tra key bên trái có được giữ */
	keyLeftDown = KEY::getInstance()->isLeftDown;
	/* kiểm tra key bên phải có được giữ */
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;

	/* kiểm tra key jump có được nhấn */
	keyJumpPress = KEY::getInstance()->isJumpPress;

	float vx = GLOBALS_D("player_vx");

	/* nếu vật đứng trên sàn */
	if (getIsOnGround())
	{
		/* nếu giữ key trái */
		if (keyLeftDown)
		{
			/* set animation chạy */
			setAnimation(PLAYER_ACTION_RUN);
			setVx(-vx);
			setDirection(TEXTURE_DIRECTION_LEFT);
		}
		/* nếu giữ key phải */
		else if (keyRightDown)
		{
			/* set animation chạy */
			setAnimation(PLAYER_ACTION_RUN);
			setVx(vx);
			setDirection(TEXTURE_DIRECTION_RIGHT);
		}
		else
		{
			/* set animation đứng yên */
			setAnimation(PLAYER_ACTION_STAND);
			setVx(0);
		}
		/* nếu đứng trên sàn mà nhấn key jump thì sẽ cho nhân vật nhảy. còn nếu ở trên không mà nhấn key jump thì nó sẽ
		không vào chỗ này vì không thỏa mãn isOnGround = true*/
		if (keyJumpPress)
		{
			setVy(100);
		}
	}
	else /* nếu nhân vật không đứng trên sàn (đang lơ lững trên không) */
	{
		setAnimation(PLAYER_ACTION_JUMP);
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
