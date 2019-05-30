#pragma once
#include "MovableRect.h"
#include"Sprite.h"
#include"GameTime.h"
#include"Camera.h"
#include"CollisionType.h"

class BaseObject :
	public MovableRect
{
	Sprite* sprite;
	int animationIndex, frameIndex;
	bool pauseAnimation;
	bool isLastFrameAnimationDone;
	TEXTTURE_DIRECTION direction;
	bool renderActive;
	Rect* initBox;
public:
	GameTime animationGameTime;
	void setSprite(Sprite*sprite);
	Sprite* getSprite();
	bool getPauseAnimation();
	virtual void setPauseAnimation(bool pauseAnimation);
	bool getIsLastFrameAnimationDone();
	virtual void setIsLastFrameAnimationDone(bool isLastFrameAnimationDone);
	virtual void onInitFromFile(ifstream& fs, int mapHeight);
	virtual void onInit(ifstream& fs);
	virtual void onUpdate(float dt);
	void update(float dt);
	virtual void render(Camera* camera);
	int getAnimation();
	void setAnimation(int animation);
	int getFrameAnimation();
	void setFrameAnimation(int frameAnimation);
	TEXTTURE_DIRECTION	getDirection();
	void setDirection(TEXTTURE_DIRECTION direction);
	void setRenderActive(bool renderActive);
	bool getRenderActive();
	Rect* getInitBox();
	void setInitBox(Rect* initBox);
	virtual void restoreLocation();
	BaseObject();
	~BaseObject();
};

