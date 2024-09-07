#pragma once
#include "Item.h"
class LockedGateRight : public Item
{
public:
	LockedGateRight(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};