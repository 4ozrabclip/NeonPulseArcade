#pragma once
#include "Item.h"
class DoorToStart : public Item
{
public:
	DoorToStart(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};