#include "Weapon.h"

class DeathWeapon :
	public Weapon
{
public:
	DeathWeapon();
	~DeathWeapon();
	void onUpdate(float dt) override;
	void render(Camera* camera);
};

