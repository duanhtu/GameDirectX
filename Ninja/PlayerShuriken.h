#pragma once
#include"Weapon.h"

class PlayerShuriken
	: public Weapon
{
public:
	void onUpdate(float dt) override;
	PlayerShuriken();
	~PlayerShuriken();
};

