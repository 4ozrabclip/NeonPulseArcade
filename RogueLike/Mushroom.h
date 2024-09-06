#pragma once
#include "Item.h"
class Mushroom : public Item
{
public:
	Mushroom(int x, int y);
	virtual void ItemEffect() override;
	//virtual void Update(World* world, float fElapsedTime) override;
};

