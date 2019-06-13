#include "ScoreBoard.h"
#include"Player.h"

#define NUMBER_WIDTH 8
#define HEALTH_WIDTH 4
void ignoreLineIfstream(ifstream & fs, int lineCount);


void ScoreBoard::renderNumber(int num, int x, int y, int maxLength)
{
	int currentX = x + NUMBER_WIDTH * maxLength;
	int length = 0;
	while (num)
	{
		currentX -= NUMBER_WIDTH;
		int val = num % 10;
		miscSprite->render(currentX, y, MISC_SPRITE_ID_NUMBER, val);
		num /= 10;
		length++;
	}
	for (; length < maxLength; length++)
	{
		currentX -= NUMBER_WIDTH;
		miscSprite->render(currentX, y, MISC_SPRITE_ID_NUMBER, 0);
	}
}

void ScoreBoard::renderHealth()
{
	int healthLost = maxHealth - health;
	int lastLocationXHealth = healthLocation.X + HEALTH_WIDTH * maxHealth - HEALTH_WIDTH;
	for (size_t i = 0; i < healthLost; i++)
	{
		miscSprite->render(lastLocationXHealth, healthLocation.Y, MISC_SPRITE_ID_LOST_HEALTH, 0);
		lastLocationXHealth -= HEALTH_WIDTH;
	}
}

void ScoreBoard::renderBossHealth()
{
	int healthLost = maxHealth - bossHealth;
	if (healthLost > maxHealth)
	{
		healthLost = maxHealth;
	}
	int lastLocationXHealth = bossHealthLocation.X + HEALTH_WIDTH * maxHealth - HEALTH_WIDTH;
	for (size_t i = 0; i < healthLost; i++)
	{
		miscSprite->render(lastLocationXHealth, bossHealthLocation.Y, MISC_SPRITE_ID_LOST_HEALTH, 0);
		lastLocationXHealth -= HEALTH_WIDTH;
	}
}

ScoreBoard* ScoreBoard::instance = 0;
ScoreBoard* ScoreBoard::getInstance()
{
	if (instance == 0)
		instance = new ScoreBoard();
	return instance;
}

ScoreBoard::ScoreBoard()
{
	scoreBoard = new GameTexture("assets/sprites/misc/score_bar.png", D3DCOLOR_XRGB(10, 20, 60));
	miscSprite = SpriteManager::getInstance()->getSprite(SPRITE_MISC);
	shurikenSprite = SpriteManager::getInstance()->getSprite(SPRITE_INFO_ITEM_BIGSHURIKEN);
	timeGame.init(1000);

	ifstream ifs("assets/sprites/misc/score_bar_item_location.txt");
	ignoreLineIfstream(ifs, 1);
	ifs >> lifeLocation.X >> lifeLocation.Y >> lifeLocation.MaxLength;
	setPlayerLife(2);
	setScore(0);

	ignoreLineIfstream(ifs, 2);
	ifs >> heartLocation.X >> heartLocation.Y >> heartLocation.MaxLength;
	setHeartCount(5);

	ignoreLineIfstream(ifs, 2);
	ifs >> stageLocation.X >> stageLocation.Y >> stageLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> scoreLocation.X >> scoreLocation.Y >> scoreLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> timeLocation.X >> timeLocation.Y >> timeLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> healthLocation.X >> healthLocation.Y >> maxHealth;

	ignoreLineIfstream(ifs, 2);
	ifs >> subWeaponLocation.X >> subWeaponLocation.Y;

	ignoreLineIfstream(ifs, 2);
	ifs >> bossHealthLocation.X >> bossHealthLocation.Y >> bossHealthLocation.MaxLength;

	setHealth(maxHealth);
	setBossHealth(maxHealth);
	setTime(400);
	gameOver = false;
}


ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::render()
{
	scoreBoard->Render(0, 0, 0, 0);
	renderNumber(getPlayerLife(), lifeLocation.X, lifeLocation.Y, lifeLocation.MaxLength);
	//renderNumber(getHeartCount(), heartLocation.X, heartLocation.Y, heartLocation.MaxLength);
	renderNumber(currentStageNumber, stageLocation.X, stageLocation.Y, stageLocation.MaxLength);
	renderNumber(score, scoreLocation.X, scoreLocation.Y, scoreLocation.MaxLength);
	renderNumber(time, timeLocation.X, timeLocation.Y, timeLocation.MaxLength);
	renderHealth();
	renderBossHealth();
	renderSubWeapon();
}

void ScoreBoard::update()
{ 
	if (getTime() > 0)
	{
		if (!gameOver)
		{
			if (timeGame.atTime())
			{
				increaseTime(-1);
			}
		}
		else
		{
			timeGame.init(50);
			if (timeGame.atTime())
			{
				increaseTime(-1);
				setScore(getScore() + 100);
			}
		}
	}

}


void ScoreBoard::restoreHealth()
{
	setHealth(maxHealth);
}

void ScoreBoard::restoreBossHealth()
{
	setBossHealth(maxHealth);
}

int ScoreBoard::getPlayerLife()
{
	return playerLife;
}

void ScoreBoard::setPlayerLife(int playerLife)
{
	if (playerLife >= 0)
		this->playerLife = playerLife;
}

void ScoreBoard::increasePlayerLife(int playerLife)
{
	setPlayerLife(this->playerLife + playerLife);
}

int ScoreBoard::getHeartCount()
{
	return heartCount;
}

void ScoreBoard::setHeartCount(int heartCount)
{
	this->heartCount = heartCount;
}

void ScoreBoard::increaseHeartCount(int heartCount)
{
	setHeartCount(this->heartCount + heartCount);
}

void ScoreBoard::setCurrentStageNumber(int currentStageNumber)
{
	this->currentStageNumber = currentStageNumber;
}

int ScoreBoard::getScore()
{
	return score;
}
void ScoreBoard::setScore(int score)
{
	this->score = score;
}
void ScoreBoard::increaseScore(int score)
{
	this->score += score;
}

int ScoreBoard::getTime()
{
	return time;
}
void ScoreBoard::setTime(int time)
{
	if (time >= 0)
		this->time = time;
}
void ScoreBoard::increaseTime(int time)
{
	setTime(this->time + time);
}

int ScoreBoard::getHealth()
{
	return health;
}
void ScoreBoard::setHealth(int health)
{
	if (health >= 0)
		this->health = health;
}
void ScoreBoard::increaseHealth(int health)
{
	setHealth(this->health + health);
}

int ScoreBoard::getBossHealth()
{
	return bossHealth;
}
void ScoreBoard::setBossHealth(int health)
{
	this->bossHealth = health;
}
void ScoreBoard::increaseBossHealth(int health)
{
	setBossHealth(bossHealth + health);
}

int ScoreBoard::getMaxHealth()
{
	return maxHealth;
}

void ScoreBoard::setUseSubWeapon(bool useSubWeapon)
{
	this->useSubWeapon = useSubWeapon;
}

bool ScoreBoard::getUseSubWeapon()
{
	return useSubWeapon;
}

void ScoreBoard::renderSubWeapon()
{
	if (this->useSubWeapon)
	{
		shurikenSprite->render(135, 16, 0, 0);
	}
}