#include "Player.h"
#include "World.h"
#include <iostream>
#include <random>

Player::Player(int x, int y)
{
    this->Pos.x = x;
    this->Pos.y = y;
    Tileset = World::Instance->Tileset;
    FAnimSequence animSequence;
    animSequence.WhichSprite = Actor::SpritePosition(RABCLIP);
    animSequence.NumberOfFrames = 4;
    animSequence.SpriteSize = World::Instance->TileSize;
    animSequence.AnimationDuration = 1.0f;
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
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
    Pos.x += InX;
    Pos.y += InY;

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
