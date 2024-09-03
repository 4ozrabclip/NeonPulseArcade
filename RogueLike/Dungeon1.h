#pragma once
#include "Map.h"
class Brick;
class Dungeon1 : public Map
{
public:
	Dungeon1();
	void DrawRoom(World* world, float fElapsedTime);

private:
	std::unique_ptr<Brick> BrickPtr;
};

