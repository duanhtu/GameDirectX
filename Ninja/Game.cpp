#include "Game.h"
/* singleton pattern */
Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}
/* Cac cau lenh khoi tao game */
void Game::GameInit()
{
		
	/* khoi tao tilemap */
	tilemap = new Tilemap();
	tilemap->Init("test/demotile");
	Camera::getInstance()->set(
		0,
		200,
		/* kich thuoc cua camera bang kich thuoc cua backbuffer*/
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height")
		);
	/* di chuyen camera theo phuong phai 1 px */
Camera::getInstance()->setDx(1);
	/* khoi tao danh sach vi tri khung hinh */
	
}
/* Cac cau lenh cap nhat game */
void Game::GameUpdate()
{
	
	 /* di chuyen camera theo phuong x */
	Camera::getInstance()->goX();
	
}
/* Cac cau lenh ve cua game */
void Game::GameRender()
{

	/* ve tile len game */
	//tilemap->render(Camera::getInstance());
	tilemap->render(Camera::getInstance());
}
Game::Game()
{
}
Game::~Game()
{
}