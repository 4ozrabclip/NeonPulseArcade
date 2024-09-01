#pragma once
#include "olcPixelGameEngine.h"
#include "Player.h"

class Map : public olc::PixelGameEngine
{
public:
	Map();
	~Map();

	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;
	virtual bool OnUserDestroy() override;

	static Map* Instance;

private:
	Player* player;

	std::shared_ptr<olc::Sprite> Tileset;
	const olc::vi2d TileSize = { 12, 12 };
	std::unique_ptr<int[]> blocks;

	const int mapX = 21;
	const int mapY = 20;

};