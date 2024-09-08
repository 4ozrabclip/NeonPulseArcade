#pragma once
#include "Item.h"
class SecretKey : public Item
{
public:
	SecretKey(int x, int y);
	virtual void ItemEffect() override;
};

