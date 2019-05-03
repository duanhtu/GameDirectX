﻿#pragma once
#include "PhysicsObject.h"
#include"SpriteManager.h"
#include"KEY.h"
enum PLAYER_ACTION
{
	PLAYER_ACTION_STAND,
	PLAYER_ACTION_RUN,
	PLAYER_ACTION_JUMP,
	PLAYER_ACTION_SIT,
	PLAYER_ACTION_ATTACK,
	PLAYER_ACTION_ATTACK_SIT
};

class Player :
	public PhysicsObject
{
	static Player* instance;
	bool isOnAttack;
public:
	static Player* getInstance();
	void onUpdate(float dt) override;
	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void setIsOnAttack(bool isOnAttack);
	Player();
	~Player();
};

