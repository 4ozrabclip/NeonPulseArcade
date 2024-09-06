#define OLC_PGE_APPLICATION
#include "World.h"

constexpr int SCREEN_WIDTH = 240;
constexpr int SCREEN_HEIGHT = 240;
constexpr int PIXEL_SIZE = 4;
int main()
{
	World GameWorld;
	if (GameWorld.Construct(SCREEN_WIDTH, SCREEN_HEIGHT, PIXEL_SIZE, PIXEL_SIZE))
	{
		GameWorld.Start();
	}

	return 0;
}