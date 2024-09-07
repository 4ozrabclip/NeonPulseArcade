#pragma once
#include "olcPixelGameEngine.h"
#include "TVector2D.h"
#include "TArray.h"
class Map;
class Player;
class Enemy;
class Dungeon1;
class Actor;

struct FMapCoordinates {
	TVector2D<float> coords;
};

class World : public olc::PixelGameEngine
{

public:
	World();
	~World() override;
	void SetBarriers(olc::vi2d InBarriers);
	olc::vi2d GetMapCoordinates();
	olc::vi2d GetBarriers();

	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;
	virtual bool OnUserDestroy() override;
	void ClearAllActors();
	void ClearDeadActors();

	static World* Instance;

	std::shared_ptr<olc::Sprite> Tileset;
	const olc::vi2d TileSize = { 12, 12 };
	Player* PlayerPtr;

	TArray<Actor*> Actors;
	TArray<Map*> Dungeons;

	void LevelSwitch(bool bSwitch, int InLevel);

	void EnemyKilled(bool bEnemyKilled, int DeadEnemyIndex);

	int GetActorIndex();

	bool NewLevelFlag;

	int Level;

private:
	int ActorIndex;
	bool bEnemyKilled;
	int DeadEnemyIndex;
	int EnemyMax;
	olc::vi2d Barriers;
	FMapCoordinates MapCoords;
	//Enemy** EnemyPtrs = new Enemy * [EnemyMax];
	bool EndLevelFLag;

	Dungeon1* DungeonPtr;
};