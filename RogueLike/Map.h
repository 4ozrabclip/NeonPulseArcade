#pragma once
#include "olcPixelGameEngine.h"

class Map : public olc::PixelGameEngine
{
public:
	Map();

	bool OnUserCreate() override;

	bool OnUserDestroy() override;


	bool OnUserUpdate(float fElapsedTime) override;

private:
	std::unique_ptr<int[]> Blocks;
	olc::vi2d BlockSize = { 12, 12 };
};