#include "Sythe.h"
#include "World.h"
#include "Player.h"

Sythe::Sythe(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    AnimSeq.WhichSprite = Actor::SpritePosition(SWORD);
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
    PlayerPtr = World::Instance->PlayerPtr;
    SytheHealth = 100;

}
void Sythe::ItemEffect()
{
    PlayerPtr->SetWeapon(true);
}

void Sythe::Update(World* world, float fElapsedTime)
{
    if (PlayerPtr->GetAttacking() && SytheHealth > 0)
    {
        SytheHealth -= 10;
    }
    else if (SytheHealth <= 0)
    {

    }
}

void Sythe::SetSytheHealth(int InSytheHealth)
{
    SytheHealth = InSytheHealth;
}

int Sythe::GetSytheHealth()
{
    return SytheHealth;
}
