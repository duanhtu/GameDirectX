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

	for (size_t i = 0; i < COLLISION_TYPE_COUNT; i++)
	{ 
		objectCategories._Add(new List<BaseObject*>());
	}

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
		objectCategories.at(obj->getCollisionType())->_Add(obj);
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
	ifstream fsGrid(gridPath);
	int numberGridRect;
	float widthGirdRect, heightGridRect;
	fsGrid >> numberGridRect >> widthGirdRect >> heightGridRect;
	for (size_t i = 0; i < numberGridRect; i++)
	{
		float x, y;
		fsGrid >> x >> y;
		GridRect* gridRect = new GridRect();
		gridRect->set(x, y, widthGirdRect, heightGridRect);
		allGridRects._Add(gridRect);
	}
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
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		//GridRect::addObjectToProperGridRect(allGridRects,allObjects[i]);
		float objectXBottom = allObjects[i]->getX() + allObjects[i]->getWidth();
		float realY = worldHeight - allObjects[i]->getY();
		float objectYBottom =  realY + allObjects[i]->getHeight();
		for (size_t j = 0; j < allGridRects.Count; j++) {
			float rectXBottom = allGridRects.at(j)->getX() + allGridRects.at(j)->getWidth();
			float rectYBottom = allGridRects.at(j)->getY() + allGridRects.at(j)->getHeight();
			if (allObjects[i]->getX() >= allGridRects.at(j)->getX()
				&& realY >= allGridRects.at(j)->getY()
				&& objectXBottom <= rectXBottom
				&& objectYBottom <= rectYBottom
				)
			{
				//allGridRects.at(i)->getGridRectObjects()._Add(allObjects[i]);
				allGridRects.at(j)->addObject(allObjects[i]);
				break;
			}
		}
	}
	
	//List<BaseObject*> collisionObjects = GridRect::getCollisionObjects(allGridRects);
	List<BaseObject*> collisionObjects;
	for (size_t i = 0; i < allGridRects.Count; i++)
	{
		if (Collision::AABBCheck(allGridRects.at(i), Camera::getInstance()))
		{
			for (size_t j = 0; j < allGridRects.at(i)->getGridRectObjects().Count; j++)
			{
				collisionObjects._Add(allGridRects.at(i)->getGridRectObjects().at(j));
			}
	}
	}
	for (size_t i = 0; i < collisionObjects.Count; i++)
	{
		collisionObjects[i]->update(dt);
		Collision::CheckCollision(Player::getInstance(), collisionObjects[i]);
	}
	for (size_t i = 0; i < collisionTypeCollides.size(); i++)
	{
		COLLISION_TYPE col1 = collisionTypeCollides.at(i)->COLLISION_TYPE_1;
		COLLISION_TYPE col2 = collisionTypeCollides.at(i)->COLLISION_TYPE_2;

		List<BaseObject*>* collection1 = objectCategories.at(col1);
		List<BaseObject*>* collection2 = objectCategories.at(col2);

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
