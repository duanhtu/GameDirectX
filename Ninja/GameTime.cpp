#include "GameTime.h"
GameTime::GameTime(void)
{
}
GameTime::GameTime(DWORD tickPerFrame)
{
	this->tickPerFrame = tickPerFrame;
}
bool GameTime::atTime()
{
	/* Lay thoi gian hien tai */
	DWORD now = GetTickCount();
	/* Tinh thoi gian tu bay gio toi luc bat dau */
	deltaTime = now - startTime;
	/*  Neu khoang thoi gian do lon hon thoi gian cho truoc */
	if (deltaTime >= tickPerFrame)
	{
		startTime = GetTickCount();
		/* Tra ra ket qua dung */
		return true;
	}
	/* chua toi thoi gian tra ra ket qua sai */
	return false;
}
GameTime::~GameTime(void)
{
}
DWORD GameTime::getStartTime()
{
	return startTime;
}
void GameTime::setStartTime(DWORD startTime)
{
	this->startTime = startTime;
}
DWORD GameTime::getTickPerFrame()
{
	return tickPerFrame;
}
void GameTime::setTickPerFrame(DWORD tickPerFrame)
{
	this->tickPerFrame = tickPerFrame;
}
void GameTime::init(DWORD tickPerFrame)
{
	setTickPerFrame(tickPerFrame);
}
DWORD GameTime::getDeltaTime()
{
	return deltaTime;
}
void GameTime::setDeltaTime(DWORD deltaTime)
{
	this->deltaTime = deltaTime;
}