#pragma once
#include"Tilemap.h"
#include"SpriteManager.h"
#include"BaseObject.h"
#include"CollisionTypeCollide.h"

class World
{
	Tilemap tilemap;

	List<BaseObject*> allObjects;

	List<CollisionTypeCollide*> collisionTypeCollides;
	List<List<BaseObject*>*> objectCategories;
	

public:
	void Init(const char* tilesheetPath, 
		const char* matrixPath, 
		const char* objectsPath, 
		const char* collisionTypeCollidePath);
	void Init(const char* folderPath);
	void update(float dt);


	void render();
	World();
	~World();
};


