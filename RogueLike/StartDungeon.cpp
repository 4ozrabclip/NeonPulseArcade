#include "StartDungeon.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Door.h"
#include "DoorToYtc.h"
#include "DoorToApa.h"
#include "Enemy.h"
StartDungeon::StartDungeon()
{
	MapLayout = std::make_unique<int[]>(400);
}
void StartDungeon::DrawRoom(World* world)
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
void StartDungeon::SetMap(int map[])
{
	std::copy(map, map + 400, Map::MapLayout.get());
}

void StartDungeon::InitDungeon(World* world)
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
		1 , 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 , 1 , 1  ,0 , 1 , 1 , 1 , 1 , 0 , 1  , 1 ,
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
	Actor** StartDungeonActors = new Actor * [15];

	StartDungeonActors[0] = new Enemy(20, 100, World::Instance->PlayerPtr);
	StartDungeonActors[1] = new DoorToApa(19, 4);
	StartDungeonActors[2] = new DoorToYtc(19, 12);
	StartDungeonActors[3] = new Wood(11, 14);
	StartDungeonActors[4] = new Wood(11, 15);
	StartDungeonActors[5] = new Wood(11, 16);
	StartDungeonActors[6] = new Wood(11, 17);
	StartDungeonActors[7] = new Wood(11, 18);
	StartDungeonActors[8] = new Wood(12, 14);
	StartDungeonActors[9] = new Wood(13, 14);
	StartDungeonActors[10] = new Wood(16, 14);
	StartDungeonActors[11] = new Wood(17, 14);
	StartDungeonActors[12] = new Wood(18, 14);
	StartDungeonActors[13] = new Door(19, 17);
	StartDungeonActors[14] = new Pill(5, 8);

	for (size_t D1Actors = 0; D1Actors < 15; D1Actors++)
	{
		world->Actors.AddElement(StartDungeonActors[D1Actors]);
	}
	delete[] StartDungeonActors;
	PlaySound(TEXT("fucked1(tat2).wav"), 0, SND_FILENAME | SND_ASYNC);

	//DrawRoom(world);
}
