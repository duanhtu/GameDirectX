#pragma once
#include "GameTexture.h"
/* include  de su dung  kieu danh sach*/
#include "List.h"
#include "GameTime.h"
#include "FrameAnimation.h"
#include "Animation.h"
#include "Tilemap.h"
#include "Sprite.h"
class Game
{
	/*single pattern*/
	static Game* instance;	

	Tilemap* tilemap;

public:
	static Game* getInstance();
	
	/*Cac cau lenh khoi tao game*/
	void GameInit();
	/*Cac cau lenh cap nhat game*/
	void GameUpdate();
	/*Cac cau lenh ve cua game*/
	void GameRender();
	Game();
	~Game();
};
