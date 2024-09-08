#include "DoorToApa.h"
#include "Map.h"

DoorToApa::DoorToApa(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    //WhichSpriteInt = DoorToApaLADY;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(APA_DOORLADY);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void DoorToApa::Update(World* world, float fElapsedTime)
{
    Draw(world, fElapsedTime);
    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        bItemTaken = true;
    }

    if (bItemTaken)
    {
        //AnimSeq.WhichSprite = Actor::SpritePosition(DoorToApaSTAIRS);
        //AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
        //Draw(world, fElapsedTime);
        World::Instance->LevelSwitch(true, 5);
    }
}

void DoorToApa::ItemEffect()
{
    AnimSeq.WhichSprite = Actor::SpritePosition(DOORSTAIRS);
}
