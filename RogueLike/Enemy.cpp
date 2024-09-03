#include "Enemy.h"
#include "World.h"
#include <iostream>
#include <random>

Enemy::Enemy(int x, int y)
{
    this->Pos.x = x;
    this->Pos.y = y;
    Tileset = World::Instance->Tileset;
    FAnimSequence animSequence;
    animSequence.WhichSprite = Actor::SpritePosition(ALIEN);
    animSequence.NumberOfFrames = 2;
    animSequence.SpriteSize = World::Instance->TileSize;
    animSequence.AnimationDuration = 1.0f;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, animSequence);
}
Enemy::~Enemy()
{
}

void Enemy::MakeNoise() const
{
    std::cout << "Enemy [" << this << "] makes generic noise." << std::endl;
}

void Enemy::Move(float fElapsedTime)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-1, 1);
    Pos.x += distr(gen);
    Pos.y += distr(gen);

    if (Pos.x >= 256 - 12)   
    {
        Pos.x = 256 - 12;
    }
    if (Pos.x <= 0)
    {
        Pos.x = 0;
    }
    if (Pos.y >= 240 - 12)
    {
        Pos.y = 240 - 12;
    }
    if (Pos.y <= 0)
    {
        Pos.y = 0;
    }
    }

void Enemy::Update(float fElapsedTime)
{
    olc::vi2d position(Pos.x, Pos.y);

    fEnemy_ElapsedTime += fElapsedTime;
    if (fEnemy_ElapsedTime >= 0.1) {
        Move(fElapsedTime);
        fEnemy_ElapsedTime = 0;
    }

    Draw(World::Instance, fElapsedTime);
    //if (AnimatedSpritePtr.get())
    //{
    //    AnimatedSpritePtr.get()->DrawAt(fElapsedTime, position);
    //}
}