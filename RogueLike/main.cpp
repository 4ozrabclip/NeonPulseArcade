#define OLC_PGE_APPLICATION
#include "Map.h"

constexpr int SCREEN_WIDTH = 252;
constexpr int SCREEN_HEIGHT = 240;
constexpr int PIXEL_SIZE = 4;
int main()
{

	Map World;
	if (World.Construct(SCREEN_WIDTH, SCREEN_HEIGHT, PIXEL_SIZE, PIXEL_SIZE))
	{
		World.Start();
	}

	return 0;
}