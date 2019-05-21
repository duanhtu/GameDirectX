#pragma once
#include"Tilemap.h"
#include"SpriteManager.h"
#include"BaseObject.h"
#include"CollisionTypeCollide.h"
#include "GridRect.h"
#include "Grid.h"

class World
{
	Tilemap tilemap;
	List<BaseObject*> allObjects;
	List<CollisionTypeCollide*> collisionTypeCollides;
	Grid grid;

public:
	void Init(const char* tilesheetPath, 
		const char* matrixPath, 
		const char* objectsPath, 
		const char* collisionTypeCollidePath,
		const char* gridPath);
	void Init(const char* folderPath);
	void update(float dt);
	void render();
	World();
	~World();
};


