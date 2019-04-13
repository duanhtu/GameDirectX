#include "Game.h"


/* singleton pattern */
Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

/* Các câu lệnh khởi tạo game */
void Game::GameInit()
{
	/* khởi tạo tilemap */
	world = new World();
	world->Init("test/demoloadobject");
	Camera::getInstance()->set(
		0,
		400, /* y camera */
		/* kích thước của camera bằng với kích thước của backbuffer */
		GLOBALS_D("backbuffer_width"), 
		GLOBALS_D("backbuffer_height"));
}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate(float dt)
{
	/* cập nhật đối tượng trong world */
	world->update(dt);
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ đối tượng trong world */
	world->render();
}

Game::Game()
{
}


Game::~Game()
{
}
