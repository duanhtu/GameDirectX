#pragma once
#include<Windows.h>
class GameTime
{
	/* Thoi gian bat dau */
	DWORD startTime;
	/* Khoang thoi gian delay */
	DWORD tickPerFrame;
	/* Khoang thoi gian ke tu starttime toi bay gio */
	DWORD deltaTime;

public:
	DWORD getStartTime();
	void setStartTime(DWORD startTime);
	DWORD getTickPerFrame();
	void setTickPerFrame(DWORD tickPerFrame);
	/* khoi tao thoi gian delay	 */
	void init(DWORD tickPerFrame);
	DWORD getDeltaTime();
	void setDeltaTime(DWORD deltaTime);

	GameTime(void);
	~GameTime(void);

	GameTime(DWORD tickPerFrame);
	/* Toi thoi gian hien tai */
	virtual bool atTime();
};
