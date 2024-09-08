#include "DeathScreen.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Door.h"
#include "DoorToYtc.h"
#include "DoorToApa.h"
#include "Enemy.h"
#include "Sythe.h"


DeathScreen::DeathScreen()
{
	MapLayout = std::make_unique<int[]>(400);
}
void DeathScreen::DrawRoom(World* world)
{
	//FAnimSequence BrickSprite;
	//BrickSprite.NumberOfFrames = 2;
	//BrickSprite.SpriteSize = world->TileSize;
	//BrickSprite.AnimationDuration = 1.0f;
	//WhichSpriteInt = BRICKS;
	//BrickSprite.WhichSprite = Actor::SpritePosition(BRICKS);
	//AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, BrickSprite);
	//Draw(world, 0);

	//FAnimSequence SpeakerSprite;
	//SpeakerSprite.NumberOfFrames = 2;
	//SpeakerSprite.SpriteSize = world->TileSize;
	//SpeakerSprite.AnimationDuration = 1.0f;
	//WhichSpriteInt = SPEAKER;
	//SpeakerSprite.WhichSprite = Actor::SpritePosition(SPEAKER);
	//AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, SpeakerSprite);
	//Draw(world, 0);

	//FAnimSequence DeskLeftSprite;
	//DeskLeftSprite.NumberOfFrames = 2;
	//DeskLeftSprite.SpriteSize = world->TileSize;
	//DeskLeftSprite.AnimationDuration = 1.0f;
	//WhichSpriteInt = DESK_LEFT;
	//DeskLeftSprite.WhichSprite = Actor::SpritePosition(DESK_LEFT);
	//AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskLeftSprite);
	//Draw(world, 0);
	//FAnimSequence DeskDecksRabSprite;
	//DeskDecksRabSprite.NumberOfFrames = 2;
	//DeskDecksRabSprite.SpriteSize = world->TileSize;
	//DeskDecksRabSprite.AnimationDuration = 1.0f;
	//WhichSpriteInt = DESK_DECKS_RAB;
	//DeskDecksRabSprite.WhichSprite = Actor::SpritePosition(DESK_DECKS_RAB);
	//AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskDecksRabSprite);
	//Draw(world, 0);

	//FAnimSequence DeskRightSprite;
	//DeskRightSprite.NumberOfFrames = 2;
	//DeskRightSprite.SpriteSize = world->TileSize;
	//DeskRightSprite.AnimationDuration = 1.0f;
	//WhichSpriteInt = DESK_RIGHT;
	//DeskRightSprite.WhichSprite = Actor::SpritePosition(DESK_RIGHT);
	//AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, DeskRightSprite);
	//Draw(world, 0);

	World::Instance->DrawStringDecal(olc::vi2d(50, 62), "YOU DIE!", olc::WHITE);
}
void DeathScreen::SetMap(int map[])
{
	std::copy(map, map + 400, Map::MapLayout.get());
}

void DeathScreen::InitDungeon(World* world)
{
	//Static Init-------------------------------------------------------------------
	MapLayout = std::make_unique<int[]>(400);
	int D1Map[400] = {
		1 , 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1  , 1 ,
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

	PlaySound(TEXT("fucked1(tat2).wav"), 0, SND_FILENAME | SND_ASYNC);

	//DrawRoom(world);
}
