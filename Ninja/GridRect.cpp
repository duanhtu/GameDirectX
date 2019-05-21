#include "GridRect.h"
#include "Camera.h"
#include "Collision.h"

List<BaseObject*> GridRect::getGridRectObjects()
{
	return gridRectObjects;
}

void GridRect::addObjectToProperGridRect(List<GridRect*>& allGridRects, BaseObject* object)
{
	float objectXBottom = object->getX() + object->getWidth();
	float objectYBottom = object->getY() + object->getHeight();
	for (size_t i = 0; i < allGridRects.Count; i++) {
		float rectXBottom = allGridRects.at(i)->getX() + allGridRects.at(i)->getWidth();
		float rectYBottom = allGridRects.at(i)->getY() + allGridRects.at(i)->getHeight();
		if (object->getX() >= allGridRects.at(i)->getX()
			&& object->getY() >= allGridRects.at(i)->getY()
			&& objectXBottom <= rectXBottom
			&& objectYBottom <= rectYBottom
			)
		{
			allGridRects.at(i)->getGridRectObjects()._Add(object);
			break;
		}
	}
}

List<BaseObject*> GridRect::getCollisionObjects(List<GridRect*> allGridRects)
{
	List<BaseObject*> collisionObjects;
	for (size_t i = 0; i < allGridRects.Count; i++)
	{
		if (Collision::AABBCheck(allGridRects.at(i), Camera::getInstance()))
		{
			for (size_t j = 0; i < allGridRects.at(i)->getGridRectObjects().Count; i++)
			{
				collisionObjects._Add(allGridRects.at(i)->getGridRectObjects().at(j));
			}
		}
	}
	return collisionObjects;
}

void GridRect::addObject(BaseObject* object)
{
	gridRectObjects._Add(object);
}


GridRect::GridRect()
{
}

GridRect::~GridRect()
{
}