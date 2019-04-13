#include "Text.h"

CText::CText()
{
	
}

CText::~CText()
{

}

void CText::CreateText(LPDIRECT3DDEVICE9 gDevice, int fontH, int fontW, string m)
{
	//font = NULL;
	HRESULT hr = D3DXCreateFont(gDevice, fontH, fontW, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &font);
	if (SUCCEEDED(hr))
	{
		SetRect(&fRec, 0, 15, 500, 500);
		if (font)
		{
			GSprite* g = new GSprite();
			//font->DrawTextA(NULL, m.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
			font->DrawText(NULL, m.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
			
		}
	}

}

void CText::CreateTextBoard(LPDIRECT3DDEVICE9 gDevice)
{
	//font = NULL;
	//string m = "DAY LA DONG CHỮ";
	//HRESULT hr = D3DXCreateFont(gDevice, 15, 10, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &font);
	//if (SUCCEEDED(hr))
	//{
	//	SetRect(&fRec, 0, 15, 500, 500);
	//	if (font)
	//	{
	//		GSprite* g = new GSprite();
	//		//font->DrawTextA(NULL, m.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	//		font->DrawText(NULL, m.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	//	}
	//}
	//---------->
	//LPD3DXSPRITE m_pSprite;
	//HRESULT hr = D3DXCreateFont(gDevice, 15, 10, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &font);
	//SetRect(&fRec, 0, 15, 500, 500);
	////-----------------
	//// Render Loop
	////----------------------
	//gDevice->BeginScene();
 //   m_pSprite->Begin(D3DRS_ALPHABLENDENABLE); //  <--- must be called between LPD3DXSPRITE::Begin()
	//string m = "DAY LA DONG CHu";
	//font->DrawTextA(NULL, m.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	//font->DrawText(NULL, m.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

 //   m_pSprite->End();
	//gDevice->EndScene();
	
	//m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	//D3DXFONT_DESC FontDesc = {40,40,400,10,	false,DEFAULT_CHARSET,OUT_TT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_PITCH, "Arial" };
	
	////create font
	//D3DXCreateFontIndirect(gDevice, &FontDesc, &font);
	//font->DrawText(fSprite,"Hello",-1,&fRec,	NULL, D3DCOLOR_XRGB(255, 255, 255));
	//fSprite->End();
	//gDevice->EndScene();
	string s = "hello";
	//RECT r;
	//r.top = 0;
	//r.bottom = 0;
	//r.left = 0;
	//r.right = 0;
	//hr = D3DXCreateFont(gDevice, 15, 10, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &font);
	//hr = font->DrawTextA(fSprite, s.c_str(), -1, &fRec, NULL, D3DCOLOR_XRGB(255, 255, 255));
	//font->DrawText(fSprite, s.c_str(), -1, &r, DT_LEFT | DT_TOP | DT_CALCRECT, D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	
	//gDevice->OMSetBlendState(NULL, 0, 0xffffffff);
	gDevice->BeginScene();
	D3DXCreateSprite(gDevice, &fSprite);
	SetRect(&fRec, 0, 17, 100, 500);
	HRESULT	hr =// fSprite->Begin(0);
	D3DXCreateFont(gDevice, 50, 50, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &font);
	if (SUCCEEDED(hr))
	{
		SetRect(&fRec, 0, 15, 500, 500);
		if (font)
		{
			GSprite* g = new GSprite();
			//font->DrawTextA(NULL, m.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
			font->DrawText(NULL, s.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

		}
	}
	fSprite->End();
	//gDevice->EndScene();
}

HRESULT CText::LoadFont(LPD3DXFONT pFont, char* fontName, LPDIRECT3DDEVICE9 pDevice)
{
	//// clear if not empty <no memory leaks!!>
	//if (pFont)
	//	pFont->Release();

	//	// font description struct
	//	D3DXFONT_DESC	m_fontDesc;

	//ZeroMemory(&pFont->m_fontDesc, sizeof(D3DXFONT_DESC));
	//m_fontDesc.Height = 12;
	//m_fontDesc.Width = 8;
	//m_fontDesc.Weight = 500;
	//m_fontDesc.MipLevels = D3DX_DEFAULT;
	//m_fontDesc.Italic = false;
	//m_fontDesc.CharSet = 0;
	//m_fontDesc.OutputPrecision = 0;
	//m_fontDesc.Quality = 0;
	//m_fontDesc.PitchAndFamily = 0;
	//strcpy(m_fontDesc.FaceName, fontName); // name will be something like "Arial"


	//if (FAILED(D3DXCreateFontIndirect(pDevice, &m_fontDesc, &pFont))
	//	return E_FAIL;

	return S_OK;

	// Other options
	//DT_NOCLIP | DT_WORDBREAK
	
}
