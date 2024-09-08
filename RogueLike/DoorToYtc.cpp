#include "DoorToYtc.h"
#include "Map.h"

DoorToYtc::DoorToYtc(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    //WhichSpriteInt = DoorToYtcLADY;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(FERG_DOORGUARD);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void DoorToYtc::Update(World* world, float fElapsedTime)
{
    Draw(world, fElapsedTime);
    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        bItemTaken = true;
    }

    if (bItemTaken)
    {
        //AnimSeq.WhichSprite = Actor::SpritePosition(DoorToYtcSTAIRS);
        //AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
        //Draw(world, fElapsedTime);
        World::Instance->LevelSwitch(true, 4);
    }
}

void DoorToYtc::ItemEffect()
{
    AnimSeq.WhichSprite = Actor::SpritePosition(DOORSTAIRS);
}
