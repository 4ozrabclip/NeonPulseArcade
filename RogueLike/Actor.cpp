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
        return olc::vi2d(16, 2) 
            * World::Instance->TileSize;
    case FERG:
        return olc::vi2d(2, 16) 
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

void Actor::SetAnimatedSprite(std::shared_ptr<AnimatedSprite> AnimatedSprite)
{
    AnimatedSpritePtr = AnimatedSprite;
}

olc::vi2d Actor::GetXY()
{
    return olc::vi2d(Pos.coords.x, Pos.coords.y);
}

void Actor::SetXY(float InX, float InY)
{
    Pos.coords.x += InX;
    Pos.coords.y += InY;

    if (Pos.coords.x >= 240 - 12)
    {
        Pos.coords.x = 240 - 12;
    }
    if (Pos.coords.x <= 0)
    {
        Pos.coords.x = 0;
    }
    if (Pos.coords.y >= 240 - 12)
    {
        Pos.coords.y = 240 - 12;
    }
    if (Pos.coords.y <= 0)
    {
        Pos.coords.y = 0;
    }
}