#pragma once
#include "Character.h"
#include <memory>


class Player : public Character
{
public:
	Player(int x, int y);
	virtual ~Player();

	virtual void Update(float fElapsedTime) override;
	virtual void Move(float fElapsedTime) override;

	virtual void SetXY(float InX, float InY);
	virtual olc::vi2d GetXY();

protected:
	float fPlayer_ElapsedTime;
private:
	Player(const Player& other);
};