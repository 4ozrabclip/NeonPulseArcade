#pragma once
#include "Actor.h"
#include "Player.h"

class Item : public Actor
{
public:
	Item(int x, int y);
	virtual void TakeItem();

private:
	Player* PlayerPtr;
};

