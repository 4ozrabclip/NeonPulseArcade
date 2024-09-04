#include "Player.h"
#include "World.h"
#include "Enemy.h"
#include <iostream>
#include <random>

Player::Player(int x, int y)
{
    this->Pos.coords.x = x;
    this->Pos.coords.y = y;
    Tileset = World::Instance->Tileset;
    FAnimSequence animSequence;
    animSequence.WhichSprite = Actor::SpritePosition(RABCLIP);
    animSequence.NumberOfFrames = 4;
    animSequence.SpriteSize = World::Instance->TileSize;
    animSequence.AnimationDuration = 1.0f;
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, animSequence);
}
Player::~Player()
{
}

void Player::Update(float fElapsedTime)
{
    Move(fElapsedTime);
    Draw(World::Instance, fElapsedTime);
    
}

void Player::Move(float fElapsedTime)
{
    float x = 0, y = 0;

    if (World::Instance->GetKey(olc::Key::LEFT).bHeld)
    {
        x -= 100 * fElapsedTime;
    }
    else if (World::Instance->GetKey(olc::Key::RIGHT).bHeld)
    {
        x += 100 * fElapsedTime;
    }
    else if (World::Instance->GetKey(olc::Key::UP).bHeld)
    {
        y -= 100 * fElapsedTime;
    }
    else if (World::Instance->GetKey(olc::Key::DOWN).bHeld)
    {
        y += 100 * fElapsedTime;
    }
    else {
    }
    SetXY(x, y);
}

void Player::SetXY(float InX, float InY)
{
    Pos.coords.x += InX;
    Pos.coords.y += InY;

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

olc::vi2d Player::GetXY()
{
    return olc::vi2d(Pos.coords.x, Pos.coords.y);
}
