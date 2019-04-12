#pragma once
#include"Animation.h"
#include"GameTexture.h"
#include"GameUtils.h"
class Sprite
{

public:
	/* Hinh anh cua doi tuong game */
	GameTexture* image;
	/* danh sach animation cua doi tuong game */
	List<Animation*> animations;
	/* imagePath: duong dan hinh
	    infoPath : duong dan file cau hinh danh sach animation
		*/
	void InitFromFile(const char* imagePath, const char* infoPath);
	/* animationIndex: Loai animation can cap nhat
	    frameIndex: frame can cap nhat
	*/
	void update(int animationIndex, int& frameIndex);

	void render(int x, int y, int animationIndex, int frameIndex);
	Sprite();
	~Sprite();
};