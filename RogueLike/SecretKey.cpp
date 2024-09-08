#include "SecretKey.h"
#include "World.h"

SecretKey::SecretKey(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    AnimSeq.WhichSprite = Actor::SpritePosition(SECRETKEY);
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}
void SecretKey::ItemEffect()
{
    PlayerPtr->SetHasSecretKey(true);
}