#pragma once
#include "Character.h"
#include <memory>

class Enemy : public Character
{
public:
	Enemy(int x, int y);
	virtual ~Enemy();

	virtual void MakeNoise() const;

	virtual void Update(float fElapsedTime) override;
	virtual void Move(float fElapsedTime) override;

protected:
	float fEnemy_ElapsedTime;

private:
	Enemy(const Enemy& other);

};