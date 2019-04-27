#include "Game.h"


Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

void Game::GameInit()
{
	world = new World();
	world->Init("assets/levels/level1");
	Camera::getInstance()->set(
		0,
		200, 
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));
}
void Game::GameUpdate(float dt)
{
	world->update(dt);
}
void Game::GameRender()
{
	world->render();
}

Game::Game()
{
}


Game::~Game()
{
}
