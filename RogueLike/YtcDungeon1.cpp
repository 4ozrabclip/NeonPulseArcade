#include "YtcDungeon1.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Door.h"
#include "Enemy.h"
#include "Ytc.h"
#include "Sythe.h"
#include "LockedGate.h"
#include "LockedGateRight.h"
#include "Key.h"
#include "DoorToStart.h"
#include "SecretKey.h"

YtcDungeon1::YtcDungeon1()
{
	bSecretKeyGiven = false;
	yurp = 21;
}

void YtcDungeon1::DrawRoom(World* world)
{
	FAnimSequence FancyWalls1Sprite;
	WhichSpriteInt = FANCYWALLS1;
	FancyWalls1Sprite.SpriteSize = World::Instance->TileSize;
	FancyWalls1Sprite.NumberOfFrames = 2;
	FancyWalls1Sprite.AnimationDuration = 1.0f;
	FancyWalls1Sprite.WhichSprite = Actor::SpritePosition(FANCYWALLS1);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, FancyWalls1Sprite);
	Draw(world, 0);

	FAnimSequence FancyWalls2Sprite;
	WhichSpriteInt = FANCYWALLS2;
	FancyWalls2Sprite.SpriteSize = World::Instance->TileSize;
	FancyWalls2Sprite.NumberOfFrames = 2;
	FancyWalls2Sprite.AnimationDuration = 1.0f;
	FancyWalls2Sprite.WhichSprite = Actor::SpritePosition(FANCYWALLS2);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, FancyWalls2Sprite);
	Draw(world, 0);

	FAnimSequence FancyWalls3Sprite;
	WhichSpriteInt = FANCYWALLS3;
	FancyWalls3Sprite.SpriteSize = World::Instance->TileSize;
	FancyWalls3Sprite.NumberOfFrames = 2;
	FancyWalls3Sprite.AnimationDuration = 1.0f;
	FancyWalls3Sprite.WhichSprite = Actor::SpritePosition(FANCYWALLS3);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, FancyWalls3Sprite);
	Draw(world, 0);

	FAnimSequence SpeakerSprite;
	WhichSpriteInt = SPEAKER;
	SpeakerSprite.SpriteSize = World::Instance->TileSize;
	SpeakerSprite.NumberOfFrames = 2;
	SpeakerSprite.AnimationDuration = 1.0f;
	SpeakerSprite.WhichSprite = Actor::SpritePosition(SPEAKER);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, SpeakerSprite);
	Draw(world, 0);

	FAnimSequence StairsSprite;
	WhichSpriteInt = DOORSTAIRS;
	StairsSprite.SpriteSize = World::Instance->TileSize;
	StairsSprite.NumberOfFrames = 2;
	StairsSprite.AnimationDuration = 1.0f;
	StairsSprite.WhichSprite = Actor::SpritePosition(DOORSTAIRS);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, StairsSprite);
	Draw(world, 0);

	FAnimSequence PalmTreeSprite;
	WhichSpriteInt = PALM_TREE;
	StairsSprite.SpriteSize = World::Instance->TileSize;
	StairsSprite.NumberOfFrames = 2;
	StairsSprite.AnimationDuration = 1.0f;
	StairsSprite.WhichSprite = Actor::SpritePosition(PALM_TREE);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, StairsSprite);
	Draw(world, 0);
}

void YtcDungeon1::SetMap(int map[])
{
	std::copy(map, map + 400, MapLayout.get());
}

void YtcDungeon1::InitDungeon(World* world)
{
	//Static Init ------------------------------------------------------------------------------
	MapLayout = std::make_unique<int[]>(400);
	int D2Map[400] = {
		29, 29, 0 , 29, 29, 29, 29, 29, 29 , 29, 29, 29 ,29, 29, 29, 29, 29, 29, 29 , 29,
		29, 0 , 0,  0,  0,  0,  0,  7,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  29,
		29, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  29,
		29, 0 ,34,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  29,
		30, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  30,
		30, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  30,
		30, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  30,
		30, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  30,
		30, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  30,
		30, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  30,
		30, 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  30,
		31, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  31,
		31, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  31,
		31, 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  31,
		31, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  31,
		31, 0 ,34,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  31,
		31, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  31,
		31, 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  31,
		31, 0 , 0,  0,  0,  0,  0,  7,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  31,
		31, 31 ,31, 31, 31, 31, 31, 31, 31 , 31, 31, 31 ,31, 31, 31, 31, 31, 12, 31 , 31,
	};
	SetMap(D2Map);

	//Static Init Fin -----------------------------------------------------------------------------------------

	YtcDungeon1Actors[0] = new Enemy(20, 100, World::Instance->PlayerPtr);
	YtcDungeon1Actors[1] = new Enemy(120, 100, World::Instance->PlayerPtr);
	YtcDungeon1Actors[2] = new Enemy(220, 100, World::Instance->PlayerPtr);
	YtcDungeon1Actors[3] = new Enemy(200, 60, World::Instance->PlayerPtr);
	YtcDungeon1Actors[4] = new Enemy(100, 60, World::Instance->PlayerPtr);
	YtcDungeon1Actors[5] = new Wood(15, 6);
	YtcDungeon1Actors[6] = new Wood(16, 6);
	YtcDungeon1Actors[7] = new Wood(17, 6);
	YtcDungeon1Actors[8] = new Wood(18, 6);
	YtcDungeon1Actors[9] = new Wood(13, 7);
	YtcDungeon1Actors[10] = new Wood(13, 8);
	YtcDungeon1Actors[11] = new Wood(13, 9);
	YtcDungeon1Actors[12] = new Wood(14, 9);
	YtcDungeon1Actors[13] = new DoorToStart(0, 2);
	YtcDungeon1Actors[14] = new Sythe(5, 8);
	YtcDungeon1Actors[15] = new Ytc(10, 3, this);
	YtcDungeon1Actors[16] = new LockedGate(15, 9);
	YtcDungeon1Actors[17] = new LockedGateRight(16, 9);
	YtcDungeon1Actors[18] = new Wood(17, 9);
	YtcDungeon1Actors[19] = new Wood(18, 9);
	YtcDungeon1Actors[20] = new Key(8, 9);
	YtcDungeon1Actors[21] = new SecretKey(15, 4);
	if (bSecretKeyGiven)
	{
		yurp = 22;
	}


	for (size_t D1Actors = 0; D1Actors < yurp; D1Actors++)
	{
		world->Actors.AddElement(YtcDungeon1Actors[D1Actors]);
	}
	PlaySound(TEXT("ESCAPE.wav"), 0, SND_FILENAME | SND_ASYNC);

}

void YtcDungeon1::DungeonUpdate(World* world)
{
	world->Actors.AddElement(YtcDungeon1Actors[21]);
	delete[] YtcDungeon1Actors;
}
