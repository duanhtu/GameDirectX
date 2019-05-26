#include "Weapon.h"

class DeathWeapon :
	public Weapon
{
public:
	void onCollision(MovableRect *other, float collisionTime, int nx, int ny);
	DeathWeapon();
	~DeathWeapon();
	void onUpdate(float dt) override;
	void render(Camera* camera);
};

