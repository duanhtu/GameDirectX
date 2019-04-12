#pragma once
#include<Windows.h>
/* Frame bao gom lop RECT va anchor X va anchor y */
class FrameAnimation : public RECT
{
public:
	int anchorX, anchorY;
};
