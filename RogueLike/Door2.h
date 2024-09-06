#pragma once
#include "Item.h"
class Door2 : public Item
{
public:
	Door2(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};