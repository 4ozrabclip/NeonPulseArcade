#pragma once
#include "Item.h"
class LeaveDoor : public Item
{
public:
	LeaveDoor(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};