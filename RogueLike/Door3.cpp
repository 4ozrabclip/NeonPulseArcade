#include "Door3.h"
#include "Map.h"

Door3::Door3(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    //WhichSpriteInt = Door3LADY;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(DOORLADY);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void Door3::Update(World* world, float fElapsedTime)
{
    Draw(world, fElapsedTime);
    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        bItemTaken = true;
    }

    if (bItemTaken)
    {
        //AnimSeq.WhichSprite = Actor::SpritePosition(Door3STAIRS);
        //AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
        //Draw(world, fElapsedTime);
        World::Instance->LevelSwitch(true, 3);
    }
}

void Door3::ItemEffect()
{
    AnimSeq.WhichSprite = Actor::SpritePosition(DOORSTAIRS);
}
