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
	worlds = new World*[2];
	worlds[0] = new World();
	worlds[0]->Init("assets/levels/level1");
	worlds[1] = new World();
	worlds[1]->Init("assets/levels/level2");
	Camera::getInstance()->set(
		0,
		200, 
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));
	currentWorldIndex = 0;
}
void Game::GameUpdate(float dt)
{
	if (GetAsyncKeyState(getKeyChar('q')))
	{
		currentWorldIndex = 1;
		Player::getInstance()->restoreLocation();
		Camera::getInstance()->setX(0);
		Camera::getInstance()->setY(200);
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
