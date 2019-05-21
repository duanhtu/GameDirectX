#include "GridRect.h"
#include "Camera.h"
#include "Collision.h"

List<BaseObject*> GridRect::getGridRectObjects()
{
	return gridRectObjects;
}

void GridRect::addObject(BaseObject* object)
{
	gridRectObjects._Add(object);
}

void GridRect::clearGridRectObjects()
{
	gridRectObjects.Clear();
}

GridRect::GridRect()
{
}

GridRect::~GridRect()
{
}