#pragma once
#include "Map.h"
#include "Actor.h"
#include <memory>

class Pill;
class Door;
class Wood;
class Dungeon1 : public Map
{
public:
	Dungeon1();
	void DrawRoom(World* world, float fElapsedTime);
	virtual void SetMap(int map[]);
private:
	Pill* PillPtr;
	Door* DoorPtr;
	Wood** WoodPtrs = new Wood * [8];
};

