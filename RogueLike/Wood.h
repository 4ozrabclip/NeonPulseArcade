#pragma once
#include "Item.h"
class Wood : public Item
{
public:
	Wood(int x, int y);
	virtual void Update(World* world, float fElapsedTime) override;
	virtual void ItemEffect() override;


};