#include "Enemy.h"
#include "Player.h"
#include "World.h"
#include "AnimatedSprite.h"

World* World::Instance = nullptr;

World::World()
{
	sAppName = "4oz Game";
	Instance = this;
}

World::~World()
{
	for (int i = 0; i < ArraySize; ++i)
	{
		delete EnemyPtrs[i];
	}

	delete[] EnemyPtrs;
	delete PlayerPtr;
	Instance = nullptr;
}

bool World::OnUserCreate()
{
	Tileset = std::make_shared<olc::Sprite>("tileset.png");

	PlayerPtr = new Player(0, 0);

	EnemyPtrs[0] = new Enemy(20, 100);
	EnemyPtrs[1] = new Enemy(120, 100);
	EnemyPtrs[2] = new Enemy(220, 100);


	return true;
}
bool World::OnUserUpdate(float fElapsedTime)
{
	const olc::Pixel ClearPixel;
	Clear(ClearPixel);

	for (int i = 0; i < ArraySize; ++i)
	{
		EnemyPtrs[i]->Update(fElapsedTime);
	}
	PlayerPtr->Update(fElapsedTime);
	PlayerPtr->Draw(this, fElapsedTime);

	return true;
}
bool World::OnUserDestroy()
{
	return true;
}