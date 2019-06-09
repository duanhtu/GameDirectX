#include"RedScore.h"
#include "Player.h"
#include "ScoreBoard.h"

RedScore::RedScore()
{

}

void RedScore::onIntersect(MovableRect* other)
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

RedScore::~RedScore()
{

}