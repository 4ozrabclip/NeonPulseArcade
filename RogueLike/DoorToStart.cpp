#include "DoorToStart.h"
#include "Map.h"

DoorToStart::DoorToStart(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    //WhichSpriteInt = DoorToStartLADY;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(DOOR);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void DoorToStart::Update(World* world, float fElapsedTime)
{
    Draw(world, fElapsedTime);
    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        bItemTaken = true;
    }

    if (bItemTaken)
    {
        //AnimSeq.WhichSprite = Actor::SpritePosition(DoorToStartSTAIRS);
        //AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
        //Draw(world, fElapsedTime);
        World::Instance->LevelSwitch(true, 0);
    }
}
void DoorToStart::ItemEffect()
{
    //AnimSeq.WhichSprite = Actor::SpritePosition(DoorToStartSTAIRS);
}
