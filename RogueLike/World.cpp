#include "Enemy.h"
#include "Player.h"
#include "World.h"
#include "Map.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "StartDungeon.h"
#include "Dungeon2.h"
#include "Dungeon3.h"
#include "YtcDungeon1.h"
#include "ApaDungeon1.h"
#include <windows.h>
#include <stdlib.h>

#pragma comment(lib, "Winmm.lib")

World* World::Instance = nullptr;

World::World()
{
	sAppName = "4oz Game";
	Instance = this;
	EnemyMax = 3;
	Level = 0;

	EndLevelFLag = false;
	bEnemyKilled = false;
	DeadEnemyIndex = 0;
}

World::~World()
{
	size_t ArraySize = Actors.Num();
	for (ActorIndex = 0; ActorIndex < ArraySize; ++ActorIndex)
	{
		Actors.RemoveElement(ActorIndex);
	}
	delete PlayerPtr;

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
	Tileset = std::make_shared<olc::Sprite>("tileset.png");
	PlayerPtr = new Player(20, 20);
	Map** DungeonPtrs = new Map * [6];
	DungeonPtrs[0] = new StartDungeon();
	DungeonPtrs[1] = new Dungeon2();
	DungeonPtrs[2] = new Dungeon3();
	DungeonPtrs[3] = new Dungeon3();
	DungeonPtrs[4] = new YtcDungeon1();
	DungeonPtrs[5] = new ApaDungeon1();
	
	Dungeons.AddElement(DungeonPtrs[0]);
	Dungeons.AddElement(DungeonPtrs[1]);
	Dungeons.AddElement(DungeonPtrs[2]);
	Dungeons.AddElement(DungeonPtrs[3]);
	Dungeons.AddElement(DungeonPtrs[4]);
	Dungeons.AddElement(DungeonPtrs[5]);

	delete[] DungeonPtrs;
	NewLevelFlag = true;
	return true;
}
bool World::OnUserUpdate(float fElapsedTime)
{
	size_t ArraySize = Actors.Num();
	const olc::Pixel ClearPixel;
	Clear(ClearPixel);
	SetPixelMode(olc::Pixel::MASK);


	if (NewLevelFlag)
	{
		Dungeons.GetElement(Level)->InitDungeon(Instance);
		NewLevelFlag = false;
	}
	Dungeons.GetElement(Level)->Update(Instance, fElapsedTime);

	for (ActorIndex = 0; ActorIndex < ArraySize; ++ActorIndex)
	{
		Actors.GetElement(ActorIndex)->Update(Instance, fElapsedTime);
	}

	PlayerPtr->Update(Instance, fElapsedTime);
	
	//if (bEnemyKilled)
	//{
	//	ClearDeadActors();
	//	bEnemyKilled = false;
	//}

	if (EndLevelFLag)
	{
		ClearAllActors();
		EndLevelFLag = false;
		NewLevelFlag = true;
	}
	return true;
}
bool World::OnUserDestroy()
{
	return true;
}
void World::ClearAllActors()
{
	size_t ArraySize = Actors.Num();
	for (ActorIndex = 0; ActorIndex < ArraySize; ActorIndex++)
	{
		Actors.RemoveElement(ActorIndex);
	}
}
void World::ClearDeadActors()
{
	Actors.RemoveElement(DeadEnemyIndex);
}

void World::LevelSwitch(bool bSwitch, int InLevel)
{
	EndLevelFLag = bSwitch;
	Level = InLevel;
}

void World::EnemyKilled(bool InbEnemyKilled, int InDeadEnemyIndex)
{
	bEnemyKilled = InbEnemyKilled;
	DeadEnemyIndex = InDeadEnemyIndex;
}

void World::DrawUIText(olc::vi2d pos, std::string text)
{
}

int World::GetActorIndex()
{
	return ActorIndex;
}
