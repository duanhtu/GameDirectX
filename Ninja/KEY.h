#pragma once
#include<Windows.h>
class KEY
{
public:
	bool
		isLeftDown,
		isRightDown,
		isUpDown,
		isDownDown,
		isJumpDown,
		isPreviousJumpDown,
		isJumpPress,
		isPreviousDownDown,
		isDownPress,
		isAttackDown,
		isAttackPress,
		isPreviousAttackDown;

	static KEY* instance;
	static KEY* getInstance();

	void update();

	KEY();
	~KEY();
};

