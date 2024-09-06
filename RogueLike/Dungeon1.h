#pragma once
#include "Map.h"
#include "Actor.h"
#include <memory>

class Pill;
class Door;
class Wood;
class Enemy;

class Dungeon1 : public Map
{
public:
	Dungeon1();
	virtual void DrawRoom(World* world) override;
	virtual void SetMap(int map[]);
	virtual void InitDungeon(World* world) override;
};

