#include "Player.h"
#include "World.h"
#include <iostream>
#include <random>

Player::Player(int x, int y)
{
    this->X = x;
    this->Y = y;
    

    Tileset = World::Instance->Tileset;
    FAnimSequence animSequence;
    EAnimationType AnimType = EAnimationType::STILL;
    animSequence.WhichSprite = Actor::SpritePosition(RABCLIP);
    animSequence.NumberOfFrames = 4;
    animSequence.SpriteSize = World::Instance->TileSize;
    animSequence.AnimationDuration = 1.0f;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, AnimType, animSequence);
}

Player::~Player()
{
}

void Player::Draw(World* World, float fElapsedTime) const
{
    olc::vi2d position(X, Y);

    if (AnimatedSpritePtr)
    {
        AnimatedSpritePtr->DrawAt(fElapsedTime, position);
    }
    else
    {
        World->DrawRect(position, olc::vi2d(8, 8), olc::Pixel(255, 0, 0));
    }
}

void Player::Update(float fElapsedTime)
{
    Move(fElapsedTime);
}

void Player::Move(float fElapsedTime)
{
    float x = 0, y = 0;

    if (World::Instance->GetKey(olc::Key::LEFT).bHeld)
    {
        x -= 100 * fElapsedTime;
        AnimatedSpritePtr->SetAnimationType(EAnimationType::LOOP_FOREVER);
    }
    else if (World::Instance->GetKey(olc::Key::RIGHT).bHeld)
    {
        x += 100 * fElapsedTime;
        AnimatedSpritePtr->SetAnimationType(EAnimationType::LOOP_FOREVER);
    }
    else if (World::Instance->GetKey(olc::Key::UP).bHeld)
    {
        y -= 100 * fElapsedTime;
        AnimatedSpritePtr->SetAnimationType(EAnimationType::LOOP_FOREVER);
    }
    else if (World::Instance->GetKey(olc::Key::DOWN).bHeld)
    {
        y += 100 * fElapsedTime;
        AnimatedSpritePtr->SetAnimationType(EAnimationType::LOOP_FOREVER);
    }
    else {
        AnimatedSpritePtr->SetAnimationType(EAnimationType::STILL);
    }

    SetXY(x, y);

}

void Player::SetXY(float InX, float InY)
{
    X += InX;
    Y += InY;

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
