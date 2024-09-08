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
	DOORSTAIRS,
	PILL = 13,
	MUSHROOM,
	APATHETIC,
	RABCLIP_SWORD,
	FERG_SWORD,
	APATHETIC_SWORD,
	SWORD,
	RABCLIP_SING,
	DESK_LEFT_GREY,
	DESK_DECKS_APA,
	DESK_RIGHT_GREY,
	LOCKED_GATE_LEFT,
	LOCKED_GATE_RIGHT,
	OPEN_GATE_LEFT,
	OPEN_GATE_RIGHT,
	KEY,
	FANCYWALLS1,
	FANCYWALLS2,
	FANCYWALLS3,
	APA_DOORLADY,
	FERG_DOORGUARD
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
	//virtual void SetCollider(olc::vf2d coords);
	virtual void Update(World* world, float fElapsedTime) {};
	virtual void SetXY(float InX, float InY);
	virtual olc::vi2d GetXY();
	//virtual void SetAnimSeq(FAnimSequence InAnimSeq);
	bool RectangleCollision(TVector2D<float> r) const;
	int GetIndex();

	FCoords Pos;

protected:
	FAnimSequence AnimSeq;
	std::shared_ptr<AnimatedSprite> AnimatedSpritePtr;
	std::shared_ptr<olc::Sprite> Tileset;
};