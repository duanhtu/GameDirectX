#pragma once
#include "GameTexture.h"
#include "List.h"
#include "GameTime.h"
#include "FrameAnimation.h"
#include "Animation.h"
#include "Tilemap.h"
#include "Sprite.h"
#include"World.h"

class Game
{
	static Game* instance;	
	World** worlds;
	Tilemap* tilemap;
	int currentWorldIndex;

public:
	static Game* getInstance();
	void GameInit();
	void GameUpdate(float dt);
	void GameRender();
	World* getCurrentWorld();
	int getCurrentWorldIndex();
	void goToTheNextStage();
	Game();
	~Game();
};
