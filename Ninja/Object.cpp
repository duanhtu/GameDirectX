#include "Object.h"

CObject::CObject()
{
//	this->cLink = NULL;
	this->fSpeed = 0;
	this->fX = 10;
	this->fY = 10;

	this->fW = 0;
	this->fH = 0;

	this->fVx = 0;
	this->fVy = 0;
	
	this->iState = 1;
	this->isMoving = 0;
}


CObject::~CObject()
{
	delete GSObject;
	delete GTObject;
}

void CObject::MoveLeft()
{

	if (isJumping == 1)
	{
		isMoving = 0;
		return;
	}
	this->iJump = 4;
	fVx = (isAttacking == 1) ? 0 : fSpeed;
	this->isMoving = 1;
	this->iState = -1;
}

void CObject::MoveRight()
{
	if (isJumping == 1)
	{
		isMoving = 0;
		return;
	}
	this->iJump = 3;
	fVx = (isAttacking == 1) ? 0 : fSpeed;
	this->isMoving = 1;
	this->iState = 1;
}

void CObject::Stop()
{
	this->fVx = 0;
	this->isMoving = 0;
	//this->isSitting = 0;
	//this->iState = 0;
}

void CObject::Move()
{
	if (iState == -1) this->MoveLeft();
	else this->MoveRight();
}

void CObject::SitDown()
{
	if (isJumping)return;
	this->isSitting = 1;
	Cohieu = 2;
}
void CObject::Jump()
{
	isJumping = 1;
	Cohieu = 3;
	if (isSitting)return;
}
void CObject::Fall()
{
	isFalling = 1;
	//iJumping = 0;
}
void CObject::StandUp()
{
	//this->fVx = 0;
	this->isSitting = 0;
	Cohieu = 1;
}

void CObject::Attack()
{
	//if (isAttacking)return;
	//if (isJumping)return;
	isAttacking = 1;
	switch (Cohieu)
	{
	case 1:
		GSObject->_index = 5;
		break;
	case 2:
		GSObject->_index = 15;
		break;
	case 3:
		GSObject->_index = 18;
		break;
	default:
		break;
	}
}


void CObject::Update(int t)
{

}

void CObject::Draw(GCamera* cam)
{

}