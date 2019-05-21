#include "Grid.h"
#include "Collision.h"


void Grid::Init(const char* gridPath)
{
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

void Grid::addObjectToProperGridRect(BaseObject* object, int worldHeight)
{
	float objectXBottom = object->getX() + object->getWidth();
	float realYTop = worldHeight - object->getY();
	float objectYBottom = realYTop + object->getHeight();
	for (size_t j = 0; j < allGridRects.Count; j++) {
		float rectXBottom = allGridRects.at(j)->getX() + allGridRects.at(j)->getWidth();
		float rectYBottom = allGridRects.at(j)->getY() + allGridRects.at(j)->getHeight();
		if ((object->getX() >= allGridRects.at(j)->getX() && realYTop >= allGridRects.at(j)->getY())
			&& ( (objectXBottom <= rectXBottom && objectYBottom <= rectYBottom) 
				|| (object->getX() < rectXBottom && object->getY() < rectYBottom))
			)
		{
			allGridRects.at(j)->addObject(object);
			break;
		}
	}
}

List<BaseObject*> Grid::getCollisionObjects()
{
	objectCategories.Clear();
	for (size_t i = 0; i < COLLISION_TYPE_COUNT; i++)
	{
		objectCategories._Add(new List<BaseObject*>());
	}
	List<BaseObject*> collisionObjects;
	for (size_t i = 0; i < allGridRects.Count; i++)
	{
		if (Collision::AABBCheck(allGridRects.at(i), Camera::getInstance()))
		{
			for (size_t j = 0; j < allGridRects.at(i)->getGridRectObjects().Count; j++)
			{
				collisionObjects._Add(allGridRects.at(i)->getGridRectObjects().at(j));
				objectCategories.at(allGridRects.at(i)->getGridRectObjects().at(j)->getCollisionType())->_Add(allGridRects.at(i)->getGridRectObjects().at(j));
			}
		}
	}
	return collisionObjects;
}

List<List<BaseObject*>*> Grid::getObjectCategories()
{
	return objectCategories;
}

void Grid::clearAllGridRectObjects()
{
	for (size_t i = 0; i < allGridRects.Count; i++)
	{
		allGridRects.at(i)->clearGridRectObjects();
	}
}

Grid::Grid()
{
}

Grid::~Grid()
{
}