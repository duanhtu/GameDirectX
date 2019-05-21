#include "World.h"
#include"Camera.h"
#include"Player.h"
#include"Samurai.h"
#include"KEY.h"
#include "Collision.h"
#include"Cheetah.h"
#include"Hawl.h"
#include"Butterfly.h"
#include"Death.h"
#include"Solicol.h"
#include "GridRect.h"

void World::Init(const char * tilesheetPath, const char * matrixPath, const char * objectsPath,const char * collisionTypeCollidePath, const char* gridPath)
{
	Player::getInstance()->set(64, 100, 16, 32);

	tilemap.Init(tilesheetPath, matrixPath);

	int worldHeight = tilemap.getWorldHeight();

	int objectCount;
	ifstream fs(objectsPath);
	fs >> objectCount;
	for (size_t i = 0; i < objectCount; i++)
	{
		BaseObject* obj;
		int id;
		fs >> id;
		switch (id)
		{

		case SPRITE_INFO_SAMURAI:
			obj = new Samurai();
			break;
		
		case SPRITE_INFO_CHEETAH:
			obj = new Cheetah();
			break;

		case SPRITE_INFO_HAWL:
			obj = new Hawl(worldHeight);
			break;

		case SPRITE_INFO_BUTTERFLY:
			obj = new Butterfly();
			break;

		case SPRITE_INFO_DEATH:
			obj = new Death();
			break;
		case SPRITE_INFO_SOLICOL:
			obj = new Solicol();
			break;

		default:
			obj = new BaseObject();
			break;
		}
		obj->onInitFromFile(fs, worldHeight);
		if (id >= 0)
		{
			obj->setSprite(SPR(id));
		}
		allObjects._Add(obj);
	}
	int numberOfCollisionTypeCollides = 0;
	ifstream fsColli(collisionTypeCollidePath);
	fsColli >> numberOfCollisionTypeCollides;
	for (size_t i = 0; i < numberOfCollisionTypeCollides; i++)
	{
		int collisionType1, collisionType2;
		fsColli >> collisionType1 >> collisionType2;
		CollisionTypeCollide* collisionTypeCollide = new CollisionTypeCollide();
		collisionTypeCollide->COLLISION_TYPE_1 = (COLLISION_TYPE)collisionType1;
		collisionTypeCollide->COLLISION_TYPE_2 = (COLLISION_TYPE)collisionType2;
		collisionTypeCollides._Add(collisionTypeCollide);
	}
	grid.Init(gridPath);
}

void World::Init(const char * folderPath)
{
	string folderPathString = (string)folderPath;
	string tilesheetString = folderPathString;
	tilesheetString.append("/tilesheet.png");
	string matrixPathString = folderPathString;
	matrixPathString.append("/matrix.dat");
	string objectPathString = folderPathString;
	objectPathString.append("/objects.dat");
	string collisionTypeCollidePath = folderPathString;
	collisionTypeCollidePath.append("/collision_type_collides.dat");
	string gridPath = folderPathString;
	gridPath.append("/grid.txt");
	Init(tilesheetString.c_str(), matrixPathString.c_str(), objectPathString.c_str(),collisionTypeCollidePath.c_str(), gridPath.c_str());
}

void World::update(float dt)
{

	KEY::getInstance()->update();
	int worldHeight = tilemap.getWorldHeight();
	grid.clearAllGridRectObjects();
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		grid.addObjectToProperGridRect(allObjects[i], worldHeight);
	}
	List<BaseObject*> collisionObjects = grid.getCollisionObjects();
	for (size_t i = 0; i < collisionObjects.Count; i++)
	{
		collisionObjects[i]->update(dt);
		Collision::CheckCollision(Player::getInstance(), collisionObjects[i]);
	}

	for (size_t i = 0; i < collisionTypeCollides.size(); i++)
	{
		COLLISION_TYPE col1 = collisionTypeCollides.at(i)->COLLISION_TYPE_1;
		COLLISION_TYPE col2 = collisionTypeCollides.at(i)->COLLISION_TYPE_2;
		List<BaseObject*>* collection1 = grid.getObjectCategories().at(col1);
		List<BaseObject*>* collection2 = grid.getObjectCategories().at(col2);

		for (size_t i1 = 0; i1 < collection1->size(); i1++)
		{
			for (size_t i2 = 0; i2 < collection2->size(); i2++)
			{
				Collision::CheckCollision(collection1->at(i1), collection2->at(i2));
			}
		}

	}
	Player::getInstance()->update(dt);
	Camera::getInstance()->update();
}


void World::render()
{
	tilemap.render(Camera::getInstance());
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		allObjects[i]->render(Camera::getInstance());
	}
	Player::getInstance()->render(Camera::getInstance());
}

World::World()
{
}
World::~World()
{
}
