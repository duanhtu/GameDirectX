#include "PhysicsObject.h"
#include"SpriteManager.h"
#include"KEY.h"
#include "Delay.h"
#include "Ladder.h"

enum PLAYER_ACTION
{
	PLAYER_ACTION_STAND,
	PLAYER_ACTION_RUN,
	PLAYER_ACTION_JUMP,
	PLAYER_ACTION_SIT,
	PLAYER_ACTION_ATTACK,
	PLAYER_ACTION_ATTACK_SIT,
	PLAYER_ACTION_ATTACK_SURIKEN,
	PLAYER_ACTION_HURT,
	PLAYER_ACTION_CLIMB
};

enum PLAYER_STATE
{
	PLAYER_STATE_NORMAL,
	PLAYER_STATE_CLIMBING,
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
	bool isHit;
	void drawPlayerSword();
	void throwPlayerShuriken();
	boolean hasThrownShuriken;
	PLAYER_STATE playerState;
	boolean firstSecondClimb;
public:
	Ladder* currentLadder;
	Delay blinkDelay;
	boolean isUsingWeapon;
	static Player* getInstance();
	void onUpdate(float dt) override;
	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void setIsOnAttack(bool isOnAttack);
	void setIsOnAttackSuriken(bool isOnAttack);
	PLAYER_STATE getPlayerState();
	void setPlayerState(PLAYER_STATE playerState);
	Player();
	~Player();
};

