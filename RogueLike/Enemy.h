#pragma once
#include "Character.h"
#include "AnimatedSprite.h"
#include <memory>

class Enemy : public Character
{
public:
	Enemy(int x, int y);
	virtual ~Enemy();

	virtual void MakeNoise() const;
	virtual void Draw(class World* World, float fElapsedTime) const override;

	virtual void Update(float fElapsedTime) override;
	virtual void Move(float fElapsedTime) override;




protected:
	// Enemie world position
	//int X;
	//int Y;

	float fEnemy_ElapsedTime;

private:
	Enemy(const Enemy& other);

	//std::shared_ptr<AnimatedSprite> AnimatedSpritePtr;
};