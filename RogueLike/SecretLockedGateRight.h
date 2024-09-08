#pragma once
#include "Item.h"
class SecretLockedGateRight : public Item
{
public:
	SecretLockedGateRight(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};