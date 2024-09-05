#include "Map.h"
#include "Actor.h"
#include "olcPixelGameEngine.h"
#include <iostream>


Map::Map()
{
    MapLayout = nullptr;
    WhichSpriteInt = 0;
}

Map::~Map()
{
}

void Map::Draw(World* World, float fElapsedTime) const
{
    if (AnimatedSpritePtr)
    {
        //std::cout << "yurp";
        for (int GridBlock = 0; GridBlock < 400; GridBlock++)
        {
            int x = (GridBlock / 20) * 12;
            int y = (GridBlock % 20) * 12;
            olc::vi2d RoomGrid = { x, y };

            if (MapLayout[GridBlock] == WhichSpriteInt)
            {
                //std::cout << "x: " << x << '\n' << "y: " << y << std::endl;
                AnimatedSpritePtr->DrawAt(fElapsedTime, RoomGrid);
            }
        }
    }
}

void Map::SetMap(int map[])
{
    std::copy(map, map + 400, MapLayout.get());
}
