#include"ShurikenItem.h"
#include "Player.h"
#include "ScoreBoard.h"

ShurikenItem::ShurikenItem()
{

}

void ShurikenItem::onIntersect(MovableRect* other)
{
	if (!hasEaten)
	{
		if (other == Player::getInstance() && getRenderActive())
		{
			setRenderActive(false);
			ScoreBoard::getInstance()->setUseSubWeapon(true);
			hasEaten = true;
		}
		Item::onIntersect(other);
	}
}

ShurikenItem::~ShurikenItem()
{

}