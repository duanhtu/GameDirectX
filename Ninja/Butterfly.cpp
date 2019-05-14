#include "Butterfly.h"


void Butterfly::onUpdate(float dt)
{
}

Butterfly::Butterfly()
{
	setAnimation(BUTTERFLY_ACTION_FLY);
	setDirection(TEXTURE_DIRECTION_LEFT);
	setRenderActive(true);
}


Butterfly::~Butterfly()
{
}
