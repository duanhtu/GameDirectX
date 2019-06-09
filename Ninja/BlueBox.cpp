#include"BlueBox.h"
#include "Player.h"
#include "ScoreBoard.h"

BlueBox::BlueBox()
{

}

void BlueBox::onIntersect(MovableRect* other)
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

BlueBox::~BlueBox()
{

}