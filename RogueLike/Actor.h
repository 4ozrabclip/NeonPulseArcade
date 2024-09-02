#pragma once
#include <stdio.h>
#include <cstdint>
#include "olcPixelGameEngine.h"

enum InitialSprite {
	BORDER,
	BRICKS,
	DOOR,
	RABCLIP,
	FERG,
	WOOD,
	ALIEN,
	SPEAKER
};

class Actor
{
public:
	virtual void Update(float fElapsedTime) {};
	virtual void Tick();
	olc::vi2d SpritePosition(InitialSprite sprite) const;
protected:
	float X;
	float Y;

};