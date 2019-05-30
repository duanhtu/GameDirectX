#include "PhysicsObject.h"
#include"SpriteManager.h"
#include"KEY.h"
#include "Delay.h"

enum PLAYER_ACTION
{
	PLAYER_ACTION_STAND,
	PLAYER_ACTION_RUN,
	PLAYER_ACTION_JUMP,
	PLAYER_ACTION_SIT,
	PLAYER_ACTION_ATTACK,
	PLAYER_ACTION_ATTACK_SIT,
	PLAYER_ACTION_ATTACK_SURIKEN
};

class Player :
	public PhysicsObject
{
	static Player* instance;
	bool isOnAttack;
	bool isOnAttackSuriken;
	Delay invisibleDelay;
	GameTime invisibleTime;
	GameTime blinkTime;
	Delay blinkDelay;
	bool isHit;
	void drawPlayerSword();
public:
	static Player* getInstance();
	void onUpdate(float dt) override;
	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void setIsOnAttack(bool isOnAttack);
	void setIsOnAttackSuriken(bool isOnAttack);
	Player();
	~Player();
};

