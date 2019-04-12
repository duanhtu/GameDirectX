#pragma once
#include "d3dx9.h"
#include <string>
#include "GSprite.h"
using namespace std;
class CText
{
	private: 
	//ID3DXFont *font;
	LPD3DXFONT font;
	LPD3DXSPRITE fSprite;
	RECT fRec;
public:
	CText();
	~CText();
	void CreateText(LPDIRECT3DDEVICE9 gDevice, int fontH, int fontW, string m);
	void CreateTextBoard(LPDIRECT3DDEVICE9 gDevice);
	HRESULT LoadFont(LPD3DXFONT pFont, char* fontName, LPDIRECT3DDEVICE9 pDevice);
};