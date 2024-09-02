#include "Player.h"
#include "World.h"
#include <iostream>
#include <random>

Player::Player(int x, int y)
{
    this->X = x;
    this->Y = y;
    AnimatedSpritePtr = nullptr;

    Tileset = std::make_shared<olc::Sprite>("tileset.png");
    FAnimSequence animSequence;
    animSequence.WhichSprite = olc::vi2d(469, 80);
    animSequence.NumberOfFrames = 4;
    animSequence.SpriteSize = olc::vi2d(12, 12);
    animSequence.AnimationDuration = 1.0f;

    this->SetAnimatedSprite(std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, animSequence));
}

Player::~Player()
{
}

void Player::Draw(World* World, float fElapsedTime) const
{
    olc::vi2d position(Actor::X, Actor::Y);

    if (AnimatedSpritePtr.get())
    {
        AnimatedSpritePtr.get()->DrawAt(fElapsedTime, position);
    }
    else
    {
        // If there's no AnimatedSprite, draw a placeholder rectangle
        olc::Pixel color(255, 0, 0, 255);
        olc::vi2d size(8, 8);
        World->DrawRect(position, size, color);
    }
}

void Player::Update(float fElapsedTime)
{
    Move();

}

void Player::Move()
{
    // check collisions
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

void Player::SetXY(float x, float y)
{
    X += x;
    Y += y;
}
