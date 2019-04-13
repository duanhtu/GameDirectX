#include "Sprite.h"
/* khoi lop doc file */
#include<fstream>
using namespace std;

void Sprite::InitFromFile(const char * imagePath, const char * infoPath)
{
	image = new GameTexture();
	ifstream fs(infoPath);
	/* Truoc tien doc argb va khoi tao buc hinh truoc */
	/* bo 2 line va doc a r g b */
	ignoreLineIfstream(fs, 2);
	int a, r, g, b;
	fs >> a >> r >> g >> b;	
	/* khoi tao image */
	image->Init(imagePath, D3DCOLOR_ARGB(a, r, g, b));

	/* Tu cuoi dong do ta enter xuong 2 lan de doc so 2 cua animation count */
	ignoreLineIfstream(fs, 2);
	int animationCount;
	fs >> animationCount;


	/* tiep theo ta duyet vong lap de khoi tao animation */
	for (size_t i = 0; i < animationCount; i++)
	{
		Animation* animation = new Animation();






		ignoreLineIfstream(fs, 6);
		/* doc frame count */
		int frameCount;
		fs >> frameCount;
		


		ignoreLineIfstream(fs, 3);
		for (size_t frameIndex = 0; frameIndex < frameCount; frameIndex++)
		{
			/* khoi tao frame */
			FrameAnimation* frame = new FrameAnimation();
			int x, y, width, height, anchorX, anchorY;
			fs >> x >> y >> width >> height >> anchorX >> anchorY;
			SetRect(frame, x, y, x + width, y + height);
			frame->anchorX = anchorX;
			frame->anchorY = anchorY;
			/* Them frame vao animation */
			animation->frames._Add(frame);
		}
         /* them animation vao sprite */
		animations._Add(animation);
	}
}
void Sprite::update(int animationIndex, int& frameIndex)
{
	/* Cap nhat bang cach chuyen frame cua animation */
	frameIndex = animations.at(animationIndex)->NextFrame(frameIndex);
}
void Sprite::render(int x, int y, int animationIndex, int frameIndex)
{
	/* ve hinh tai animation index va frame index */
	auto animation = animations.at(animationIndex);
	auto frame = animation->frames.at(frameIndex);
	image->Render(x, y, frame->anchorX, frame->anchorY, frame);
}
Sprite::Sprite()
{
}
Sprite::~Sprite()
{
}