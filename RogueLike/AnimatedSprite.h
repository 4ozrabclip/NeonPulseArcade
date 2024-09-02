#pragma once
#include "olcPixelGameEngine.h"
#include <memory>


enum class EAnimationType
{
	STILL,
	LOOP_ONCE,
	LOOP_FOREVER
};

struct FAnimSequence
{
	olc::vi2d WhichSprite;
	olc::vi2d SpriteSize;
	int NumberOfFrames;
	time_t AnimationDuration;

};

class AnimatedSprite
{
public:
	AnimatedSprite(std::shared_ptr<olc::Sprite> tileset, EAnimationType animType,
		const FAnimSequence& animSequence);

	void DrawAt(float fElapsedTime, olc::vi2d InScreenPosition);

private:
	std::shared_ptr<olc::Sprite> Tileset;
	EAnimationType AnimationType;
	FAnimSequence AnimSequence;
	float ElapsedTime;
};