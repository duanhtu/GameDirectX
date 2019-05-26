#include "Weapon.h"
#include"Collision.h"
#include"Camera.h"

List<Weapon*>* Weapon::allCurrentWeapons = 0;
List<Weapon*>* Weapon::getAllCurrentWeapons()
{
	if (allCurrentWeapons == 0)
	{
		allCurrentWeapons = new List<Weapon*>();
	}
	return allCurrentWeapons;
}

void Weapon::updateCurrentWeapons()
{
	auto objs = getAllCurrentWeapons();
	for (int i = 0; i < objs->Count; i++)
	{
		auto obj = objs->at(i);
		if (!Collision::AABBCheck(Camera::getInstance(), obj))
		{
			getAllCurrentWeapons()->_Remove(obj);
			delete obj;
			i--;
		}
	}
}


Weapon::Weapon()
{
	getAllCurrentWeapons()->_Add(this);
}


Weapon::~Weapon()
{
}
