#pragma once
#include "Item.h"
class Door3 : public Item
{
public:
	Door3(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};