#include "Game.h"
#include "ScoreBoard.h"
#include "KEY.h"
#include "Player.h"

extern DWORD getKeyChar(char keyChar);

Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

void Game::GameInit()
{
	Camera::getInstance()->setSize(
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));
	worlds = new World*[3];
	worlds[0] = new World();
	worlds[0]->Init("assets/levels/level1");
	worlds[0]->setInformationStage(0, 2048);
	worlds[1] = new World();
	worlds[1]->Init("assets/levels/level2");
	worlds[1]->setInformationStage(0, 3072);
	worlds[2] = new World();
	worlds[2]->Init("assets/levels/level3");
	worlds[2]->setInformationStage(0, 257);
	currentWorldIndex = 0;
	worlds[currentWorldIndex]->resetCamera(10);
}
void Game::GameUpdate(float dt)
{
	if (GetAsyncKeyState(getKeyChar('a')))
	{
		currentWorldIndex = 0;
		worlds[currentWorldIndex]->resetCamera(10);
		Player::getInstance()->restoreLocation();
	}
	if (GetAsyncKeyState(getKeyChar('s')))
	{
		currentWorldIndex = 1;
		worlds[currentWorldIndex]->resetCamera(10);
		Player::getInstance()->restoreLocation();
	}
	if (GetAsyncKeyState(getKeyChar('d')))
	{
		currentWorldIndex = 2;
		worlds[currentWorldIndex]->resetCamera(40);
		Player::getInstance()->restoreLocation();
	}
	worlds[currentWorldIndex]->update(dt);
	ScoreBoard::getInstance()->update();
}
void Game::GameRender()
{
	worlds[currentWorldIndex]->render();
	ScoreBoard::getInstance()->render();
}

Game::Game()
{
}


Game::~Game()
{
}

World* Game::getCurrentWorld()
{
	return worlds[currentWorldIndex];
}

int Game::getCurrentWorldIndex()
{
	return currentWorldIndex;
}

void Game::goToTheNextStage()
{
	if (currentWorldIndex == 2)
	{
		return;
	}
	currentWorldIndex += 1;
	if (currentWorldIndex < 2)
	{
		worlds[currentWorldIndex]->resetCamera(10);
	}
	else
	{
		worlds[currentWorldIndex]->resetCamera(40);
	}
	Player::getInstance()->restoreLocation();
}
