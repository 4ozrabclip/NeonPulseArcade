#include "Enemy.h"
#include "World.h"
#include <iostream>
#include <random>
#include <cmath>
#include "Player.h"

Enemy::Enemy(int x, int y, Player* InPlayerPtr)
{
    this->Pos.coords.x = x;
    this->Pos.coords.y = y;
    Tileset = World::Instance->Tileset;
    FAnimSequence animSequence;
    animSequence.WhichSprite = Actor::SpritePosition(ALIEN);
    animSequence.NumberOfFrames = 2;
    animSequence.SpriteSize = World::Instance->TileSize;
    animSequence.AnimationDuration = 1.0f;

    PlayerPtr = InPlayerPtr;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, animSequence);
}
Enemy::~Enemy()
{
}

void Enemy::Move(float fElapsedTime)
{
    int TargetX = PlayerPtr->GetXY().x;
    int TargetY = PlayerPtr->GetXY().y;

    float DToTargetX = TargetX - Pos.coords.x;
    float DToTargetY = TargetY - Pos.coords.y;

    float Distance = std::sqrt(DToTargetX * DToTargetX + DToTargetY * DToTargetY);

    if (Distance != 0)
    {
        DToTargetX /= Distance;
        DToTargetY /= Distance;
    }
    else {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(-1, 1);
        Pos.coords.x += distr(gen);
        Pos.coords.y += distr(gen);
    }
    float MoveSpeed = 1000.0f;
    Pos.coords.x += DToTargetX * 10 * fElapsedTime;
    Pos.coords.y += DToTargetY * 10 * fElapsedTime;

    if (Pos.coords.x >= 240 - 12)   
    {
        Pos.coords.x = 240 - 12;
    }
    if (Pos.coords.x <= 0)
    {
        Pos.coords.x = 0;
    }
    if (Pos.coords.y >= 240 - 12)
    {
        Pos.coords.y = 240 - 12;
    }
    if (Pos.coords.y <= 0)
    {
        Pos.coords.y = 0;
    }
}

void Enemy::Update(float fElapsedTime)
{
    olc::vi2d position(Pos.coords.x, Pos.coords.y);

    fEnemy_ElapsedTime += fElapsedTime;
    Move(fElapsedTime);
    //if (fEnemy_ElapsedTime >= 0.1) {

    //    fEnemy_ElapsedTime = 0;
    //}
    Draw(World::Instance, fElapsedTime);
}