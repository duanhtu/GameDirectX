#pragma once
#include "Rect.h"
#include"BaseObject.h"

class GridRect :
	public Rect
{
	List<BaseObject*> gridRectObjects;
public:
	List<BaseObject*> getGridRectObjects();
	void addObject(BaseObject* object);
	static void addObjectToProperGridRect(List<GridRect*> allGridRects, BaseObject* object);
	static List<BaseObject*> getCollisionObjects(List<GridRect*> allGridRects);
	GridRect();
	~GridRect();
};
