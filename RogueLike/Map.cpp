#include "Map.h"

Map::Map()
{
	sAppName = "4oz Game";
}
bool Map::OnUserCreate()
{
	Blocks = std::make_unique<int[]>(24 * 30);
	for (int y = 0; y < 30; y++)
	{
		for (int x = 0; x < 24; x++)
		{
			if (x == 0 || y == 0 || x == 23)
			{
				Blocks[y * 24 + x] = 10;
			}
			else {
				Blocks[y * 24 + x] = 0;
			}
		}
	}
	return true;


}
bool Map::OnUserUpdate(float fElapsedTime) //If we want to quit the game, return false 
{
	bool running = true;

	//DrawString(ScreenWidth() -160, 12, "4oz Game", olc::WHITE, 1);
	Clear(olc::DARK_BLUE);
	for (int y = 0; y < 30; y++)
	{
		for (int x = 0; x < 24; x++)
		{
			switch (Blocks[y * 24 + x])
			{
			case 0: 
				break;
			case 10: 
				FillRect(olc::vi2d(x, y) * BlockSize, BlockSize, olc::WHITE);
				break;
			}
		}
	}

	return running;
}
bool Map::OnUserDestroy()
{
	return true;
}