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
//bool Item::HasCollided()
//{
//    float PlayerX = PlayerPtr->GetXY().x;
//    float PlayerY = PlayerPtr->GetXY().y;
//
//    float ItemX = GetXY().x;
//    float ItemY = GetXY().y;
//
//    //olc::vi2d PlayerPos = {PlayerX, PlayerY};
//
//    float DeltaX = PlayerX - ItemX;
//    float DeltaY = PlayerY - ItemY;
//    float DistanceSquared = DeltaX * DeltaX + DeltaY * DeltaY;
//
//    return DistanceSquared <= 6;
//}
void Item::ItemEffect()
{

}
