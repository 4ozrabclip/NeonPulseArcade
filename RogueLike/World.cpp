#include "Enemy.h"
#include "Player.h"
#include "World.h"
#include "Map.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Dungeon1.h"
#include "Dungeon2.h"
#include "Dungeon3.h"

#include <windows.h>
#include <stdlib.h>

#pragma comment(lib, "Winmm.lib")

World* World::Instance = nullptr;

World::World()
{
	sAppName = "4oz Game";
	Instance = this;
	EnemyMax = 3;
	LevelSwitchFlag = false;
	Level = 0;
}

World::~World()
{
	for (ActorIndex = 0; ActorIndex < Actors.Num(); ++ActorIndex)
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
	Map** DungeonPtrs = new Map * [3];
	DungeonPtrs[0] = new Dungeon1();
	DungeonPtrs[1] = new Dungeon2();
	DungeonPtrs[2] = new Dungeon3();
	
	Dungeons.AddElement(DungeonPtrs[0]);
	Dungeons.AddElement(DungeonPtrs[1]);
	Dungeons.AddElement(DungeonPtrs[2]);

	delete[] DungeonPtrs;
	Flag = true;
	return true;
}
bool World::OnUserUpdate(float fElapsedTime)
{
	size_t ArraySize = Actors.Num();
	const olc::Pixel ClearPixel;
	Clear(ClearPixel);
	SetPixelMode(olc::Pixel::MASK);

	if (Flag)
	{
		Dungeons.GetElement(Level)->InitDungeon(Instance);
		Flag = false;
	}
	Dungeons.GetElement(Level)->Update(Instance, fElapsedTime);

	for (ActorIndex = 0; ActorIndex < ArraySize; ++ActorIndex)
	{
		if (Actors.GetElement(ActorIndex))
		{
			Actors.GetElement(ActorIndex)->Update(Instance, fElapsedTime);
		}
	}
	PlayerPtr->Update(Instance, fElapsedTime);
	if (LevelSwitchFlag)
	{
		ClearMapActors();
		LevelSwitchFlag = false;
		Flag = true;
	}
	return true;
}
bool World::OnUserDestroy()
{
	return true;
}
void World::ClearMapActors()
{
	size_t ArraySize = Actors.Num();
	for (ActorIndex = 0; ActorIndex < ArraySize; ActorIndex++)
	{
		World::Instance->Actors.RemoveElement(ActorIndex);
	}
}

int World::GetNumCharacters()
{
	return EnemyMax + 1; //max enemys + 1 for player
}

void World::LevelSwitch(bool bSwitch, int InLevel)
{
	LevelSwitchFlag = bSwitch;
	Level = InLevel;
}

int World::GetActorIndex()
{
	return ActorIndex;
}
