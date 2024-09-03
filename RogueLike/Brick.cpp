#include "Brick.h"

Brick::Brick()
{
    FAnimSequence animSequence;
    animSequence.WhichSprite = Actor::SpritePosition(BRICKS);

    WhichSpriteInt = BRICKS;
    animSequence.NumberOfFrames = 4;
    animSequence.SpriteSize = World::Instance->TileSize;
    animSequence.AnimationDuration = 1.f;
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
}
