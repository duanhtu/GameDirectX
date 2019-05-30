#pragma once
#include"Weapon.h"

class PlayerSword :
	public Weapon
{
public:
	void onIntersect(MovableRect* other) override;
	PlayerSword();
	~PlayerSword();
};


