#include "Character.h"
#include "World.h"
#include <iostream>
#include <random>

Character::Character()
{
    AnimatedSpritePtr = nullptr;
}

Character::~Character()
{
}

void Character::Draw(World* World, float fElapsedTime) const
{
    olc::vi2d position(Actor::X, Actor::Y);

    //olc::Pixel color(255, 0, 0, 255);

    //olc::vi2d size(8, 8);

    //World->DrawRect(position, size, color);

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

void Character::SetAnimatedSprite(std::shared_ptr<AnimatedSprite> AnimatedSprite)
{
    AnimatedSpritePtr = AnimatedSprite;
}

void Character::Move(float fElapsedTime)
{
}


