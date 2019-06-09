#pragma once
#include"Item.h"
class RedBox : public Item
{
public:
	RedBox();
	~RedBox();
	void onIntersect(MovableRect* other) override;
};
