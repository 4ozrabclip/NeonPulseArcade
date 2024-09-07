#pragma once
#include "Character.h"
#include <memory>

enum MoveDirection {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Player : public Character
{
public:
	Player(int x, int y);
	virtual ~Player();

	virtual void Update(World* world, float fElapsedTime) override;
	virtual void Move(float fElapsedTime) override;
	virtual void SetXY(float InX, float InY) override;

	void SetDirection(MoveDirection dir);
	MoveDirection GetDirection();
	virtual olc::vi2d GetXY();
	virtual void SetMoveSpeed(int InMoveSpeed);
	virtual int GetMoveSpeed();
	void SetWeapon(bool HoldingWeapon);
	bool GetWeapon();
	bool FacingLeft;
protected:
	float fPlayer_ElapsedTime;
	int MoveSpeed;
private:
	MoveDirection Direction;
	bool HoldingWeapon;
	Player(const Player& other);
};