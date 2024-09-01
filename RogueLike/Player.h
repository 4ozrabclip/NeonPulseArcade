#pragma once
#include "Character.h"
class Map;
class Player : public Character
{
public:
	Player(Map* map);
	void Update();
private:
	Map* map;
};

