#pragma once
#include"Item.h"
class BlueBox : public Item
{
public:
	BlueBox();
	~BlueBox();
	void onIntersect(MovableRect* other) override;
};