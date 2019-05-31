#pragma once
#include"Item.h"
class Blood : public Item
{
public:
	Blood();
	~Blood();
	void onIntersect(MovableRect* other) override;
};