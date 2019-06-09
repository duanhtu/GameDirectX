#pragma once
#include"Item.h"
class BlueBlood : public Item
{
public:
	BlueBlood();
	~BlueBlood();
	void onIntersect(MovableRect* other) override;
};