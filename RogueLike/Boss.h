#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
public:
	Boss(int x, int y);

	virtual void Move(float fElapsedTime) override;


};

