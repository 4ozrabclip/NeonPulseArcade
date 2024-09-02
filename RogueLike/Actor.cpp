#include "Actor.h"

void Actor::Tick()
{
}

olc::vi2d Actor::SpritePosition(InitialSprite sprite) const
{
    switch (sprite)
    {
    case BORDER:
        return olc::vi2d(0, 0) 
            * olc::vi2d(12, 12);
    case BRICKS:
        return olc::vi2d(0, 5) 
            * olc::vi2d(12, 12);
    case DOOR:
        return olc::vi2d(0, 1) 
            * olc::vi2d(12, 12);
    case RABCLIP:
        return olc::vi2d(16, 2) 
            * olc::vi2d(12, 12);
    case FERG:
        return olc::vi2d(2, 16) 
            * olc::vi2d(12, 12);
    case WOOD:
        return olc::vi2d(0, 3)
            * olc::vi2d(12, 12);
    case ALIEN:
        return olc::vi2d(2, 12)
            * olc::vi2d(12, 12);
    case SPEAKER:
        return olc::vi2d(0, 8)
            * olc::vi2d(12, 12);
    default:
        return olc::vi2d(-1, -1); 
    }
}