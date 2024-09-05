#pragma once
#include "Item.h"
class Pill: public Item
{
public:
	Pill(int x, int y);
	virtual void ItemEffect() override;
	//virtual void Update(World* world, float fElapsedTime) override;
};

