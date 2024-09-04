#pragma once
#include "Item.h"
class Door : public Item
{
public:
	Door(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};

