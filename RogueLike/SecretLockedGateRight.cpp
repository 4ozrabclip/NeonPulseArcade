#include "SecretLockedGateRight.h"
#include "Map.h"

SecretLockedGateRight::SecretLockedGateRight(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(SECRET_GATE_RIGHT);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}


void SecretLockedGateRight::Update(World* world, float fElapsedTime)
{

    bool Key = PlayerPtr->GetHasSecretKey();

    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        if (!Key)
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
        else {
            ItemEffect();
        }
    }

    Draw(world, fElapsedTime);
}

void SecretLockedGateRight::ItemEffect()
{
    AnimSeq.WhichSprite = Actor::SpritePosition(OPEN_GATE_RIGHT);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}