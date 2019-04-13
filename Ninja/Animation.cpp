#include "Animation.h"
int Animation::NextFrame(int currentFrame)
{
	/* Vi du co 4 frame thi dam bao currentFrame chi trong 0 1 2 3 va khong the vuot qua 4*/
	if (currentFrame >= frames.size() - 1)
	{
		/* Neu vuot qua thi quay lai frame dau */
		return 0;
	}
     /* Neu chua toi 4 frame thi chuyen qua frame ke */
	return currentFrame + 1;
}
Animation::Animation()
{
}
Animation::~Animation()
{
}