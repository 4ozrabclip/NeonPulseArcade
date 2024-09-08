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
    if (PlayerPtr->RectangleCollision(this->Pos.coords))
    {
        bItemTaken = true;
    }

    if (!bItemTaken)
    {
        Draw(world, fElapsedTime);
    }
    else {
        ItemEffect();
    }
}

void Item::ItemEffect()
{

}
