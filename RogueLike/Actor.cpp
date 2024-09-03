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
        return olc::vi2d(0, 8)
            * World::Instance->TileSize;
    default:
        return olc::vi2d(-1, -1); 
    }
}

void Actor::Draw(World* World, float fElapsedTime) const
{
    olc::vi2d position(Actor::Pos.x, Actor::Pos.y);

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
