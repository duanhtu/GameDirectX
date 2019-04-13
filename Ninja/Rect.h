#pragma once
class Rect
{
	/* x y width height cua doi tuong */
	float x, y, width, height;
public:
	/* di chuyen hinh chu nhat theo phuong x 1 khoang dx */
	void moveX(float dx);
	/* di chuyen hinh chu nhat theo phuong y 1 khoang dy */
	void moveY(float dy);
	/* di chuyen hinh chu nhat theo 2 phuong */
	void move(float dx, float dy);
	/* get set phuong thuc */
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	virtual void setX(float x);
	virtual void setY(float y);
	virtual void setWidth(float width);
	virtual void setHeight(float height);
	void setLocation(float x, float y);
	void setSize(float width, float height);
	void set(float x, float y, float width, float height);
	/* lay ra cac phuong left right top bottom cua hinh chu nhat xem phuong thuc dinh nghia Rect.cpp se hieu */
	float getleft();
	float getRight();
	float getTop();
	float getBottom();
	/* vi tri giua cua Rect */
	float getMidX();
	float getMidY();
	Rect();
	virtual ~Rect();
};
