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
		setRenderActive(false);
		if (ScoreBoard::getInstance()->getMaxHealth() != ScoreBoard::getInstance()->getHealth())
		{
			ScoreBoard::getInstance()->setHealth(ScoreBoard::getInstance()->getHealth() + 1);
		}
	}
	Item::onIntersect(other);
}

Blood::~Blood() 
{

}