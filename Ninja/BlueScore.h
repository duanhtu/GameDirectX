#pragma once
#include"Item.h"
class BlueScore : public Item
{
public:
	BlueScore();
	~BlueScore();
	void onIntersect(MovableRect* other) override;
};