#pragma once
#include"PhysicsObject.h"
#include"List.h"

class Weapon :
	public PhysicsObject
{
	static List<Weapon*>* allCurrentWeapons;
	bool removed;
public:
	static List<Weapon*>* getAllCurrentWeapons();
	static void updateCurrentWeapons();
	void Weapon::remove();
	Weapon();
	~Weapon();
};


