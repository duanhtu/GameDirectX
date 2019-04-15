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
		/* sẽ bằng true nếu bạn giữ key jump */
		isJumpDown,
		isPreviousJumpDown,
		/* sẽ bằng true nếu bạn chỉ nhấn key jump lần đầu. nếu lần sau vẫn giữ key jump thì nó sẽ là false */
		isJumpPress;

	static KEY* instance;
	static KEY* getInstance();

	void update();

	KEY();
	~KEY();
};

