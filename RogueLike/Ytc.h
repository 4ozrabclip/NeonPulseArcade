#pragma once
#include "Character.h"
class Ytc : public Character
{
public:
	Ytc(int x, int y);
	virtual void Move(float fElapsedTime) override;
	virtual void Update(World* world, float fElapsedTime) override;

private:
	float StartPosition;
	float WalkSpeed;
};

