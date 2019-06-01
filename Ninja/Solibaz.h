#pragma once
#include "Enemy.h"
enum SOLIBAZ_STATE
{
   SOLIBAZ_STATE_INVISIBLE,
   SOLIBAZ_STATE_VISIBLE
};
enum SOLIBAZ_ACTION
{
	SOLIBAZ_ACTION_ATTACK,
};
class Solibaz :
	public Enemy
{
	SOLIBAZ_STATE solibazState;
	GameTime fireTime;
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void onUpdate(float dt) override;
	void setSolibazState(SOLIBAZ_STATE solibazState);
	void onInit(ifstream& fs) override;
	Solibaz();
	~Solibaz();

};