#pragma once
#include"BaseObject.h"
enum BIRD_ACTION
{
	BIRD_ACTION_FLY,
};
class Bird :
	public BaseObject
{
public:
	void onUpdate(float dt) override;
	void onIntersect(MovableRect* other) override;
	Bird();
	~Bird();
};
