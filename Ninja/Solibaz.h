#pragma once
#include "Enemy.h"
#include "Delay.h"
enum SOLIBAZ_STATE
{
   SOLIBAZ_STATE_SIT,
   SOLIBAZ_STATE_ATTACK
};
enum SOLIBAZ_ACTION
{
	SOLIBAZ_ACTION_SIT,
	SOLIBAZ_ACTION_ATTACK,
};
class Solibaz :
	public Enemy
{
	SOLIBAZ_STATE solibazState;
	Delay fireDelay;
	GameTime fireTime;
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny)override;
	void onUpdate(float dt) override;
	void setSolibazState(SOLIBAZ_STATE solibazState);
	void backToTheFirstState() override;
	void onInit(ifstream& fs) override;
	Solibaz();
	~Solibaz();

};