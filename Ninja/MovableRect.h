#pragma once
#include "Rect.h"

/* day la lop Rect co the di chuyen */
class MovableRect :
	public Rect
{
     /* do doi di chuyen cua doi tuong */
	float dx, dy;
public :
	virtual void setDx(float dx);
	virtual void setDy(float dy);
	float getDx();
	float getDy();
	/* phuong thuc di chuyen */
	void goX();
	void goY();
	MovableRect();
	~MovableRect();
};
