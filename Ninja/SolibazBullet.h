
#pragma once
#include"Weapon.h"

class SolibazBullet
	: public Weapon
{
public:
	void onUpdate(float dt) override;
	SolibazBullet();
	~SolibazBullet();
};