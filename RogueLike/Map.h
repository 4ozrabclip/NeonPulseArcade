#pragma once
#include "World.h"
#include "Actor.h"
#include <memory>

class Map : public Actor
{
public:
	Map();
	virtual ~Map();
	virtual void Draw(World* World, float fElapsedTime) const override;
	virtual void SetMap(int map[]);
protected:
	std::unique_ptr<int[]> MapLayout;
	int WhichSpriteInt;
private:
	Map(const Map& other);
};
