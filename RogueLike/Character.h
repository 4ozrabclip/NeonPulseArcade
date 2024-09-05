#pragma once
#include "Actor.h"
#include <memory>

class Character : public Actor
{
public:

	Character();
	~Character();
	virtual void Move(float fElapsedTime);
	virtual void Update(World* world, float fElapsedTime);
	virtual void PushBackCollision(TVector2D<float> max, TVector2D<float> min);

	virtual void SetXY(float InX, float InY) override;
protected:
};

