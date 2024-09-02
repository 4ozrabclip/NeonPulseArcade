#pragma once
#include "Character.h"
#include "AnimatedSprite.h"
#include <memory>

class Player : public Character
{
public:
	Player(int x, int y);
	virtual ~Player();

	virtual void Draw(class World* World, float fElapsedTime) const override;

	virtual void Update(float fElapsedTime) override;
	virtual void Move() override;

	void SetXY(float x, float y);

protected:
	float fPlayer_ElapsedTime;
private:
	Player(const Player& other);
};

