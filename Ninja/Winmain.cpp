#include<Windows.h>
#include"WindowGame.h"
#include"GameDirectX.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

#include"Game.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WindowGame::getInstance()->initHandleWindows(hInstance, nCmdShow);
			srand(time(NULL));
	/* GetTickCount: lay thoi gian hien tai cua he thong */
	/* Tinh thoi gian bat dau */
	DWORD startTime = GetTickCount();
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	/*Tinh thoi gian cho moi frame*/
	DWORD timePerFrame = 1000 / GLOBALS_D("fps");
	Game::getInstance()->GameInit();
	//b1. Tao bien imageGame va khoi tao hinh


	/* vong lap game*/
	while (msg.message != WM_QUIT)
	{
		/* now la thoi gian hien tai*/
		DWORD now = GetTickCount();
		/* neu khoang thoi gian ke tu luc bat dau toi bay gio lon hon thoi gian cho moi frame thi khoi tao lai thoi gian bat dau la bay gio */
		DWORD deltaTime = now - startTime;
		if (deltaTime >= timePerFrame)
		{    
			/* time : thoi gian giua 2 frame dung de tinh van toc doi tuong */
			

			Game::getInstance()->GameUpdate();

			startTime = now;
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			GameDirectX::getInstance()->BeginGraphics();//bat dau ve len backbuffer

			Game::getInstance()->GameRender();

			GameDirectX::getInstance()->EndGraphics();//ket thuc ve len backbuffer
			GameDirectX::getInstance()->PresentBackBuffer();//ve backbuffer len man hinh
		}
	}
	return nCmdShow;
}