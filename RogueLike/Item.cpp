#include "Item.h"
#include "World.h"

Item::Item()
{
    PlayerPtr = World::Instance->PlayerPtr;

    bItemTaken = false;
}

Item::Item(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;

    
}
void Item::TakeItem()
{

}

void Item::Update(World* world, float fElapsedTime)
{
    float PlayerX = PlayerPtr->GetXY().x;
    float PlayerY = PlayerPtr->GetXY().y;

    float ItemX = this->GetXY().x;
    float ItemY = this->GetXY().y;

    //olc::vi2d PlayerPos = {PlayerX, PlayerY};

    float deltaX = PlayerX - ItemX;
    float deltaY = PlayerY - ItemY;
    float distanceSquared = deltaX * deltaX + deltaY * deltaY;

    if (distanceSquared <= 6)
    {
        bItemTaken = true;
    }

    if (!bItemTaken)
    {
        Draw(world, fElapsedTime);
    }
    else {
        ItemEffect();
        std::cout << "item taken: " << bItemTaken << std::endl;
    }
}

void Item::ItemEffect()
{

}
