#pragma once
#include "Character.h"
class Rabclip : public Character
{
public:
	Rabclip(int x, int y);
	virtual void Move(float fElapsedTime) override;
	virtual void Update(World* world, float fElapsedTime) override;

private:
	float moveSpeed; 
	float moveRange; 
	float moveDirection; 
	float moveTimeAccumulator;
};

