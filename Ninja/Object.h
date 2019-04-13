#pragma once
#include"GSprite.h"
#include"GCamera.h"
class CObject
{
protected:
	//char cLink;						//Đường dẫn file texture

	float fX;						//Vị trí giữa tâm simon theo trục ox
	float fY;						//Vị trí giữa tâm simon theo trục oy
	
	float fW;						//Chiều dài của box
	float fH;						//Chiều rộng của box

	float fVx;						//Vận tốc trên trục ox
	float fVy;						//Vận tốc trên trục oy
	float fSpeed;					//Tốc độ di chuyển của đối tượng

	int iState;						//Đối tượng đang quay mặt về hướng nào

	int isMoving;					//Đứng yên = 0, di chuyển = 1

	int isSitting;					//Đứng lên = 1, ngồi xuống = 0
	int isFalling;
	int isJumping;
	int iJump; // he so nhay
	
	int Cohieu;						//Biến cờ hiệu :nhan biet trang thai quat roi dung,ngoi,nhay

	int isAttacking;				//Đánh = 1, Không đánh = 0;
	
	GTexture* GTObject;
	GSprite* GSObject;

public:
	//===========================================
	//Hàm khởi tạo
	CObject();
	
	//===========================================	
	//Hàm hủy
	~CObject();	

	//===========================================
	//Hàm GET - SET
//	char getlink() { return this->cLink; }
	float getx() { return this->fX; }
	float gety() { return this->fY; }
	float getvx() { return this->fVx; }
	float getvy() { return this->fVy; }
	float getw() { return this->fW; }
	float getH() { return this->fH; }
	float getspeed() { return this->fSpeed; }
	int getstate(){ return this->iState; }
	int getmoving() { return this->isMoving; }
	int getsitting() { return this->isSitting; }

	//===========================================
	//void setlink(char l) { this->cLink = l; }
	void setx(float x1) { this->fX = x1; };
	void sety(float x1) { this->fY = x1; };
	void setvx(float x1) { this->fVx = x1; };
	void setvy(float x1) { this->fVy = x1; };
	void setW(float x1) { this->fW = x1; };
	void setH(float x1) { this->fH = x1; };
	void setspeed(float x1) { this->fSpeed = x1; };
	void setstate(int x1) { this->iState = x1; };
	void setmoving(int x1) { this->isMoving = x1; }
	void setsitting(int x1) { this->isSitting = x1; }
	int getattacking() { return this->isAttacking; }

	//===========================================
	void MoveLeft();
	void MoveRight();
	void Stop();
	void Move();
	void SitDown();
	void StandUp();
	void Attack();
	void Jump();
	void Fall();
	//===========================================
	//Các hàm Update, Draw
	virtual void Update(int t);
	virtual void Draw(GCamera* cam);

	//
	
};

