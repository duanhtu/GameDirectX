#include "Camera.h"
#include <d3dx9.h>
#include "Player.h"
#include "Game.h"

Camera * Camera::instance = 0;
Camera * Camera::getInstance()
{
	if (instance == 0)
	{
		instance = new Camera();
	}
	return instance;
}
void Camera::convertWorldToView(float xWorld, float yWorld, float & xView, float & yView)
{
	D3DXMATRIX matrixWorldToView;
	D3DXMatrixIdentity(&matrixWorldToView);
	matrixWorldToView._22 = -1;
	matrixWorldToView._41 = -this->getX();
	matrixWorldToView._42 = this->getY();
	D3DXVECTOR3 pos3(xWorld, yWorld, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrixWorldToView);

	xView = MatrixResult.x;
	yView = MatrixResult.y;


}

void Camera::update()
{
	setDx(0);

	Player* player = Player::getInstance();
	if (player->getDx() < 0 && getMidX() > player->getMidX())
	{
		setDx(player->getDx());
	}
	if (player->getDx() > 0 && getMidX() < player->getMidX())
	{
		setDx(player->getDx());
	}
	int currentStageX = Game::getInstance()->getCurrentWorld()->getStageX();
	int currentStageWidth = Game::getInstance()->getCurrentWorld()->getStageWidth();
	if (getX() + getDx() < currentStageX && getDx() < 0)
	{
		setX(currentStageX);
		setDx(0);
	}
	if (getRight() + getDx() > currentStageX + currentStageWidth && getDx() > 0)
	{
		setX(currentStageX + currentStageWidth - getWidth());
		setDx(0);
	}
	if (player->getX() + player->getDx() < currentStageX && player->getDx() < 0)
	{
		player->setX(currentStageX);
		player->setDx(0);
	}
	if (player->getRight() + player->getDx() > currentStageX + currentStageWidth && player->getDx() > 0)
	{
		player->setX(currentStageX + currentStageWidth - player->getWidth());
		player->setDx(0);
	}
	goX();
	goY();
}

Camera::Camera()
{
}
Camera::~Camera()
{
}
