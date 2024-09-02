#include "Enemy.h"
#include "World.h"
#include <iostream>
#include <random>

//#define DEBUG_PRINT_CONSTRUCTORS

Enemy::Enemy(int x, int y)
{
    this->X = x;
    this->Y = y;
    AnimatedSpritePtr = nullptr;

    Tileset = World::Instance->Tileset;
    FAnimSequence animSequence;
    EAnimationType animType = EAnimationType::LOOP_FOREVER;
    animSequence.WhichSprite = Actor::SpritePosition(ALIEN);
    animSequence.NumberOfFrames = 2;
    animSequence.SpriteSize = World::Instance->TileSize;
    animSequence.AnimationDuration = 1.0f;

    this->SetAnimatedSprite(std::make_shared<AnimatedSprite>(Tileset, animType, animSequence));

    std::cout << "Constructor called on object at: " << this << " (Enemy)." << std::endl;

}

Enemy::~Enemy()
{
    std::cout << "Destructor called on object at: " << this << " (Enemy)." << std::endl;

}

void Enemy::MakeNoise() const
{

    std::cout << "Enemy [" << this << "] makes generic noise." << std::endl;

}

void Enemy::Draw(World* World, float fElapsedTime) const
{
    olc::vi2d position(X, Y);

    //olc::Pixel color(255, 0, 0, 255);

    //olc::vi2d size(8, 8);

    //World->DrawRect(position, size, color);

    if (AnimatedSpritePtr.get())
    {
        AnimatedSpritePtr.get()->DrawAt(fElapsedTime, position);
    }
    else
    {
        olc::Pixel color(255, 0, 0, 255);
        olc::vi2d size(8, 8);
        World->DrawRect(position, size, color);
    }
}

void Enemy::Move(float fElapsedTime)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-1, 1);
    X += distr(gen);
    Y += distr(gen);

    if (X >= 256 - 12)   //max x boundry
    {
        X = 256 - 12;
    }
    if (X <= 0)     //min x boundry
    {
        X = 0;
    }
    if (Y >= 240 - 12)   //max y boundry
    {
        Y = 240 - 12;
    }
    if (Y <= 0)     //min x boundry
    {
        Y = 0;
    }

}

void Enemy::Update(float fElapsedTime)
{
    olc::vi2d position(X, Y);

    fEnemy_ElapsedTime += fElapsedTime;
    if (fEnemy_ElapsedTime >= 0.1) {
        Move(fElapsedTime);
        fEnemy_ElapsedTime = 0;
    }

    if (AnimatedSpritePtr.get())
    {
        AnimatedSpritePtr.get()->DrawAt(fElapsedTime, position);
    }
}