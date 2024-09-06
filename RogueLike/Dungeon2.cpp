#include "Dungeon2.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Mushroom.h"
#include "Door.h"
#include "Door2.h"
#include "Enemy.h"

Dungeon2::Dungeon2()
{

}

void Dungeon2::DrawRoom(World* world)
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

void Dungeon2::SetMap(int map[])
{
	std::copy(map, map + 400, MapLayout.get());
}

void Dungeon2::InitDungeon(World* world)
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

	Actor** Dungeon2Actors = new Actor * [14];

	Dungeon2Actors[0] = new Enemy(20, 100, World::Instance->PlayerPtr);
	Dungeon2Actors[1] = new Enemy(120, 100, World::Instance->PlayerPtr);
	Dungeon2Actors[2] = new Enemy(220, 100, World::Instance->PlayerPtr);
	Dungeon2Actors[3] = new Wood(11, 14);
	Dungeon2Actors[4] = new Wood(11, 15);
	Dungeon2Actors[5] = new Wood(11, 16);
	Dungeon2Actors[6] = new Wood(11, 17);
	Dungeon2Actors[7] = new Wood(11, 18);
	Dungeon2Actors[8] = new Wood(11, 13);
	Dungeon2Actors[9] = new Wood(11, 12);
	Dungeon2Actors[10] = new Door2(0, 2);
	Dungeon2Actors[11] = new Mushroom(8, 3);
	Dungeon2Actors[12] = new Enemy(50, 160, World::Instance->PlayerPtr);
	Dungeon2Actors[13] = new Enemy(70, 140, World::Instance->PlayerPtr);

	for (size_t D1Actors = 0; D1Actors < 14; D1Actors++)
	{
		world->Actors.AddElement(Dungeon2Actors[D1Actors]);
	}

	delete[] Dungeon2Actors;
	PlaySound(TEXT("pcdopamine.wav"), 0, SND_FILENAME | SND_ASYNC);

	//DrawRoom(world);
}