#include "LockedGate.h"
#include "Map.h"

LockedGate::LockedGate(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(LOCKED_GATE_LEFT);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}


void LockedGate::Update(World* world, float fElapsedTime)
{

    bool Key = PlayerPtr->GetHasKey();

        if (PlayerPtr->RectangleCollision(Pos.coords))
        {
            if (!Key)
            {
                switch (PlayerPtr->GetDirection())
                {
                case LEFT:
                    //PlayerPtr->SetXY(Pos.coords.x, PlayerPtr->Pos.coords.y);
                    PlayerPtr->Pos.coords.x = this->Pos.coords.x + 12;
                    break;
                case RIGHT:
                    //PlayerPtr->SetXY(Pos.coords.x, PlayerPtr->Pos.coords.y);
                    PlayerPtr->Pos.coords.x = this->Pos.coords.x - 12;
                    //PlayerPtr->Pos.coords.x - 1;
                    break;
                case UP:
                    //PlayerPtr->SetXY(PlayerPtr->Pos.coords.x, PlayerPtr->Pos.coords.y);
                    PlayerPtr->Pos.coords.y = this->Pos.coords.y + 12;
                    break;
                case DOWN:
                    //PlayerPtr->SetXY(PlayerPtr->Pos.coords.x, PlayerPtr->Pos.coords.y);
                    PlayerPtr->Pos.coords.y = this->Pos.coords.y - 12;
                    break;
                }
            }else {
                ItemEffect();
            }
        }
   
    Draw(world, fElapsedTime);
}

void LockedGate::ItemEffect()
{
    AnimSeq.WhichSprite = Actor::SpritePosition(OPEN_GATE_LEFT);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}