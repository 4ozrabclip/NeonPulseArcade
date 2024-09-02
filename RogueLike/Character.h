#pragma once
#include "Actor.h"
#include "AnimatedSprite.h"
#include <memory>

class Character : public Actor
{
public:

	Character();
	~Character();

	virtual void Draw(class World* World, float fElapsedTime) const;
	void SetAnimatedSprite(std::shared_ptr<AnimatedSprite> AnimatedSprite);
	virtual void Move(float fElapsedTime);
protected:
	std::shared_ptr<AnimatedSprite> AnimatedSpritePtr;
	std::shared_ptr<olc::Sprite> Tileset;
};

