#pragma once


#include"GameDirectX.h"


enum TEXTTURE_DIRECTION
{
	TEXTURE_DIRECTION_LEFT = -1,
	TEXTURE_DIRECTION_RIGHT = 1
};
class GameTexture
{
private:
	LPDIRECT3DTEXTURE9 m_image;
public:
	int Width, Height;
	/* Huong dan mac dinh cua texture*/
	TEXTTURE_DIRECTION direction;


	GameTexture(const char* filepath, D3DCOLOR transColor = 0);


	/**Tao texture
	  filepath: duong dan file hinh anh
	  transColor: mau can trong suot*/

	void Init(const char* filepath, D3DCOLOR transColor = 0);
	GameTexture() {}
	/** Ve texture 
	 filepath: duong dan file hinh anh
	 transColor: mau can trong suot
	*/
	void Render(int x, int y,int anchorX, int anchorY, RECT *r=0);
	~GameTexture();

};