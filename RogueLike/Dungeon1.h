#pragma once
#include "Map.h"
#include <memory>
class Dungeon1 : public Map
{
public:
	Dungeon1();
	void DrawRoom(World* world, float fElapsedTime);
	virtual void SetMap(int map[]);
private:
};

