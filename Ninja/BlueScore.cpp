#include"BlueScore.h"
#include "Player.h"
#include "ScoreBoard.h"

BlueScore::BlueScore()
{

}

void BlueScore::onIntersect(MovableRect* other)
{

	if (!hasEaten)
	{
		if (other == Player::getInstance() && getRenderActive())
		{
			setRenderActive(false);
			ScoreBoard::getInstance()->increaseScore(500);
			hasEaten = true;
		}
		Item::onIntersect(other);
	}

}

BlueScore::~BlueScore()
{

}