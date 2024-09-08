#pragma once
#include "Map.h"
#include "Actor.h"

class Pill;
class Door;
class Wood;
class Enemy;

class DeathScreen : public Map
{
public:
	DeathScreen();
	virtual void DrawRoom(World* world) override;
	virtual void SetMap(int map[]);
	virtual void InitDungeon(World* world) override;
};

