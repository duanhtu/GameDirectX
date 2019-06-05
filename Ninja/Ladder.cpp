#include "Ladder.h"
#include "Player.h"

Ladder::Ladder()
{

}

Ladder::~Ladder()
{

}

void Ladder::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	if (nx == -1 && Player::getInstance()->getDirection() == TEXTURE_DIRECTION_RIGHT)
	{
		Player::getInstance()->currentLadder = this;
		Player::getInstance()->setPlayerState(PLAYER_STATE_CLIMBING);
	}
}