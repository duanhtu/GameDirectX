#pragma once
#include "Weapon.h"

class BossExplosion :
	public Weapon
{
public:
	BossExplosion();
	void render(Camera* camera) override;
};