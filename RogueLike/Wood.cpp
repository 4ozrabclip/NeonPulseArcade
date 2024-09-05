#include "Wood.h"
#include "Map.h"

Wood::Wood(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    //WhichSpriteInt = DOORLADY;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(WOOD);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void Wood::Update(World* world, float fElapsedTime)
{
    int MaxNumCharacters = World::Instance->GetNumCharacters();

    for (int Num = 0; Num < MaxNumCharacters - 1; Num++)
    {
        World::Instance->Enemy
    }

    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        World::Instance->DrawRect(olc::vf2d(Pos.coords.x, Pos.coords.y), AnimSeq.SpriteSize, olc::YELLOW);
    }

    //PlayerPtr->PushBackCollision({ Pos.coords.x,Pos.coords.y }, {Pos.coords.x - 12, Pos.coords.y - 12});
    Draw(world, fElapsedTime);
}

void Wood::ItemEffect()
{
}
