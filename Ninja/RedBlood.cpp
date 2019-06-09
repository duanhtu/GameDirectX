#include"RedBlood.h"
#include "Player.h"
#include "ScoreBoard.h"

RedBlood::RedBlood()
{

}

void RedBlood::onIntersect(MovableRect* other)
{
	if (!hasEaten)
	{
		if (other == Player::getInstance() && getRenderActive())
		{
			setRenderActive(false);
			if (ScoreBoard::getInstance()->getMaxHealth() != ScoreBoard::getInstance()->getHealth())
			{
				int needBlood = ScoreBoard::getInstance()->getMaxHealth() - ScoreBoard::getInstance()->getHealth();
				if (needBlood < 4)
				{
					ScoreBoard::getInstance()->setHealth(ScoreBoard::getInstance()->getHealth() + needBlood);
					hasEaten = true;
				}
				else
				{
					ScoreBoard::getInstance()->setHealth(ScoreBoard::getInstance()->getHealth() + 4);
					hasEaten = true;
				}
			}
		}
		Item::onIntersect(other);
	}
}

RedBlood::~RedBlood() 
{

}