#pragma once
#include "Weapon.h"

class Explosion:
	public Weapon
{
public:
	Explosion();
	void onUpdate(float dt) override;
	void render(Camera* camera) override;
};
