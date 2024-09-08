#pragma once
#include "Item.h"
class Sythe : public Item
{
public:
	Sythe(int x, int y);
	virtual void ItemEffect() override;
	virtual void Update(World* world, float fElapsedTime) override;
	void SetSytheHealth(int InSytheHealth);
	int GetSytheHealth();
private:
	int SytheHealth;
	Player* PlayerPtr;
};

