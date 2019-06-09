#include"RedBox.h"
#include "Player.h"
#include "ScoreBoard.h"

RedBox::RedBox()
{

}

void RedBox::onIntersect(MovableRect* other)
{

	if (!hasEaten)
	{
		if (other == Player::getInstance() && getRenderActive())
		{
			setRenderActive(false);
			ScoreBoard::getInstance()->increaseScore(1000);
			hasEaten = true;
		}
		Item::onIntersect(other);
	}

}

RedBox::~RedBox()
{

}