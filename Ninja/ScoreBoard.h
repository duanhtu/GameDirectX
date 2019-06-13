#include"SpriteManager.h"
#include"GameTime.h"

struct SCORE_LOCATION
{
	int X;
	int Y;
	int MaxLength;
};

class ScoreBoard
{
	Sprite* miscSprite;
	Sprite* shurikenSprite;
	GameTexture* scoreBoard;
	void renderNumber(int num, int x, int y, int maxLength);
	void renderHealth();
	void renderBossHealth();
	static ScoreBoard* instance;
	SCORE_LOCATION lifeLocation;
	SCORE_LOCATION heartLocation;
	SCORE_LOCATION stageLocation;
	SCORE_LOCATION scoreLocation;
	SCORE_LOCATION timeLocation;
	SCORE_LOCATION healthLocation;
	SCORE_LOCATION subWeaponLocation;
	SCORE_LOCATION bossHealthLocation;

	int health;
	int bossHealth;
	int maxHealth;
	int playerLife;
	int heartCount;
	int currentStageNumber;
	int score;
	int time;
	GameTime timeGame;
	bool useSubWeapon;
public:
	bool gameOver;
	static ScoreBoard* getInstance();
	ScoreBoard();
	~ScoreBoard();
	void render();
	void update();


	void restoreHealth();
	void restoreBossHealth();

	int getPlayerLife();
	void setPlayerLife(int playerLife);
	void increasePlayerLife(int playerLife);

	int getHeartCount();
	void setHeartCount(int heartCount);
	void increaseHeartCount(int heartCount);

	int getScore();
	void setScore(int score);
	void increaseScore(int score);

	int getTime();
	void setTime(int time);
	void increaseTime(int time);

	int getHealth();
	void setHealth(int health);
	void increaseHealth(int health);

	int getBossHealth();
	void setBossHealth(int health);
	void increaseBossHealth(int health);

	int getMaxHealth();

	void setCurrentStageNumber(int currentStageNumber);

	void setUseSubWeapon(bool useSubWeapon);
	bool getUseSubWeapon();
	void renderSubWeapon();

};


