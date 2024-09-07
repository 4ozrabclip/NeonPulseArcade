#include "Dungeon3.h"
#include "Dungeon3.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Door.h"
#include "Enemy.h"
#include "Rabclip.h"
#include "Sythe.h"
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
	//Static Init-------------------------------------------------------------------
	MapLayout = std::make_unique<int[]>(400);
	int D1Map[400] = {
		5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 5  , 5 , 5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 5  , 5 ,
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
		5 , 23, 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  5,  5,  5,  5 ,  5 ,
		5 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  5 ,
		5 , 7,  0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0,  0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  5 ,
		5 , 0 , 0,  7,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  5 ,
		5 , 5  ,5 , 5 , 5 , 5 , 5 , 5 , 5  , 5 , 5 , 5  ,5 , 5 , 5 , 5 , 5 , 0 , 5  , 5 ,
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
	Actor** Dungeon3Actors = new Actor * [16];

	Dungeon3Actors[0] = new Enemy(20, 100, World::Instance->PlayerPtr);
	Dungeon3Actors[1] = new Enemy(120, 100, World::Instance->PlayerPtr);
	Dungeon3Actors[2] = new Enemy(220, 100, World::Instance->PlayerPtr);
	Dungeon3Actors[3] = new Wood(11, 14);
	Dungeon3Actors[4] = new Wood(11, 15);
	Dungeon3Actors[5] = new Wood(11, 16);
	Dungeon3Actors[6] = new Wood(11, 17);
	Dungeon3Actors[7] = new Wood(11, 18);
	Dungeon3Actors[8] = new Wood(12, 14);
	Dungeon3Actors[9] = new Wood(13, 14);
	Dungeon3Actors[10] = new Wood(16, 14);
	Dungeon3Actors[11] = new Wood(17, 14);
	Dungeon3Actors[12] = new Wood(18, 14);
	Dungeon3Actors[13] = new Door(19, 17);
	Dungeon3Actors[14] = new Sythe(5, 8);
	Dungeon3Actors[15] = new Rabclip(10, 1);

	for (size_t D1Actors = 0; D1Actors < 16; D1Actors++)
	{
		world->Actors.AddElement(Dungeon3Actors[D1Actors]);
	}
	delete[] Dungeon3Actors;
	//PlaySound(TEXT("fucked1(tat2).wav"), 0, SND_FILENAME | SND_ASYNC);

	//DrawRoom(world);
}