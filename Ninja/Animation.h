#pragma once
#include"List.h"
#include"FrameAnimation.h"

class Animation
{
public:
	/* Danh sach frame */
	List<FrameAnimation*> frames;
	/* Chuyen sang frame ke khi truyen vao current frame */
	int NextFrame(int currentFrame);
	 Animation();
	~Animation();
};