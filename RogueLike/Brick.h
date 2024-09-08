#pragma once
#include "Item.h"
class Brick : public Item
{
public:
	Brick(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;

};