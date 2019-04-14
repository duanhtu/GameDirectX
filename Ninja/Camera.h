#pragma once
#include "MovableRect.h"
/* camera la 1 hinh chu nhat co the di chuyen nen se ke thua lai lop MovableRect */
class Camera : public MovableRect
{
	static Camera* instance;
public:
	static Camera* getInstance();
	/* phuong thuc chuyen doi world  qua view
	   Tham so dau vao la xWorld  yWorld
	   Tham so can lay la xView yView (nen co dau &, can xem lai khai niem ve tham chieu c++ de hieu)
	   Phuong thuc nay trong sach game co gio sach ra xem se thay
	*/
	void convertWorldToView(float xWorld, float yWorld, float& xView, float& yView);
	void update();
	Camera();
	~Camera();
};
