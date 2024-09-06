#include "Dungeon1.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Door.h"
#include "Enemy.h"
Dungeon1::Dungeon1()
{
	MapLayout = std::make_unique<int[]>(400);
}
void Dungeon1::DrawRoom(World* world)
{
	FAnimSequence BrickSprite;
	BrickSprite.NumberOfFrames = 2;
	BrickSprite.SpriteSize = world->TileSize;
	BrickSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = BRICKS;
	BrickSprite.WhichSprite = Actor::SpritePosition(BRICKS);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, BrickSprite);
	Draw(world, 0);

	FAnimSequence SpeakerSprite;
	SpeakerSprite.NumberOfFrames = 2;
	SpeakerSprite.SpriteSize = world->TileSize;
	SpeakerSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = SPEAKER;
	SpeakerSprite.WhichSprite = Actor::SpritePosition(SPEAKER);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, SpeakerSprite);
	Draw(world, 0);

	FAnimSequence DeskLeftSprite;
	DeskLeftSprite.NumberOfFrames = 2;
	DeskLeftSprite.SpriteSize = world->TileSize;
	DeskLeftSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = DESK_LEFT;
	DeskLeftSprite.WhichSprite = Actor::SpritePosition(DESK_LEFT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskLeftSprite);
	Draw(world, 0);
	FAnimSequence DeskDecksRabSprite;
	DeskDecksRabSprite.NumberOfFrames = 2;
	DeskDecksRabSprite.SpriteSize = world->TileSize;
	DeskDecksRabSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = DESK_DECKS_RAB;
	DeskDecksRabSprite.WhichSprite = Actor::SpritePosition(DESK_DECKS_RAB);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskDecksRabSprite);
	Draw(world, 0);

	FAnimSequence DeskRightSprite;
	DeskRightSprite.NumberOfFrames = 2;
	DeskRightSprite.SpriteSize = world->TileSize;
	DeskRightSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = DESK_RIGHT;
	DeskRightSprite.WhichSprite = Actor::SpritePosition(DESK_RIGHT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskRightSprite);
	Draw(world, 0);


}
void Dungeon1::SetMap(int map[])
{
	std::copy(map, map + 400, Map::MapLayout.get());
}

void Dungeon1::InitDungeon(World* world)
{
	//Static Init-------------------------------------------------------------------
	MapLayout = std::make_unique<int[]>(400);
	int D1Map[400] = {
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

	SetMap(D1Map);
	/*FAnimSequence BrickSprite;
	BrickSprite.NumberOfFrames = 2;
	BrickSprite.SpriteSize = world->TileSize;
	BrickSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = BRICKS;
	BrickSprite.WhichSprite = Actor::SpritePosition(BRICKS);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, BrickSprite);
	Draw(world, 0);

	FAnimSequence SpeakerSprite;
	SpeakerSprite.NumberOfFrames = 2;
	SpeakerSprite.SpriteSize = world->TileSize;
	SpeakerSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = SPEAKER;
	SpeakerSprite.WhichSprite = Actor::SpritePosition(SPEAKER);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, SpeakerSprite);
	Draw(world, 0);

	FAnimSequence DeskLeftSprite;
	DeskLeftSprite.NumberOfFrames = 2;
	DeskLeftSprite.SpriteSize = world->TileSize;
	DeskLeftSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = DESK_LEFT;
	DeskLeftSprite.WhichSprite = Actor::SpritePosition(DESK_LEFT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskLeftSprite);
	Draw(world, 0);
	FAnimSequence DeskDecksRabSprite;
	DeskDecksRabSprite.NumberOfFrames = 2;
	DeskDecksRabSprite.SpriteSize = world->TileSize;
	DeskDecksRabSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = DESK_DECKS_RAB;
	DeskDecksRabSprite.WhichSprite = Actor::SpritePosition(DESK_DECKS_RAB);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskDecksRabSprite);
	Draw(world, 0);

	FAnimSequence DeskRightSprite;
	DeskRightSprite.NumberOfFrames = 2;
	DeskRightSprite.SpriteSize = world->TileSize;
	DeskRightSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = DESK_RIGHT;
	DeskRightSprite.WhichSprite = Actor::SpritePosition(DESK_RIGHT);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskRightSprite);
	Draw(world, 0);*/

	//Static Init Fin---------------------------------------------------------------
	Actor** Dungeon1Actors = new Actor * [15];

	Dungeon1Actors[0] = new Enemy(20, 100, World::Instance->PlayerPtr);
	Dungeon1Actors[1] = new Enemy(120, 100, World::Instance->PlayerPtr);
	Dungeon1Actors[2] = new Enemy(220, 100, World::Instance->PlayerPtr);
	Dungeon1Actors[3] = new Wood(11, 14);
	Dungeon1Actors[4] = new Wood(11, 15);
	Dungeon1Actors[5] = new Wood(11, 16);
	Dungeon1Actors[6] = new Wood(11, 17);
	Dungeon1Actors[7] = new Wood(11, 18);
	Dungeon1Actors[8] = new Wood(12, 14);
	Dungeon1Actors[9] = new Wood(13, 14);
	Dungeon1Actors[10] = new Wood(16, 14);
	Dungeon1Actors[11] = new Wood(17, 14);
	Dungeon1Actors[12] = new Wood(18, 14);
	Dungeon1Actors[13] = new Door(19, 17);
	Dungeon1Actors[14] = new Pill(5, 8);

	for (size_t D1Actors = 0; D1Actors < 15; D1Actors++)
	{
		world->Actors.AddElement(Dungeon1Actors[D1Actors]);
	}
	delete[] Dungeon1Actors;
	//DrawRoom(world);
}
