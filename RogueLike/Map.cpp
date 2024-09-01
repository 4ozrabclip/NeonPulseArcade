#include "Map.h"

Map* Map::Instance = nullptr;
Map::Map()
{
	sAppName = "4oz Game";
	Instance = this;
}
Map::~Map()
{
	Instance = nullptr;
}
bool Map::OnUserCreate()
{
	blocks = std::make_unique<int[]>(mapX * mapY);
	for (int y = 0; y < mapY; y++)
	{
		for (int x = 0; x < mapX; x++)
		{
			if (x == 0 || y == 0 || x == mapX - 1 || y == mapY - 1) //BORDER
			{
				blocks[y * mapX + x] = 10;
			}
			else {
				blocks[y * mapX + x] = 0;
			}			
			if ((x > 2 && y > 10 && x < 10 && y < 15)) { //Building1
				blocks[y * mapX + x] = 1;
			}
		}
	}
	return true;
}
bool Map::OnUserUpdate(float fElapsedTime) //If we want to quit the game, return false 
{
	SetPixelMode(olc::Pixel::MASK);
	bool running = true;
	Tileset = std::make_shared<olc::Sprite>("tileset.png");

	Clear(olc::BLACK);

	olc::vi2d temp = { 0,10 };
	olc::vi2d sourcepos = { 0, 0 };

	for (int y = 0; y < mapY; y++)
	{
		for (int x = 0; x < mapX; x++)
		{
			switch (blocks[y * mapX + x])
			{
			case 0: // NOTHING
				break;
			case 10: // BOUNDARY
				DrawPartialSprite(
					olc::vi2d(x, y) * TileSize, 
					Tileset.get(), 
					sourcepos * TileSize, 
					TileSize);
				break;
			case 1: //BUILDING 1
				x == 5 && y == 14 ? 
					DrawPartialSprite(
						olc::vi2d(x,y) * TileSize, 
						Tileset.get(), 
						olc::vi2d(1, 2) * TileSize, 
						TileSize) 
					: DrawPartialSprite(
						olc::vi2d(x, y) * TileSize, 
						Tileset.get(), 
						olc::vi2d(0, 5) * TileSize, 
						TileSize);
				
				break;
			}
		}
	}
	SetPixelMode(olc::Pixel::NORMAL);
	return running;
}
bool Map::OnUserDestroy()
{
	return true;
}