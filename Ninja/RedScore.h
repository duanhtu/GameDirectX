#pragma once
#include"Item.h"
class RedScore : public Item
{
public:
	RedScore();
	~RedScore();
	void onIntersect(MovableRect* other) override;
};