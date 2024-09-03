#pragma once
#include "Character.h"
#include <memory>
class Player;
class Enemy : public Character
{
public:
	Enemy(int x, int y, Player* InPlayerPtr);
	virtual ~Enemy();

	virtual void Update(float fElapsedTime) override;
	virtual void Move(float fElapsedTime) override;

protected:
	float fEnemy_ElapsedTime;

private:
	Enemy(const Enemy& other);
	Player* PlayerPtr;

};