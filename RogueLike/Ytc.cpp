#include "Ytc.h"
#include "World.h"
#include "Player.h"
#include "YtcDungeon1.h"
#include "SecretKey.h"

Ytc::Ytc(int x, int y, YtcDungeon1* InYtcDungeon)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    Tileset = World::Instance->Tileset;
    AnimSeq.WhichSprite = Actor::SpritePosition(FERG);
    AnimSeq.NumberOfFrames = 4;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    StartPosition = this->Pos.coords.x;

    YtcDungeon = InYtcDungeon;

    WalkSpeed = 0.01f;
    PlayerPtr = World::Instance->PlayerPtr;
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, AnimSeq);
    bHasntBeenTouchedYet = true;
    //SecretKey* SecretKeyItem = new SecretKey(15, 4);
}

void Ytc::Move(float fElapsedTime)
{
    Pos.coords.x += WalkSpeed;

    if (Pos.coords.x >= StartPosition + 10 || Pos.coords.x <= StartPosition - 10)
    {
        WalkSpeed *= -1;
    }
}

void Ytc::Update(World* world, float fElapsedTime)
{
    Move(fElapsedTime);
    Draw(world, fElapsedTime);


    if (RectangleCollision(PlayerPtr->Pos.coords) && bHasntBeenTouchedYet)
    {
        //world->Actors.AddElement(SecretKeyItem);
        World::Instance->DrawRect(olc::vf2d(Pos.coords.x, Pos.coords.y), AnimSeq.SpriteSize, olc::RED);
        YtcDungeon->bSecretKeyGiven = true;
        YtcDungeon->DungeonUpdate(world);
        bHasntBeenTouchedYet = false;
    }
}
