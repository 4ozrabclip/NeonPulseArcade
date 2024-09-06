#include "Rabclip.h"
#include "World.h"

Rabclip::Rabclip(int x, int y)
{
	this->Pos.coords.x = x * 12;
	this->Pos.coords.y = y * 12;
    Tileset = World::Instance->Tileset;
    AnimSeq.WhichSprite = Actor::SpritePosition(RABCLIP_SING);
    AnimSeq.NumberOfFrames = 3;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    moveSpeed = 1.0f;
    moveRange = 2.0f;
    moveDirection = 1.0f;
    moveTimeAccumulator = 0.0f;
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, AnimSeq);
}

void Rabclip::Move(float fElapsedTime)
{

    moveTimeAccumulator += fElapsedTime;

    float movementOffset = moveRange * std::sin(moveTimeAccumulator * moveSpeed);

    Pos.coords.x += movementOffset * moveDirection;

    if (movementOffset >= moveRange || movementOffset <= -moveRange) {
        moveDirection *= -1;
    }
}

void Rabclip::Update(World* world, float fElapsedTime)
{
    Move(fElapsedTime);
    Draw(world, fElapsedTime);
}
