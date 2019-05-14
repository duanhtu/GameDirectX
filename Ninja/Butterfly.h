#pragma once
#pragma once
#include "BaseObject.h"
enum BUTTERFLY_ACTION
{
	BUTTERFLY_ACTION_FLY,
};

class Butterfly :
	public BaseObject
{
public:
	void onUpdate(float dt) override;
	Butterfly();
	~Butterfly();
};

