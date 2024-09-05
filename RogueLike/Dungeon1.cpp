#include "Dungeon1.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Door.h"
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
		1 , 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 , 1 , 1  ,1 , 1 , 1 , 1 , 1 , 0 , 1  , 1 ,
	};

	SetMap(NewMap);
	DoorPtr = new Door(19, 17);
	PillPtr = new Pill(5, 8);
	WoodPtrs[0] = new Wood(11, 14);
	WoodPtrs[1] = new Wood(11, 15);
	WoodPtrs[2] = new Wood(11, 16);
	WoodPtrs[3] = new Wood(11, 17);
	WoodPtrs[4] = new Wood(11, 18);
	WoodPtrs[5] = new Wood(12, 14);
	WoodPtrs[6] = new Wood(13, 14);
	WoodPtrs[7] = new Wood(16, 14);








}
void Dungeon1::DrawRoom(World* world, float fElapsedTime)
{
	AnimSeq.NumberOfFrames = 2;
	AnimSeq.SpriteSize = World::Instance->TileSize;
	AnimSeq.AnimationDuration = 1.0f;

	WhichSpriteInt = BRICKS;
	AnimSeq.WhichSprite = Actor::SpritePosition(BRICKS);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, fElapsedTime);

	for (int i = 0; i < 8; ++i)
	{
		WoodPtrs[i]->Update(world, fElapsedTime);
	}
	//WhichSpriteInt = WOOD;
	//AnimSeq.WhichSprite = Actor::SpritePosition(WOOD);
	//AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	//Draw(world, fElapsedTime);

	//WhichSpriteInt = DOORLADY;
	//AnimSeq.WhichSprite = Actor::SpritePosition(DOORLADY);
	//AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	//Draw(world, fElapsedTime);

	DoorPtr->Update(world, fElapsedTime);

	WhichSpriteInt = SPEAKER;
	AnimSeq.NumberOfFrames = 2;
	AnimSeq.WhichSprite = Actor::SpritePosition(SPEAKER);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, fElapsedTime);

	WhichSpriteInt = DESK_LEFT;
	AnimSeq.WhichSprite = Actor::SpritePosition(DESK_LEFT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, fElapsedTime);

	WhichSpriteInt = DESK_DECKS_RAB;
	AnimSeq.WhichSprite = Actor::SpritePosition(DESK_DECKS_RAB);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, fElapsedTime);

	WhichSpriteInt = DESK_RIGHT;
	AnimSeq.WhichSprite = Actor::SpritePosition(DESK_RIGHT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, fElapsedTime);

	PillPtr->Update(world, fElapsedTime);

}
void Dungeon1::SetMap(int map[])
{
	std::copy(map, map + 400, MapLayout.get());
}
