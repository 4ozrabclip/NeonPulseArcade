#include "Player.h"
#include "Map.h"
#include <iostream>

Player::Player(Map* map)
{
	this->map = map;
}

void Player::Update()
{

	if (map->GetKey(olc::W).bPressed)
	{
		std::cout << "Up" << std::endl;
	}
}
