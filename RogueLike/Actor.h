#pragma once
#include <stdio.h>
#include <cstdint>
#include "olcPixelGameEngine.h"
#include "AnimatedSprite.h"

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

};
struct FCoords{
	float x;
	float y;
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
protected:
	FCoords Pos;
	std::shared_ptr<AnimatedSprite> AnimatedSpritePtr;
	std::shared_ptr<olc::Sprite> Tileset;

};