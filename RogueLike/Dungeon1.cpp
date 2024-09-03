#include "Dungeon1.h"
#include "World.h"
#include "Brick.h"
#include "AnimatedSprite.h"
Dungeon1::Dungeon1()
{
	MapLayout = std::make_unique<int[]>(400);
	int NewMap[400] = {
		1 , 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 , 1 , 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  5,  5,  5,  5 ,  1 ,
		1 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 9 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 10, 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 11, 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 , 1 , 1  ,1 , 1 , 1 , 1 , 1 , 8 , 1  , 1 ,
	};

	SetMap(NewMap);


}
void Dungeon1::DrawRoom(World* world, float fElapsedTime)
{
	FAnimSequence animSequence;
	animSequence.NumberOfFrames = 2;
	animSequence.SpriteSize = World::Instance->TileSize;
	animSequence.AnimationDuration = 1.0f;

	WhichSpriteInt = BRICKS;
	animSequence.WhichSprite = Actor::SpritePosition(BRICKS);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
	Draw(world, fElapsedTime);

	WhichSpriteInt = WOOD;
	animSequence.WhichSprite = Actor::SpritePosition(WOOD);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
	Draw(world, fElapsedTime);

	WhichSpriteInt = DOORLADY;
	animSequence.WhichSprite = Actor::SpritePosition(DOORLADY);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
	Draw(world, fElapsedTime);

	WhichSpriteInt = SPEAKER;
	animSequence.NumberOfFrames = 2;
	animSequence.WhichSprite = Actor::SpritePosition(SPEAKER);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
	Draw(world, fElapsedTime);

	WhichSpriteInt = DESK_LEFT;
	animSequence.WhichSprite = Actor::SpritePosition(DESK_LEFT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
	Draw(world, fElapsedTime);

	WhichSpriteInt = DESK_DECKS_RAB;
	animSequence.WhichSprite = Actor::SpritePosition(DESK_DECKS_RAB);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
	Draw(world, fElapsedTime);

	WhichSpriteInt = DESK_RIGHT;
	animSequence.WhichSprite = Actor::SpritePosition(DESK_RIGHT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
	Draw(world, fElapsedTime);


}
void Dungeon1::SetMap(int map[])
{
	std::copy(map, map + 400, MapLayout.get());
}
