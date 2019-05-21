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
	void clearGridRectObjects();
	GridRect();
	~GridRect();
};
