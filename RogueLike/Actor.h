#pragma once
#include <stdio.h>
#include <cstdint>
#include "olcPixelGameEngine.h"
#include "AnimatedSprite.h"
#include "TVector2D.h"

class World;

enum InitialSprite {
	BORDER = 0,
	BRICKS,
	DOOR,
	RABCLIP,
	FERG,
	WOOD,
	ALIEN,
	SPEAKER,
	DOORLADY,
	DESK_LEFT,
	DESK_DECKS_RAB,
	DESK_RIGHT,
	PILL = 13,
};
struct FCoords {
	TVector2D<float> coords;
};
class Actor
{
public:
	Actor();

	virtual void Update(float fElapsedTime) {};
	virtual void Tick();
	olc::vi2d SpritePosition(InitialSprite sprite) const;
	virtual void Draw(World* World, float fElapsedTime) const;
	virtual void SetAnimatedSprite(std::shared_ptr<AnimatedSprite> AnimatedSprite);

	virtual void SetXY(float InX, float InY);
	virtual olc::vi2d GetXY();

protected:
	FCoords Pos;
	std::shared_ptr<AnimatedSprite> AnimatedSpritePtr;
	std::shared_ptr<olc::Sprite> Tileset;

};