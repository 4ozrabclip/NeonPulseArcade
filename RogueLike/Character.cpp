#include "Character.h"
#include "World.h"
#include <iostream>
#include <random>
#include <algorithm>

Character::Character()
{
}

Character::~Character()
{
}


void Character::Move(float fElapsedTime)
{
}

void Character::Update(World* world, float fElapsedTime)
{
    
}

void Character::PushBackCollision(TVector2D<float> max, TVector2D<float> min)
{
    if (this->Pos.coords.x <= min.x)
    {
        this->Pos.coords.x = min.x;
    }
    if (this->Pos.coords.y <= min.y)
    {
        this->Pos.coords.y = min.y;
    }
    if (this->Pos.coords.x >= max.x)
    {
        this->Pos.coords.x = max.x;
    }
    if (this->Pos.coords.y >= max.y)
    {
        this->Pos.coords.y = max.y;
    }
}



void Character::SetXY(float InX, float InY)
{
    this->Pos.coords.x += InX;
    this->Pos.coords.y += InY;

}
