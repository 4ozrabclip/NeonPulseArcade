#include "Wood.h"
#include "Map.h"

Wood::Wood(int x, int y)
{
    this->Pos.coords.x = x * 12;
    this->Pos.coords.y = y * 12;
    //WhichSpriteInt = DOORLADY;
    AnimSeq.NumberOfFrames = 2;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    AnimSeq.AnimationDuration = 1.0f;
    AnimSeq.WhichSprite = Actor::SpritePosition(WOOD);
    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
}

void Wood::Update(World* world, float fElapsedTime)
{

    //for (int Num = 0; Num < MaxNumCharacters - 1; Num++)
    //{
    //    World::Instance->Enemy
    //}

    if (PlayerPtr->RectangleCollision(Pos.coords))
    {
        switch (PlayerPtr->GetDirection())
        {
        case LEFT:
            //PlayerPtr->SetXY(Pos.coords.x, PlayerPtr->Pos.coords.y);
            PlayerPtr->Pos.coords.x = this->Pos.coords.x + 12;
            break;
        case RIGHT:
            //PlayerPtr->SetXY(Pos.coords.x, PlayerPtr->Pos.coords.y);
            PlayerPtr->Pos.coords.x = this->Pos.coords.x - 12;
            //PlayerPtr->Pos.coords.x - 1;
            break;
        case UP:
            //PlayerPtr->SetXY(PlayerPtr->Pos.coords.x, PlayerPtr->Pos.coords.y);
            PlayerPtr->Pos.coords.y = this->Pos.coords.y + 12;
            break;
        case DOWN:
            //PlayerPtr->SetXY(PlayerPtr->Pos.coords.x, PlayerPtr->Pos.coords.y);
            PlayerPtr->Pos.coords.y = this->Pos.coords.y - 12;
            break;
        }
        //World::Instance->DrawRect(olc::vf2d(Pos.coords.x, Pos.coords.y), AnimSeq.SpriteSize, olc::YELLOW);
    }
    else {
        //std::cout << "no collide: " << PlayerPtr->Pos.coords.x << std::endl;
        //std::cout << "no collide: " << PlayerPtr->Pos.coords.y << std::endl;
    }
    //PlayerPtr->BorderStopper({ Pos.coords.x,Pos.coords.y }, {Pos.coords.x - 12, Pos.coords.y - 12});
    Draw(world, fElapsedTime);
}

void Wood::ItemEffect()
{
}