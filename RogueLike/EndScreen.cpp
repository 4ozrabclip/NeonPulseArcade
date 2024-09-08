#include "EndScreen.h"
#include "World.h"
#include "Wood.h"
#include "AnimatedSprite.h"
#include "Pill.h"
#include "Door.h"
#include "DoorToYtc.h"
#include "DoorToApa.h"
#include "Enemy.h"
#include "Sythe.h"
EndScreen::EndScreen()
{
	MapLayout = std::make_unique<int[]>(400);
}
void EndScreen::DrawRoom(World* world)
{

	World::Instance->DrawStringDecal(olc::vi2d(12, 62), "Winner Winner Chicken Dinner", olc::WHITE);
}
void EndScreen::SetMap(int map[])
{
	std::copy(map, map + 400, Map::MapLayout.get());
}

void EndScreen::InitDungeon(World* world)
{
	//Static Init-------------------------------------------------------------------
	MapLayout = std::make_unique<int[]>(400);
	int D1Map[400] = {
		1 , 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 ,
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
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  5,  5,  5,  0 ,  1 ,
		1 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 9 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 10, 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 11, 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  0,  0,  0,  0,  0 ,  1 ,
		1 , 7 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 0 , 0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0 , 0,  0,  5,  0,  0,  0,  0 ,  1 ,
		1 , 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 , 1 , 1  ,1 , 1 , 1 , 1 , 1 , 1 , 1  , 1 ,
	};

	SetMap(D1Map);
	//Static Init Fin---------------------------------------------------------------

	PlaySound(TEXT("fucked1(tat2).wav"), 0, SND_FILENAME | SND_ASYNC);

}
