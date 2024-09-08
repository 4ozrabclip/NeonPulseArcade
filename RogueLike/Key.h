#pragma once
#include "Item.h"
class Key : public Item
{
public:
	Key(int x, int y);
	virtual void ItemEffect() override;
};

