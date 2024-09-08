#include "Actor.h"
#include "World.h"

Actor::Actor()
{
    Tileset = World::Instance->Tileset;
    AnimatedSpritePtr = nullptr;
}

void Actor::Tick()
{
}

olc::vi2d Actor::SpritePosition(InitialSprite sprite) const
{
    switch (sprite)
    {
    case BORDER:
        return olc::vi2d(0, 0) 
            * World::Instance->TileSize;
    case BRICKS:
        return olc::vi2d(0, 5) 
            * World::Instance->TileSize;
    case DOOR:
        return olc::vi2d(0, 1) 
            * World::Instance->TileSize;
    case RABCLIP:
        return olc::vi2d(16, 4) 
            * World::Instance->TileSize;
    case FERG:
        return olc::vi2d(16, 0) 
            * World::Instance->TileSize;
    case WOOD:
        return olc::vi2d(0, 3)
            * World::Instance->TileSize;
    case ALIEN:
        return olc::vi2d(12, 2)
            * World::Instance->TileSize;
    case SPEAKER:
        return olc::vi2d(8, 0)
            * World::Instance->TileSize;
    case DOORLADY:
        return olc::vi2d(1, 2)
            * World::Instance->TileSize;
    case DESK_LEFT:
        return olc::vi2d(8, 3)
            * World::Instance->TileSize;
    case DESK_DECKS_RAB:
        return olc::vi2d(9, 3)
            * World::Instance->TileSize;
    case DESK_RIGHT:
        return olc::vi2d(10, 3)
            * World::Instance->TileSize;
    case PILL:
        return olc::vi2d(13, 0)
            * World::Instance->TileSize;
    case DOORSTAIRS:
        return olc::vi2d(0, 2)
            * World::Instance->TileSize;
    case MUSHROOM:
        return olc::vi2d(14, 0)
            * World::Instance->TileSize;
    case RABCLIP_SWORD:
        return olc::vi2d(16, 5)
            * World::Instance->TileSize;
    case FERG_SWORD:
        return olc::vi2d(16, 1)
            * World::Instance->TileSize;
    case APATHETIC:
        return olc::vi2d(16, 2)
            * World::Instance->TileSize;
    case APATHETIC_SWORD:
        return olc::vi2d(16, 3)
            * World::Instance->TileSize;
    case SWORD:
        return olc::vi2d(13, 3)
            * World::Instance->TileSize;
    case RABCLIP_SING:
        return olc::vi2d(20, 4)
            * World::Instance->TileSize;
    case DESK_LEFT_GREY:
        return olc::vi2d(8, 4)
            * World::Instance->TileSize;
    case DESK_DECKS_APA:
        return olc::vi2d(9, 4)
            * World::Instance->TileSize;
    case DESK_RIGHT_GREY:
        return olc::vi2d(10, 4)
            * World::Instance->TileSize;
    case LOCKED_GATE_LEFT:
        return olc::vi2d(6, 1)
            * World::Instance->TileSize;
    case LOCKED_GATE_RIGHT:
        return olc::vi2d(7, 1)
            * World::Instance->TileSize;
    case OPEN_GATE_LEFT:
        return olc::vi2d(2, 2)
            * World::Instance->TileSize;
    case OPEN_GATE_RIGHT:
        return olc::vi2d(3, 2)
            * World::Instance->TileSize;
    case KEY:
        return olc::vi2d(14, 3)
            * World::Instance->TileSize;
    case FANCYWALLS1:
        return olc::vi2d(5, 0)
            * World::Instance->TileSize;
    case FANCYWALLS2:
        return olc::vi2d(6, 0)
            * World::Instance->TileSize;
    case FANCYWALLS3:
        return olc::vi2d(7, 0)
            * World::Instance->TileSize;
    case APA_DOORLADY:
        return olc::vi2d(5, 5)
            * World::Instance->TileSize;
    case FERG_DOORGUARD:
        return olc::vi2d(4, 5)
            * World::Instance->TileSize;
    case PALM_TREE:
        return olc::vi2d(13, 4)
            * World::Instance->TileSize;
    case SECRETKEY:
        return olc::vi2d(15, 3)
            * World::Instance->TileSize;
    case SECRET_GATE_LEFT:
        return olc::vi2d(6, 2)
            * World::Instance->TileSize;
    case SECRET_GATE_RIGHT:
        return olc::vi2d(7, 2)
            * World::Instance->TileSize;
    case FINAL_DOOR:
        return olc::vi2d(4, 1)
            * World::Instance->TileSize;
    case CHECKERWALLS:
        return olc::vi2d(3, 4)
            * World::Instance->TileSize;
    case DEVIL:
        return olc::vi2d(12, 3)
            * World::Instance->TileSize;
    default:
        return olc::vi2d(-1, -1); 
    }
}

void Actor::Draw(World* World, float fElapsedTime) const
{
    olc::vi2d position(Actor::Pos.coords.x, Actor::Pos.coords.y);

    if (AnimatedSpritePtr.get())
    {
        AnimatedSpritePtr.get()->DrawAt(fElapsedTime, position);
    }
    else
    {
        olc::Pixel color(255, 0, 0, 255);
        olc::vi2d size(8, 8);
        World->DrawRect(position, size, color);
    }
}
bool Actor::RectangleCollision(TVector2D<float> r) const
{
    return (this->Pos.coords.x < r.x + 12 && this->Pos.coords.x + 12 > r.x
        && this->Pos.coords.y < r.y + 12 && this->Pos.coords.y + 12 > r.y);
}
int Actor::GetIndex()
{
    return 0;
}
void Actor::SetAnimatedSprite(std::shared_ptr<AnimatedSprite> AnimatedSprite)
{
    AnimatedSpritePtr = AnimatedSprite;
}

//void Actor::SetCollider(olc::vf2d pos)
//{
//    
//}

olc::vi2d Actor::GetXY()
{
    return olc::vi2d(Pos.coords.x, Pos.coords.y);
}

//void Actor::SetAnimSeq(FAnimSequence InAnimSeq)
//{
//    this->AnimSeq = InAnimSeq;
//}

void Actor::SetXY(float InX, float InY)
{
    Pos.coords.x += InX;
    Pos.coords.y += InY;
}