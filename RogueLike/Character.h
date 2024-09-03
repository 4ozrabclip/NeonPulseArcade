#pragma once
#include "Actor.h"
#include <memory>

class Character : public Actor
{
public:

	Character();
	~Character();

	virtual void Move(float fElapsedTime);
protected:
};

