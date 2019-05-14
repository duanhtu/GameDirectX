#include "KEY.h"

DWORD getKeyChar(char keyChar)
{
	return ((int)keyChar - 'a') + 0x41;
}

KEY * KEY::instance = 0;
KEY * KEY::getInstance()
{
	if (instance == 0)
		instance = new KEY();
	return instance;
}

void KEY::update()
{
	isUpDown = GetAsyncKeyState(VK_UP);
	isLeftDown = GetAsyncKeyState(VK_LEFT);
	isRightDown = GetAsyncKeyState(VK_RIGHT);

	isDownDown = GetAsyncKeyState(VK_DOWN);
	isDownPress = isDownDown && !isPreviousDownDown;
	isPreviousDownDown = isDownDown;

	isJumpDown = GetAsyncKeyState(getKeyChar('x'));
	isJumpPress = (isPreviousJumpDown == false && isJumpDown == true);
	isPreviousJumpDown = isJumpDown;

	isAttackDown = GetAsyncKeyState(getKeyChar('z'));
	isAttackPress = isAttackDown && !isPreviousAttackDown;
	isPreviousAttackDown = isAttackDown;

	isAttackSurikenDown = GetAsyncKeyState(getKeyChar('c'));
}

KEY::KEY()
{
}


KEY::~KEY()
{
}
