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

YtcDungeon1::YtcDungeon1()
{

}

void YtcDungeon1::DrawRoom(World* world)
{
	FAnimSequence WoodSprite;
	WhichSpriteInt = WOOD;
	WoodSprite.SpriteSize = World::Instance->TileSize;
	WoodSprite.NumberOfFrames = 2;
	WoodSprite.AnimationDuration = 1.0f;
	WoodSprite.WhichSprite = Actor::SpritePosition(WOOD);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, WoodSprite);
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
		5 , 5 , 0 , 5 , 5 , 5 , 5 , 5 , 5  , 5 , 5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 5  , 5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 5  , 5 , 5 , 5  ,5 , 5 , 5 , 5 , 5 , 12, 5  , 5 ,
	};
	SetMap(D2Map);

	/*FAnimSequence WoodSprite;
	WhichSpriteInt = WOOD;
	WoodSprite.SpriteSize = World::Instance->TileSize;
	WoodSprite.NumberOfFrames = 2;
	WoodSprite.AnimationDuration = 1.0f;
	WoodSprite.WhichSprite = Actor::SpritePosition(WOOD);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, WoodSprite);
	Draw(world, 0);

	FAnimSequence SpeakerSprite;
	WhichSpriteInt = SPEAKER;
	SpeakerSprite.SpriteSize = World::Instance->TileSize;
	SpeakerSprite.NumberOfFrames = 2;
	SpeakerSprite.AnimationDuration = 1.0f;
	SpeakerSprite.WhichSprite = Actor::SpritePosition(SPEAKER);
	AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, SpeakerSprite);
	Draw(world, 0);*/
	//Static Init Fin -----------------------------------------------------------------------------------------

	Actor** YtcDungeon1Actors = new Actor * [21];

	YtcDungeon1Actors[0] = new Enemy(20, 100, World::Instance->PlayerPtr);
	YtcDungeon1Actors[1] = new Enemy(120, 100, World::Instance->PlayerPtr);
	YtcDungeon1Actors[2] = new Enemy(220, 100, World::Instance->PlayerPtr); 
	YtcDungeon1Actors[3] = new Wood(13, 6);
	YtcDungeon1Actors[4] = new Wood(14, 6);
	YtcDungeon1Actors[5] = new Wood(15, 6);
	YtcDungeon1Actors[6] = new Wood(16, 6);
	YtcDungeon1Actors[7] = new Wood(17, 6);
	YtcDungeon1Actors[8] = new Wood(18, 6);
	YtcDungeon1Actors[9] = new Wood(13, 7);
	YtcDungeon1Actors[10] = new Wood(13, 8);
	YtcDungeon1Actors[11] = new Wood(13, 9);
	YtcDungeon1Actors[12] = new Wood(14, 9);
	YtcDungeon1Actors[13] = new DoorToStart(19, 7);
	YtcDungeon1Actors[14] = new Sythe(5, 8);
	YtcDungeon1Actors[15] = new Ytc(10, 2);
	YtcDungeon1Actors[16] = new LockedGate(15, 9);
	YtcDungeon1Actors[17] = new LockedGateRight(16, 9);
	YtcDungeon1Actors[18] = new Wood(17, 9);
	YtcDungeon1Actors[19] = new Wood(18, 9);
	YtcDungeon1Actors[20] = new Key(8, 9);


	for (size_t D1Actors = 0; D1Actors < 21; D1Actors++)
	{
		world->Actors.AddElement(YtcDungeon1Actors[D1Actors]);
	}
	delete[] YtcDungeon1Actors;
	//PlaySound(TEXT("pcdopamine.wav"), 0, SND_FILENAME | SND_ASYNC);

	//DrawRoom(world);
}