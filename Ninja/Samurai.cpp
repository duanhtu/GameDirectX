#include "Samurai.h"



Samurai::Samurai()
{
}
void Samurai::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

Samurai::~Samurai()
{
}
