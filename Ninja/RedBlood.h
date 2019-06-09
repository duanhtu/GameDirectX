#pragma once
#include"Item.h"
class RedBlood : public Item
{
public:
	RedBlood();
	~RedBlood();
	void onIntersect(MovableRect* other) override;
};