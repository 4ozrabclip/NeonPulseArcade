#pragma once
#include "Item.h"
class DoorToApa : public Item
{
public:
	DoorToApa(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};