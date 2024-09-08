#include "LeaveDoor.h"
#include "Map.h"

LeaveDoor::LeaveDoor(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    //WhichSpriteInt = LeaveDoorLADY;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(FINAL_DOOR);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void LeaveDoor::Update(World* world, float fElapsedTime)
{
    Draw(world, fElapsedTime);
    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        bItemTaken = true;
    }

    if (bItemTaken)
    {
        //AnimSeq.WhichSprite = Actor::SpritePosition(LeaveDoorSTAIRS);
        //AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
        //Draw(world, fElapsedTime);
        World::Instance->LevelSwitch(true, 0);
    }
}

void LeaveDoor::ItemEffect()
{
    AnimSeq.WhichSprite = Actor::SpritePosition(DOORSTAIRS);
}
