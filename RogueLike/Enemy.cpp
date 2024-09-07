#include "Enemy.h"
#include "World.h"
#include <iostream>
#include <random>
#include <cmath>
#include "Player.h"
#include "Actor.h"

Enemy::Enemy(int x, int y, Player* InPlayerPtr)
{
    this->Pos.coords.x = x;
    this->Pos.coords.y = y;
    Tileset = World::Instance->Tileset;
    AnimSeq.WhichSprite = Actor::SpritePosition(ALIEN);
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;

    PlayerPtr = InPlayerPtr;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, AnimSeq);
}
Enemy::~Enemy()
{
}
void Enemy::Update(World* world, float fElapsedTime)
{
    //olc::vi2d position(Pos.coords.x, Pos.coords.y);

    fEnemy_ElapsedTime += fElapsedTime;
    Move(fElapsedTime);
    Draw(world, fElapsedTime);
    ReceivePain();
    std::cout << "Actor Index: " << World::Instance->GetActorIndex() << std::endl;
    BorderStopper({ 220,220 }, { 10, 10 });
}
void Enemy::Move(float fElapsedTime)
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
    else {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(-1, 1);
        Pos.coords.x += distr(gen);
        Pos.coords.y += distr(gen);
    }
    float MoveSpeed = 1000.0f;
    Pos.coords.x += DToTarget.x * 10 * fElapsedTime;
    Pos.coords.y += DToTarget.y * 10 * fElapsedTime;
}

void Enemy::ReceivePain()
{
    int Index;
    if (PlayerPtr->GetWeapon() && RectangleCollision(PlayerPtr->Pos.coords))
    {
        Index = World::Instance->GetActorIndex();
        World::Instance->EnemyKilled(true, Index);

        //World::Instance->Actors.RemoveElement(Index);
        World::Instance->DrawRect(olc::vf2d(Pos.coords.x, Pos.coords.y), AnimSeq.SpriteSize, olc::RED);
    }
}

bool Enemy::HasCollided()
{
    float PlayerX = World::Instance->PlayerPtr->GetXY().x;
    float PlayerY = World::Instance->PlayerPtr->GetXY().y;

    float ItemX = this->GetXY().x;
    float ItemY = this->GetXY().y;

    //olc::vi2d PlayerPos = {PlayerX, PlayerY};

    float DeltaX = PlayerX - ItemX;
    float DeltaY = PlayerY - ItemY;
    float DistanceSquared = DeltaX * DeltaX + DeltaY * DeltaY;

    return DistanceSquared <= 6;
}

