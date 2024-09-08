#include "Apathetic.h"
#include "World.h"

Apathetic::Apathetic(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    Tileset = World::Instance->Tileset;
    AnimSeq.WhichSprite = Actor::SpritePosition(APATHETIC);
    AnimSeq.NumberOfFrames = 4;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;

    StartPosition = this->Pos.coords.x;
    WalkSpeed = 0.01f;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, AnimSeq);
}

void Apathetic::Move(float fElapsedTime)
{

    Pos.coords.x += WalkSpeed;

    if (Pos.coords.x >= StartPosition + 10 || Pos.coords.x <= StartPosition - 10)
    {
        WalkSpeed *= -1;
    }
}

void Apathetic::Update(World* world, float fElapsedTime)
{
    Move(fElapsedTime);
    Draw(world, fElapsedTime);
}
