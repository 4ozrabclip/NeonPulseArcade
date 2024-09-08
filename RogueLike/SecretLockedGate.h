#pragma once
#include "Item.h"
class SecretLockedGate : public Item
{
public:
	SecretLockedGate(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;
};