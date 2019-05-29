#include "Delay.h"


void Delay::start(DWORD time)
{
	ready = false;
	terminated = false;
	startTime = GetTickCount();
	if (time != (DWORD)-1)
	{
		init(time);
	}
}

void Delay::init(DWORD time)
{
	tickPerFrame = time;
}

Delay::Delay()
{
	ready = true;
	terminated = false;
}

bool Delay::isTerminated()
{
	if (terminated)
	{
		ready = true;
		terminated = false;
		return true;
	}
	return false;
}
void Delay::setIsTerminated(bool isTerminated)
{
	terminated = isTerminated;
}
bool Delay::isOnTime()
{
	return !terminated && !ready;
}
void Delay::update()
{
	if (isOnTime())
	{
		DWORD now = GetTickCount();
		DWORD deltaTime = now - startTime;
		if (deltaTime >= tickPerFrame)
		{
			terminated = true;
		}
	}

}

Delay::~Delay()
{
}
