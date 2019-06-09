#pragma once
#include"Item.h"
class ShurikenItem : public Item
{
public:
	ShurikenItem();
	~ShurikenItem();
	void onIntersect(MovableRect* other) override;
};