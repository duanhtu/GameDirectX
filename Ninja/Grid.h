#include "GridRect.h"

class Grid
{
	List<GridRect*> allGridRects;
	List<List<BaseObject*>*> objectCategories;
public:
	void addObjectToProperGridRect(BaseObject* object, int worldHeight);
	List<BaseObject*> getCollisionObjects();
	List<List<BaseObject*>*> getObjectCategories();
	void Init(const char* gridPath);
	void clearAllGridRectObjects();
	Grid();
	~Grid();
};
