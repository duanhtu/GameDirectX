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
	/* phương thức xử lý va chạm là phương thức ảo sẽ được mỗi đối tượng override để hiện thực */
	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny);
	/* phương thức xử lý va chạm chặn di chuyển khi phát hiện va chạm */
	void preventMovementWhenCollision(float collisionTime, int nx, int ny);
	MovableRect();
	~MovableRect();
};
