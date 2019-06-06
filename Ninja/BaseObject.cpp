#include "BaseObject.h"


void BaseObject::setSprite(Sprite * sprite)
{
	this->sprite = sprite;
}

Sprite * BaseObject::getSprite()
{
	return this->sprite;
}

bool BaseObject::getPauseAnimation()
{
	return pauseAnimation;
}

void BaseObject::setPauseAnimation(bool pauseAnimation)
{
	this->pauseAnimation = pauseAnimation;
}

bool BaseObject::getIsLastFrameAnimationDone()
{
	return isLastFrameAnimationDone;
}

void BaseObject::setIsLastFrameAnimationDone(bool isLastFrameAnimationDone)
{
	this->isLastFrameAnimationDone = isLastFrameAnimationDone;
}

void BaseObject::onInitFromFile(ifstream& fs, int mapHeight)
{
	int collisionType, x, y, width, height;
	fs >> collisionType >> x >> y >> width >> height;
	
	y = mapHeight - y;
	set(x, y, width, height);
	setCollisionType((COLLISION_TYPE)collisionType);
	onInit(fs);
	Rect* initBox = new Rect();
	initBox->set(x, y, width, height);
	setInitBox(initBox);
}

void BaseObject::onInit(ifstream& fs)
{
}

void BaseObject::update(float dt)
{
	if (!getIsAlive())
	{
		return;
	}
	goX();
	goY();
	setIsLastFrameAnimationDone(false);
	if (!pauseAnimation && getSprite() != NULL)
	{
		if (animationGameTime.atTime())
		{
			sprite->update(animationIndex, frameIndex);
			if (frameIndex == 0)
			{
				setIsLastFrameAnimationDone(true);
			}
		}
	}
	onUpdate(dt);
}

void BaseObject::onUpdate(float dt)
{
	setPauseAnimation(false);
}

void BaseObject::render(Camera* camera)
{
	if (!getIsAlive())
	{
		return;
	}
	if (getSprite() == 0)
		return;
	if (!getRenderActive())
		return;
	float xView, yView;
	camera->convertWorldToView(getX(), getY(), xView, yView);
	TEXTTURE_DIRECTION imageDirection = sprite->image->direction;

	TEXTTURE_DIRECTION currentDirection = getDirection();
	if (imageDirection != currentDirection)
	{
		int currentFrameWidth = getSprite()->animations[getAnimation()]->frames[getFrameAnimation()]->right -
			getSprite()->animations[getAnimation()]->frames[getFrameAnimation()]->left;
		D3DXMATRIX flipMatrix;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xView + currentFrameWidth / 2);
		GameDirectX::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
	sprite->render(xView, yView, animationIndex, frameIndex);

	if (direction != imageDirection)
	{
		D3DXMATRIX identityMatrix;
		D3DXMatrixIdentity(&identityMatrix);
		GameDirectX::getInstance()->GetSprite()->SetTransform(&identityMatrix);
	}
}

BaseObject::BaseObject()
{
	setSprite(NULL);
	animationGameTime.init(GLOBALS_D("object_animation_time_default"));
	setIsAlive(true);
}


BaseObject::~BaseObject()
{
}

int BaseObject::getAnimation()
{
	return animationIndex;
}

void BaseObject::setAnimation(int animation)
{
	if (this->animationIndex != animation)
	{
		setFrameAnimation(0);
	}
	this->animationIndex = animation;
}

int BaseObject::getFrameAnimation()
{
	return frameIndex;
}

void BaseObject::setFrameAnimation(int frameAnimation)
{
	this->frameIndex = frameAnimation;
}

TEXTTURE_DIRECTION BaseObject::getDirection()
{
	return direction;
}
void BaseObject::setDirection(TEXTTURE_DIRECTION direction)
{
	this->direction = direction;
}

void BaseObject::setRenderActive(bool renderActive)
{
	this->renderActive = renderActive;
}
bool BaseObject::getRenderActive()
{
	return this->renderActive;
}

Rect * BaseObject::getInitBox()
{
	return initBox;
}

void BaseObject::setInitBox(Rect * initBox)
{
	this->initBox = initBox;
}

void BaseObject::restoreLocation()
{
	set(initBox->getX(), initBox->getY(), initBox->getWidth(), initBox->getHeight());
	setIsAlive(true);
}
