#include "Enemy.h"
#include "Player.h"
#include "World.h"
#include "Map.h"
#include "Brick.h"
#include "AnimatedSprite.h"
#include "Dungeon1.h"

#include <windows.h>
#include <stdlib.h>

#pragma comment(lib, "Winmm.lib")

World* World::Instance = nullptr;

World::World()
{
	sAppName = "4oz Game";
	Instance = this;
}

World::~World()
{
	for (int i = 0; i < 3; ++i)
	{
		delete EnemyPtrs[i];
	}

	delete[] EnemyPtrs;
	delete PlayerPtr;
	delete DungeonPtr;
	Instance = nullptr;
}

void World::SetBarriers(olc::vi2d InBarriers)
{
	Barriers = InBarriers;
}

olc::vi2d World::GetMapCoordinates()
{
	return olc::vi2d(MapCoords.coords.x, MapCoords.coords.y);
}

olc::vi2d World::GetBarriers()
{
	return Barriers;
}

bool World::OnUserCreate()
{
	//PlaySound(TEXT("fucked1(tat2).wav"), 0, SND_FILENAME | SND_ASYNC);

	Tileset = std::make_shared<olc::Sprite>("tileset.png");
	PlayerPtr = new Player(0, 0);

	DungeonPtr = new Dungeon1();
	SetBarriers(olc::vi2d(228, 228));

	EnemyPtrs[0] = new Enemy(20, 100, PlayerPtr);
	EnemyPtrs[1] = new Enemy(120, 100, PlayerPtr);
	EnemyPtrs[2] = new Enemy(220, 100, PlayerPtr);

	return true;
}
bool World::OnUserUpdate(float fElapsedTime)
{
	const olc::Pixel ClearPixel;
	Clear(ClearPixel);
	SetPixelMode(olc::Pixel::MASK);

	DungeonPtr->DrawRoom(this, fElapsedTime);

	for (int i = 0; i < 3; ++i)
	{
		EnemyPtrs[i]->Update(fElapsedTime);
	}
	PlayerPtr->Update(fElapsedTime);

	return true;
}
bool World::OnUserDestroy()
{
	return true;
}