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

	GameTime animationGameTime;

	bool pauseAnimation;
	
	bool isLastFrameAnimationDone;
	TEXTTURE_DIRECTION direction;
public:


	void setSprite(Sprite*sprite);
	Sprite* getSprite();

	bool getPauseAnimation();
	virtual void setPauseAnimation(bool pauseAnimation);

	bool getIsLastFrameAnimationDone();
	virtual void setIsLastFrameAnimationDone(bool isLastFrameAnimationDone);

	/* hàm ảo được gọi khi khởi tạo đối tượng đọc từ file, mỗi đối tượng sẽ thực hiện phương thức này khác nhau */
	virtual void onInitFromFile(ifstream& fs, int mapHeight);

	/* hàm ảo, hành động update của đối tượng, do mỗi đối tượng có phương thức cập nhật khác nhau
	như con zombie thì chạy còn con dơi thì bay hình sin
	dt : thời gian giữa 2 khung hình game tính bằng giây dùng để tính toán vật lý sau này
	*/
	virtual void onUpdate(float dt);
	/* hành động cập nhật của đối tượng sau mỗi lần vẽ lại */

	void update(float dt);
	/* hành động vẽ của đối tượng
	camera dùng để biến đổi tọa độ của object từ world sang view
	*/
	virtual void render(Camera* camera);
	int getAnimation();
	void setAnimation(int animation);
	int getFrameAnimation();
	void setFrameAnimation(int frameAnimation);

	TEXTTURE_DIRECTION	getDirection();
	void setDirection(TEXTTURE_DIRECTION direction);

	BaseObject();
	~BaseObject();
};

