#pragma once
#include"Weapon.h"

class SolicolBullet
	: public Weapon
{
public:
	void onUpdate(float dt) override;
	SolicolBullet();
	~SolicolBullet();
};

