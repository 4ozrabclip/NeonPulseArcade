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
    Draw(world, fElapsedTime);
    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        bItemTaken = true;
    }

    if (bItemTaken)
    {
        World::Instance->LevelSwitch(true, 1);
    }
}
void Door::ItemEffect()
{
    AnimSeq.WhichSprite = Actor::SpritePosition(DOORSTAIRS);
}
