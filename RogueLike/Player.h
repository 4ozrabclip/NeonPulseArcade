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
	virtual void Move(float fElapsedTime) override;

	void SetXY(float InX, float InY);

protected:
	float fPlayer_ElapsedTime;
private:
	Player(const Player& other);
	std::shared_ptr<AnimatedSprite> AnimatedSpritePtr;
};

