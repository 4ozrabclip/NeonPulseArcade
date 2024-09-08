#pragma once
#include "Character.h"
class Player;
class YtcDungeon1;
class SecretKey;
class Ytc : public Character
{
public:
	Ytc(int x, int y, YtcDungeon1* InYtcDungeon);
	virtual void Move(float fElapsedTime) override;
	virtual void Update(World* world, float fElapsedTime) override;

private:
	float StartPosition;
	float WalkSpeed;
	Player* PlayerPtr;
	bool bHasntBeenTouchedYet;
	YtcDungeon1* YtcDungeon;

};

