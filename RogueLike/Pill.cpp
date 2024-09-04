#include "Pill.h"
#include "World.h"

Pill::Pill(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    FAnimSequence animSequence;
    animSequence.WhichSprite = Actor::SpritePosition(PILL);
    animSequence.NumberOfFrames = 2;
    animSequence.SpriteSize = World::Instance->TileSize;
    animSequence.AnimationDuration = 1.0f;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
}
