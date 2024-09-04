#include "Pill.h"
#include "World.h"

Pill::Pill(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    AnimSeq.WhichSprite = Actor::SpritePosition(PILL);
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void Pill::ItemEffect()
{
    PlayerPtr->SetMoveSpeed(200);
}
