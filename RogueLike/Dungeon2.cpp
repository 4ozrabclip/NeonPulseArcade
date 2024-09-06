#include "Dungeon2.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Mushroom.h"
#include "Door.h"
#include "Enemy.h"

Dungeon2::Dungeon2()
{

}

void Dungeon2::DrawRoom(World* world)
{
	AnimSeq.NumberOfFrames = 2;
	AnimSeq.SpriteSize = World::Instance->TileSize;
	AnimSeq.AnimationDuration = 1.0f;

	WhichSpriteInt = WOOD;
	AnimSeq.WhichSprite = Actor::SpritePosition(WOOD);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, 0);

	WhichSpriteInt = SPEAKER;
	AnimSeq.NumberOfFrames = 2;
	AnimSeq.WhichSprite = Actor::SpritePosition(SPEAKER);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, 0);

	WhichSpriteInt = DESK_LEFT;
	AnimSeq.WhichSprite = Actor::SpritePosition(DESK_LEFT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, 0);

	WhichSpriteInt = DESK_DECKS_RAB;
	AnimSeq.WhichSprite = Actor::SpritePosition(DESK_DECKS_RAB);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, 0);

	WhichSpriteInt = DESK_RIGHT;
	AnimSeq.WhichSprite = Actor::SpritePosition(DESK_RIGHT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
	Draw(world, 0);

}

void Dungeon2::SetMap(int map[])
{
	std::copy(map, map + 400, MapLayout.get());
}

void Dungeon2::InitDungeon(World* world)
{
	MapLayout = std::make_unique<int[]>(400);
	int D2Map[400] = {
		5 , 5 , 0 , 5 , 5 , 5 , 5 , 5 , 5  , 5 , 5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 5  , 5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 5  , 5 , 5 , 5  ,5 , 5 , 5 , 5 , 5 , 12, 5  , 5 ,
	};
	SetMap(D2Map);

	Actor** Dungeon2Actors = new Actor * [15];

	Dungeon2Actors[0] = new Enemy(20, 100, World::Instance->PlayerPtr);
	Dungeon2Actors[1] = new Enemy(120, 100, World::Instance->PlayerPtr);
	Dungeon2Actors[2] = new Enemy(220, 100, World::Instance->PlayerPtr);
	Dungeon2Actors[3] = new Wood(11, 14);
	Dungeon2Actors[4] = new Wood(11, 15);
	Dungeon2Actors[5] = new Wood(11, 16);
	Dungeon2Actors[6] = new Wood(11, 17);
	Dungeon2Actors[7] = new Wood(11, 18);
	Dungeon2Actors[8] = new Wood(12, 14);
	Dungeon2Actors[9] = new Wood(13, 14);
	Dungeon2Actors[10] = new Wood(16, 14);
	Dungeon2Actors[11] = new Wood(17, 14);
	Dungeon2Actors[12] = new Wood(18, 14);
	Dungeon2Actors[13] = new Door(0, 2);
	Dungeon2Actors[14] = new Mushroom(5, 8);

	for (size_t D1Actors = 0; D1Actors < 15; D1Actors++)
	{
		world->Actors.AddElement(Dungeon2Actors[D1Actors]);
	}

	delete[] Dungeon2Actors;
	//DrawRoom(world);
}