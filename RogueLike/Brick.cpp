#include "Brick.h"
#include "Map.h"

Brick::Brick(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(BRICKS);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void Brick::Update(World* world, float fElapsedTime)
{

    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        switch (PlayerPtr->GetDirection())
        {
        case LEFT:
            PlayerPtr->Pos.coords.x = this->Pos.coords.x + 12;
            break;
        case RIGHT:
            PlayerPtr->Pos.coords.x = this->Pos.coords.x - 12;
            break;
        case UP:
            PlayerPtr->Pos.coords.y = this->Pos.coords.y + 12;
            break;
        case DOWN:
            PlayerPtr->Pos.coords.y = this->Pos.coords.y - 12;
            break;
        }
    }

    Draw(world, fElapsedTime);
}

void Brick::ItemEffect()
{
}