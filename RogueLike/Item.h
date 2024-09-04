#pragma once
#include "Actor.h"
#include "Player.h"

class Item : public Actor
{
public:
	Item();
	Item(int x, int y);
	virtual void TakeItem();
	virtual void Update(World* world, float fElapsedTime);

	virtual void ItemEffect();
protected:
	bool bItemTaken;
	Player* PlayerPtr;

};