#include"BlueBlood.h"
#include "Player.h"
#include "ScoreBoard.h"

BlueBlood::BlueBlood()
{

}

void BlueBlood::onIntersect(MovableRect* other)
{
	if (!hasEaten)
	{
		if (other == Player::getInstance() && getRenderActive())
		{
			setRenderActive(false);
			if (ScoreBoard::getInstance()->getMaxHealth() != ScoreBoard::getInstance()->getHealth())
			{
				int needBlood = ScoreBoard::getInstance()->getMaxHealth() - ScoreBoard::getInstance()->getHealth();
				if (needBlood < 2)
				{
					ScoreBoard::getInstance()->setHealth(ScoreBoard::getInstance()->getHealth() + needBlood);
					hasEaten = true;
				}
				else
				{
					ScoreBoard::getInstance()->setHealth(ScoreBoard::getInstance()->getHealth() + 2);
					hasEaten = true;
				}
			}
		}
		Item::onIntersect(other);
	}
}

BlueBlood::~BlueBlood()
{

}