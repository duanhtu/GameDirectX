#include"Blood.h"
#include "Player.h"
#include "ScoreBoard.h"

Blood::Blood()
{

}

void Blood::onIntersect(MovableRect* other)
{
	if (other == Player::getInstance() && getRenderActive())
	{
		ScoreBoard::getInstance()->setHealth(ScoreBoard::getInstance()->getHealth() + 1);
		setRenderActive(false);
	}
	Item::onIntersect(other);
}

Blood::~Blood() 
{

}