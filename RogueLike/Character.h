#pragma once
#include "Actor.h"
#include <memory>

enum MoveDirection {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Character : public Actor
{
public:

	Character();
	~Character();
	virtual void Move(float fElapsedTime);
	virtual void Update(World* world, float fElapsedTime);
	virtual void BorderStopper(TVector2D<float> max, TVector2D<float> min);

	virtual void SetDirection(MoveDirection InDir);
	virtual MoveDirection GetDirection();
	
	virtual void SetXY(float InX, float InY) override;
protected:
	MoveDirection Direction;
};

