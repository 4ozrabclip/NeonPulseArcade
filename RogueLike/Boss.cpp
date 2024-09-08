#include "Boss.h"
#include "World.h"
#include <iostream>
#include <random>
#include <cmath>
#include "Player.h"
#include "Actor.h"
#include "Sythe.h"

Boss::Boss(int x, int y)
{
    this->Pos.coords.x = x;
    this->Pos.coords.y = y;
    Tileset = World::Instance->Tileset;
    AnimSeq.WhichSprite = Actor::SpritePosition(DEVIL);
    AnimSeq.NumberOfFrames = 1;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    EnemyHealth = 3000;
    PlayerPtr = World::Instance->PlayerPtr;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void Boss::Move(float fElapsedTime)
{
    int TargetX = PlayerPtr->GetXY().x;
    int TargetY = PlayerPtr->GetXY().y;

    TVector2D<float> DToTarget = { TargetX - Pos.coords.x, TargetY - Pos.coords.y };

    float Distance = std::sqrt(DToTarget.x * DToTarget.x + DToTarget.y * DToTarget.y);

    if (this->Pos.coords.Distance(PlayerPtr->Pos.coords) != 0)
    {
        DToTarget.x /= this->Pos.coords.Distance(PlayerPtr->Pos.coords);
        DToTarget.y /= this->Pos.coords.Distance(PlayerPtr->Pos.coords);
    }
    float MoveSpeed = 5000.0f;
    Pos.coords.x += DToTarget.x * 20 * fElapsedTime;
    Pos.coords.y += DToTarget.y * 20 * fElapsedTime;
}
