#pragma once
#include "olcPixelGameEngine.h"
class Map;
class Player;
class Enemy;
class Dungeon1;
class World : public olc::PixelGameEngine
{
public:
	World();
	~World() override;

	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;
	virtual bool OnUserDestroy() override;

	static World* Instance;

	std::shared_ptr<olc::Sprite> Tileset;
	const olc::vi2d TileSize = { 12, 12 };

private:
	static constexpr int ArraySize = 3;
	Enemy** EnemyPtrs = new Enemy * [ArraySize];
	Player* PlayerPtr;
	Dungeon1* DungeonPtr;
};