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
	virtual void DrawRoom(World* world);
	virtual void Update(World* World, float fElapsedTime);

	virtual void InitDungeon(World* world);

	//virtual bool HasCollided();
protected:
	std::unique_ptr<int[]> MapLayout;
	int WhichSpriteInt;
private:
	Map(const Map& other);
};
