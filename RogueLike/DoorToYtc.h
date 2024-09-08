#pragma once
#include "Item.h"
class DoorToYtc : public Item
{
public:
	DoorToYtc(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};