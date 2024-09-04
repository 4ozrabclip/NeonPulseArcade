#include "Door.h"
#include "Map.h"

Door::Door(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    //WhichSpriteInt = DOORLADY;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(DOORLADY);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void Door::Update(World* world, float fElapsedTime)
{
    float PlayerX = PlayerPtr->GetXY().x;
    float PlayerY = PlayerPtr->GetXY().y;

    float ItemX = this->GetXY().x;
    float ItemY = this->GetXY().y;

    //olc::vi2d PlayerPos = {PlayerX, PlayerY};

    float deltaX = PlayerX - ItemX;
    float deltaY = PlayerY - ItemY;
    float distanceSquared = deltaX * deltaX + deltaY * deltaY;

    if (distanceSquared <= 6)
    {
        bItemTaken = true;
    }

    if (bItemTaken)
    {
        AnimSeq.WhichSprite = Actor::SpritePosition(DOORSTAIRS);
        AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
        Draw(world, fElapsedTime);
        //ItemEffect();
    }
    Draw(world, fElapsedTime);
}

void Door::ItemEffect()
{
    AnimSeq.WhichSprite = Actor::SpritePosition(DOORSTAIRS);
    
}
