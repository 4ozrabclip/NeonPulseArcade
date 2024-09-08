#include "Dungeon3.h"
#include "Dungeon3.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Door.h"
#include "Enemy.h"
#include "Rabclip.h"
#include "Brick.h"
#include "Sythe.h"
#include "LockedGate.h"
#include "LockedGateRight.h"
#include "Key.h"
#include "DoorToStart.h"
#include "SecretLockedGate.h"
#include "SecretLockedGateRight.h"
#include "LeaveDoor.h"
Dungeon3::Dungeon3()
{
	MapLayout = std::make_unique<int[]>(400);

}
void Dungeon3::DrawRoom(World* world)
{
	FAnimSequence BrickSprite;
	BrickSprite.NumberOfFrames = 2;
	BrickSprite.SpriteSize = world->TileSize;
	BrickSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = BRICKS;
	BrickSprite.WhichSprite = Actor::SpritePosition(BRICKS);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, BrickSprite);
	Draw(world, 0);

	FAnimSequence WoodSprite;
	WhichSpriteInt = WOOD;
	WoodSprite.SpriteSize = World::Instance->TileSize;
	WoodSprite.NumberOfFrames = 2;
	WoodSprite.AnimationDuration = 1.0f;
	WoodSprite.WhichSprite = Actor::SpritePosition(WOOD);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, WoodSprite);
	Draw(world, 0);

	FAnimSequence SpeakerSprite;
	SpeakerSprite.NumberOfFrames = 2;
	SpeakerSprite.SpriteSize = world->TileSize;
	SpeakerSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = SPEAKER;
	SpeakerSprite.WhichSprite = Actor::SpritePosition(SPEAKER);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, SpeakerSprite);
	Draw(world, 0);

	FAnimSequence DeskLeftSprite;
	DeskLeftSprite.NumberOfFrames = 2;
	DeskLeftSprite.SpriteSize = world->TileSize;
	DeskLeftSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = DESK_LEFT_GREY;
	DeskLeftSprite.WhichSprite = Actor::SpritePosition(DESK_LEFT_GREY);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskLeftSprite);
	Draw(world, 0);

	FAnimSequence DeskDecksApaSprite;
	DeskDecksApaSprite.NumberOfFrames = 2;
	DeskDecksApaSprite.SpriteSize = world->TileSize;
	DeskDecksApaSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = DESK_DECKS_APA;
	DeskDecksApaSprite.WhichSprite = Actor::SpritePosition(DESK_DECKS_APA);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskDecksApaSprite);
	Draw(world, 0);

	FAnimSequence DeskRightSprite;
	DeskRightSprite.NumberOfFrames = 2;
	DeskRightSprite.SpriteSize = world->TileSize;
	DeskRightSprite.AnimationDuration = 1.0f;
	WhichSpriteInt = DESK_RIGHT_GREY;
	DeskRightSprite.WhichSprite = Actor::SpritePosition(DESK_RIGHT_GREY);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskRightSprite);
	Draw(world, 0);
}
void Dungeon3::SetMap(int map[])
{
	std::copy(map, map + 400, Map::MapLayout.get());
}

void Dungeon3::InitDungeon(World* world)
{
	World::Instance->PlayerPtr->SetHasKey(false);
	//Static Init-------------------------------------------------------------------
	MapLayout = std::make_unique<int[]>(400);
	int D1Map[400] = {
		5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 5  , 5 , 5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 0  , 5 ,
		5 , 0 , 0,  7,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 21, 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 22, 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 23, 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 7,  0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0,  0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 5  ,5 , 5 , 5 , 5 , 5 , 0 , 5  , 5 , 5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 5  , 5 ,
	};

	SetMap(D1Map);

	//Static Init Fin---------------------------------------------------------------
	
	Actor** Dungeon3Actors = new Actor * [32];

	Dungeon3Actors[0] = new Enemy(20, 100, World::Instance->PlayerPtr);
	Dungeon3Actors[1] = new Enemy(120, 100, World::Instance->PlayerPtr);
	Dungeon3Actors[2] = new Enemy(220, 100, World::Instance->PlayerPtr);
	Dungeon3Actors[3] = new Wood(13, 6);
	Dungeon3Actors[4] = new Wood(14, 6);
	Dungeon3Actors[5] = new Wood(15, 6);
	Dungeon3Actors[6] = new Wood(16, 6);
	Dungeon3Actors[7] = new Wood(17, 6);
	Dungeon3Actors[8] = new Wood(18, 6);
	Dungeon3Actors[9] = new Wood(13, 7);
	Dungeon3Actors[10] = new Wood(13, 8);
	Dungeon3Actors[11] = new Wood(13, 9);
	Dungeon3Actors[12] = new Wood(14, 9);
	Dungeon3Actors[13] = new LeaveDoor(19, 7);
	Dungeon3Actors[14] = new Sythe(17, 16);
	Dungeon3Actors[15] = new Rabclip(10, 1);
	Dungeon3Actors[16] = new SecretLockedGate(15, 9);
	Dungeon3Actors[17] = new SecretLockedGateRight(16, 9);
	Dungeon3Actors[18] = new Wood(17, 9);
	Dungeon3Actors[19] = new Wood(18, 9);
	Dungeon3Actors[20] = new Pill(17, 2);
	Dungeon3Actors[21] = new DoorToStart(0, 18);
	Dungeon3Actors[22] = new Brick(12, 8);
	Dungeon3Actors[23] = new Brick(11, 8);
	Dungeon3Actors[24] = new Brick(10, 8);
	Dungeon3Actors[25] = new Brick(9, 8);
	Dungeon3Actors[26] = new Brick(8, 8);
	Dungeon3Actors[27] = new Brick(7, 8);
	Dungeon3Actors[28] = new Brick(1, 8);
	Dungeon3Actors[29] = new Brick(2, 8);
	Dungeon3Actors[30] = new Brick(3, 8);
	Dungeon3Actors[31] = new Brick(4, 8);



	for (size_t D1Actors = 0; D1Actors < 32; D1Actors++)
	{
		world->Actors.AddElement(Dungeon3Actors[D1Actors]);
	}
	delete[] Dungeon3Actors;
	//PlaySound(TEXT("fucked1(tat2).wav"), 0, SND_FILENAME | SND_ASYNC);

	//DrawRoom(world);
}