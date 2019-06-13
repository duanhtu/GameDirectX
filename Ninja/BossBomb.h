#pragma once
#include"Weapon.h"

class BossBomb
	: public Weapon
{
public:
	void onUpdate(float dt) override;
	BossBomb();
	~BossBomb();
};

