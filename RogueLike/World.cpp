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

	Instance = nullptr;
}

bool World::OnUserCreate()
{
	Tileset = std::make_shared<olc::Sprite>("tileset.png");

	//FAnimSequence animSequence;
	//animSequence.WhichSprite = olc::vi2d(326, 40);
	//animSequence.NumberOfFrames = 2;
	//animSequence.SpriteSize = olc::vi2d(12, 12);
	//animSequence.AnimationDuration = 1.0f;


	//std::shared_ptr<AnimatedSprite> spriteStill = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, animSequence);
	//std::shared_ptr<AnimatedSprite> spriteLoopOnce = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_ONCE, animSequence);
	//std::shared_ptr<AnimatedSprite> spriteLoopForever = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, animSequence);

	/*blocks = std::make_unique<int[]>(mapX * mapY);
	for (int y = 0; y < mapY; y++)
	{
		for (int x = 0; x < mapX; x++)
		{
			if (x == 0 || y == 0 || x == mapX - 1 || y == mapY - 1) //BORDER
			{
				blocks[y * mapX + x] = 10;
			}
			else {
				blocks[y * mapX + x] = 0;
			}
			if ((x > 2 && y > 10 && x < 10 && y < 15)) { //Building1
				blocks[y * mapX + x] = 1;
			}
		}
	}*/


	EnemyPtrs[0] = new Enemy(20, 100);
	//EnemyPtrs[0]->SetAnimatedSprite(spriteStill);

	EnemyPtrs[1] = new Enemy(120, 100);
	//EnemyPtrs[1]->SetAnimatedSprite(spriteLoopOnce);

	EnemyPtrs[2] = new Enemy(220, 100);
	//EnemyPtrs[2]->SetAnimatedSprite(spriteLoopForever);

	PlayerPtr = new Player(0, 0);

	return true;
}

bool World::OnUserUpdate(float fElapsedTime)
{
	const olc::Pixel ClearPixel;
	Clear(ClearPixel);

	for (int i = 0; i < ArraySize; ++i)
	{
		EnemyPtrs[i]->Update(fElapsedTime);
		//EnemyPtrs[i]->Draw(this, fElapsedTime);
	}
	float x = 0;
	float y = 0;
	if (GetKey(olc::Key::LEFT).bHeld) x -= 100 * fElapsedTime;
	if (GetKey(olc::Key::RIGHT).bHeld) x += 100 * fElapsedTime;
	if (GetKey(olc::Key::UP).bHeld) y -= 100 * fElapsedTime;
	if (GetKey(olc::Key::DOWN).bHeld) y += 100 * fElapsedTime;
	PlayerPtr->SetXY(x, y);
	PlayerPtr->Update(fElapsedTime);
	PlayerPtr->Draw(this, fElapsedTime);
	/*
Clear(olc::BLACK);

olc::vi2d temp = { 0,10 };
olc::vi2d sourcepos = { 0, 0 };

for (int y = 0; y < mapY; y++)
{
	for (int x = 0; x < mapX; x++)
	{
		switch (blocks[y * mapX + x])
		{
		case 0: // NOTHING
			break;
		case 10: // BOUNDARY
			DrawPartialSprite(
				olc::vi2d(x, y) * TileSize,
				Tileset.get(),
				sourcepos * TileSize,
				TileSize);
			break;
		case 1: //BUILDING 1
			x == 5 && y == 14 ?
				DrawPartialSprite(
					olc::vi2d(x,y) * TileSize,
					Tileset.get(),
					olc::vi2d(1, 2) * TileSize,
					TileSize)
				: DrawPartialSprite(
					olc::vi2d(x, y) * TileSize,
					Tileset.get(),
					olc::vi2d(0, 5) * TileSize,
					TileSize);
			break;
		}
	}
}*/
	return true;
}
bool World::OnUserDestroy()
{
	return true;
}