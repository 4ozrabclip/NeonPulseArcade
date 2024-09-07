#pragma once
#include "Item.h"
class LockedGate : public Item
{
public:
	LockedGate(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};