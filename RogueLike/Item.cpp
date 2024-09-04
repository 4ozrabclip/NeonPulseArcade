#include "Item.h"
#include "World.h"

Item::Item(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
	PlayerPtr = World::Instance->PlayerPtr;
}
void Item::TakeItem()
{
	float PlayerX = PlayerPtr->GetXY().x;
	float PlayerY = PlayerPtr->GetXY().y;

	float ItemX = this->GetXY().x;
    float ItemY = this->GetXY().y;

	//olc::vi2d PlayerPos = {PlayerX, PlayerY};

    float deltaX = PlayerX - ItemX;
    float deltaY = PlayerY - ItemY;
    float distanceSquared = deltaX * deltaX + deltaY * deltaY;

    if (distanceSquared <= 1)
    {
        
    }
}
