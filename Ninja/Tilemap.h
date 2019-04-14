#pragma once
#include "GameTexture.h"

/* de ve tilemap ta can them camera vao */
#include "Camera.h"
class Tilemap
{
  /* chieu rong tile */
	int tileWidth;
  /* chieu dai tile */
	int tileHeight;
	/* so luong dong trong matrix */
	int tileRows;
	/* so luong cot trong matrix */
	int tileColumns;
	/* so luong cot trong tilesheet */
	int tilesheetColumns;


	/* tilesheet */
	GameTexture* tilesheet;

	/* ma tran tile */
	int** matrix;
public:
	/* ve tilemap bang camera */
	void render(Camera* camera);

	/* lấy chiều cao của world dùng để chuyển đổi tọa độ khi init */
	int getWorldHeight();

	/* tilesheetPath: duong dan tilesheet
	matrixPath: duong dan file ma tran
	*/
	void Init(const char* tilesheetPath, const char* matrixPath);
	/* folderPath: duong dan thu muc chua ma tran va tilesheet */
	void Init(const char* folderPath);
	Tilemap();
	~Tilemap();
};