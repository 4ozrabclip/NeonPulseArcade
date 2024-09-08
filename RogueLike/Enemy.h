#pragma once
#include "Character.h"
#include <memory>
class Player;
class Enemy : public Character
{
public:
	Enemy(int x, int y, Player* InPlayerPtr);
	virtual ~Enemy();

	virtual void Update(World* world, float fElapsedTime) override;
	virtual void Move(float fElapsedTime) override;
	virtual void ReceivePain();
	virtual bool HasCollided();
	virtual void SetHealth(int InHealth);
	virtual int GetHealth() { return EnemyHealth; }

protected:
	int EnemyHealth;
	float fEnemy_ElapsedTime;
private:
	Enemy(const Enemy& other);
	Player* PlayerPtr;

};