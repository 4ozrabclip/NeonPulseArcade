#pragma once
#include "Character.h"
#include <memory>


class Player : public Character
{
public:
	Player(int x, int y);
	virtual ~Player();

	virtual void Update(World* world, float fElapsedTime) override;
	virtual void Move(float fElapsedTime) override;

	virtual void SetXY(float InX, float InY) override;
	virtual olc::vi2d GetXY();
	virtual void SetMoveSpeed(int InMoveSpeed);
	virtual int GetMoveSpeed();


protected:
	float fPlayer_ElapsedTime;
	int MoveSpeed;
private:
	Player(const Player& other);
};